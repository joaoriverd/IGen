#pragma once
#include <immintrin.h>
#include <stdio.h>
#include <math.h>
#include "igen_immintrin_types.h"
#include "igen_lib.h"
#include "igen_math.h"

#define _FALSE 0
#define _TRUE  1

typedef __uint8_t  u8;
typedef __int8_t   i8;
typedef __uint16_t u16;
typedef __int16_t  i16;
typedef __uint32_t u32;
typedef __int32_t  i32;
typedef __uint64_t u64;
typedef __int64_t  i64;

typedef struct sIntervalU32 {
    __uint32_t lo;
    __uint32_t up;
} u32_I;

typedef struct sIntervalU64 {
    __uint64_t lo;
    __uint64_t up;
} u64_I;

typedef union {
    __m64 v;
    u32   i[2];
    u64   l[1];
} vec64i;

typedef union {
    __m128i v;
    u32     i[4];
    u64     l[2];
} vec128i;

typedef union {
    f32i_simd4 v;
    f32_I   f[4];
    u32_I   i[4];
} vec128s;

typedef union {
    f64i_simd2 v;
    f64_I   f[2];
    u_f64i  ff[4];
    u64_I   i[2];
} vec128d;

typedef union {
    __m256i v;
    u32     i[8];
    u64     l[4];
} vec256i;

typedef union {
    f32i_simd8 v;
    f32_I   f[8];
    u32_I   i[8];
} vec256s;

typedef union {
    f64i_simd4 v;
    f64_I   f[4];
    u_f64i  ff[4];
    u64_I   i[4];
} vec256d;

typedef union {
    f32i_simd16  v;
    u32_I    i[16];
    u64_I    l[8];
} vec512i;

typedef union {
    f32i_simd16 v;
    f32_I   f[16];
    u32_I   i[16];
} vec512s;

typedef union {
    f64i_simd8  v;
    f64_I    f[8];
    u_f64i  ff[4];
    u64_I    i[8];
} vec512d;

/* Comparison functions. todo: Add support for ordered and signaling comparisons */
#define _cmp_eq  _ia_cmpeq_f64
#define _cmp_neq _ia_cmpneq_f64
#define _cmp_lt  _ia_cmplt_f64
#define _cmp_leq _ia_cmple_f64
#define _cmp_gt  _ia_cmpgt_f64
#define _cmp_geq _ia_cmpge_f64

/* Basic math functions in intervals */
#define SQRT_s   _ia_sqrt_f32
#define SQRT_d   _ia_sqrt_f64
#define FLOOR_s  _ia_floor_f32
#define FLOOR_d  _ia_floor_f64
#define CEIL_s   _ia_ceil_f32
#define CEIL_d   _ia_ceil_f64

/* Math functions */
#define ACOS_d               _ia_acos_f64
#define ACOSH_d              _error_d
#define ASIN_d               _ia_asin_f64
#define ASINH_d              _error_d
#define ATAN_d               _ia_atan_f64
#define ATANH_d              _error_d
#define CubeRoot_d           _error_d
#define CDFNormal_d          _error_d
#define InverseCDFNormal_d   _error_d
#define COS_d                _ia_cos_f64
#define COSD_d               _error_d
#define COSH_d               _ia_cosh_f64
#define ERF_d                _error_d
#define expe_d               _ia_exp_f64
#define exp10_d              _error_d
#define exp2_d               _error_d
#define InvCubeRoot_d        _error_d
#define InvSQRT_d            _error_d
#define ln_d                 _ia_log_f64
#define log10_d              _ia_log10_f64
#define log2_d               _ia_log2_f64
#define ConvertExpFP64_d     _error_d
#define SIN_d                _ia_sin_f64
#define SIND_d               _error_d
#define SINH_d               _ia_sinh_f64
#define ROUND_d              _error_d
#define TAN_d                _ia_tan_f64
#define TAND_d               _error_d
#define TANH_d               _error_d
#define TRUNCATE_d           _error_d
#define NearbyInt_d          _error_d
#define RoundToNearestEven_d _error_d

