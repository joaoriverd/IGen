#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "pollyReduction.h"
#include "commonInterval.h"

using namespace std;

/* Global object with Polly reductions */
PollyReduction GlobalPollyReduction;

/* Counter for reductions IDs */
static size_t id_coutner;

/// CSV row parser. Taken from https://stackoverflow.com/a/1120224/10755597
class CSVRow {
private:
    std::string         m_line;
    std::vector<int>    m_data;

public:
    std::string operator[](std::size_t index) const{
        return std::string(&m_line[m_data[index] + 1], m_data[index + 1] -  (m_data[index] + 1));
    }

    std::size_t size() const{
        return m_data.size() - 1;
    }

    void readNextRow(std::istream& str){
        std::getline(str, m_line);

        m_data.clear();
        m_data.emplace_back(-1);
        std::string::size_type pos = 0;
        while((pos = m_line.find(',', pos)) != std::string::npos) {
            m_data.emplace_back(pos);
            ++pos;
        }
        // This checks for a trailing comma with no data after it.
        pos = m_line.size();
        m_data.emplace_back(pos);
    }
};

std::istream& operator>>(std::istream& str, CSVRow& data) {
    data.readNextRow(str);
    return str;
}

void PollyReduction::readPollyReductions() {
    CSVRow row;
    std::ifstream file(reductionsFileName);

    /* Skip the first line (header) */
    file >> row;

    /* Iterate over the whole file */
    while(file >> row) {
        try {
            size_t loadLine  = stoi(row[0]);
            size_t loadColm  = stoi(row[1]);
            size_t storeLine = stoi(row[2]);
            size_t storeColm = stoi(row[3]);
            size_t loopLvl   = stoi(row[4]);

            /* Insert into polly records */
            pollyDetectedLoads.insert({loadLine,loadColm});
            pollyDetectedStoresAndLoopLvl[{storeLine,storeColm}] = loopLvl;
        }
        catch (...) {
            /* Clean everything and leave */
            llvm::errs() << "Error: File with polly reductions malformed. Skipping reduction improvement process.\n";
            pollyDetectedLoads.clear();
            pollyDetectedStoresAndLoopLvl.clear();
            break;
        }
    }
}

bool PollyReduction::isReductionVariable(clang::Expr* expr) {
    return loads.count(expr);
}

bool PollyReduction::isReductionAssignment(clang::Expr* expr) {
    return stores.count(expr);
}

size_t PollyReduction::getReductionIDFromAssignment(clang::Expr* expr) {
    return stores.at(expr);
}

bool PollyReduction::hasLoopReductions(clang::Stmt* stmt) {
    return loops.count(stmt);
}

vector<reductionVariable>& PollyReduction::getReductionVariablesInLoop(clang::Stmt* stmt) {
    return loops.at(stmt);
}

const clang::Stmt* PollyReduction::searchForParentLoopStmt(clang::Stmt* stmt, size_t loop_lvl) {
    const clang::Stmt* currentStmt = stmt;
    while (loop_lvl > 0) {

        const auto& parents = astContext->getParents(*currentStmt);
        if (parents.empty()) {
            llvm::errs() << "Unable to locate loop node with reduction in the AST.\n";
            return nullptr;
        }

        const clang::Stmt* parentStmt = parents[0].get<clang::Stmt>();
        if (parentStmt && clang::isa<clang::ForStmt>(parentStmt)) {
            /* Parent is a for loop */
            loop_lvl--;
        }

        currentStmt = parentStmt;
    }

    return currentStmt;
}

bool PollyReduction::VisitArraySubscriptExpr(clang::ArraySubscriptExpr* arr) {
    /* Detect load of reduction variable */
    if (semaphore > 0) {
        raw_location_ty load_loc;
        load_loc.line = astContext->getSourceManager().getExpansionLineNumber(arr->getExprLoc());
        load_loc.colm = astContext->getSourceManager().getExpansionColumnNumber(arr->getExprLoc());

        if (isLoadDetectedByPolly(load_loc)) {
            /* Add node as a load of a reduction variable */
            loads.insert(arr);
        }
    }

    return true;
}

bool PollyReduction::VisitBinaryOperator(clang::BinaryOperator* bop) {
    /* Detect assignment with reduction and loop level in which the reduction applies */
    /* Detect load of reduction variable */
    if (semaphore > 0) {
        raw_location_ty store_loc;
        if (bop->getOpcode() == clang::BO_Assign || bop->getOpcode() == clang::BO_AddAssign) {
            store_loc.line = astContext->getSourceManager().getExpansionLineNumber(bop->getOperatorLoc());
            store_loc.colm = astContext->getSourceManager().getExpansionColumnNumber(bop->getOperatorLoc());

            if (isStoreDetectedByPolly(store_loc)) {
                /* Increment the counter of detected reductions */
                id_coutner++;

                /* Add node as a store (assignment) of a reduction variable */
                stores[bop] = id_coutner;

                /* Search for the loop's node where the reduction is performed */
                size_t loop_lvl = pollyDetectedStoresAndLoopLvl[store_loc];
                const clang::Stmt *loopStmt = searchForParentLoopStmt(bop, loop_lvl);
                clang::Expr *redVariable = bop->getLHS();

                /* Mark loop as a loop with reductions and store its reduction variable */
                loops[loopStmt].emplace_back(redVariable, id_coutner);
            }
        }
    }

    return true;
}

