#pragma once
#ifndef INTERVAL_ARITHMETIC_POLLY_RED_H
#define INTERVAL_ARITHMETIC_POLLY_RED_H

#include <vector>
#include <string>
#include <set>
#include "clang/AST/AST.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/ParentMapContext.h"

using namespace std;

#define ACCUMULATOR_VAR "_acc"

enum enumReductionOperation {
    RED_INIT = 0,
    RED_ACCUMULATE,
    RED_FINAL_REDUCTION
};

struct raw_location_ty {
    size_t line = 0;
    size_t colm = 0;
    raw_location_ty(std::size_t l, std::size_t c) : line(l), colm(c) {}
    raw_location_ty() = default;

    bool operator<(raw_location_ty l) const {
        return (line == l.line) ? (colm < l.colm) : (line < l.line);
    }
};

struct reductionVariable {
    clang::Expr* redVar;     // Node to reduction variable (usually ArraySubscriptExpr)
    std::size_t   redID;     // Reduction ID used to enumerate the accumulators created during transformation
    reductionVariable(clang::Expr* rv, std::size_t id) : redVar(rv), redID(id) {}
};

/// The global object GlobalPollyReduction manages the detected reductions. This detection is done in two steps.
/// The first step simply stores the reductions detected by polly in suitables data structures. The second steps
/// searches the AST for nodes where reduction occurs. More precisely:
///
/// 1) The polly record (csv file) is read and the location (line and column) of each reduction is stored in
///    pollyDetectedLoads and pollyDetectedStoresAndLoopLvl. A reduction consists of the location of its load, the
///    location of its store (assignment operator) and the loop level in which the reduction applies. For example:
///
///    1:  for (int i = 0; i < 100; i++)
///    2:    for (int j = 0; j < 100; j++)
///    3:      x[i] = A[i*100 + j] + x[i]
///                 |                |
///                 11               27
///
///    Location (3,27) will be added to pollyDetectedLoads, and the relation (3,11)-> (1) as added to
///    pollyDetectedStoresAndLoopLvl. The reduction only holds for the inner loop. Thus, the "(1)" in the relation.
///
/// 2) We traverse the entire AST looking for nodes with "IGenAttr reduce". When found we traverse its child nodes
///    and keep track of Expr nodes (ArraySubscriptExpr) that match the location in pollyDetectedLoads. We do the same
///    for Expr nodes (Assignment operators) that match the location in pollyDetectedStoresAndLoopLvl.
class PollyReduction : clang::RecursiveASTVisitor<PollyReduction> {
    friend clang::RecursiveASTVisitor<PollyReduction>;

    std::string reductionsFileName;                // Name of file where reductions extracted from polly are (CSV file)

    clang::ASTContext* astContext;                 // Context used for get position information of AST nodes (line, column)

    set<raw_location_ty> pollyDetectedLoads;       // Loads as detected by polly (using file location line and column)

    map<raw_location_ty, std::size_t>              // Map from detected stores by polly (using file location), to its
    pollyDetectedStoresAndLoopLvl;                 // loop level in which the reduction holds. A reduction level 1 means
                                                   // that the reduction holds only for the loop where the store happens.

    set<clang::Expr*> loads;                       // Load expressions that are part of a reduction chain.
                                                   // These nodes will transformed to zero when transforming reductions

    map<clang::Expr*, std::size_t> stores;         // Assignments (or stores) expressions in reduction chain.
                                                   // These nodes will be replaced by the accumulate function when
                                                   // transforming reductions. The mapping is to store the id of the reduction.

    map<const clang::Stmt*,                        // Map from loop with reductions to the variables to reduce. These
        vector<reductionVariable>> loops;          // variables will used to initialize the accumulator just before the
                                                   // loop starts during reduction transformation.

    std::size_t semaphore = 0;                     // Semaphore. It is incremented when a IGenAttr is detected and
                                                   // decremented when the traversal of its child loop is done.
public:
    void setASTContext(clang::ASTContext* c);
    void readPollyReductions();
    void matchReductionsWithASTNodes(clang::Decl* decl);
    bool isReductionVariable(clang::Expr* expr);
    bool isReductionAssignment(clang::Expr* expr);
    bool hasLoopReductions(clang::Stmt* stmt);
    std::size_t getReductionIDFromAssignment(clang::Expr* expr);
    vector<reductionVariable>& getReductionVariablesInLoop(clang::Stmt* stmt);
    void setRedCSVFileName(std::string& fname);

private:
    bool isLoadDetectedByPolly(raw_location_ty& load);
    bool isStoreDetectedByPolly(raw_location_ty& load);
    const clang::Stmt* searchForParentLoopStmt(clang::Stmt* stmt, size_t loop_lvl);

    /// Visitors callbacks during traversing of AST.
    bool VisitArraySubscriptExpr(clang::ArraySubscriptExpr* arr);
    bool VisitBinaryOperator(clang::BinaryOperator* bop);
    bool VisitCompoundAssignOperator(clang::CompoundAssignOperator* cao);
    bool VisitForStmt(clang::ForStmt* frs);

    bool TraverseArraySubscriptExpr(clang::ArraySubscriptExpr* arr);
    bool TraverseBinaryOperator(clang::BinaryOperator* bop);
    bool TraverseCompoundAssignOperator(clang::CompoundAssignOperator* cao);
    bool TraverseForStmt(clang::ForStmt* frs);
    bool TraverseAttributedStmt(clang::AttributedStmt* att);
};

/// Declaration of global object with Polly reductions
extern PollyReduction GlobalPollyReduction;

/// IGen functions used for transformations
std::string getIGenReductionOperationFun(enumReductionOperation op, const std::string& type, const std::string& var, size_t acc_id);
std::string getIGenAccumulatorType(const std::string& type);

#endif //INTERVAL_ARITHMETIC_POLLY_RED_H