#define ACOS_s               _ia_acos_f32
#define ACOSH_s              _error_s
#define ASIN_s               _ia_asin_f32
#define ASINH_s              _error_s
#define ATAN_s               _ia_atan_f32
#define ATANH_s              _error_s
#define CubeRoot_s           _error_s
#define CDFNormal_s          _error_s
#define InverseCDFNormal_s   _error_s
#define COS_s                _ia_cos_f32
#define COSD_s               _error_s
#define COSH_s               _error_s
#define ERF_s                _error_s
#define expe_s               _ia_exp_f32
#define exp10_s              _error_s
#define exp2_s               _error_s
#define InvCubeRoot_s        _error_s
#define InvSQRT_s            _error_s
#define ln_s                 _ia_log_f32
#define log10_s              _error_s
#define log2_s               _error_s
#define ConvertExpFP32_s     _error_s
#define SIN_s                _ia_sin_f32
#define SIND_s               _error_s
#define SINH_s               _error_s
#define ROUND_s              _error_s
#define TAN_s                _ia_tan_f32
#define TAND_s               _error_s
#define TANH_s               _error_s
#define TRUNCATE_s           _error_s
#define NearbyInt_s          _error_s
#define RoundToNearestEven_s _error_s

#define BIT_ACCESS(var, x) ((var >> x) & 1u)

typedef union {
    __m128d v;
    f64_I   f;
} u_m128d;

typedef union {
    __m128 v;
    f32_I  f[2];
} u_m128s;

/* Bitwise logical operations */
static u32_I _ia_and_u32(u32_I a, u32_I b){
    u32_I dst;
    // dst.lo = ((a.lo & b.lo) & 0x7FFFFFFF) | ((a.lo | b.lo) & 0x80000000);
    dst.lo = a.lo & b.lo;
    dst.up = a.up & b.up;

    return dst;
}

static u64_I _ia_and_u64(u64_I a, u64_I b){
    u64_I dst;
    // dst.lo = ((a.lo & b.lo) & 0x7FFFFFFFFFFFFFFF) | ((a.lo | b.lo) & 0x8000000000000000);
    dst.lo = a.lo & b.lo;
    dst.up = a.up & b.up;

    return dst;
}

static u32_I _ia_or_u32(u32_I a, u32_I b){
    u32_I dst;
    //dst.lo = ((a.lo | b.lo) & 0x7FFFFFFF) | ((a.lo & b.lo) & 0x80000000);
    dst.lo = a.lo | b.lo;
    dst.up = a.up | b.up;

    return dst;
}

static u64_I _ia_or_u64(u64_I a, u64_I b){
    u64_I dst;
    //dst.lo = ((a.lo | b.lo) & 0x7FFFFFFFFFFFFFFF) | ((a.lo & b.lo) & 0x8000000000000000);
    dst.lo = a.lo | b.lo;
    dst.up = a.up | b.up;

    return dst;
}

static u64 toogleBit(u64 a, unsigned int bit){
    // bypass
    u64 dst;
    // dst = a ^ (1UL << bit);
    dst = a;
    return dst;
}

/* isnan for intervals */
static int _igen_isnan_s(f32_I a) {
    if (isnan(a.lo)) {
        return _TRUE;
    }
    if (isnan(a.up)) {
        return _TRUE;
    }
    return _FALSE;
}

static int _igen_isnan_d(f64_I _a) {
    u_f64i* a = (u_f64i*) &_a;
    if (isnan(a->lo)) {
        return _TRUE;
    }
    if (isnan(a->up)) {
        return _TRUE;
    }
    return _FALSE;
}

/* Comparison functions */
static int _cmp_ord(f64_I a, f64_I b) {
    return _igen_isnan_d(a) || _igen_isnan_d(b);
}

static int _cmp_unord(f64_I a, f64_I b) {
    return !_cmp_ord(a,b);
}

static int _cmp_true(f64_I a, f64_I b) {
    return _TRUE;
}

static int _cmp_false(f64_I a, f64_I b) {
    return _FALSE;
}

/* Bit access functions to vector type */
static u32 vecBitAccess_i(u32 * vec, u32 bit) {
    int i = bit / 32;
    int b = bit % 32;
    u32 elem = vec[i];
    return (elem >> b) & 0x1u;
}

