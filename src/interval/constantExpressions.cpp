#include <iostream>
#include <sstream>
#include <iomanip>
#include <mpfr.h>
#include "ASTVisitor.h"
#include "constantExpressions.h"
#include "commonInterval.h"

using namespace std;

///
/// This file handles expressions on constants. Each boundary of
/// an interval is represented using llvm::APFloat datatype.
/// The lower bound is only negated in the string representation.
///

#define MAX_PRECISION(T) std::numeric_limits<T>::digits10 + 2

using namespace std;
using namespace clang;
using namespace llvm;

template< typename T >
std::string int_to_hex( T i )
{
    std::stringstream stream;
    stream << "0x"
           << std::setfill ('0') << std::setw(sizeof(T)*2)
           << std::hex << i;
    return stream.str();
}

string double2string(double d) {
    string str;
    std::ostringstream ostr;
    ostr << std::setprecision(MAX_PRECISION(double));
    ostr << d;
    str = ostr.str();

    /* Add .0 at the end if needed */
    size_t pos1 = str.find('.');
    size_t pos2 = str.find('e');

    if (pos1 == string::npos && pos2 == string::npos) {
        str += ".0";
    }

    return str;
}

///
/// \param fl
/// \param type
/// \return
string APFloat2String(APFloat& apfl, const string& type, bool negated = false) {
    std::ostringstream ostr;
    string fltStr;

    if (negated) { apfl.changeSign(); }

    /* Perform case distinction depending whether float is finite or not */
    if (apfl.isFinite()) {
        if (type == DOUBLE_T) {
            ostr << std::setprecision(MAX_PRECISION(double));
            ostr << apfl.convertToDouble();
        }
        else if (type == FLOAT_T || type == HALF_T) {
            ostr << std::setprecision(MAX_PRECISION(float));
            ostr << apfl.convertToFloat();
        }
        else {
            cerr << "Error: Type not supported in APFloat2String function." << endl;
        }

        /* Add decimal point in case of integer float */
        if (apfl.isInteger()) {
            ostr << ".0";
        }

        fltStr = ostr.str();
    }
    else if (apfl.isInfinity()) {
        fltStr = (apfl.isNegative()) ? "(-1./0.)" : "(1./0.)";
    }
    else if (apfl.isNaN()) {
        fltStr = (negated) ? "(-1./0.)" : "(1./0.)";
    }


    return fltStr;
}

