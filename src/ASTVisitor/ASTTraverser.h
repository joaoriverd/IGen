#ifndef INTERVAL_ARITHMETIC_ASTTRAVERSER_H
#define INTERVAL_ARITHMETIC_ASTTRAVERSER_H

#include "clang/AST/Type.h"
#include "clang/AST/AST.h"

class ASTTraverser {

    virtual void ActionBinaryOperator(clang::BinaryOperator* bop) {}
    virtual void ActionVarDecl(clang::VarDecl* var) {}
    virtual void ActionDeclRefExpr(clang::DeclRefExpr* ref) {}

protected:
    void _traverseAST(clang::Stmt* st);
    void _traverseAST(clang::Expr* st);
    void _traverseAST(clang::Decl* st);

public:
    template<typename T>
    explicit ASTTraverser(T* st) {
        _traverseAST(st);
    }
    ASTTraverser() = default;

    virtual ~ASTTraverser() = default;
};


#endif //INTERVAL_ARITHMETIC_ASTTRAVERSER_H