static u32 vecBitAccess_s(u32_I* vec, u32 bit) {
    int i = bit / 32;
    int b = bit % 32;
    u32_I elem = vec[i];
    u32 b_lo = (elem.lo >> b) & 0x1u;
    u32 b_up = (elem.up >> b) & 0x1u;


    if (b == 31 && b_lo == b_up) {
        /* It is accessing the sign bit of the floating point.
        * Remember that the sign of the lower bound is inverted.
        * The only exception can be when the variable is zero
        * (check this carefully later). */
        fprintf(stderr, "Error: Unknown state in vecBitAccess_s\n");
        return _FALSE;
    }

    if (b < 31 && b_lo != b_up) {
        /* undefined bit */
        fprintf(stderr, "Error: Unknown state in vecBitAccess_s\n");
        return _FALSE;
    }

    return b_up;
}

static u32 vecBitAccess_d(u64_I* vec, u32 bit) {
    int i = bit / 64;
    int b = bit % 64;
    u64_I elem = vec[i];
    u64 b_lo = (elem.lo >> b) & 0x1u;
    u64 b_up = (elem.up >> b) & 0x1u;


    if (b == 63 && b_lo == b_up) {
        /* It is accessing the sign bit of the floating point.
        * Remember that the sign of the lower bound is inverted.
        * The only exception can be when the variable is zero
        * (check this carefully). */
        fprintf(stderr, "Error: Unknown state in vecBitAccess_s\n");
        return _FALSE;
    }

    if (b < 63 && b_lo != b_up) {
        /* undefined bit */
        fprintf(stderr, "Error: Unknown state in vecBitAccess_s\n");
        return _FALSE;
    }

    return b_up;
}

static u32 vecBitsAccess_i(u32* vec, u32 upBit, u32 loBit) {
    int i = upBit / 32;

    if (i != loBit / 32 || upBit < loBit) {
        fprintf(stderr, "Error: Accessing bits within different elements of the vector not supported yet. (vecBitsAccess_i)\n");
        return _FALSE;
    }

    int b_up = upBit % 32;
    int b_lo = loBit % 32;
    u32 size = b_up - b_lo;
    u32 elem = vec[i];

    u32 mask = (1 << (size+1)) - 1;
    return (elem >> b_lo) & mask;
}

static u32 vecBitsAccess_s(u32_I* vec, u32 upBit, u32 loBit) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
    return 0;
}

static u32 vecBitsAccess_d(u64_I* vec, u32 upBit, u32 loBit) {
    fprintf(stderr, "Error: vecBitsAccess_d not supported yet\n");
    return 0;
}

static void vecBitAssign_i(u32* vec, u32 bit, u32 val) {
    fprintf(stderr, "Error: vecBitAssign_i not supported yet\n");
}

static void vecBitAssign_s(u32_I* vec, u32 bit, u32 val) {
    fprintf(stderr, "Error: vecBitAssign_s not supported yet\n");
}

static void vecBitAssign_d(u64_I* vec, u32 bit, u32 val) {
    fprintf(stderr, "Error: vecBitAssign_d not supported yet\n");
}

static void vecBitsAssign_i(u32* vec, u32 upBit, u32 loBit, u32 val) {
    fprintf(stderr, "Error: vecBitsAssign_i not supported yet\n");
}

static void vecBitsAssign_s(u32_I* vec, u32 upBit, u32 loBit, u32 val) {
    fprintf(stderr, "Error: vecBitsAssign_s not supported yet\n");
}

static void vecBitsAssign_d(u64_I* vec, u32 upBit, u32 loBit, u32 val) {
    fprintf(stderr, "Error: function not supported yet\n");
}

static f64_I zerod = {0,0};
static f32_I zerof = {0,0};

