#include "unaryOpExpressions.h"
#include "llvm/Support/raw_ostream.h"
#include "commonInterval.h"
#include "tempVariables.h"
#include "constantExpressions.h"

using namespace std;

#define NEG_AS_FUNCTION
void uopMinus (intervalExpression& iExpr, intervalExpression& iRes) {
    iRes.isScalar   = iExpr.isScalar;
    iRes.isConstant = iExpr.isConstant;

#ifdef NEG_AS_FUNCTION
    if ( iExpr.isScalar ) {
        iRes.intervalVar = "-" + iExpr.intervalVar;
    }
    else if ( iExpr.isConstantExpr() ) {
        negateConstantInterval(iExpr, iRes);
    }
    else {
        string type = iRes.getType();

        /* Generate interval variable for iExpr if needed */
        genTempVar(iExpr, intervalExpression::getInternalBuff());

        iRes.intervalVar = _iaFunName("neg", type) + "(" + iExpr.intervalVar + ")";
        iRes.loExpr = "";
        iRes.upExpr = "";
    }
#else
    if ( iExpr.isScalar ) {
        iRes.intervalVar = "-" + iExpr.intervalVar;
    }
    else if (iExpr.typeStr == DD_T) {
        /* Negate a DD variable */
        iRes.intervalVar = _iaFunName("neg", DD_T) + "(" + iExpr.intervalVar + ")";
        iRes.loExpr = "";
        iRes.upExpr = "";
    }
    else {
        /* Generate temporal variable if needed. */
        if (!iExpr.hasBounds()) {
            genTempVar(iExpr, intervalExpression::getInternalBuff());
        }

        /* To apply only upward rounding, the lower bound part of an interval is implicitly negated.
        /* Hence, it follows that -[a.lo, a.up] = [a.up, a.lo] */
        iRes.loExpr = iExpr.upExpr;
        iRes.upExpr = iExpr.loExpr;
        if ( iExpr.isConstantExpr() ) {
            negateConstantInterval(iExpr, iRes);
        }
    }
#endif
}

void uopDereference (intervalExpression& iExpr, intervalExpression& iRes) {

    iRes.intervalVar = "*" + iExpr.intervalVar;
    iRes.isScalar   = iExpr.isScalar;
    iRes.isConstant = false;
    if ( isTypeSupported(iRes.getType()) && getIntervalLib() == IAGEN)
    {
        iRes.loExpr = "(*" + iExpr.intervalVar + ").lo" ;
        iRes.upExpr = "(*" + iExpr.intervalVar + ").up" ;
        iRes.isScalar = false;
    }
}

void uopAutoincrement (intervalExpression& iExpr, intervalExpression& iRes, string& op, bool is_prefix) {

    iRes.isScalar = iExpr.isScalar;
    if ( iRes.isScalarExpr() ) {
        iRes.intervalVar = is_prefix ? op + iExpr.intervalVar : iExpr.intervalVar + op;
    }
    if (iExpr.getType() == DD_T) {

        if ( is_prefix ) {
            intervalExpression::getInternalBuff() += iExpr.intervalVar + " = " +
                                                     _iaFunName(op, DD_T) + "(" + iExpr.intervalVar + ")" + SCNL;
            iRes.intervalVar = iExpr.intervalVar;
        }
        else {
            string tempVar = genTempVar(iExpr.typeStr, intervalExpression::getInternalBuff() );
            intervalExpression::getInternalBuff() += tempVar + " = " + iExpr.intervalVar + SCNL;
            intervalExpression::getInternalBuff() += iExpr.intervalVar + " = " +
                                                     _iaFunName(op, DD_T) + "(" + iExpr.intervalVar + ")" + SCNL;
            iRes.intervalVar = tempVar;
        }
    }
    else {
        string& opUp = op;
        string  opLo = op == "++" ? "--" : "++";

        if ( is_prefix ) {
            iRes.loExpr = opLo + iExpr.loExpr;
            iRes.upExpr = opUp + iExpr.upExpr;
        }
        else {
            iRes.loExpr = iExpr.loExpr + opLo;
            iRes.upExpr = iExpr.upExpr + opUp;
        }
    }
}

void uopNot(intervalExpression& iExpr, intervalExpression& iRes) {

    iRes.isScalar   = iExpr.isScalar;
    iRes.isConstant = iExpr.isConstant;
    if ( iExpr.isScalarExpr() ) {
        iRes.intervalVar = "~" + iExpr.intervalVar;
    }
    else {

        /* To apply only upward rounding, the lower bound part of an interval is implicitly negated.
        /* Hence, it follows that -[a.lo, a.up] = [a.up, a.lo] */
        iRes.loExpr = "~" + iExpr.loExpr;
        iRes.upExpr = "~" + iExpr.upExpr;
        iRes.typeStr = iExpr.typeStr;

    }
}