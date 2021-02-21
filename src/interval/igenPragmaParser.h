#ifndef INTERVAL_ARITHMETIC_IGENPRAGMAPARSER_H
#define INTERVAL_ARITHMETIC_IGENPRAGMAPARSER_H

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


class igenPragmaParser {

    /* vector of code fragments that were transformed */
    AttributedStmt*      attrStmt;
    DeclRefExpr*         var_attr;
    vector<codeFragment> codeTransformations;
    SourceLocation       lastProcessedLocation;

    /* Private functions */
    static bool _isValidVarAttribute(DeclRefExpr* var);
    void _analyseStmtWithAttribute(Stmt *st);
    void _parseReducePragma(const IGenAttr* igen_attr);

public:
    explicit igenPragmaParser(AttributedStmt* attr);

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

#endif //INTERVAL_ARITHMETIC_IGENPRAGMAPARSER_H
