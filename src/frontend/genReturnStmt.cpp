#include "genReturnStmt.h"
#include "commonInterval.h"
#include "ASTVisitor.h"

using namespace std;
using namespace clang;

genReturnStmt::genReturnStmt(ReturnStmt *ret) {

    switch (getIntervalLib()) {

        case IAGEN :
            _constructReturnStmt(ret);
            break;

        case MPFI_LIB :
            _constructReturnStmtMPFI(ret);
            break;

        default: break;
    }

}

void genReturnStmt::_constructReturnStmt(ReturnStmt *re){

    if( Expr* retExpr = re->getRetValue() ) {

        /* The return has an expresion. First parse it */
        intervalExpression iExpr(retExpr);
        this->prelude = iExpr.getBuff();
        string exprType = iExpr.typeStr;
        transformToIntervalType(exprType);

        string strRetVar;
        if (iExpr.getIntervalExpr().empty()){

            /* Create interval _ret variable to return if needed */
            this->prelude += exprType + " "  RETURN_VAR SCNL;
            this->prelude += RETURN_VAR_LO " = " + iExpr.getLowExpr() + SCNL;
            this->prelude += RETURN_VAR_UP " = " + iExpr.getUpExpr()  + SCNL;
            strRetVar = RETURN_VAR;

        }
        else if ( !iExpr.hasBounds() && !iExpr.isConstantExpr()) {

            /* The expression is not a variable and neither a constant, e.g. _ia_mul_d(...) */
            this->prelude  += exprType + " " RETURN_VAR SCNL;
            this->prelude  += RETURN_VAR " = " + iExpr.getIntervalExpr() + SCNL;
            strRetVar   = RETURN_VAR;

        } else {
            /* The expression is a variable */
            strRetVar = iExpr.getIntervalExpr();
        }

        if (re->getEndLoc() < returnToleranceScope.endLoc) {
            /* The result should be reduced to its original floating point type */
            /* First, get the original return type */
            string retType = retExpr->getType().getAsString();

            if (isTypeSupported(retType)) {
                /* If type was indeed transformed then we should perform reduction */
                string reduceFunc = getReductionFunction(exprType, retType);
                this->prelude += retType + " " RETURN_VAR_F " = " + reduceFunc
                                         + "(" + strRetVar + ", " + returnToleranceScope.tolerance + ")" SCNL;
                strRetVar = RETURN_VAR_F;
            }
        }

        this->prelude += CODE_RESTORE_FROUND;
        this->ret     += RETURN_KEY " " + strRetVar;
    }
    else {
        /* No expression after return. Simply restore rounding mode. */
        this->prelude = CODE_RESTORE_FROUND;
        this->ret     = RETURN_KEY;
    }
}

void genReturnStmt::_constructReturnStmtMPFI(clang::ReturnStmt *re) {

    if( Expr* retExpr = re->getRetValue() ) {

        /* The return has an expresion */
        string retType = retExpr->getType().getUnqualifiedType().getAsString();

        intervalExpression iExpr(retExpr);
        this->prelude = iExpr.getBuff();

        if ( isTypeSupported(retType) ) {
            /* When the return type supports interval operations, the function signature changed
             * to void instead of returning an mpfi_t object. This is done in MPFI only because
             * functions cannot return this type (mpfi_t). Thus, we should return void and store the
             * return's expression in the corresponding return variable (which now is a parameter of
             * the function ) */
            string retVar  = RETURN_VAR;

            if (iExpr.isConstantExpr()) {
                /* Constants are assigned differently to MPFI interval's objects */
                this->prelude += MPFI_ASSIGN_CONST(retVar, iExpr.getLowExpr(), iExpr.getUpExpr()) + SCNL;
            }
            else {
                this->prelude += MPFI_ASSIGN(retVar, iExpr.intervalVar) + SCNL;
            }

            this->ret = RETURN_KEY;

        }
        else {
            /* The return type is not an interval. Thus, keep it as it is. */
            this->ret = RETURN_KEY " " + iExpr.intervalVar;
        }

    }
    else {
        /* No expression after return. Thus, keep it that way. */
        this->prelude = "";
        this->ret     = RETURN_KEY;
    }
}

std::string genReturnStmt::getPrelude() {
    return this->prelude;
}

std::string genReturnStmt::getReturn() {
    return this->ret;
}

std::string genReturnStmt::getCompleteReturn() {
    return this->prelude + this->ret;
}

