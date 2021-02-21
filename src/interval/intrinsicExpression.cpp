#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include <iostream>
#include "intrinsicExpression.h"

using namespace std;

extern std::unordered_set<std::string> supportedSimdIntrinsics;

enum eIntrinsicOperation {
    NA_INTRINSIC = 0,
    ADD_INTRINSIC,
    SUB_INTRINSIC,
    MUL_INTRINSIC,
    DIV_INTRINSIC,
    SET_INTRINSIC,
    SET1_INTRINSIC,
    SET_ZERO_INTRINSIC,
    LOAD_INTRINSIC,
    STORE_INTRINSIC,

    TOTAL_OPERATIONS
};

static const map <string, eIntrinsicOperation> mapIntrinsicOperation{
    /* SSE/SEE2 */
//    {"_mm_set_ps"  , SET_INTRINSIC },
//    {"_mm_set_pd"  , SET_INTRINSIC },
//    {"_mm_add_ps"  , ADD_INTRINSIC },
//    {"_mm_add_pd"  , ADD_INTRINSIC },
//    {"_mm_sub_ps"  , SUB_INTRINSIC },
//    {"_mm_sub_pd"  , SUB_INTRINSIC },
//    {"_mm_mul_ps"  , MUL_INTRINSIC },
//    {"_mm_mul_pd"  , MUL_INTRINSIC },
//    {"_mm_div_ps"  , DIV_INTRINSIC },
//    {"_mm_div_pd"  , DIV_INTRINSIC },

    /* AVX */
//    {"_mm256_load_ps"   , LOAD_INTRINSIC  },
//    {"_mm256_load_pd"   , LOAD_INTRINSIC  },
//    {"_mm256_store_ps"  , STORE_INTRINSIC },
//    {"_mm256_store_pd"  , STORE_INTRINSIC },
//    {"_mm256_set_ps"    , SET_INTRINSIC   },
//    {"_mm256_set_pd"    , SET_INTRINSIC   },
//    {"_mm256_set1_ps"   , SET_INTRINSIC   },
//    {"_mm256_set1_pd"   , SET_INTRINSIC   },
//    {"_mm256_setzero_ps", SET_INTRINSIC   },
//    {"_mm256_setzero_pd", SET_INTRINSIC   },
//    {"_mm256_add_ps"    , ADD_INTRINSIC   },
//    {"_mm256_add_pd"    , ADD_INTRINSIC   },
//    {"_mm256_sub_ps"    , SUB_INTRINSIC   },
//    {"_mm256_sub_pd"    , SUB_INTRINSIC   },
//    {"_mm256_mul_ps"    , MUL_INTRINSIC   },
//    {"_mm256_mul_pd"    , MUL_INTRINSIC   },
//    {"_mm256_div_ps"    , DIV_INTRINSIC   },
//    {"_mm256_div_pd"    , DIV_INTRINSIC   },
 };

bool loadIntrinsic (intervalExpression& iRes, string& intrinsic, vector<intervalExpression>& iArgs) {

    iRes.intervalVar = "";

    cout << iRes.typeStr << endl;

    size_t numArgs = 1;
    if (iRes.typeStr == M256D_T) {
        numArgs = 4;
        iRes.loExpr = "_mm256_set_pd";
        iRes.upExpr = "_mm256_set_pd";
    }
    else if (iRes.typeStr == M256S_T) {
        numArgs = 8;
        iRes.loExpr = "_mm256_set_ps";
        iRes.upExpr = "_mm256_set_ps";
    }
    else if (iRes.typeStr == M128D_T) {
        numArgs = 2;
        iRes.loExpr = "_mm_set_pd";
        iRes.upExpr = "_mm_set_pd";
    }
    else if (iRes.typeStr == M128S_T) {
        numArgs = 4;
        iRes.loExpr = "_mm_set_ps";
        iRes.upExpr = "_mm_set_ps";
    }

    /* Prepare arguments */
    string arr = iArgs[0].getIntervalExpr();
    string args_lo, args_up;
    for (size_t i = numArgs; i > 0; --i) {
        args_lo += arr + "[" + to_string(i-1) + "].lo";
        args_up += arr + "[" + to_string(i-1) + "].up";

        if (i > 1) {
            args_lo += ", ";
            args_up += ", ";
        }
    }

    iRes.loExpr += "(" + args_lo + ")";
    iRes.upExpr += "(" + args_up + ")";

    return true;
}

