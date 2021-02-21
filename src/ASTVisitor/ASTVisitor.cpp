/* Clang front end header files */
#include "clang/Driver/Options.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Rewrite/Core/Rewriter.h"

/* Other headers */
#include <iostream>
#include "intervalExpression.h"
#include "ifStmtParser.h"
#include "genVarDecl.h"
#include "genReturnStmt.h"
#include "vector"
#include "ASTVisitor.h"
#include "commonInterval.h"
#include "forStmtParser.h"
#include "codeFragment.h"
#include "igenPragmaParser.h"
#include "pollyReduction.h"

using namespace std;
using namespace clang;
using namespace clang::driver;
using namespace clang::tooling;
using namespace llvm;

Rewriter rewriter;
CompilerInstance* mainCI;
static int numFunctions = 0;
static string file_name;

/* Global tolerance for return type. When a tolerance is detected in
 * a function, we can simply store that here and update th scope of
 * the tolerance to be till the end of the function */
toleranceScope_t returnToleranceScope;

static bool parseToleranceReturnType (FunctionDecl *fund, string& tolerance) {

    SourceLocation funcStartLoc  = fund->getLocation().getLocWithOffset(-1);
    SourceLocation returnTypeLoc = fund->getReturnTypeSourceRange().getBegin();
    string rawReturnType = rewriter.getRewrittenText(SourceRange(returnTypeLoc, funcStartLoc));

    size_t startToleranceSeparator = rawReturnType.find(TOLERANCE_TYPE_SEPARATOR);
    if (startToleranceSeparator == string::npos) {
        return false;
    }
    tolerance = rawReturnType.substr(startToleranceSeparator + 1);
    /* Remove white spaces */
    string::iterator end_pos = std::remove(tolerance.begin(), tolerance.end(), ' ');
    tolerance.erase(end_pos, tolerance.end());

    return true;
}

static bool parseToleranceType (ParmVarDecl* param, string& tolerance) {

    string type = param->getType().getAsString();
    string rawVarDecl = rewriter.getRewrittenText(param->getSourceRange());
    size_t posType = rawVarDecl.find(type);
    string varWithTolerance = rawVarDecl.substr(posType + type.size(), string::npos);

    size_t endTolerance = varWithTolerance.find(param->getName().str());
    size_t startToleranceSeparator = varWithTolerance.find(TOLERANCE_TYPE_SEPARATOR);
    if (startToleranceSeparator == string::npos) {
        return false;
    }
    tolerance = varWithTolerance.substr(startToleranceSeparator + 1, endTolerance - startToleranceSeparator - 1);
    /* Remove white spaces */
    string::iterator end_pos = std::remove(tolerance.begin(), tolerance.end(), ' ');
    tolerance.erase(end_pos, tolerance.end());

    return true;
}

static void addCompound(Rewriter& out_rewriter, Stmt* st, const ASTContext &C) {

    if (auto *ifs = dyn_cast<IfStmt>(st)) {
        Stmt* elseStmt = ifs->getElse();

        /* Add compound statement to else if needed */
        if (ifs->hasElseStorage() && !dyn_cast<CompoundStmt>(elseStmt)) {
            /* It is else-if statement*/
            auto elseifStmt = dyn_cast<IfStmt>(elseStmt);

            /* Set location for braces. LBrace hast to be one location before stmt
             * to not interfere with its source range */
            SourceLocation LBraceLoc = elseifStmt->getBeginLoc().getLocWithOffset(-1);
            SourceLocation RBraceLoc = elseifStmt->getEndLoc();
            string temp = out_rewriter.getRewrittenText(LBraceLoc);
            out_rewriter.ReplaceText(LBraceLoc, " {");
            temp = out_rewriter.getRewrittenText(RBraceLoc);
            out_rewriter.ReplaceText(RBraceLoc, "}}");

        }
    }
}

/* Get expanded source range to manage macros */
SourceRange getExpandedSourceRange(const Stmt* st) {
    CharSourceRange stCharRange = rewriter.getSourceMgr().getExpansionRange( st->getSourceRange() );
    return stCharRange.getAsRange();
}

SourceRange getExpandedSourceRange(const SourceRange& sr) {
    CharSourceRange stCharRange = rewriter.getSourceMgr().getExpansionRange(sr);
    return stCharRange.getAsRange();
}

/* Apply a custom category to all command-line options so that they are the only ones displayed. */
llvm::cl::OptionCategory MyToolCategory("my-tool options");

