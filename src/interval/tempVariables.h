#ifndef INTERVAL_ARITHMETIC_TEMPVARIABLES_H
#define INTERVAL_ARITHMETIC_TEMPVARIABLES_H

#include "intervalExpression.h"
//
// Function declarations
//
std::string genTempVar (std::string& type, std::string &buff);
void genTempVar (intervalExpression &iExpr, std::string &buff);
void genTempIntervalVar (intervalExpression &iExpr, std::string &buff);
std::string genTempVarMPFI (std::string &buff);
void incVarCount ();
size_t getVarCount ();

#endif //INTERVAL_ARITHMETIC_TEMPVARIABLES_H
