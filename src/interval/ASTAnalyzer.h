#ifndef INTERVAL_ARITHMETIC_ASTANALYZER_H
#define INTERVAL_ARITHMETIC_ASTANALYZER_H

#include <iostream>
#include <vector>
#include "clang/AST/Type.h"
#include "clang/AST/AST.h"
#include "clang/AST/ParentMapContext.h"
#include "commonInterval.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "codeFragment.h"
#include "clang/Tooling/Tooling.h"
#include "clang/AST/ASTImporter.h"

//struct tRootNote {
//    enum NodeType {
//        StmtType = 0,
//        DeclType
//    };
//
//    void*    n;
//    NodeType t;
//
//    tRootNote(void* n, NodeType t) : n(n), t(t) {}
//};
//
///* First try of more generalized analyzer */
//class ASTAnalyzer : clang::RecursiveASTVisitor<ASTAnalyzer>{
//    friend clang::RecursiveASTVisitor<ASTAnalyzer>;
//
//protected:
//    /* Root node */
//    tRootNote root;
//
//    /* Traverse root AST. This is normally called when starting some analysis. */
//    bool TraverseRootAST() {
//        switch (root.t) {
//            case tRootNote::StmtType: return TraverseStmt(static_cast<clang::Stmt *>(root.n));
//            case tRootNote::DeclType: return TraverseDecl(static_cast<clang::Decl *>(root.n));
//        }
//        return false;
//    }
//
//public:
//    explicit ASTAnalyzer(clang::Stmt* stmt) : root(stmt, tRootNote::StmtType) { }
//    explicit ASTAnalyzer(clang::Decl* decl) : root(decl, tRootNote::DeclType) { }
//
//    /* Auxiliary function for analysis */
//    static bool isSameVar(clang::DeclRefExpr* a, clang::DeclRefExpr* b) {
//        return a->getDecl()->getID() == b->getDecl()->getID();
//    }
//};

/* The analysis of the #pragma igen reduce var consists of two intermediate analysis
 * of the AST. First identify the assigned expressions of the form "var = var + term".
 * And then extract the "term" in the rhs of the assignment expression */
class SearchAssignment : clang::RecursiveASTVisitor<SearchAssignment> {
    friend clang::RecursiveASTVisitor<SearchAssignment>;

    clang::DeclRefExpr*                    var; /* Variable to reduce */
    std::vector<clang::Expr*> _vecAssignedExpr;

    /* Auxiliary function for the analysis */
    bool isParentCompoundStmt(clang::Expr* expr);
    bool isValidExprToReduce(clang::Expr* expr);
    bool identifyAssignedExpr(clang::Expr* expr);
    bool VisitBinaryOperator(clang::BinaryOperator *bop) {
        return identifyAssignedExpr(bop);
    }

public:

    SearchAssignment() : var(nullptr) { };

    std::vector<clang::Expr*>& getVecOfAssignedExpr() {
        return _vecAssignedExpr;
    }

    std::vector<clang::Expr*>& SearchAssignmentOfVar(clang::Stmt* st, clang::DeclRefExpr* v) {
        var = v;
        TraverseStmt(st);
        return _vecAssignedExpr;
    }

};

class ExprPtr {
    std::unique_ptr<clang::ASTUnit> astUnit;
    clang::Expr* expr;

public:
    ExprPtr() = default;

    explicit ExprPtr(clang::Expr* e) {
        astUnit = clang::tooling::buildASTFromCode("");
        expr = makeCopy(e);
    }

    /// Make a copy of an expression in the current astUnit. Return the copy.
    clang::Expr* makeCopy(clang::Expr* node) {
        clang::ASTImporter astImporter(astUnit->getASTContext(), astUnit->getFileManager(),
                                       mainCI->getASTContext(), mainCI->getFileManager(), false);

        llvm::Expected<clang::Expr*> CopiedOrErr = astImporter.Import(node);

        if (!CopiedOrErr) {
            llvm::errs() << "Error when creating a copy of ast node";
            return nullptr;
        }
        return *CopiedOrErr;
    }

    /// Assign an Expr* to ExprPtr. This will actually copy the whole AST.
    ExprPtr& operator=(clang::Expr* e) {
        expr = e;
        return *this;
    }

    clang::Expr* get() const {
        return expr;
    }

    clang::ASTContext* getContextPtr() const {
        return &astUnit->getASTContext();
    }

    void update(clang::Expr* e) {
        expr = e;
    }
};

class TermExtractor : clang::RecursiveASTVisitor<TermExtractor> {
    friend clang::RecursiveASTVisitor<TermExtractor>;

    clang::DeclRefExpr*    var; /* variable to remove from expression    */
    clang::Expr*          expr; /* Expression where to get the term from */
    clang::Expr*          term; /* Extracted term                        */
    clang::ASTContext* context; /* Needed to get the parents of node     */

    /* This helps to keep track of AddNodes and in which child (left or right) var is located */
    enum eRLSide { RHS = 0, LHS };
    struct AddBopMarked {
        clang::BinaryOperator* bop;
        eRLSide side;
        AddBopMarked (clang::BinaryOperator* bop, eRLSide side) : bop(bop), side(side) {}
    };

    /* Auxiliary function for the analysis */
    bool extractTermFromExpr(clang::Expr*, clang::DeclRefExpr* ref);
    bool areParentsOnlyAdditions(clang::Expr* e, clang::DeclRefExpr* v, std::vector<AddBopMarked>& vecParentAdd);
    bool VisitDeclRefExpr(clang::DeclRefExpr* ref);


public:

    TermExtractor() : var(nullptr), expr(nullptr), term(nullptr) { }

    ExprPtr getTermFromAssignedExpr(clang::Expr* e, clang::DeclRefExpr* v);

};

/// This class represents the added term to the reduced variable.
/// E.g. In var = var + term. The range is the location of the whole assignment expression.
class AddedTerm {
    ExprPtr expr;
    clang::SourceRange range;  /* Location where expression will be placed */
public:
    AddedTerm(ExprPtr& e, clang::SourceRange r) : range(r) {
        expr = std::move(e);
    }

    clang::Expr* getTerm() const {
        return expr.get();
    }

    clang::SourceRange getRange() const {
        return range;
    }
};

class AnalyzerReducePragma {

    clang::Stmt*                   stmt; /* Statement with attribute #pragma igen reduce var            */
    clang::DeclRefExpr*             var; /* Variable to reduce                                          */
    std::vector<AddedTerm> vecAddedTerm; /* Vector of the terms added to var, e.g. in var = var + term  */
    SearchAssignment             search; /* Object that searches for the assignment of var in stmt      */
    TermExtractor               extract; /* Object that extracts the term from an assignment expression */

public:
    AnalyzerReducePragma(clang::Stmt* stmt, clang::DeclRefExpr* v);

    /// Get a vector of Expressions in which the variable var is assigned. This can happen
    /// only if there are expressions like var = expr or var += expr, etc. Which are either
    /// of type BinaryOperator or CompoundAssignOperator.
    const std::vector<AddedTerm>& getVecOfAddedTerms() {
        return vecAddedTerm;
    }
};


#endif //INTERVAL_ARITHMETIC_ASTANALYZER_H
