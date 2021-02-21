#include <iostream>
#include "ifStmtParser.h"
#include "intervalExpression.h"
#include "tempVariables.h"
#include "ASTTraverser.h"

using namespace clang;
using namespace std;

ifStmtParser::ifStmtParser(IfStmt *ifs) {
    /* Generate interval expression of the conditional by traversing its AST */
    intervalExpression iExpr( ifs->getCond() );

    if (!iExpr.isLogicalExpr() && !iExpr.isScalarExpr()) {
        cerr << "** Error: If statement can only process logical or scalar expressions" << endl;
        return;
    }

    condPreamble = iExpr.getBuff();
    isThreeValuedLogic = iExpr.isThreeValuedLogic();

    if (isThreeValuedLogic) {
        /*Generate temporal variable if needed for the conditional. This is because for tribools,
         * we add a special function in the condition, e.g. _ia_true(cond), to determine the state
         * of the tribool (true, false, or unknown) */
        genTempVar(iExpr, condPreamble);

        /* Detect the used variables in the if body */
        tRefDeclSet vars = _getRelevantVariables(ifs);

        /* Generate code to save state before performing the third state */
        _genCodeSaveState1(codeSaveState1, vars);
        if (ifs->hasElseStorage()) {
            _genCodeSaveState2(codeSaveState2, vars);
        }

        /* Generate code to merge the states */
        _genCodeMergeState(codeMergeState, vars);
    }

    condition = iExpr.getLogicalExpr();
}

tRefDeclSet ifStmtParser::_getRelevantVariables(IfStmt* ifs) {
    /* Traverse body to detect used variables */
    cerr << "** Extracting variables of if body:" << endl;
    this->TraverseStmt(ifs->getThen());

    /* Perform set operations: varsRelevant = varsAssigned - varsDeclared */
    tRefDeclSet varsRelevant;
    for (DeclRefExpr* ref : varsAssigned) {
        bool isRefRelevant = true;
        for (VarDecl* var : varsDeclared) {
            if (var->getID() == ref->getDecl()->getID()) {
                isRefRelevant = false;
                break;
            }
        }

        if (isRefRelevant) {
            varsRelevant.insert(ref);
        }
    }

    cerr << "** Relevant variables:" << endl;
    for (DeclRefExpr* ref : varsRelevant) {
        string  refName = ref->getDecl()->getNameAsString();
        int64_t refID   = ref->getDecl()->getID();
        cerr << "\t" << refName << " : " << refID << endl;
    }

    return varsRelevant;
}

///
/// Generates the code to save the state before branch1 is executed in the "unknown" body.
/// Precondition: vars contains only supported variables (e.g. double, float, etc).
///
void ifStmtParser::_genCodeSaveState1(string &gen, const tRefDeclSet& vars) {
    /* Here we create temporal variables to backup the state in vars */
    for (DeclRefExpr* v : vars) {
        string varType = getTypeAsString(v->getType());
        transformToIntervalType(varType);

        /* generate temporal variables with similar name but with prefix */
        string varName = v->getDecl()->getNameAsString();
        string newName = IA_PREFIX "_" + varName;
        string varDecl = varType + " " + newName + " = " + varName + SCNL;

        gen += varDecl;
    }
}

void ifStmtParser::_genCodeSaveState2(string &gen, const tRefDeclSet &vars) {

}

///
/// Generate the code to marge the states of the two previous branches. This is
/// done by calling union function.
/// Precondition: vars contains only supported variables (e.g. double, float, etc).
///
void ifStmtParser::_genCodeMergeState(string &gen, const tRefDeclSet &vars) {
    /* Here we create temporal variables to backup the state in vars */
    for (DeclRefExpr* v : vars) {
        string varType = getBareTypeAsString(v->getType());
        string posfix  = getPostfixForType(varType);

        /* generate temporal variables with similar name but with prefix */
        string varName  = v->getDecl()->getNameAsString();
        string newName  = IA_PREFIX "_" + varName;
        string varMerge = varName + " = " + IA_UNION(posfix) + "(" + varName + "," + newName + ")" SCNL;

        gen += varMerge;
    }
}


bool ifStmtParser::VisitVarDecl(clang::VarDecl* var) {
    string varName = var->getNameAsString();
    string varType = getBareTypeAsString(var->getType());

    /* Only keep track of the interval variables declared. */
    if (isTypeSupported(varType)) {
        varsDeclared.insert(var);
        cerr << "\tVarDecl: " << varName << " (" << varType << ")"  << endl;
    }

    return true;
}

bool ifStmtParser::VisitDeclRefExpr(clang::DeclRefExpr* ref) {
    string refName = ref->getDecl()->getName().str();
    string refType = getBareTypeAsString(ref->getType());

    /* Only keep track of the interval variables declared. */
    if (isTypeSupported(refType) && isVarAssigned) {
        varsAssigned.insert(ref);
        cerr << "\tDeclRefExpr: " << refName << " (" << refType << ")" << endl;
    }

    return true;
}

bool ifStmtParser::VisitBinaryOperator(clang::BinaryOperator *bop) {
    /* Detect variables that are assigned */
    if (bop->isAssignmentOp()) {
        /* Traverse left part of assignment to search for a variable */
        isVarAssigned = true;
        this->TraverseStmt(bop->getLHS());
        isVarAssigned = false;
    }

    return true;
}
