#ifndef INTERVAL_ARITHMETIC_COMMONINTERVAL_H
#define INTERVAL_ARITHMETIC_COMMONINTERVAL_H
#include <string>
#include <vector>
#include <map>
#include "clang/AST/Type.h"
#include "clang/Frontend/CompilerInstance.h"

#define JOIN_IN_BRANCHES false

/* New line and semicolon */
#define NL      "\n"
#define NLSS    "\n    "
#define SCNL    ";\n    "
#define TEMP_VAR_SUFIX "_t"

/* Types */
#define HALF_T      "_Float16"
#define FLOAT_T     "float"
#define DOUBLE_T    "double"
#define DD_T        "long double"      /* Using double-double to represent long double */
#define UINT_T      "unsigned int"
#define INT_T       "int"
#define LONG_T      "long"
#define ULONG_T     "unsigned long"
#define LL_T        "long long"
#define ULL_T       "unsigned long long"
#define M128S_T     "__m128"
#define M128D_T     "__m128d"
#define M256S_T     "__m256"
#define M256D_T     "__m256d"
#define M512S_T     "__m512"
#define M512D_T     "__m512d"

#define M128S_CANONICAL_T "__attribute__((__vector_size__(4 * sizeof(float)))) float"
#define M128D_CANONICAL_T "__attribute__((__vector_size__(2 * sizeof(double)))) double"
#define M256S_CANONICAL_T "__attribute__((__vector_size__(8 * sizeof(float)))) float"
#define M256D_CANONICAL_T "__attribute__((__vector_size__(4 * sizeof(double)))) double"
#define M512S_CANONICAL_T "__attribute__((__vector_size__(16 * sizeof(float)))) float"
#define M512D_CANONICAL_T "__attribute__((__vector_size__(8 * sizeof(double)))) double"

/* Precision of types */
#define F128_PRECISION 128
#define F64_PRECISION  64
#define F32_PRECISION  32

/* Interval types */
#define DD_INTERVAL_T       "dd_I"
#define DOUBLE_INTERVAL_T   "f64_I"
#define FLOAT_INTERVAL_T    "f32_I"
#define HALF_INTERVAL_T     "f16_I"
#define M128S_INTERVAL_T    "m256di_2"
#define M128D_INTERVAL_T    "m256di_1"
#define M256S_INTERVAL_T    "m256di_4"
#define M256D_INTERVAL_T    "m256di_2"
#define M512S_INTERVAL_T    "m256di_8"
#define M512D_INTERVAL_T    "m256di_4"

/* Artificial double-double vector types */
#define DD2_T               "dd_2"
#define DD4_T               "dd_4"
#define DD8_T               "dd_8"
#define DD16_T              "dd_16"
#define DD2_INTERVAL_T      "ddi_2"
#define DD4_INTERVAL_T      "ddi_4"
#define DD8_INTERVAL_T      "ddi_8"
#define DD16_INTERVAL_T     "ddi_16"

/* Custom integer interval types */
#define UINT32_T      "_u32"
#define UINT64_T      "_u64"
#define UINT32_I      "u32_I"
#define UINT64_I      "u64_I"

#define TRUE_NATIVE     "1"
#define FALSE_NATIVE    "0"

/* FP rounding environment definitions */
#if false
#define CODE_FROUND_INIT                                         NLSS \
                             "#pragma STDC FENV_ACCESS ON"       NLSS \
                             "int _fp_round = fegetround();"     NLSS \
                             "fesetround(FE_UPWARD);"            NLSS

#define CODE_RESTORE_FROUND  "fesetround(_fp_round);" NLSS
#else
#define CODE_FROUND_INIT    ""
#define CODE_RESTORE_FROUND ""
#endif

/* Return */
#define RETURN_KEY           "return"
#define RETURN_VAR           "_ret"
#define RETURN_VAR_F         "_ret_f"
#define RETURN_VAR_LO        "_ret.lo"
#define RETURN_VAR_UP        "_ret.up"

#define SIZEOF(a)  "sizeof(" + a + ")"
#define ALIGNOF(a) "_Alignof(" + a + ")"

#define TOLERANCE_TYPE_SEPARATOR ':'

/* IAGEN code definitions */
#define IAGEN_INCLUDE_HEADER    "#include \"igen_lib.h\"" NL
#define IAGEN_MATH_HEADER       "#include \"igen_math.h\"" NL
#define IAGEN_REDUCTION_HEADER  "#include \"igen_reduction.h\"" NL
#define IAGEN_DD_INCLUDE_HEADER    "#include \"igen_dd_lib.h\"" NL
#define IAGEN_DD_MATH_HEADER       "#include \"igen_dd_math.h\"" NL
#define IAGEN_DD_REDUCTION_HEADER  "#include \"igen_dd_reduction.h\"" NL

