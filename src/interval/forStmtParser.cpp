#include <iostream>
#include "forStmtParser.h"
#include "intervalExpression.h"
#include "tempVariables.h"
#include "genVarDecl.h"
#include "pollyReduction.h"

using namespace clang;
using namespace std;
using namespace llvm;

forStmtParser::forStmtParser(ForStmt *frs) : forStmt(frs) {
    /* Parse initialization */
    _parseCodeInit(frs->getInit());

    /* Parse condition expressions of for loop */
    _parseCodeCond(frs->getCond());

    /* Parse increment expressions of for loop */
    _parseCodeIncr(frs->getInc());

    /* In case the for loop contains a reduction */
    _parseCodeRedu(frs);

    /* Add code transformation for the preamble before the for loop */
    addCodeTransformation(preamble, frs->getBeginLoc(), codeFragment::InsertBefore);
}

void forStmtParser::_parseCodeInit(Stmt *initExpr) {

    if (initExpr == nullptr) {
        return;
    }

    if (auto *decs = dyn_cast<DeclStmt>(initExpr)) {
        /* for statement has declaration of variable */
        auto *var = dyn_cast<VarDecl>(decs->getSingleDecl());
        genVarDecl genVar(var);

        /* create code fragment for  init */
        init          = genVar.getCompleteDecl();
        addCodeTransformation(init, var->getSourceRange(), codeFragment::Replace);

        /* Add code to preamble */
        preamble += genVar.getInit();

        errs() <<  "** Rewrote declaration: " << genVar.getCompleteDecl() << NL;
    }

    if (auto *expr = dyn_cast<Expr>(initExpr)) {
        intervalExpression iInit(expr);
        init = iInit.getIntervalExpr();
        addCodeTransformation(init, initExpr->getSourceRange(), codeFragment::Replace);

        /* Add code to preamble */
        preamble += iInit.getBuff();
    }

    lastProcessedLocation = initExpr->getEndLoc();
}

void forStmtParser::_parseCodeCond(Expr *condExpr) {

    if(condExpr == nullptr) {
        return;
    }

    /* Process condition */
    intervalExpression iCond(condExpr);
    if (iCond.isLogicalExpr() || iCond.isScalarExpr()) {
        /* create code fragment for condition expresion */
        cond = iCond.getLogicalExpr();
        addCodeTransformation(cond, condExpr->getSourceRange(), codeFragment::Replace);

        /* Add code to preamble */
        preamble += iCond.getBuff();
    }
    else {
        errs() << "** Error: for statement can only process logical or scalar expressions\n";
    }

    lastProcessedLocation = condExpr->getEndLoc();
}

void forStmtParser::_parseCodeIncr(Expr *incrExpr) {

    if (incrExpr == nullptr) {
        return;
    }
    intervalExpression iInc(incrExpr);
    incr          = iInc.getCompleteExprAsString();

    if (iInc.isOneLineExpr()) {
        /* Create code fragment in the position of the increment expression */
        addCodeTransformation(incr, incrExpr->getSourceRange(), codeFragment::Replace);
    }
    else {
        /* If multiple lines are required. Then, placed the fragment at the end of the
         * loop and clean the original increment expression */
        incr += SCNL;
        addCodeTransformation(incr, forStmt->getEndLoc(), codeFragment::InsertBefore);
        addCodeTransformation("", incrExpr->getSourceRange(), codeFragment::Replace);
    }

    lastProcessedLocation = incrExpr->getEndLoc();
}

void forStmtParser::_parseCodeRedu(ForStmt *frs) {
    if (!GlobalPollyReduction.hasLoopReductions(frs)) {
        /* Loop doesn't have reductions */
        return;
    }

    /* Add declaration and initialization of the accumulators before the loop (in preamble) */
    for (reductionVariable& rv : GlobalPollyReduction.getReductionVariablesInLoop(frs)) {
        intervalExpression reductionVar(rv.redVar);

        /* Accumulator declaration */
        string accType = getIGenAccumulatorType(reductionVar.getType());
        string accName = ACCUMULATOR_VAR + to_string(rv.redID);
        preamble += accType + " " + accName + SCNL;

        /* Accumulator initialization  */
        preamble += getIGenReductionOperationFun(RED_INIT, reductionVar.getType(), reductionVar.getIntervalExpr(), rv.redID);
        preamble += SCNL;

        /* Final reduction at the end of the loop */
        string final_reduction = getIGenReductionOperationFun(RED_FINAL_REDUCTION, reductionVar.getType(),
                                                              reductionVar.getIntervalExpr(), rv.redID);
        final_reduction += SCNL;
        addCodeTransformation(final_reduction, frs->getEndLoc(), codeFragment::InsertAfterToken);

        /* Set reduction improvement transformation flag to generate proper header file */
        setReductionImprovementUsed();
    }
}
