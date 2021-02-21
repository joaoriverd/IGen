#include "igen_immintrin_fallback.h"
#include "igen_immintrin_internal.h"

f32i_simd4 _igen_fb_mm_cvtsi32_ss(f32i_simd4 _a, int b) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = Convert_Int32_To_FP32_i(b);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cvtsi64_ss(f32i_simd4 _a, long b) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = (Convert_Int64_To_FP32_l(b));
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cvtpi32_ps(f32i_simd4 _a, __m64 _b) {
    vec128s a;
    a.v = _a;
    vec64i b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = Convert_Int32_To_FP32_i(b.i[0]);
    dst.f[1] = Convert_Int32_To_FP32_i(b.i[1]);
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cvtpi16_ps(__m64 _a) {
    vec64i a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 16;
        m = j * 32;
        dst.f[m / 32] = Convert_Int16_To_FP32_i(vecBitsAccess_i(a.i, i + 15, i));
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cvtpu16_ps(__m64 _a) {
    vec64i a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 16;
        m = j * 32;
        dst.f[m / 32] =
                Convert_UnsignedInt16_To_FP32_i(vecBitsAccess_i(a.i, i + 15, i));
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cvtpi8_ps(__m64 _a) {
    vec64i a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 8;
        m = j * 32;
        dst.f[m / 32] = Convert_Int8_To_FP32_i(vecBitsAccess_i(a.i, i + 7, i));
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cvtpu8_ps(__m64 _a) {
    vec64i a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 8;
        m = j * 32;
        dst.f[m / 32] =
                Convert_UnsignedInt8_To_FP32_i(vecBitsAccess_i(a.i, i + 7, i));
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cvtpi32x2_ps(__m64 _a, __m64 _b) {
    vec64i a;
    a.v = _a;
    vec64i b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = Convert_Int32_To_FP32_i(a.i[0]);
    dst.f[1] = Convert_Int32_To_FP32_i(a.i[1]);
    dst.f[2] = Convert_Int32_To_FP32_i(b.i[0]);
    dst.f[3] = Convert_Int32_To_FP32_i(b.i[1]);
    return dst.v;
}

f32i_simd4 _igen_fb_mm_add_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0].lo = a.f[0].lo + b.f[0].lo;
    dst.f[0].up = a.f[0].up + b.f[0].up;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_add_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32].lo = a.f[i / 32].lo + b.f[i / 32].lo;
        dst.f[i / 32].up = a.f[i / 32].up + b.f[i / 32].up;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_sub_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0].lo = a.f[0].lo + b.f[0].up;
    dst.f[0].up = a.f[0].up + b.f[0].lo;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_sub_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32].lo = a.f[i / 32].lo + b.f[i / 32].up;
        dst.f[i / 32].up = a.f[i / 32].up + b.f[i / 32].lo;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_mul_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = _ia_mul_f32(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_mul_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_div_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = _ia_div_f32(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_div_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        dst.f[i / 32] = _ia_div_f32(a.f[i / 32], b.f[i / 32]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_sqrt_ss(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = SQRT_s(a.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_sqrt_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = SQRT_s(a.f[i / 32]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_rcp_ss(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    f32_I _t1;
    _t1.lo = -1.0;
    _t1.up = 1.0;
    f32_I _t2;
    _t2.lo = a.f[0].lo;
    _t2.up = a.f[0].up;
    f32_I _t3 = _ia_div_f32(_t1, _t2);
    dst.f[0].lo = _t3.lo;
    dst.f[0].up = _t3.up;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_rcp_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t4;
        _t4.lo = -1.0f;
        _t4.up = 1.0f;
        f32_I _t5;
        _t5.lo = a.f[i / 32].lo;
        _t5.up = a.f[i / 32].up;
        f32_I _t6 = _ia_div_f32(_t4, _t5);
        dst.f[i / 32].lo = _t6.lo;
        dst.f[i / 32].up = _t6.up;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_rsqrt_ss(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    f32_I _t7 = SQRT_s(a.f[0]);
    f32_I _t8;
    _t8.lo = -1.0;
    _t8.up = 1.0;
    f32_I _t9;
    _t9.lo = _t7.lo;
    _t9.up = _t7.up;
    f32_I _t10 = _ia_div_f32(_t8, _t9);
    dst.f[0].lo = _t10.lo;
    dst.f[0].up = _t10.up;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_rsqrt_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t11 = SQRT_s(a.f[i / 32]);
        f32_I _t12;
        _t12.lo = -1.0;
        _t12.up = 1.0;
        f32_I _t13;
        _t13.lo = _t11.lo;
        _t13.up = _t11.up;
        f32_I _t14 = _ia_div_f32(_t12, _t13);
        dst.f[i / 32].lo = _t14.lo;
        dst.f[i / 32].up = _t14.up;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_min_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = MIN_ss(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_min_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = MIN_ss(a.f[i / 32], b.f[i / 32]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_max_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = MAX_ss(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_max_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = MAX_ss(a.f[i / 32], b.f[i / 32]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_and_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.i[i / 32] = _ia_and_u32(a.i[i / 32], b.i[i / 32]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_andnot_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        u32_I _t15;
        _t15.lo = (~a.i[i / 32].lo);
        _t15.up = (~a.i[i / 32].up);
        dst.i[i / 32] = _ia_and_u32(_t15, b.i[i / 32]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_or_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.i[i / 32] = _ia_or_u32(a.i[i / 32], b.i[i / 32]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_xor_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.i[i / 32].lo = a.i[i / 32].lo ^ b.i[i / 32].lo;
        dst.i[i / 32].up = a.i[i / 32].up ^ b.i[i / 32].up;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpeq_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = (_ia_cmpeq_f32(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t16, 31);
    dst.i[0].up = _t16;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpeq_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = (_ia_cmpeq_f32(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t17, 31);
        dst.i[i / 32].up = _t17;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmplt_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t18 = (_ia_cmplt_f32(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t18, 31);
    dst.i[0].up = _t18;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmplt_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t19 = (_ia_cmplt_f32(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t19, 31);
        dst.i[i / 32].up = _t19;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmple_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t20 = (_ia_cmple_f32(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t20, 31);
    dst.i[0].up = _t20;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmple_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t21 = (_ia_cmple_f32(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t21, 31);
        dst.i[i / 32].up = _t21;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpgt_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t22 = (_ia_cmpgt_f32(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t22, 31);
    dst.i[0].up = _t22;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpgt_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t23 = (_ia_cmpgt_f32(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t23, 31);
        dst.i[i / 32].up = _t23;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpge_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t24 = (_ia_cmpge_f32(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t24, 31);
    dst.i[0].up = _t24;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpge_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t25 = (_ia_cmpge_f32(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t25, 31);
        dst.i[i / 32].up = _t25;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpneq_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t26 = (_ia_cmpneq_f32(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t26, 31);
    dst.i[0].up = _t26;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpneq_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t27 = (_ia_cmpneq_f32(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t27, 31);
        dst.i[i / 32].up = _t27;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpnlt_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t28 = (!(_ia_cmplt_f32(a.f[0], b.f[0]))) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t28, 31);
    dst.i[0].up = _t28;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpnlt_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t29 = !(_ia_cmplt_f32(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t29, 31);
        dst.i[i / 32].up = _t29;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpnle_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t30 = (!(_ia_cmple_f32(a.f[0], b.f[0]))) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t30, 31);
    dst.i[0].up = _t30;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpnle_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t31 = (!(_ia_cmple_f32(a.f[i / 32], b.f[i / 32]))) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t31, 31);
        dst.i[i / 32].up = _t31;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpngt_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t32 = (!(_ia_cmpgt_f32(a.f[0], b.f[0]))) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t32, 31);
    dst.i[0].up = _t32;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpngt_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t33 = (!(_ia_cmpgt_f32(a.f[i / 32], b.f[i / 32]))) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t33, 31);
        dst.i[i / 32].up = _t33;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpnge_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t34 = (!(_ia_cmpge_f32(a.f[0], b.f[0]))) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t34, 31);
    dst.i[0].up = _t34;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpnge_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t35 = (!(_ia_cmpge_f32(a.f[i / 32], b.f[i / 32]))) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t35, 31);
        dst.i[i / 32].up = _t35;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpord_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t36 =
            (!_igen_isnan_s(a.f[0]) & !_igen_isnan_s(b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t36, 31);
    dst.i[0].up = _t36;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpord_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t37 =
                (!_igen_isnan_s(a.f[i / 32]) & !_igen_isnan_s(b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t37, 31);
        dst.i[i / 32].up = _t37;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpunord_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t38 = (_igen_isnan_s(a.f[0]) | _igen_isnan_s(b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t38, 31);
    dst.i[0].up = _t38;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmpunord_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t39 =
                (_igen_isnan_s(a.f[i / 32]) | _igen_isnan_s(b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t39, 31);
        dst.i[i / 32].up = _t39;
    }
    return dst.v;
}

int _igen_fb_mm_comieq_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpeq_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comilt_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmplt_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comile_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmple_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comigt_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgt_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comige_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpge_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comineq_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpneq_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomieq_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpeq_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomilt_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmplt_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomile_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmple_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomigt_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgt_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomige_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpge_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomineq_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpneq_f32(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_cvtss_si32(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    int dst;

    dst = Convert_FP32_To_Int32_s(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_cvt_ss2si(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    int dst;

    dst = Convert_FP32_To_Int32_s(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

long _igen_fb_mm_cvtss_si64(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    long dst;

    dst = Convert_FP32_To_Int64_s(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

f32_I _igen_fb_mm_cvtss_f32(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    f32_I dst;

    dst = a.f[0];
    return dst;
}

__m64 _igen_fb_mm_cvtps_pi32(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec64i dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = 32 * j;
        dst.i[i / 32] = Convert_FP32_To_Int32_s(a.f[i / 32]);
    }
    __m64 _ret;
    _ret = dst.v;
    return _ret;
}

__m64 _igen_fb_mm_cvt_ps2pi(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec64i dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = 32 * j;
        dst.i[i / 32] = Convert_FP32_To_Int32_s(a.f[i / 32]);
    }
    __m64 _ret;
    _ret = dst.v;
    return _ret;
}

int _igen_fb_mm_cvttss_si32(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    int dst;

    dst = Convert_FP32_To_Int32_Truncate_s(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_cvtt_ss2si(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    int dst;

    dst = Convert_FP32_To_Int32_Truncate_s(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

long _igen_fb_mm_cvttss_si64(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int32_Truncate_s(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

__m64 _igen_fb_mm_cvttps_pi32(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec64i dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = 32 * j;
        dst.i[i / 32] = Convert_FP32_To_Int32_Truncate_s(a.f[i / 32]);
    }
    __m64 _ret;
    _ret = dst.v;
    return _ret;
}

__m64 _igen_fb_mm_cvtt_ps2pi(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec64i dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = 32 * j;
        dst.i[i / 32] = Convert_FP32_To_Int32_Truncate_s(a.f[i / 32]);
    }
    __m64 _ret;
    _ret = dst.v;
    return _ret;
}

__m64 _igen_fb_mm_cvtps_pi16(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec64i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 16 * j;
        k = 32 * j;
        vecBitsAssign_i(dst.i, i + 15, i, Convert_FP32_To_Int16_s(a.f[k / 32]));
    }
    __m64 _ret;
    _ret = dst.v;
    return _ret;
}

__m64 _igen_fb_mm_cvtps_pi8(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec64i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 8 * j;
        k = 32 * j;
        vecBitsAssign_i(dst.i, i + 7, i, Convert_FP32_To_Int8_s(a.f[k / 32]));
    }
    __m64 _ret;
    _ret = dst.v;
    return _ret;
}

f32i_simd4 _igen_fb_mm_set_ss(f32_I a) {
    vec128s dst;

    dst.f[0] = a;
    dst.f[1] = _ia_set_f32(0.0, 0.0);
    dst.f[2] = _ia_set_f32(0.0, 0.0);
    dst.f[3] = _ia_set_f32(0.0, 0.0);

    return dst.v;
}

f32i_simd4 _igen_fb_mm_set1_ps(f32_I a) {
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = a;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_set_ps1(f32_I a) {
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = a;
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_set_ps(f32_I e3, f32_I e2, f32_I e1, f32_I e0) {
    vec128s dst;

    dst.f[0] = e0;
    dst.f[1] = e1;
    dst.f[2] = e2;
    dst.f[3] = e3;
    return dst.v;
}

f32i_simd4 _igen_fb_mm_setr_ps(f32_I e3, f32_I e2, f32_I e1, f32_I e0) {
    vec128s dst;

    dst.f[0] = e3;
    dst.f[1] = e2;
    dst.f[2] = e1;
    dst.f[3] = e0;
    return dst.v;
}

f32i_simd4 _igen_fb_mm_setzero_ps() {
    vec128s dst;

    dst.f[0] = _ia_set_f32(0.0, 0.0);
    dst.f[1] = _ia_set_f32(0.0, 0.0);
    dst.f[2] = _ia_set_f32(0.0, 0.0);
    dst.f[3] = _ia_set_f32(0.0, 0.0);

    return dst.v;
}

f32i_simd4 _igen_fb_mm_load_ss(const f32_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = _ia_set_f32(0.0, 0.0);
    dst.f[2] = _ia_set_f32(0.0, 0.0);
    dst.f[3] = _ia_set_f32(0.0, 0.0);

    return dst.v;
}

f32i_simd4 _igen_fb_mm_load1_ps(const f32_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    dst.f[2] = *(mem_addr + 0);
    dst.f[3] = *(mem_addr + 0);
    return dst.v;
}

f32i_simd4 _igen_fb_mm_load_ps1(const f32_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    dst.f[2] = *(mem_addr + 0);
    dst.f[3] = *(mem_addr + 0);
    return dst.v;
}

f32i_simd4 _igen_fb_mm_load_ps(const f32_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);

    return dst.v;
}

f32i_simd4 _igen_fb_mm_loadu_ps(const f32_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);

    return dst.v;
}

f32i_simd4 _igen_fb_mm_loadr_ps(const f32_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 3);
    dst.f[1] = *(mem_addr + 2);
    dst.f[2] = *(mem_addr + 1);
    dst.f[3] = *(mem_addr + 0);
    return dst.v;
}

void _igen_fb_mm_stream_ps(f32_I *mem_addr, f32i_simd4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];

}

void _igen_fb_mm_store_ss(f32_I *mem_addr, f32i_simd4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];

}

void _igen_fb_mm_store1_ps(f32_I *mem_addr, f32i_simd4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[0];
    *(mem_addr + 2) = a.f[0];
    *(mem_addr + 3) = a.f[0];

}

void _igen_fb_mm_store_ps1(f32_I *mem_addr, f32i_simd4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[0];
    *(mem_addr + 2) = a.f[0];
    *(mem_addr + 3) = a.f[0];

}

void _igen_fb_mm_store_ps(f32_I *mem_addr, f32i_simd4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];

}

void _igen_fb_mm_storeu_ps(f32_I *mem_addr, f32i_simd4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];

}

void _igen_fb_mm_storer_ps(f32_I *mem_addr, f32i_simd4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[3];
    *(mem_addr + 1) = a.f[2];
    *(mem_addr + 2) = a.f[1];
    *(mem_addr + 3) = a.f[0];

}

f32i_simd4 _igen_fb_mm_move_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = b.f[0];
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];
    return dst.v;
}

f32i_simd4 _igen_fb_mm_shuffle_ps(f32i_simd4 _a, f32i_simd4 _b, unsigned int imm8) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = SELECT4_si(&a.f[0], (((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1)));
    dst.f[1] = SELECT4_si(&a.f[0], (((imm8) >> (2)) & ((1 << (3 - 2 + 1)) - 1)));
    dst.f[2] = SELECT4_si(&b.f[0], (((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1)));
    dst.f[3] = SELECT4_si(&b.f[0], (((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1)));
    return dst.v;
}

f32i_simd4 _igen_fb_mm_unpackhi_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    INTERLEAVE_HIGH_DWORDS_ss(&dst.f[0], &a.f[0], &b.f[0]);
    return dst.v;
}

f32i_simd4 _igen_fb_mm_unpacklo_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    INTERLEAVE_DWORDS_ss(&dst.f[0], &a.f[0], &b.f[0]);
    return dst.v;
}

f32i_simd4 _igen_fb_mm_movehl_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = b.f[2];
    dst.f[1] = b.f[3];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];
    return dst.v;
}

f32i_simd4 _igen_fb_mm_movelh_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[1];
    dst.f[2] = b.f[0];
    dst.f[3] = b.f[1];
    return dst.v;
}

int _igen_fb_mm_movemask_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    int dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (vecBitAccess_s(a.i, i + 31)) {
            dst = ((dst & ~(1 << (j))) | ((1) << (j)));
        } else {
            dst = ((dst & ~(1 << (j))) | ((0) << (j)));
        }
    }
    (dst) = ((dst) & (~(((1 << ((31) - (4) + 1)) - 1) << ((4))))) | ((0) << (4));
    int _ret;
    _ret = dst;
    return _ret;
}

f64i_simd2 _igen_fb_mm_cvtepi32_pd(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 1; ++j) {
        i = j * 32;
        m = j * 64;
        dst.f[m / 64] = Convert_Int32_To_FP64_i(a.i[i / 32]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cvtsi32_sd(f64i_simd2 _a, int b) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = Convert_Int32_To_FP64_i(b);
    dst.f[1] = a.f[1];

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cvtsi64_sd(f64i_simd2 _a, long b) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = Convert_Int64_To_FP64_l(b);
    dst.f[1] = a.f[1];

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cvtsi64x_sd(f64i_simd2 _a, long b) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = Convert_Int64_To_FP64_l(b);
    dst.f[1] = a.f[1];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cvtepi32_ps(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        dst.f[i / 32] = Convert_Int32_To_FP32_i(a.i[i / 32]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cvtpi32_pd(__m64 _a) {
    vec64i a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 1; ++j) {
        i = j * 32;
        m = j * 64;
        dst.f[m / 64] = Convert_Int32_To_FP64_i(a.i[i / 32]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_add_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_add_f64(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_add_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_add_f64(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_div_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_div_f64(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_div_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = 64 * j;
        dst.f[i / 64] = _ia_div_f64(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_max_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = MAX_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_max_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = MAX_dd(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_min_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = MIN_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_min_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = MIN_dd(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_mul_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_mul_f64(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_mul_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_sqrt_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = SQRT_d(b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_sqrt_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = SQRT_d(a.f[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_sub_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_sub_f64(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_sub_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_sub_f64(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_and_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.i[i / 64] = _ia_and_u64(a.i[i / 64], b.i[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_andnot_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        u64_I _t40;
        _t40.lo = (~a.i[i / 64].lo);
        _t40.up = (~a.i[i / 64].up);
        dst.i[i / 64] = _ia_and_u64(_t40, b.i[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_or_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.i[i / 64] = _ia_or_u64(a.i[i / 64], b.i[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_xor_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.i[i / 64].lo = a.i[i / 64].lo ^ b.i[i / 64].lo;
        dst.i[i / 64].up = a.i[i / 64].up ^ b.i[i / 64].up;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpeq_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = (_ia_cmpeq_f64(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t41, 63);
    dst.i[0].up = _t41;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmplt_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t42 = (_ia_cmplt_f64(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t42, 63);
    dst.i[0].up = _t42;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmple_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t43 = (_ia_cmple_f64(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t43, 63);
    dst.i[0].up = _t43;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpgt_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t44 = (_ia_cmpgt_f64(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t44, 63);
    dst.i[0].up = _t44;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpge_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t45 = (_ia_cmpge_f64(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t45, 63);
    dst.i[0].up = _t45;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpord_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t46 =
            (!_igen_isnan_d(a.f[0]) & !_igen_isnan_d(b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t46, 63);
    dst.i[0].up = _t46;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpunord_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t47 = (_igen_isnan_d(a.f[0]) | _igen_isnan_d(b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t47, 63);
    dst.i[0].up = _t47;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpneq_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t48 = (_ia_cmpneq_f64(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t48, 63);
    dst.i[0].up = _t48;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpnlt_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t49 = (!(_ia_cmplt_f64(a.f[0], b.f[0]))) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t49, 63);
    dst.i[0].up = _t49;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpnle_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t50 = (!(_ia_cmple_f64(a.f[0], b.f[0]))) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t50, 63);
    dst.i[0].up = _t50;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpngt_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t51 = (!(_ia_cmpgt_f64(a.f[0], b.f[0]))) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t51, 63);
    dst.i[0].up = _t51;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpnge_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t52 = (!(_ia_cmpge_f64(a.f[0], b.f[0]))) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t52, 63);
    dst.i[0].up = _t52;
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpeq_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = (_ia_cmpeq_f64(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t53, 63);
        dst.i[i / 64].up = _t53;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmplt_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t54 = (_ia_cmplt_f64(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t54, 63);
        dst.i[i / 64].up = _t54;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmple_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t55 = (_ia_cmple_f64(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t55, 63);
        dst.i[i / 64].up = _t55;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpgt_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t56 = (_ia_cmpgt_f64(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t56, 63);
        dst.i[i / 64].up = _t56;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpge_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t57 = (_ia_cmpge_f64(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t57, 63);
        dst.i[i / 64].up = _t57;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpord_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t58 =
                (!_igen_isnan_d(a.f[i / 64]) & !_igen_isnan_d(b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t58, 63);
        dst.i[i / 64].up = _t58;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpunord_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t59 =
                (_igen_isnan_d(a.f[i / 64]) | _igen_isnan_d(b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t59, 63);
        dst.i[i / 64].up = _t59;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpneq_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t60 = (_ia_cmpneq_f64(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t60, 63);
        dst.i[i / 64].up = _t60;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpnlt_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t61 = (!(_ia_cmplt_f64(a.f[i / 64], b.f[i / 64]))) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t61, 63);
        dst.i[i / 64].up = _t61;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpnle_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t62 = (!(_ia_cmple_f64(a.f[i / 64], b.f[i / 64]))) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t62, 63);
        dst.i[i / 64].up = _t62;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpngt_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t63 = (!(_ia_cmpgt_f64(a.f[i / 64], b.f[i / 64]))) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t63, 63);
        dst.i[i / 64].up = _t63;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmpnge_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t64 = (!(_ia_cmpge_f64(a.f[i / 64], b.f[i / 64]))) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t64, 63);
        dst.i[i / 64].up = _t64;
    }
    return dst.v;
}

int _igen_fb_mm_comieq_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpeq_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comilt_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmplt_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comile_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmple_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comigt_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgt_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comige_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpge_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_comineq_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpneq_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomieq_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpeq_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomilt_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmplt_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomile_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmple_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomigt_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgt_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomige_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpge_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_ucomineq_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpneq_f64(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

f32i_simd4 _igen_fb_mm_cvtpd_ps(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 1; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.f[i / 32] = Convert_FP64_To_FP32_d(a.f[k / 64]);
    }
    dst.f[2] = _ia_set_f32(0.0, 0.0);
    dst.f[3] = _ia_set_f32(0.0, 0.0);

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cvtps_pd(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 1; ++j) {
        i = 64 * j;
        k = 32 * j;
        dst.f[i / 64] = Convert_FP32_To_FP64_s(a.f[k / 32]);
    }
    return dst.v;
}

__m128i _igen_fb_mm_cvtpd_epi32(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 1; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.i[i / 32] = Convert_FP64_To_Int32_d(a.f[k / 64]);
    }
    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

int _igen_fb_mm_cvtsd_si32(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    int dst;

    dst = Convert_FP64_To_Int32_d(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

long _igen_fb_mm_cvtsd_si64(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int64_d(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

long _igen_fb_mm_cvtsd_si64x(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int64_d(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

f32i_simd4 _igen_fb_mm_cvtsd_ss(f32i_simd4 _a, f64i_simd2 _b) {
    vec128s a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = Convert_FP64_To_FP32_d(b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f64_I _igen_fb_mm_cvtsd_f64(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    f64_I dst;

    dst = a.f[0];
    return dst;
}

f64i_simd2 _igen_fb_mm_cvtss_sd(f64i_simd2 _a, f32i_simd4 _b) {
    vec128d a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = Convert_FP32_To_FP64_s(b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[1] = _ia_zero_f64();
    return dst.v;
}

__m128i _igen_fb_mm_cvttpd_epi32(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 1; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.i[i / 32] = Convert_FP64_To_Int32_Truncate_d(a.f[k / 64]);
    }
    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

int _igen_fb_mm_cvttsd_si32(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    int dst;

    dst = Convert_FP64_To_Int32_Truncate_d(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

long _igen_fb_mm_cvttsd_si64(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int64_Truncate_d(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

long _igen_fb_mm_cvttsd_si64x(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int64_Truncate_d(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

__m128i _igen_fb_mm_cvtps_epi32(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        dst.i[i / 32] = Convert_FP32_To_Int32_s(a.f[i / 32]);
    }
    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

__m128i _igen_fb_mm_cvttps_epi32(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        dst.i[i / 32] = Convert_FP32_To_Int32_Truncate_s(a.f[i / 32]);
    }
    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

__m64 _igen_fb_mm_cvtpd_pi32(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec64i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 1; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.i[i / 32] = Convert_FP64_To_Int32_d(a.f[k / 64]);
    }
    __m64 _ret;
    _ret = dst.v;
    return _ret;
}

__m64 _igen_fb_mm_cvttpd_pi32(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec64i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 1; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.i[i / 32] = Convert_FP64_To_Int32_Truncate_d(a.f[k / 64]);
    }
    __m64 _ret;
    _ret = dst.v;
    return _ret;
}

f64i_simd2 _igen_fb_mm_set_sd(f64_I a) {
    vec128d dst;

    dst.f[0] = a;
    dst.f[1] = _ia_zero_f64();
    return dst.v;
}

f64i_simd2 _igen_fb_mm_set1_pd(f64_I a) {
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = a;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_set_pd1(f64_I a) {
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = a;
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_set_pd(f64_I e1, f64_I e0) {
    vec128d dst;

    dst.f[0] = e0;
    dst.f[1] = e1;
    return dst.v;
}

f64i_simd2 _igen_fb_mm_setr_pd(f64_I e1, f64_I e0) {
    vec128d dst;

    dst.f[0] = e1;
    dst.f[1] = e0;
    return dst.v;
}

f64i_simd2 _igen_fb_mm_setzero_pd() {
    vec128d dst;

    dst.f[0] = _ia_zero_f64();
    dst.f[1] = _ia_zero_f64();

    return dst.v;
}

f64i_simd2 _igen_fb_mm_load_pd(const f64_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);

    return dst.v;
}

f64i_simd2 _igen_fb_mm_load1_pd(const f64_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

f64i_simd2 _igen_fb_mm_load_pd1(const f64_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

f64i_simd2 _igen_fb_mm_loadr_pd(const f64_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 1);
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

f64i_simd2 _igen_fb_mm_loadu_pd(const f64_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);

    return dst.v;
}

f64i_simd2 _igen_fb_mm_load_sd(const f64_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = _ia_zero_f64();
    return dst.v;
}

f64i_simd2 _igen_fb_mm_loadh_pd(f64i_simd2 _a, const f64_I *mem_addr) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = a.f[0];
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

f64i_simd2 _igen_fb_mm_loadl_pd(f64i_simd2 _a, const f64_I *mem_addr) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = a.f[1];
    return dst.v;
}

void _igen_fb_mm_stream_pd(f64_I *mem_addr, f64i_simd2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];

}

void _igen_fb_mm_store_sd(f64_I *mem_addr, f64i_simd2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];

}

void _igen_fb_mm_store1_pd(f64_I *mem_addr, f64i_simd2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[0];

}

void _igen_fb_mm_store_pd1(f64_I *mem_addr, f64i_simd2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[0];

}

void _igen_fb_mm_store_pd(f64_I *mem_addr, f64i_simd2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];

}

void _igen_fb_mm_storeu_pd(f64_I *mem_addr, f64i_simd2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];

}

void _igen_fb_mm_storer_pd(f64_I *mem_addr, f64i_simd2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[1];
    *(mem_addr + 1) = a.f[0];

}

void _igen_fb_mm_storeh_pd(f64_I *mem_addr, f64i_simd2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[1];

}

void _igen_fb_mm_storel_pd(f64_I *mem_addr, f64i_simd2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];

}

f64i_simd2 _igen_fb_mm_unpackhi_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    INTERLEAVE_HIGH_QWORDS_dd(&dst.f[0], &a.f[0], &b.f[0]);
    return dst.v;
}

f64i_simd2 _igen_fb_mm_unpacklo_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    INTERLEAVE_QWORDS_dd(&dst.f[0], &a.f[0], &b.f[0]);
    return dst.v;
}

int _igen_fb_mm_movemask_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    int dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        if (vecBitAccess_d(a.i, i + 63)) {
            dst = ((dst & ~(1 << (j))) | ((1) << (j)));
        } else {
            dst = ((dst & ~(1 << (j))) | ((0) << (j)));
        }
    }
    (dst) = ((dst) & (~(((1 << ((31) - (2) + 1)) - 1) << ((2))))) | ((0) << (2));
    int _ret;
    _ret = dst;
    return _ret;
}

f64i_simd2 _igen_fb_mm_shuffle_pd(f64i_simd2 _a, f64i_simd2 _b, int imm8) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = (((imm8 >> 0) & 1) == 0) ? a.f[0] : a.f[1];
    dst.f[1] = (((imm8 >> 1) & 1) == 0) ? b.f[0] : b.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_move_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = b.f[0];
    dst.f[1] = a.f[1];
    return dst.v;
}

f32i_simd4 _igen_fb_mm_castpd_ps(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

__m128i _igen_fb_mm_castpd_si128(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128i dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

f64i_simd2 _igen_fb_mm_castps_pd(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

__m128i _igen_fb_mm_castps_si128(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128i dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

f64i_simd2 _igen_fb_mm_castsi128_pd(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec128d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

f32i_simd4 _igen_fb_mm_castsi128_ps(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec128s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

f32_I _igen_fb_cvtsh_ss(__mmask16 a) {
    f32_I dst;

    dst = Convert_FP16_To_FP32_u16(a);
    return dst;
}

__mmask16 _igen_fb_cvtss_sh(f32_I a, int rounding) {
    __mmask16 dst;

    dst = Convert_FP32_To_FP16_s(a);
    __mmask16 _ret;
    _ret = dst;
    return _ret;
}

f32i_simd4 _igen_fb_mm_cvtph_ps(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        m = j * 16;
        dst.f[i / 32] = Convert_FP16_To_FP32_i(vecBitsAccess_i(a.i, m + 15, m));
    }

    return dst.v;
}

__m128i _igen_fb_mm_cvtps_ph(f32i_simd4 _a, int rounding) {
    vec128s a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;
    int l;

    for (j = 0; j <= 3; ++j) {
        i = 16 * j;
        l = 32 * j;
        vecBitsAssign_i(dst.i, i + 15, i, Convert_FP32_To_FP16_s(a.f[l / 32]));
    }

    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

f32i_simd4 _igen_fb_mm_addsub_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (j % 1 == 0) {
            dst.f[i / 32].lo = a.f[i / 32].lo + b.f[i / 32].up;
            dst.f[i / 32].up = a.f[i / 32].up + b.f[i / 32].lo;
        } else {
            dst.f[i / 32].lo = a.f[i / 32].lo + b.f[i / 32].lo;
            dst.f[i / 32].up = a.f[i / 32].up + b.f[i / 32].up;
        }
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_addsub_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        if (j % 1 == 0) {
            dst.f[i / 64] = _ia_sub_f64(a.f[i / 64], b.f[i / 64]);
        } else {
            dst.f[i / 64] = _ia_add_f64(a.f[i / 64], b.f[i / 64]);
        }
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_hadd_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_add_f64(a.f[1], a.f[0]);
    dst.f[1] = _ia_add_f64(b.f[1], b.f[0]);
    return dst.v;
}

f32i_simd4 _igen_fb_mm_hadd_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0].lo = a.f[1].lo + a.f[0].lo;
    dst.f[0].up = a.f[1].up + a.f[0].up;
    dst.f[1].lo = a.f[3].lo + a.f[2].lo;
    dst.f[1].up = a.f[3].up + a.f[2].up;
    dst.f[2].lo = b.f[1].lo + b.f[0].lo;
    dst.f[2].up = b.f[1].up + b.f[0].up;
    dst.f[3].lo = b.f[3].lo + b.f[2].lo;
    dst.f[3].up = b.f[3].up + b.f[2].up;
    return dst.v;
}

f64i_simd2 _igen_fb_mm_hsub_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.ff[0].lo = a.ff[0].lo + a.ff[1].up;
    dst.ff[0].up = a.ff[0].up + a.ff[1].lo;
    dst.ff[1].lo = b.ff[0].lo + b.ff[1].up;
    dst.ff[1].up = b.ff[0].up + b.ff[1].lo;
    return dst.v;
}

f32i_simd4 _igen_fb_mm_hsub_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0].lo = a.f[0].lo + a.f[1].up;
    dst.f[0].up = a.f[0].up + a.f[1].lo;
    dst.f[1].lo = a.f[2].lo + a.f[3].up;
    dst.f[1].up = a.f[2].up + a.f[3].lo;
    dst.f[2].lo = b.f[0].lo + b.f[1].up;
    dst.f[2].up = b.f[0].up + b.f[1].lo;
    dst.f[3].lo = b.f[2].lo + b.f[3].up;
    dst.f[3].up = b.f[2].up + b.f[3].lo;
    return dst.v;
}

f64i_simd2 _igen_fb_mm_movedup_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[0];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_loaddup_pd(const f64_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

f32i_simd4 _igen_fb_mm_movehdup_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = a.f[1];
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[3];
    dst.f[3] = a.f[3];
    return dst.v;
}

f32i_simd4 _igen_fb_mm_moveldup_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[0];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[2];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_blend_pd(f64i_simd2 _a, f64i_simd2 _b, int imm8) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        if (((imm8 >> j) & 1)) {
            dst.f[i / 64] = b.f[i / 64];
        } else {
            dst.f[i / 64] = a.f[i / 64];
        }
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_blend_ps(f32i_simd4 _a, f32i_simd4 _b, int imm8) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (((imm8 >> j) & 1)) {
            dst.f[i / 32] = b.f[i / 32];
        } else {
            dst.f[i / 32] = a.f[i / 32];
        }
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_blendv_pd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _mask) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d mask;
    mask.v = _mask;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        if (vecBitAccess_d(mask.i, i + 63)) {
            dst.f[i / 64] = b.f[i / 64];
        } else {
            dst.f[i / 64] = a.f[i / 64];
        }
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_blendv_ps(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _mask) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s mask;
    mask.v = _mask;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (vecBitAccess_s(mask.i, i + 31)) {
            dst.f[i / 32] = b.f[i / 32];
        } else {
            dst.f[i / 32] = a.f[i / 32];
        }
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_dp_pd(f64i_simd2 _a, f64i_simd2 _b, int imm8) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;
    vec128d temp;
    vec128d sum;
    vec128d tmpdst;

    DP_ddi(&dst.f[0], &a.f[0], &b.f[0],
           (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)));
    return dst.v;
}

f32i_simd4 _igen_fb_mm_dp_ps(f32i_simd4 _a, f32i_simd4 _b, int imm8) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;
    vec128s temp;
    vec128s sum;
    vec128s tmpdst;

    DP_ssi(&dst.f[0], &a.f[0], &b.f[0],
           (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)));
    return dst.v;
}

int _igen_fb_mm_extract_ps(f32i_simd4 _a, int imm8) {
    vec128s a;
    a.v = _a;
    int dst;

    int _ret;
    _ret = dst;
    return _ret;
}

f32i_simd4 _igen_fb_mm_insert_ps(f32i_simd4 _a, f32i_simd4 _b, int imm8) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    vec128s tmp2;
    vec128s tmp1;
    int j;
    int i;

    tmp2.f[0] = a.f[0];
    tmp2.f[1] = a.f[1];
    tmp2.f[2] = a.f[2];
    tmp2.f[3] = a.f[3];

    switch ((((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1))) {
        case 0:
            tmp1.f[0] = b.f[0];
            break;
        case 1:
            tmp1.f[0] = b.f[1];
            break;
        case 2:
            tmp1.f[0] = b.f[2];
            break;
        case 3:
            tmp1.f[0] = b.f[3];
            break;
    }
    switch ((((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1))) {
        case 0:
            tmp2.f[0] = tmp1.f[0];
            break;
        case 1:
            tmp2.f[1] = tmp1.f[0];
            break;
        case 2:
            tmp2.f[2] = tmp1.f[0];
            break;
        case 3:
            tmp2.f[3] = tmp1.f[0];
            break;
    }
    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (((imm8 >> j % 8) & 1)) {
            dst.f[i / 32].lo = -0.0;
            dst.f[i / 32].up = 0.0;
        } else {
            dst.f[i / 32] = tmp2.f[i / 32];
        }
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_round_pd(f64i_simd2 _a, int rounding) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ROUND_di(a.f[i / 64], rounding);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_floor_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = FLOOR_d(a.f[i / 64]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_ceil_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = CEIL_d(a.f[i / 64]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_round_ps(f32i_simd4 _a, int rounding) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ROUND_si(a.f[i / 32], rounding);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_floor_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = FLOOR_s(a.f[i / 32]);
    }
    return dst.v;
}

f32i_simd4 _igen_fb_mm_ceil_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = CEIL_s(a.f[i / 32]);
    }
    return dst.v;
}

f64i_simd2 _igen_fb_mm_round_sd(f64i_simd2 _a, f64i_simd2 _b, int rounding) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = ROUND_di(b.f[0], rounding);
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_floor_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = FLOOR_d(b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

f64i_simd2 _igen_fb_mm_ceil_sd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = CEIL_d(b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

f32i_simd4 _igen_fb_mm_round_ss(f32i_simd4 _a, f32i_simd4 _b, int rounding) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = ROUND_si(b.f[0], rounding);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_floor_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = FLOOR_s(b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_ceil_ss(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = CEIL_s(b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_add_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.ff[i / 64].lo = a.ff[i / 64].lo + b.ff[i / 64].lo;
        dst.ff[i / 64].up = a.ff[i / 64].up + b.ff[i / 64].up;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_add_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32].lo = a.f[i / 32].lo + b.f[i / 32].lo;
        dst.f[i / 32].up = a.f[i / 32].up + b.f[i / 32].up;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_addsub_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (j % 1 == 0) {
            dst.ff[i / 64].lo = a.ff[i / 64].lo + b.ff[i / 64].up;
            dst.ff[i / 64].up = a.ff[i / 64].up + b.ff[i / 64].lo;
        } else {
            dst.ff[i / 64].lo = a.ff[i / 64].lo + b.ff[i / 64].lo;
            dst.ff[i / 64].up = a.ff[i / 64].up + b.ff[i / 64].up;
        }
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_addsub_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        if (j % 1 == 0) {
            dst.f[i / 32].lo = a.f[i / 32].lo + b.f[i / 32].up;
            dst.f[i / 32].up = a.f[i / 32].up + b.f[i / 32].lo;
        } else {
            dst.f[i / 32].lo = a.f[i / 32].lo + b.f[i / 32].lo;
            dst.f[i / 32].up = a.f[i / 32].up + b.f[i / 32].up;
        }
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_and_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.i[i / 64] = _ia_and_u64(a.i[i / 64], b.i[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_and_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.i[i / 32] = _ia_and_u32(a.i[i / 32], b.i[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_andnot_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        u64_I _t65;
        _t65.lo = (~a.i[i / 64].lo);
        _t65.up = (~a.i[i / 64].up);
        dst.i[i / 64] = _ia_and_u64(_t65, b.i[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_andnot_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        u32_I _t66;
        _t66.lo = (~a.i[i / 32].lo);
        _t66.up = (~a.i[i / 32].up);
        dst.i[i / 32] = _ia_and_u32(_t66, b.i[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_blend_pd(f64i_simd4 _a, f64i_simd4 _b, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (((imm8 >> j) & 1)) {
            dst.f[i / 64] = b.f[i / 64];
        } else {
            dst.f[i / 64] = a.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_blend_ps(f32i_simd8 _a, f32i_simd8 _b, int imm8) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        if (((imm8 >> j) & 1)) {
            dst.f[i / 32] = b.f[i / 32];
        } else {
            dst.f[i / 32] = a.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_blendv_pd(f64i_simd4 _a, f64i_simd4 _b, f64i_simd4 _mask) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d mask;
    mask.v = _mask;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (vecBitAccess_d(mask.i, i + 63)) {
            dst.f[i / 64] = b.f[i / 64];
        } else {
            dst.f[i / 64] = a.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_blendv_ps(f32i_simd8 _a, f32i_simd8 _b, f32i_simd8 _mask) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s mask;
    mask.v = _mask;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        if (vecBitAccess_s(mask.i, i + 31)) {
            dst.f[i / 32] = b.f[i / 32];
        } else {
            dst.f[i / 32] = a.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_div_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = 64 * j;
        dst.f[i / 64] = _ia_div_f64(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_div_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = 32 * j;
        dst.f[i / 32] = _ia_div_f32(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_dp_ps(f32i_simd8 _a, f32i_simd8 _b, int imm8) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;
    vec256s temp;
    vec256s sum;
    vec256s tmpdst;

    DP_ssi(&dst.f[0], &a.f[0], &b.f[0],
           (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)));
    DP_ssi(&dst.f[4], &a.f[4], &b.f[4],
           (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)));

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_hadd_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    dst.f[0] = _ia_add_f64(a.f[1], a.f[0]);
    dst.f[1] = _ia_add_f64(b.f[1], b.f[0]);
    dst.f[2] = _ia_add_f64(a.f[3], a.f[2]);
    dst.f[3] = _ia_add_f64(b.f[3], b.f[2]);

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_hadd_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;

    dst.f[0].lo = a.f[1].lo + a.f[0].lo;
    dst.f[0].up = a.f[1].up + a.f[0].up;
    dst.f[1].lo = a.f[3].lo + a.f[2].lo;
    dst.f[1].up = a.f[3].up + a.f[2].up;
    dst.f[2].lo = b.f[1].lo + b.f[0].lo;
    dst.f[2].up = b.f[1].up + b.f[0].up;
    dst.f[3].lo = b.f[3].lo + b.f[2].lo;
    dst.f[3].up = b.f[3].up + b.f[2].up;
    dst.f[4].lo = a.f[5].lo + a.f[4].lo;
    dst.f[4].up = a.f[5].up + a.f[4].up;
    dst.f[5].lo = a.f[7].lo + a.f[6].lo;
    dst.f[5].up = a.f[7].up + a.f[6].up;
    dst.f[6].lo = b.f[5].lo + b.f[4].lo;
    dst.f[6].up = b.f[5].up + b.f[4].up;
    dst.f[7].lo = b.f[7].lo + b.f[6].lo;
    dst.f[7].up = b.f[7].up + b.f[6].up;

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_hsub_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    dst.ff[0].lo = a.ff[0].lo + a.ff[1].up;
    dst.ff[0].up = a.ff[0].up + a.ff[1].lo;
    dst.ff[1].lo = b.ff[0].lo + b.ff[1].up;
    dst.ff[1].up = b.ff[0].up + b.ff[1].lo;
    dst.ff[2].lo = a.ff[2].lo + a.ff[3].up;
    dst.ff[2].up = a.ff[2].up + a.ff[3].lo;
    dst.ff[3].lo = b.ff[2].lo + b.ff[3].up;
    dst.ff[3].up = b.ff[2].up + b.ff[3].lo;

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_hsub_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;

    dst.f[0].lo = a.f[0].lo + a.f[1].up;
    dst.f[0].up = a.f[0].up + a.f[1].lo;
    dst.f[1].lo = a.f[2].lo + a.f[3].up;
    dst.f[1].up = a.f[2].up + a.f[3].lo;
    dst.f[2].lo = b.f[0].lo + b.f[1].up;
    dst.f[2].up = b.f[0].up + b.f[1].lo;
    dst.f[3].lo = b.f[2].lo + b.f[3].up;
    dst.f[3].up = b.f[2].up + b.f[3].lo;
    dst.f[4].lo = a.f[4].lo + a.f[5].up;
    dst.f[4].up = a.f[4].up + a.f[5].lo;
    dst.f[5].lo = a.f[6].lo + a.f[7].up;
    dst.f[5].up = a.f[6].up + a.f[7].lo;
    dst.f[6].lo = b.f[4].lo + b.f[5].up;
    dst.f[6].up = b.f[4].up + b.f[5].lo;
    dst.f[7].lo = b.f[6].lo + b.f[7].up;
    dst.f[7].up = b.f[6].up + b.f[7].lo;

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_max_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = MAX_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_max_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = MAX_ss(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_min_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = MIN_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_min_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = MIN_ss(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_mul_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_mul_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_or_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.i[i / 64] = _ia_or_u64(a.i[i / 64], b.i[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_or_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.i[i / 32] = _ia_or_u32(a.i[i / 32], b.i[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_shuffle_pd(f64i_simd4 _a, f64i_simd4 _b, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    dst.f[0] = (((imm8 >> 0) & 1) == 0) ? a.f[0] : a.f[1];
    dst.f[1] = (((imm8 >> 1) & 1) == 0) ? b.f[0] : b.f[1];
    dst.f[2] = (((imm8 >> 2) & 1) == 0) ? a.f[2] : a.f[3];
    dst.f[3] = (((imm8 >> 3) & 1) == 0) ? b.f[2] : b.f[3];

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_shuffle_ps(f32i_simd8 _a, f32i_simd8 _b, int imm8) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;

    dst.f[0] = SELECT4_si(&a.f[0], (((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1)));
    dst.f[1] = SELECT4_si(&a.f[0], (((imm8) >> (2)) & ((1 << (3 - 2 + 1)) - 1)));
    dst.f[2] = SELECT4_si(&b.f[0], (((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1)));
    dst.f[3] = SELECT4_si(&b.f[0], (((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1)));
    dst.f[4] = SELECT4_si(&a.f[4], (((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1)));
    dst.f[5] = SELECT4_si(&a.f[4], (((imm8) >> (2)) & ((1 << (3 - 2 + 1)) - 1)));
    dst.f[6] = SELECT4_si(&b.f[4], (((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1)));
    dst.f[7] = SELECT4_si(&b.f[4], (((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1)));

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_sub_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.ff[i / 64].lo = a.ff[i / 64].lo + b.ff[i / 64].up;
        dst.ff[i / 64].up = a.ff[i / 64].up + b.ff[i / 64].lo;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_sub_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32].lo = a.f[i / 32].lo + b.f[i / 32].up;
        dst.f[i / 32].up = a.f[i / 32].up + b.f[i / 32].lo;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_xor_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.i[i / 64].lo = a.i[i / 64].lo ^ b.i[i / 64].lo;
        dst.i[i / 64].up = a.i[i / 64].up ^ b.i[i / 64].up;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_xor_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.i[i / 32].lo = a.i[i / 32].lo ^ b.i[i / 32].lo;
        dst.i[i / 32].up = a.i[i / 32].up ^ b.i[i / 32].up;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmp_pd(f64i_simd2 _a, f64i_simd2 _b, int imm8) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int (*op)(f64_I, f64_I);
    int j;
    int i;

    switch ((((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1))) {
        case 0:
            op = _cmp_eq;
            break;
        case 1:
            op = _cmp_lt;
            break;
        case 2:
            op = _cmp_leq;
            break;
        case 3:
            op = _cmp_unord;
            break;
        case 4:
            op = _cmp_neq;
            break;
        case 5:
            op = _cmp_geq;
            break;
        case 6:
            op = _cmp_gt;
            break;
        case 7:
            op = _cmp_ord;
            break;
        case 8:
            op = _cmp_eq;
            break;
        case 9:
            op = _cmp_lt;
            break;
        case 10:
            op = _cmp_leq;
            break;
        case 11:
            op = _cmp_false;
            break;
        case 12:
            op = _cmp_neq;
            break;
        case 13:
            op = _cmp_geq;
            break;
        case 14:
            op = _cmp_gt;
            break;
        case 15:
            op = _cmp_true;
            break;
        case 16:
            op = _cmp_eq;
            break;
        case 17:
            op = _cmp_lt;
            break;
        case 18:
            op = _cmp_leq;
            break;
        case 19:
            op = _cmp_unord;
            break;
        case 20:
            op = _cmp_neq;
            break;
        case 21:
            op = _cmp_geq;
            break;
        case 22:
            op = _cmp_gt;
            break;
        case 23:
            op = _cmp_ord;
            break;
        case 24:
            op = _cmp_eq;
            break;
        case 25:
            op = _cmp_lt;
            break;
        case 26:
            op = _cmp_leq;
            break;
        case 27:
            op = _cmp_false;
            break;
        case 28:
            op = _cmp_neq;
            break;
        case 29:
            op = _cmp_geq;
            break;
        case 30:
            op = _cmp_gt;
            break;
        case 31:
            op = _cmp_true;
            break;
    }
    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t67 = (op(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t67, 63);
        dst.i[i / 64].up = _t67;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_cmp_pd(f64i_simd4 _a, f64i_simd4 _b, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int (*op)(f64_I, f64_I);
    int j;
    int i;

    switch ((((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1))) {
        case 0:
            op = _cmp_eq;
            break;
        case 1:
            op = _cmp_lt;
            break;
        case 2:
            op = _cmp_leq;
            break;
        case 3:
            op = _cmp_unord;
            break;
        case 4:
            op = _cmp_neq;
            break;
        case 5:
            op = _cmp_geq;
            break;
        case 6:
            op = _cmp_gt;
            break;
        case 7:
            op = _cmp_ord;
            break;
        case 8:
            op = _cmp_eq;
            break;
        case 9:
            op = _cmp_lt;
            break;
        case 10:
            op = _cmp_leq;
            break;
        case 11:
            op = _cmp_false;
            break;
        case 12:
            op = _cmp_neq;
            break;
        case 13:
            op = _cmp_geq;
            break;
        case 14:
            op = _cmp_gt;
            break;
        case 15:
            op = _cmp_true;
            break;
        case 16:
            op = _cmp_eq;
            break;
        case 17:
            op = _cmp_lt;
            break;
        case 18:
            op = _cmp_leq;
            break;
        case 19:
            op = _cmp_unord;
            break;
        case 20:
            op = _cmp_neq;
            break;
        case 21:
            op = _cmp_geq;
            break;
        case 22:
            op = _cmp_gt;
            break;
        case 23:
            op = _cmp_ord;
            break;
        case 24:
            op = _cmp_eq;
            break;
        case 25:
            op = _cmp_lt;
            break;
        case 26:
            op = _cmp_leq;
            break;
        case 27:
            op = _cmp_false;
            break;
        case 28:
            op = _cmp_neq;
            break;
        case 29:
            op = _cmp_geq;
            break;
        case 30:
            op = _cmp_gt;
            break;
        case 31:
            op = _cmp_true;
            break;
    }
    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        unsigned long _t68 = (op(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64].lo = toogleBit(_t68, 63);
        dst.i[i / 64].up = _t68;
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmp_ps(f32i_simd4 _a, f32i_simd4 _b, int imm8) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int (*op)(f64_I, f64_I);
    int j;
    int i;

    switch ((((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1))) {
        case 0:
            op = _cmp_eq;
            break;
        case 1:
            op = _cmp_lt;
            break;
        case 2:
            op = _cmp_leq;
            break;
        case 3:
            op = _cmp_unord;
            break;
        case 4:
            op = _cmp_neq;
            break;
        case 5:
            op = _cmp_geq;
            break;
        case 6:
            op = _cmp_gt;
            break;
        case 7:
            op = _cmp_ord;
            break;
        case 8:
            op = _cmp_eq;
            break;
        case 9:
            op = _cmp_lt;
            break;
        case 10:
            op = _cmp_leq;
            break;
        case 11:
            op = _cmp_false;
            break;
        case 12:
            op = _cmp_neq;
            break;
        case 13:
            op = _cmp_geq;
            break;
        case 14:
            op = _cmp_gt;
            break;
        case 15:
            op = _cmp_true;
            break;
        case 16:
            op = _cmp_eq;
            break;
        case 17:
            op = _cmp_lt;
            break;
        case 18:
            op = _cmp_leq;
            break;
        case 19:
            op = _cmp_unord;
            break;
        case 20:
            op = _cmp_neq;
            break;
        case 21:
            op = _cmp_geq;
            break;
        case 22:
            op = _cmp_gt;
            break;
        case 23:
            op = _cmp_ord;
            break;
        case 24:
            op = _cmp_eq;
            break;
        case 25:
            op = _cmp_lt;
            break;
        case 26:
            op = _cmp_leq;
            break;
        case 27:
            op = _cmp_false;
            break;
        case 28:
            op = _cmp_neq;
            break;
        case 29:
            op = _cmp_geq;
            break;
        case 30:
            op = _cmp_gt;
            break;
        case 31:
            op = _cmp_true;
            break;
    }
    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        u_f64i _t69;
        _t69.lo = a.f[i / 32].lo;
        _t69.up = a.f[i / 32].up;
        u_f64i _t70;
        _t70.lo = b.f[i / 32].lo;
        _t70.up = b.f[i / 32].up;
        unsigned int _t71 = (op(_t69.v, _t70.v)) ? -1 : 0;
        dst.i[i / 32].lo = _t71;
        dst.i[i / 32].up = _t71;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cmp_ps(f32i_simd8 _a, f32i_simd8 _b, int imm8) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int (*op)(f64_I, f64_I);
    int j;
    int i;

    switch ((((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1))) {
        case 0:
            op = _cmp_eq;
            break;
        case 1:
            op = _cmp_lt;
            break;
        case 2:
            op = _cmp_leq;
            break;
        case 3:
            op = _cmp_unord;
            break;
        case 4:
            op = _cmp_neq;
            break;
        case 5:
            op = _cmp_geq;
            break;
        case 6:
            op = _cmp_gt;
            break;
        case 7:
            op = _cmp_ord;
            break;
        case 8:
            op = _cmp_eq;
            break;
        case 9:
            op = _cmp_lt;
            break;
        case 10:
            op = _cmp_leq;
            break;
        case 11:
            op = _cmp_false;
            break;
        case 12:
            op = _cmp_neq;
            break;
        case 13:
            op = _cmp_geq;
            break;
        case 14:
            op = _cmp_gt;
            break;
        case 15:
            op = _cmp_true;
            break;
        case 16:
            op = _cmp_eq;
            break;
        case 17:
            op = _cmp_lt;
            break;
        case 18:
            op = _cmp_leq;
            break;
        case 19:
            op = _cmp_unord;
            break;
        case 20:
            op = _cmp_neq;
            break;
        case 21:
            op = _cmp_geq;
            break;
        case 22:
            op = _cmp_gt;
            break;
        case 23:
            op = _cmp_ord;
            break;
        case 24:
            op = _cmp_eq;
            break;
        case 25:
            op = _cmp_lt;
            break;
        case 26:
            op = _cmp_leq;
            break;
        case 27:
            op = _cmp_false;
            break;
        case 28:
            op = _cmp_neq;
            break;
        case 29:
            op = _cmp_geq;
            break;
        case 30:
            op = _cmp_gt;
            break;
        case 31:
            op = _cmp_true;
            break;
    }
    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        u_f64i _t72;
        _t72.lo = a.f[i / 32].lo;
        _t72.up = a.f[i / 32].up;
        u_f64i _t73;
        _t73.lo = b.f[i / 32].lo;
        _t73.up = b.f[i / 32].up;
        unsigned int _t74 = (op(_t72.v, _t73.v)) ? -1 : 0;
        dst.i[i / 32].lo = toogleBit(_t74, 31);
        dst.i[i / 32].up = _t74;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cmp_sd(f64i_simd2 _a, f64i_simd2 _b, int imm8) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int (*op)(f64_I, f64_I);

    switch ((((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1))) {
        case 0:
            op = _cmp_eq;
            break;
        case 1:
            op = _cmp_lt;
            break;
        case 2:
            op = _cmp_leq;
            break;
        case 3:
            op = _cmp_unord;
            break;
        case 4:
            op = _cmp_neq;
            break;
        case 5:
            op = _cmp_geq;
            break;
        case 6:
            op = _cmp_gt;
            break;
        case 7:
            op = _cmp_ord;
            break;
        case 8:
            op = _cmp_eq;
            break;
        case 9:
            op = _cmp_lt;
            break;
        case 10:
            op = _cmp_leq;
            break;
        case 11:
            op = _cmp_false;
            break;
        case 12:
            op = _cmp_neq;
            break;
        case 13:
            op = _cmp_geq;
            break;
        case 14:
            op = _cmp_gt;
            break;
        case 15:
            op = _cmp_true;
            break;
        case 16:
            op = _cmp_eq;
            break;
        case 17:
            op = _cmp_lt;
            break;
        case 18:
            op = _cmp_leq;
            break;
        case 19:
            op = _cmp_unord;
            break;
        case 20:
            op = _cmp_neq;
            break;
        case 21:
            op = _cmp_geq;
            break;
        case 22:
            op = _cmp_gt;
            break;
        case 23:
            op = _cmp_ord;
            break;
        case 24:
            op = _cmp_eq;
            break;
        case 25:
            op = _cmp_lt;
            break;
        case 26:
            op = _cmp_leq;
            break;
        case 27:
            op = _cmp_false;
            break;
        case 28:
            op = _cmp_neq;
            break;
        case 29:
            op = _cmp_geq;
            break;
        case 30:
            op = _cmp_gt;
            break;
        case 31:
            op = _cmp_true;
            break;
    }
    unsigned long _t75 = (op(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t75, 63);
    dst.i[0].up = _t75;
    dst.f[1] = a.f[1];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cmp_ss(f32i_simd4 _a, f32i_simd4 _b, int imm8) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int (*op)(f64_I, f64_I);

    switch ((((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1))) {
        case 0:
            op = _cmp_eq;
            break;
        case 1:
            op = _cmp_lt;
            break;
        case 2:
            op = _cmp_leq;
            break;
        case 3:
            op = _cmp_unord;
            break;
        case 4:
            op = _cmp_neq;
            break;
        case 5:
            op = _cmp_geq;
            break;
        case 6:
            op = _cmp_gt;
            break;
        case 7:
            op = _cmp_ord;
            break;
        case 8:
            op = _cmp_eq;
            break;
        case 9:
            op = _cmp_lt;
            break;
        case 10:
            op = _cmp_leq;
            break;
        case 11:
            op = _cmp_false;
            break;
        case 12:
            op = _cmp_neq;
            break;
        case 13:
            op = _cmp_geq;
            break;
        case 14:
            op = _cmp_gt;
            break;
        case 15:
            op = _cmp_true;
            break;
        case 16:
            op = _cmp_eq;
            break;
        case 17:
            op = _cmp_lt;
            break;
        case 18:
            op = _cmp_leq;
            break;
        case 19:
            op = _cmp_unord;
            break;
        case 20:
            op = _cmp_neq;
            break;
        case 21:
            op = _cmp_geq;
            break;
        case 22:
            op = _cmp_gt;
            break;
        case 23:
            op = _cmp_ord;
            break;
        case 24:
            op = _cmp_eq;
            break;
        case 25:
            op = _cmp_lt;
            break;
        case 26:
            op = _cmp_leq;
            break;
        case 27:
            op = _cmp_false;
            break;
        case 28:
            op = _cmp_neq;
            break;
        case 29:
            op = _cmp_geq;
            break;
        case 30:
            op = _cmp_gt;
            break;
        case 31:
            op = _cmp_true;
            break;
    }
    u_f64i _t76;
    _t76.lo = a.f[0].lo;
    _t76.up = a.f[0].up;
    u_f64i _t77;
    _t77.lo = b.f[0].lo;
    _t77.up = b.f[0].up;
    unsigned int _t78 = (op(_t76.v, _t77.v)) ? -1 : 0;
    dst.i[0].lo = toogleBit(_t78, 31);
    dst.i[0].up = _t78;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_cvtepi32_pd(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        m = j * 64;
        dst.f[m / 64] = Convert_Int32_To_FP64_i(a.i[i / 32]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cvtepi32_ps(__m256i _a) {
    vec256i a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = 32 * j;
        dst.f[i / 32] = Convert_Int32_To_FP32_i(a.i[i / 32]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm256_cvtpd_ps(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.f[i / 32] = Convert_FP64_To_FP32_d(a.f[k / 64]);
    }

    return dst.v;
}

__m256i _igen_fb_mm256_cvtps_epi32(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256i dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = 32 * j;
        dst.i[i / 32] = Convert_FP32_To_Int32_s(a.f[i / 32]);
    }

    __m256i _ret;
    _ret = dst.v;
    return _ret;
}

f64i_simd4 _igen_fb_mm256_cvtps_pd(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 64 * j;
        k = 32 * j;
        dst.f[i / 64] = Convert_FP32_To_FP64_s(a.f[k / 32]);
    }

    return dst.v;
}

__m128i _igen_fb_mm256_cvttpd_epi32(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.i[i / 32] = Convert_FP64_To_Int32_Truncate_d(a.f[k / 64]);
    }

    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

__m128i _igen_fb_mm256_cvtpd_epi32(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;
    int k;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        k = 64 * j;
        dst.i[i / 32] = Convert_FP64_To_Int32_d(a.f[k / 64]);
    }

    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

__m256i _igen_fb_mm256_cvttps_epi32(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256i dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = 32 * j;
        dst.i[i / 32] = Convert_FP32_To_Int32_Truncate_s(a.f[i / 32]);
    }

    __m256i _ret;
    _ret = dst.v;
    return _ret;
}

f32i_simd4 _igen_fb_mm256_extractf128_ps(f32i_simd8 _a, int imm8) {
    vec256s a;
    a.v = _a;
    vec128s dst;

    switch (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)) {
        case 0:
            dst.f[0] = a.f[0];
            dst.f[1] = a.f[1];
            dst.f[2] = a.f[2];
            dst.f[3] = a.f[3];

            break;
        case 1:
            dst.f[0] = a.f[4];
            dst.f[1] = a.f[5];
            dst.f[2] = a.f[6];
            dst.f[3] = a.f[7];

            break;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm256_extractf128_pd(f64i_simd4 _a, int imm8) {
    vec256d a;
    a.v = _a;
    vec128d dst;

    switch (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)) {
        case 0:
            dst.f[0] = a.f[0];
            dst.f[1] = a.f[1];

            break;
        case 1:
            dst.f[0] = a.f[2];
            dst.f[1] = a.f[3];

            break;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_permutevar_ps(f32i_simd8 _a, __m256i _b) {
    vec256s a;
    a.v = _a;
    vec256i b;
    b.v = _b;
    vec256s dst;

    dst.f[0] = SELECT4_si(&a.f[0], vecBitsAccess_i(b.i, 1, 0));
    dst.f[1] = SELECT4_si(&a.f[0], vecBitsAccess_i(b.i, 33, 32));
    dst.f[2] = SELECT4_si(&a.f[0], vecBitsAccess_i(b.i, 65, 64));
    dst.f[3] = SELECT4_si(&a.f[0], vecBitsAccess_i(b.i, 97, 96));
    dst.f[4] = SELECT4_si(&a.f[4], vecBitsAccess_i(b.i, 129, 128));
    dst.f[5] = SELECT4_si(&a.f[4], vecBitsAccess_i(b.i, 161, 160));
    dst.f[6] = SELECT4_si(&a.f[4], vecBitsAccess_i(b.i, 193, 192));
    dst.f[7] = SELECT4_si(&a.f[4], vecBitsAccess_i(b.i, 225, 224));

    return dst.v;
}

f32i_simd4 _igen_fb_mm_permutevar_ps(f32i_simd4 _a, __m128i _b) {
    vec128s a;
    a.v = _a;
    vec128i b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = SELECT4_si(&a.f[0], vecBitsAccess_i(b.i, 1, 0));
    dst.f[1] = SELECT4_si(&a.f[0], vecBitsAccess_i(b.i, 33, 32));
    dst.f[2] = SELECT4_si(&a.f[0], vecBitsAccess_i(b.i, 65, 64));
    dst.f[3] = SELECT4_si(&a.f[0], vecBitsAccess_i(b.i, 97, 96));

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_permute_ps(f32i_simd8 _a, int imm8) {
    vec256s a;
    a.v = _a;
    vec256s dst;

    dst.f[0] = SELECT4_si(&a.f[0], (((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1)));
    dst.f[1] = SELECT4_si(&a.f[0], (((imm8) >> (2)) & ((1 << (3 - 2 + 1)) - 1)));
    dst.f[2] = SELECT4_si(&a.f[0], (((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1)));
    dst.f[3] = SELECT4_si(&a.f[0], (((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1)));
    dst.f[4] = SELECT4_si(&a.f[4], (((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1)));
    dst.f[5] = SELECT4_si(&a.f[4], (((imm8) >> (2)) & ((1 << (3 - 2 + 1)) - 1)));
    dst.f[6] = SELECT4_si(&a.f[4], (((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1)));
    dst.f[7] = SELECT4_si(&a.f[4], (((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1)));

    return dst.v;
}

f32i_simd4 _igen_fb_mm_permute_ps(f32i_simd4 _a, int imm8) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = SELECT4_si(&a.f[0], (((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1)));
    dst.f[1] = SELECT4_si(&a.f[0], (((imm8) >> (2)) & ((1 << (3 - 2 + 1)) - 1)));
    dst.f[2] = SELECT4_si(&a.f[0], (((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1)));
    dst.f[3] = SELECT4_si(&a.f[0], (((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1)));

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_permutevar_pd(f64i_simd4 _a, __m256i _b) {
    vec256d a;
    a.v = _a;
    vec256i b;
    b.v = _b;
    vec256d dst;

    if (vecBitAccess_i(b.i, 1) == 0) {
        dst.f[0] = a.f[0];
    }
    if (vecBitAccess_i(b.i, 1) == 1) {
        dst.f[0] = a.f[1];
    }
    if (vecBitAccess_i(b.i, 65) == 0) {
        dst.f[1] = a.f[0];
    }
    if (vecBitAccess_i(b.i, 65) == 1) {
        dst.f[1] = a.f[1];
    }
    if (vecBitAccess_i(b.i, 129) == 0) {
        dst.f[2] = a.f[2];
    }
    if (vecBitAccess_i(b.i, 129) == 1) {
        dst.f[2] = a.f[3];
    }
    if (vecBitAccess_i(b.i, 193) == 0) {
        dst.f[3] = a.f[2];
    }
    if (vecBitAccess_i(b.i, 193) == 1) {
        dst.f[3] = a.f[3];
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_permutevar_pd(f64i_simd2 _a, __m128i _b) {
    vec128d a;
    a.v = _a;
    vec128i b;
    b.v = _b;
    vec128d dst;

    if (vecBitAccess_i(b.i, 1) == 0) {
        dst.f[0] = a.f[0];
    }
    if (vecBitAccess_i(b.i, 1) == 1) {
        dst.f[0] = a.f[1];
    }
    if (vecBitAccess_i(b.i, 65) == 0) {
        dst.f[1] = a.f[0];
    }
    if (vecBitAccess_i(b.i, 65) == 1) {
        dst.f[1] = a.f[1];
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_permute_pd(f64i_simd4 _a, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d dst;

    if (((imm8 >> 0) & 1) == 0) {
        dst.f[0] = a.f[0];
    }
    if (((imm8 >> 0) & 1) == 1) {
        dst.f[0] = a.f[1];
    }
    if (((imm8 >> 1) & 1) == 0) {
        dst.f[1] = a.f[0];
    }
    if (((imm8 >> 1) & 1) == 1) {
        dst.f[1] = a.f[1];
    }
    if (((imm8 >> 2) & 1) == 0) {
        dst.f[2] = a.f[2];
    }
    if (((imm8 >> 2) & 1) == 1) {
        dst.f[2] = a.f[3];
    }
    if (((imm8 >> 3) & 1) == 0) {
        dst.f[3] = a.f[2];
    }
    if (((imm8 >> 3) & 1) == 1) {
        dst.f[3] = a.f[3];
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_permute_pd(f64i_simd2 _a, int imm8) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    if (((imm8 >> 0) & 1) == 0) {
        dst.f[0] = a.f[0];
    }
    if (((imm8 >> 0) & 1) == 1) {
        dst.f[0] = a.f[1];
    }
    if (((imm8 >> 1) & 1) == 0) {
        dst.f[1] = a.f[0];
    }
    if (((imm8 >> 1) & 1) == 1) {
        dst.f[1] = a.f[1];
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_permute2f128_ps(f32i_simd8 _a, f32i_simd8 _b, int imm8) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int tmp;

    SELECT4_ssi(&dst.f[0], &a.f[0], &b.f[0],
                (((imm8) >> (0)) & ((1 << (3 - 0 + 1)) - 1)));
    SELECT4_ssi(&dst.f[4], &a.f[0], &b.f[0],
                (((imm8) >> (4)) & ((1 << (7 - 4 + 1)) - 1)));

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_permute2f128_pd(f64i_simd4 _a, f64i_simd4 _b, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int tmp;

    SELECT4_ddi(&dst.f[0], &a.f[0], &b.f[0],
                (((imm8) >> (0)) & ((1 << (3 - 0 + 1)) - 1)));
    SELECT4_ddi(&dst.f[2], &a.f[0], &b.f[0],
                (((imm8) >> (4)) & ((1 << (7 - 4 + 1)) - 1)));

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_broadcast_ss(const f32_I *mem_addr) {
    vec256s dst;
    vec256s tmp;
    int j;
    int i;

    tmp.f[0] = *(mem_addr + 0);
    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = tmp.f[0];
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_broadcast_ss(const f32_I *mem_addr) {
    vec128s dst;
    vec256s tmp;
    int j;
    int i;

    tmp.f[0] = *(mem_addr + 0);
    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = tmp.f[0];
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_broadcast_sd(const f64_I *mem_addr) {
    vec256d dst;
    vec256d tmp;
    int j;
    int i;

    tmp.f[0] = *(mem_addr + 0);
    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = tmp.f[0];
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_broadcast_ps(f32i_simd4 *_mem_addr) {
    vec128s *mem_addr = (vec128s *)_mem_addr;
    vec256s dst;
    vec128s tmp;

    tmp.f[0] = mem_addr->f[0];
    tmp.f[1] = mem_addr->f[1];
    tmp.f[2] = mem_addr->f[2];
    tmp.f[3] = mem_addr->f[3];

    dst.f[0] = tmp.f[0];
    dst.f[1] = tmp.f[1];
    dst.f[2] = tmp.f[2];
    dst.f[3] = tmp.f[3];

    dst.f[4] = tmp.f[0];
    dst.f[5] = tmp.f[1];
    dst.f[6] = tmp.f[2];
    dst.f[7] = tmp.f[3];

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_broadcast_pd(f64i_simd2 *_mem_addr) {
    vec128d *mem_addr = (vec128d *)_mem_addr;
    vec256d dst;
    vec128d tmp;

    tmp.f[0] = mem_addr->f[0];
    tmp.f[1] = mem_addr->f[1];

    dst.f[0] = tmp.f[0];
    dst.f[1] = tmp.f[1];

    dst.f[2] = tmp.f[0];
    dst.f[3] = tmp.f[1];

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_insertf128_ps(f32i_simd8 _a, f32i_simd4 _b, int imm8) {
    vec256s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec256s dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];
    dst.f[4] = a.f[4];
    dst.f[5] = a.f[5];
    dst.f[6] = a.f[6];
    dst.f[7] = a.f[7];

    switch ((((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1))) {
        case 0:
            dst.f[0] = b.f[0];
            dst.f[1] = b.f[1];
            dst.f[2] = b.f[2];
            dst.f[3] = b.f[3];

            break;
        case 1:
            dst.f[4] = b.f[0];
            dst.f[5] = b.f[1];
            dst.f[6] = b.f[2];
            dst.f[7] = b.f[3];

            break;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_insertf128_pd(f64i_simd4 _a, f64i_simd2 _b, int imm8) {
    vec256d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec256d dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    switch (((imm8) >> (0)) & ((1 << (7 - 0 + 1)) - 1)) {
        case 0:
            dst.f[0] = b.f[0];
            dst.f[1] = b.f[1];

            break;
        case 1:
            dst.f[2] = b.f[0];
            dst.f[3] = b.f[1];

            break;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_load_pd(const f64_I *mem_addr) {
    vec256d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);

    return dst.v;
}

void _igen_fb_mm256_store_pd(f64_I *mem_addr, f64i_simd4 _a) {
    vec256d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];

}

f32i_simd8 _igen_fb_mm256_load_ps(const f32_I *mem_addr) {
    vec256s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);
    dst.f[4] = *(mem_addr + 4);
    dst.f[5] = *(mem_addr + 5);
    dst.f[6] = *(mem_addr + 6);
    dst.f[7] = *(mem_addr + 7);

    return dst.v;
}

void _igen_fb_mm256_store_ps(f32_I *mem_addr, f32i_simd8 _a) {
    vec256s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
    *(mem_addr + 4) = a.f[4];
    *(mem_addr + 5) = a.f[5];
    *(mem_addr + 6) = a.f[6];
    *(mem_addr + 7) = a.f[7];

}

f64i_simd4 _igen_fb_mm256_loadu_pd(const f64_I *mem_addr) {
    vec256d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);

    return dst.v;
}

void _igen_fb_mm256_storeu_pd(f64_I *mem_addr, f64i_simd4 _a) {
    vec256d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];

}

f32i_simd8 _igen_fb_mm256_loadu_ps(const f32_I *mem_addr) {
    vec256s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);
    dst.f[4] = *(mem_addr + 4);
    dst.f[5] = *(mem_addr + 5);
    dst.f[6] = *(mem_addr + 6);
    dst.f[7] = *(mem_addr + 7);

    return dst.v;
}

void _igen_fb_mm256_storeu_ps(f32_I *mem_addr, f32i_simd8 _a) {
    vec256s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
    *(mem_addr + 4) = a.f[4];
    *(mem_addr + 5) = a.f[5];
    *(mem_addr + 6) = a.f[6];
    *(mem_addr + 7) = a.f[7];

}

f64i_simd4 _igen_fb_mm256_maskload_pd(const f64_I *mem_addr, __m256i _mask) {
    vec256i mask;
    mask.v = _mask;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (vecBitAccess_i(mask.i, i + 63)) {
            dst.f[i / 64] = *(mem_addr + i / 64);
        } else {
            dst.f[i / 64] = _ia_zero_f64();
        }
    }

    return dst.v;
}

void _igen_fb_mm256_maskstore_pd(f64_I *mem_addr, __m256i _mask, f64i_simd4 _a) {
    vec256i mask;
    mask.v = _mask;
    vec256d a;
    a.v = _a;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (vecBitAccess_i(mask.i, i + 63)) {
            *(mem_addr + i / 64) = a.f[i / 64];
        }
    }

}

f64i_simd2 _igen_fb_mm_maskload_pd(const f64_I *mem_addr, __m128i _mask) {
    vec128i mask;
    mask.v = _mask;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        if (vecBitAccess_i(mask.i, i + 63)) {
            dst.f[i / 64] = *(mem_addr + i / 64);
        } else {
            dst.f[i / 64] = _ia_zero_f64();
        }
    }

    return dst.v;
}

void _igen_fb_mm_maskstore_pd(f64_I *mem_addr, __m128i _mask, f64i_simd2 _a) {
    vec128i mask;
    mask.v = _mask;
    vec128d a;
    a.v = _a;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        if (vecBitAccess_i(mask.i, i + 63)) {
            *(mem_addr + i / 64) = a.f[i / 64];
        }
    }

}

f32i_simd8 _igen_fb_mm256_maskload_ps(const f32_I *mem_addr, __m256i _mask) {
    vec256i mask;
    mask.v = _mask;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        if (vecBitAccess_i(mask.i, i + 31)) {
            dst.f[i / 32] = *(mem_addr + i / 32);
        } else {
            dst.f[i / 32].lo = -0.0;
            dst.f[i / 32].up = 0.0;
        }
    }

    return dst.v;
}

void _igen_fb_mm256_maskstore_ps(f32_I *mem_addr, __m256i _mask, f32i_simd8 _a) {
    vec256i mask;
    mask.v = _mask;
    vec256s a;
    a.v = _a;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        if (vecBitAccess_i(mask.i, i + 31)) {
            *(mem_addr + i / 32) = a.f[i / 32];
        }
    }

}

f32i_simd4 _igen_fb_mm_maskload_ps(const f32_I *mem_addr, __m128i _mask) {
    vec128i mask;
    mask.v = _mask;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (vecBitAccess_i(mask.i, i + 31)) {
            dst.f[i / 32] = *(mem_addr + i / 32);
        } else {
            dst.f[i / 32].lo = -0.0;
            dst.f[i / 32].up = 0.0;
        }
    }

    return dst.v;
}

void _igen_fb_mm_maskstore_ps(f32_I *mem_addr, __m128i _mask, f32i_simd4 _a) {
    vec128i mask;
    mask.v = _mask;
    vec128s a;
    a.v = _a;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (vecBitAccess_i(mask.i, i + 31)) {
            *(mem_addr + i / 32) = a.f[i / 32];
        }
    }

}

f32i_simd8 _igen_fb_mm256_movehdup_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;

    dst.f[0] = a.f[1];
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[3];
    dst.f[3] = a.f[3];
    dst.f[4] = a.f[5];
    dst.f[5] = a.f[5];
    dst.f[6] = a.f[7];
    dst.f[7] = a.f[7];

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_moveldup_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[0];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[2];
    dst.f[4] = a.f[4];
    dst.f[5] = a.f[4];
    dst.f[6] = a.f[6];
    dst.f[7] = a.f[6];

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_movedup_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[0];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[2];

    return dst.v;
}

void _igen_fb_mm256_stream_pd(f64_I *mem_addr, f64i_simd4 _a) {
    vec256d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];

}

void _igen_fb_mm256_stream_ps(f32_I *mem_addr, f32i_simd8 _a) {
    vec256s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
    *(mem_addr + 4) = a.f[4];
    *(mem_addr + 5) = a.f[5];
    *(mem_addr + 6) = a.f[6];
    *(mem_addr + 7) = a.f[7];

}

f32i_simd8 _igen_fb_mm256_rcp_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t79;
        _t79.lo = -1.0;
        _t79.up = 1.0;
        f32_I _t80;
        _t80.lo = a.f[i / 32].lo;
        _t80.up = a.f[i / 32].up;
        f32_I _t81 = _ia_div_f32(_t79, _t80);
        dst.f[i / 32].lo = _t81.lo;
        dst.f[i / 32].up = _t81.up;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_rsqrt_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t82 = SQRT_s(a.f[i / 32]);
        f32_I _t83;
        _t83.lo = -1.0;
        _t83.up = 1.0;
        f32_I _t84;
        _t84.lo = _t82.lo;
        _t84.up = _t82.up;
        f32_I _t85 = _ia_div_f32(_t83, _t84);
        dst.f[i / 32].lo = _t85.lo;
        dst.f[i / 32].up = _t85.up;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_sqrt_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = SQRT_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_sqrt_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = SQRT_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_round_pd(f64i_simd4 _a, int rounding) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ROUND_di(a.f[i / 64], rounding);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_round_ps(f32i_simd8 _a, int rounding) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ROUND_si(a.f[i / 32], rounding);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_unpackhi_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    INTERLEAVE_HIGH_QWORDS_dd(&dst.f[0], &a.f[0], &b.f[0]);
    INTERLEAVE_HIGH_QWORDS_dd(&dst.f[2], &a.f[2], &b.f[2]);

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_unpackhi_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;

    INTERLEAVE_HIGH_DWORDS_ss(&dst.f[0], &a.f[0], &b.f[0]);
    INTERLEAVE_HIGH_DWORDS_ss(&dst.f[4], &a.f[4], &b.f[4]);

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_unpacklo_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    INTERLEAVE_QWORDS_dd(&dst.f[0], &a.f[0], &b.f[0]);
    INTERLEAVE_QWORDS_dd(&dst.f[2], &a.f[2], &b.f[2]);

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_unpacklo_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;

    INTERLEAVE_DWORDS_ss(&dst.f[0], &a.f[0], &b.f[0]);
    INTERLEAVE_DWORDS_ss(&dst.f[4], &a.f[4], &b.f[4]);

    return dst.v;
}

int _igen_fb_mm256_testz_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    int dst;
    vec256d tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u64(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u64(a.i[1], b.i[1]);
    tmp.i[2] = _ia_and_u64(a.i[2], b.i[2]);
    tmp.i[3] = _ia_and_u64(a.i[3], b.i[3]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == vecBitAccess_d(tmp.i, 191) &&
        vecBitAccess_d(tmp.i, 191) == vecBitAccess_d(tmp.i, 255) &&
        vecBitAccess_d(tmp.i, 255) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u64_I _t86;
    _t86.lo = (~a.i[0].lo);
    _t86.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u64(_t86, b.i[0]);
    u64_I _t87;
    _t87.lo = (~a.i[1].lo);
    _t87.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u64(_t87, b.i[1]);
    u64_I _t88;
    _t88.lo = (~a.i[2].lo);
    _t88.up = (~a.i[2].up);
    tmp.i[2] = _ia_and_u64(_t88, b.i[2]);
    u64_I _t89;
    _t89.lo = (~a.i[3].lo);
    _t89.up = (~a.i[3].up);
    tmp.i[3] = _ia_and_u64(_t89, b.i[3]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == vecBitAccess_d(tmp.i, 191) &&
        vecBitAccess_d(tmp.i, 191) == vecBitAccess_d(tmp.i, 255) &&
        vecBitAccess_d(tmp.i, 255) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    dst = ZF;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm256_testc_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    int dst;
    vec256d tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u64(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u64(a.i[1], b.i[1]);
    tmp.i[2] = _ia_and_u64(a.i[2], b.i[2]);
    tmp.i[3] = _ia_and_u64(a.i[3], b.i[3]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == vecBitAccess_d(tmp.i, 191) &&
        vecBitAccess_d(tmp.i, 191) == vecBitAccess_d(tmp.i, 255) &&
        vecBitAccess_d(tmp.i, 255) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u64_I _t90;
    _t90.lo = (~a.i[0].lo);
    _t90.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u64(_t90, b.i[0]);
    u64_I _t91;
    _t91.lo = (~a.i[1].lo);
    _t91.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u64(_t91, b.i[1]);
    u64_I _t92;
    _t92.lo = (~a.i[2].lo);
    _t92.up = (~a.i[2].up);
    tmp.i[2] = _ia_and_u64(_t92, b.i[2]);
    u64_I _t93;
    _t93.lo = (~a.i[3].lo);
    _t93.up = (~a.i[3].up);
    tmp.i[3] = _ia_and_u64(_t93, b.i[3]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == vecBitAccess_d(tmp.i, 191) &&
        vecBitAccess_d(tmp.i, 191) == vecBitAccess_d(tmp.i, 255) &&
        vecBitAccess_d(tmp.i, 255) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    dst = CF;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm256_testnzc_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    int dst;
    vec256d tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u64(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u64(a.i[1], b.i[1]);
    tmp.i[2] = _ia_and_u64(a.i[2], b.i[2]);
    tmp.i[3] = _ia_and_u64(a.i[3], b.i[3]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == vecBitAccess_d(tmp.i, 191) &&
        vecBitAccess_d(tmp.i, 191) == vecBitAccess_d(tmp.i, 255) &&
        vecBitAccess_d(tmp.i, 255) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u64_I _t94;
    _t94.lo = (~a.i[0].lo);
    _t94.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u64(_t94, b.i[0]);
    u64_I _t95;
    _t95.lo = (~a.i[1].lo);
    _t95.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u64(_t95, b.i[1]);
    u64_I _t96;
    _t96.lo = (~a.i[2].lo);
    _t96.up = (~a.i[2].up);
    tmp.i[2] = _ia_and_u64(_t96, b.i[2]);
    u64_I _t97;
    _t97.lo = (~a.i[3].lo);
    _t97.up = (~a.i[3].up);
    tmp.i[3] = _ia_and_u64(_t97, b.i[3]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == vecBitAccess_d(tmp.i, 191) &&
        vecBitAccess_d(tmp.i, 191) == vecBitAccess_d(tmp.i, 255) &&
        vecBitAccess_d(tmp.i, 255) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    if (ZF == 0 && CF == 0) {
        dst = 1;
    } else {
        dst = 0;
    }
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_testz_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;
    vec128d tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u64(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u64(a.i[1], b.i[1]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u64_I _t98;
    _t98.lo = (~a.i[0].lo);
    _t98.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u64(_t98, b.i[0]);
    u64_I _t99;
    _t99.lo = (~a.i[1].lo);
    _t99.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u64(_t99, b.i[1]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    dst = ZF;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_testc_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;
    vec128d tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u64(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u64(a.i[1], b.i[1]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u64_I _t100;
    _t100.lo = (~a.i[0].lo);
    _t100.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u64(_t100, b.i[0]);
    u64_I _t101;
    _t101.lo = (~a.i[1].lo);
    _t101.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u64(_t101, b.i[1]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    dst = CF;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_testnzc_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;
    vec128d tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u64(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u64(a.i[1], b.i[1]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u64_I _t102;
    _t102.lo = (~a.i[0].lo);
    _t102.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u64(_t102, b.i[0]);
    u64_I _t103;
    _t103.lo = (~a.i[1].lo);
    _t103.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u64(_t103, b.i[1]);

    if (vecBitAccess_d(tmp.i, 63) == vecBitAccess_d(tmp.i, 127) &&
        vecBitAccess_d(tmp.i, 127) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    if (ZF == 0 && CF == 0) {
        dst = 1;
    } else {
        dst = 0;
    }
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm256_testz_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    int dst;
    vec256s tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u32(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u32(a.i[1], b.i[1]);
    tmp.i[2] = _ia_and_u32(a.i[2], b.i[2]);
    tmp.i[3] = _ia_and_u32(a.i[3], b.i[3]);
    tmp.i[4] = _ia_and_u32(a.i[4], b.i[4]);
    tmp.i[5] = _ia_and_u32(a.i[5], b.i[5]);
    tmp.i[6] = _ia_and_u32(a.i[6], b.i[6]);
    tmp.i[7] = _ia_and_u32(a.i[7], b.i[7]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == vecBitAccess_s(tmp.i, 159) &&
        vecBitAccess_s(tmp.i, 159) == vecBitAccess_s(tmp.i, 191) &&
        vecBitAccess_s(tmp.i, 191) == vecBitAccess_s(tmp.i, 223) &&
        vecBitAccess_s(tmp.i, 223) == vecBitAccess_s(tmp.i, 255) &&
        vecBitAccess_s(tmp.i, 255) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u32_I _t104;
    _t104.lo = (~a.i[0].lo);
    _t104.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u32(_t104, b.i[0]);
    u32_I _t105;
    _t105.lo = (~a.i[1].lo);
    _t105.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u32(_t105, b.i[1]);
    u32_I _t106;
    _t106.lo = (~a.i[2].lo);
    _t106.up = (~a.i[2].up);
    tmp.i[2] = _ia_and_u32(_t106, b.i[2]);
    u32_I _t107;
    _t107.lo = (~a.i[3].lo);
    _t107.up = (~a.i[3].up);
    tmp.i[3] = _ia_and_u32(_t107, b.i[3]);
    u32_I _t108;
    _t108.lo = (~a.i[4].lo);
    _t108.up = (~a.i[4].up);
    tmp.i[4] = _ia_and_u32(_t108, b.i[4]);
    u32_I _t109;
    _t109.lo = (~a.i[5].lo);
    _t109.up = (~a.i[5].up);
    tmp.i[5] = _ia_and_u32(_t109, b.i[5]);
    u32_I _t110;
    _t110.lo = (~a.i[6].lo);
    _t110.up = (~a.i[6].up);
    tmp.i[6] = _ia_and_u32(_t110, b.i[6]);
    u32_I _t111;
    _t111.lo = (~a.i[7].lo);
    _t111.up = (~a.i[7].up);
    tmp.i[7] = _ia_and_u32(_t111, b.i[7]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == vecBitAccess_s(tmp.i, 159) &&
        vecBitAccess_s(tmp.i, 159) == vecBitAccess_s(tmp.i, 191) &&
        vecBitAccess_s(tmp.i, 191) == vecBitAccess_s(tmp.i, 223) &&
        vecBitAccess_s(tmp.i, 223) == vecBitAccess_s(tmp.i, 255) &&
        vecBitAccess_s(tmp.i, 255) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    dst = ZF;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm256_testc_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    int dst;
    vec256s tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u32(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u32(a.i[1], b.i[1]);
    tmp.i[2] = _ia_and_u32(a.i[2], b.i[2]);
    tmp.i[3] = _ia_and_u32(a.i[3], b.i[3]);
    tmp.i[4] = _ia_and_u32(a.i[4], b.i[4]);
    tmp.i[5] = _ia_and_u32(a.i[5], b.i[5]);
    tmp.i[6] = _ia_and_u32(a.i[6], b.i[6]);
    tmp.i[7] = _ia_and_u32(a.i[7], b.i[7]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == vecBitAccess_s(tmp.i, 159) &&
        vecBitAccess_s(tmp.i, 159) == vecBitAccess_s(tmp.i, 191) &&
        vecBitAccess_s(tmp.i, 191) == vecBitAccess_s(tmp.i, 223) &&
        vecBitAccess_s(tmp.i, 223) == vecBitAccess_s(tmp.i, 255) &&
        vecBitAccess_s(tmp.i, 255) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u32_I _t112;
    _t112.lo = (~a.i[0].lo);
    _t112.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u32(_t112, b.i[0]);
    u32_I _t113;
    _t113.lo = (~a.i[1].lo);
    _t113.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u32(_t113, b.i[1]);
    u32_I _t114;
    _t114.lo = (~a.i[2].lo);
    _t114.up = (~a.i[2].up);
    tmp.i[2] = _ia_and_u32(_t114, b.i[2]);
    u32_I _t115;
    _t115.lo = (~a.i[3].lo);
    _t115.up = (~a.i[3].up);
    tmp.i[3] = _ia_and_u32(_t115, b.i[3]);
    u32_I _t116;
    _t116.lo = (~a.i[4].lo);
    _t116.up = (~a.i[4].up);
    tmp.i[4] = _ia_and_u32(_t116, b.i[4]);
    u32_I _t117;
    _t117.lo = (~a.i[5].lo);
    _t117.up = (~a.i[5].up);
    tmp.i[5] = _ia_and_u32(_t117, b.i[5]);
    u32_I _t118;
    _t118.lo = (~a.i[6].lo);
    _t118.up = (~a.i[6].up);
    tmp.i[6] = _ia_and_u32(_t118, b.i[6]);
    u32_I _t119;
    _t119.lo = (~a.i[7].lo);
    _t119.up = (~a.i[7].up);
    tmp.i[7] = _ia_and_u32(_t119, b.i[7]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == vecBitAccess_s(tmp.i, 159) &&
        vecBitAccess_s(tmp.i, 159) == vecBitAccess_s(tmp.i, 191) &&
        vecBitAccess_s(tmp.i, 191) == vecBitAccess_s(tmp.i, 223) &&
        vecBitAccess_s(tmp.i, 223) == vecBitAccess_s(tmp.i, 255) &&
        vecBitAccess_s(tmp.i, 255) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    dst = CF;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm256_testnzc_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    int dst;
    vec256s tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u32(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u32(a.i[1], b.i[1]);
    tmp.i[2] = _ia_and_u32(a.i[2], b.i[2]);
    tmp.i[3] = _ia_and_u32(a.i[3], b.i[3]);
    tmp.i[4] = _ia_and_u32(a.i[4], b.i[4]);
    tmp.i[5] = _ia_and_u32(a.i[5], b.i[5]);
    tmp.i[6] = _ia_and_u32(a.i[6], b.i[6]);
    tmp.i[7] = _ia_and_u32(a.i[7], b.i[7]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == vecBitAccess_s(tmp.i, 159) &&
        vecBitAccess_s(tmp.i, 159) == vecBitAccess_s(tmp.i, 191) &&
        vecBitAccess_s(tmp.i, 191) == vecBitAccess_s(tmp.i, 223) &&
        vecBitAccess_s(tmp.i, 223) == vecBitAccess_s(tmp.i, 255) &&
        vecBitAccess_s(tmp.i, 255) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u32_I _t120;
    _t120.lo = (~a.i[0].lo);
    _t120.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u32(_t120, b.i[0]);
    u32_I _t121;
    _t121.lo = (~a.i[1].lo);
    _t121.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u32(_t121, b.i[1]);
    u32_I _t122;
    _t122.lo = (~a.i[2].lo);
    _t122.up = (~a.i[2].up);
    tmp.i[2] = _ia_and_u32(_t122, b.i[2]);
    u32_I _t123;
    _t123.lo = (~a.i[3].lo);
    _t123.up = (~a.i[3].up);
    tmp.i[3] = _ia_and_u32(_t123, b.i[3]);
    u32_I _t124;
    _t124.lo = (~a.i[4].lo);
    _t124.up = (~a.i[4].up);
    tmp.i[4] = _ia_and_u32(_t124, b.i[4]);
    u32_I _t125;
    _t125.lo = (~a.i[5].lo);
    _t125.up = (~a.i[5].up);
    tmp.i[5] = _ia_and_u32(_t125, b.i[5]);
    u32_I _t126;
    _t126.lo = (~a.i[6].lo);
    _t126.up = (~a.i[6].up);
    tmp.i[6] = _ia_and_u32(_t126, b.i[6]);
    u32_I _t127;
    _t127.lo = (~a.i[7].lo);
    _t127.up = (~a.i[7].up);
    tmp.i[7] = _ia_and_u32(_t127, b.i[7]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == vecBitAccess_s(tmp.i, 159) &&
        vecBitAccess_s(tmp.i, 159) == vecBitAccess_s(tmp.i, 191) &&
        vecBitAccess_s(tmp.i, 191) == vecBitAccess_s(tmp.i, 223) &&
        vecBitAccess_s(tmp.i, 223) == vecBitAccess_s(tmp.i, 255) &&
        vecBitAccess_s(tmp.i, 255) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    if (ZF == 0 && CF == 0) {
        dst = 1;
    } else {
        dst = 0;
    }
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_testz_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;
    vec128s tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u32(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u32(a.i[1], b.i[1]);
    tmp.i[2] = _ia_and_u32(a.i[2], b.i[2]);
    tmp.i[3] = _ia_and_u32(a.i[3], b.i[3]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u32_I _t128;
    _t128.lo = (~a.i[0].lo);
    _t128.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u32(_t128, b.i[0]);
    u32_I _t129;
    _t129.lo = (~a.i[1].lo);
    _t129.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u32(_t129, b.i[1]);
    u32_I _t130;
    _t130.lo = (~a.i[2].lo);
    _t130.up = (~a.i[2].up);
    tmp.i[2] = _ia_and_u32(_t130, b.i[2]);
    u32_I _t131;
    _t131.lo = (~a.i[3].lo);
    _t131.up = (~a.i[3].up);
    tmp.i[3] = _ia_and_u32(_t131, b.i[3]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    dst = ZF;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_testc_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;
    vec128s tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u32(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u32(a.i[1], b.i[1]);
    tmp.i[2] = _ia_and_u32(a.i[2], b.i[2]);
    tmp.i[3] = _ia_and_u32(a.i[3], b.i[3]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u32_I _t132;
    _t132.lo = (~a.i[0].lo);
    _t132.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u32(_t132, b.i[0]);
    u32_I _t133;
    _t133.lo = (~a.i[1].lo);
    _t133.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u32(_t133, b.i[1]);
    u32_I _t134;
    _t134.lo = (~a.i[2].lo);
    _t134.up = (~a.i[2].up);
    tmp.i[2] = _ia_and_u32(_t134, b.i[2]);
    u32_I _t135;
    _t135.lo = (~a.i[3].lo);
    _t135.up = (~a.i[3].up);
    tmp.i[3] = _ia_and_u32(_t135, b.i[3]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    dst = CF;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm_testnzc_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;
    vec128s tmp;
    int ZF;
    int CF;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    tmp.i[0] = _ia_and_u32(a.i[0], b.i[0]);
    tmp.i[1] = _ia_and_u32(a.i[1], b.i[1]);
    tmp.i[2] = _ia_and_u32(a.i[2], b.i[2]);
    tmp.i[3] = _ia_and_u32(a.i[3], b.i[3]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == 0) {
        ZF = 1;
    } else {
        ZF = 0;
    }
    u32_I _t136;
    _t136.lo = (~a.i[0].lo);
    _t136.up = (~a.i[0].up);
    tmp.i[0] = _ia_and_u32(_t136, b.i[0]);
    u32_I _t137;
    _t137.lo = (~a.i[1].lo);
    _t137.up = (~a.i[1].up);
    tmp.i[1] = _ia_and_u32(_t137, b.i[1]);
    u32_I _t138;
    _t138.lo = (~a.i[2].lo);
    _t138.up = (~a.i[2].up);
    tmp.i[2] = _ia_and_u32(_t138, b.i[2]);
    u32_I _t139;
    _t139.lo = (~a.i[3].lo);
    _t139.up = (~a.i[3].up);
    tmp.i[3] = _ia_and_u32(_t139, b.i[3]);

    if (vecBitAccess_s(tmp.i, 31) == vecBitAccess_s(tmp.i, 63) &&
        vecBitAccess_s(tmp.i, 63) == vecBitAccess_s(tmp.i, 95) &&
        vecBitAccess_s(tmp.i, 95) == vecBitAccess_s(tmp.i, 127) &&
        vecBitAccess_s(tmp.i, 127) == 0) {
        CF = 1;
    } else {
        CF = 0;
    }
    if (ZF == 0 && CF == 0) {
        dst = 1;
    } else {
        dst = 0;
    }
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm256_movemask_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    int dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (vecBitAccess_d(a.i, i + 63)) {
            dst = ((dst & ~(1 << (j))) | ((1) << (j)));
        } else {
            dst = ((dst & ~(1 << (j))) | ((0) << (j)));
        }
    }
    (dst) = ((dst) & (~(((1 << ((31) - (4) + 1)) - 1) << ((4))))) | ((0) << (4));
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_fb_mm256_movemask_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    int dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        if (vecBitAccess_s(a.i, i + 31)) {
            dst = ((dst & ~(1 << (j))) | ((1) << (j)));
        } else {
            dst = ((dst & ~(1 << (j))) | ((0) << (j)));
        }
    }
    (dst) = ((dst) & (~(((1 << ((31) - (8) + 1)) - 1) << ((8))))) | ((0) << (8));
    int _ret;
    _ret = dst;
    return _ret;
}

f64i_simd4 _igen_fb_mm256_setzero_pd() {
    vec256d dst;

    dst.f[0] = _ia_zero_f64();
    dst.f[1] = _ia_zero_f64();
    dst.f[2] = _ia_zero_f64();
    dst.f[3] = _ia_zero_f64();

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_setzero_ps() {
    vec256s dst;

    dst.f[0] = _ia_set_f32(0.0, 0.0);
    dst.f[1] = _ia_set_f32(0.0, 0.0);
    dst.f[2] = _ia_set_f32(0.0, 0.0);
    dst.f[3] = _ia_set_f32(0.0, 0.0);
    dst.f[4] = _ia_set_f32(0.0, 0.0);
    dst.f[5] = _ia_set_f32(0.0, 0.0);
    dst.f[6] = _ia_set_f32(0.0, 0.0);
    dst.f[7] = _ia_set_f32(0.0, 0.0);

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_set_pd(f64_I e3, f64_I e2, f64_I e1, f64_I e0) {
    vec256d dst;

    dst.f[0] = e0;
    dst.f[1] = e1;
    dst.f[2] = e2;
    dst.f[3] = e3;

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_set_ps(f32_I e7, f32_I e6, f32_I e5, f32_I e4,
                           f32_I e3, f32_I e2, f32_I e1, f32_I e0) {
    vec256s dst;

    dst.f[0] = e0;
    dst.f[1] = e1;
    dst.f[2] = e2;
    dst.f[3] = e3;
    dst.f[4] = e4;
    dst.f[5] = e5;
    dst.f[6] = e6;
    dst.f[7] = e7;

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_setr_pd(f64_I e3, f64_I e2, f64_I e1,
                            f64_I e0) {
    vec256d dst;

    dst.f[0] = e3;
    dst.f[1] = e2;
    dst.f[2] = e1;
    dst.f[3] = e0;

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_setr_ps(f32_I e7, f32_I e6, f32_I e5, f32_I e4,
                            f32_I e3, f32_I e2, f32_I e1, f32_I e0) {
    vec256s dst;

    dst.f[0] = e7;
    dst.f[1] = e6;
    dst.f[2] = e5;
    dst.f[3] = e4;
    dst.f[4] = e3;
    dst.f[5] = e2;
    dst.f[6] = e1;
    dst.f[7] = e0;

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_set1_pd(f64_I a) {
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = a;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_set1_ps(f32_I a) {
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = a;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_castpd_ps(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

f64i_simd4 _igen_fb_mm256_castps_pd(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

__m256i _igen_fb_mm256_castps_si256(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256i dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    __m256i _ret;
    _ret = dst.v;
    return _ret;
}

__m256i _igen_fb_mm256_castpd_si256(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256i dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    __m256i _ret;
    _ret = dst.v;
    return _ret;
}

f32i_simd8 _igen_fb_mm256_castsi256_ps(__m256i _a) {
    vec256i a;
    a.v = _a;
    vec256s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

f64i_simd4 _igen_fb_mm256_castsi256_pd(__m256i _a) {
    vec256i a;
    a.v = _a;
    vec256d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

f32i_simd4 _igen_fb_mm256_castps256_ps128(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec128s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

f64i_simd2 _igen_fb_mm256_castpd256_pd128(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec128d dst;

    union {
        vec128d v128;
        vec256d v256;
    } castVec;

    castVec.v256 = a;
    dst = castVec.v128;

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_castps128_ps256(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec256s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

f64i_simd4 _igen_fb_mm256_castpd128_pd256(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec256d dst;

    union {
        vec128d v128;
        vec256d v256;
    } castVec;

    castVec.v128 = a;
    dst = castVec.v256;

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_zextps128_ps256(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec256s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

f64i_simd4 _igen_fb_mm256_zextpd128_pd256(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec256d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

f32i_simd8 _igen_fb_mm256_floor_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = FLOOR_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_ceil_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = CEIL_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_floor_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = FLOOR_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_ceil_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = CEIL_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_undefined_ps() {
    vec128s dst;

    return dst.v;
}

f64i_simd2 _igen_fb_mm_undefined_pd() {
    vec128d dst;

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_undefined_ps() {
    vec256s dst;

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_undefined_pd() {
    vec256d dst;

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_set_m128(f32i_simd4 _hi, f32i_simd4 _lo) {
    vec128s hi;
    hi.v = _hi;
    vec128s lo;
    lo.v = _lo;
    vec256s dst;

    dst.f[0] = lo.f[0];
    dst.f[1] = lo.f[1];
    dst.f[2] = lo.f[2];
    dst.f[3] = lo.f[3];

    dst.f[4] = hi.f[0];
    dst.f[5] = hi.f[1];
    dst.f[6] = hi.f[2];
    dst.f[7] = hi.f[3];

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_set_m128d(f64i_simd2 _hi, f64i_simd2 _lo) {
    vec128d hi;
    hi.v = _hi;
    vec128d lo;
    lo.v = _lo;
    vec256d dst;

    dst.f[0] = lo.f[0];
    dst.f[1] = lo.f[1];

    dst.f[2] = hi.f[0];
    dst.f[3] = hi.f[1];

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_setr_m128(f32i_simd4 _lo, f32i_simd4 _hi) {
    vec128s lo;
    lo.v = _lo;
    vec128s hi;
    hi.v = _hi;
    vec256s dst;

    dst.f[0] = lo.f[0];
    dst.f[1] = lo.f[1];
    dst.f[2] = lo.f[2];
    dst.f[3] = lo.f[3];

    dst.f[4] = hi.f[0];
    dst.f[5] = hi.f[1];
    dst.f[6] = hi.f[2];
    dst.f[7] = hi.f[3];

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_setr_m128d(f64i_simd2 _lo, f64i_simd2 _hi) {
    vec128d lo;
    lo.v = _lo;
    vec128d hi;
    hi.v = _hi;
    vec256d dst;

    dst.f[0] = lo.f[0];
    dst.f[1] = lo.f[1];

    dst.f[2] = hi.f[0];
    dst.f[3] = hi.f[1];

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_loadu2_m128(const f32_I *hiaddr, const f32_I *loaddr) {
    vec256s dst;

    dst.f[0] = *(loaddr + 0);
    dst.f[1] = *(loaddr + 1);
    dst.f[2] = *(loaddr + 2);
    dst.f[3] = *(loaddr + 3);

    dst.f[4] = *(hiaddr + 0);
    dst.f[5] = *(hiaddr + 1);
    dst.f[6] = *(hiaddr + 2);
    dst.f[7] = *(hiaddr + 3);

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_loadu2_m128d(const f64_I *hiaddr,
                                 const f64_I *loaddr) {
    vec256d dst;

    dst.f[0] = *(loaddr + 0);
    dst.f[1] = *(loaddr + 1);

    dst.f[2] = *(hiaddr + 0);
    dst.f[3] = *(hiaddr + 1);

    return dst.v;
}

void _igen_fb_mm256_storeu2_m128(f32_I *hiaddr, f32_I *loaddr, f32i_simd8 _a) {
    vec256s a;
    a.v = _a;

    *(loaddr + 0) = a.f[0];
    *(loaddr + 1) = a.f[1];
    *(loaddr + 2) = a.f[2];
    *(loaddr + 3) = a.f[3];

    *(hiaddr + 0) = a.f[4];
    *(hiaddr + 1) = a.f[5];
    *(hiaddr + 2) = a.f[6];
    *(hiaddr + 3) = a.f[7];

}

void _igen_fb_mm256_storeu2_m128d(f64_I *hiaddr, f64_I *loaddr, f64i_simd4 _a) {
    vec256d a;
    a.v = _a;

    *(loaddr + 0) = a.f[0];
    *(loaddr + 1) = a.f[1];

    *(hiaddr + 0) = a.f[2];
    *(hiaddr + 1) = a.f[3];

}

f64i_simd2 _igen_fb_mm_broadcastsd_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = a.f[0];
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_broadcastsd_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = a.f[0];
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_broadcastss_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = a.f[0];
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_broadcastss_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = a.f[0];
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_i32gather_pd(const f64_I *base_addr, __m128i _vindex,
                              int scale) {
    vec128i vindex;
    vindex.v = _vindex;
    vec128d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        m = j * 32;
        dst.f[i / 64] = *(
                base_addr +
                ((base_addr + SignExtend_i(vindex.i[m / 32]) * scale - base_addr) / 8));
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_i32gather_pd(const f64_I *base_addr, __m128i _vindex,
                                 int scale) {
    vec128i vindex;
    vindex.v = _vindex;
    vec256d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        m = j * 32;
        dst.f[i / 64] = *(
                base_addr +
                ((base_addr + SignExtend_i(vindex.i[m / 32]) * scale - base_addr) / 8));
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_i32gather_ps(const f32_I *base_addr, __m128i _vindex,
                              int scale) {
    vec128i vindex;
    vindex.v = _vindex;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        m = j * 32;
        dst.f[i / 32] = *(
                base_addr +
                ((base_addr + SignExtend_i(vindex.i[i / 32]) * scale - base_addr) / 4));
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_i32gather_ps(const f32_I *base_addr, __m256i _vindex,
                                 int scale) {
    vec256i vindex;
    vindex.v = _vindex;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = *(
                base_addr +
                ((base_addr + SignExtend_i(vindex.i[i / 32]) * scale - base_addr) / 4));
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_i64gather_pd(const f64_I *base_addr, __m128i _vindex,
                              int scale) {
    vec128i vindex;
    vindex.v = _vindex;
    vec128d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        m = j * 64;
        dst.f[i / 64] =
                *(base_addr +
                  ((base_addr + SignExtend_i(vindex.l[(m) / 64]) * scale - base_addr) /
                   8));
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_i64gather_pd(const f64_I *base_addr, __m256i _vindex,
                                 int scale) {
    vec256i vindex;
    vindex.v = _vindex;
    vec256d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        m = j * 64;
        dst.f[i / 64] =
                *(base_addr +
                  ((base_addr + SignExtend_i(vindex.l[(m) / 64]) * scale - base_addr) /
                   8));
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_i64gather_ps(const f32_I *base_addr, __m128i _vindex,
                              int scale) {
    vec128i vindex;
    vindex.v = _vindex;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 1; ++j) {
        i = j * 32;
        m = j * 64;
        dst.f[i / 32] =
                *(base_addr +
                  ((base_addr + SignExtend_i(vindex.l[(m) / 64]) * scale - base_addr) /
                   4));
    }
    dst.f[2] = _ia_set_f32(0.0, 0.0);
    dst.f[3] = _ia_set_f32(0.0, 0.0);

    return dst.v;
}

f32i_simd4 _igen_fb_mm256_i64gather_ps(const f32_I *base_addr, __m256i _vindex,
                                 int scale) {
    vec256i vindex;
    vindex.v = _vindex;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        m = j * 64;
        dst.f[i / 32] =
                *(base_addr +
                  ((base_addr + SignExtend_i(vindex.l[(m) / 64]) * scale - base_addr) /
                   4));
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_mask_i32gather_pd(f64i_simd2 _src, const f64_I *base_addr,
                                   __m128i _vindex, f64i_simd2 _mask, int scale) {
    vec128d src;
    src.v = _src;
    vec128i vindex;
    vindex.v = _vindex;
    vec128d mask;
    mask.v = _mask;
    vec128d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        m = j * 32;
        if (vecBitAccess_d(mask.i, i + 63)) {
            dst.f[i / 64] =
                    *(base_addr +
                      ((base_addr + SignExtend_i(vindex.i[m / 32]) * scale - base_addr) /
                       8));
            vecBitAssign_d(mask.i, i + 63, 0);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_mask_i32gather_pd(f64i_simd4 _src, const f64_I *base_addr,
                                      __m128i _vindex, f64i_simd4 _mask,
                                      int scale) {
    vec256d src;
    src.v = _src;
    vec128i vindex;
    vindex.v = _vindex;
    vec256d mask;
    mask.v = _mask;
    vec256d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        m = j * 32;
        if (vecBitAccess_d(mask.i, i + 63)) {
            dst.f[i / 64] =
                    *(base_addr +
                      ((base_addr + SignExtend_i(vindex.i[m / 32]) * scale - base_addr) /
                       8));
            vecBitAssign_d(mask.i, i + 63, 0);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_mask_i32gather_ps(f32i_simd4 _src, const f32_I *base_addr,
                                   __m128i _vindex, f32i_simd4 _mask, int scale) {
    vec128s src;
    src.v = _src;
    vec128i vindex;
    vindex.v = _vindex;
    vec128s mask;
    mask.v = _mask;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (vecBitAccess_s(mask.i, i + 31)) {
            dst.f[i / 32] =
                    *(base_addr +
                      ((base_addr + SignExtend_i(vindex.i[i / 32]) * scale - base_addr) /
                       4));
            vecBitAssign_s(mask.i, i + 31, 0);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_mask_i32gather_ps(f32i_simd8 _src, const f32_I *base_addr,
                                      __m256i _vindex, f32i_simd8 _mask,
                                      int scale) {
    vec256s src;
    src.v = _src;
    vec256i vindex;
    vindex.v = _vindex;
    vec256s mask;
    mask.v = _mask;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        if (vecBitAccess_s(mask.i, i + 31)) {
            dst.f[i / 32] =
                    *(base_addr +
                      ((base_addr + SignExtend_i(vindex.i[i / 32]) * scale - base_addr) /
                       4));
            vecBitAssign_s(mask.i, i + 31, 0);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_mask_i64gather_pd(f64i_simd2 _src, const f64_I *base_addr,
                                   __m128i _vindex, f64i_simd2 _mask, int scale) {
    vec128d src;
    src.v = _src;
    vec128i vindex;
    vindex.v = _vindex;
    vec128d mask;
    mask.v = _mask;
    vec128d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        m = j * 64;
        if (vecBitAccess_d(mask.i, i + 63)) {
            dst.f[i / 64] = *(
                    base_addr +
                    ((base_addr + SignExtend_i(vindex.l[(m) / 64]) * scale - base_addr) /
                     8));
            vecBitAssign_d(mask.i, i + 63, 0);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_mask_i64gather_pd(f64i_simd4 _src, const f64_I *base_addr,
                                      __m256i _vindex, f64i_simd4 _mask,
                                      int scale) {
    vec256d src;
    src.v = _src;
    vec256i vindex;
    vindex.v = _vindex;
    vec256d mask;
    mask.v = _mask;
    vec256d dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        m = j * 64;
        if (vecBitAccess_d(mask.i, i + 63)) {
            dst.f[i / 64] = *(
                    base_addr +
                    ((base_addr + SignExtend_i(vindex.l[(m) / 64]) * scale - base_addr) /
                     8));
            vecBitAssign_d(mask.i, i + 63, 0);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_mask_i64gather_ps(f32i_simd4 _src, const f32_I *base_addr,
                                   __m128i _vindex, f32i_simd4 _mask, int scale) {
    vec128s src;
    src.v = _src;
    vec128i vindex;
    vindex.v = _vindex;
    vec128s mask;
    mask.v = _mask;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 1; ++j) {
        i = j * 32;
        m = j * 64;
        if (vecBitAccess_s(mask.i, i + 31)) {
            dst.f[i / 32] = *(
                    base_addr +
                    ((base_addr + SignExtend_i(vindex.l[(m) / 64]) * scale - base_addr) /
                     4));
            vecBitAssign_s(mask.i, i + 31, 0);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }
    mask.f[2].lo = -0.0;
    mask.f[2].up = 0.0;
    mask.f[3].lo = -0.0;
    mask.f[3].up = 0.0;

    dst.f[2] = _ia_set_f32(0.0, 0.0);
    dst.f[3] = _ia_set_f32(0.0, 0.0);

    return dst.v;
}

f32i_simd4 _igen_fb_mm256_mask_i64gather_ps(f32i_simd4 _src, const f32_I *base_addr,
                                      __m256i _vindex, f32i_simd4 _mask,
                                      int scale) {
    vec128s src;
    src.v = _src;
    vec256i vindex;
    vindex.v = _vindex;
    vec128s mask;
    mask.v = _mask;
    vec128s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        m = j * 64;
        if (vecBitAccess_s(mask.i, i + 31)) {
            dst.f[i / 32] = *(
                    base_addr +
                    ((base_addr + SignExtend_i(vindex.l[(m) / 64]) * scale - base_addr) /
                     4));
            vecBitAssign_s(mask.i, i + 31, 0);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_permute4x64_pd(f64i_simd4 _a, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d dst;

    dst.f[0] = SELECT4_di(&a.f[0], (((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1)));
    dst.f[1] = SELECT4_di(&a.f[0], (((imm8) >> (2)) & ((1 << (3 - 2 + 1)) - 1)));
    dst.f[2] = SELECT4_di(&a.f[0], (((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1)));
    dst.f[3] = SELECT4_di(&a.f[0], (((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1)));

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_permutevar8x32_ps(f32i_simd8 _a, __m256i _idx) {
    vec256s a;
    a.v = _a;
    vec256i idx;
    idx.v = _idx;
    vec256s dst;
    int j;
    int i;
    int id;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        id = vecBitsAccess_i(idx.i, i + 2, i) * 32;
        dst.f[i / 32] = a.f[id / 32];
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fmadd_pd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        u_f64i _t140;
        _t140.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
        dst.ff[i / 64].lo = _t140.lo + c.ff[i / 64].lo;
        dst.ff[i / 64].up = _t140.up + c.ff[i / 64].up;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_fmadd_pd(f64i_simd4 _a, f64i_simd4 _b, f64i_simd4 _c) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d c;
    c.v = _c;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        u_f64i _t141;
        _t141.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
        dst.ff[i / 64].lo = _t141.lo + c.ff[i / 64].lo;
        dst.ff[i / 64].up = _t141.up + c.ff[i / 64].up;
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fmadd_ps(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t142 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32].lo = _t142.lo + c.f[i / 32].lo;
        dst.f[i / 32].up = _t142.up + c.f[i / 32].up;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_fmadd_ps(f32i_simd8 _a, f32i_simd8 _b, f32i_simd8 _c) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s c;
    c.v = _c;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t143 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32].lo = _t143.lo + c.f[i / 32].lo;
        dst.f[i / 32].up = _t143.up + c.f[i / 32].up;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fmadd_sd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;

    u_f64i _t144;
    _t144.v = _ia_mul_f64(a.f[0], b.f[0]);
    dst.ff[0].lo = _t144.lo + c.ff[0].lo;
    dst.ff[0].up = _t144.up + c.ff[0].up;
    dst.f[1] = a.f[1];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fmadd_ss(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;

    f32_I _t145 = _ia_mul_f32(a.f[0], b.f[0]);
    dst.f[0].lo = _t145.lo + c.f[0].lo;
    dst.f[0].up = _t145.up + c.f[0].up;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fmaddsub_pd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        if (j % 1 == 0) {
            u_f64i _t146;
            _t146.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
            dst.ff[i / 64].lo = _t146.lo + c.ff[i / 64].up;
            dst.ff[i / 64].up = _t146.up + c.ff[i / 64].lo;
        } else {
            u_f64i _t147;
            _t147.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
            dst.ff[i / 64].lo = _t147.lo + c.ff[i / 64].lo;
            dst.ff[i / 64].up = _t147.up + c.ff[i / 64].up;
        }
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_fmaddsub_pd(f64i_simd4 _a, f64i_simd4 _b, f64i_simd4 _c) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d c;
    c.v = _c;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (j % 1 == 0) {
            u_f64i _t148;
            _t148.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
            dst.ff[i / 64].lo = _t148.lo + c.ff[i / 64].up;
            dst.ff[i / 64].up = _t148.up + c.ff[i / 64].lo;
        } else {
            u_f64i _t149;
            _t149.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
            dst.ff[i / 64].lo = _t149.lo + c.ff[i / 64].lo;
            dst.ff[i / 64].up = _t149.up + c.ff[i / 64].up;
        }
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fmaddsub_ps(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (j % 1 == 0) {
            f32_I _t150 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32].lo = _t150.lo + c.f[i / 32].up;
            dst.f[i / 32].up = _t150.up + c.f[i / 32].lo;
        } else {
            f32_I _t151 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32].lo = _t151.lo + c.f[i / 32].lo;
            dst.f[i / 32].up = _t151.up + c.f[i / 32].up;
        }
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_fmaddsub_ps(f32i_simd8 _a, f32i_simd8 _b, f32i_simd8 _c) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s c;
    c.v = _c;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        if (j % 1 == 0) {
            f32_I _t152 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32].lo = _t152.lo + c.f[i / 32].up;
            dst.f[i / 32].up = _t152.up + c.f[i / 32].lo;
        } else {
            f32_I _t153 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32].lo = _t153.lo + c.f[i / 32].lo;
            dst.f[i / 32].up = _t153.up + c.f[i / 32].up;
        }
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fmsub_pd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        u_f64i _t154;
        _t154.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
        dst.ff[i / 64].lo = _t154.lo + c.ff[i / 64].up;
        dst.ff[i / 64].up = _t154.up + c.ff[i / 64].lo;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_fmsub_pd(f64i_simd4 _a, f64i_simd4 _b, f64i_simd4 _c) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d c;
    c.v = _c;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        u_f64i _t155;
        _t155.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
        dst.ff[i / 64].lo = _t155.lo + c.ff[i / 64].up;
        dst.ff[i / 64].up = _t155.up + c.ff[i / 64].lo;
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fmsub_ps(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t156 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32].lo = _t156.lo + c.f[i / 32].up;
        dst.f[i / 32].up = _t156.up + c.f[i / 32].lo;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_fmsub_ps(f32i_simd8 _a, f32i_simd8 _b, f32i_simd8 _c) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s c;
    c.v = _c;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t157 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32].lo = _t157.lo + c.f[i / 32].up;
        dst.f[i / 32].up = _t157.up + c.f[i / 32].lo;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fmsub_sd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;

    u_f64i _t158;
    _t158.v = _ia_mul_f64(a.f[0], b.f[0]);
    dst.ff[0].lo = _t158.lo + c.ff[0].up;
    dst.ff[0].up = _t158.up + c.ff[0].lo;
    dst.f[1] = a.f[1];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fmsub_ss(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;

    f32_I _t159 = _ia_mul_f32(a.f[0], b.f[0]);
    dst.f[0].lo = _t159.lo + c.f[0].up;
    dst.f[0].up = _t159.up + c.f[0].lo;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fmsubadd_pd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        if (j % 1 == 0) {
            u_f64i _t160;
            _t160.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
            dst.ff[i / 64].lo = _t160.lo + c.ff[i / 64].lo;
            dst.ff[i / 64].up = _t160.up + c.ff[i / 64].up;
        } else {
            u_f64i _t161;
            _t161.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
            dst.ff[i / 64].lo = _t161.lo + c.ff[i / 64].up;
            dst.ff[i / 64].up = _t161.up + c.ff[i / 64].lo;
        }
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_fmsubadd_pd(f64i_simd4 _a, f64i_simd4 _b, f64i_simd4 _c) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d c;
    c.v = _c;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (j % 1 == 0) {
            u_f64i _t162;
            _t162.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
            dst.ff[i / 64].lo = _t162.lo + c.ff[i / 64].lo;
            dst.ff[i / 64].up = _t162.up + c.ff[i / 64].up;
        } else {
            u_f64i _t163;
            _t163.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
            dst.ff[i / 64].lo = _t163.lo + c.ff[i / 64].up;
            dst.ff[i / 64].up = _t163.up + c.ff[i / 64].lo;
        }
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fmsubadd_ps(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        if (j % 1 == 0) {
            f32_I _t164 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32].lo = _t164.lo + c.f[i / 32].lo;
            dst.f[i / 32].up = _t164.up + c.f[i / 32].up;
        } else {
            f32_I _t165 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32].lo = _t165.lo + c.f[i / 32].up;
            dst.f[i / 32].up = _t165.up + c.f[i / 32].lo;
        }
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_fmsubadd_ps(f32i_simd8 _a, f32i_simd8 _b, f32i_simd8 _c) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s c;
    c.v = _c;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        if (j % 1 == 0) {
            f32_I _t166 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32].lo = _t166.lo + c.f[i / 32].lo;
            dst.f[i / 32].up = _t166.up + c.f[i / 32].up;
        } else {
            f32_I _t167 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32].lo = _t167.lo + c.f[i / 32].up;
            dst.f[i / 32].up = _t167.up + c.f[i / 32].lo;
        }
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fnmadd_pd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        u_f64i _t168;
        _t168.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
        dst.ff[i / 64].lo = _t168.up + c.ff[i / 64].lo;
        dst.ff[i / 64].up = _t168.lo + c.ff[i / 64].up;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_fnmadd_pd(f64i_simd4 _a, f64i_simd4 _b, f64i_simd4 _c) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d c;
    c.v = _c;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        u_f64i _t169;
        _t169.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
        dst.ff[i / 64].lo = _t169.up + c.ff[i / 64].lo;
        dst.ff[i / 64].up = _t169.lo + c.ff[i / 64].up;
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fnmadd_ps(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t170 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
        a.f[i / 32].lo = _t170.up + c.f[i / 32].lo;
        a.f[i / 32].up = _t170.lo + c.f[i / 32].up;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_fnmadd_ps(f32i_simd8 _a, f32i_simd8 _b, f32i_simd8 _c) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s c;
    c.v = _c;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t171 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
        a.f[i / 32].lo = _t171.up + c.f[i / 32].lo;
        a.f[i / 32].up = _t171.lo + c.f[i / 32].up;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fnmadd_sd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;

    u_f64i _t172;
    _t172.v = _ia_mul_f64(a.f[0], b.f[0]);
    dst.ff[0].lo = _t172.up + c.ff[0].lo;
    dst.ff[0].up = _t172.lo + c.ff[0].up;
    dst.f[1] = a.f[1];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fnmadd_ss(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;

    f32_I _t173 = _ia_mul_f32(a.f[0], b.f[0]);
    dst.f[0].lo = _t173.up + c.f[0].lo;
    dst.f[0].up = _t173.lo + c.f[0].up;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fnmsub_pd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        u_f64i _t174;
        _t174.v = _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
        dst.ff[i / 64].lo = _t174.up + c.ff[i / 64].up;
        dst.ff[i / 64].up = _t174.lo + c.ff[i / 64].lo;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_fnmsub_pd(f64i_simd4 _a, f64i_simd4 _b, f64i_simd4 _c) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d c;
    c.v = _c;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        u_f64i _t175;
        _t175.v= _ia_mul_f64(a.f[i / 64], b.f[i / 64]);
        dst.ff[i / 64].lo = _t175.up + c.ff[i / 64].up;
        dst.ff[i / 64].up = _t175.lo + c.ff[i / 64].lo;
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fnmsub_ps(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t176 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32].lo = _t176.up + c.f[i / 32].up;
        dst.f[i / 32].up = _t176.lo + c.f[i / 32].lo;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_fnmsub_ps(f32i_simd8 _a, f32i_simd8 _b, f32i_simd8 _c) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s c;
    c.v = _c;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t177 = _ia_mul_f32(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32].lo = _t177.up + c.f[i / 32].up;
        dst.f[i / 32].up = _t177.lo + c.f[i / 32].lo;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_fnmsub_sd(f64i_simd2 _a, f64i_simd2 _b, f64i_simd2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;

    u_f64i _t178;
    _t178.v = _ia_mul_f64(a.f[0], b.f[0]);
    dst.ff[0].lo = _t178.up + c.ff[0].up;
    dst.ff[0].up = _t178.lo + c.ff[0].lo;
    dst.f[1] = a.f[1];

    return dst.v;
}

f32i_simd4 _igen_fb_mm_fnmsub_ss(f32i_simd4 _a, f32i_simd4 _b, f32i_simd4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;

    f32_I _t179 = _ia_mul_f32(a.f[0], b.f[0]);
    dst.f[0].lo = _t179.up + c.f[0].up;
    dst.f[0].up = _t179.lo + c.f[0].lo;
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

unsigned int _igen_fb_castf32_u32(f32_I a) {
    unsigned int dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    unsigned int _ret;
    _ret = dst;
    return _ret;
}

long _igen_fb_castf64_u64(f64_I a) {
    long dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    long _ret;
    _ret = dst;
    return _ret;
}

f32_I _igen_fb_castu32_f32(unsigned int a) {
    f32_I dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst;
}

f64_I _igen_fb_castu64_f64(long a) {
    f64_I dst;

    return dst;
}

f64i_simd2 _igen_fb_mm_acos_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ACOS_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_acos_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ACOS_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_acosh_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ACOSH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_acosh_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ACOSH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_asin_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ASIN_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_asin_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ASIN_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_asinh_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ASINH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_asinh_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ASINH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_atan_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ATAN_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_atan_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ATAN_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_atan2_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        f64_I _t180 = _ia_div_f64(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = ATAN_d(_t180);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_atan2_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t181 = _ia_div_f32(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = ATAN_s(_t181);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_atanh_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ATANH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_atanh_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ATANH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cbrt_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = CubeRoot_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cbrt_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = CubeRoot_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cdfnorm_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = CDFNormal_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cdfnorm_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = CDFNormal_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cdfnorminv_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = InverseCDFNormal_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cdfnorminv_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = InverseCDFNormal_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cexp_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = expe_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_clog_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ln_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cos_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = COS_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cos_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = COS_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cosd_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = COSD_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cosd_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = COSD_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_cosh_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = COSH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_cosh_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = COSH_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_csqrt_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = SQRT_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_erf_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ERF_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_erf_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ERF_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_erfc_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        u_f64i _t182;
        _t182.v = ERF_d(a.f[i / 64]);
        dst.ff[i / 64].lo = -1.0 + _t182.up;
        dst.ff[i / 64].up = 1.0 + _t182.lo;
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_erfc_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t183 = ERF_s(a.f[i / 32]);
        dst.f[i / 32].lo = -1.0 + _t183.up;
        dst.f[i / 32].up = 1.0 + _t183.lo;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_erfcinv_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        u_f64i _t184;
        _t184.v = ERF_d(a.f[i / 64]);
        u_f64i _t185;
        _t185.lo = -1.0;
        _t185.up = 1.0;
        u_f64i _t186;
        _t186.lo = (-1.0 + _t184.up);
        _t186.up = (1.0 + _t184.lo);
        dst.f[i / 64] = _ia_div_f64(_t185.v, _t186.v);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_erfcinv_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t187 = ERF_s(a.f[i / 32]);
        f32_I _t188;
        _t188.lo = -1.0;
        _t188.up = 1.0;
        f32_I _t189;
        _t189.lo = (-1.0 + _t187.up);
        _t189.up = (1.0 + _t187.lo);
        f32_I _t190 = _ia_div_f32(_t188, _t189);
        dst.f[i / 32].lo = _t190.lo;
        dst.f[i / 32].up = _t190.up;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_erfinv_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        f64_I _t191 = _ia_one_f64();
        f64_I _t192 = ERF_d(a.f[i / 64]);
        dst.f[i / 64] = _ia_div_f64(_t191, _t192);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_erfinv_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t193 = ERF_s(a.f[i / 32]);
        f32_I _t194;
        _t194.lo = -1.0;
        _t194.up = 1.0;
        f32_I _t195;
        _t195.lo = _t193.lo;
        _t195.up = _t193.up;
        f32_I _t196 = _ia_div_f32(_t194, _t195);
        dst.f[i / 32].lo = _t196.lo;
        dst.f[i / 32].up = _t196.up;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_exp_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = expe_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_exp_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = expe_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_exp10_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = exp10_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_exp10_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = exp10_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_exp2_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = exp2_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_exp2_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = exp2_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_expm1_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        u_f64i _t197;
        _t197.v = expe_d(a.f[i / 64]);
        dst.ff[i / 64].lo = _t197.lo + 1.0;
        dst.ff[i / 64].up = _t197.up + -1.0;
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_expm1_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t198 = expe_s(a.f[i / 32]);
        dst.f[i / 32].lo = _t198.lo + 1.0;
        dst.f[i / 32].up = _t198.up + -1.0;
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_hypot_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        f64_I _t199 = _ia_mul_f64(a.f[i / 64], a.f[i / 64]);
        f64_I _t200 = _ia_mul_f64(b.f[i / 64], b.f[i / 64]);
        f64_I _t201 = _ia_add_f64(_t199, _t200);
        dst.f[i / 64] = SQRT_d(_t201);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_hypot_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t202 = _ia_mul_f32(a.f[i / 32], a.f[i / 32]);
        f32_I _t203 = _ia_mul_f32(b.f[i / 32], b.f[i / 32]);
        f32_I _t204;
        _t204.lo = _t202.lo + _t203.lo;
        _t204.up = _t202.up + _t203.up;
        dst.f[i / 32] = SQRT_s(_t204);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_invcbrt_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = InvCubeRoot_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_invcbrt_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = InvCubeRoot_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_invsqrt_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = InvSQRT_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_invsqrt_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = InvSQRT_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_log_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ln_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_log_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ln_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_log10_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = log10_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_log10_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = log10_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_log1p_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        u_f64i _t205;
        _t205.lo = -1.0 + a.ff[i / 64].lo;
        _t205.up = 1.0 + a.ff[i / 64].up;
        dst.f[i / 64] = ln_d(_t205.v);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_log1p_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        f32_I _t206;
        _t206.lo = -1.0 + a.f[i / 32].lo;
        _t206.up = 1.0 + a.f[i / 32].up;
        dst.f[i / 32] = ln_s(_t206);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_log2_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = log2_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_log2_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = log2_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_logb_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ConvertExpFP64_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_logb_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ConvertExpFP32_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_pow_pd(f64i_simd2 _a, f64i_simd2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = pow_d(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_pow_ps(f32i_simd4 _a, f32i_simd4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = pow_s(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_sin_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = SIN_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_sin_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = SIN_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_sincos_pd(f64i_simd2 *_mem_addr, f64i_simd2 _a) {
    vec128d *mem_addr = (vec128d *)_mem_addr;
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = SIN_d(a.f[i / 64]);
        mem_addr->f[i / 128] = COS_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_sincos_ps(f32i_simd4 *_mem_addr, f32i_simd4 _a) {
    vec128s *mem_addr = (vec128s *)_mem_addr;
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = SIN_s(a.f[i / 32]);
        mem_addr->f[i / 32] = COS_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_sind_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = SIND_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_sind_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = SIND_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_sinh_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = SINH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_sinh_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = SINH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_svml_ceil_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = CEIL_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_svml_ceil_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = CEIL_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_svml_floor_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = FLOOR_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_svml_floor_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = FLOOR_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_svml_round_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = ROUND_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_svml_round_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = ROUND_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_svml_sqrt_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = SQRT_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_svml_sqrt_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = SQRT_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_tan_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = TAN_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_tan_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = TAN_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_tand_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = TAND_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_tand_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = TAND_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_tanh_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = TANH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_tanh_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = TANH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd2 _igen_fb_mm_trunc_pd(f64i_simd2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = TRUNCATE_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd4 _igen_fb_mm_trunc_ps(f32i_simd4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = TRUNCATE_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_acos_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ACOS_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_acos_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ACOS_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_acosh_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ACOSH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_acosh_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ACOSH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_asin_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ASIN_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_asin_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ASIN_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_asinh_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ASINH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_asinh_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ASINH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_atan_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ATAN_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_atan_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ATAN_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_atan2_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        f64_I _t207 = _ia_div_f64(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = ATAN_d(_t207);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_atan2_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t208 = _ia_div_f32(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = ATAN_s(_t208);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_atanh_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ATANH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_atanh_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ATANH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_cbrt_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = CubeRoot_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cbrt_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = CubeRoot_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_cdfnorm_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = CDFNormal_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cdfnorm_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = CDFNormal_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_cdfnorminv_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = InverseCDFNormal_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cdfnorminv_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = InverseCDFNormal_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cexp_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = expe_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_clog_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ln_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_cos_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = COS_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cos_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = COS_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_cosd_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = COSD_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cosd_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = COSD_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_cosh_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = COSH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cosh_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = COSH_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_csqrt_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = SQRT_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_erf_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ERF_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_erf_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ERF_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_erfc_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        u_f64i _t209;
        _t209.v = ERF_d(a.f[i / 64]);
        dst.ff[i / 64].lo = -1.0 + _t209.up;
        dst.ff[i / 64].up = 1.0 + _t209.lo;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_erfc_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t210 = ERF_s(a.f[i / 32]);
        dst.f[i / 32].lo = -1.0 + _t210.up;
        dst.f[i / 32].up = 1.0 + _t210.lo;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_erfcinv_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        u_f64i _t211;
        _t211.v = ERF_d(a.f[i / 64]);
        u_f64i _t212;
        _t212.v = _ia_one_f64();
        u_f64i _t213;
        _t213.lo = (-1.0 + _t211.up);
        _t213.up = (1.0 + _t211.lo);
        dst.f[i / 64] = _ia_div_f64(_t212.v, _t213.v);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_erfcinv_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t214 = ERF_s(a.f[i / 32]);
        f32_I _t215;
        _t215.lo = -1.0;
        _t215.up = 1.0;
        f32_I _t216;
        _t216.lo = (-1.0 + _t214.up);
        _t216.up = (1.0 + _t214.lo);
        f32_I _t217 = _ia_div_f32(_t215, _t216);
        dst.f[i / 32].lo = _t217.lo;
        dst.f[i / 32].up = _t217.up;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_erfinv_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        f64_I _t218 = _ia_one_f64();
        f64_I _t219 = ERF_d(a.f[i / 64]);
        dst.f[i / 64] = _ia_div_f64(_t218, _t219);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_erfinv_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t220 = ERF_s(a.f[i / 32]);
        f32_I _t221;
        _t221.lo = -1.0;
        _t221.up = 1.0;
        f32_I _t222;
        _t222.lo = _t220.lo;
        _t222.up = _t220.up;
        f32_I _t223 = _ia_div_f32(_t221, _t222);
        dst.f[i / 32].lo = _t223.lo;
        dst.f[i / 32].up = _t223.up;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_exp_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = expe_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_exp_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = expe_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_exp10_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = exp10_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_exp10_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = exp10_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_exp2_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = exp2_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_exp2_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = exp2_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_expm1_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        u_f64i _t224;
        _t224.v = expe_d(a.f[i / 64]);
        dst.ff[i / 64].lo = _t224.lo + 1.0;
        dst.ff[i / 64].up = _t224.up + -1.0;
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_expm1_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t225 = expe_s(a.f[i / 32]);
        dst.f[i / 32].lo = _t225.lo + 1.0;
        dst.f[i / 32].up = _t225.up + -1.0;
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_hypot_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        f64_I _t226 = _ia_mul_f64(a.f[i / 64], a.f[i / 64]);
        f64_I _t227 = _ia_mul_f64(b.f[i / 64], b.f[i / 64]);
        f64_I _t228 = _ia_add_f64(_t226, _t227);
        dst.f[i / 64] = SQRT_d(_t228);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_hypot_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t229 = _ia_mul_f32(a.f[i / 32], a.f[i / 32]);
        f32_I _t230 = _ia_mul_f32(b.f[i / 32], b.f[i / 32]);
        f32_I _t231;
        _t231.lo = _t229.lo + _t230.lo;
        _t231.up = _t229.up + _t230.up;
        dst.f[i / 32] = SQRT_s(_t231);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_invcbrt_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = InvCubeRoot_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_invcbrt_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = InvCubeRoot_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_invsqrt_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = InvSQRT_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_invsqrt_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = InvSQRT_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_log_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ln_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_log_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ln_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_log10_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = log10_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_log10_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = log10_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_log1p_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        u_f64i _t232;
        _t232.lo = -1.0 + a.ff[i / 64].lo;
        _t232.up = 1.0 + a.ff[i / 64].up;
        dst.f[i / 64] = ln_d(_t232.v);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_log1p_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        f32_I _t233;
        _t233.lo = -1.0 + a.f[i / 32].lo;
        _t233.up = 1.0 + a.f[i / 32].up;
        dst.f[i / 32] = ln_s(_t233);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_log2_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = log2_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_log2_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = log2_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_logb_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ConvertExpFP64_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_logb_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ConvertExpFP32_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_pow_pd(f64i_simd4 _a, f64i_simd4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = pow_d(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_pow_ps(f32i_simd8 _a, f32i_simd8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = pow_s(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_sin_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = SIN_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_sin_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = SIN_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_sincos_pd(f64i_simd4 *_mem_addr, f64i_simd4 _a) {
    vec256d *mem_addr = (vec256d *)_mem_addr;
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = SIN_d(a.f[i / 64]);
        mem_addr->f[i / 64] = COS_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_sincos_ps(f32i_simd8 *_mem_addr, f32i_simd8 _a) {
    vec256s *mem_addr = (vec256s *)_mem_addr;
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = SIN_s(a.f[i / 32]);
        mem_addr->f[i / 32] = COS_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_sind_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = SIND_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_sind_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = SIND_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_sinh_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = SINH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_sinh_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = SINH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_svml_ceil_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = CEIL_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_svml_ceil_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = CEIL_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_svml_floor_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = FLOOR_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_svml_floor_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = FLOOR_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_svml_round_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = ROUND_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_svml_round_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = ROUND_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_svml_sqrt_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = SQRT_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_svml_sqrt_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = SQRT_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_tan_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = TAN_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_tan_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = TAN_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_tand_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = TAND_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_tand_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = TAND_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_tanh_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = TANH_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_tanh_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = TANH_s(a.f[i / 32]);
    }

    return dst.v;
}

f64i_simd4 _igen_fb_mm256_trunc_pd(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = TRUNCATE_d(a.f[i / 64]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_trunc_ps(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = TRUNCATE_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd8 _igen_fb_mm256_cvtph_ps(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;
    int m;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        m = j * 16;
        dst.f[i / 32] = Convert_FP16_To_FP32_i(vecBitsAccess_i(a.i, m + 15, m));
    }

    return dst.v;
}

__m128i _igen_fb_mm256_cvtps_ph(f32i_simd8 _a, int rounding) {
    vec256s a;
    a.v = _a;
    vec128i dst;
    int j;
    int i;
    int l;

    for (j = 0; j <= 7; ++j) {
        i = 16 * j;
        l = 32 * j;
        vecBitsAssign_i(dst.i, i + 15, i, Convert_FP32_To_FP16_s(a.f[l / 32]));
    }

    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

f32_I _igen_fb_mm256_cvtss_f32(f32i_simd8 _a) {
    vec256s a;
    a.v = _a;
    f32_I dst;

    dst = a.f[0];
    return dst;
}

f64_I _igen_fb_mm256_cvtsd_f64(f64i_simd4 _a) {
    vec256d a;
    a.v = _a;
    f64_I dst;

    dst = a.f[0];
    return dst;
}

f64i_simd8 _igen_fb_mm512_acos_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ACOS_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_acos_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ACOS_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_acos_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = ACOS_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_acos_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = ACOS_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_acosh_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ACOSH_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_acosh_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ACOSH_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_acosh_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = ACOSH_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_acosh_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = ACOSH_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_asin_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ASIN_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_asin_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ASIN_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_asin_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = ASIN_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_asin_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = ASIN_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_asinh_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ASINH_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_asinh_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ASINH_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_asinh_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = ASINH_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_asinh_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = ASINH_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_atan2_pd(f64i_simd8 _a, f64i_simd8 _b) {
    vec512d a;
    a.v = _a;
    vec512d b;
    b.v = _b;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        f64_I _t234 = _ia_div_f64(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = ATAN_d(_t234);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_atan2_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a,
                                  f64i_simd8 _b) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d b;
    b.v = _b;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            f64_I _t235 = _ia_div_f64(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = ATAN_d(_t235);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_atan2_ps(f32i_simd16 _a, f32i_simd16 _b) {
    vec512s a;
    a.v = _a;
    vec512s b;
    b.v = _b;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        f32_I _t236 = _ia_div_f32(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = ATAN_s(_t236);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_atan2_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a,
                                  f32i_simd16 _b) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s b;
    b.v = _b;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            f32_I _t237 = _ia_div_f32(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = ATAN_s(_t237);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_atan_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ATAN_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_atan_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ATAN_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_atan_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = ATAN_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_atan_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = ATAN_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_atanh_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ATANH_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_atanh_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ATANH_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_atanh_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = ATANH_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_atanh_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = ATANH_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_cbrt_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = CubeRoot_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_cbrt_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = CubeRoot_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_cbrt_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = CubeRoot_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_cbrt_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = CubeRoot_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_cdfnorm_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = CDFNormal_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_cdfnorm_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = CDFNormal_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_cdfnorm_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = CDFNormal_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_cdfnorm_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = CDFNormal_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_cdfnorminv_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = InverseCDFNormal_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_cdfnorminv_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = InverseCDFNormal_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_cdfnorminv_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = InverseCDFNormal_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_cdfnorminv_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = InverseCDFNormal_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_ceil_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = CEIL_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_ceil_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = CEIL_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_ceil_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = CEIL_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_ceil_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = CEIL_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_cos_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = COS_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_cos_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = COS_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_cos_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = COS_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_cos_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = COS_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_cosd_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = COSD_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_cosd_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = COSD_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_cosd_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = COSD_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_cosd_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = COSD_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_cosh_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = COSH_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_cosh_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = COSH_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_cosh_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = COSH_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_cosh_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = COSH_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_erf_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ERF_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_erf_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ERF_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_erfc_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        u_f64i _t238;
        _t238.v = ERF_d(a.f[i / 64]);
        dst.ff[i / 64].lo = -1.0 + _t238.up;
        dst.ff[i / 64].up = 1.0 + _t238.lo;
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_erfc_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            u_f64i _t239;
            _t239.v = ERF_d(a.f[i / 64]);
            dst.ff[i / 64].lo = -1.0 + _t239.up;
            dst.ff[i / 64].up = 1.0 + _t239.lo;
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_erf_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = ERF_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_erf_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = ERF_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_erfc_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        f32_I _t240 = ERF_s(a.f[i / 32]);
        dst.f[i / 32].lo = -1.0 + _t240.up;
        dst.f[i / 32].up = 1.0 + _t240.lo;
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_erfc_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            f32_I _t241 = ERF_s(a.f[i / 32]);
            dst.f[i / 32].lo = -1.0 + _t241.up;
            dst.f[i / 32].up = 1.0 + _t241.lo;
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_erfinv_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        f64_I _t242 = _ia_one_f64();
        f64_I _t243 = ERF_d(a.f[i / 64]);
        dst.f[i / 64] = _ia_div_f64(_t242, _t243);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_erfinv_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            f64_I _t244 = _ia_one_f64();
            f64_I _t245 = ERF_d(a.f[i / 64]);
            dst.f[i / 64] = _ia_div_f64(_t244, _t245);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_erfinv_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        f32_I _t246 = ERF_s(a.f[i / 32]);
        f32_I _t247;
        _t247.lo = -1.0;
        _t247.up = 1.0;
        f32_I _t248;
        _t248.lo = _t246.lo;
        _t248.up = _t246.up;
        f32_I _t249 = _ia_div_f32(_t247, _t248);
        dst.f[i / 32].lo = _t249.lo;
        dst.f[i / 32].up = _t249.up;
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_erfinv_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            f32_I _t250 = ERF_s(a.f[i / 32]);
            f32_I _t251;
            _t251.lo = -1.0;
            _t251.up = 1.0;
            f32_I _t252;
            _t252.lo = _t250.lo;
            _t252.up = _t250.up;
            f32_I _t253 = _ia_div_f32(_t251, _t252);
            dst.f[i / 32].lo = _t253.lo;
            dst.f[i / 32].up = _t253.up;
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_erfcinv_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        u_f64i _t254;
        _t254.v = ERF_d(a.f[i / 64]);
        u_f64i _t255;
        _t255.lo = -1.0;
        _t255.up = 1.0;
        u_f64i _t256;
        _t256.lo = (-1.0 + _t254.up);
        _t256.up = (1.0 + _t254.lo);
        dst.f[i / 64] = _ia_div_f64(_t255.v, _t256.v);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_erfcinv_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            u_f64i _t257;
            _t257.v = ERF_d(a.f[i / 64]);
            u_f64i _t258;
            _t258.lo = -1.0;
            _t258.up = 1.0;
            u_f64i _t259;
            _t259.lo = (-1.0 + _t257.up);
            _t259.up = (1.0 + _t257.lo);
            dst.f[i / 64] = _ia_div_f64(_t258.v, _t259.v);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_erfcinv_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        f32_I _t260 = ERF_s(a.f[i / 32]);
        f32_I _t261;
        _t261.lo = -1.0;
        _t261.up = 1.0;
        f32_I _t262;
        _t262.lo = (-1.0 + _t260.up);
        _t262.up = (1.0 + _t260.lo);
        f32_I _t263 = _ia_div_f32(_t261, _t262);
        dst.f[i / 32].lo = _t263.lo;
        dst.f[i / 32].up = _t263.up;
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_erfcinv_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            f32_I _t264 = ERF_s(a.f[i / 32]);
            f32_I _t265;
            _t265.lo = -1.0;
            _t265.up = 1.0;
            f32_I _t266;
            _t266.lo = (-1.0 + _t264.up);
            _t266.up = (1.0 + _t264.lo);
            f32_I _t267 = _ia_div_f32(_t265, _t266);
            dst.f[i / 32].lo = _t267.lo;
            dst.f[i / 32].up = _t267.up;
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_exp10_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = exp10_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_exp10_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = exp10_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_exp10_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = exp10_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_exp10_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = exp10_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_exp2_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = exp2_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_exp2_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = exp2_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_exp2_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = exp2_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_exp2_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = exp2_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_exp_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = expe_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_exp_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = expe_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_exp_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = expe_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_exp_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = expe_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_expm1_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        u_f64i _t268;
        _t268.v = expe_d(a.f[i / 64]);
        dst.ff[i / 64].lo = _t268.lo + 1.0;
        dst.ff[i / 64].up = _t268.up + -1.0;
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_expm1_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            u_f64i _t269;
            _t269.v = expe_d(a.f[i / 64]);
            dst.ff[i / 64].lo = _t269.lo + 1.0;
            dst.ff[i / 64].up = _t269.up + -1.0;
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_expm1_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        f32_I _t270 = expe_s(a.f[i / 32]);
        dst.f[i / 32].lo = _t270.lo + 1.0;
        dst.f[i / 32].up = _t270.up + -1.0;
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_expm1_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            f32_I _t271 = expe_s(a.f[i / 32]);
            dst.f[i / 32].lo = _t271.lo + 1.0;
            dst.f[i / 32].up = _t271.up + -1.0;
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_floor_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = FLOOR_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_floor_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = FLOOR_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_floor_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = FLOOR_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_floor_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = FLOOR_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[(i) / 32 + 0];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_hypot_pd(f64i_simd8 _a, f64i_simd8 _b) {
    vec512d a;
    a.v = _a;
    vec512d b;
    b.v = _b;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        f64_I _t272 = _ia_mul_f64(a.f[i / 64], a.f[i / 64]);
        f64_I _t273 = _ia_mul_f64(b.f[i / 64], b.f[i / 64]);
        f64_I _t274 = _ia_add_f64(_t272, _t273);
        dst.f[i / 64] = SQRT_d(_t274);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_hypot_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a,
                                  f64i_simd8 _b) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d b;
    b.v = _b;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            f64_I _t275 = _ia_mul_f64(a.f[i / 64], a.f[i / 64]);
            f64_I _t276 = _ia_mul_f64(b.f[i / 64], b.f[i / 64]);
            f64_I _t277 = _ia_add_f64(_t275, _t276);
            dst.f[i / 64] = SQRT_d(_t277);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_hypot_ps(f32i_simd16 _a, f32i_simd16 _b) {
    vec512s a;
    a.v = _a;
    vec512s b;
    b.v = _b;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        f32_I _t278 = _ia_mul_f32(a.f[i / 32], a.f[i / 32]);
        f32_I _t279 = _ia_mul_f32(b.f[i / 32], b.f[i / 32]);
        f32_I _t280;
        _t280.lo = _t278.lo + _t279.lo;
        _t280.up = _t278.up + _t279.up;
        dst.f[i / 32] = SQRT_s(_t280);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_hypot_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a,
                                  f32i_simd16 _b) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s b;
    b.v = _b;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            f32_I _t281 = _ia_mul_f32(a.f[i / 32], a.f[i / 32]);
            f32_I _t282 = _ia_mul_f32(b.f[i / 32], b.f[i / 32]);
            f32_I _t283;
            _t283.lo = _t281.lo + _t282.lo;
            _t283.up = _t281.up + _t282.up;
            dst.f[i / 32] = SQRT_s(_t283);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_invsqrt_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = InvSQRT_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_invsqrt_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = InvSQRT_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_invsqrt_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = InvSQRT_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_invsqrt_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = InvSQRT_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_log10_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = log10_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_log10_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = log10_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_log10_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = log10_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_log10_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = log10_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_log1p_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        u_f64i _t284;
        _t284.lo = -1.0 + a.ff[i / 64].lo;
        _t284.up = 1.0 + a.ff[i / 64].up;
        dst.f[i / 64] = ln_d(_t284.v);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_log1p_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            u_f64i _t285;
            _t285.lo = -1.0 + a.ff[i / 64].lo;
            _t285.up = 1.0 + a.ff[i / 64].up;
            dst.f[i / 64] = ln_d(_t285.v);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_log1p_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        f32_I _t286;
        _t286.lo = -1.0 + a.f[i / 32].lo;
        _t286.up = 1.0 + a.f[i / 32].up;
        dst.f[i / 32] = ln_s(_t286);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_log1p_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            f32_I _t287;
            _t287.lo = -1.0 + a.f[i / 32].lo;
            _t287.up = 1.0 + a.f[i / 32].up;
            dst.f[i / 32] = ln_s(_t287);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_log2_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = log2_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_log2_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = log2_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_log_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ln_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_log_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ln_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_log_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = ln_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_log_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = ln_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_logb_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ConvertExpFP64_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_logb_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ConvertExpFP64_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_logb_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = ConvertExpFP32_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_logb_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = ConvertExpFP32_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_nearbyint_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = NearbyInt_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_nearbyint_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = NearbyInt_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_nearbyint_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = NearbyInt_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_nearbyint_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = NearbyInt_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_pow_pd(f64i_simd8 _a, f64i_simd8 _b) {
    vec512d a;
    a.v = _a;
    vec512d b;
    b.v = _b;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = pow_d(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_pow_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a,
                                f64i_simd8 _b) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d b;
    b.v = _b;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = pow_d(a.f[i / 64], b.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_pow_ps(f32i_simd16 _a, f32i_simd16 _b) {
    vec512s a;
    a.v = _a;
    vec512s b;
    b.v = _b;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = pow_s(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_pow_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a,
                                f32i_simd16 _b) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s b;
    b.v = _b;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = pow_s(a.f[i / 32], b.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_recip_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        f64_I _t288 = _ia_one_f64();
        dst.f[i / 64] = _ia_div_f64(_t288, a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_recip_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            f64_I _t289 = _ia_one_f64();
            dst.f[i / 64] = _ia_div_f64(_t289, a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_recip_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        f32_I _t290;
        _t290.lo = -1.0;
        _t290.up = 1.0;
        dst.f[i / 32] = _ia_div_f32(_t290, a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_recip_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            f32_I _t291;
            _t291.lo = -1.0;
            _t291.up = 1.0;
            dst.f[i / 32] = _ia_div_f32(_t291, a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_rint_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = RoundToNearestEven_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_rint_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = RoundToNearestEven_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_rint_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = RoundToNearestEven_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_rint_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = RoundToNearestEven_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_svml_round_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = ROUND_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_svml_round_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = ROUND_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_sin_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = SIN_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_sin_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = SIN_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_sin_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = SIN_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_sin_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = SIN_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_sinh_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = SINH_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_sinh_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = SINH_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_sinh_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = SINH_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_sinh_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = SINH_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_sind_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = SIND_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_sind_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = SIND_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_sind_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = SIND_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_sind_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = SIND_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_tan_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = TAN_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_tan_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = TAN_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_tan_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = TAN_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_tan_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = TAN_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_tand_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = TAND_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_tand_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = TAND_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_tand_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = TAND_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_tand_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = TAND_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_tanh_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = TANH_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_tanh_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = TANH_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_tanh_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = TANH_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_tanh_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = TANH_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_trunc_pd(f64i_simd8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = TRUNCATE_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_trunc_pd(f64i_simd8 _src, __mmask8 k, f64i_simd8 _a) {
    vec512d src;
    src.v = _src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = TRUNCATE_d(a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_trunc_ps(f32i_simd16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = TRUNCATE_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_trunc_ps(f32i_simd16 _src, __mmask16 k, f32i_simd16 _a) {
    vec512s src;
    src.v = _src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = TRUNCATE_s(a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_sincos_pd(f64i_simd8 *_cos_res, f64i_simd8 _a) {
    vec512d *cos_res = (vec512d *)_cos_res;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dst.f[i / 64] = SIN_d(a.f[i / 64]);
    }

    return dst.v;
}

f64i_simd8 _igen_fb_mm512_mask_sincos_pd(f64i_simd8 *_cos_res, f64i_simd8 _sin_src,
                                   f64i_simd8 _cos_src, __mmask8 k, f64i_simd8 _a) {
    vec512d *cos_res = (vec512d *)_cos_res;
    vec512d sin_src;
    sin_src.v = _sin_src;
    vec512d cos_src;
    cos_src.v = _cos_src;
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        if (((k >> j) & 1)) {
            dst.f[i / 64] = SIN_d(a.f[i / 64]);

        } else {
            dst.f[i / 64] = sin_src.f[i / 64];
        }
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_sincos_ps(f32i_simd16 *_cos_res, f32i_simd16 _a) {
    vec512s *cos_res = (vec512s *)_cos_res;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dst.f[i / 32] = SIN_s(a.f[i / 32]);
    }

    return dst.v;
}

f32i_simd16 _igen_fb_mm512_mask_sincos_ps(f32i_simd16 *_cos_res, f32i_simd16 _sin_src,
                                   f32i_simd16 _cos_src, __mmask16 k, f32i_simd16 _a) {
    vec512s *cos_res = (vec512s *)_cos_res;
    vec512s sin_src;
    sin_src.v = _sin_src;
    vec512s cos_src;
    cos_src.v = _cos_src;
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        if (((k >> j) & 1)) {
            dst.f[i / 32] = SIN_s(a.f[i / 32]);

        } else {
            dst.f[i / 32] = sin_src.f[i / 32];
        }
    }

    return dst.v;
}
