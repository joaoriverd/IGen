#ifndef INTERVAL_ARITHMETIC_INTRINSICEXPRESSION_H
#define INTERVAL_ARITHMETIC_INTRINSICEXPRESSION_H

#include <string>
#include "intervalExpression.h"

bool isIntrinsicFunction(std::string& funName);
bool isOptimizedIntrinsicSupported(std::string& funName);
bool convertIntrinsicInstruction(intervalExpression&, std::string&, std::vector<intervalExpression>&);

#endif //INTERVAL_ARITHMETIC_INTRINSICEXPRESSION_H
