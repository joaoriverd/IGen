#ifndef INTERVAL_ARITHMETIC_GENRETURNSTMT_H
#define INTERVAL_ARITHMETIC_GENRETURNSTMT_H

#include "clang/AST/AST.h"
#include "intervalExpression.h"

class genReturnStmt {
private:
    std::string type;
    std::string prelude;
    std::string ret;

    void _constructReturnStmt(clang::ReturnStmt *var);
    void _constructReturnStmtMPFI(clang::ReturnStmt *var);
public:

    /* Constructors */
    genReturnStmt(clang::ReturnStmt *var);

    /* Member functions */
    std::string getPrelude();
    std::string getReturn();
    std::string getCompleteReturn();
};

#endif //INTERVAL_ARITHMETIC_GENRETURNSTMT_H
