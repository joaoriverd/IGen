#include <iostream>
#include "llvm/Support/raw_ostream.h"
#include "bopExpressions.h"
#include "commonInterval.h"
#include "tempVariables.h"
#include "constantExpressions.h"
#include "util.h"

using namespace std;


#define SET_AS_FUNCTION
void bopAssign (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes) {

#ifdef SET_AS_FUNCTION
    if (iRhs.isConstant) {
        string type = iRes.getType();
        iRes.intervalVar = iLhs.intervalVar + " = " + _iaFunName("=", type) + "(" + iRhs.loExpr + ", " + iRhs.upExpr + ")";
    }
    else if (iRhs.intervalVar.empty()) {
        /* Generate code for assignment operator */
        iRes.loExpr = iLhs.loExpr + " = " + iRhs.loExpr;
        iRes.upExpr = iLhs.upExpr + " = " + iRhs.upExpr;
    }
    else {
        iRes.intervalVar = iLhs.intervalVar + " = " + iRhs.intervalVar;
    }
#else
    /* Generate code for assignment operator */
    iRes.loExpr = iLhs.loExpr + " = " + iRhs.loExpr;
    iRes.upExpr = iLhs.upExpr + " = " + iRhs.upExpr;

    /* Generate temporal variable if needed */
    if (iRhs.intervalVar.empty()) {
        std::string declVar, tempVar;
        if (iRes.upExpr.find(iLhs.loExpr) != std::string::npos) {
            tempVar = TEMP_VAR_SUFIX + std::to_string(getVarCount());
            declVar = iLhs.typeStr + " " + tempVar;
            intervalExpression::getInternalBuff() += declVar + " = " + iLhs.loExpr + SCNL;
            replaceSubString(iRes.upExpr, iLhs.loExpr, tempVar);
            incVarCount();
            llvm::errs() << "** Temporal variable generated for: " << iLhs.loExpr << NL;
        }
    }
    else {
        iRes.intervalVar = iLhs.intervalVar + " = " + iRhs.intervalVar;
    }
#endif

    if (iLhs.isIntervalExpr() && iRhs.isScalarExpr()) {
        /* This case can only happened when handling custom vector types, e.g. vec256d. The reason is
         * that lhs can have type u64_I whereas rhs can have uint64. Thus, for this case, the rhs has to be
         * duplicated, i.e. lhs.lo = rhs, lhs.up = rhs. */

        /* It is a transformation from a non supported type to a custom integer interval,
         * e.g. int to u32_I. Transform to interval paying attention to the sign
         * of the lower bound */
        intervalExpression iTemp = iRhs;
        int signBit = iLhs.getType() == UINT32_T ? 31 : 63;

        genTempVar(iTemp, intervalExpression::getInternalBuff());
        iRhs.intervalVar = "";
        iRhs.loExpr = TOOGLE_BIT_MACRO(iTemp.intervalVar, to_string(signBit));
        iRhs.upExpr = iTemp.intervalVar;

        iRes.intervalVar = "";
        iRes.loExpr = iLhs.loExpr + " = " + iRhs.loExpr;
        iRes.upExpr = iLhs.upExpr + " = " + iRhs.upExpr;
    }
}

void bopMul (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes) {

    if (iLhs.isConstant && iRhs.isConstant) {
        mulConstantInterval(iLhs, iRhs, iRes);
    }
    else {

        string type = iRes.getType();

        /* Generate interval variable for LHS and RHS expressions if needed */
        genTempVar(iLhs, intervalExpression::getInternalBuff());
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        /* Multiplication only generates interval variable */
        iRes.intervalVar = _iaFunName("*", type) + "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";

    }
}

void bopDiv (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes) {

    if (iLhs.isConstant && iRhs.isConstant) {
        divConstantInterval(iLhs, iRhs, iRes);
    }
    else {

        string type = iRes.getType();

        /* Generate interval variable for LHS and RHS expressions if needed */
        genTempVar(iLhs, intervalExpression::getInternalBuff());
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        /*Division only generates interval variable */
        iRes.intervalVar = _iaFunName("/", type) + "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";

    }
}