bool PollyReduction::VisitCompoundAssignOperator(clang::CompoundAssignOperator *caop) {
    /* Detect compound assignment with reduction and loop level in which the reduction applies */
    return true;
}

bool PollyReduction::VisitForStmt(clang::ForStmt* frs) {
    return RecursiveASTVisitor::VisitForStmt(frs);
}

bool PollyReduction::TraverseArraySubscriptExpr(clang::ArraySubscriptExpr* arr) {
    if (semaphore == 0) {
        return true; // skip node
    }

    return RecursiveASTVisitor::TraverseArraySubscriptExpr(arr);
}

bool PollyReduction::TraverseBinaryOperator(clang::BinaryOperator* bop) {
    /* Detect assignment with reduction and loop level in which the reduction applies */
    if (semaphore == 0) {
        return true; // skip node
    }

    return RecursiveASTVisitor::TraverseBinaryOperator(bop);
}

bool PollyReduction::TraverseCompoundAssignOperator(clang::CompoundAssignOperator *caop) {
    /* Detect compound assignment with reduction and loop level in which the reduction applies */
    if (semaphore == 0) {
        return true; // skip node
    }

    return RecursiveASTVisitor::TraverseCompoundAssignOperator(caop);
}

bool PollyReduction::TraverseForStmt(clang::ForStmt* frs) {
    return RecursiveASTVisitor::TraverseForStmt(frs);
}

bool PollyReduction::TraverseAttributedStmt(clang::AttributedStmt* attr) {
    /* Check that it is a IGen reduce attribute */
    if (auto* igen_attr = clang::dyn_cast<clang::IGenAttr>(attr->getAttrs()[0])) {
        switch (igen_attr->getOption()) {
            case clang::IGenAttr::Reduce:
                llvm::errs() << "igen reduce pragma detected\n";
                semaphore++;
                PollyReduction::TraverseStmt(attr->getSubStmt());
                semaphore--;
                break;
        }
    }
    return true; // Skip child nodes because already processed
}

void PollyReduction::matchReductionsWithASTNodes(clang::Decl* decl) {
    TraverseDecl(decl);
}

void PollyReduction::setASTContext(clang::ASTContext* c) {
    astContext = c;
}

bool PollyReduction::isLoadDetectedByPolly(raw_location_ty &load) {
    return pollyDetectedLoads.count(load);
}

bool PollyReduction::isStoreDetectedByPolly(raw_location_ty &store) {
    return pollyDetectedStoresAndLoopLvl.count(store);
}

void PollyReduction::setRedCSVFileName(std::string& fname) {
    reductionsFileName = fname;
}

/// Get corresponding igen function related to a reduction improvement transformation
std::string getIGenReductionOperationFun(enumReductionOperation op, const std::string& type, const std::string& var, size_t acc_id) {
    string operation;
    string args;
    string funCall;

    switch (op) {
        case RED_INIT:            operation = "_isum_init";       break;
        case RED_ACCUMULATE:      operation = "_isum_accumulate"; break;
        case RED_FINAL_REDUCTION: operation = "_isum_reduce";     break;
    }

    if (type == HALF_T)        { operation += "_f16"; }
    else if (type == FLOAT_T)  { operation += "_f32"; }
    else if (type == DOUBLE_T) { operation += "_f64"; }
    else if (type == DD_T)     { operation += "_dd" ; }
    else {
        cerr << "Error: No interval reduction function for type: " << type << endl;
        throw std::exception();
    }

    if (op == RED_FINAL_REDUCTION) {
        args    = "&" ACCUMULATOR_VAR + to_string(acc_id);
        funCall = var + " = " + operation + "(" + args + ")";
    }
    else {
        args    = "&" ACCUMULATOR_VAR + to_string(acc_id) + ", " + var;
        funCall = operation + "(" + args + ")";
    }

    return funCall;
}

/// Get the accumulator type
std::string getIGenAccumulatorType(const std::string& type) {
    string acc_type;

    if (type == HALF_T)   { acc_type = "acc_f16i_t"; }
    if (type == FLOAT_T)  { acc_type = "acc_f32i_t"; }
    if (type == DOUBLE_T) { acc_type = "acc_f64i_t"; }
    if (type == DD_T)     { acc_type = "acc_ddi_t" ; }

    if (acc_type.empty()) {
        cerr << "Error: No reduction accumulator for type: " << type << endl;
        throw std::exception();
    }

    return acc_type;
}
