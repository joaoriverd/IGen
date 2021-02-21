#include <iostream>
#include "ASTTraverser.h"

using namespace clang;
using namespace std;

void ASTTraverser::_traverseAST(clang::Expr* ex) {

    if (auto *bop = dyn_cast<BinaryOperator>(ex)) {
        Expr* bopLHS = bop->getLHS();
        Expr* bopRHS = bop->getRHS();

        ActionBinaryOperator(bop);
        _traverseAST(bopLHS);
        _traverseAST(bopRHS);
    }

    if (auto *uop = dyn_cast<UnaryOperator>(ex)) {
        Expr* uopSub = uop->getSubExpr();
        _traverseAST(uopSub);
    }

    if (auto *par  = dyn_cast<ParenExpr>(ex)) {
        Expr* peSub = par->getSubExpr();
        _traverseAST(peSub);
    }

    if (auto *cast = dyn_cast<CastExpr>(ex)) {
        Expr* castSub = cast->getSubExpr();
        _traverseAST(castSub);
    }

    if (auto *ref = dyn_cast<DeclRefExpr>(ex)) {
        /* Terminal object */
        ActionDeclRefExpr(ref);
    }

    if (auto *il = dyn_cast<IntegerLiteral>(ex)) {
        /* Terminal object */
    }

    if (auto *fl = dyn_cast<FloatingLiteral>(ex)) {
        /* Terminal object */
    }

    if (auto *arr =  dyn_cast<ArraySubscriptExpr>(ex)) {
        Expr* arrLHS = arr->getLHS();
        Expr* arrRHS = arr->getRHS();
        _traverseAST(arrLHS);
        _traverseAST(arrRHS);
    }

    if (auto *me =  dyn_cast<MemberExpr>(ex)) {
        Expr* memBase = me->getBase();
        _traverseAST(memBase);
    }

    if (auto *ce  = dyn_cast<CallExpr>(ex)) {
        Expr* ceCallee = ce->getCallee();
        _traverseAST(ceCallee);

        for (unsigned int i = 0; i < ce->getNumArgs(); ++i) {
            Expr* ceArg = ce->getArg(i);
            _traverseAST(ceArg);
        }
    }

    if (auto *cop = dyn_cast<ConditionalOperator>(ex)) {
        Expr* copCond = cop->getCond();
        Expr* copLhs  = cop->getLHS();
        Expr* copRhs  = cop->getRHS();
        _traverseAST(copCond);
        _traverseAST(copLhs);
        _traverseAST(copRhs);
    }

    if (auto *ile = dyn_cast<InitListExpr>(ex)) {
        for (size_t i = 0; i < ile->getNumInits(); ++i) {
            Expr* ileInit = ile->getInit(i);
            _traverseAST(ileInit);
        }
    }

    if (auto *uexp = dyn_cast<UnaryExprOrTypeTraitExpr>(ex)) {
        /* This is for sizeof nad alignof. This expression can have subexpressions. But these are
         * never evaluated. Thus, we do not process them. */
    }

}

void ASTTraverser::_traverseAST(clang::Stmt* st) {

    if (auto *whs = dyn_cast<WhileStmt>(st)) {
        Expr* whsCond = whs->getCond();
        Stmt* whsBody = whs->getBody();

        _traverseAST(whsCond);
        _traverseAST(whsBody);
    }

    if (auto *dos = dyn_cast<DoStmt>(st)) {
        Stmt* whsBody = dos->getBody();
        Expr* whsCond = dos->getCond();

        _traverseAST(whsBody);
        _traverseAST(whsCond);
    }

    if (auto *ifs = dyn_cast<IfStmt>(st)) {
        Expr* ifCond = ifs->getCond();
        Stmt* ifThen = ifs->getThen();
        Stmt* ifElse = ifs->getElse();

        _traverseAST(ifCond);
        _traverseAST(ifThen);
        if (ifs->hasElseStorage()) {
            _traverseAST(ifElse);
        }
    }

    if (auto *frs = dyn_cast<ForStmt>(st)) {
        Stmt* frsInit = frs->getInit();
        Expr* frsCond = frs->getCond();
        Expr* frsIncr = frs->getInc();
        Stmt* frsBody = frs->getBody();

        _traverseAST(frsInit);
        _traverseAST(frsCond);
        _traverseAST(frsIncr);
        _traverseAST(frsBody);
    }

    if (auto *decl = dyn_cast<DeclStmt>(st)) {
        for (auto d = decl->decl_begin(); d != decl->decl_end(); d++) {
            _traverseAST(*d);
        }
    }

    if (auto *cps = dyn_cast<CompoundStmt>(st)) {
        for (auto it = cps->body_begin(); it != cps->body_end(); ++it) {
            _traverseAST(*it);
        }
    }

    if (auto expr = dyn_cast<Expr>(st)) {
        _traverseAST(expr);
    }
}

void ASTTraverser::_traverseAST(clang::Decl* de) {

    if (auto *var = dyn_cast<VarDecl>(de)) {
        ActionVarDecl(var);
        if (var->hasInit()) {
            _traverseAST(var->getInit());
        }
    }

    if (auto *fun = dyn_cast<FunctionDecl>(de)) {
        if(fun->hasBody()) {
            _traverseAST(fun->getBody());
        }

        for (size_t i = 0; i < fun->getNumParams(); ++i) {
            ParmVarDecl *parm = fun->getParamDecl(i);
            _traverseAST(parm);
        }
    }

    if (auto *typ  = dyn_cast<TypedefDecl>(de))  {
        /* Not sure about this one */
    }

    if (auto *parm  = dyn_cast<ParmVarDecl>(de))  {
        /* Not sure how to process this one */
    }
}