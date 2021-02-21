#include "tempVariables.h"
#include "commonInterval.h"

using namespace std;

static size_t varCount = 1;


//
// Generates temporal variable
//
string genTempVar (string& type, string &buff) {
    string strTempVar = TEMP_VAR_SUFIX + to_string(getVarCount());
    string tempVarType = type;
    transformToIntervalType(tempVarType);
    buff += tempVarType + " " + strTempVar + SCNL;
    incVarCount();
    return strTempVar;
}

//
// Generates temporal variable if needed
//
void genTempVar (intervalExpression &iExpr, string &buff) {
    if (iExpr.isIntervalExpr()) {
        if (iExpr.getIntervalExpr().empty()) {
            string strTempVar = TEMP_VAR_SUFIX + to_string(getVarCount());
            string tempVarType = iExpr.getType();
            transformToIntervalType(tempVarType);
            buff += tempVarType + " " + strTempVar;
            buff += " = " + _iaFunName("=", iExpr.getType()) + "(" + iExpr.getLowExpr() + ", " + iExpr.getUpExpr() + ")" + SCNL;
            iExpr.getLowExpr() = strTempVar + ".lo";
            iExpr.getUpExpr() = strTempVar + ".up";
            iExpr.getIntervalExpr() = strTempVar;
            incVarCount();
        }
        else if (iExpr.getLowExpr().empty() && iExpr.getUpExpr().empty()) {
            string strTempVar = TEMP_VAR_SUFIX + to_string(getVarCount());
            string tempVarType = iExpr.getType();
            transformToIntervalType(tempVarType);
            buff += tempVarType + " " + strTempVar + " = " + iExpr.getIntervalExpr()+ ";\n    ";
            iExpr.getLowExpr() = strTempVar + ".lo";
            iExpr.getUpExpr() = strTempVar + ".up";
            iExpr.getIntervalExpr() = strTempVar;
            incVarCount();
        }
    }
    else {
        string strTempVar = TEMP_VAR_SUFIX + to_string(getVarCount());
        buff +=  iExpr.getType() + " " + strTempVar + " = " + iExpr.getIntervalExpr()+ ";\n    ";
        iExpr.getIntervalExpr() = strTempVar;
        incVarCount();
    }

}

string genTempVarMPFI (string &buff) {

    /* Declare and init temporal variable */
    string tempVar = TEMP_VAR_SUFIX + to_string(getVarCount());
    buff +=  MPFI_TYPE " " + tempVar + ";\n    ";
    buff +=  "mpfi_init2(" + tempVar + ", MPFI_PRECISION);\n    ";
    incVarCount();

    return tempVar;
}

//
// Generates temporal interval variable if needed
//
void genTempIntervalVar (intervalExpression &iExpr, string &buff) {
    if (iExpr.getIntervalExpr().empty()) {
        string strTempVar = TEMP_VAR_SUFIX + to_string(getVarCount());
        string tempVarType = iExpr.getType();
        transformToIntervalType(tempVarType);
        buff += tempVarType + " " + strTempVar + ";\n    ";
        buff += strTempVar + ".lo = " + iExpr.getLowExpr() + ";\n    ";
        buff += strTempVar + ".up = "  + iExpr.getUpExpr()  + ";\n    ";
        iExpr.getLowExpr() = strTempVar + ".lo";
        iExpr.getUpExpr() = strTempVar + ".up";
        iExpr.getIntervalExpr() = strTempVar;
        incVarCount();
    }
}

size_t getVarCount () {
    return varCount;
}

void incVarCount () {
    varCount++;
}