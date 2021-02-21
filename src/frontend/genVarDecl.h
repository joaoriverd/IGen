#ifndef INTERVAL_ARITHMETIC_GENVARDECL_H
#define INTERVAL_ARITHMETIC_GENVARDECL_H

#include "clang/AST/AST.h"
#include "intervalExpression.h"

class genVarDecl {
private:
    std::string storageClass;
    std::string type;
    std::string name;
    std::string init;
    std::string decl;
    std::string definition;
    bool isIntervalType = false;

    void _constructDeclaration(clang::VarDecl *var);
    void _constructDeclaration(clang::FieldDecl *var);
    void _constructInit(clang::Expr *initExpr);
    void _constructDeclarationMPFI(clang::VarDecl *var);
    void _constructDeclarationMPFI(clang::FieldDecl *var);
    void _constructInitMPFI(clang::VarDecl *var);
public:

    /* Constructors */
    genVarDecl(clang::VarDecl *var);
    genVarDecl(clang::FieldDecl *var);

    /* Member functions */
    std::string getDecl();
    std::string getInit();
    std::string getCompleteDecl();

    /* Static member functions */
    static bool isParameterDecl (clang::VarDecl *var);
};

#endif //INTERVAL_ARITHMETIC_GENVARDECL_H
