#include <iostream>
#include "commonInterval.h"
#include "util.h"

using namespace std;
using namespace clang;

/* Default library used for transformation */
static eIntervalLibraries intervalLibrary = IAGEN;

/// Transformation mode:
/// NORMAL_MODE,            /* Default mode, all types are promoted to intervals */
/// PROMOTE_TO_FP32_MODE,   /* Promotes fp16 to fp32 */
/// PROMOTE_TO_FP64_MODE,   /* Promotes fp16/fp32 to fp64 */
/// PROMOTE_TO_FP128_MODE,  /* Promotes fp16/fp32/fp64 to fp128 */
/// PROMOTE_TO_DD_MODE,     /* Promotes fp16/fp32/fp64 to double-double */
static eTransformationMode transformationMode = NORMAL_MODE;

/// Math library used. This flag decides whether to generate header file
/// for interval math functions. This is only set if a supported math
/// function is detected. Same for reduction improvement.
static bool flagIntervalMathUsed = false;
static bool flagReductionImprovementUsed = false;
static bool flagLongDoubleUsed = false;

static const vector< pair <string, string> > supportedTypes {
        {DD_T     , DD_INTERVAL_T},
        {DOUBLE_T , DOUBLE_INTERVAL_T},
        {FLOAT_T  , FLOAT_INTERVAL_T},
        {HALF_T   , HALF_INTERVAL_T},

        /* Intrinsics types */
        {M128D_T , M128D_INTERVAL_T},
        {M128S_T , M128S_INTERVAL_T},
        {M256D_T , M256D_INTERVAL_T},
        {M256S_T , M256S_INTERVAL_T},
        {M512D_T , M512D_INTERVAL_T},
        {M512S_T , M512S_INTERVAL_T},

        /* Custom integer types */
        {UINT32_T, UINT32_I},
        {UINT64_T, UINT64_I},

        /* Artificial vector double-double types */
        {DD2_T , DD2_INTERVAL_T },
        {DD4_T , DD4_INTERVAL_T },
        {DD8_T , DD8_INTERVAL_T },
        {DD16_T, DD16_INTERVAL_T},
};

static const vector< pair <string, string> > vectorCanonicalTypes {
        {M128D_CANONICAL_T, M128D_T},
        {M128S_CANONICAL_T, M128S_T},
        {M256D_CANONICAL_T, M256D_T},
        {M256S_CANONICAL_T, M256S_T},
        {M512D_CANONICAL_T, M512D_T},
        {M512S_CANONICAL_T, M512S_T},
};

static const map <string, string> supportedMathFun {
        /* Double precision */
        {"sqrt"  , "_ia_sqrt" },
        {"fabs"  , "_ia_abs"  },
        {"floor" , "_ia_floor"},
        {"ceil"  , "_ia_ceil" },
        {"exp"   , "_ia_exp"  },
        {"expm1" , "_ia_expm1"},
        {"log"   , "_ia_log"  },
        {"log2"  , "_ia_log2" },
        {"log10" , "_ia_log10"},
        {"log1p" , "_ia_log1p"},
        {"sin"   , "_ia_sin"  },
        {"cos"   , "_ia_cos"  },
        {"tan"   , "_ia_tan"  },
        {"asin"  , "_ia_asin" },
        {"acos"  , "_ia_acos" },
        {"atan"  , "_ia_atan" },
        {"sinh"  , "_ia_sinh" },
        {"cosh"  , "_ia_cos"  },

        /* Single precision */
        {"sqrtf" , "_ia_sqrt"},
        {"fabsf" , "_ia_abs" },
        {"expf"  , "_ia_exp" },
        {"logf"  , "_ia_log" },
        {"sinf"  , "_ia_sin" },
        {"cosf"  , "_ia_cos" },
        {"tanf"  , "_ia_tan" },
        {"asinf" , "_ia_asin"},
        {"acosf" , "_ia_acos"},
        {"atanf" , "_ia_atan"},
};

