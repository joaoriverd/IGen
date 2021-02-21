#include <cassert>
#include "intervalExpression.h"
#include "bopExpressions.h"
#include "unaryOpExpressions.h"
#include "tempVariables.h"
#include "constantExpressions.h"
#include "commonInterval.h"
#include "util.h"
#include "ASTVisitor.h"
#include "intrinsicExpression.h"
#include "pollyReduction.h"

using namespace std;
using namespace clang;
using namespace llvm;

string intervalExpression::internalBuffer = "";

bool intervalExpression::hasBounds() {
    assert( this->loExpr.empty() == this->upExpr.empty() );
    return !this->loExpr.empty() && !this->upExpr.empty();
}

const string& intervalExpression::getVar () {

    if ( this->intervalVar.empty() ) {
        string strTempVar = TEMP_VAR_SUFIX + to_string(getVarCount());
        string tempVarType = this->typeStr;
        transformToIntervalType(tempVarType);
        internalBuffer += tempVarType + " " + strTempVar;
        internalBuffer += " = " + _iaFunName("=", this->getType()) +
                                "(" + this->getLowExpr() + ", " + this->getUpExpr() + ")" + SCNL;
        this->intervalVar = strTempVar;
        incVarCount();
    }
    else if (this->loExpr.empty() && this->upExpr.empty() && !this->isScalar) {
        string strTempVar = TEMP_VAR_SUFIX + to_string(getVarCount());
        string tempVarType = this->typeStr;
        transformToIntervalType(tempVarType);
        internalBuffer +=  tempVarType + " " + strTempVar + " = " + this->intervalVar+ ";\n    ";
        this->loExpr = strTempVar + ".lo";
        this->upExpr = strTempVar + ".up";
        this->intervalVar = strTempVar;
        incVarCount();
    }

    return this->intervalVar;
}

string getCastPostfixForType(const string& type) {
    /* Integer types */
    if (type == INT_T)   { return "i"; }
    if (type == UINT_T)  { return "u"; }
    if (type == LONG_T)  { return "l"; }
    if (type == ULONG_T) { return "ul";}
    if (type == LL_T)    { return "l"; }
    if (type == ULL_T)   { return "ul";}

    /* Floating point types */
    if (type == DD_T)     { return "dd";}
    if (type == DOUBLE_T) { return "d"; }
    if (type == FLOAT_T)  { return "f"; }
    if (type == HALF_T)   { return "h"; }

    cerr << "Type not found (getCastPostfixForType)" << endl;
    throw std::exception();
}

string getIntervalCastFunction(const string& origType, const string& resType) {

    /* This function should only be called when doing a cast between interval types.
     * If both, origin and resulting type, are integers, then throw an error. */
    if (isTypeInteger(origType) && isTypeInteger(resType)) {
        cerr << "Cast between integer types should not be translated (getIntervalCastFunction)" << endl;
        throw std::exception();
        return "";
    }

    string funcName = IA_CVT_FUN(getCastPostfixForType(origType), getCastPostfixForType(resType));
    return funcName;
}

intervalExpression intervalExpression::_constructIntervalExpr(Expr *expr) {

    if (auto *bop = dyn_cast<BinaryOperator>(expr)) {
        return _constructBopExpr(bop);
    }

    if (auto *uop = dyn_cast<UnaryOperator>(expr)) {
        return _constructUopExpr(uop);
    }

    if (auto *imcast = dyn_cast<ImplicitCastExpr>(expr)) {
        // todo: add proper cast (e.g. to convert interger to interval on doubles)
        return _constructCastExpr(imcast);
    }

    if (auto *ccast = dyn_cast<CStyleCastExpr>(expr)) {
        return _constructCastExpr(ccast);
    }

    if (auto *par = dyn_cast<ParenExpr>(expr)) {
        return _constructParenExpr(par);
    }

    if (auto *dec = dyn_cast<DeclRefExpr>(expr)) {
        return _constructDeclExpr(dec);
    }

    if (auto *il = dyn_cast<IntegerLiteral>(expr)) {
        return _constructIntLiteral(il);
    }

    if (auto *fl = dyn_cast<FloatingLiteral>(expr)) {
        return _constructFloatLiteral(fl);
    }

    if (auto *arr =  dyn_cast<ArraySubscriptExpr>(expr)) {
        return _constructArraySubscript(arr);
    }

    if (auto *me =  dyn_cast<MemberExpr>(expr)) {
        return _constructMemberExpr(me);
    }

    if (auto *ce = dyn_cast<CallExpr>(expr)) {
        return _constructCallExpr(ce);
    }

    if (auto *cop = dyn_cast<ConditionalOperator>(expr)) {
        return _constructConditionalOperator(cop);
    }

    if (auto *ile = dyn_cast<InitListExpr>(expr)) {
        /* The initialization is an init List ( e.g. arr[] = {1,2,3} ) */
        return _constructInitListExpr(ile);
    }

    if (auto *uexp = dyn_cast<UnaryExprOrTypeTraitExpr>(expr)) {
        return _constructUnaryExprOrTypeTraitExpr(uexp);
    }

    if (auto *iml = dyn_cast<ImaginaryLiteral>(expr)) {
        return _constructImaginaryLiteral(iml);
    }

    /* If this line is reached then the expression is not supported.
     * Just return the raw code then. */
    intervalExpression iRes;
    iRes.intervalVar = getRawCodeAsString(expr->getSourceRange());
    iRes.isScalar = true;

    return iRes;
}