/* Auxiliary functions */
static void DP_ddi(f64_I* dst, f64_I* a, f64_I* b, int imm8) {
    /// DEFINE DP(a[127:0], b[127:0], imm8[7:0]) {
    ///   FOR j := 0 to 1
    ///     i := j*64
    ///     IF imm8[(4+j)%8]
    ///       temp[i+63:i] := a[i+63:i] * b[i+63:i]
    ///     ELSE
    ///       temp[i+63:i] := 0
    ///     FI
    ///   ENDFOR
    ///
    ///   sum[63:0] := temp[127:64] + temp[63:0]
    ///
    ///   FOR j := 0 to 1
    ///     i := j*64
    ///     IF imm8[j%8]
    ///       tmpdst[i+63:i] := sum[63:0]
    ///     ELSE
    ///       tmpdst[i+63:i] := 0
    ///     FI
    ///   ENDFOR
    ///   RETURN tmpdst[127:0]
    /// }
    vec128d temp;
    f64_I   sum;
    for (int i = 0; i < 2; ++i) {
        if (BIT_ACCESS(imm8, i+4)) {
            temp.f[i] = _ia_mul_f64(a[i], b[i]);
        }
        else {
            temp.f[i] = _ia_set_f64(-0.0, 0.0);

        }
    }

    sum = _ia_add_f64(temp.f[1], temp.f[0]);

    for (int i = 0; i < 2; ++i) {
        if (BIT_ACCESS(imm8, i)) {
            dst[i] = sum;
        }
        else {
            dst[i] = _ia_set_f64(-0.0, 0.0);
        }
    }
 }

static void DP_ssi(f32_I* dst, f32_I* a, f32_I* b, int imm8) {
    /// DEFINE DP(a[127:0], b[127:0], imm8[7:0]) {
    ///   FOR j := 0 to 3
    ///     i := j*32
    ///     IF imm8[(4+j)%8]
    ///       temp[i+31:i] := a[i+31:i] * b[i+31:i]
    ///     ELSE
    ///       temp[i+31:i] := 0
    ///     FI
    ///   ENDFOR
    ///
    ///   sum[31:0] := (temp[127:96] + temp[95:64]) + (temp[63:32] + temp[31:0])
    ///
    ///   FOR j := 0 to 3
    ///     i := j*32
    ///     IF imm8[j%8]
    ///       tmpdst[i+31:i] := sum[31:0]
    ///     ELSE
    ///       tmpdst[i+31:i] := 0
    ///     FI
    ///   ENDFOR
    ///   RETURN tmpdst[127:0]
    /// }
    vec128s temp;
    f32_I   sum;
    for (int i = 0; i < 4; ++i) {
        if (BIT_ACCESS(imm8, i+4)) {
            temp.f[i] = _ia_mul_f32(a[i], b[i]);
        }
        else {
            temp.f[i].lo = -0.0;
            temp.f[i].up =  0.0;
        }
    }

    sum.lo = temp.f[3].lo + temp.f[2].lo + temp.f[1].lo + temp.f[0].lo;
    sum.up = temp.f[3].up + temp.f[2].up + temp.f[1].up + temp.f[0].up;

    for (int i = 0; i < 4; ++i) {
        if (BIT_ACCESS(imm8, i)) {
            dst[i] = sum;
        }
        else {
            dst[i].lo = -0.0;
            dst[i].up =  0.0;
        }
    }
}

static f64_I MAX_dd(f64_I _a, f64_I _b) {
    f64_I _c;
    u_f64i* a = (u_f64i*) &_a;
    u_f64i* b = (u_f64i*) &_b;
    u_f64i* c = (u_f64i*) &_c;

    c->up = a->up > b->up ? a->up : b->up;
    c->lo = a->lo < b->lo ? a->lo : b->lo;

    return _c;
}

static f64_I MIN_dd(f64_I _a, f64_I _b) {
    f64_I _c;
    u_f64i* a = (u_f64i*) &_a;
    u_f64i* b = (u_f64i*) &_b;
    u_f64i* c = (u_f64i*) &_c;

    c->up = a->up < b->up ? a->up : b->up;
    c->lo = a->lo > b->lo ? a->lo : b->lo;

    return _c;
}

static f32_I  MAX_ss(f32_I a,  f32_I b)  {
    f32_I c;

    c.up = a.up > b.up ? a.up : b.up;
    c.lo = a.lo < b.lo ? a.lo : b.lo;

    return c;
}

static f32_I  MIN_ss(f32_I a,  f32_I b) {
    f32_I c;

    c.up = a.up < b.up ? a.up : b.up;
    c.lo = a.lo > b.lo ? a.lo : b.lo;

    return c;
}