static const map <string, string> supportedMathFunMPFI {
        /* Elementary functions MPFI */
        {"sqrt"  , "mpfi_sqrt" },
        {"fabs"  , "mpfi_abs"  },
        {"exp"   , "mpfi_exp"  },
        {"expm1" , "mpfi_expm1"},
        {"log"   , "mpfi_log"  },
        {"log2"  , "mpfi_log2" },
        {"log10" , "mpfi_log10"},
        {"log1p" , "mpfi_log1p"},
        {"sin"   , "mpfi_sin"  },
        {"cos"   , "mpfi_cos"  },
        {"tan"   , "mpfi_tan"  },
        {"asin"  , "mpfi_asin" },
        {"acos"  , "mpfi_acos" },
        {"atan"  , "mpfi_atan" },
        {"sinh"  , "mpfi_sinh" },
        {"cosh"  , "mpfi_cosh" },

        /* Single precision */
        {"sqrtf" , "mpfi_sqrt"},
        {"fabsf" , "mpfi_abs" },
        {"expf"  , "mpfi_exp" },
        {"logf"  , "mpfi_log" },
        {"sinf"  , "mpfi_sin" },
        {"cosf"  , "mpfi_cos" },
        {"tanf"  , "mpfi_tan" },
        {"asinf" , "mpfi_asin"},
        {"acosf" , "mpfi_acos"},
        {"atanf" , "mpfi_atan"},
};

static const map <string, string> reductionFunctions {
        /* Reduction functions */
        {FLOAT_INTERVAL_T  "," FLOAT_T,  "_ia_reduce_f2f"},
        {DOUBLE_INTERVAL_T "," FLOAT_T,  "_ia_reduce_d2f"},
        {DOUBLE_INTERVAL_T "," DOUBLE_T, "_ia_reduce_d2d"},
};