bool setIntrinsic (intervalExpression& iRes, string& intrinsic, vector<intervalExpression>& args) {

    iRes.intervalVar = "";
    iRes.loExpr = intrinsic + "(";
    iRes.upExpr = intrinsic + "(";

    /* Add arguments to function */
    for (intervalExpression& iarg : args) {
        if (!iarg.isConstantExpr()) {
            /* Generate complete variable for non-constants arguments */
            iarg.getVar();
        }

        iRes.loExpr += iarg.loExpr;
        iRes.upExpr += iarg.upExpr;

        if (&iarg != &args.back()) {
            iRes.loExpr += ", ";
            iRes.upExpr += ", ";
        }
    }

    iRes.loExpr += ")";
    iRes.upExpr += ")";

    return true;
}

bool addIntrinsic (intervalExpression& iRes, string& intrinsic, vector<intervalExpression>& args) {

    /* Generate complete variable for arguments */
    args[0].getVar();
    args[1].getVar();

    iRes.intervalVar = "";
    iRes.loExpr = intrinsic + "(" + args[0].loExpr + ", " + args[1].loExpr + ")";
    iRes.upExpr = intrinsic + "(" + args[0].upExpr + ", " + args[1].upExpr + ")";
    return true;
}

bool subIntrinsic (intervalExpression& iRes, string& intrinsic, vector<intervalExpression>& args) {

    /* Generate complete variable for arguments */
    args[0].getVar();
    args[1].getVar();

    iRes.intervalVar = "";
    iRes.loExpr = intrinsic + "(" + args[0].loExpr + ", -" + args[1].upExpr + ")";
    iRes.upExpr = intrinsic + "(" + args[0].upExpr + ", -" + args[1].loExpr + ")";
    return true;
}

bool intervalFunctionIntrinsic (intervalExpression& iRes, string& intrinsic, vector<intervalExpression>& args) {

    iRes.intervalVar = IAGEN_PREFIX + intrinsic + "(" + args[0].getVar() + ", " + args[1].getVar() + ")";
    iRes.loExpr = "";
    iRes.upExpr = "";
    return true;
}

bool fallbackIntrinsic (intervalExpression& iRes, string& intrinsic, vector<intervalExpression>& args) {

    /* Change the name of the intrinsic function to the corresponding internal one supported */
    string prefix;
    switch (getTransformationMode()) {
        case NORMAL_MODE:
        case PROMOTE_TO_FP32_MODE: prefix = IAGEN_PREFIX; break;
        /* Find a way to only change intrinsics which have f32 type (promoted to f64) */
        case PROMOTE_TO_FP64_MODE: break;
        /* For this case all supported intrinsics are promoted to its double-double version */
        case PROMOTE_TO_DD_MODE:   prefix = IAGEN_PREFIX DD_PREFIX; break;
    }
    iRes.intervalVar = prefix + intrinsic + "(";

    /* Add arguments to function */
    for (intervalExpression& iarg : args) {
        if (iarg.isIntervalExpr()) {
            /* Generate complete variable for interval arguments */
            iarg.getVar();
        }

        iRes.intervalVar += iarg.intervalVar;

        if (&iarg != &args.back()) {
            iRes.intervalVar += ", ";
        }
    }
    iRes.intervalVar += ")";
    iRes.loExpr = "";
    iRes.upExpr = "";
    return true;
}

bool convertIntrinsicInstruction(intervalExpression& iRes, string& intrinsic, vector<intervalExpression>& args) {

    if (!isIntrinsicFunction(intrinsic)) {
        return false;
    }

    if (isOptimizedIntrinsicSupported(intrinsic)) {
        switch (mapIntrinsicOperation.at(intrinsic)) {
            case LOAD_INTRINSIC:
                loadIntrinsic(iRes, intrinsic, args);
                break;
            case SET_INTRINSIC:
            case SET1_INTRINSIC:
            case SET_ZERO_INTRINSIC:
                setIntrinsic(iRes, intrinsic, args);
                break;
            case ADD_INTRINSIC:
                addIntrinsic(iRes, intrinsic, args);
                break;
            case SUB_INTRINSIC:
                subIntrinsic(iRes, intrinsic, args);
                break;
            case MUL_INTRINSIC:
            case DIV_INTRINSIC:
            case STORE_INTRINSIC:
                intervalFunctionIntrinsic(iRes, intrinsic, args);
                break;
            default:
                /* In case the intrinsic is not supported, go to the fallback approach.
                 * Slow but fairly complete. */
                fallbackIntrinsic(iRes, intrinsic, args);
                break;
        }
    }
    else {
        /* No optimized version supported for this intrinsic. Thus, use fallback approach. */
        fallbackIntrinsic(iRes, intrinsic, args);
    }

    return true;
}

bool isIntrinsicFunction(string& funName) {
    const auto it  = supportedSimdIntrinsics.find(funName);
    const auto end = supportedSimdIntrinsics.end();

    return (it != end);
}

bool isOptimizedIntrinsicSupported(string& funName) {
    const auto it  = mapIntrinsicOperation.find(funName);
    const auto end = mapIntrinsicOperation.end();

    return (it != end);
}