intervalExpression intervalExpression::_constructBopExpr(BinaryOperator *bop) {
    intervalExpression iRes;
    string op = bop->getOpcodeStr().str();

    intervalExpression iLhs = _constructIntervalExpr( bop->getLHS() );

    /* Comma operator is special. Here we have to force the LHS to be evaluated first than RHS. */
    if (op == ",") {
        genTempVar(iLhs, intervalExpression::internalBuffer);
    }

    intervalExpression iRhs = _constructIntervalExpr( bop->getRHS() );
    iRes.typeStr    = getBareTypeAsString(bop->getType());
    iRes.isConstant = iLhs.isConstant && iRhs.isConstant;
    iRes.isScalar   = iLhs.isScalar   && iRhs.isScalar;

    /* Check if it is a reduction assignment */
    if (GlobalPollyReduction.isReductionAssignment(bop)) {
        /* Generate interval variable for LHS and RHS expressions if needed */
        genTempVar(iRhs, intervalExpression::getInternalBuff());

        size_t redId     = GlobalPollyReduction.getReductionIDFromAssignment(bop);
        iRes.intervalVar = getIGenReductionOperationFun(RED_ACCUMULATE, iRes.getType(), iRhs.intervalVar, redId);
        return iRes;
    }

    if ( isTypeSupported(iLhs.getType()) || isTypeSupported(iRhs.getType()) ) {

        if (op == "=") {
            if (getIntervalLib() == IAGEN)    { bopAssign(iLhs, iRhs, iRes);     }
            if (getIntervalLib() == MPFI_LIB) { bopAssignMPFI(iLhs, iRhs, iRes); }
        }

        if (op == "+") {
            if (getIntervalLib() == IAGEN)     { bopAdd(iLhs, iRhs, iRes);              }
            if (getIntervalLib() == MPFI_LIB)  { bopBasicMPFI(iLhs, iRhs, iRes, op); }
        }

        if (op == "-") {
            if (getIntervalLib() == IAGEN)     { bopSub(iLhs, iRhs, iRes);              }
            if (getIntervalLib() == MPFI_LIB)  { bopBasicMPFI(iLhs, iRhs, iRes, op); }
        }

        if (op == "*") {
            if (getIntervalLib() == IAGEN)    { bopMul(iLhs, iRhs, iRes);              }
            if (getIntervalLib() == MPFI_LIB) { bopBasicMPFI(iLhs, iRhs, iRes, op); }
        }

        if (op == "/") {
            bopDiv(iLhs, iRhs, iRes);
            if (getIntervalLib() == IAGEN)    { bopDiv(iLhs, iRhs, iRes);              }
            if (getIntervalLib() == MPFI_LIB) { bopBasicMPFI(iLhs, iRhs, iRes, op); }
        }

        if (op == "<" || op == "<=" || op == ">" || op == ">=" || op == "==" || op == "!=") {
            if (getIntervalLib() == IAGEN)    { bopComp(iLhs, iRhs, iRes, op);     }
            if (getIntervalLib() == MPFI_LIB) { bopCompMPFI(iLhs, iRhs, iRes, op); }
        }

        if (op == "+=" || op == "-=" || op == "*=" || op == "/=") {
            if (getIntervalLib() == IAGEN)    { bopCompoundAssign(iLhs, iRhs, iRes, op);        }
            if (getIntervalLib() == MPFI_LIB) { bopCompoundAssignMPFI(iLhs, iRhs, iRes, op); }
        }

        if (op == "&" || op == "|" || op == "^") {
            if (getIntervalLib() == IAGEN)    { bopBitwise(iLhs, iRhs, iRes, op);     }
        }

    }

    if (op == "||" || op == "&&") {
        /* Logical operators are done in integers. Thus, only one function for all supported libraries */
        bopLogical(iLhs, iRhs, iRes, op);
    }

    if (op == ",") {
        bopComma(iLhs, iRhs, iRes);
    }

    if (iRes.isEmpty()) {
        /* If no change was done to iRes, then keep the same expression */
        iRes.intervalVar = iLhs.intervalVar + " " + op + " " + iRhs.intervalVar;
    }

    return iRes;
}