static void SELECT4_ssi(f32_I* dst, f32_I* src1, f32_I* src2, int control) {
    /** DEFINE SELECT4(src1, src2, control) {
     *    CASE(control[1:0]) OF
     *    0: tmp[127:0] := src1[127:0]
     *    1: tmp[127:0] := src1[255:128]
     *    2: tmp[127:0] := src2[127:0]
     *    3: tmp[127:0] := src2[255:128]
     *    ESAC
     *    IF control[3]
     *    tmp[127:0] := 0
     *    FI
     *    RETURN tmp[127:0]
     *  }
     */

     switch (control & 0x3u) {
         case 0:
             dst[0] = src1[0];
             dst[1] = src1[1];
             dst[2] = src1[2];
             dst[3] = src1[3];
             break;
         case 1:
             dst[0] = src1[4];
             dst[1] = src1[5];
             dst[2] = src1[6];
             dst[3] = src1[7];
             break;
         case 2:
             dst[0] = src2[0];
             dst[1] = src2[1];
             dst[2] = src2[2];
             dst[3] = src2[3];
             break;
         case 3:
             dst[0] = src2[4];
             dst[1] = src2[5];
             dst[2] = src2[6];
             dst[3] = src2[7];
             break;
     }

     if ((control >> 3) & 0x1u) {
         dst[0] = zerof;
         dst[1] = zerof;
         dst[2] = zerof;
         dst[3] = zerof;
     }
}

static void SELECT4_ddi(f64_I* dst, f64_I* src1, f64_I* src2, int control) {
    /** DEFINE SELECT4(src1, src2, control) {
     *    CASE(control[1:0]) OF
     *    0: tmp[127:0] := src1[127:0]
     *    1: tmp[127:0] := src1[255:128]
     *    2: tmp[127:0] := src2[127:0]
     *    3: tmp[127:0] := src2[255:128]
     *    ESAC
     *    IF control[3]
     *    tmp[127:0] := 0
     *    FI
     *    RETURN tmp[127:0]
     *  }
     */
    switch (control & 0x3u) {
        case 0:
            dst[0] = src1[0];
            dst[1] = src1[1];
            break;
        case 1:
            dst[0] = src1[2];
            dst[1] = src1[3];
            break;
        case 2:
            dst[0] = src2[0];
            dst[1] = src2[1];
            break;
        case 3:
            dst[0] = src2[2];
            dst[1] = src2[3];
            break;
    }

    if ((control >> 3) & 0x1u) {
        dst[0] = zerod;
        dst[1] = zerod;
    }
}

static f32_I SELECT4_si(f32_I* src, int control) {
    /** DEFINE SELECT4(src, control) {
     *   CASE(control[1:0]) OF
     *       0: tmp[31:0] := src[31:0]
     *       1: tmp[31:0] := src[63:32]
     *       2: tmp[31:0] := src[95:64]
     *       3: tmp[31:0] := src[127:96]
     *       ESAC
     *       RETURN tmp[31:0]
     *   }
     */
    f32_I dst;
    switch (control & 0x3u) {
        case 0:
            dst = src[0];
            break;
        case 1:
            dst = src[1];
            break;
        case 2:
            dst = src[2];
            break;
        case 3:
            dst = src[3];
            break;
        default: dst = zerof;
    }

    return dst;
}

static f64_I SELECT4_di(f64_I* src, int control) {
    /** DEFINE SELECT4(src, control) {
     *    CASE(control[1:0]) OF
     *    0: tmp[63:0] := src[63:0]
     *    1: tmp[63:0] := src[127:64]
     *    2: tmp[63:0] := src[191:128]
     *    3: tmp[63:0] := src[255:192]
     *    ESAC
     *    RETURN tmp[63:0]
     *  }
     */
    f64_I dst;
    switch (control & 0x3u) {
        case 0:
            dst = src[0];
            break;
        case 1:
            dst = src[1];
            break;
        case 2:
            dst = src[2];
            break;
        case 3:
            dst = src[3];
            break;
        default: dst = zerod;
    }

    return dst;
}

static void INTERLEAVE_HIGH_QWORDS_dd(f64_I* dst, f64_I* src1, f64_I* src2) {
    /** DEFINE INTERLEAVE_HIGH_QWORDS(src1[127:0], src2[127:0]) {
     *   dst[63:0] := src1[127:64]
     *   dst[127:64] := src2[127:64]
     *   RETURN dst[127:0]
     *  }
     */
    dst[0] = src1[1];
    dst[1] = src2[1];
}