class ASTMainVisitor : public RecursiveASTVisitor<ASTMainVisitor> {
    friend RecursiveASTVisitor<ASTMainVisitor>;

    /* Context used for getting additional AST info */
    ASTContext* astMainContext;
    SourceLocation processedLocation;

    bool isAttributedStmt(Stmt* st) {
        return nullptr != dyn_cast<AttributedStmt>(st);
    }

    bool transformFunctionDecl(FunctionDecl *fund) {
        /* There are three things to do in a function declaration:
         * 1. Rewrite return type to interval type (if needed).
         * 2. Rewrite parameters to intervals if needed and parse whether
         *    they use a tolerance.
         * 3. Generate the preamble and restore rounding at the end. The
         *    preamble is what is executed at the beginning of the function.
         *    A preamble includes change of rounding mode and promotion of
         *    input parameters to interval variables.
         * Note: For MPFI we only move the return variable to the parameter list.
         *       Let the VisitVarDecl to handle the parameter list for MPFI. */

        numFunctions++;
        string funcName     = fund->getNameAsString();
        string funcPreamble = CODE_FROUND_INIT; // only used when function definition
        string returnType   = getTypeAsString(fund->getReturnType(), true);
        bool functionHasBody = fund->doesThisDeclarationHaveABody();

        if (getIntervalLib() == IAGEN) {

            /* First rewrite return type to interval type */
            if (isTypeTransformable(returnType)) {

                /* Detect whether the var declaration has tolerance */
                string returnTolerance;
                bool returnHasTolerance = parseToleranceReturnType(fund, returnTolerance);

                SourceRange returnRange;
                if (returnHasTolerance) {
                    /* Handle type with tolerance */
                    SourceLocation endReturnLoc   = fund->getLocation().getLocWithOffset(-1);
                    SourceLocation beginReturnLoc = fund->getReturnTypeSourceRange().getBegin();
                    returnRange.setBegin(beginReturnLoc);
                    returnRange.setEnd(endReturnLoc);

                    /* Normally we would use function getTypeAsString() but here we want to keep the raw type */
                    returnType = fund->getReturnType().getAsString();

                    /* Update returnTolerance with the scope of the tolerance */
                    returnToleranceScope.tolerance = returnTolerance;
                    returnToleranceScope.endLoc    = fund->getEndLoc();
                }
                else {
                    transformToIntervalType(returnType);
                    returnRange = fund->getReturnTypeSourceRange();
                }

                rewriter.ReplaceText(returnRange, returnType);
                errs() << "** Rewrote return type of function: " << funcName << "\n";
            }

            /* Iterate through the parameter list and transform each type.
             * Generate promotion to interval in the preamble if needed */
            for (size_t i = 0; i < fund->getNumParams(); ++i) {
                ParmVarDecl *param = fund->getParamDecl(i);
                string varTolerance;

                /* Detect whether the var declaration has tolerance */
                bool parameterHasTolerance = parseToleranceType(param, varTolerance);

                string varDecl;
                if (parameterHasTolerance) {
                    /* The parameter has tolerance. Thus, remove the tolerance from the
                     * declaration and change the name of the parameter. Also, add the
                     * initialization of the variable in the preamble */

                    // Normally we would use function getTypeAsString() but here we want the raw type
                    string varType = param->getType().getAsString();
                    if (isTypeSupported(varType)) {
                        string varName = param->getName().str();
                        varDecl = varType + " " IN_PARAM_PREFIX + varName;

                        /* Rewrite variable declaration with new name */
                        rewriter.ReplaceText(param->getSourceRange(), varDecl);

                        if (fund->doesThisDeclarationHaveABody()) {
                            /* Store initialization of promoted variable in the preamble.
                             * This only makes sense if function has a body (i.e. function definition). */

                            string up = IN_PARAM_PREFIX + varName + " + " + varTolerance;
                            string lo = "-" IN_PARAM_PREFIX + varName + " + " + varTolerance;
                            string varPromotedType = getTypeAsString(param->getType());
                            transformToIntervalType(varPromotedType);
                            funcPreamble += IAGEN_INTERVAL_VAR_DEF(varPromotedType, varName, lo, up) + SCNL;
                        }
                    }
                    else if (isTypeTransformable(varType)) {
                        /* Handle case for double*, double[], etc. */
                        // todo: support this case
                    }
                }
                else {
                    /* The parameter is transformed to interval */
                    genVarDecl genVar(param);
                    varDecl = genVar.getDecl();
                }

                /* Rewrite parameter declaration */
                rewriter.ReplaceText(param->getSourceRange(), varDecl);
                errs() << "** Rewrote param declaration: " << varDecl << "\n";
                processedLocation = param->getEndLoc();
            }

            /* Lastly, write th preamble in the function in case it has body.
             * Also, restore rounding mode at the end of body in case of void function */
            if (functionHasBody) {
                auto *comp = dyn_cast<CompoundStmt>(fund->getBody());
                rewriter.InsertTextAfterToken(comp->getLBracLoc(), funcPreamble);

                /* If void function then restore rounding environment at the end */
                if (fund->getReturnType().getUnqualifiedType()->isVoidType()) {
                    rewriter.InsertTextBefore(comp->getRBracLoc(), CODE_RESTORE_FROUND);
                }
            }
            else {
                /* In case it is simply a function declaration and it is a supported math functions.
                 * Translate the math function to its interval counter part. */
                if (translateMathFun(funcName, getBareTypeAsString(fund->getReturnType()))) {
                    rewriter.ReplaceText(fund->getNameInfo().getSourceRange(), funcName);
                }
            }
        }
        else if (getIntervalLib() == MPFI_LIB) {

            /* Rewrite return type for MPFI transformation */
            if (isTypeSupported(returnType)) {

                /* MPFI's datatype for intervals cannot be used as return type.
                 * Make return type void and add return parameter _ret */
                rewriter.ReplaceText(fund->getTypeSpecStartLoc(), MPFI_RET_NO_INTERVAL);

                /* Add a return parameter as first argument
                 * First find the left parenthesis of the function
                 * (where the new argument will be placed)
                 * Note: there should be a more elegant way to do this */

                SourceLocation locationLeftParenthesis = fund->getLocation().getLocWithOffset(funcName.size());
                string textLeftParenthesis = rewriter.getRewrittenText(locationLeftParenthesis);

                if ( textLeftParenthesis != "(") {
                    /* The left parenthesis is not right after the function name.
                     * Thus, add offset of one to the location. This works because
                     * clang-format only adds one space between funName and LeftParenthesis */
                    locationLeftParenthesis = locationLeftParenthesis.getLocWithOffset(1);
                }

                /* Replace the left parenthesis with the new return parameter after a left parenthesis */
                string leftParenthesisAndParameter = "( " MPFI_TYPE " " RETURN_VAR;

                if ( fund->getNumParams() > 0 ) {
                    leftParenthesisAndParameter += ", ";
                }

                rewriter.ReplaceText(locationLeftParenthesis, 1, leftParenthesisAndParameter);
            }
            else {

                /* Return type is not supported as an interval */
                if (isTypeTransformable(returnType)) {

                    /* This part handles when the return type is e.g. a pointer to double and has
                     * to be transformed to pointer to interval */
                    transformToIntervalType(returnType);
                    rewriter.ReplaceText(fund->getReturnTypeSourceRange(), returnType);
                }

            }

            errs() << "** Rewrote return type of function: " << funcName << "\n";

        }

        return true;
    }

