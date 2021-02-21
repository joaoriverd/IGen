#include "ASTAnalyzer.h"
#include "clang/AST/Stmt.h"
#include "clang/Tooling/Tooling.h"
#include "clang/AST/ASTImporter.h"
#include "ASTVisitor.h" /* for getRawCodeAsString */
#include "commonInterval.h"

using namespace std;
using namespace clang;

bool operator==(clang::DeclRefExpr const& lhs, clang::DeclRefExpr const& rhs) {
    return lhs.getDecl()->getID() == rhs.getDecl()->getID();
}

bool operator!=(clang::DeclRefExpr const& lhs, clang::DeclRefExpr const& rhs) {
    return lhs.getDecl()->getID() != rhs.getDecl()->getID();
}

bool haveSameName(clang::DeclRefExpr* const& lhs, clang::DeclRefExpr* const& rhs) {
    return lhs->getNameInfo().getAsString() == rhs->getNameInfo().getAsString();
}

AnalyzerReducePragma::AnalyzerReducePragma(Stmt *st, DeclRefExpr *v) : stmt(st), var(v) {
    /* The main purpose is to identify expressions in the attributed stmt where a reduction
     * in "var" is done (e.g. var = var + term). This is done in two steps:
     * 1) Identify expressions in stmt where "var" is assigned.
     * 2) For each expression found in 1), get the term added to "var" if it exists. Otherwise error */
    std::vector<clang::Expr*> vecAssignedExpr = search.SearchAssignmentOfVar(st, v);

    for (Expr* e : vecAssignedExpr) {
        /* Copy the original expression using ExprPtr to modify the ast safely without changing the original */
        ExprPtr subExpr = extract.getTermFromAssignedExpr(e, v);
        if(subExpr.get()) {
            vecAddedTerm.emplace_back(subExpr, e->getSourceRange());
        }
        else {
            /* E.g. var = 1.0 is not a proper reduction */
            vecAddedTerm.clear();
            llvm::errs() << "Assignment expressions not well formed for reduce pragma\n";
            break;
        }
    }
}

bool SearchAssignment::isParentCompoundStmt(Expr* expr) {
    ASTContext& context = mainCI->getASTContext();
    const auto& parents = context.getParents(*expr);
    if ( parents.empty() ) {
        return false;
    }
    const Stmt* parentStmt = parents[0].get<Stmt>();
    if (!parentStmt || !isa<CompoundStmt>(parentStmt)) {
        return false;
    }

    return true;
}

bool SearchAssignment::isValidExprToReduce(Expr* expr) {

    auto* bop = dyn_cast<BinaryOperator>(expr);
    if (!bop) {
        return false;
    }

    /* Check if it is an assignment operation. If not, then return */
    if(!(BinaryOperatorKind::BO_Assign    == bop->getOpcode()) &&
       !(BinaryOperatorKind::BO_AddAssign == bop->getOpcode())) {
        return false;
    }

    /* Remove all possible parenthesis from the lhs, e.g. (var) = (var) + 1.0 */
    Expr* lhsExpr = bop->getLHS();
    while (auto* parenExpr = dyn_cast<ParenExpr>(lhsExpr))
    {
        lhsExpr = parenExpr->getSubExpr();
    }

    /* Check if left side is the variable that we are looking for. If not, then return */
    auto* lhsVar = dyn_cast<DeclRefExpr>(lhsExpr);
    if (!lhsVar || *var != *lhsVar) {
        return false;
    }

    return true;
}

bool SearchAssignment::identifyAssignedExpr(Expr* expr) {

    auto* bop = dyn_cast<BinaryOperator>(expr);
    if(!bop || !isTypeSupported(bop->getType())) {
        return false;
    }

    /* Check if it is an assignment expression where lhs is the variable to reduce */
    if (!isValidExprToReduce(bop)) {
        return true; /* Return true to continue traversing ast */
    }

    /* Now check that the parent expression is a compound statement. Otherwise it is not supported,
     * e.g. (var += 1.0) is not yet supported, and we should stop the analysis without results. */
    if (!isParentCompoundStmt(bop)) {
        llvm::errs() << "Assignment expressions not well formed for reduce pragma: ";
        llvm::errs() << getRawCodeAsString(bop->getSourceRange()) << "\n";
        _vecAssignedExpr.clear();
        return false;
    }

    /* At this point we know that expr is well formed and it's an assignment to var. */
    _vecAssignedExpr.push_back(expr);

    return true;
}

