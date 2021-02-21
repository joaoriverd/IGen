#include "unaryOpExpressions.h"
#include "llvm/Support/raw_ostream.h"
#include "commonInterval.h"
#include "tempVariables.h"
#include "constantExpressions.h"

using namespace std;

void uopMinusMPFI (intervalExpression& iExpr, intervalExpression& iRes) {

    string op1, op2;

    /* Create temporal variable to hold result of operation */
    op1 = genTempVarMPFI(intervalExpression::getInternalBuff());
    op2 = iExpr.intervalVar;

    iRes.isScalar   = iExpr.isScalar;
    iRes.isConstant = iExpr.isConstant;
    if ( iExpr.isScalarExpr() ) {
        iRes.intervalVar = "-" + iExpr.intervalVar;
    }
    else {

        /* Generate temporal variable for constant operands */
        if (iExpr.isConstantExpr()) {
            op2 = genTempVarMPFI(intervalExpression::getInternalBuff());
            intervalExpression::getInternalBuff() += "mpfi_interv_d("
                                                     + op2 + ", "
                                                     + iExpr.loExpr + ", "
                                                     + iExpr.upExpr + ");"
                                                     + NLSS;
        }

        /* Call negation mpfi function */
        string funName = "mpfi_neg";
        intervalExpression::getInternalBuff() += funName + "("
                                                 + op1 + ", "
                                                 + op2 + ");"
                                                 + NLSS;
    }

    /* In MPFI we always use temporal variables for constants */
    iRes.isConstant = false;
    iRes.intervalVar = op1;
}

void uopAutoincrementMPFI (intervalExpression& iExpr, intervalExpression& iRes, string& op, bool is_prefix) {

    iRes.isScalar = iExpr.isScalar;
    if ( iRes.isScalarExpr() ) {
        iRes.intervalVar = is_prefix ? op + iExpr.intervalVar : iExpr.intervalVar + op;
    }
    else {

        string op1, op2, op3, funName;
        op1 = iExpr.intervalVar;
        op2 = iExpr.intervalVar;
        op3 = "1.0";
        iRes.intervalVar = iExpr.intervalVar;
        funName = (op == "++") ? "mpfi_add_d" : "mpfi_sub_d";

        if ( !is_prefix ) {

            /* It is postfix autoincrement. Create temporal */
            /* variable to hold result of operation         */
            string temp = genTempVarMPFI(intervalExpression::getInternalBuff());
            intervalExpression::getInternalBuff() += "mpfi_set("
                                                     + temp + ", "
                                                     + op2  + ");"
                                                     + NLSS;

            iRes.intervalVar = temp;
        }

        intervalExpression::getInternalBuff() += funName + "("
                                                 + op1 + ", "
                                                 + op2 + ", "
                                                 + op3 + ");"
                                                 + NLSS;
    }
}