static void INTERLEAVE_HIGH_DWORDS_ss(f32_I* dst, f32_I* src1, f32_I* src2) {
    /** DEFINE INTERLEAVE_HIGH_DWORDS(src1[127:0], src2[127:0]) {
     *   dst[31:0] := src1[95:64]
     *   dst[63:32] := src2[95:64]
     *   dst[95:64] := src1[127:96]
     *   dst[127:96] := src2[127:96]
     *   RETURN dst[127:0]
     *  }
    */
    dst[0] = src1[2];
    dst[1] = src2[2];
    dst[2] = src1[3];
    dst[3] = src2[3];
}

static void INTERLEAVE_QWORDS_dd(f64_I* dst, f64_I* src1, f64_I* src2) {
    /** DEFINE INTERLEAVE_QWORDS(src1[127:0], src2[127:0]) {
     *   dst[63:0] := src1[63:0]
     *   dst[127:64] := src2[63:0]
     *   RETURN dst[127:0]
     *  }
     */
     dst[0] = src1[0];
     dst[1] = src2[0];
}

static void INTERLEAVE_DWORDS_ss(f32_I* dst, f32_I* src1, f32_I* src2) {
    /** DEFINE INTERLEAVE_DWORDS(src1[127:0], src2[127:0]) {
     *   dst[31:0] := src1[31:0]
     *   dst[63:32] := src2[31:0]
     *   dst[95:64] := src1[63:32]
     *   dst[127:96] := src2[63:32]
     *   RETURN dst[127:0]
     *  }
     */
     dst[0] = src1[0];
     dst[1] = src2[0];
     dst[2] = src1[1];
     dst[3] = src2[1];
}

/* Basic math functions */
static f64_I ROUND_di(f64_I _a, int rounding) {
    /// (_MM_FROUND_TO_NEAREST_INT |_MM_FROUND_NO_EXC) // round to nearest (ties to even), and suppress exceptions
    /// (_MM_FROUND_TO_NEG_INF |_MM_FROUND_NO_EXC)     // round down, and suppress exceptions
    /// (_MM_FROUND_TO_POS_INF |_MM_FROUND_NO_EXC)     // round up, and suppress exceptions
    /// (_MM_FROUND_TO_ZERO |_MM_FROUND_NO_EXC)        // truncate, and suppress exceptions
    /// _MM_FROUND_CUR_DIRECTION // use MXCSR.RC; see _MM_SET_ROUNDING_MODE
    u_m128d temp, dst;

    u_f64i* a = (u_f64i*) &_a;
    a->lo     = -a->lo;
    temp.f    =  _a;
    switch (rounding) {
        case _MM_FROUND_TO_NEAREST_INT: dst.v = _mm_round_pd(temp.v, _MM_FROUND_TO_NEAREST_INT); break;
        case _MM_FROUND_TO_NEG_INF:     dst.v = _mm_round_pd(temp.v, _MM_FROUND_TO_NEG_INF);     break;
        case _MM_FROUND_TO_POS_INF:     dst.v = _mm_round_pd(temp.v, _MM_FROUND_TO_POS_INF);     break;
        case _MM_FROUND_TO_ZERO:        dst.v = _mm_round_pd(temp.v, _MM_FROUND_TO_ZERO);        break;
        case _MM_FROUND_CUR_DIRECTION:  dst.v = _mm_round_pd(temp.v, _MM_FROUND_CUR_DIRECTION);  break;
        default:
            /* Rise exception */
            fprintf(stderr, "Error: Rounding option not supported.\n");
    }

    u_f64i* t = (u_f64i*) &dst.f;
    t->lo = -t->lo;

    return dst.f;
}