    bool transformFieldDecl(FieldDecl *fld) {
        static string sameLineDecl;

        /* First get the variable type without qualifiers (e.g. without const) */
        string varType = getTypeAsString(fld->getType());

        /* Only make changes to the variable type when it is transformable */
        if ( isTypeTransformable(varType) ) {

            /* Change the type of the variable to interval if not yet processed */
            if ( processedLocation < fld->getEndLoc() ) {
                genVarDecl genVar(fld);

                if ( processedLocation < fld->getBeginLoc() ) {

                    /* This variable is declared either alone in one line
                     * or is the first one in that line. */
                    string varDecl = genVar.getDecl();
                    rewriter.ReplaceText(fld->getSourceRange(), varDecl);
                    sameLineDecl = varDecl + SCNL;

                }
                else {

                    /* This variable is declared in the same line as other
                     * already processed */
                    sameLineDecl += genVar.getDecl();
                    rewriter.ReplaceText(fld->getSourceRange(), sameLineDecl);
                    sameLineDecl = sameLineDecl + SCNL;
                }

                errs() << "** Rewrote declaration: " << genVar.getDecl() << "\n";
                processedLocation = fld->getEndLoc();
            }
        }

        return true;
    }

    bool transformVarDecl(VarDecl *var) {
        static string sameLineDecl;
        SourceRange varLocRange = getExpandedSourceRange(var->getSourceRange());

        if ( processedLocation < varLocRange.getEnd() ) {

            /* Transform variable declaration */
            genVarDecl genVar(var);

            if ( processedLocation < varLocRange.getBegin() ) {
                /* This variable is declared either alone in one line
                 * or it's the first one in that line. */

                /* For MPFI only get complete declaration (including initialization) for local variables.
                 * Initialization for e.g. global variables should be handled separately. */
                string varDecl;
                if (getIntervalLib() == MPFI_LIB) {
                    varDecl = var->isLocalVarDecl() ? genVar.getCompleteDecl() : genVar.getDecl();
                }
                else {
                    varDecl = genVar.getCompleteDecl();
                }
                rewriter.ReplaceText(varLocRange, varDecl);
                sameLineDecl = varDecl + SCNL;

            }
            else {

                /* This variable is declared in the same line as other
                 * already processed */
                sameLineDecl += genVar.getCompleteDecl();
                rewriter.ReplaceText(varLocRange, sameLineDecl);
                sameLineDecl = sameLineDecl + SCNL;
            }

            errs() << "** Rewrote declaration: " << genVar.getDecl() << "\n";
            processedLocation = varLocRange.getEnd();
        }

        return true;
    }