///
/// This function casts a constant integer/float32/float64 to a constant float32/float64 interval.
///
void castConstantExpr(const string& resType, intervalExpression& iConst) {

    assert(iConst.isConstantExpr());
    assert(isTypeSupported(resType));

    if (resType == iConst.getType()) {
        /* The types already match. Do nothing. */
        return;
    }

    /* For IAGEN the lowerbound representation is stored in negated form */
    bool isLoNegated = (getIntervalLib() == IAGEN);

    if (isTypeIntervalInteger(resType)) {
        /* Here the constant is casted to an integer interval. This is for simd2interval generation */
        if ( iConst.isScalarExpr() ) {

            /* We have to invert the sign bit for the lower bound */
            if (resType == UINT32_T) {
                uint32_t num_up = stoul(iConst.intervalVar);
                uint32_t num_lo = stoul(iConst.intervalVar);
                if (num_lo >= 0x80000000u) {
                    num_lo -= 0x80000000u;
                }
                else {
                    num_lo += 0x80000000u;
                }
                iConst.loExpr = int_to_hex(num_lo);
                iConst.upExpr = int_to_hex(num_up);
            }
            else {
                uint64_t num_up = stoul(iConst.intervalVar);
                uint64_t num_lo = stoul(iConst.intervalVar);
                if (num_lo >= 0x8000000000000000u) {
                    num_lo -= 0x8000000000000000u;
                }
                else {
                    num_lo += 0x8000000000000000u;
                }
                iConst.loExpr = int_to_hex(num_lo);
                iConst.upExpr = int_to_hex(num_up);
            }
        }
        else {
            /* How to handle interval constant. Is it possible for this case */
            cerr << "Error: feature not supported yet in castConstantExpr" << endl;
        }

        /* Update interval expresion */
        iConst.intervalVar = "";
        iConst.isScalar = false;
        iConst.typeStr  = resType;
    }
    else if (resType == DD_T) {
        /* The constant is casted to a DD type */

        if ( iConst.isScalarExpr() ) {
            /* It is an integer constant */
            string c = iConst.intervalVar;
            string zero = "0.0";
            iConst.intervalVar = _iaFunName("=", DD_T) + "(-" + c + "," + zero + "," + c + ", " + zero + ")";
        }
        else {
            /* It is an interval constant */
            string cl = iConst.getLowExpr();
            string cu = iConst.getUpExpr();
            string zero = "0.0";
            iConst.intervalVar = _iaFunName("=", DD_T) + "(" + cl + "," + zero + "," + cu + ", " + zero + ")";
        }

        iConst.loExpr   = "";
        iConst.upExpr   = "";
        iConst.isConstant = false; // treat like variable for DD type
        iConst.isScalar = false;
        iConst.typeStr  = resType;
    }
    else {
        /* This is the normal case where the constant is casted to interval float or double */
        const fltSemantics& sem = (resType == DOUBLE_T) ? APFloat::IEEEdouble() : APFloat::IEEEsingle();
        APFloat flo(sem), fup(sem);

        if ( iConst.isScalarExpr() ) {
            /* It is an integer constant */
            fup.convertFromString(iConst.intervalVar, APFloat::rmTowardPositive);
            flo.convertFromString(iConst.intervalVar, APFloat::rmTowardNegative);
        }
        else {
            /* It is an interval constant. Round both towards positive because lower bound is negated */
            fup.convertFromString(iConst.getUpExpr() , APFloat::rmTowardPositive);
            if (isLoNegated) {
                flo.convertFromString(iConst.getLowExpr(), APFloat::rmTowardPositive);
                flo.changeSign();
            }
            else {
                flo.convertFromString(iConst.getLowExpr(), APFloat::rmTowardNegative);
            }
        }

        /* Update interval expression */
        *iConst.loConst = flo;
        *iConst.upConst = fup;
        iConst.loExpr   = APFloat2String(flo, resType, isLoNegated);
        iConst.upExpr   = APFloat2String(fup, resType);
        iConst.intervalVar = "";
        iConst.isScalar = false;
        iConst.typeStr  = resType;
    }
}

///
/// Get epsilion interval of the unknown decimal. Used in language extension, e.g. double b = 1.5_
///
APFloat getUnknownDecimalEpsilon(FloatingLiteral*& fl) {

    /* Precision of a constant is determined by the number of decimal digits */
    APFloat epsilon(0.0);
    string floatStr = getRawCodeAsString(fl->getSourceRange());

    /* Count the number of digits after decimal point */
    bool start = false;
    size_t numDecimals = 0;
    for (char c : floatStr) {
        if (start)    { numDecimals++; }
        if (c == '.') { start = true; }
        if (c == 'e' || c == 'E') { return APFloat(0.0); }
    }

    /* Check if the constant doesn't have epsilon */
    if (floatStr.back() != '_') { return APFloat(0.0); }
    if (numDecimals < 1)        { return APFloat(0.0); }

    /* Determine epsilon from the number of decimals */
    size_t i = numDecimals;
    epsilon = APFloat(10.0);
    while (i--) {
        epsilon.divide(APFloat(10.0), APFloat::rmTowardPositive);
    }

    return epsilon;
}

///
/// \param s: string to convert to interval
/// \param iConst: Output interval
void getConstIntervalFromString(string s, intervalExpression& iConst) {

    /* Get exact constant with proper rounding */
    string type = iConst.getType();
    const fltSemantics& sem = (type == DOUBLE_T) ? APFloat::IEEEdouble() : APFloat::IEEEsingle();
    APFloat flo(sem), fup(sem);
    flo.convertFromString(s, flo.rmTowardNegative);
    fup.convertFromString(s, fup.rmTowardPositive);

    /* Store constant in interval expression */
    *iConst.loConst = flo;
    *iConst.upConst = fup;
    bool neg_lower = getIntervalLib() == IAGEN;
    iConst.loExpr = APFloat2String(flo, iConst.getType(), neg_lower);
    iConst.upExpr = APFloat2String(fup, iConst.getType());
}

