#ifndef INTERVAL_ARITHMETIC_ASTVISITOR_H
#define INTERVAL_ARITHMETIC_ASTVISITOR_H

#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/AST/Type.h"
#include <iostream>

/* Check if this can be moved outside */
extern clang::Rewriter rewriter;

struct toleranceScope_t {
    std::string tolerance;
    clang::SourceLocation endLoc;
};

/* Global tolerance for return type. When a tolerance is detected in
 * a the return type of a function, we can simply store it here and update
 * the scope of the tolerance to be till the end of the function */
extern toleranceScope_t returnToleranceScope;

std::string getRawCodeAsString(clang::SourceRange);
int runIntervalGenTool (int libToolingArgc, const char **libToolingArgv);
clang::SourceRange getExpandedSourceRange(const clang::Stmt *st);
clang::SourceRange getExpandedSourceRange(const clang::SourceRange& sr);

#endif //INTERVAL_ARITHMETIC_ASTVISITOR_H