#define IAGEN_INTERVAL_VAR_DEF(TYPE, VAR, LO, UP) TYPE + " " + VAR + " = {" + LO + ", " + UP + "}"

#define IA_PREFIX        "_ia"
#define IAGEN_PREFIX     "_igen"
#define DD_PREFIX        "_dd"
#define IN_PARAM_PREFIX  "_in_"
#define OUT_PARAM_PREFIX "_out_"

/* IA Functions */
#define IA_CVT_FUN(t1, t2) ("_ia_cvt_" + t1 + "2" + t2)
#define IA_CVT2TB_FUN       "_ia_cvt2tb"
#define IA_TRUE             "_ia_true"
#define IA_FALSE            "_ia_false"
#define IA_UNKNOWN          "_ia_unknown"
#define IA_UNION(pfix)     ("_ia_union" + pfix)

/* MPFI code definitions */
#define MPFI_INCLUDE_HEADER   "#include \"interval_mpfi.h\"\n"
#define MPFI_MATH_HEADER      ""
#define MPFI_TYPE             "mpfi_t"
#define MPFI_RET_NO_INTERVAL  "void"
#define MPFI_ASSIGN(RES, OP)  "mpfi_set(" + RES + "," + OP + ")"
#define MPFI_ASSIGN_CONST(RES, CLO, CUP) "mpfi_interv_d(" + RES + "," + CLO + "," + CUP + ")"
#define MPFI_INIT_VAR(VAR)    "mpfi_init2(" + VAR + ", MPFI_PRECISION)"

#define MPFI_SET    "mpfi_set"
#define MPFI_ADD    "mpfi_add"
#define MPFI_SUB    "mpfi_sub"
#define MPFI_MUL    "mpfi_mul"
#define MPFI_DIV    "mpfi_div"
#define MPFI_CMPL   "mpfi_cmpl"
#define MPFI_CMPLEQ "mpfi_cmpleq"
#define MPFI_CMPG   "mpfi_cmpg"
#define MPFI_CMPGEQ "mpfi_cmpgeq"
#define MPFI_CMPEQ  "mpfi_cmpeq"

#define TOOGLE_BIT_MACRO(var, b) "toogleBit(" + var + ", " + b + ")"

enum eIntervalLibraries {
    IAGEN = 0,
    MPFI_LIB,
    BOOST_LIB,
    FILIB_LIB
};

enum eTransformationMode {
    NORMAL_MODE = 0,        /* Default mode, all types are promoted to intervals */
    PROMOTE_TO_FP32_MODE,   /* Promotes fp16 to fp32 */
    PROMOTE_TO_FP64_MODE,   /* Promotes fp16/fp32 to fp64 */
    PROMOTE_TO_FP128_MODE,  /* Promotes fp16/fp32/fp64 to fp128 */
    PROMOTE_TO_DD_MODE,     /* Promotes fp16/fp32/fp64 to double-double */
};

/* Global CompilerInstance for additional AST info */
extern clang::CompilerInstance* mainCI;

eIntervalLibraries getIntervalLib ();
eTransformationMode getTransformationMode ();
void setIntervalLib (eIntervalLibraries lib);
void setTransformationMode (eTransformationMode mode);
bool isTypeSupported(const std::string& t);
bool isTypeSupported(const clang::QualType& qt);
bool isTypeIntervalInteger(const std::string& t);
bool isTypeIntervalVector(const std::string& t);
bool isTypeInteger(const std::string& t);
bool isTypeSupported(const std::string& t);
bool isTypeTransformable(const std::string& t);
std::string getTypeAsString (const clang::QualType& type, bool getQualifier = false);
std::string getBareTypeAsString (const clang::QualType& type);
bool transformToIntervalType (std::string& type);
bool promoteType (std::string& type);
bool translateMathFun(std::string& t, std::string type);
std::string getReductionFunction (const std::string& retType, const std::string& intervalType);
std::string _iaFunName(std::string op, std::string type);
std::string _iaCastFunName(std::string t_base, std::string t_dest);
void rewriteCanonicalVectorType(std::string& type);
bool isIntervalMathUsed();
void setIntervalMathUsed();
bool isReductionImprovementUsed();
void setReductionImprovementUsed();
std::string getPostfixForType(const std::string& type);
std::string getIGenHeaderFiles();

#endif //INTERVAL_ARITHMETIC_COMMONINTERVAL_H
