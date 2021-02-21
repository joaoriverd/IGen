#ifndef INTERVAL_ARITHMETIC_BOPEXPRESSIONS_H
#define INTERVAL_ARITHMETIC_BOPEXPRESSIONS_H

#include "intervalExpression.h"

/* IAGen transformations */
void bopAssign (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r);
void bopMul (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r);
void bopDiv (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r);
void bopAdd (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r);
void bopSub (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r);
void bopComp (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r, std::string& op);
void bopCompoundAssign (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r, std::string& op);
void bopBitwise (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r, std::string& op);
void bopLogical (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes, std::string& op);
void bopComma (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r);

/* MPFI transformations */
void bopAssignMPFI (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r);
void bopBasicMPFI (intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iRes, std::string& op);
void bopCompMPFI (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r, std::string& op);
void bopCompoundAssignMPFI (intervalExpression& lhs, intervalExpression& rhs, intervalExpression& r, std::string& op);

#endif //INTERVAL_ARITHMETIC_BOPEXPRESSIONS_H