static f32_I ROUND_si(f32_I a, int rounding) {
    /// (_MM_FROUND_TO_NEAREST_INT |_MM_FROUND_NO_EXC) // round to nearest (ties to even), and suppress exceptions
    /// (_MM_FROUND_TO_NEG_INF |_MM_FROUND_NO_EXC)     // round down, and suppress exceptions
    /// (_MM_FROUND_TO_POS_INF |_MM_FROUND_NO_EXC)     // round up, and suppress exceptions
    /// (_MM_FROUND_TO_ZERO |_MM_FROUND_NO_EXC)        // truncate, and suppress exceptions
    /// _MM_FROUND_CUR_DIRECTION // use MXCSR.RC; see _MM_SET_ROUNDING_MODE
    u_m128s temp, dst;

    a.lo     = -a.lo;
    temp.f[0]   =  a;
    switch (rounding) {
        case _MM_FROUND_TO_NEAREST_INT: dst.v = _mm_round_ps(temp.v, _MM_FROUND_TO_NEAREST_INT); break;
        case _MM_FROUND_TO_NEG_INF:     dst.v = _mm_round_ps(temp.v, _MM_FROUND_TO_NEG_INF);     break;
        case _MM_FROUND_TO_POS_INF:     dst.v = _mm_round_ps(temp.v, _MM_FROUND_TO_POS_INF);     break;
        case _MM_FROUND_TO_ZERO:        dst.v = _mm_round_ps(temp.v, _MM_FROUND_TO_ZERO);        break;
        case _MM_FROUND_CUR_DIRECTION:  dst.v = _mm_round_ps(temp.v, _MM_FROUND_CUR_DIRECTION);  break;
        default:
            /* Rise exception */
            fprintf(stderr, "Error: Rounding option not supported.\n");
    }

    dst.f[0].lo = -dst.f[0].lo;

    return dst.f[0];
}

static i32 SignExtend_i(u32 a) {
    return a;
}

/* Convert functions */
static f64_I Convert_Int32_To_FP64_i(int a) {
    f64_I dst = _ia_set_f64(-a, a);
    return dst;
}

static f32_I Convert_Int16_To_FP32_i(short int a) {
    f32_I dst;
    dst.lo = -a;
    dst.up = a;
    return dst;
}

static f32_I Convert_Int32_To_FP32_i(int a) {
    f32_I dst;
    dst.lo = -a;
    dst.up = a;
    return dst;
}

static i32 Convert_FP32_To_Int32_s(f32_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static f64_I Convert_FP32_To_FP64_s(f32_I a) {
    f64_I dst = _ia_set_f64(a.lo, a.up);
    return dst;
}

static i32 Convert_FP32_To_Int32_Truncate_s(f32_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static f32_I Convert_FP64_To_FP32_d(f64_I _a){
    f32_I dst;
    u_f64i* a = (u_f64i*) &_a;
    dst.lo = a->lo;
    dst.up = a->up;
    return dst;
}

static i32 Convert_FP64_To_Int32_Truncate_d(f64_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i32 Convert_FP64_To_Int32_d(f64_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i64 Convert_FP64_To_Int64_Truncate_d(f64_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i64 Convert_FP64_To_Int64_d(f64_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static f64_I Convert_Int64_To_FP64_l(i64 a) {
    f64_I dst = _ia_set_f64(-a, a);
    return dst;
}

static f32_I Convert_Int64_To_FP32_l(i64 a) {
    f32_I dst;
    dst.lo = -a;
    dst.up = a;
    return dst;
}

static f32_I Convert_UnsignedInt16_To_FP32_i(u16 a) {
    f32_I dst;
    dst.lo = -a;
    dst.up = a;
    return dst;
}

static f32_I Convert_UnsignedInt8_To_FP32_i(u8 a) {
    f32_I dst;
    dst.lo = -a;
    dst.up = a;
    return dst;
}

static f32_I  Convert_Int8_To_FP32_i(i8 a) {
    f32_I dst;
    dst.lo = -a;
    dst.up = a;
    return dst;
}

static i64 Convert_FP32_To_Int64_s(f32_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i32 Convert_FP64_To_Int32_Truncate_s(f32_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static u16 Convert_FP32_To_FP16_s(f32_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static f32_I Convert_FP16_To_FP32_u16(u16 a) {
    f32_I dst;
    dst.lo = -a;
    dst.up = a;
    return dst;
}

static f32_I Convert_FP16_To_FP32_i(i16 a) {
    f32_I dst;
    dst.lo = -a;
    dst.up = a;
    return dst;
}

static i16 Convert_FP32_To_Int16_s(f32_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i8 Convert_FP32_To_Int8_s(f32_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static f64_I pow_d (f64_I a, f64_I b) {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zerod;
}

static f32_I pow_s (f32_I a, f32_I b) {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zerof;
}

static f64_I _error_d (f64_I a) {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zerod;
}

static f32_I _error_s (f32_I a) {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zerof;
}