intervalExpression intervalExpression::_constructUopExpr(UnaryOperator *uop) {
    intervalExpression iRes;
    intervalExpression iExpr = _constructIntervalExpr(uop->getSubExpr());

    iRes.typeStr = getBareTypeAsString(uop->getType());
    string op = UnaryOperator::getOpcodeStr(uop->getOpcode()).str();

    if (op == "-") {
        if (getIntervalLib() == IAGEN)     { uopMinus(iExpr, iRes);     }
        if (getIntervalLib() == MPFI_LIB)  { uopMinusMPFI(iExpr, iRes); }
    }

    if (op == "+") {
        iRes = iExpr;
    }

    /* Pointer dereference */
    if (op == "*") {
        uopDereference(iExpr, iRes);
    }

    if (op == "&") {
        iRes.intervalVar = op + iExpr.intervalVar;
        iRes.isScalar = true;
        iRes.isConstant = false;
    }

    /* auto increment/decrement */
    if (op == "++" || op == "--") {
        if (getIntervalLib() == IAGEN) { uopAutoincrement(iExpr, iRes, op, uop->isPrefix());     }
        if (getIntervalLib() == MPFI_LIB)  { uopAutoincrementMPFI(iExpr, iRes, op, uop->isPrefix()); }

    }

    /* Added to support custom integer intervals */
    if (op == "~") {
        /* NOT operation */
        if (getIntervalLib() == IAGEN)  { uopNot(iExpr, iRes);     }
    }

    if (iRes.isEmpty()) {

        /* If no change was done to iRes, then keep the same expression */
        iRes = iExpr;
        if (uop->isPostfix()) {
            iRes.intervalVar = iExpr.intervalVar + op;
        }
        else {
            iRes.intervalVar = op + iExpr.intervalVar;
        }

    }

    return iRes;
}

intervalExpression intervalExpression::_constructParenExpr(ParenExpr *par) {

    intervalExpression iRes;
    intervalExpression iExpr = _constructIntervalExpr(par->getSubExpr());
    iRes.typeStr = getBareTypeAsString(par->getType());

    if ( iExpr.isScalarExpr() && iExpr.isConstantExpr() )  {
        /* Keep parenthesis always works. Check cases where it is safe to remove them.
         * An example where it is not safe: (1 << 1) + 1*/
        iRes.intervalVar = "(" + iExpr.intervalVar + ")";
        iRes.isConstant = false;
    }
    else if ( iExpr.isIntervalExpr() ) {
        /* It's an interval variable */
        iRes.intervalVar = iExpr.intervalVar;
        if ( iExpr.hasBounds() ) {
            iRes.loExpr = "(" + iExpr.loExpr + ")";
            iRes.upExpr = "(" + iExpr.upExpr + ")";
            iRes.isConstant = false;
        }
    }
    else {
        /* Keep parenthesis for scalar expressions */
        iRes.intervalVar = "(" + iExpr.intervalVar + ")";
        iRes.isConstant = false;
    }

    iRes.isScalar   = iExpr.isScalar;
    iRes.isBoolean  = iExpr.isBoolean;

    return iRes;
}

intervalExpression intervalExpression::_constructDeclExpr(DeclRefExpr *dec) {

    intervalExpression iRes;
    iRes.typeStr     = getBareTypeAsString(dec->getType());
    iRes.intervalVar = dec->getDecl()->getName().str();

    if (isTypeSupported(iRes.typeStr)) {
        /* Datatype is an interval. */
        iRes.loExpr = iRes.intervalVar + ".lo";
        iRes.upExpr = iRes.intervalVar + ".up";
    }
    else {
        /* Datatype is not converted to interval (e.g. int, short, double*, float*, function, etc.) */
        iRes.isScalar = true;
    }

    return iRes;
}

