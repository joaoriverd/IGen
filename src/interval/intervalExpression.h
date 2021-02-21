#ifndef INTERVAL_ARITHMETIC_INTERVALEXPRESSION_H
#define INTERVAL_ARITHMETIC_INTERVALEXPRESSION_H

#include "clang/AST/AST.h"
#include "commonInterval.h"

enum eBooleanType {
    NonBoolean = 0,
    BooleanLogic,
    ThreeValuedLogic
};

class intervalExpression {
private:
    static std::string internalBuffer;
    std::string buff;

    intervalExpression _constructIntervalExpr (clang::Expr *st);
    intervalExpression _constructBopExpr(clang::BinaryOperator *bop);
    intervalExpression _constructUopExpr(clang::UnaryOperator *uop);
    intervalExpression _constructParenExpr(clang::ParenExpr *par);
    intervalExpression _constructDeclExpr(clang::DeclRefExpr *dec);
    intervalExpression _constructIntLiteral(clang::IntegerLiteral *il);
    intervalExpression _constructFloatLiteral(clang::FloatingLiteral *fl);
    intervalExpression _constructArraySubscript(clang::ArraySubscriptExpr *arr);
    intervalExpression _constructMemberExpr(clang::MemberExpr *me);
    intervalExpression _constructCallExpr(clang::CallExpr *ce);
    intervalExpression _constructCastExpr(clang::ImplicitCastExpr *imcast);
    intervalExpression _constructCastExpr(clang::CStyleCastExpr *ccast);
    intervalExpression _constructConditionalOperator(clang::ConditionalOperator *imcast);
    intervalExpression _constructInitListExpr(clang::InitListExpr *ile);
    intervalExpression _constructUnaryExprOrTypeTraitExpr(clang::UnaryExprOrTypeTraitExpr *ile);
    intervalExpression _constructImaginaryLiteral(clang::ImaginaryLiteral *iml);

public:

    //
    // todo: Make this private variables
    //
    std::string intervalVar;
    std::string loExpr;
    std::string upExpr;
    std::string typeStr;
    llvm::APFloat* loConst = new llvm::APFloat(0.0);
    llvm::APFloat* upConst = new llvm::APFloat(0.0);
    //
    // todo: instead of having flags. Make an enum type with the different option.
    //       you can call it "variable kind"
    //
    bool isConstant = false;
    bool isScalar   = false;
    eBooleanType isBoolean = NonBoolean;

    intervalExpression () {
        intervalVar = "";
        loExpr = "";
        upExpr = "";
        typeStr = "";
    };

    intervalExpression (clang::Expr *expr) {
        intervalExpression iExpr = _constructIntervalExpr(expr);
        intervalVar = iExpr.intervalVar;
        loExpr      = iExpr.loExpr;
        upExpr      = iExpr.upExpr;
        typeStr     = iExpr.typeStr;
        isConstant  = iExpr.isConstant;
        isBoolean   = iExpr.isBoolean;
        isScalar    = iExpr.isScalar;
        *loConst    = *iExpr.loConst;
        *upConst    = *iExpr.upConst;
        buff        = internalBuffer;
        internalBuffer.clear();
    }

    ~intervalExpression() {
        //assert(loConst == nullptr || upConst == nullptr);
        if (loConst == nullptr && upConst == nullptr) {
            delete loConst;
            delete upConst;
        }
    }

    intervalExpression& operator=(const intervalExpression& rhs);

    const std::string& getVar ();

    std::string& getIntervalExpr () {
        return intervalVar;
    }

    std::string& getLogicalExpr () {
        return intervalVar;
    }

    std::string& getLowExpr () {
        return loExpr;
    }

    std::string& getUpExpr () {
        return upExpr;
    }

    std::string& getBuff () {
        return buff;
    }

    bool isLogicalExpr () {
        return isBoolean == BooleanLogic || isBoolean == ThreeValuedLogic;
    }

    bool isThreeValuedLogic () {
        return isBoolean == ThreeValuedLogic;
    }

    bool isScalarExpr () {
        return isScalar;
    }

    bool isIntervalExpr () {
        return !isScalar;
    }

    bool isConstantExpr () {
        return isConstant;
    }

    static std::string& getInternalBuff () {
        return internalBuffer;
    }

    const std::string& getType() {
        return typeStr;
    }

    bool hasBounds();

    bool isEmpty(){
        return getLowExpr().empty() && \
               getUpExpr().empty()  && \
               getIntervalExpr().empty();
    }

    bool isOneLineExpr() {
        /* Buffer is empty and variable exists. Thus, the expression can be placed in one line */
        return buff.empty() && !intervalVar.empty();
    }

    std::string getCompleteExprAsString() {
        std::string strIntervalExpr;
        if (intervalVar.empty()) {
            strIntervalExpr = buff \
                            + loExpr + SCNL \
                            + upExpr;
        }
        else {
            strIntervalExpr = buff \
                            + intervalVar;
        }

        return strIntervalExpr;
    }

};

#endif //INTERVAL_ARITHMETIC_INTERVALEXPRESSION_H