#define ADD_AS_FUNCTION
void bopAdd (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes) {

#ifdef ADD_AS_FUNCTION
    /* This may be less efficient, but unifies how basic operations are transformed (all using a corresponding function) */
    if (iLhs.isConstant && iRhs.isConstant) {
        addConstantInterval(iLhs, iRhs, iRes);
    }
    else {
        string type = iRes.getType();

        /* Generate interval variable for LHS and RHS expressions if needed */
        genTempVar(iLhs, intervalExpression::getInternalBuff());
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        iRes.intervalVar = _iaFunName("+", type) + "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";
    }
#else
    /* Special case for double-double types */
    string type = iRes.getType();
    if (type == DD_T) {
        /* Generate interval variable for LHS and RHS expressions if needed */
        genTempVar(iLhs, intervalExpression::getInternalBuff());
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        /*Division only generates interval variable */
        iRes.intervalVar = _iaFunName("+", type) + "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";

        return;
    }

    if (iLhs.isConstant && iRhs.isConstant) {
        addConstantInterval(iLhs, iRhs, iRes);
    } else {
        /* Generate temporal variable if needed */
        if (!iLhs.hasBounds()) { genTempVar(iLhs, intervalExpression::getInternalBuff()); }
        if (!iRhs.hasBounds()) { genTempVar(iRhs, intervalExpression::getInternalBuff()); }
        iRes.loExpr = iLhs.loExpr + " + " + iRhs.loExpr;
        iRes.upExpr = iLhs.upExpr + " + " + iRhs.upExpr;
    }
#endif
}

void bopSub (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes) {
#ifdef ADD_AS_FUNCTION
    /* This may be less efficient, but unifies how basic operations are transformed (all using a corresponding function) */
    if (iLhs.isConstant && iRhs.isConstant) {
        subConstantInterval(iLhs, iRhs, iRes);
    }
    else {
        string type = iRes.getType();

        /* Generate interval variable for LHS and RHS expressions if needed */
        genTempVar(iLhs, intervalExpression::getInternalBuff());
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        iRes.intervalVar = _iaFunName("-", type) + "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";
    }
#else
    /* Special case for double-double types */
    string type = iRes.getType();
    if (type == DD_T) {
        /* Generate interval variable for LHS and RHS expressions if needed */
        genTempVar(iLhs, intervalExpression::getInternalBuff());
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        /*Division only generates interval variable */
        iRes.intervalVar = _iaFunName("-", type) + "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";

        return;
    }

    if (iLhs.isConstant && iRhs.isConstant) {
        /* Handle case when rhs and lhs expressions are constants */
        subConstantInterval(iLhs, iRhs, iRes);
    } else {
        /* Generate temporal variable if needed */
        if (!iLhs.hasBounds()) { genTempVar(iLhs, intervalExpression::getInternalBuff()); }
        if (!iRhs.hasBounds()) { genTempVar(iRhs, intervalExpression::getInternalBuff()); }
        iRes.loExpr = iLhs.loExpr + " + " + iRhs.upExpr;
        iRes.upExpr = iLhs.upExpr + " + " + iRhs.loExpr;
    }
#endif
}

void bopComp (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes, string& op) {
    /* The type of the operands should be the same. Take one. */
    assert(iLhs.typeStr == iRhs.typeStr);
    string type = iLhs.getType();

    if (iLhs.isConstant && iRhs.isConstant) {
        /* Handle case when rhs and lhs expressions are constants */
        cmpConstantInterval(iLhs, iRhs, iRes, op);
    } else {
        /*Generate interval variable for LHS and RHS expressions if needed */
        genTempVar(iLhs, intervalExpression::getInternalBuff());
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        /* Comparison only generates logical expression */
        iRes.intervalVar = _iaFunName(op, type) + "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";
    }

    /* Update interval expression kind. Logical and scalar */
    if (!isTypeIntervalVector(type)) {
        iRes.isScalar  = true;
        iRes.isBoolean = isTypeSupported(type) && !iRes.isConstant ? ThreeValuedLogic : BooleanLogic;
    }
}

void bopCompoundAssign (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes, string& op) {

    if (iRhs.getIntervalExpr().empty()) {
        /* Add parenthesis to preserve floating point arithmetic */
        iRhs.loExpr = "(" + iRhs.loExpr + ")";
        iRhs.upExpr = "(" + iRhs.upExpr + ")";
    }

    if (op == "+=") {
        bopAdd(iLhs, iRhs, iRes);
    }

    if (op == "-=") {
        bopSub(iLhs, iRhs, iRes);
    }

    if (op == "*=") {
        bopMul(iLhs, iRhs, iRes);
    }

    if (op == "/=") {
        bopDiv(iLhs, iRhs, iRes);
    }

    bopAssign(iLhs, iRes, iRes);
    iRes.isBoolean = NonBoolean;
}

