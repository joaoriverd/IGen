#include <iostream>
#include "igenPragmaParser.h"
#include "intervalExpression.h"
#include "ASTAnalyzer.h"

using namespace clang;
using namespace std;
using namespace llvm;

igenPragmaParser::igenPragmaParser(AttributedStmt* attr) : attrStmt(attr) {
    if (auto* igen_attr = dyn_cast<IGenAttr>(attr->getAttrs()[0])) {
        switch (igen_attr->getOption()) {
            case IGenAttr::Reduce:
                errs() << "igen reduce pragma detected\n";
                _parseReducePragma(igen_attr);
                break;
        }
    }
}

void igenPragmaParser::_parseReducePragma(const IGenAttr* igen_attr) {

    /* Check that the attribute is indeed a variable with the correct type */
    var_attr = dyn_cast<DeclRefExpr>(igen_attr->getValue());
    if(!_isValidVarAttribute(var_attr)) {
        errs() << "Bad attribute in #pragma reduce. It should be a float variable\n";
        return;
    }
    errs() << "variable to reduce: " << var_attr->getDecl()->getNameAsString() << "\n";

    /* Start analysis of attributed statement */
    AnalyzerReducePragma reduceAnalyzer(attrStmt->getSubStmt(), var_attr);
    const std::vector<AddedTerm>& vecAddedTerms = reduceAnalyzer.getVecOfAddedTerms();

    /* Iterate over the terms (expressions) added to var_attr, e.g. var += term, and
     * transform to interval code. Add them to the vector of code fragments with their
     * respective location. */
    for (const AddedTerm& rhsExpr : vecAddedTerms) {
        intervalExpression iRhsExpr(rhsExpr.getTerm());
        string strRhs = iRhsExpr.getCompleteExprAsString() + SCNL;
        addCodeTransformation(strRhs, rhsExpr.getRange(), codeFragment::InsertBeforeToken);
    }
}

/// Only floating point variables and arrays with floats elements are allowed as
/// attributed variables in pragma. Only unidimensional arrays are supported for now.
bool igenPragmaParser::_isValidVarAttribute(DeclRefExpr* var) {

    if (nullptr == var) {
        return false;
    }

    clang::QualType   qt = var->getType();
    const clang::Type* t = qt->getArrayElementTypeNoTypeQual();

    return ( qt->isFloatingType() || (qt->isArrayType() && t->isFloatingType()) );
}