intervalExpression intervalExpression::_constructIntLiteral(IntegerLiteral *il) {
    intervalExpression iRes;
    iRes.typeStr     = getBareTypeAsString(il->getType());
    iRes.intervalVar = il->getValue().toString(10, true);
    iRes.isConstant  = true;
    iRes.isScalar    = true;
    return iRes;
}

intervalExpression intervalExpression::_constructFloatLiteral(FloatingLiteral *fl) {

    intervalExpression iConst;
    iConst.typeStr = getBareTypeAsString(fl->getType());
    iConst.isScalar   =  false;
    iConst.isConstant =  true;

    /* Make the constant an interval */
    getConstInterval(fl, iConst);

    return iConst;
}

intervalExpression intervalExpression::_constructArraySubscript(ArraySubscriptExpr *arr) {
    intervalExpression iRes;
    iRes.typeStr = getBareTypeAsString(arr->getType());

    /* Check if it is the load of a reduction variable first. If yes, transform to a zero interval.
     * Otherwise process normally. */
    if (GlobalPollyReduction.isReductionVariable(arr)) {
        iRes.intervalVar = _iaFunName("zero", iRes.typeStr) + "()";
        return iRes;
    }

    /* Process normally */
    intervalExpression iLhs = _constructIntervalExpr( arr->getLHS() );
    intervalExpression iRhs = _constructIntervalExpr( arr->getRHS() );

    assert(iRhs.isScalar);

    iRes.typeStr = getBareTypeAsString(arr->getType());
    iRes.intervalVar = iLhs.intervalVar + "[" + iRhs.intervalVar + "]";
    if (isTypeSupported(iRes.typeStr)) {
        iRes.loExpr = iRes.intervalVar + ".lo";
        iRes.upExpr = iRes.intervalVar + ".up";
    }
    else {
        iRes.isScalar = true;
    }
    iRes.isConstant = false;
    return iRes;
}

intervalExpression intervalExpression::_constructMemberExpr(MemberExpr *me) {
    intervalExpression iRes;
    intervalExpression iBase = _constructIntervalExpr( me->getBase() );

    string accessOp = me->isArrow() ? "->" : ".";
    iRes.intervalVar = iBase.intervalVar + accessOp + me->getMemberDecl()->getNameAsString();
    iRes.typeStr = getBareTypeAsString(me->getType());

    if (isTypeSupported(iRes.typeStr)) {
        /* Datatype can be treated as interval. */
        iRes.loExpr = iRes.intervalVar + ".lo";
        iRes.upExpr = iRes.intervalVar + ".up";
    }
    else {
        iRes.isScalar = true;
    }

    return iRes;
}

string getFunName(CallExpr *ce) {
    string funDecl = rewriter.getRewrittenText(getExpandedSourceRange(ce->getSourceRange()));
    size_t idx = funDecl.find('(');

    if (idx == string::npos) {
        cerr << "Error in getFunName" << endl;
    }

    return funDecl.substr(0,idx);
}

intervalExpression intervalExpression::_constructCallExpr(CallExpr *ce) {
    intervalExpression iRes;

    /* Handle return type and function name. */
    intervalExpression iCallee = _constructIntervalExpr( ce->getCallee() );
    string funcName = iCallee.getIntervalExpr();
    iRes.typeStr  = getBareTypeAsString(ce->getType());
    iRes.isScalar = !isTypeSupported(iRes.typeStr);

    /* In case of supported math functions, translate to interval and set
     * configuration flag that interval math is used. */
    bool isIntervalMath = translateMathFun(funcName, iRes.typeStr);
    if (isIntervalMath) {
        setIntervalMathUsed();
    }

    /* Get argument variables and store names in vector */
    vector<intervalExpression> iaArgs;
    for (unsigned int i = 0; i < ce->getNumArgs(); ++i) {
        intervalExpression iArg = _constructIntervalExpr( ce->getArg(i) );
        iaArgs.push_back( iArg );
    }

    if (isIntrinsicFunction(funcName)) {
        convertIntrinsicInstruction(iRes, funcName, iaArgs);
        return iRes;
    }

    string funCall;
    if (getIntervalLib() == IAGEN || iRes.isScalar) {

        /* Create function call in variable of interval */
        funCall = funcName + "(";
        for (unsigned int i = 0; i < ce->getNumArgs(); ++i) {
            funCall += (i > 0)? ", " : "";
            funCall += iaArgs[i].getVar();
        }
        funCall += ")";
        iRes.intervalVar = funCall;

    }
    else if (getIntervalLib() == MPFI_LIB) {

        /* Functions cannot return an mpfi interval type. Thus, we change
         * the return to the first parameter of the function */
        string tempVar = genTempVarMPFI(intervalExpression::getInternalBuff());
        funCall = funcName + "(" + tempVar;
        for (unsigned int i = 0; i < ce->getNumArgs(); ++i) {
            funCall += ", " + iaArgs[i].getVar();
        }
        funCall += ")";

        intervalExpression::getInternalBuff() += funCall + SCNL;
        iRes.intervalVar = tempVar;
    }

    return iRes;
}

