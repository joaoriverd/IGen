#ifndef INTERVAL_ARITHMETIC_FORSTMTPARSER_H
#define INTERVAL_ARITHMETIC_FORSTMTPARSER_H

#include <iostream>
#include <vector>
#include "clang/AST/Type.h"
#include "clang/AST/AST.h"
#include "commonInterval.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "codeFragment.h"


using namespace clang;
using namespace std;


class forStmtParser {
    /* vector of code fragments that were transformed */
    ForStmt* forStmt;
    string   preamble;
    string   init;
    string   cond;
    string   incr;
    vector<codeFragment> codeTransformations;
    SourceLocation lastProcessedLocation;

    /* Private functions */
    void _parseCodeInit(Stmt *initExpr);
    void _parseCodeCond(Expr *condExpr);
    void _parseCodeIncr(Expr *incrExpr);
    void _parseCodeRedu(ForStmt *frs);

public:
    explicit forStmtParser(ForStmt* frs);

    vector<codeFragment>& getCodeTransformations() {
        return codeTransformations;
    }

    void addCodeTransformation(const string& c, const SourceRange& r, const codeFragment::eInsertPosition& p) {
        codeTransformations.emplace_back(c, r, p);
    }

    SourceLocation getLastProcessedLocation() {
        return lastProcessedLocation;
    }
};


#endif //INTERVAL_ARITHMETIC_FORSTMTPARSER_H
