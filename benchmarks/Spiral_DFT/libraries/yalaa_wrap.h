#pragma  once
#include <yalaa.hpp>


class yalaa_af0 {
public:
    yalaa::aff_e_d v;

    yalaa_af0() : v(0.0) {}
    yalaa_af0(double val) : v(val) {}

    yalaa_af0& operator=(yalaa_af0 x) {
        v = x.v;
        return *this;
    }

    yalaa_af0 operator+(yalaa_af0 x) {
        yalaa_af0 res;
        res.v = v + x.v;
        return res;
    }

    yalaa_af0 operator-(yalaa_af0 x) {
        yalaa_af0 res;
        res.v = v - x.v;
        return res;
    }

    yalaa_af0 operator*(yalaa_af0 x) {
        yalaa_af0 res;
        res.v = v * x.v;
        return res;
    }

    yalaa_af0 operator/(yalaa_af0 x) {
        yalaa_af0 res;
        res.v = v / x.v;
        return res;
    }
};

static yalaa_af0 operator* (double x1, yalaa_af0 x2) {
    return yalaa_af0(x1) * x2;
}