///
/// \param fl
/// \param iConst
void getConstIntervalDD(FloatingLiteral*& fl, intervalExpression& iConst) {
    /* Get source constant as string */
    string fltStr = getRawCodeAsString(fl->getSourceRange());

    mpfr_t fup, flo;
    mpfr_init2(fup, F128_PRECISION);
    mpfr_init2(flo, F128_PRECISION);
    mpfr_set_str(fup, fltStr.c_str(), 10, MPFR_RNDU);
    mpfr_set_str(flo, fltStr.c_str(), 10, MPFR_RNDD);

    /* Check whether it is an interval constant (with suffix 't' or 'T') */
    if (fltStr.back() ==  't' || fltStr.back() == 'T') {
        /* A constant cannot be negative */
        mpfr_neg(flo, fup, MPFR_RNDD);
    }

    /* Get dd representation */
    mpfr_t t;
    mpfr_init2(t, F128_PRECISION);
    double up_h, up_l, lo_h, lo_l;

    up_h = mpfr_get_d(fup, MPFR_RNDN);
    lo_h = mpfr_get_d(flo, MPFR_RNDN);
    mpfr_sub_d(t, fup, up_h, MPFR_RNDU);
    up_l = mpfr_get_d(t, MPFR_RNDU);
    mpfr_sub_d(t, flo, lo_h, MPFR_RNDD);
    lo_l = mpfr_get_d(t, MPFR_RNDD);

    /* Create function assignment */
    string uphStr, uplStr, lohStr, lolStr;
    uphStr = double2string(up_h);
    uplStr = double2string(up_l);
    lohStr = double2string(-lo_h);
    lolStr = double2string(-lo_l);
    iConst.intervalVar = _iaFunName("=", DD_T) + "(" + lohStr + "," + lolStr + "," + uphStr + ", " + uplStr + ")";

    /* Treat dd constants as variables */
    iConst.isConstant = false;
}

///
/// \param fl
/// \param iConst
void getConstInterval(FloatingLiteral*& fl, intervalExpression& iConst) {

    /* Double-Double constants are handled differently */
    if (iConst.getType() == DD_T) {
        getConstIntervalDD(fl, iConst);
        return;
    }

    /* Determine interval of constant around the real value */
    APFloat cval = fl->getValue();
    APFloat fup = cval;
    APFloat flo = cval;
    if (!fl->isExact()) {
        flo.next(true);
        fup.next(false);
    }

    bool loosesInfo;
    switch (getTransformationMode()) {
        case PROMOTE_TO_FP32_MODE:
            flo.convert(APFloat::IEEEsingle(), fup.rmTowardNegative, &loosesInfo);
            fup.convert(APFloat::IEEEsingle(), fup.rmTowardPositive, &loosesInfo);
            break;
        case PROMOTE_TO_FP64_MODE:
            flo.convert(APFloat::IEEEdouble(), fup.rmTowardNegative, &loosesInfo);
            fup.convert(APFloat::IEEEdouble(), fup.rmTowardPositive, &loosesInfo);
            break;
        case PROMOTE_TO_FP128_MODE:
            flo.convert(APFloat::IEEEquad(), fup.rmTowardNegative, &loosesInfo);
            fup.convert(APFloat::IEEEquad(), fup.rmTowardPositive, &loosesInfo);
            break;
        default: break;
    }

    // todo: identification of interval constants should be done in the clang parser
    /* Check whether it is an interval constant (with suffix 't' or 'T') */
    string floatStr = getRawCodeAsString(fl->getSourceRange());
    if (floatStr.back() ==  't' || floatStr.back() == 'T') {
        /* A constant cannot be negative. But just in case handle the case */
        if (cval.isNegative()) {
            fup = neg(flo);
        }
        else {
            flo = neg(fup);
        }
    }

    /* Check whether the constant has an unknown decimal (with suffix '_') */
    if (floatStr.back() == '_') {
        APFloat epsilon = getUnknownDecimalEpsilon(fl);
        fup.add(epsilon, APFloatBase::rmTowardPositive);
    }

    /* Update interval expression */
    *iConst.loConst = flo;
    *iConst.upConst = fup;
    bool neg_lower = getIntervalLib() == IAGEN;
    iConst.loExpr = APFloat2String(flo, iConst.getType(), neg_lower);
    iConst.upExpr = APFloat2String(fup, iConst.getType());

}

///
/// \param iRhs
/// \param iLhs
/// \param iConst
void negateConstantInterval(intervalExpression& iArg, intervalExpression& iConst) {
    iConst = iArg;
    *iConst.loConst = neg((*iArg.upConst));
    *iConst.upConst = neg((*iArg.loConst));
    bool neg_lower = getIntervalLib() == IAGEN;
    iConst.loExpr = APFloat2String(*iConst.loConst, iConst.getType(), neg_lower);
    iConst.upExpr = APFloat2String(*iConst.upConst, iConst.getType());
}

