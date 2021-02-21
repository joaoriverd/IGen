#ifndef INTERVAL_ARITHMETIC_UNARYOPEXPRESSIONS_H
#define INTERVAL_ARITHMETIC_UNARYOPEXPRESSIONS_H

#include "intervalExpression.h"

/* IAGen transformations */
void uopMinus(intervalExpression& iExpr, intervalExpression& iRes);
void uopDereference(intervalExpression& iExpr, intervalExpression& iRes);
void uopAutoincrement(intervalExpression& iExpr, intervalExpression& iRes, std::string& op, bool is_prefix);
void uopNot(intervalExpression& iExpr, intervalExpression& iRes);

/* MPFI transformations */
void uopMinusMPFI (intervalExpression& iExpr, intervalExpression& iRes);
void uopAutoincrementMPFI (intervalExpression& iExpr, intervalExpression& iRes, std::string& op, bool is_prefix);

#endif //INTERVAL_ARITHMETIC_UNARYOPEXPRESSIONS_H
