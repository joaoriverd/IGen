#include "genVarDecl.h"
#include "commonInterval.h"
#include "tempVariables.h"
#include "util.h"

using namespace std;
using namespace clang;

static size_t findVarPositionWithinType(string& type) {

    size_t pos;

    /* Check for array type */
    pos = type.find('[');
    if (pos != string::npos) {
        return pos;
    }

    /* Check for function pointer type */
    pos = type.find("(*)");
    if (pos != string::npos) {
        pos += 2;
        return pos;
    }

    return string::npos;
}

genVarDecl::genVarDecl(VarDecl *var) {

    switch (getIntervalLib()) {

        case IAGEN :
            _constructDeclaration(var);
            if (var->hasInit()) {
                _constructInit(var->getInit());
            }
            break;

        case MPFI_LIB :
            _constructDeclarationMPFI(var);
            if (var->hasInit()) {
                _constructInitMPFI(var);
            }
            break;

        default: break;
    }

}

genVarDecl::genVarDecl(FieldDecl *var) {

    switch (getIntervalLib()) {

        case IAGEN :
            _constructDeclaration(var);
            break;

        case MPFI_LIB :
            _constructDeclarationMPFI(var);
            break;

        default: break;
    }

}

void genVarDecl::_constructDeclaration(VarDecl *var){

    string varUnqualType = getTypeAsString(var->getType());
    isIntervalType = isTypeSupported(varUnqualType);
    string varType = getTypeAsString(var->getType(), true);
    transformToIntervalType(varUnqualType);
    transformToIntervalType(varType);

    this->type = (isIntervalType) ? varUnqualType : varType;
    this->name = var->getName().str();
    this->storageClass = var->getStorageClass() == SC_Static  ? "static " : "";

    /* Find where to put variable in the type. E.g. double[10] and void (*)(int) are
     * types in which the variable should be placed in the middle. */
    size_t arrTypePos = findVarPositionWithinType(this->type);

    if (arrTypePos == string::npos) {
        /* This is a normal type. The variable is placed after the type declaration. */
        this->decl = this->storageClass + this->type + " " + this->name;
    }
    else {
        /* Handle case when type is an array, or function pointer */
        this->decl = this->storageClass + this->type.insert(arrTypePos, this->name);
    }
}

void genVarDecl::_constructDeclaration(FieldDecl *var){

    string varUnqualType = getTypeAsString(var->getType());
    string varType       = getTypeAsString(var->getType(), true);
    transformToIntervalType(varUnqualType);
    transformToIntervalType(varType);

    isIntervalType = isTypeSupported(varUnqualType);
    this->type = (isIntervalType) ? varType : varUnqualType;
    this->name = var->getName().str();

    size_t arrTypePos = findVarPositionWithinType(varType);

    if (arrTypePos == string::npos) {

        /* Not an array. Thus, handled normally. */
        this->decl = this->type + " " + this->name;

    }
    else {

        /* Handle case when type is an array */
        this->decl = this->type.insert(arrTypePos, this->name);

    }
}

void genVarDecl::_constructDeclarationMPFI(VarDecl *var){

    _constructDeclaration(var);
    string varBaseType = getTypeAsString(var->getType());

    /* Only init the precision when type is an interval object (not a pointer to interval) */
    if ( isTypeSupported(varBaseType) ) {
        this->definition = MPFI_INIT_VAR(this->name);
    }
}

void genVarDecl::_constructDeclarationMPFI(FieldDecl *var){
    _constructDeclaration(var);

    /* No initialization of variable when declared in a field (e.g. in struct) */
}

void genVarDecl::_constructInit(Expr *initExpr){

    /* Construct interval expression based on init expression */
    intervalExpression iInit(initExpr);

    string strInitVal;
    if (iInit.isConstantExpr()) {
        strInitVal = iInit.isScalarExpr() ? iInit.getIntervalExpr()
                                          : "{" + iInit.getLowExpr() + ", " + iInit.getUpExpr() + "}";
    }
    else {
        genTempIntervalVar(iInit, iInit.getBuff());
        strInitVal = iInit.getIntervalExpr();
    }

    this->init = iInit.getBuff();
    this->definition = strInitVal;
}

void genVarDecl::_constructInitMPFI(VarDecl *var){

    /* Construct interval expression based on init expression */
    intervalExpression iInit(var->getInit());
    this->init = iInit.getBuff();

    if (isIntervalType) {
        string strInit;
        if (iInit.isConstantExpr()) {
            strInit = MPFI_ASSIGN_CONST(this->name, iInit.getLowExpr(), iInit.getUpExpr());
        }
        else {
            strInit = MPFI_ASSIGN(this->name, iInit.getIntervalExpr());
        }
        this->definition += SCNL + strInit;
    }
    else {
        /* Not an interval type. Thus handle normally */
        this->definition =  iInit.getIntervalExpr();
    }

}

std::string genVarDecl::getInit() {
    return this->init;
}

std::string genVarDecl::getDecl() {
    return this->decl;
}

std::string genVarDecl::getCompleteDecl() {

    string completeDecl;

    if (this->definition.empty()) {
        /* The variable is only declared */
        completeDecl = this->decl;
    }
    else if ( getIntervalLib() == IAGEN || !isIntervalType ) {
        completeDecl = this->init + this->decl + " = "  + this->definition;
    }
    else if (getIntervalLib() == MPFI_LIB) {
        completeDecl = this->init + this->decl + SCNL + this->definition;
    }

    return completeDecl;
}

bool genVarDecl::isParameterDecl (clang::VarDecl *var) {
    return (var->isLocalVarDeclOrParm() && !var->isLocalVarDecl());
}