bool TermExtractor::areParentsOnlyAdditions(Expr* root, DeclRefExpr* v, vector<AddBopMarked>& vecParentAdd) {
    const Expr* subExpr = static_cast<Expr*>(v);
    bool hasAddition = false;
    while (subExpr->getID(*context) != root->getID(*context)) {
        const auto& parents = context->getParents(*subExpr);
        if (parents.empty()) {
            llvm::errs() << "Expression to reduce is malformed\n";
            return false;
        }

        const Expr* parentExpr = parents[0].get<Expr>();
        auto* bop = dyn_cast<BinaryOperator>(parentExpr);
        if (!parentExpr || (!isa<ParenExpr>(parentExpr) && !isa<ImplicitCastExpr>(parentExpr)
                             &&  BinaryOperatorKind::BO_Add != bop->getOpcode())) {
            /* parent is neither addition, parenthesis or implicit cast */
            llvm::errs() << "Expression to reduce is malformed\n";
            return false;
        }

        if (bop && BinaryOperatorKind::BO_Add == bop->getOpcode()) {
            /* It should have at least one addition */
            hasAddition = true;

            /* Check if subExpr is in lhs or rhs of parent bop expression */
            if (bop->getRHS()->getID(*context) == subExpr->getID(*context)) {
                vecParentAdd.emplace_back(const_cast<BinaryOperator *&&>(bop), RHS);
            }
            else if (bop->getLHS()->getID(*context) == subExpr->getID(*context)) {
                vecParentAdd.emplace_back(const_cast<BinaryOperator *&&>(bop), LHS);
            }
            else {
                llvm::errs() << "Expression to reduce is malformed\n";
                return false;
            }

        }

        subExpr = parentExpr;
    }

    return hasAddition;
}

ExprPtr TermExtractor::getTermFromAssignedExpr(Expr* e, DeclRefExpr* v) {
    ExprPtr cpExpr(e);   // make copy of expression
    context = cpExpr.getContextPtr();
    expr    = cpExpr.get();
    var     = v;
    term    = nullptr;

    auto* bop = dyn_cast<BinaryOperator>(cpExpr.get());

    /* In case of AddAssign kind, we are done. This is a proper reduction. E.g. in var += term */
    if(BinaryOperatorKind::BO_AddAssign == bop->getOpcode()) {
        term = bop->getRHS();
    }

    /* If it is assignment operator then we have to identify if it is indeed a summation (reduction)
     * and modify the AST accordingly, e.g. var = var + term should only save the term part */
    if(BinaryOperatorKind::BO_Assign == bop->getOpcode()) {
        TraverseStmt(bop->getRHS());  /* The term is found during traversal */
    }

    cpExpr = term;
    return cpExpr;
}

bool TermExtractor::extractTermFromExpr(Expr* e, DeclRefExpr* v) {
    /* Here, we traverse the expression and eliminate var from the expression. This can only be
     * removed if the parents nodes of var are additions (or parenthesis). If the variable is not present
     * in the expression then this is not a valid, e.g. var = 1.0 is not valid */

    vector<AddBopMarked> vecParentAdd; /* Keep the parents that are additions */
    auto* assignExpr = dyn_cast<BinaryOperator>(e);
    if (!assignExpr || BinaryOperatorKind::BO_Assign != assignExpr->getOpcode() ||
        !areParentsOnlyAdditions(assignExpr->getRHS(), v, vecParentAdd)) {
        return false;
    }
    Expr* rhsAssign = assignExpr->getRHS();

    /* We have found the correct node to remove if this line is reached. */
    /* Remove var and associated add operation */
    if (!vecParentAdd.empty()) {
        AddBopMarked& firstAddNode  = vecParentAdd[0];
        Expr* t1 = firstAddNode.side == RHS ? firstAddNode.bop->getLHS() : firstAddNode.bop->getRHS();

        if (vecParentAdd.size() == 1) {
            /* There is only one add in the parents. Thus we are done */
            term = t1;
        }
        else {
            AddBopMarked& secondAddNode = vecParentAdd[1];
            if(secondAddNode.side == RHS) {
                secondAddNode.bop->setRHS(t1);
            }
            else {
                secondAddNode.bop->setLHS(t1);
            }
            term = rhsAssign;
        }
    }
    return true;
}


bool TermExtractor::VisitDeclRefExpr(DeclRefExpr* ref) {
    /* Check for the correct variable to remove */
    bool termExtracted = false;

    if (haveSameName(ref, var)) {
        /* Note: it is actually not nice to compare variables by name instead of ID but
         * since ref is in another context than var (since we copied the ast) they have
         * different IDs. */
        termExtracted = extractTermFromExpr(expr, ref);
    }

    if (!termExtracted) {
        return true; // keep searching;
    }
    return false;
}