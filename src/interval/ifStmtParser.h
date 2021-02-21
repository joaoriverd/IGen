#ifndef INTERVAL_ARITHMETIC_IFSTMTPARSER_H
#define INTERVAL_ARITHMETIC_IFSTMTPARSER_H

#include <iostream>
#include <set>
#include "clang/AST/Type.h"
#include "clang/AST/AST.h"
#include "commonInterval.h"
#include "clang/AST/RecursiveASTVisitor.h"

using namespace clang;

struct VarDeclComp {
    bool operator() (VarDecl* lhs, VarDecl* rhs) const {
        return (lhs->getID() < rhs->getID());
    }
};

struct RefDeclComp {
    bool operator() (DeclRefExpr* lhs, DeclRefExpr* rhs) const {
        return (lhs->getDecl()->getID() < rhs->getDecl()->getID());
    }
};

using tRefDeclSet = std::set<DeclRefExpr*, RefDeclComp>;
using tVarDeclSet = std::set<VarDecl*    , VarDeclComp>;

class ifStmtParser : public RecursiveASTVisitor<ifStmtParser>  {
    friend RecursiveASTVisitor<ifStmtParser>;

    std::string condition;
    std::string condPreamble;
    bool isThreeValuedLogic = false;
    std::string codeSaveState1;
    std::string codeSaveState2;
    std::string codeMergeState;

    /* Auxiliary internal variables used to handle traversal of AST */
    tVarDeclSet varsDeclared; /* Not necessarily subset of varsUsed */
    tRefDeclSet varsAssigned; /* Subset of varsUsed */
    bool isVarAssigned = false;

    /* Override visitor functions of RecursiveASTVisitor */
    bool VisitBinaryOperator(BinaryOperator* bop);
    bool VisitVarDecl(VarDecl* var);
    bool VisitDeclRefExpr(DeclRefExpr *var);

    /* Private functions */
    tRefDeclSet _getRelevantVariables(IfStmt* st);
    void _genCodeSaveState1(std::string& gen, const tRefDeclSet& vars);
    void _genCodeSaveState2(std::string& gen, const tRefDeclSet& vars);
    void _genCodeMergeState(std::string& gen, const tRefDeclSet& vars);

public:

    explicit ifStmtParser(IfStmt* ifs);

    std::string getCond() {
        if (isThreeValuedLogic) {
            return IA_TRUE  "(" + condition + ")";
        }
        return condition;
    }

    std::string getElseCond() {
        if (isThreeValuedLogic) {
            return IA_FALSE "(" + condition + ")";
        }
        std::cerr << "Error: getElseCond should only be accessed for three logic transformations.";
        return condition;
    }

    std::string getUnknownCond() {
        if (isThreeValuedLogic) {
            return IA_UNKNOWN "(" + condition + ")";
        }
        std::cerr << "Error: getElseCond should only be accessed for three logic transformations.";
        return condition;
    }

    std::string& getCondPreamble() {
        return condPreamble;
    }

    bool hasThirdState () const {
        return isThreeValuedLogic;
    }

    std::string getCodeStateSave1() {
        if (isThreeValuedLogic) {
            return codeSaveState1;
        }
        std::cerr << "Error: getCodeStateSave1 should only be accessed for three logic transformations.";
        return std::string();
    }

    std::string getCodeMergeState() {
        if (isThreeValuedLogic) {
            return codeMergeState;
        }
        std::cerr << "Error: getCodeMergeState should only be accessed for three logic transformations.";
        return std::string();
    }
};


#endif //INTERVAL_ARITHMETIC_IFSTMTPARSER_H