///
/// Get corresponding igen function for the operation "op"
///
string _iaFunName(string op, string type) {

    if (type == HALF_T) {
        if (op == "=")  { return "_ia_set_f16";    }
        if (op == "+")  { return "_ia_add_f16";    }
        if (op == "-")  { return "_ia_sub_f16";    }
        if (op == "*")  { return "_ia_mul_f16";    }
        if (op == "/")  { return "_ia_div_f16";    }
        if (op == "neg"){ return "_ia_neg_f16";    }
        if (op == "<")  { return "_ia_cmplt_f16";  }
        if (op == "<=") { return "_ia_cmple_f16";  }
        if (op == ">")  { return "_ia_cmpgt_f16";  }
        if (op == ">=") { return "_ia_cmpge_f16";  }
        if (op == "==") { return "_ia_cmpeq_f16";  }
        if (op == "!=") { return "_ia_cmpneq_f16"; }

        /* Constants */
        if (op == "zero") { return "_ia_zero_f16"; }
        if (op == "one")  { return "_ia_one_f16";  }

    }

    if (type == FLOAT_T) {
        if (op == "=")  { return "_ia_set_f32";    }
        if (op == "+")  { return "_ia_add_f32";    }
        if (op == "-")  { return "_ia_sub_f32";    }
        if (op == "*")  { return "_ia_mul_f32";    }
        if (op == "/")  { return "_ia_div_f32";    }
        if (op == "neg"){ return "_ia_neg_f32";    }
        if (op == "<")  { return "_ia_cmplt_f32";  }
        if (op == "<=") { return "_ia_cmple_f32";  }
        if (op == ">")  { return "_ia_cmpgt_f32";  }
        if (op == ">=") { return "_ia_cmpge_f32";  }
        if (op == "==") { return "_ia_cmpeq_f32";  }
        if (op == "!=") { return "_ia_cmpneq_f32"; }

        /* Constants */
        if (op == "zero") { return "_ia_zero_f32"; }
        if (op == "one")  { return "_ia_one_f32" ; }
    }

    if (type == DOUBLE_T) {
        if (op == "=")  { return "_ia_set_f64";    }
        if (op == "+")  { return "_ia_add_f64";    }
        if (op == "-")  { return "_ia_sub_f64";    }
        if (op == "*")  { return "_ia_mul_f64";    }
        if (op == "/")  { return "_ia_div_f64";    }
        if (op == "neg"){ return "_ia_neg_f64";    }
        if (op == "<")  { return "_ia_cmplt_f64";  }
        if (op == "<=") { return "_ia_cmple_f64";  }
        if (op == ">")  { return "_ia_cmpgt_f64";  }
        if (op == ">=") { return "_ia_cmpge_f64";  }
        if (op == "==") { return "_ia_cmpeq_f64";  }
        if (op == "!=") { return "_ia_cmpneq_f64"; }

        /* Constants */
        if (op == "zero") { return "_ia_zero_f64"; }
        if (op == "one")  { return "_ia_one_f64" ; }
    }

    /* Support for double double types (including vectors fo double-doubles) */
    if (type == DD_T || type == DD2_T || type == DD4_T || type == DD8_T || type == DD16_T) {
        string opName;
        if (op == "=")   { opName = "_ia_set_dd";   }
        if (op == "+")   { opName = "_ia_add_dd";   }
        if (op == "-")   { opName = "_ia_sub_dd";   }
        if (op == "*")   { opName = "_ia_mul_dd";   }
        if (op == "/")   { opName = "_ia_div_dd";   }
        if (op == "neg") { opName = "_ia_neg_dd";   }
        if (op == "++")  { opName = "_ia_add1_dd";  }
        if (op == "--")  { opName = "_ia_sub1_dd";  }
        if (op == "<")   { opName = "_ia_cmplt_dd"; }
        if (op == "<=")  { opName = "_ia_cmple_dd"; }
        if (op == ">")   { opName = "_ia_cmpgt_dd"; }
        if (op == ">=")  { opName = "_ia_cmpge_dd"; }
        if (op == "==")  { opName = "_ia_cmpeq_dd"; }
        if (op == "!=")  { opName = "_ia_cmpneq_dd";}

        /* Constants */
        if (op == "zero") { return "_ia_zero_dd"; }
        if (op == "one")  { return "_ia_one_dd" ; }

        string postfix;
        if(type == DD_T)   { postfix = "";   }
        if(type == DD2_T)  { postfix = "x2";  }
        if(type == DD4_T)  { postfix = "x4";  }
        if(type == DD8_T)  { postfix = "x8";  }
        if(type == DD16_T) { postfix = "x16"; }

        return opName + postfix;
    }

    if (type == M256D_T) {
        if (op == "+")   { return "_ia_add_m256d";    }
        if (op == "-")   { return "_ia_sub_m256d";    }
        if (op == "*")   { return "_ia_mul_m256d";    }
        if (op == "/")   { return "_ia_div_m256d";    }
        if (op == "neg") { return "_ia_neg_m256d";    }
        if (op == "<")   { return "_ia_cmplt_m256d";  }
        if (op == "<=")  { return "_ia_cmple_m256d";  }
        if (op == ">")   { return "_ia_cmpgt_m256d";  }
        if (op == ">=")  { return "_ia_cmpge_m256d";  }
        if (op == "==")  { return "_ia_cmpeq_m256d";  }
        if (op == "!=")  { return "_ia_cmpneq_m256d"; }
    }

    if (type == M256S_T) {
        if (op == "+")   { return "_ia_add_m256s";    }
        if (op == "-")   { return "_ia_sub_m256s";    }
        if (op == "*")   { return "_ia_mul_m256s";    }
        if (op == "/")   { return "_ia_div_m256s";    }
        if (op == "neg") { return "_ia_neg_m256s";    }
        if (op == "<")   { return "_ia_cmplt_m256s";  }
        if (op == "<=")  { return "_ia_cmple_m256s";  }
        if (op == ">")   { return "_ia_cmpgt_m256s";  }
        if (op == ">=")  { return "_ia_cmpge_m256s";  }
        if (op == "==")  { return "_ia_cmpeq_m256s";  }
        if (op == "!=")  { return "_ia_cmpneq_m256s"; }
    }

    if (type == M128D_T) {
        if (op == "+")   { return "_ia_add_m128d";    }
        if (op == "-")   { return "_ia_sub_m128d";    }
        if (op == "*")   { return "_ia_mul_m128d";    }
        if (op == "/")   { return "_ia_div_m128d";    }
        if (op == "neg") { return "_ia_neg_m128d";    }
        if (op == "<")   { return "_ia_cmplt_m128d";  }
        if (op == "<=")  { return "_ia_cmple_m128d";  }
        if (op == ">")   { return "_ia_cmpgt_m128d";  }
        if (op == ">=")  { return "_ia_cmpge_m128d";  }
        if (op == "==")  { return "_ia_cmpeq_m128d";  }
        if (op == "!=")  { return "_ia_cmpneq_m128d"; }
    }

    if (type == M128S_T) {
        if (op == "+")   { return "_ia_add_m128s";    }
        if (op == "-")   { return "_ia_sub_m128s";    }
        if (op == "*")   { return "_ia_mul_m128s";    }
        if (op == "/")   { return "_ia_div_m128s";    }
        if (op == "neg") { return "_ia_neg_m128s";    }
        if (op == "<")   { return "_ia_cmplt_m128s";  }
        if (op == "<=")  { return "_ia_cmple_m128s";  }
        if (op == ">")   { return "_ia_cmpgt_m128s";  }
        if (op == ">=")  { return "_ia_cmpge_m128s";  }
        if (op == "==")  { return "_ia_cmpeq_m128s";  }
        if (op == "!=")  { return "_ia_cmpneq_m128s"; }
    }

    if (type == UINT32_T) {
        if (op == "&") { return "_ia_and_u32"; }
        if (op == "|") { return "_ia_or_u32"; }
    }

    if (type == UINT64_T) {
        if (op == "&") { return "_ia_and_u64"; }
        if (op == "|") { return "_ia_or_u64"; }
    };

    /* Logical functions */
    if (op == "&&") { return "_ia_and_tb"; }
    if (op == "||") { return "_ia_or_tb"; }

    cerr << "Error: No interval function for operand found (_iaFunName)" << endl;
    throw std::exception();
}