intervalExpression intervalExpression::_constructCastExpr(ImplicitCastExpr *imcast) {
    intervalExpression iRes = _constructIntervalExpr( imcast->getSubExpr() );
    string originalType = iRes.getType();
    string resultType   = getBareTypeAsString(imcast->getType());

    if (resultType == originalType || imcast->getCastKind() == CK_LValueToRValue || imcast->getCastKind() == CK_BitCast) {
        /* If the types are the same or the cast is only from lval to rval just return.
         * BitCast is also common when supporting e.g. comparison on vector types (e.g. _m256d).
         * We ignore bitcasts */
        iRes.typeStr = resultType;
        return iRes;
    }

    if (isTypeSupported(resultType)) {

        if (iRes.isConstantExpr() && !isTypeIntervalVector(resultType)) {
            /* Cast constant expression. Vector constants do not exist. Thus, excluding this case */
            castConstantExpr(resultType, iRes);
        }
        else if (isTypeSupported(originalType)) {
            /* Here there are two cases:
             * 1) From float_I to double_I, or from double_I to float_I.
             *    Simply cast implicitly each bound. For this, it is enough to remove
             *    the interval part.
             * 2) The resulting type is a vector type (e.g. _m256d). In this case, we have
             *    to call the function to cast it. */
            if (!isTypeIntervalVector(resultType)) {
                if (!iRes.hasBounds()) {
                    /* The expression does not have bounds (e.g. in multiplication).
                     * Thus, first introduce temporal variables */
                    genTempVar(iRes, intervalExpression::getInternalBuff());
                }

                iRes.intervalVar = "";
            }
            else {
                /* Generate interval variable if needed */
                genTempVar(iRes, intervalExpression::getInternalBuff());
                iRes.intervalVar = _iaCastFunName(originalType, resultType) + "(" + iRes.intervalVar + ")";
                iRes.loExpr = "";
                iRes.upExpr = "";
            }
        }
        else {

            /* Not supported types in interval notation are directly casted to
             * its interval counterpart. E.g. from int to double_I */
            iRes.intervalVar = getIntervalCastFunction(originalType, resultType) + "(" + iRes.intervalVar + ")";
            iRes.isScalar = false;

        }
    }

    iRes.typeStr = resultType;

    return iRes;
}

intervalExpression intervalExpression::_constructCastExpr(CStyleCastExpr *ccast) {
    intervalExpression iRes = _constructIntervalExpr( ccast->getSubExpr() );
    string originalType = iRes.getType();
    string resultType = getBareTypeAsString(ccast->getType());

    if (resultType == originalType) {
        /* If the types are the same or the cast is only from lval to rval just return. */
        return iRes;
    }

    if (isTypeSupported(resultType)) {

        if (iRes.isConstantExpr()) {
            /* Cast constant expression */
            castConstantExpr(resultType, iRes);
        }
        else if (isTypeSupported(originalType)) {

            /* From interval float to double, or from double to float.
             * Simply cast each bound. For this, we should remove
             * the interval part. */
            if (!iRes.hasBounds()) {
                /* The expression does not have bounds (e.g. in multiplication).
                 * Thus, first introduce temporal variables */
                genTempVar(iRes, intervalExpression::getInternalBuff());
            }

            iRes.intervalVar = "";
            iRes.loExpr  = "(" + resultType + ") " + iRes.loExpr;
            iRes.upExpr  = "(" + resultType + ") " + iRes.upExpr;

        }
        else {

            /* Not supported types in interval notation are directly casted to
             * its interval counterpart. */
            iRes.intervalVar = getIntervalCastFunction(originalType, resultType) + "(" + iRes.intervalVar + ")";
            iRes.isScalar = false;

        }
    }
    else if (isTypeSupported(originalType)) {
        /* The origin type is interval bt not the resulting type. This is not
         * really supported but we still convert it to a function. */
        cerr << "Warning: Cast from an interval to an scalar type." << endl;
        iRes.intervalVar = getIntervalCastFunction(originalType, resultType) + "(" + iRes.intervalVar + ")";
        iRes.isScalar = true;
    }
    else {
        /* The types are not interval types. Keep explicit cast. */
        if (isTypeTransformable(resultType)) {
            /* The type is transformable to interval but not necessarily
             * an interval type, e.g. (double *) */
            transformToIntervalType(resultType);
        }
        iRes.intervalVar = "(" + resultType + ") " + iRes.intervalVar;
    }

    iRes.typeStr = resultType;

    return iRes;
}