///
/// \param iRhs
/// \param iLhs
/// \param iConst
void addConstantInterval(intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iConst) {
    iConst = iLhs;
    iConst.loConst->add((*iRhs.loConst), APFloat::rmTowardNegative);
    iConst.upConst->add((*iRhs.upConst), APFloat::rmTowardPositive);
    bool neg_lower = getIntervalLib() == IAGEN;
    iConst.loExpr = APFloat2String(*iConst.loConst, iConst.getType(), neg_lower);
    iConst.upExpr = APFloat2String(*iConst.upConst, iConst.getType());
}

///
/// \param iRhs
/// \param iLhs
/// \param iConst
void subConstantInterval(intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iConst) {
    iConst = iLhs;
    iConst.loConst->subtract((*iRhs.upConst), APFloat::rmTowardNegative);
    iConst.upConst->subtract((*iRhs.loConst), APFloat::rmTowardPositive);
    bool neg_lower = getIntervalLib() == IAGEN;
    iConst.loExpr = APFloat2String(*iConst.loConst, iConst.getType(), neg_lower);
    iConst.upExpr = APFloat2String(*iConst.upConst, iConst.getType());
}

///
/// \param iLhs
/// \param iRhs
/// \param iConst
void mulConstantInterval(intervalExpression &iLhs, intervalExpression &iRhs, intervalExpression &iConst) {

    /* Copy attributes from LHS */
    iConst = iLhs;
    APFloat min(0.0), max(0.0);
    APFloat lo1 = *iLhs.loConst;    APFloat up1 = *iLhs.loConst;
    APFloat lo2 = *iLhs.loConst;    APFloat up2 = *iLhs.loConst;
    APFloat lo3 = *iLhs.upConst;    APFloat up3 = *iLhs.upConst;
    APFloat lo4 = *iLhs.upConst;    APFloat up4 = *iLhs.upConst;

    /* Calculate lower bound */
    lo1.multiply(*iRhs.loConst, APFloat::rmTowardNegative);
    lo2.multiply(*iRhs.upConst, APFloat::rmTowardNegative);
    lo3.multiply(*iRhs.loConst, APFloat::rmTowardNegative);
    lo4.multiply(*iRhs.upConst, APFloat::rmTowardNegative);
    min = minimum(lo1, lo2);
    min = minimum(min, lo3);
    min = minimum(min, lo4);
    *iConst.loConst = min;

    /* Calculate upper bound */
    up1.multiply(*iRhs.loConst, APFloat::rmTowardPositive);
    up2.multiply(*iRhs.upConst, APFloat::rmTowardPositive);
    up3.multiply(*iRhs.loConst, APFloat::rmTowardPositive);
    up4.multiply(*iRhs.upConst, APFloat::rmTowardPositive);
    max = maximum(up1, up2);
    max = maximum(max, up3);
    max = maximum(max, up4);
    *iConst.upConst = max;

    /* Convert to string interval */
    bool neg_lower = getIntervalLib() == IAGEN;
    iConst.loExpr = APFloat2String(*iConst.loConst, iConst.getType(), neg_lower);
    iConst.upExpr = APFloat2String(*iConst.upConst, iConst.getType());
}

///
/// \param iRhs
/// \param iLhs
/// \param iConst
void divConstantInterval(intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iConst) {

    iConst = iLhs;
    APFloat invRhsLo(1.0), invRhsUp(1.0);
    APFloat inf = APFloat(1.0/0.0);

    if (iRhs.getType() == FLOAT_T) {
        APFloat onef((float) 1.0);
        invRhsLo = onef;
        invRhsUp = onef;
    }

    if (iRhs.loConst->isZero() && iRhs.upConst->isNonZero()) {
        invRhsLo.divide(*iRhs.upConst, APFloat::rmTowardNegative);
        invRhsUp = inf;
    }
    else if ( iRhs.loConst->isNonZero() && iRhs.upConst->isZero() ) {
        invRhsLo = inf;
        invRhsLo.changeSign();
        invRhsUp.divide(*iRhs.loConst, APFloat::rmTowardPositive);
    }
    else if ( ( iRhs.loConst->isNegative() &&  iRhs.upConst->isNegative()) ||
              (!iRhs.loConst->isNegative() && !iRhs.upConst->isNegative()) ) {
        /* Both bounds have the same sign */
        invRhsLo.divide(*iRhs.upConst, APFloat::rmTowardNegative);
        invRhsUp.divide(*iRhs.loConst, APFloat::rmTowardPositive);
    }
    else {
        invRhsLo = inf;
        invRhsUp = inf;
        invRhsLo.changeSign();
    }
    *iRhs.loConst = invRhsLo;
    *iRhs.upConst = invRhsUp;

    mulConstantInterval(iLhs, iRhs, iConst);
}