    bool transformTypedefDecl(TypedefDecl *tyd) {
        /* First get the variable type without qualifiers (e.g. without const) */
        string defType = getTypeAsString(tyd->getUnderlyingType());

        /* Only make changes to the variable type when it is transformable */
        if ( isTypeTransformable(defType) ) {

            /* Change the type of the variable to interval if not yet processed */
            if ( processedLocation < tyd->getEndLoc() ) {
                transformToIntervalType(defType);
                string typeName = tyd->getName().str();
                string typeDefStr = "typedef " + defType + " " + typeName;

                rewriter.ReplaceText(tyd->getSourceRange(), typeDefStr);
                errs() << "** Rewrote declaration: " << typeDefStr << "\n";
                processedLocation = tyd->getEndLoc();
            }
        }

        return true;
    }

    bool transformExpr(Expr* expr) {
        /* Save the original expression */
        string stringIntervalExpr, stringOriginalStmt;
        SourceRange exprSourceRange = getExpandedSourceRange(expr);
        stringOriginalStmt = rewriter.getRewrittenText(exprSourceRange);

        /* Construct the IA statement using either bounds or interval variable */
        intervalExpression iExpr(expr);
        stringIntervalExpr = iExpr.getCompleteExprAsString();

        /* Rewrite statement */
        rewriter.ReplaceText(exprSourceRange, stringIntervalExpr);
        processedLocation = exprSourceRange.getEnd();
        errs() << "** Rewrote statement: " << stringOriginalStmt << NL;

        return true;
    }

    bool transformWhileStmt(WhileStmt* whs) {
        Expr *condExpr = whs->getCond();
        intervalExpression iExpr(condExpr);

        processedLocation = getExpandedSourceRange(condExpr).getEnd();
        if (iExpr.isLogicalExpr() || iExpr.isScalarExpr()) {
            /* Print using scalar condition */
            SourceLocation beforeKeyword = whs->getWhileLoc();
            rewriter.InsertTextBefore(beforeKeyword, iExpr.getBuff());
            rewriter.ReplaceText(getExpandedSourceRange(condExpr), iExpr.getLogicalExpr());
        }
        else {
            errs() << "** Error: While statement can only process logical or scalar expressions\n";
        }

        return true;
    }