///
/// Get corresponding igen function for casting
///
string _iaCastFunName(string t_base, string t_dest) {
    return "_ia_cast" + getPostfixForType(t_base) + "_to" + getPostfixForType(t_dest);
}

///
/// Get the currently used interval library for code transformation
///
eIntervalLibraries getIntervalLib () {
    return intervalLibrary;
}

///
/// Get the currently used transformation mode for input and output of each function
///
eTransformationMode getTransformationMode () {
    return transformationMode;
}

///
/// Set currently used interval library for code transformation
///
void setIntervalLib (eIntervalLibraries lib) {
    intervalLibrary = lib;
}

///
/// Set currently used interval library for code transformation
///
void setTransformationMode (eTransformationMode mode) {
    transformationMode = mode;
}

///
/// This will return true if the type can be transformed in any way.
/// E.g. from double to interval or from a pointer to double to a pointer
/// to interval.
///
bool isTypeTransformable(const string& type) {
    for (const pair <string, string>& t : supportedTypes) {

        size_t pos = type.find(t.first);
        if (pos != string::npos ) {
            /* A supported type is found. Make sure that this is indeed the case. E.g. my_double should
             * not be detected as supported type. To this end, the immediate left character of e.g. "double"
             * should be either a space or nothing. Similar for the character immediate after the type */
            bool isIntervalType = true;
            if (pos > 0) {
                size_t prev = pos - 1;
                bool isInvaildChar = (type.at(prev) >= 'a' && type.at(prev) <= 'z') ||
                                     (type.at(prev) >= 'A' && type.at(prev) <= 'Z') ||
                                     (type.at(prev) >= '0' && type.at(prev) <= '9') ||
                                     (type.at(prev)  =='_');
                isIntervalType &= !isInvaildChar;
            }
            if (pos + t.first.size() < type.size()) {
                size_t post = pos + t.first.size();
                bool isInvaildChar = (type.at(post) >= 'a' && type.at(post) <= 'z') ||
                                     (type.at(post) >= 'A' && type.at(post) <= 'Z') ||
                                     (type.at(post) >= '0' && type.at(post) <= '9') ||
                                     (type.at(post)  =='_');
                isIntervalType &= !isInvaildChar;
            }
            return isIntervalType;
        }
    }
    return false;
}

///
/// Returns the type as a string either with qualifier or without.
/// It also promotes the type when required.
///
string getTypeAsString(const clang::QualType& type, bool getQualifier) {
    /* Get type as string */
    string typeStr = (getQualifier) ? type.getAsString() : type.getUnqualifiedType().getAsString();

    if (transformationMode != NORMAL_MODE) {
        promoteType(typeStr);
    }

    return  typeStr;
}

///
/// Returns the canonical type without qualifier. This always returns
/// the canonical type. This allows to get the underlying type possibly
/// hidden using typedef. The canonical type of vector types is not used
/// since it may not be suitable, and we rise the type to standard vector
/// type when detected (e.g. __m256d). If the non-canonical type is transformable
/// then it returns that (to allow custom transformable types defined by our
/// tool e.g. interval integers). It also promotes the type when required.
///
string getBareTypeAsString(const clang::QualType& type) {
    /* Get type as string */
    string typeNonCanonical = type.getUnqualifiedType().getAsString();
    string typeCanonical = type.getCanonicalType().getUnqualifiedType().getAsString();
    string typeStr;

    if (isTypeSupported(typeNonCanonical)) {
        typeStr = typeNonCanonical;
    }
    else {
        typeStr = typeCanonical;
    }

    /* Rise canonical vector type to its standard type used (e.g. __m256d) if applicable */
    rewriteCanonicalVectorType(typeStr);

    if (transformationMode != NORMAL_MODE) {
        promoteType(typeStr);
    }

    return  typeStr;
}