intervalExpression intervalExpression::_constructConditionalOperator(ConditionalOperator *cop) {
    intervalExpression iRes;
    intervalExpression iCond = _constructIntervalExpr( cop->getCond() );
    intervalExpression iLhs  = _constructIntervalExpr( cop->getLHS()  );
    intervalExpression iRhs  = _constructIntervalExpr( cop->getRHS()  );

    iRes.intervalVar = iCond.getVar() + " ? " + iLhs.getVar() + " : " + iRhs.getVar();
    iRes.typeStr = getBareTypeAsString(cop->getType());
    iRes.isScalar = iLhs.isScalar && iRhs.isScalar;

    return iRes;
}

intervalExpression intervalExpression::_constructInitListExpr(InitListExpr *ile) {
    /* This is an init expression (e.g. float arr[] = {1.0, 2.0, ..}).
     * Thus, we have to iterate through the elements in the list and process
     * them individually. Afterwards we enclose the parameters of the list
     * with curly brackets and separate using commas. */

    intervalExpression iRes;

    iRes.intervalVar = "{";

    for (size_t i = 0; i < ile->getNumInits(); ++i) {
        intervalExpression iExpr = _constructIntervalExpr( ile->getInit(i) );

        string strInitList;
        if (iExpr.isConstantExpr()) {
            strInitList = iExpr.isScalarExpr() ? iExpr.getIntervalExpr()
                                              : "{" + iExpr.getLowExpr() + ", " + iExpr.getUpExpr() + "}";
        }
        else {
            genTempIntervalVar(iExpr, intervalExpression::getInternalBuff());
            strInitList = iExpr.getIntervalExpr();
        }

        iRes.intervalVar += strInitList;
        iRes.intervalVar += (i < ile->getNumInits()-1) ? ", " : "";
    }

    iRes.intervalVar += "}";
    iRes.isScalar   = true;

    return iRes;
}

intervalExpression intervalExpression::_constructUnaryExprOrTypeTraitExpr(UnaryExprOrTypeTraitExpr *uexp) {
    /* This is to support sizeof (e.g. sizeof(double)) */
    intervalExpression iRes;

    if (uexp->getKind() == UETT_SizeOf || uexp->getKind() == UETT_AlignOf) {
        /* Only sizeof and alignof are supported for now */
        iRes.typeStr = getTypeAsString(uexp->getType());
        string argType = getTypeAsString(uexp->getTypeOfArgument());
        transformToIntervalType(argType);

        iRes.intervalVar = (uexp->getKind() == UETT_SizeOf) ? SIZEOF(argType) : ALIGNOF(argType);
    }
    else {
        iRes.intervalVar = getRawCodeAsString(uexp->getSourceRange());
    }

    iRes.isScalar = true;
    return iRes;
}

intervalExpression intervalExpression::_constructImaginaryLiteral(ImaginaryLiteral *iml) {
    /* An imaginary literal is just a wrapper for the underlying literal. This is used also to
     * detect tolerance. In case of underlying floating point type. Convert the values to tolerance
     * around zero */
    intervalExpression iRes = _constructIntervalExpr(iml->getSubExpr());
    iRes.typeStr = getBareTypeAsString(iml->getType());

    return iRes;
}

intervalExpression& intervalExpression::operator=(const intervalExpression& rhs) {
    if (this != &rhs) {
        intervalVar = rhs.intervalVar;
        loExpr      = rhs.loExpr;
        upExpr      = rhs.upExpr;
        typeStr     = rhs.typeStr;
        isConstant  = rhs.isConstant;
        isBoolean   = rhs.isBoolean;
        isScalar    = rhs.isScalar;
        *loConst    = *rhs.loConst;
        *upConst    = *rhs.upConst;
    }
    return *this;
}