    bool transformIfStmt(IfStmt* ifs) {
#if JOIN_IN_BRANCHES
        ifStmtParser ifStmt(ifs);

        /* Replace transformation of conditional in source code. The preamble
         * goes before the if keyword */
        SourceLocation preambleLoc = ifs->getIfLoc();
        SourceRange conditionLoc   = getExpandedSourceRange(ifs->getCond());
        rewriter.InsertTextBefore(preambleLoc, ifStmt.getCondPreamble());
        rewriter.ReplaceText(conditionLoc, ifStmt.getCond());
        errs() <<  "** Rewrote if condition: " << ifStmt.getCond() << NL;

        /* Update processed location (if conditional) */
        processedLocation = conditionLoc.getEnd();

        /* Transform compound then statements */
        this->TraverseStmt(ifs->getThen());

        if (ifStmt.hasThirdState()) {
            /* Handle else case */
            if(ifs->hasElseStorage()) {
                SourceLocation elseLoc = ifs->getElseLoc();
                rewriter.InsertTextAfterToken(elseLoc, " if ( " + ifStmt.getElseCond() + ")");
            }

            /* Handle third branch (unknown state) */
            string firstBranchCode = rewriter.getRewrittenText(ifs->getThen()->getSourceRange());
            string thirdBranchCode;

            thirdBranchCode +=  NL "else if (" + ifStmt.getUnknownCond() + ") {" NL;
            thirdBranchCode += "/* Save state */" NL;
            thirdBranchCode += ifStmt.getCodeStateSave1() + NL;
            thirdBranchCode += "/* First branch */" NL;
            thirdBranchCode += firstBranchCode + NL;
            thirdBranchCode += NL "/* Merge states */" NL;
            thirdBranchCode += ifStmt.getCodeMergeState();
            thirdBranchCode += "}" NL;

            SourceLocation endIfLoc = ifs->getEndLoc();
            rewriter.InsertTextAfterToken(endIfLoc, thirdBranchCode);
        }
#else
        Expr *condExpr = ifs->getCond();
        intervalExpression iExpr(condExpr);

        processedLocation = getExpandedSourceRange(condExpr).getEnd();
        if (iExpr.isLogicalExpr() || iExpr.isScalarExpr()) {
            /* Print using scalar condition */
            SourceLocation beforeKeyword = ifs->getIfLoc();
            rewriter.InsertTextBefore(beforeKeyword, iExpr.getBuff());
            rewriter.ReplaceText(getExpandedSourceRange(condExpr), iExpr.getLogicalExpr());
        }
        else {
            errs() << "** Error: If statement can only process logical or scalar expressions\n";
        }
#endif
        return true;
    }

    bool transformForStmt(ForStmt* frs) {
        /* Parse for statement */
        forStmtParser forParse(frs);
        vector<codeFragment>& codeTransformations = forParse.getCodeTransformations();

        /* Replace all code transformations into source file */
        for (const codeFragment& cf : codeTransformations) {
            cf.replaceCodeFragment(rewriter);
        }

        processedLocation = forParse.getLastProcessedLocation();

        return true;
    }

    bool transformDoStmt(DoStmt* dws) {
        /* todo: support transformations on do-while statements */
        return true;
    }

    bool transformReturnStmt(ReturnStmt* res) {
        genReturnStmt retStmt(res);
        string strReturn = retStmt.getCompleteReturn();

        /* Rewrite return statement */
        rewriter.ReplaceText(res->getSourceRange(), strReturn);
        errs() <<  "** Rewrote return statement: " << rewriter.getRewrittenText(res->getSourceRange()) << "\n";

        processedLocation = res->getEndLoc();
        return true;
    }

    bool transformAttributedStmt(AttributedStmt *attr) {
        igenPragmaParser pragmaParser(attr);

        vector<codeFragment>& codeTransformations = pragmaParser.getCodeTransformations();

        /* Replace all code transformations into source file */
        for (const codeFragment& cf : codeTransformations) {
            cf.replaceCodeFragment(rewriter);
        }

        return true;
    }

    /* We have to traverse all the AST. There are two main parent classes that we have to visit,
     * namely Stmt and Decl. All nodes of interest are derived from them. An exception is
     * AttributedStmt. This node is not caught by VisitStmt. Thus, we used its own visitor function */
    bool VisitStmt(Stmt *st) {
        SourceRange stmtSourceRange;
        SourceLocation stmtLocation;
        /* Get the source range of the current statement. Note that Attributed Stmts does
         * not have a valid location (probably because they are preprocessor directives?). Thus,
         * get the source range of its first attribute */
        stmtLocation    = st->getBeginLoc();
        stmtSourceRange = getExpandedSourceRange(st);
        auto* as = dyn_cast<AttributedStmt>(st);
        if (as && !as->getAttrs().empty()) {
            stmtSourceRange = as->getAttrs().front()->getRange();
            stmtLocation    = stmtSourceRange.getBegin();
        }

        /* Check that the statement is in the main file. If not, it is most likely in a header file*/
        if (!rewriter.getSourceMgr().isInMainFile(stmtLocation)) {
            return true;
        }

        /* Only process stmt if not processed yet */
        if (processedLocation < stmtSourceRange.getBegin()) {

            /* Create compound statement (if missing) in case of if, or loops */
            addCompound(rewriter, st, *astMainContext);

            /* Process expression, e.g. binary expression, function calls, etc */
            if (auto *expr  = dyn_cast<Expr>(st)) {
                return transformExpr(expr);
            }

            /* Process if-else statement */
            if (auto *ifs = dyn_cast<IfStmt>(st)) {
                return transformIfStmt(ifs);
            }

            /* Process while-loop conditions */
            if (auto *whs = dyn_cast<WhileStmt>(st)) {
                return transformWhileStmt(whs);
            }

            /* Process for-loop */
            if (auto *frs = dyn_cast<ForStmt>(st)) {
                return transformForStmt(frs);
            }

            /* Process do-while */
            if (auto *dws = dyn_cast<DoStmt>(st)) {
                return transformDoStmt(dws);
            }

            /* Process return statement */
            if (auto *res = dyn_cast<ReturnStmt>(st)) {
                return transformReturnStmt(res);
            }

            /* Process attributed statement */
//            if (auto *attr = dyn_cast<AttributedStmt>(st)) {
//                return transformAttributedStmt(attr);
//            }
        }

        return true;
    }

