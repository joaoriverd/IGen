#ifndef INTERVAL_ARITHMETIC_CONSTANTEXPRESSIONS_H
#define INTERVAL_ARITHMETIC_CONSTANTEXPRESSIONS_H

#include "intervalExpression.h"

std::string APFloat2String(llvm::APFloat& fl, const std::string& type, bool);
void castConstantExpr(const std::string& resType, intervalExpression& iConst);
void getConstIntervalFromString(std::string s, intervalExpression& iConst);
void getConstInterval(clang::FloatingLiteral*& fl, intervalExpression& iConst);
void negateConstantInterval(intervalExpression& iArg, intervalExpression& iConst);
void addConstantInterval(intervalExpression& iRhs, intervalExpression& iLhs, intervalExpression& iConst);
void subConstantInterval(intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iConst);
void mulConstantInterval(intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iConst);
void divConstantInterval(intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iConst);
void cmpConstantInterval(intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iConst, std::string& op);

#endif //INTERVAL_ARITHMETIC_CONSTANTEXPRESSIONS_H