///
/// Only returns true if the type is supported to perform interval
/// operations. E.g. it returns true for "double" and it returns false
/// for "double*". Although the latter is transformed to a pointer to
/// interval, all the operations on pointers are not interval operations.
///
bool isTypeSupported(const string& type) {
    for (const pair <string, string>& t : supportedTypes) {
        if (t.first == type) return true;
    }
    return false;
}

/// Overloaded version of above
bool isTypeSupported(const QualType& qt) {
    string type = qt.getUnqualifiedType().getAsString();
    for (const pair <string, string>& t : supportedTypes) {
        if (t.first == type) return true;
    }
    return false;
}

///
/// Only returns true if the type is interval integer.
/// Intervals on integers are only supported for simd2interval
/// transformations.
///
bool isTypeIntervalInteger(const string& type) {
    return UINT32_T == type || UINT64_T == type;
}

///
/// Only returns true if the type is interval vector.
///
bool isTypeIntervalVector(const string& type) {
    bool res;
    res =   (type == M128D_T) ||
            (type == M128S_T) ||
            (type == M256D_T) ||
            (type == M256S_T) ||
            (type == M512D_T) ||
            (type == M512S_T) ||
            (type == DD2_T )  ||
            (type == DD4_T )  ||
            (type == DD8_T )  ||
            (type == DD16_T);
    return res;
}

///
/// Only returns true if the type is integer bare type.
///
bool isTypeInteger(const string& type) {
    bool res;
    res =   (type == INT_T)   ||
            (type == UINT_T)  ||
            (type == LONG_T)  ||
            (type == ULONG_T) ||
            (type == LL_T)    ||
            (type == ULL_T);
    return res;
}

///
/// Only returns true if the type is long double bare type.
///
bool isTypeLongDouble(const string& type) {
    return type == DD_T;
}

///
/// Returns true in case the type was transformed to its respective
/// interval type.
///
bool transformToIntervalType (string& type) {

    /* Check first if type can be transformed */
    if (!isTypeTransformable(type)) {
        return false;
    }

    /* Check if the type to transform is (or contains) long double */
    if (isTypeLongDouble(type)) {
        flagLongDoubleUsed = true;
    }

    for ( const pair<string, string>& t : supportedTypes ) {
        /* Search for the type and replace it by its interval counterpart. */
        string intervalType = (getIntervalLib() == IAGEN) ? t.second : MPFI_TYPE;
        replaceSubString(type, t.first , intervalType);
    }

    return true;
}

///
/// This function promotes the basic types, e.g. float, double, etc.
/// Thus, it should not be used to promote non-basic types, e.g. float*
/// Returns, the promoted type if possible, same type as input otherwise.
///
string promoteBasicType(const string& type) {
    string promType = type;

    if (transformationMode == PROMOTE_TO_FP32_MODE) {
        if (type == HALF_T)  { promType = FLOAT_T; }
    }

    if (transformationMode == PROMOTE_TO_FP64_MODE) {
        if (type == HALF_T ) { promType = DOUBLE_T; }
        if (type == FLOAT_T) { promType = DOUBLE_T; }
        if (type == M128S_T) { promType = M256D_T;  }
        if (type == M256S_T) { promType = M512D_T;  }
    }

    if (transformationMode == PROMOTE_TO_DD_MODE) {
        if (type == HALF_T  ) { promType = DD_T;   }
        if (type == FLOAT_T ) { promType = DD_T;   }
        if (type == DOUBLE_T) { promType = DD_T;   }
        if (type == M128S_T ) { promType = DD4_T;  }
        if (type == M256S_T ) { promType = DD8_T;  }
        if (type == M512S_T ) { promType = DD16_T; }
        if (type == M128D_T ) { promType = DD2_T;  }
        if (type == M256D_T ) { promType = DD4_T;  }
        if (type == M512D_T ) { promType = DD8_T;  }
    }

    return promType;
}

///
/// Returns true in case the type was successfully promoted to
/// double precision (or if it was already in double precision)
///
bool promoteType(string& type) {

    /* Check first if type can be transformed */
    if (!isTypeTransformable(type)) {
        return false;
    }

    for ( const pair<string, string>& t : supportedTypes ) {
        /* Search for the type and replace it by its promoted version. */
        string promotedType = promoteBasicType(t.first);
        replaceSubString(type, t.first , promotedType);
    }

    return true;
}