void cmpConstantInterval(intervalExpression& iLhs, intervalExpression& iRhs, intervalExpression& iConst, string& op) {

    /* First transform the inputs into interval constants in case one is an int */
    string type = DOUBLE_T;
    castConstantExpr(type, iLhs);
    castConstantExpr(type, iRhs);

    /* Compare all the bounds of the interval constants */
    APFloatBase::cmpResult cmpUU = iLhs.upConst->compare(*iRhs.upConst);
    APFloatBase::cmpResult cmpUL = iLhs.upConst->compare(*iRhs.loConst);
    APFloatBase::cmpResult cmpLU = iLhs.loConst->compare(*iRhs.upConst);
    APFloatBase::cmpResult cmpLL = iLhs.loConst->compare(*iRhs.loConst);

    if (op == "<") {
        if (cmpUL == APFloatBase::cmpLessThan) {
            iConst.intervalVar = TRUE_NATIVE;
        }
        else {
            iConst.intervalVar = FALSE_NATIVE;
            if (cmpLL == APFloatBase::cmpLessThan) {
                /* The result of the comparison is in unknown state. Warn the user */
                std::cerr << "Result of a comparison yields unknown state" << endl;
            }
        }
    }

    if (op == "<=") {
        if (cmpUL == APFloatBase::cmpLessThan || cmpUL == APFloatBase::cmpEqual) {
            iConst.intervalVar = TRUE_NATIVE;
        }
        else {
            iConst.intervalVar = FALSE_NATIVE;
            if (cmpLL == APFloatBase::cmpLessThan || cmpLL == APFloatBase::cmpEqual) {
                /* The result of the comparison is in $unknown state. Warn the user */
                std::cerr << "Result of a comparison yields unknown state" << endl;
            }
        }
    }

    if (op == ">") {
        if (cmpLU == APFloatBase::cmpGreaterThan) {
            iConst.intervalVar = TRUE_NATIVE;
        }
        else {
            iConst.intervalVar = FALSE_NATIVE;
            if (cmpLL == APFloatBase::cmpGreaterThan) {
                /* The result of the comparison is in $unknown state. Warn the user */
                std::cerr << "Result of a comparison yields unknown state" << endl;
            }
        }
    }

    if (op == ">=") {
        if (cmpLU == APFloatBase::cmpGreaterThan || cmpLU == APFloatBase::cmpEqual) {
            iConst.intervalVar = TRUE_NATIVE;
        }
        else {
            iConst.intervalVar = FALSE_NATIVE;
            if (cmpLL == APFloatBase::cmpGreaterThan || cmpLL == APFloatBase::cmpEqual) {
                /* The result of the comparison is in $unknown state. Warn the user */
                std::cerr << "Result of a comparison yields unknown state" << endl;
            }
        }
    }

    if (op == "==") {
        if (cmpLL == APFloatBase::cmpEqual && cmpUU == APFloatBase::cmpEqual && cmpLU == APFloatBase::cmpEqual) {
            iConst.intervalVar = TRUE_NATIVE;
        }
        else {
            iConst.intervalVar = FALSE_NATIVE;
            bool isStrictlyNotEqual = (cmpUL == APFloatBase::cmpLessThan) || (cmpLU == APFloatBase::cmpGreaterThan);
            if (!isStrictlyNotEqual) {
                /* The result of the comparison is in $unknown state. Warn the user */
                std::cerr << "Result of a comparison yields unknown state" << endl;
            }
        }
    }

    iConst.loExpr = "";
    iConst.upExpr = "";
    iConst.typeStr    = INT_T;
    iConst.isConstant = true;
    iConst.isScalar   = true;
    iConst.isBoolean  = BooleanLogic;
}