#include "igen_dd_immintrin_fallback.h"
#include "igen_dd_immintrin_internal.h"

ddi_4 _igen_dd_fb_mm_cvtsi32_ss(ddi_4 _a, int b) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = Convert_Int32_To_FP32_i(b);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cvtsi64_ss(ddi_4 _a, long b) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = (Convert_Int64_To_FP32_l(b));
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cvtpi32_ps(ddi_4 _a, __m64 _b) {
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

ddi_4 _igen_dd_fb_mm_cvtpi16_ps(__m64 _a) {
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

ddi_4 _igen_dd_fb_mm_cvtpu16_ps(__m64 _a) {
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

ddi_4 _igen_dd_fb_mm_cvtpi8_ps(__m64 _a) {
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

ddi_4 _igen_dd_fb_mm_cvtpu8_ps(__m64 _a) {
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

ddi_4 _igen_dd_fb_mm_cvtpi32x2_ps(__m64 _a, __m64 _b) {
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

ddi_4 _igen_dd_fb_mm_add_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = _ia_add_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_add_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = _ia_add_dd(a.f[i / 32], b.f[i / 32]);
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_sub_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = _ia_sub_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_sub_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = _ia_sub_dd(a.f[i / 32], b.f[i / 32]);
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_mul_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = _ia_mul_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_mul_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_div_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = _ia_div_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_div_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = 32 * j;
        dst.f[i / 32] = _ia_div_dd(a.f[i / 32], b.f[i / 32]);
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_sqrt_ss(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = SQRT_s(a.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_sqrt_ps(ddi_4 _a) {
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

ddi_4 _igen_dd_fb_mm_rcp_ss(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dd_I _t1 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
    dst.f[0] = _ia_div_dd(_t1, a.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_rcp_ps(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dd_I _t2 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dst.f[i / 32] = _ia_div_dd(_t2, a.f[i / 32]);
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_rsqrt_ss(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dd_I _t3 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
    dd_I _t4 = SQRT_s(a.f[0]);
    dst.f[0] = _ia_div_dd(_t3, _t4);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_rsqrt_ps(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dd_I _t5 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t6 = SQRT_s(a.f[i / 32]);
        dst.f[i / 32] = _ia_div_dd(_t5, _t6);
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_min_ss(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm_min_ps(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm_max_ss(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm_max_ps(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm_and_ps(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm_andnot_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        i256 _t7;
        _t7 = (~a.i[i / 32]);
        dst.i[i / 32] = _ia_and_u32(_t7, b.i[i / 32]);
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_or_ps(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm_xor_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.i[i / 32] = a.i[i / 32] ^ b.i[i / 32];
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpeq_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = (_ia_cmpeq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpeq_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = (_ia_cmpeq_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmplt_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = (_ia_cmplt_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmplt_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = (_ia_cmplt_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmple_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = (_ia_cmpleq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmple_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = (_ia_cmpleq_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpgt_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = (_ia_cmpgt_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpgt_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = (_ia_cmpgt_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpge_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = (_ia_cmpgeq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpge_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = (_ia_cmpgeq_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpneq_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = (_ia_cmpneq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpneq_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = (_ia_cmpneq_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpnlt_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = !(_ia_cmplt_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpnlt_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = !(_ia_cmplt_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpnle_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = !(_ia_cmpleq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpnle_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = !(_ia_cmpleq_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpngt_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = !(_ia_cmpgt_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpngt_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = !(_ia_cmpgt_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpnge_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t16 = !(_ia_cmpgeq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t16);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpnge_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        unsigned int _t17 = !(_ia_cmpgeq_dd(a.f[i / 32], b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t17);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpord_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t36 =
            (!_igen_isnan_s(a.f[0]) & !_igen_isnan_s(b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t36);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpord_ps(ddi_4 _a, ddi_4 _b) {
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
        dst.i[i / 32] = _ia_create_mask(_t37);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpunord_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    unsigned int _t38 = (_igen_isnan_s(a.f[0]) | _igen_isnan_s(b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t38);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmpunord_ps(ddi_4 _a, ddi_4 _b) {
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
                (_igen_isnan_s(a.f[i / 32]) | _igen_isnan_s(b.f[i / 32])) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t37);
    }

    return dst.v;
}

int _igen_dd_fb_mm_comieq_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpeq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comilt_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmplt_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comile_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpleq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comigt_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgt_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comige_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgeq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comineq_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpneq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomieq_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpeq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomilt_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmplt_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomile_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpleq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomigt_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgt_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomige_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgeq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomineq_ss(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpneq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_cvtss_si32(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    int dst;

    dst = Convert_FP32_To_Int32_s(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_cvt_ss2si(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    int dst;

    dst = Convert_FP32_To_Int32_s(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

long _igen_dd_fb_mm_cvtss_si64(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    long dst;

    dst = Convert_FP32_To_Int64_s(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

dd_I _igen_dd_fb_mm_cvtss_f32(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    dd_I dst;

    dst = a.f[0];
    return dst;
}

__m64 _igen_dd_fb_mm_cvtps_pi32(ddi_4 _a) {
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

__m64 _igen_dd_fb_mm_cvt_ps2pi(ddi_4 _a) {
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

int _igen_dd_fb_mm_cvttss_si32(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    int dst;

    dst = Convert_FP32_To_Int32_Truncate_s(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_cvtt_ss2si(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    int dst;

    dst = Convert_FP32_To_Int32_Truncate_s(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

long _igen_dd_fb_mm_cvttss_si64(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int32_Truncate_s(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

__m64 _igen_dd_fb_mm_cvttps_pi32(ddi_4 _a) {
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

__m64 _igen_dd_fb_mm_cvtt_ps2pi(ddi_4 _a) {
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

__m64 _igen_dd_fb_mm_cvtps_pi16(ddi_4 _a) {
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

__m64 _igen_dd_fb_mm_cvtps_pi8(ddi_4 _a) {
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

ddi_4 _igen_dd_fb_mm_set_ss(dd_I a) {
    vec128s dst;

    dst.f[0] = a;
    dst.f[1] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[2] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[3] = _ia_set_dd(-0, 0.0, 0, 0.0);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_set1_ps(dd_I a) {
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = a;
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_set_ps1(dd_I a) {
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dst.f[i / 32] = a;
    }
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_set_ps(dd_I e3, dd_I e2, dd_I e1, dd_I e0) {
    vec128s dst;

    dst.f[0] = e0;
    dst.f[1] = e1;
    dst.f[2] = e2;
    dst.f[3] = e3;
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_setr_ps(dd_I e3, dd_I e2, dd_I e1, dd_I e0) {
    vec128s dst;

    dst.f[0] = e3;
    dst.f[1] = e2;
    dst.f[2] = e1;
    dst.f[3] = e0;
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_setzero_ps() {
    vec128s dst;

    dst.f[0] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[1] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[2] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[3] = _ia_set_dd(-0, 0.0, 0, 0.0);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_load_ss(const dd_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[2] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[3] = _ia_set_dd(-0, 0.0, 0, 0.0);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_load1_ps(const dd_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    dst.f[2] = *(mem_addr + 0);
    dst.f[3] = *(mem_addr + 0);
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_load_ps1(const dd_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    dst.f[2] = *(mem_addr + 0);
    dst.f[3] = *(mem_addr + 0);
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_load_ps(const dd_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_loadu_ps(const dd_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_loadr_ps(const dd_I *mem_addr) {
    vec128s dst;

    dst.f[0] = *(mem_addr + 3);
    dst.f[1] = *(mem_addr + 2);
    dst.f[2] = *(mem_addr + 1);
    dst.f[3] = *(mem_addr + 0);
    return dst.v;
}

void _igen_dd_fb_mm_stream_ps(dd_I *mem_addr, ddi_4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
}

void _igen_dd_fb_mm_store_ss(dd_I *mem_addr, ddi_4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
}

void _igen_dd_fb_mm_store1_ps(dd_I *mem_addr, ddi_4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[0];
    *(mem_addr + 2) = a.f[0];
    *(mem_addr + 3) = a.f[0];
}

void _igen_dd_fb_mm_store_ps1(dd_I *mem_addr, ddi_4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[0];
    *(mem_addr + 2) = a.f[0];
    *(mem_addr + 3) = a.f[0];
}

void _igen_dd_fb_mm_store_ps(dd_I *mem_addr, ddi_4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
}

void _igen_dd_fb_mm_storeu_ps(dd_I *mem_addr, ddi_4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
}

void _igen_dd_fb_mm_storer_ps(dd_I *mem_addr, ddi_4 _a) {
    vec128s a;
    a.v = _a;

    *(mem_addr + 0) = a.f[3];
    *(mem_addr + 1) = a.f[2];
    *(mem_addr + 2) = a.f[1];
    *(mem_addr + 3) = a.f[0];
}

ddi_4 _igen_dd_fb_mm_move_ss(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm_shuffle_ps(ddi_4 _a, ddi_4 _b, unsigned int imm8) {
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

ddi_4 _igen_dd_fb_mm_unpackhi_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    INTERLEAVE_HIGH_DWORDS_ss(&dst.f[0], &a.f[0], &b.f[0]);
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_unpacklo_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    INTERLEAVE_DWORDS_ss(&dst.f[0], &a.f[0], &b.f[0]);
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_movehl_ps(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm_movelh_ps(ddi_4 _a, ddi_4 _b) {
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

int _igen_dd_fb_mm_movemask_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_cvtepi32_pd(__m128i _a) {
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

ddi_2 _igen_dd_fb_mm_cvtsi32_sd(ddi_2 _a, int b) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = Convert_Int32_To_FP64_i(b);
    dst.f[1] = a.f[1];

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cvtsi64_sd(ddi_2 _a, long b) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = Convert_Int64_To_FP64_l(b);
    dst.f[1] = a.f[1];

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cvtsi64x_sd(ddi_2 _a, long b) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = Convert_Int64_To_FP64_l(b);
    dst.f[1] = a.f[1];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cvtepi32_ps(__m128i _a) {
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

ddi_2 _igen_dd_fb_mm_cvtpi32_pd(__m64 _a) {
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

ddi_2 _igen_dd_fb_mm_add_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_add_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_add_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_add_dd(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_div_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_div_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_div_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = 64 * j;
        dst.f[i / 64] = _ia_div_dd(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_max_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = MAX_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_max_pd(ddi_2 _a, ddi_2 _b) {
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

ddi_2 _igen_dd_fb_mm_min_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = MIN_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_min_pd(ddi_2 _a, ddi_2 _b) {
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

ddi_2 _igen_dd_fb_mm_mul_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_mul_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_mul_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_sqrt_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = SQRT_d(b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_sqrt_pd(ddi_2 _a) {
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

ddi_2 _igen_dd_fb_mm_sub_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_sub_dd(a.f[0], b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_sub_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_sub_dd(a.f[i / 64], b.f[i / 64]);
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_and_pd(ddi_2 _a, ddi_2 _b) {
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

ddi_2 _igen_dd_fb_mm_andnot_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        i256 _t40;
        _t40 = ~a.i[i / 64];
        dst.i[i / 64] = _ia_and_u64(_t40, b.i[i / 64]);
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_or_pd(ddi_2 _a, ddi_2 _b) {
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

ddi_2 _igen_dd_fb_mm_xor_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.i[i / 64] = a.i[i / 64] ^ b.i[i / 64];
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpeq_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = (_ia_cmpeq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmplt_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = (_ia_cmplt_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmple_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = (_ia_cmpleq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpgt_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = (_ia_cmpgt_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpge_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = (_ia_cmpgeq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpord_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = (!_igen_isnan_d(a.f[0]) & !_igen_isnan_d(b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpunord_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = (_igen_isnan_d(a.f[0]) | _igen_isnan_d(b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpneq_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = (_ia_cmpneq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpnlt_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = !(_ia_cmplt_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpnle_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = !(_ia_cmpleq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpngt_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = !(_ia_cmpgt_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpnge_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    unsigned long _t41 = !(_ia_cmpgeq_dd(a.f[0], b.f[0])) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t41);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpeq_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = (_ia_cmpeq_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmplt_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = (_ia_cmplt_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmple_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = (_ia_cmpleq_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpgt_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = (_ia_cmpgt_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpge_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = (_ia_cmpgeq_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpord_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = (!_igen_isnan_d(a.f[i / 64]) & !_igen_isnan_d(b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpunord_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = (_igen_isnan_d(a.f[i / 64]) | _igen_isnan_d(b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpneq_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = (_ia_cmpneq_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpnlt_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = !(_ia_cmplt_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpnle_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = !(_ia_cmpleq_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpngt_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = !(_ia_cmpgt_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmpnge_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        unsigned long _t53 = !(_ia_cmpgeq_dd(a.f[i / 64], b.f[i / 64])) ? -1 : 0;
        dst.i[i / 64] = _ia_create_mask(_t53);
    }

    return dst.v;
}

int _igen_dd_fb_mm_comieq_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpeq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comilt_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmplt_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comile_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpleq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comigt_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgt_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comige_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgeq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_comineq_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpneq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomieq_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpeq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomilt_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmplt_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomile_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpleq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomigt_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgt_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomige_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpgeq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

int _igen_dd_fb_mm_ucomineq_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    int dst;

    dst = (_ia_cmpneq_dd(a.f[0], b.f[0])) ? 1 : 0;
    int _ret;
    _ret = dst;
    return _ret;
}

ddi_4 _igen_dd_fb_mm_cvtpd_ps(ddi_2 _a) {
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
    dst.f[2] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[3] = _ia_set_dd(-0, 0.0, 0, 0.0);

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cvtps_pd(ddi_4 _a) {
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

__m128i _igen_dd_fb_mm_cvtpd_epi32(ddi_2 _a) {
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

int _igen_dd_fb_mm_cvtsd_si32(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    int dst;

    dst = Convert_FP64_To_Int32_d(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

long _igen_dd_fb_mm_cvtsd_si64(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int64_d(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

long _igen_dd_fb_mm_cvtsd_si64x(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int64_d(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

ddi_4 _igen_dd_fb_mm_cvtsd_ss(ddi_4 _a, ddi_2 _b) {
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

dd_I _igen_dd_fb_mm_cvtsd_f64(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    dd_I dst;

    dst = a.f[0];
    return dst;
}

ddi_2 _igen_dd_fb_mm_cvtss_sd(ddi_2 _a, ddi_4 _b) {
    vec128d a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = Convert_FP32_To_FP64_s(b.f[0]);
    dst.f[1] = a.f[1];
    dst.f[1] = _ia_set_dd(-0, 0.0, 0, 0.0);
    return dst.v;
}

__m128i _igen_dd_fb_mm_cvttpd_epi32(ddi_2 _a) {
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

int _igen_dd_fb_mm_cvttsd_si32(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    int dst;

    dst = Convert_FP64_To_Int32_Truncate_d(a.f[0]);
    int _ret;
    _ret = dst;
    return _ret;
}

long _igen_dd_fb_mm_cvttsd_si64(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int64_Truncate_d(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

long _igen_dd_fb_mm_cvttsd_si64x(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    long dst;

    dst = Convert_FP64_To_Int64_Truncate_d(a.f[0]);
    long _ret;
    _ret = dst;
    return _ret;
}

__m128i _igen_dd_fb_mm_cvtps_epi32(ddi_4 _a) {
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

__m128i _igen_dd_fb_mm_cvttps_epi32(ddi_4 _a) {
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

__m64 _igen_dd_fb_mm_cvtpd_pi32(ddi_2 _a) {
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

__m64 _igen_dd_fb_mm_cvttpd_pi32(ddi_2 _a) {
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

ddi_2 _igen_dd_fb_mm_set_sd(dd_I a) {
    vec128d dst;

    dst.f[0] = a;
    dst.f[1] = _ia_set_dd(-0, 0.0, 0, 0.0);
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_set1_pd(dd_I a) {
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = a;
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_set_pd1(dd_I a) {
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dst.f[i / 64] = a;
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_set_pd(dd_I e1, dd_I e0) {
    vec128d dst;

    dst.f[0] = e0;
    dst.f[1] = e1;
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_setr_pd(dd_I e1, dd_I e0) {
    vec128d dst;

    dst.f[0] = e1;
    dst.f[1] = e0;
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_setzero_pd() {
    vec128d dst;

    dst.f[0] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[1] = _ia_set_dd(-0, 0.0, 0, 0.0);

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_load_pd(const dd_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_load1_pd(const dd_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_load_pd1(const dd_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_loadr_pd(const dd_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 1);
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_loadu_pd(const dd_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_load_sd(const dd_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = _ia_set_dd(-0, 0.0, 0, 0.0);
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_loadh_pd(ddi_2 _a, const dd_I *mem_addr) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = a.f[0];
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_loadl_pd(ddi_2 _a, const dd_I *mem_addr) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = a.f[1];
    return dst.v;
}

void _igen_dd_fb_mm_stream_pd(dd_I *mem_addr, ddi_2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
}

void _igen_dd_fb_mm_store_sd(dd_I *mem_addr, ddi_2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
}

void _igen_dd_fb_mm_store1_pd(dd_I *mem_addr, ddi_2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[0];
}

void _igen_dd_fb_mm_store_pd1(dd_I *mem_addr, ddi_2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[0];
}

void _igen_dd_fb_mm_store_pd(dd_I *mem_addr, ddi_2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
}

void _igen_dd_fb_mm_storeu_pd(dd_I *mem_addr, ddi_2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
}

void _igen_dd_fb_mm_storer_pd(dd_I *mem_addr, ddi_2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[1];
    *(mem_addr + 1) = a.f[0];
}

void _igen_dd_fb_mm_storeh_pd(dd_I *mem_addr, ddi_2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[1];
}

void _igen_dd_fb_mm_storel_pd(dd_I *mem_addr, ddi_2 _a) {
    vec128d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
}

ddi_2 _igen_dd_fb_mm_unpackhi_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    INTERLEAVE_HIGH_QWORDS_dd(&dst.f[0], &a.f[0], &b.f[0]);
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_unpacklo_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    INTERLEAVE_QWORDS_dd(&dst.f[0], &a.f[0], &b.f[0]);
    return dst.v;
}

int _igen_dd_fb_mm_movemask_pd(ddi_2 _a) {
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

ddi_2 _igen_dd_fb_mm_shuffle_pd(ddi_2 _a, ddi_2 _b, int imm8) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = (((imm8 >> 0) & 1) == 0) ? a.f[0] : a.f[1];
    dst.f[1] = (((imm8 >> 1) & 1) == 0) ? b.f[0] : b.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_move_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = b.f[0];
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_castpd_ps(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec128s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

__m128i _igen_dd_fb_mm_castpd_si128(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec128i dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

ddi_2 _igen_dd_fb_mm_castps_pd(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

__m128i _igen_dd_fb_mm_castps_si128(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128i dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    __m128i _ret;
    _ret = dst.v;
    return _ret;
}

ddi_2 _igen_dd_fb_mm_castsi128_pd(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec128d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_castsi128_ps(__m128i _a) {
    vec128i a;
    a.v = _a;
    vec128s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

dd_I _igen_dd_fb_cvtsh_ss(__mmask16 a) {
    dd_I dst;

    dst = Convert_FP16_To_FP32_u16(a);
    return dst;
}

__mmask16 _igen_dd_fb_cvtss_sh(dd_I a, int rounding) {
    __mmask16 dst;

    dst = Convert_FP32_To_FP16_s(a);
    __mmask16 _ret;
    _ret = dst;
    return _ret;
}

ddi_4 _igen_dd_fb_mm_cvtph_ps(__m128i _a) {
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

__m128i _igen_dd_fb_mm_cvtps_ph(ddi_4 _a, int rounding) {
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

ddi_4 _igen_dd_fb_mm_addsub_ps(ddi_4 _a, ddi_4 _b) {
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
            dst.f[i / 32] = _ia_sub_dd(a.f[i / 32], b.f[i / 32]);
        } else {
            dst.f[i / 32] = _ia_add_dd(a.f[i / 32], b.f[i / 32]);
        }
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_addsub_pd(ddi_2 _a, ddi_2 _b) {
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
            dst.f[i / 64] = _ia_sub_dd(a.f[i / 64], b.f[i / 64]);
        } else {
            dst.f[i / 64] = _ia_add_dd(a.f[i / 64], b.f[i / 64]);
        }
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_hadd_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_add_dd(a.f[1], a.f[0]);
    dst.f[1] = _ia_add_dd(b.f[1], b.f[0]);
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_hadd_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = _ia_add_dd(a.f[1], a.f[0]);
    dst.f[1] = _ia_add_dd(a.f[3], a.f[2]);
    dst.f[2] = _ia_add_dd(b.f[1], b.f[0]);
    dst.f[3] = _ia_add_dd(b.f[3], b.f[2]);
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_hsub_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = _ia_sub_dd(a.f[0], a.f[1]);
    dst.f[1] = _ia_sub_dd(b.f[0], b.f[1]);
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_hsub_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;

    dst.f[0] = _ia_sub_dd(a.f[0], a.f[1]);
    dst.f[1] = _ia_sub_dd(a.f[2], a.f[3]);
    dst.f[2] = _ia_sub_dd(b.f[0], b.f[1]);
    dst.f[3] = _ia_sub_dd(b.f[2], b.f[3]);
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_movedup_pd(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[0];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_loaddup_pd(const dd_I *mem_addr) {
    vec128d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_movehdup_ps(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = a.f[1];
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[3];
    dst.f[3] = a.f[3];
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_moveldup_ps(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[0];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[2];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_blend_pd(ddi_2 _a, ddi_2 _b, int imm8) {
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

ddi_4 _igen_dd_fb_mm_blend_ps(ddi_4 _a, ddi_4 _b, int imm8) {
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

ddi_2 _igen_dd_fb_mm_blendv_pd(ddi_2 _a, ddi_2 _b, ddi_2 _mask) {
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

ddi_4 _igen_dd_fb_mm_blendv_ps(ddi_4 _a, ddi_4 _b, ddi_4 _mask) {
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

ddi_2 _igen_dd_fb_mm_dp_pd(ddi_2 _a, ddi_2 _b, int imm8) {
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

ddi_4 _igen_dd_fb_mm_dp_ps(ddi_4 _a, ddi_4 _b, int imm8) {
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

int _igen_dd_fb_mm_extract_ps(ddi_4 _a, int imm8) {
    vec128s a;
    a.v = _a;
    int dst;

    int _ret;
    _ret = dst;
    return _ret;
}

ddi_4 _igen_dd_fb_mm_insert_ps(ddi_4 _a, ddi_4 _b, int imm8) {
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
            dst.f[i / 32] = _ia_set_dd(-0, 0.0, 0, 0.0);
        } else {
            dst.f[i / 32] = tmp2.f[i / 32];
        }
    }
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_round_pd(ddi_2 _a, int rounding) {
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

ddi_2 _igen_dd_fb_mm_floor_pd(ddi_2 _a) {
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

ddi_2 _igen_dd_fb_mm_ceil_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_round_ps(ddi_4 _a, int rounding) {
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

ddi_4 _igen_dd_fb_mm_floor_ps(ddi_4 _a) {
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

ddi_4 _igen_dd_fb_mm_ceil_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_round_sd(ddi_2 _a, ddi_2 _b, int rounding) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = ROUND_di(b.f[0], rounding);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_floor_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = FLOOR_d(b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_ceil_sd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;

    dst.f[0] = CEIL_d(b.f[0]);
    dst.f[1] = a.f[1];
    return dst.v;
}

ddi_4 _igen_dd_fb_mm_round_ss(ddi_4 _a, ddi_4 _b, int rounding) {
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

ddi_4 _igen_dd_fb_mm_floor_ss(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm_ceil_ss(ddi_4 _a, ddi_4 _b) {
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

ddi_4 _igen_dd_fb_mm256_add_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_add_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_add_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = _ia_add_dd(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_addsub_pd(ddi_4 _a, ddi_4 _b) {
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
            dst.f[i / 64] = _ia_sub_dd(a.f[i / 64], b.f[i / 64]);
        } else {
            dst.f[i / 64] = _ia_add_dd(a.f[i / 64], b.f[i / 64]);
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_addsub_ps(ddi_8 _a, ddi_8 _b) {
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
            dst.f[i / 32] = _ia_sub_dd(a.f[i / 32], b.f[i / 32]);
        } else {
            dst.f[i / 32] = _ia_add_dd(a.f[i / 32], b.f[i / 32]);
        }
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_and_pd(ddi_4 _a, ddi_4 _b) {
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

ddi_8 _igen_dd_fb_mm256_and_ps(ddi_8 _a, ddi_8 _b) {
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

ddi_4 _igen_dd_fb_mm256_andnot_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        i256 _t65;
        _t65 = ~a.i[i / 64];
        dst.i[i / 64] = _ia_and_u64(_t65, b.i[i / 64]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_andnot_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        i256 _t66;
        _t66 = ~a.i[i / 32];
        dst.i[i / 32] = _ia_and_u32(_t66, b.i[i / 32]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_blend_pd(ddi_4 _a, ddi_4 _b, int imm8) {
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

ddi_8 _igen_dd_fb_mm256_blend_ps(ddi_8 _a, ddi_8 _b, int imm8) {
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

ddi_4 _igen_dd_fb_mm256_blendv_pd(ddi_4 _a, ddi_4 _b, ddi_4 _mask) {
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

ddi_8 _igen_dd_fb_mm256_blendv_ps(ddi_8 _a, ddi_8 _b, ddi_8 _mask) {
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

ddi_4 _igen_dd_fb_mm256_div_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = 64 * j;
        dst.f[i / 64] = _ia_div_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_div_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = 32 * j;
        dst.f[i / 32] = _ia_div_dd(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_dp_ps(ddi_8 _a, ddi_8 _b, int imm8) {
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

ddi_4 _igen_dd_fb_mm256_hadd_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    dst.f[0] = _ia_add_dd(a.f[1], a.f[0]);
    dst.f[1] = _ia_add_dd(b.f[1], b.f[0]);
    dst.f[2] = _ia_add_dd(a.f[3], a.f[2]);
    dst.f[3] = _ia_add_dd(b.f[3], b.f[2]);

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_hadd_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;

    dst.f[0] = _ia_add_dd(a.f[1], a.f[0]);
    dst.f[1] = _ia_add_dd(a.f[3], a.f[2]);
    dst.f[2] = _ia_add_dd(b.f[1], b.f[0]);
    dst.f[3] = _ia_add_dd(b.f[3], b.f[2]);
    dst.f[4] = _ia_add_dd(a.f[5], a.f[4]);
    dst.f[5] = _ia_add_dd(a.f[7], a.f[6]);
    dst.f[6] = _ia_add_dd(b.f[5], b.f[4]);
    dst.f[7] = _ia_add_dd(b.f[7], b.f[6]);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_hsub_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    dst.f[0] = _ia_sub_dd(a.f[0], a.f[1]);
    dst.f[1] = _ia_sub_dd(b.f[0], b.f[1]);
    dst.f[2] = _ia_sub_dd(a.f[2], a.f[3]);
    dst.f[3] = _ia_sub_dd(b.f[2], b.f[3]);

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_hsub_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;

    dst.f[0] = _ia_sub_dd(a.f[0], a.f[1]);
    dst.f[1] = _ia_sub_dd(a.f[2], a.f[3]);
    dst.f[2] = _ia_sub_dd(b.f[0], b.f[1]);
    dst.f[3] = _ia_sub_dd(b.f[2], b.f[3]);
    dst.f[4] = _ia_sub_dd(a.f[4], a.f[5]);
    dst.f[5] = _ia_sub_dd(a.f[6], a.f[7]);
    dst.f[6] = _ia_sub_dd(b.f[4], b.f[5]);
    dst.f[7] = _ia_sub_dd(b.f[6], b.f[7]);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_max_pd(ddi_4 _a, ddi_4 _b) {
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

ddi_8 _igen_dd_fb_mm256_max_ps(ddi_8 _a, ddi_8 _b) {
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

ddi_4 _igen_dd_fb_mm256_min_pd(ddi_4 _a, ddi_4 _b) {
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

ddi_8 _igen_dd_fb_mm256_min_ps(ddi_8 _a, ddi_8 _b) {
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

ddi_4 _igen_dd_fb_mm256_mul_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_mul_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_or_pd(ddi_4 _a, ddi_4 _b) {
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

ddi_8 _igen_dd_fb_mm256_or_ps(ddi_8 _a, ddi_8 _b) {
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

ddi_4 _igen_dd_fb_mm256_shuffle_pd(ddi_4 _a, ddi_4 _b, int imm8) {
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

ddi_8 _igen_dd_fb_mm256_shuffle_ps(ddi_8 _a, ddi_8 _b, int imm8) {
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

ddi_4 _igen_dd_fb_mm256_sub_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_sub_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_sub_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = _ia_sub_dd(a.f[i / 32], b.f[i / 32]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_xor_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.i[i / 64] = a.i[i / 64] ^ b.i[i / 64];
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_xor_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.i[i / 32] = a.i[i / 32] ^ b.i[i / 32];
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmp_pd(ddi_2 _a, ddi_2 _b, int imm8) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int (*op)(dd_I, dd_I);
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
        dst.i[i / 64] = _ia_create_mask(_t67);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_cmp_pd(ddi_4 _a, ddi_4 _b, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int (*op)(dd_I, dd_I);
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
        dst.i[i / 64] = _ia_create_mask(_t68);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmp_ps(ddi_4 _a, ddi_4 _b, int imm8) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int (*op)(dd_I, dd_I);
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
        dd_I _t69;
        _t69 = a.f[i / 32];
        dd_I _t70;
        _t70 = b.f[i / 32];
        unsigned int _t71 = (op(_t69, _t70)) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t71);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_cmp_ps(ddi_8 _a, ddi_8 _b, int imm8) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int (*op)(dd_I, dd_I);
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
        dd_I _t72;
        _t72 = a.f[i / 32];
        dd_I _t73;
        _t73 = b.f[i / 32];
        unsigned int _t74 = (op(_t72, _t73)) ? -1 : 0;
        dst.i[i / 32] = _ia_create_mask(_t74);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_cmp_sd(ddi_2 _a, ddi_2 _b, int imm8) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int (*op)(dd_I, dd_I);

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
    dst.i[0] = _ia_create_mask(_t75);
    dst.f[1] = a.f[1];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_cmp_ss(ddi_4 _a, ddi_4 _b, int imm8) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int (*op)(dd_I, dd_I);

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
    dd_I _t76;
    _t76 = a.f[0];
    dd_I _t77;
    _t77 = b.f[0];
    unsigned int _t78 = (op(_t76, _t77)) ? -1 : 0;
    dst.i[0] = _ia_create_mask(_t78);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_cvtepi32_pd(__m128i _a) {
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

ddi_8 _igen_dd_fb_mm256_cvtepi32_ps(__m256i _a) {
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

ddi_4 _igen_dd_fb_mm256_cvtpd_ps(ddi_4 _a) {
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

__m256i _igen_dd_fb_mm256_cvtps_epi32(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_cvtps_pd(ddi_4 _a) {
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

__m128i _igen_dd_fb_mm256_cvttpd_epi32(ddi_4 _a) {
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

__m128i _igen_dd_fb_mm256_cvtpd_epi32(ddi_4 _a) {
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

__m256i _igen_dd_fb_mm256_cvttps_epi32(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_extractf128_ps(ddi_8 _a, int imm8) {
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

ddi_2 _igen_dd_fb_mm256_extractf128_pd(ddi_4 _a, int imm8) {
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

ddi_8 _igen_dd_fb_mm256_permutevar_ps(ddi_8 _a, __m256i _b) {
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

ddi_4 _igen_dd_fb_mm_permutevar_ps(ddi_4 _a, __m128i _b) {
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

ddi_8 _igen_dd_fb_mm256_permute_ps(ddi_8 _a, int imm8) {
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

ddi_4 _igen_dd_fb_mm_permute_ps(ddi_4 _a, int imm8) {
    vec128s a;
    a.v = _a;
    vec128s dst;

    dst.f[0] = SELECT4_si(&a.f[0], (((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1)));
    dst.f[1] = SELECT4_si(&a.f[0], (((imm8) >> (2)) & ((1 << (3 - 2 + 1)) - 1)));
    dst.f[2] = SELECT4_si(&a.f[0], (((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1)));
    dst.f[3] = SELECT4_si(&a.f[0], (((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1)));

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_permutevar_pd(ddi_4 _a, __m256i _b) {
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

ddi_2 _igen_dd_fb_mm_permutevar_pd(ddi_2 _a, __m128i _b) {
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

ddi_4 _igen_dd_fb_mm256_permute_pd(ddi_4 _a, int imm8) {
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

ddi_2 _igen_dd_fb_mm_permute_pd(ddi_2 _a, int imm8) {
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

ddi_8 _igen_dd_fb_mm256_permute2f128_ps(ddi_8 _a, ddi_8 _b, int imm8) {
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

ddi_4 _igen_dd_fb_mm256_permute2f128_pd(ddi_4 _a, ddi_4 _b, int imm8) {
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

ddi_8 _igen_dd_fb_mm256_broadcast_ss(const dd_I *mem_addr) {
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

ddi_4 _igen_dd_fb_mm_broadcast_ss(const dd_I *mem_addr) {
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

ddi_4 _igen_dd_fb_mm256_broadcast_sd(const dd_I *mem_addr) {
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

ddi_8 _igen_dd_fb_mm256_broadcast_ps(ddi_4 *_mem_addr) {
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

ddi_4 _igen_dd_fb_mm256_broadcast_pd(ddi_2 *_mem_addr) {
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

ddi_8 _igen_dd_fb_mm256_insertf128_ps(ddi_8 _a, ddi_4 _b, int imm8) {
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

ddi_4 _igen_dd_fb_mm256_insertf128_pd(ddi_4 _a, ddi_2 _b, int imm8) {
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

ddi_4 _igen_dd_fb_mm256_load_pd(const dd_I *mem_addr) {
    vec256d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);

    return dst.v;
}

void _igen_dd_fb_mm256_store_pd(dd_I *mem_addr, ddi_4 _a) {
    vec256d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
}

ddi_8 _igen_dd_fb_mm256_load_ps(const dd_I *mem_addr) {
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

void _igen_dd_fb_mm256_store_ps(dd_I *mem_addr, ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_loadu_pd(const dd_I *mem_addr) {
    vec256d dst;

    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);

    return dst.v;
}

void _igen_dd_fb_mm256_storeu_pd(dd_I *mem_addr, ddi_4 _a) {
    vec256d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
}

ddi_8 _igen_dd_fb_mm256_loadu_ps(const dd_I *mem_addr) {
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

void _igen_dd_fb_mm256_storeu_ps(dd_I *mem_addr, ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_maskload_pd(const dd_I *mem_addr, __m256i _mask) {
    vec256i mask;
    mask.v = _mask;
    ddi_4 dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        if (vecBitAccess_i(mask.i, i + 63)) {
            dst.f[i / 64] = *(mem_addr + i / 64);
        } else {
            dst.f[i / 64] = zero_ddi;
        }
    }

    return dst;
}

void _igen_dd_fb_mm256_maskstore_pd(dd_I *mem_addr, __m256i _mask, ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_maskload_pd(const dd_I *mem_addr, __m128i _mask) {
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
            dst.f[i / 64] = zero_ddi;
        }
    }

    return dst.v;
}

void _igen_dd_fb_mm_maskstore_pd(dd_I *mem_addr, __m128i _mask, ddi_2 _a) {
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

ddi_8 _igen_dd_fb_mm256_maskload_ps(const dd_I *mem_addr, __m256i _mask) {
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
            dst.f[i / 32] = zero_ddi;
        }
    }

    return dst.v;
}

void _igen_dd_fb_mm256_maskstore_ps(dd_I *mem_addr, __m256i _mask, ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm_maskload_ps(const dd_I *mem_addr, __m128i _mask) {

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
            dst.f[i / 32] = zero_ddi;
        }
    }

    return dst.v;
}

void _igen_dd_fb_mm_maskstore_ps(dd_I *mem_addr, __m128i _mask, ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_movehdup_ps(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm256_moveldup_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_movedup_pd(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;

    dst.f[0] = a.f[0];
    dst.f[1] = a.f[0];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[2];

    return dst.v;
}

void _igen_dd_fb_mm256_stream_pd(dd_I *mem_addr, ddi_4 _a) {
    vec256d a;
    a.v = _a;

    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
}

void _igen_dd_fb_mm256_stream_ps(dd_I *mem_addr, ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm256_rcp_ps(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dd_I _t65 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dst.f[i / 32] = _ia_div_dd(_t65, a.f[i / 32]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_rsqrt_ps(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dd_I _t66 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t67 = SQRT_s(a.f[i / 32]);
        dst.f[i / 32] = _ia_div_dd(_t66, _t67);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_sqrt_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_sqrt_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_round_pd(ddi_4 _a, int rounding) {
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

ddi_8 _igen_dd_fb_mm256_round_ps(ddi_8 _a, int rounding) {
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

ddi_4 _igen_dd_fb_mm256_unpackhi_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    INTERLEAVE_HIGH_QWORDS_dd(&dst.f[0], &a.f[0], &b.f[0]);
    INTERLEAVE_HIGH_QWORDS_dd(&dst.f[2], &a.f[2], &b.f[2]);

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_unpackhi_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;

    INTERLEAVE_HIGH_DWORDS_ss(&dst.f[0], &a.f[0], &b.f[0]);
    INTERLEAVE_HIGH_DWORDS_ss(&dst.f[4], &a.f[4], &b.f[4]);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_unpacklo_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;

    INTERLEAVE_QWORDS_dd(&dst.f[0], &a.f[0], &b.f[0]);
    INTERLEAVE_QWORDS_dd(&dst.f[2], &a.f[2], &b.f[2]);

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_unpacklo_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;

    INTERLEAVE_DWORDS_ss(&dst.f[0], &a.f[0], &b.f[0]);
    INTERLEAVE_DWORDS_ss(&dst.f[4], &a.f[4], &b.f[4]);

    return dst.v;
}

int _igen_dd_fb_mm256_testz_pd(ddi_4 _a, ddi_4 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm256_testc_pd(ddi_4 _a, ddi_4 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm256_testnzc_pd(ddi_4 _a, ddi_4 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm_testz_pd(ddi_2 _a, ddi_2 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm_testc_pd(ddi_2 _a, ddi_2 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm_testnzc_pd(ddi_2 _a, ddi_2 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm256_testz_ps(ddi_8 _a, ddi_8 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm256_testc_ps(ddi_8 _a, ddi_8 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm256_testnzc_ps(ddi_8 _a, ddi_8 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm_testz_ps(ddi_4 _a, ddi_4 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm_testc_ps(ddi_4 _a, ddi_4 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm_testnzc_ps(ddi_4 _a, ddi_4 _b) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

int _igen_dd_fb_mm256_movemask_pd(ddi_4 _a) {
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

int _igen_dd_fb_mm256_movemask_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_setzero_pd() {
    vec256d dst;

    dst.f[0] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[1] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[2] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[3] = _ia_set_dd(-0, 0.0, 0, 0.0);

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_setzero_ps() {
    vec256s dst;

    dst.f[0] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[1] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[2] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[3] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[4] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[5] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[6] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[7] = _ia_set_dd(-0, 0.0, 0, 0.0);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_set_pd(dd_I e3, dd_I e2, dd_I e1, dd_I e0) {
    vec256d dst;

    dst.f[0] = e0;
    dst.f[1] = e1;
    dst.f[2] = e2;
    dst.f[3] = e3;

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_set_ps(dd_I e7, dd_I e6, dd_I e5, dd_I e4, dd_I e3, dd_I e2,
                          dd_I e1, dd_I e0) {
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

ddi_4 _igen_dd_fb_mm256_setr_pd(dd_I e3, dd_I e2, dd_I e1, dd_I e0) {
    vec256d dst;

    dst.f[0] = e3;
    dst.f[1] = e2;
    dst.f[2] = e1;
    dst.f[3] = e0;

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_setr_ps(dd_I e7, dd_I e6, dd_I e5, dd_I e4, dd_I e3, dd_I e2,
                           dd_I e1, dd_I e0) {
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

ddi_4 _igen_dd_fb_mm256_set1_pd(dd_I a) {
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = a;
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_set1_ps(dd_I a) {
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dst.f[i / 32] = a;
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_castpd_ps(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_castps_pd(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

__m256i _igen_dd_fb_mm256_castps_si256(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256i dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    __m256i _ret;
    _ret = dst.v;
    return _ret;
}

__m256i _igen_dd_fb_mm256_castpd_si256(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256i dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    __m256i _ret;
    _ret = dst.v;
    return _ret;
}

ddi_8 _igen_dd_fb_mm256_castsi256_ps(__m256i _a) {
    vec256i a;
    a.v = _a;
    vec256s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_castsi256_pd(__m256i _a) {
    vec256i a;
    a.v = _a;
    vec256d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_castps256_ps128(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec128s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_2 _igen_dd_fb_mm256_castpd256_pd128(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec128d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_castps128_ps256(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec256s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_castpd128_pd256(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec256d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_zextps128_ps256(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec256s dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_zextpd128_pd256(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec256d dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_floor_ps(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm256_ceil_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_floor_pd(ddi_4 _a) {
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

ddi_4 _igen_dd_fb_mm256_ceil_pd(ddi_4 _a) {
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

ddi_4 _igen_dd_fb_mm_undefined_ps() {
    vec128s dst;
    return dst.v;
}

ddi_2 _igen_dd_fb_mm_undefined_pd() {
    vec128d dst;
    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_undefined_ps() {
    vec256s dst;
    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_undefined_pd() {
    vec256d dst;
    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_set_m128(ddi_4 _hi, ddi_4 _lo) {
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

ddi_4 _igen_dd_fb_mm256_set_m128d(ddi_2 _hi, ddi_2 _lo) {
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

ddi_8 _igen_dd_fb_mm256_setr_m128(ddi_4 _lo, ddi_4 _hi) {
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

ddi_4 _igen_dd_fb_mm256_setr_m128d(ddi_2 _lo, ddi_2 _hi) {
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

ddi_8 _igen_dd_fb_mm256_loadu2_m128(const dd_I *hiaddr, const dd_I *loaddr) {
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

ddi_4 _igen_dd_fb_mm256_loadu2_m128d(const dd_I *hiaddr, const dd_I *loaddr) {
    vec256d dst;

    dst.f[0] = *(loaddr + 0);
    dst.f[1] = *(loaddr + 1);

    dst.f[2] = *(hiaddr + 0);
    dst.f[3] = *(hiaddr + 1);

    return dst.v;
}

void _igen_dd_fb_mm256_storeu2_m128(dd_I *hiaddr, dd_I *loaddr, ddi_8 _a) {
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

void _igen_dd_fb_mm256_storeu2_m128d(dd_I *hiaddr, dd_I *loaddr, ddi_4 _a) {
    vec256d a;
    a.v = _a;

    *(loaddr + 0) = a.f[0];
    *(loaddr + 1) = a.f[1];

    *(hiaddr + 0) = a.f[2];
    *(hiaddr + 1) = a.f[3];
}

ddi_2 _igen_dd_fb_mm_broadcastsd_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm256_broadcastsd_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_broadcastss_ps(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_broadcastss_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_i32gather_pd(const dd_I *base_addr, __m128i _vindex,
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

ddi_4 _igen_dd_fb_mm256_i32gather_pd(const dd_I *base_addr, __m128i _vindex,
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

ddi_4 _igen_dd_fb_mm_i32gather_ps(const dd_I *base_addr, __m128i _vindex,
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

ddi_8 _igen_dd_fb_mm256_i32gather_ps(const dd_I *base_addr, __m256i _vindex,
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

ddi_2 _igen_dd_fb_mm_i64gather_pd(const dd_I *base_addr, __m128i _vindex,
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

ddi_4 _igen_dd_fb_mm256_i64gather_pd(const dd_I *base_addr, __m256i _vindex,
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

ddi_4 _igen_dd_fb_mm_i64gather_ps(const dd_I *base_addr, __m128i _vindex,
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
    dst.f[2] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[3] = _ia_set_dd(-0, 0.0, 0, 0.0);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_i64gather_ps(const dd_I *base_addr, __m256i _vindex,
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

ddi_2 _igen_dd_fb_mm_mask_i32gather_pd(ddi_2 _src, const dd_I *base_addr,
                                  __m128i _vindex, ddi_2 _mask, int scale) {
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

ddi_4 _igen_dd_fb_mm256_mask_i32gather_pd(ddi_4 _src, const dd_I *base_addr,
                                     __m128i _vindex, ddi_4 _mask, int scale) {
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

ddi_4 _igen_dd_fb_mm_mask_i32gather_ps(ddi_4 _src, const dd_I *base_addr,
                                  __m128i _vindex, ddi_4 _mask, int scale) {
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

ddi_8 _igen_dd_fb_mm256_mask_i32gather_ps(ddi_8 _src, const dd_I *base_addr,
                                     __m256i _vindex, ddi_8 _mask, int scale) {
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

ddi_2 _igen_dd_fb_mm_mask_i64gather_pd(ddi_2 _src, const dd_I *base_addr,
                                  __m128i _vindex, ddi_2 _mask, int scale) {
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

ddi_4 _igen_dd_fb_mm256_mask_i64gather_pd(ddi_4 _src, const dd_I *base_addr,
                                     __m256i _vindex, ddi_4 _mask, int scale) {
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

ddi_4 _igen_dd_fb_mm_mask_i64gather_ps(ddi_4 _src, const dd_I *base_addr,
                                  __m128i _vindex, ddi_4 _mask, int scale) {
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
    mask.f[2] = _ia_set_dd(-0, 0.0, 0, 0.0);
    mask.f[3] = _ia_set_dd(-0, 0.0, 0, 0.0);

    dst.f[2] = _ia_set_dd(-0, 0.0, 0, 0.0);
    dst.f[3] = _ia_set_dd(-0, 0.0, 0, 0.0);

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_mask_i64gather_ps(ddi_4 _src, const dd_I *base_addr,
                                     __m256i _vindex, ddi_4 _mask, int scale) {
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

ddi_4 _igen_dd_fb_mm256_permute4x64_pd(ddi_4 _a, int imm8) {
    vec256d a;
    a.v = _a;
    vec256d dst;

    dst.f[0] = SELECT4_di(&a.f[0], (((imm8) >> (0)) & ((1 << (1 - 0 + 1)) - 1)));
    dst.f[1] = SELECT4_di(&a.f[0], (((imm8) >> (2)) & ((1 << (3 - 2 + 1)) - 1)));
    dst.f[2] = SELECT4_di(&a.f[0], (((imm8) >> (4)) & ((1 << (5 - 4 + 1)) - 1)));
    dst.f[3] = SELECT4_di(&a.f[0], (((imm8) >> (6)) & ((1 << (7 - 6 + 1)) - 1)));

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_permutevar8x32_ps(ddi_8 _a, __m256i _idx) {
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

ddi_2 _igen_dd_fb_mm_fmadd_pd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
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
        dd_I _t122 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = _ia_add_dd(_t122, c.f[i / 64]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_fmadd_pd(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
        dd_I _t123 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = _ia_add_dd(_t123, c.f[i / 64]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fmadd_ps(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
        dd_I _t124 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = _ia_add_dd(_t124, c.f[i / 32]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_fmadd_ps(ddi_8 _a, ddi_8 _b, ddi_8 _c) {
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
        dd_I _t125 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = _ia_add_dd(_t125, c.f[i / 32]);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_fmadd_sd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;

    dd_I _t126 = _ia_mul_dd(a.f[0], b.f[0]);
    dst.f[0] = _ia_add_dd(_t126, c.f[0]);
    dst.f[1] = a.f[1];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fmadd_ss(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;

    dd_I _t127 = _ia_mul_dd(a.f[0], b.f[0]);
    dst.f[0] = _ia_add_dd(_t127, c.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_fmaddsub_pd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
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
            dd_I _t128 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_sub_dd(_t128, c.f[i / 64]);
        } else {
            dd_I _t129 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_add_dd(_t129, c.f[i / 64]);
        }
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_fmaddsub_pd(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
            dd_I _t130 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_sub_dd(_t130, c.f[i / 64]);
        } else {
            dd_I _t131 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_add_dd(_t131, c.f[i / 64]);
        }
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fmaddsub_ps(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
            dd_I _t132 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = _ia_sub_dd(_t132, c.f[i / 32]);
        } else {
            dd_I _t133 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = _ia_add_dd(_t133, c.f[i / 32]);
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_fmaddsub_ps(ddi_8 _a, ddi_8 _b, ddi_8 _c) {
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
            dd_I _t134 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = _ia_sub_dd(_t134, c.f[i / 32]);
        } else {
            dd_I _t135 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = _ia_add_dd(_t135, c.f[i / 32]);
        }
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_fmsub_pd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
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
        dd_I _t136 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = _ia_sub_dd(_t136, c.f[i / 64]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_fmsub_pd(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
        dd_I _t137 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = _ia_sub_dd(_t137, c.f[i / 64]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fmsub_ps(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
        dd_I _t138 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = _ia_sub_dd(_t138, c.f[i / 32]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_fmsub_ps(ddi_8 _a, ddi_8 _b, ddi_8 _c) {
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
        dd_I _t139 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = _ia_sub_dd(_t139, c.f[i / 32]);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_fmsub_sd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;

    dd_I _t140 = _ia_mul_dd(a.f[0], b.f[0]);
    dst.f[0] = _ia_sub_dd(_t140, c.f[0]);
    dst.f[1] = a.f[1];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fmsub_ss(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;

    dd_I _t141 = _ia_mul_dd(a.f[0], b.f[0]);
    dst.f[0] = _ia_sub_dd(_t141, c.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_fmsubadd_pd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
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
            dd_I _t142 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_add_dd(_t142, c.f[i / 64]);
        } else {
            dd_I _t143 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_sub_dd(_t143, c.f[i / 64]);
        }
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_fmsubadd_pd(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
            dd_I _t144 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_add_dd(_t144, c.f[i / 64]);
        } else {
            dd_I _t145 = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = _ia_sub_dd(_t145, c.f[i / 64]);
        }
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fmsubadd_ps(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
            dd_I _t146 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = _ia_add_dd(_t146, c.f[i / 32]);
        } else {
            dd_I _t147 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = _ia_sub_dd(_t147, c.f[i / 32]);
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_fmsubadd_ps(ddi_8 _a, ddi_8 _b, ddi_8 _c) {
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
            dd_I _t148 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = _ia_add_dd(_t148, c.f[i / 32]);
        } else {
            dd_I _t149 = _ia_mul_dd(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = _ia_sub_dd(_t149, c.f[i / 32]);
        }
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_fnmadd_pd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
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
        dd_I _t150 = _ia_neg_dd(_ia_mul_dd(a.f[i / 64], b.f[i / 64]));
        dst.f[i / 64] = _ia_add_dd(_t150, c.f[i / 64]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_fnmadd_pd(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
        dd_I _t151 = _ia_neg_dd(_ia_mul_dd(a.f[i / 64], b.f[i / 64]));
        dst.f[i / 64] = _ia_add_dd(_t151, c.f[i / 64]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fnmadd_ps(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
        dd_I _t152 = _ia_neg_dd(_ia_mul_dd(a.f[i / 32], b.f[i / 32]));
        a.f[i / 32] = _ia_add_dd(_t152, c.f[i / 32]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_fnmadd_ps(ddi_8 _a, ddi_8 _b, ddi_8 _c) {
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
        dd_I _t153 = _ia_neg_dd(_ia_mul_dd(a.f[i / 32], b.f[i / 32]));
        a.f[i / 32] = _ia_add_dd(_t153, c.f[i / 32]);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_fnmadd_sd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;

    dd_I _t154 = _ia_neg_dd(_ia_mul_dd(a.f[0], b.f[0]));
    dst.f[0] = _ia_add_dd(_t154, c.f[0]);
    dst.f[1] = a.f[1];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fnmadd_ss(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;

    dd_I _t155 = _ia_neg_dd(_ia_mul_dd(a.f[0], b.f[0]));
    dst.f[0] = _ia_add_dd(_t155, c.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_fnmsub_pd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
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
        dd_I _t156 = _ia_neg_dd(_ia_mul_dd(a.f[i / 64], b.f[i / 64]));
        dst.f[i / 64] = _ia_sub_dd(_t156, c.f[i / 64]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_fnmsub_pd(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
        dd_I _t157 = _ia_neg_dd(_ia_mul_dd(a.f[i / 64], b.f[i / 64]));
        dst.f[i / 64] = _ia_sub_dd(_t157, c.f[i / 64]);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fnmsub_ps(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
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
        dd_I _t158 = _ia_neg_dd(_ia_mul_dd(a.f[i / 32], b.f[i / 32]));
        dst.f[i / 32] = _ia_sub_dd(_t158, c.f[i / 32]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_fnmsub_ps(ddi_8 _a, ddi_8 _b, ddi_8 _c) {
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
        dd_I _t159 = _ia_neg_dd(_ia_mul_dd(a.f[i / 32], b.f[i / 32]));
        dst.f[i / 32] = _ia_sub_dd(_t159, c.f[i / 32]);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_fnmsub_sd(ddi_2 _a, ddi_2 _b, ddi_2 _c) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d c;
    c.v = _c;
    vec128d dst;

    dd_I _t160 = _ia_neg_dd(_ia_mul_dd(a.f[0], b.f[0]));
    dst.f[0] = _ia_sub_dd(_t160, c.f[0]);
    dst.f[1] = a.f[1];

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_fnmsub_ss(ddi_4 _a, ddi_4 _b, ddi_4 _c) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s c;
    c.v = _c;
    vec128s dst;

    dd_I _t161 = _ia_neg_dd(_ia_mul_dd(a.f[0], b.f[0]));
    dst.f[0] = _ia_sub_dd(_t161, c.f[0]);
    dst.f[1] = a.f[1];
    dst.f[2] = a.f[2];
    dst.f[3] = a.f[3];

    return dst.v;
}

unsigned int _igen_dd_fb_castf32_u32(dd_I a) {
    unsigned int dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    unsigned int _ret;
    _ret = dst;
    return _ret;
}

long _igen_dd_fb_castf64_u64(dd_I a) {
    long dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    long _ret;
    _ret = dst;
    return _ret;
}

dd_I _igen_dd_fb_castu32_f32(unsigned int a) {
    dd_I dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst;
}

dd_I _igen_dd_fb_castu64_f64(long a) {
    dd_I dst;
    fprintf(stderr, "Error: Intrinsic not supported\n");
    return dst;
}

ddi_2 _igen_dd_fb_mm_acos_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_acos_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_acosh_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_acosh_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_asin_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_asin_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_asinh_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_asinh_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_atan_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_atan_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_atan2_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dd_I _t162 = _ia_div_dd(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = ATAN_d(_t162);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_atan2_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dd_I _t163 = _ia_div_dd(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = ATAN_s(_t163);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_atanh_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_atanh_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_cbrt_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_cbrt_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_cdfnorm_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_cdfnorm_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_cdfnorminv_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_cdfnorminv_ps(ddi_4 _a) {
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

ddi_4 _igen_dd_fb_mm_cexp_ps(ddi_4 _a) {
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

ddi_4 _igen_dd_fb_mm_clog_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_cos_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_cos_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_cosd_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_cosd_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_cosh_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_cosh_ps(ddi_4 _a) {
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

ddi_4 _igen_dd_fb_mm_csqrt_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_erf_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_erf_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_erfc_pd(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dd_I _t164 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t165 = ERF_d(a.f[i / 64]);
        dst.f[i / 64] = _ia_sub_dd(_t164, _t165);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_erfc_ps(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dd_I _t166 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t167 = ERF_s(a.f[i / 32]);
        dst.f[i / 32] = _ia_sub_dd(_t166, _t167);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_erfcinv_pd(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dd_I _t168 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t169 = ERF_d(a.f[i / 64]);
        dd_I _t170 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t171 = _ia_sub_dd(_t168, _t169);
        dst.f[i / 64] = _ia_div_dd(_t170, _t171);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_erfcinv_ps(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dd_I _t172 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t173 = ERF_s(a.f[i / 32]);
        dd_I _t174 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t175 = _ia_sub_dd(_t172, _t173);
        dst.f[i / 32] = _ia_div_dd(_t174, _t175);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_erfinv_pd(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dd_I _t176 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t177 = ERF_d(a.f[i / 64]);
        dst.f[i / 64] = _ia_div_dd(_t176, _t177);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_erfinv_ps(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dd_I _t178 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t179 = ERF_s(a.f[i / 32]);
        dst.f[i / 32] = _ia_div_dd(_t178, _t179);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_exp_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_exp_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_exp10_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_exp10_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_exp2_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_exp2_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_expm1_pd(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dd_I _t180 = expe_d(a.f[i / 64]);
        dd_I _t181 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dst.f[i / 64] = _ia_sub_dd(_t180, _t181);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_expm1_ps(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dd_I _t182 = expe_s(a.f[i / 32]);
        dd_I _t183 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dst.f[i / 32] = _ia_sub_dd(_t182, _t183);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_hypot_pd(ddi_2 _a, ddi_2 _b) {
    vec128d a;
    a.v = _a;
    vec128d b;
    b.v = _b;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dd_I _t184 = _ia_mul_dd(a.f[i / 64], a.f[i / 64]);
        dd_I _t185 = _ia_mul_dd(b.f[i / 64], b.f[i / 64]);
        dd_I _t186 = _ia_add_dd(_t184, _t185);
        dst.f[i / 64] = SQRT_d(_t186);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_hypot_ps(ddi_4 _a, ddi_4 _b) {
    vec128s a;
    a.v = _a;
    vec128s b;
    b.v = _b;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dd_I _t187 = _ia_mul_dd(a.f[i / 32], a.f[i / 32]);
        dd_I _t188 = _ia_mul_dd(b.f[i / 32], b.f[i / 32]);
        dd_I _t189 = _ia_add_dd(_t187, _t188);
        dst.f[i / 32] = SQRT_s(_t189);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_invcbrt_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_invcbrt_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_invsqrt_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_invsqrt_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_log_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_log_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_log10_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_log10_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_log1p_pd(ddi_2 _a) {
    vec128d a;
    a.v = _a;
    vec128d dst;
    int j;
    int i;

    for (j = 0; j <= 1; ++j) {
        i = j * 64;
        dd_I _t190 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t191 = _ia_add_dd(_t190, a.f[i / 64]);
        dst.f[i / 64] = ln_d(_t191);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm_log1p_ps(ddi_4 _a) {
    vec128s a;
    a.v = _a;
    vec128s dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 32;
        dd_I _t192 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t193 = _ia_add_dd(_t192, a.f[i / 32]);
        dst.f[i / 32] = ln_s(_t193);
    }

    return dst.v;
}

ddi_2 _igen_dd_fb_mm_log2_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_log2_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_logb_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_logb_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_pow_pd(ddi_2 _a, ddi_2 _b) {
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

ddi_4 _igen_dd_fb_mm_pow_ps(ddi_4 _a, ddi_4 _b) {
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

ddi_2 _igen_dd_fb_mm_sin_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_sin_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_sincos_pd(ddi_2 *_mem_addr, ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_sincos_ps(ddi_4 *_mem_addr, ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_sind_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_sind_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_sinh_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_sinh_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_svml_ceil_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_svml_ceil_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_svml_floor_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_svml_floor_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_svml_round_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_svml_round_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_svml_sqrt_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_svml_sqrt_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_tan_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_tan_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_tand_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_tand_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_tanh_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_tanh_ps(ddi_4 _a) {
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

ddi_2 _igen_dd_fb_mm_trunc_pd(ddi_2 _a) {
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

ddi_4 _igen_dd_fb_mm_trunc_ps(ddi_4 _a) {
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

ddi_4 _igen_dd_fb_mm256_acos_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_acos_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_acosh_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_acosh_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_asin_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_asin_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_asinh_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_asinh_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_atan_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_atan_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_atan2_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dd_I _t194 = _ia_div_dd(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = ATAN_d(_t194);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_atan2_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dd_I _t195 = _ia_div_dd(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = ATAN_s(_t195);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_atanh_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_atanh_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_cbrt_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_cbrt_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_cdfnorm_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_cdfnorm_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_cdfnorminv_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_cdfnorminv_ps(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm256_cexp_ps(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm256_clog_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_cos_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_cos_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_cosd_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_cosd_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_cosh_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_cosh_ps(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm256_csqrt_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_erf_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_erf_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_erfc_pd(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dd_I _t196 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t197 = ERF_d(a.f[i / 64]);
        dst.f[i / 64] = _ia_sub_dd(_t196, _t197);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_erfc_ps(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dd_I _t198 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t199 = ERF_s(a.f[i / 32]);
        dst.f[i / 32] = _ia_sub_dd(_t198, _t199);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_erfcinv_pd(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dd_I _t200 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t201 = ERF_d(a.f[i / 64]);
        dd_I _t202 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t203 = _ia_sub_dd(_t200, _t201);
        dst.f[i / 64] = _ia_div_dd(_t202, _t203);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_erfcinv_ps(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dd_I _t204 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t205 = ERF_s(a.f[i / 32]);
        dd_I _t206 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t207 = _ia_sub_dd(_t204, _t205);
        dst.f[i / 32] = _ia_div_dd(_t206, _t207);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_erfinv_pd(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dd_I _t208 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t209 = ERF_d(a.f[i / 64]);
        dst.f[i / 64] = _ia_div_dd(_t208, _t209);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_erfinv_ps(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dd_I _t210 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t211 = ERF_s(a.f[i / 32]);
        dst.f[i / 32] = _ia_div_dd(_t210, _t211);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_exp_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_exp_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_exp10_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_exp10_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_exp2_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_exp2_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_expm1_pd(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dd_I _t212 = expe_d(a.f[i / 64]);
        dd_I _t213 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dst.f[i / 64] = _ia_sub_dd(_t212, _t213);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_expm1_ps(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dd_I _t214 = expe_s(a.f[i / 32]);
        dd_I _t215 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dst.f[i / 32] = _ia_sub_dd(_t214, _t215);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_hypot_pd(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dd_I _t216 = _ia_mul_dd(a.f[i / 64], a.f[i / 64]);
        dd_I _t217 = _ia_mul_dd(b.f[i / 64], b.f[i / 64]);
        dd_I _t218 = _ia_add_dd(_t216, _t217);
        dst.f[i / 64] = SQRT_d(_t218);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_hypot_ps(ddi_8 _a, ddi_8 _b) {
    vec256s a;
    a.v = _a;
    vec256s b;
    b.v = _b;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dd_I _t219 = _ia_mul_dd(a.f[i / 32], a.f[i / 32]);
        dd_I _t220 = _ia_mul_dd(b.f[i / 32], b.f[i / 32]);
        dd_I _t221 = _ia_add_dd(_t219, _t220);
        dst.f[i / 32] = SQRT_s(_t221);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_invcbrt_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_invcbrt_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_invsqrt_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_invsqrt_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_log_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_log_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_log10_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_log10_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_log1p_pd(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dd_I _t222 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t223 = _ia_add_dd(_t222, a.f[i / 64]);
        dst.f[i / 64] = ln_d(_t223);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm256_log1p_ps(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    vec256s dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 32;
        dd_I _t224 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t225 = _ia_add_dd(_t224, a.f[i / 32]);
        dst.f[i / 32] = ln_s(_t225);
    }

    return dst.v;
}

ddi_4 _igen_dd_fb_mm256_log2_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_log2_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_logb_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_logb_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_pow_pd(ddi_4 _a, ddi_4 _b) {
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

ddi_8 _igen_dd_fb_mm256_pow_ps(ddi_8 _a, ddi_8 _b) {
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

ddi_4 _igen_dd_fb_mm256_sin_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_sin_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_sincos_pd(ddi_4 *_mem_addr, ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_sincos_ps(ddi_8 *_mem_addr, ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_sind_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_sind_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_sinh_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_sinh_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_svml_ceil_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_svml_ceil_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_svml_floor_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_svml_floor_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_svml_round_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_svml_round_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_svml_sqrt_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_svml_sqrt_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_tan_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_tan_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_tand_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_tand_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_tanh_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_tanh_ps(ddi_8 _a) {
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

ddi_4 _igen_dd_fb_mm256_trunc_pd(ddi_4 _a) {
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

ddi_8 _igen_dd_fb_mm256_trunc_ps(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm256_cvtph_ps(__m128i _a) {
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

__m128i _igen_dd_fb_mm256_cvtps_ph(ddi_8 _a, int rounding) {
    fprintf(stderr, "Error: Intrinsic not supported\n");
}

dd_I _igen_dd_fb_mm256_cvtss_f32(ddi_8 _a) {
    vec256s a;
    a.v = _a;
    dd_I dst;

    dst = a.f[0];
    return dst;
}

dd_I _igen_dd_fb_mm256_cvtsd_f64(ddi_4 _a) {
    vec256d a;
    a.v = _a;
    dd_I dst;

    dst = a.f[0];
    return dst;
}

ddi_8 _igen_dd_fb_mm512_acos_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_acos_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_acos_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_acos_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_acosh_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_acosh_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_acosh_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_acosh_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_asin_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_asin_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_asin_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_asin_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_asinh_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_asinh_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_asinh_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_asinh_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_atan2_pd(ddi_8 _a, ddi_8 _b) {
    vec512d a;
    a.v = _a;
    vec512d b;
    b.v = _b;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dd_I _t226 = _ia_div_dd(a.f[i / 64], b.f[i / 64]);
        dst.f[i / 64] = ATAN_d(_t226);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_mask_atan2_pd(ddi_8 _src, __mmask8 k, ddi_8 _a,
                                 ddi_8 _b) {
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
            dd_I _t227 = _ia_div_dd(a.f[i / 64], b.f[i / 64]);
            dst.f[i / 64] = ATAN_d(_t227);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_atan2_ps(ddi_16 _a, ddi_16 _b) {
    vec512s a;
    a.v = _a;
    vec512s b;
    b.v = _b;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dd_I _t228 = _ia_div_dd(a.f[i / 32], b.f[i / 32]);
        dst.f[i / 32] = ATAN_s(_t228);
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_mask_atan2_ps(ddi_16 _src, __mmask16 k, ddi_16 _a,
                                  ddi_16 _b) {
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
            dd_I _t229 = _ia_div_dd(a.f[i / 32], b.f[i / 32]);
            dst.f[i / 32] = ATAN_s(_t229);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_atan_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_atan_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_atan_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_atan_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_atanh_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_atanh_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_atanh_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_atanh_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_cbrt_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_cbrt_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_cbrt_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_cbrt_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_cdfnorm_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_cdfnorm_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_cdfnorm_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_cdfnorm_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_cdfnorminv_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_cdfnorminv_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_cdfnorminv_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_cdfnorminv_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_ceil_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_ceil_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_ceil_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_ceil_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_cos_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_cos_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_cos_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_cos_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_cosd_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_cosd_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_cosd_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_cosd_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_cosh_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_cosh_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_cosh_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_cosh_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_erf_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_erf_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_erfc_pd(ddi_8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dd_I _t230 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t231 = ERF_d(a.f[i / 64]);
        dst.f[i / 64] = _ia_sub_dd(_t230, _t231);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_mask_erfc_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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
            dd_I _t232 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t233 = ERF_d(a.f[i / 64]);
            dst.f[i / 64] = _ia_sub_dd(_t232, _t233);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_erf_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_erf_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_erfc_ps(ddi_16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dd_I _t234 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t235 = ERF_s(a.f[i / 32]);
        dst.f[i / 32] = _ia_sub_dd(_t234, _t235);
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_mask_erfc_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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
            dd_I _t236 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t237 = ERF_s(a.f[i / 32]);
            dst.f[i / 32] = _ia_sub_dd(_t236, _t237);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_erfinv_pd(ddi_8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dd_I _t238 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t239 = ERF_d(a.f[i / 64]);
        dst.f[i / 64] = _ia_div_dd(_t238, _t239);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_mask_erfinv_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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
            dd_I _t240 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t241 = ERF_d(a.f[i / 64]);
            dst.f[i / 64] = _ia_div_dd(_t240, _t241);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_erfinv_ps(ddi_16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dd_I _t242 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t243 = ERF_s(a.f[i / 32]);
        dst.f[i / 32] = _ia_div_dd(_t242, _t243);
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_mask_erfinv_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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
            dd_I _t244 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t245 = ERF_s(a.f[i / 32]);
            dst.f[i / 32] = _ia_div_dd(_t244, _t245);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_erfcinv_pd(ddi_8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dd_I _t246 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t247 = ERF_d(a.f[i / 64]);
        dd_I _t248 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t249 = _ia_sub_dd(_t246, _t247);
        dst.f[i / 64] = _ia_div_dd(_t248, _t249);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_mask_erfcinv_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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
            dd_I _t250 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t251 = ERF_d(a.f[i / 64]);
            dd_I _t252 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t253 = _ia_sub_dd(_t250, _t251);
            dst.f[i / 64] = _ia_div_dd(_t252, _t253);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_erfcinv_ps(ddi_16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dd_I _t254 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t255 = ERF_s(a.f[i / 32]);
        dd_I _t256 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t257 = _ia_sub_dd(_t254, _t255);
        dst.f[i / 32] = _ia_div_dd(_t256, _t257);
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_mask_erfcinv_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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
            dd_I _t258 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t259 = ERF_s(a.f[i / 32]);
            dd_I _t260 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t261 = _ia_sub_dd(_t258, _t259);
            dst.f[i / 32] = _ia_div_dd(_t260, _t261);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_exp10_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_exp10_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_exp10_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_exp10_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_exp2_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_exp2_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_exp2_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_exp2_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_exp_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_exp_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_exp_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_exp_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_expm1_pd(ddi_8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dd_I _t262 = expe_d(a.f[i / 64]);
        dd_I _t263 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dst.f[i / 64] = _ia_sub_dd(_t262, _t263);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_mask_expm1_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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
            dd_I _t264 = expe_d(a.f[i / 64]);
            dd_I _t265 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dst.f[i / 64] = _ia_sub_dd(_t264, _t265);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_expm1_ps(ddi_16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dd_I _t266 = expe_s(a.f[i / 32]);
        dd_I _t267 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dst.f[i / 32] = _ia_sub_dd(_t266, _t267);
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_mask_expm1_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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
            dd_I _t268 = expe_s(a.f[i / 32]);
            dd_I _t269 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dst.f[i / 32] = _ia_sub_dd(_t268, _t269);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_floor_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_floor_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_floor_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_floor_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_hypot_pd(ddi_8 _a, ddi_8 _b) {
    vec512d a;
    a.v = _a;
    vec512d b;
    b.v = _b;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dd_I _t270 = _ia_mul_dd(a.f[i / 64], a.f[i / 64]);
        dd_I _t271 = _ia_mul_dd(b.f[i / 64], b.f[i / 64]);
        dd_I _t272 = _ia_add_dd(_t270, _t271);
        dst.f[i / 64] = SQRT_d(_t272);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_mask_hypot_pd(ddi_8 _src, __mmask8 k, ddi_8 _a,
                                 ddi_8 _b) {
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
            dd_I _t273 = _ia_mul_dd(a.f[i / 64], a.f[i / 64]);
            dd_I _t274 = _ia_mul_dd(b.f[i / 64], b.f[i / 64]);
            dd_I _t275 = _ia_add_dd(_t273, _t274);
            dst.f[i / 64] = SQRT_d(_t275);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_hypot_ps(ddi_16 _a, ddi_16 _b) {
    vec512s a;
    a.v = _a;
    vec512s b;
    b.v = _b;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dd_I _t276 = _ia_mul_dd(a.f[i / 32], a.f[i / 32]);
        dd_I _t277 = _ia_mul_dd(b.f[i / 32], b.f[i / 32]);
        dd_I _t278 = _ia_add_dd(_t276, _t277);
        dst.f[i / 32] = SQRT_s(_t278);
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_mask_hypot_ps(ddi_16 _src, __mmask16 k, ddi_16 _a,
                                  ddi_16 _b) {
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
            dd_I _t279 = _ia_mul_dd(a.f[i / 32], a.f[i / 32]);
            dd_I _t280 = _ia_mul_dd(b.f[i / 32], b.f[i / 32]);
            dd_I _t281 = _ia_add_dd(_t279, _t280);
            dst.f[i / 32] = SQRT_s(_t281);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_invsqrt_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_invsqrt_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_invsqrt_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_invsqrt_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_log10_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_log10_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_log10_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_log10_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_log1p_pd(ddi_8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dd_I _t282 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t283 = _ia_add_dd(_t282, a.f[i / 64]);
        dst.f[i / 64] = ln_d(_t283);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_mask_log1p_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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
            dd_I _t284 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t285 = _ia_add_dd(_t284, a.f[i / 64]);
            dst.f[i / 64] = ln_d(_t285);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_log1p_ps(ddi_16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dd_I _t286 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
        dd_I _t287 = _ia_add_dd(_t286, a.f[i / 32]);
        dst.f[i / 32] = ln_s(_t287);
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_mask_log1p_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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
            dd_I _t288 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
            dd_I _t289 = _ia_add_dd(_t288, a.f[i / 32]);
            dst.f[i / 32] = ln_s(_t289);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_log2_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_log2_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_log_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_log_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_log_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_log_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_logb_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_logb_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_logb_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_logb_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_nearbyint_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_nearbyint_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_nearbyint_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_nearbyint_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_pow_pd(ddi_8 _a, ddi_8 _b) {
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

ddi_8 _igen_dd_fb_mm512_mask_pow_pd(ddi_8 _src, __mmask8 k, ddi_8 _a, ddi_8 _b) {
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

ddi_16 _igen_dd_fb_mm512_pow_ps(ddi_16 _a, ddi_16 _b) {
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

ddi_16 _igen_dd_fb_mm512_mask_pow_ps(ddi_16 _src, __mmask16 k, ddi_16 _a,
                                ddi_16 _b) {
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

ddi_8 _igen_dd_fb_mm512_recip_pd(ddi_8 _a) {
    vec512d a;
    a.v = _a;
    vec512d dst;
    int j;
    int i;

    for (j = 0; j <= 7; ++j) {
        i = j * 64;
        dd_I _t290 = _ia_set_dd(-1, 0.0, 1, 0.0);
        dst.f[i / 64] = _ia_div_dd(_t290, a.f[i / 64]);
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_mask_recip_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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
            dd_I _t291 = _ia_set_dd(-1, 0.0, 1, 0.0);
            dst.f[i / 64] = _ia_div_dd(_t291, a.f[i / 64]);
        } else {
            dst.f[i / 64] = src.f[i / 64];
        }
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_recip_ps(ddi_16 _a) {
    vec512s a;
    a.v = _a;
    vec512s dst;
    int j;
    int i;

    for (j = 0; j <= 15; ++j) {
        i = j * 32;
        dd_I _t292 = _ia_set_dd(-1, 0.0, 1, 0.0);
        dst.f[i / 32] = _ia_div_dd(_t292, a.f[i / 32]);
    }

    return dst.v;
}

ddi_16 _igen_dd_fb_mm512_mask_recip_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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
            dd_I _t293 = _ia_set_dd(-1, 0.0, 1, 0.0);
            dst.f[i / 32] = _ia_div_dd(_t293, a.f[i / 32]);
        } else {
            dst.f[i / 32] = src.f[i / 32];
        }
    }

    return dst.v;
}

ddi_8 _igen_dd_fb_mm512_rint_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_rint_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_rint_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_rint_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_svml_round_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_svml_round_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_sin_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_sin_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_sin_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_sin_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_sinh_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_sinh_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_sinh_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_sinh_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_sind_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_sind_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_sind_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_sind_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_tan_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_tan_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_tan_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_tan_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_tand_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_tand_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_tand_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_tand_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_tanh_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_tanh_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_tanh_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_tanh_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_trunc_pd(ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_trunc_pd(ddi_8 _src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_trunc_ps(ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_trunc_ps(ddi_16 _src, __mmask16 k, ddi_16 _a) {
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

ddi_8 _igen_dd_fb_mm512_sincos_pd(ddi_8 *_cos_res, ddi_8 _a) {
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

ddi_8 _igen_dd_fb_mm512_mask_sincos_pd(ddi_8 *_cos_res, ddi_8 _sin_src,
                                  ddi_8 _cos_src, __mmask8 k, ddi_8 _a) {
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

ddi_16 _igen_dd_fb_mm512_sincos_ps(ddi_16 *_cos_res, ddi_16 _a) {
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

ddi_16 _igen_dd_fb_mm512_mask_sincos_ps(ddi_16 *_cos_res, ddi_16 _sin_src,
                                   ddi_16 _cos_src, __mmask16 k, ddi_16 _a) {
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