///
/// Translates an elementary math function ( e.g. cos() ), to its respective
/// interval function (e.g. _ia_cos_f64() ). Returns true in case the function
/// was translated, false otherwise.
///
bool translateMathFun(string& funName, string type) {

    auto it  = (getIntervalLib() == IAGEN) ? supportedMathFun.find(funName) : supportedMathFunMPFI.find(funName);
    auto end = (getIntervalLib() == IAGEN) ? supportedMathFun.end()         : supportedMathFunMPFI.end();

    if (it != end) {
        /* Math function is transformed to interval version */
        string igenFun = it->second;
        string postfix = (getIntervalLib() == IAGEN) ? getPostfixForType(type) : "";
        funName        = igenFun + postfix;
        return true;
    }

    return false;
}

///
/// Stores the reduction function name into funName corresponding to the
/// given type, e.g. _ia_reduce_d2f() when the type = float. The function
/// returns true when the reduction function was found, false otherwise.
///
string getReductionFunction (const string& intervalType, const string& retType) {

    string reductionTypes = intervalType + "," + retType;
    auto it  = reductionFunctions.find(reductionTypes);
    auto end = reductionFunctions.end();

    if (it != end) {
        /* Math function is transformed to interval version */
        return it->second;
    }

    return "";
}

///
/// Rewrite the canonical type of a vector type to its standard alias (e.g. to __m256d)
///
void rewriteCanonicalVectorType(string& type) {
    for ( const pair<string, string>& t : vectorCanonicalTypes ) {
        /* Search for the type and replace it by its interval counterpart. */
        string intervalType = t.second;
        replaceSubString(type, t.first , intervalType);
    }
}

///
/// Returns whether a interval elementary (math) functions are used in the transformed code.
///
bool isIntervalMathUsed() {
    return flagIntervalMathUsed;
}

///
/// Returns whether improvement for reductions is used.
///
bool isReductionImprovementUsed() {
    return flagReductionImprovementUsed;
}

///
/// Returns whether long double is used in the code. This is helpful to include the correct
/// header file for double-double.
///
bool isLongDoubleUsed() {
    return flagLongDoubleUsed;
}

///
/// Set flag specifying that elementary (math) functions are used in the transformed code.
///
void setIntervalMathUsed() {
    flagIntervalMathUsed = true;
}

///
/// Set flag specifying that improvement for reductions is used.
///
void setReductionImprovementUsed() {
    flagReductionImprovementUsed = true;
}

///
/// Get postfix for the given type
///
string getPostfixForType(const string& type) {
    /* Integer types */
    if (type == INT_T)    { return "_int";  }
    if (type == UINT_T)   { return "_uint"; }
    if (type == LONG_T)   { return "_long"; }
    if (type == ULONG_T)  { return "_ulong";}
    if (type == LL_T)     { return "_long"; }
    if (type == ULL_T)    { return "_ulong";}

    /* Floating point types */
    if (type == DD_T)     { return "_dd";  }
    if (type == DOUBLE_T) { return "_f64"; }
    if (type == FLOAT_T)  { return "_f32"; }
    if (type == HALF_T)   { return "_f16"; }

    /* Vector types */
    // todo: complete vector types
    if (type == M256D_T)  { return "_m256d"; }
    if (type == DD2_T)    { return "_dd2";   }
    if (type == DD4_T)    { return "_dd4";   }
    if (type == DD8_T)    { return "_dd8";   }
    if (type == DD16_T)   { return "_dd16";  }

    cerr << "Type not found (getPostfixForType): " << type << endl;
    throw std::exception();
}

///
/// Get the necessary header files of IGen
///
string getIGenHeaderFiles() {
    string headers;

    if (getTransformationMode() == PROMOTE_TO_DD_MODE || isLongDoubleUsed()) {
        headers  = getIntervalLib() == IAGEN    ? IAGEN_DD_INCLUDE_HEADER   : "";
        headers += isReductionImprovementUsed() ? IAGEN_DD_REDUCTION_HEADER : "";
        headers += (isIntervalMathUsed())       ? IAGEN_DD_MATH_HEADER      : "";
    }
    else {
        headers  = getIntervalLib() == IAGEN    ? IAGEN_INCLUDE_HEADER   : MPFI_INCLUDE_HEADER;
        headers += isReductionImprovementUsed() ? IAGEN_REDUCTION_HEADER : "";
        if (isIntervalMathUsed()) {
            headers += (getIntervalLib() == IAGEN) ? IAGEN_MATH_HEADER   : MPFI_MATH_HEADER;
        }
    }

    return headers;
}