    bool VisitDecl(Decl* decl) {
        SourceManager& SM = rewriter.getSourceMgr();
        if (!SM.isInMainFile(decl->getLocation())) {
            /* The current location is not in the main file. Do not process.
             * (It is most likely in a header file.) */
            return true;
        }

        /* Process while-loop conditions */
        if (auto *fund = dyn_cast<FunctionDecl>(decl)) {
            return transformFunctionDecl(fund);
        }

        /* Process for-loop */
        if (auto *fld = dyn_cast<FieldDecl>(decl)) {
            return transformFieldDecl(fld);
        }

        /* Process do-while */
        if (auto *var = dyn_cast<VarDecl>(decl)) {
            return transformVarDecl(var);
        }

        /* Process return statement */
        if (auto *tyd = dyn_cast<TypedefDecl>(decl)) {
            return transformTypedefDecl(tyd);
        }

        return true;
    }

public:
    explicit ASTMainVisitor(CompilerInstance *CI) : astMainContext(&(CI->getASTContext())) {
        mainCI = CI;
        rewriter.setSourceMgr(astMainContext->getSourceManager(), astMainContext->getLangOpts());
    }
};

class ExampleASTConsumer : public ASTConsumer {
private:
    ASTMainVisitor *visitor; // doesn't have to be private

public:
    /* Override the constructor in order to pass CI */
    explicit ExampleASTConsumer(CompilerInstance *CI)
            : visitor(new ASTMainVisitor(CI)) // initialize the visitor
    { }

    /* Override this to call our ASTMainVisitor on the entire source file */
    void HandleTranslationUnit(ASTContext &Context) override {
        /* ASTContext is used to get the TranslationUnitDecl (a declaration representing the entire source file. */
        TranslationUnitDecl* tud = Context.getTranslationUnitDecl();

        /* First call our reduction detection mechanism to identify polly reductions in the AST */
        GlobalPollyReduction.setASTContext(&Context);
        GlobalPollyReduction.readPollyReductions();
        GlobalPollyReduction.matchReductionsWithASTNodes(tud);

        /* Now traverse the entire main visitor to perform the interval transformations */
        visitor->TraverseDecl(tud);
    }
};

class ExampleFrontendAction : public ASTFrontendAction {
public:
    ExampleFrontendAction() = default;

    void EndSourceFileAction() override {
        /* Do something when end of source is reached */
    }

    virtual std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef file) override {
        return (std::unique_ptr<ASTConsumer>) new ExampleASTConsumer(&CI); // pass CI pointer to ASTConsumer
    }
};

string getRawCodeAsString(SourceRange sr) {
    return rewriter.getRewrittenText(sr);
}

int runIntervalGenTool (int libToolingArgc, const char **libToolingArgv) {

    CommonOptionsParser op(libToolingArgc, libToolingArgv, MyToolCategory);

    /* create a new Clang Tool instance (a LibTooling environment) */
    ClangTool Tool(op.getCompilations(), op.getSourcePathList());

    /* run the Clang Tool, creating a new FrontendAction */
    int result = Tool.run(newFrontendActionFactory<ExampleFrontendAction>().get());

    /* print out the rewritten source code */
    errs() << "\nFound " << numFunctions << " functions.\n\n";
    FileID fid = rewriter.getSourceMgr().getMainFileID();

    /* Add igen header files at the top of file */
    string headers = getIGenHeaderFiles();

    rewriter.getEditBuffer(fid).InsertTextBefore(0, headers);
    rewriter.getEditBuffer(fid).write(outs());

    errs() << "\n";
    return result;
}