/* Bitwise operations are mainly for costume integer intervals, e.g. in vec256d. */
void bopBitwise (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes, string& op) {

    /* Generate temporal variable if needed */
    string lhs_lo, lhs_up, rhs_lo, rhs_up;

    if (op == "^") {
        /* XOR can be transformed directly in the upper and lower bounds */
        if (iLhs.isIntervalExpr()) {
            lhs_lo = iLhs.loExpr;
            lhs_up = iLhs.upExpr;

            iRes.typeStr = iLhs.typeStr;
        }
        else {
            lhs_lo = iLhs.intervalVar;
            lhs_up = iLhs.intervalVar;
        }

        if (iRhs.isIntervalExpr()) {
            rhs_lo = iRhs.loExpr;
            rhs_up = iRhs.upExpr;
            iRes.typeStr = iRhs.typeStr;
        }
        else {
            rhs_lo = iRhs.intervalVar;
            rhs_up = iRhs.intervalVar;
        }

        iRes.loExpr = lhs_lo + " " + op + " " + rhs_lo;
        iRes.upExpr = lhs_up + " " + op + " " + rhs_up;
        iRes.isBoolean = NonBoolean;

        return;
    }

    if (iLhs.isIntervalExpr() && iRhs.isIntervalExpr()) {

        iRes.typeStr = iRhs.typeStr; // should be the same as iLhs.typeStr

        genTempVar(iLhs, intervalExpression::getInternalBuff());
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        iRes.intervalVar = _iaFunName(op, iRes.typeStr) + "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";
        iRes.loExpr = "";
        iRes.upExpr = "";
        iRes.isBoolean = NonBoolean;
    }
    else {
        std::cerr << "Error: Bit wise and/or not yet supported for types other than u32_I and u64_I" << endl;
    }

}

void bopLogical (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes, string& op) {

    iRes.isBoolean = (iLhs.isThreeValuedLogic() || iRhs.isThreeValuedLogic()) ? ThreeValuedLogic :  BooleanLogic;

    if (iLhs.isConstant && iRhs.isConstant) {
        /* todo: Handle logical operations on constant integers */
        iRes.intervalVar = iLhs.intervalVar + " " + op + " " + iRhs.intervalVar;
    }
    else if (iRes.isThreeValuedLogic()){
        /* At least one of the operands is a tribool. In case one operand is a normal bool, first
         * translate to tribool in order to compare. */
        if (!iRhs.isThreeValuedLogic() || !iLhs.isThreeValuedLogic()) {
            intervalExpression& iBool = iRhs.isThreeValuedLogic() ? iLhs : iRhs;
            iBool.intervalVar = IA_CVT2TB_FUN "(" + iBool.intervalVar + ")";
            iBool.isBoolean = ThreeValuedLogic;
        }

        /*Generate interval variable for LHS and RHS expressions if needed */
        genTempVar(iLhs, intervalExpression::getInternalBuff());
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        /* Comparison only generates logical expression */
        iRes.intervalVar = _iaFunName(op, "") + "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";
    }
    else {
        /* Generate temporal variable if needed */
        iRes.intervalVar = iLhs.intervalVar + " " + op + " " + iRhs.intervalVar;
    }


}

void bopComma(intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes) {
    /* The comma operator stays as it is. Simply add extra parenthesis just in case. This is because the comma
     * operator has the lowest precedence. Thus, when handling expressions such as "d1 = (expr1, expr2, expr3) + d2"
     * will result in code similar to:
     *   _t1 = expr1;
     *   _t2 = _t1, expr2  (no parenthesis by default here, thus wrong)
     *   _t3 = (_t2, expr3)
     *   d1 = _ia_add_f64(_t3, d2).
     *
     *   Clearly the second line is wrong because the assignment operator has higher precedence. Thus, we insert always
     *   a parenthesis to avoid this nasty cases */
    iRes.intervalVar = "(" + iLhs.intervalVar + ", " + iRhs.intervalVar + ")";
}