#include "bopExpressions.h"
#include "commonInterval.h"
#include "tempVariables.h"

using namespace std;

static string _iaFunName(string& op) {

    /* Basic operators */
    if (op == "=")  { return MPFI_SET;  }
    if (op == "+")  { return MPFI_ADD;    }
    if (op == "-")  { return MPFI_SUB;    }
    if (op == "*")  { return MPFI_MUL;    }
    if (op == "/")  { return MPFI_DIV;    }

    /* Comparison operators */
    if (op == "<")  { return MPFI_CMPL;   }
    if (op == "<=") { return MPFI_CMPLEQ; }
    if (op == ">")  { return MPFI_CMPG;   }
    if (op == ">=") { return MPFI_CMPGEQ; }
    if (op == "==") { return MPFI_CMPEQ;  }

    throw std::exception();
}

void bopBasicMPFI (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes,  std::string& op) {

    string op1, op2, op3;

    /* Create temporal variable to hold result of operation */
    op1 = genTempVarMPFI(intervalExpression::getInternalBuff());
    op2 = iLhs.intervalVar;
    op3 = iRhs.intervalVar;

    /* Generate temporal variable for constant operands */
    if (iLhs.isConstantExpr()) {
        op2 = genTempVarMPFI(intervalExpression::getInternalBuff());
        intervalExpression::getInternalBuff() += MPFI_ASSIGN_CONST(op2, iLhs.loExpr, iLhs.upExpr) + SCNL;
    }

    if (iRhs.isConstantExpr()) {
        op3 = genTempVarMPFI(intervalExpression::getInternalBuff());
        intervalExpression::getInternalBuff() += MPFI_ASSIGN_CONST(op3, iRhs.loExpr, iRhs.upExpr) + SCNL;
    }

    /* Call operation function */
    string funName = _iaFunName(op);
    intervalExpression::getInternalBuff() += funName + "(" + op1 + ", "
                                                           + op2 + ", "
                                                           + op3 + ")" SCNL;

    /* In MPFI we always use temporal variables for constants */
    iRes.isConstant = false;
    iRes.intervalVar = op1;

}

void bopAssignMPFI (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes) {

    if ( iRhs.isConstantExpr() ) {
        intervalExpression::getInternalBuff() += MPFI_ASSIGN_CONST(iLhs.intervalVar, iRhs.loExpr, iRhs.upExpr) + SCNL;
    }
    else {
        intervalExpression::getInternalBuff() += MPFI_ASSIGN(iLhs.intervalVar, iRhs.intervalVar) + SCNL;
    }

    iRes.intervalVar = iLhs.intervalVar;

}

void bopCompMPFI (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes, std::string& op) {

    string op1, op2;

    op1 = iLhs.intervalVar;
    op2 = iRhs.intervalVar;

    /* Generate temporal variable for constant operands */
    if (iLhs.isConstantExpr()) {
        op1 = genTempVarMPFI(intervalExpression::getInternalBuff());
        intervalExpression::getInternalBuff() += MPFI_ASSIGN_CONST(op1, iLhs.loExpr, iLhs.upExpr) + SCNL;
    }

    if (iRhs.isConstantExpr()) {
        op2 = genTempVarMPFI(intervalExpression::getInternalBuff());
        intervalExpression::getInternalBuff() += MPFI_ASSIGN_CONST(op2, iRhs.loExpr, iRhs.upExpr) + SCNL;
    }

    /* Call operation function */
    string funName = _iaFunName(op);
    iRes.intervalVar += funName + "("
                                + op1 + ", "
                                + op2 + ")";

    /* In MPFI we always use temporal variables for constants */
    iRes.isConstant = false;
    iRes.isBoolean = BooleanLogic;
}

void bopCompoundAssignMPFI (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes, std::string& op) {

    /* Get the basic operator first */
    std::string basic_op = op.substr(0, 1);

    /* Perform transformation */
    bopBasicMPFI(iLhs, iRhs, iRes, basic_op);
    bopAssignMPFI(iLhs, iRes, iRes);
    iRes.isBoolean = NonBoolean;
}
