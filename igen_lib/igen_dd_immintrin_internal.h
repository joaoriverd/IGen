#pragma once
#include <immintrin.h>
#include <stdio.h>
#include <math.h>
#include "igen_dd_immintrin_types.h"
#include "igen_dd_math.h"

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

typedef __m256i i256;

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
    ddi_4 v;
    dd_I   f[4];
    i256   i[4];
} vec128s;

typedef union {
    ddi_2 v;
    dd_I   f[2];
    i256   i[2];
} vec128d;

typedef union {
    __m256i v;
    u32     i[8];
    u64     l[4];
} vec256i;

typedef union {
    ddi_8 v;
    dd_I   f[8];
    i256   i[8];
} vec256s;

typedef union {
    ddi_4 v;
    dd_I   f[4];
    i256   i[4];
} vec256d;

typedef union {
    ddi_16 v;
    dd_I    f[16];
    i256    i[16];
} vec512s;

typedef union {
    ddi_8 v;
    dd_I   f[8];
    i256   i[8];
} vec512d;


/* Bitwise logical operations */
static i256 _ia_and_u32(i256 a, i256 b){
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
}

static i256 _ia_and_u64(i256 a, i256 b){
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
}

static i256 _ia_or_u32(i256 a, i256 b) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
}

static i256 _ia_or_u64(i256 a, i256 b) {
    fprintf(stderr, "Error: Math function not supported yet\n");
}

static i256 _ia_create_mask(u64 a) {
    if (a) {
        return ~_mm256_setzero_si256();
    }
    else {
        return  _mm256_setzero_si256();
    }
}

static u64 toogleBit(u64 a, unsigned int bit) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
    return 0;
}

/* isnan for intervals */
static int _igen_isnan_s(dd_I a) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
    return 0;
}

static int _igen_isnan_d(dd_I a) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
    return 0;
}

/* Comparison functions */
static int _cmp_ord(dd_I a, dd_I b) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
    return 0;
}

static int _cmp_unord(dd_I a, dd_I b) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
    return 0;
}

static int _cmp_true(dd_I a, dd_I b) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
    return 0;
}

static int _cmp_false(dd_I a, dd_I b) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
    return 0;
}

/* Bit access functions to vector type */
static u32 vecBitAccess_i(u32 * vec, u32 bit) {
    int i = bit / 32;
    int b = bit % 32;
    u32 elem = vec[i];
    return (elem >> b) & 0x1u;
}

static u32 vecBitAccess_s(i256* vec, u32 bit) {
    fprintf(stderr, "Error: not supported yet\n");
}

static u32 vecBitAccess_d(i256* vec, u32 bit) {
    fprintf(stderr, "Error: not supported yet\n");
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

static u32 vecBitsAccess_s(i256* vec, u32 upBit, u32 loBit) {
    fprintf(stderr, "Error: vecBitsAccess_s not supported yet\n");
    return 0;
}

static u32 vecBitsAccess_d(i256* vec, u32 upBit, u32 loBit) {
    fprintf(stderr, "Error: vecBitsAccess_d not supported yet\n");
    return 0;
}

static void vecBitAssign_i(i256* vec, u32 bit, u32 val) {
    fprintf(stderr, "Error: vecBitAssign_i not supported yet\n");
}

static void vecBitAssign_s(i256* vec, u32 bit, u32 val) {
    fprintf(stderr, "Error: vecBitAssign_s not supported yet\n");
}

static void vecBitAssign_d(i256* vec, u32 bit, u32 val) {
    fprintf(stderr, "Error: vecBitAssign_d not supported yet\n");
}

static void vecBitsAssign_i(u32* vec, u32 upBit, u32 loBit, u32 val) {
    fprintf(stderr, "Error: vecBitsAssign_i not supported yet\n");
}

static void vecBitsAssign_s(i256* vec, u32 upBit, u32 loBit, u32 val) {
    fprintf(stderr, "Error: vecBitsAssign_s not supported yet\n");
}

static void vecBitsAssign_d(i256* vec, u32 upBit, u32 loBit, u32 val) {
    fprintf(stderr, "Error: function not supported yet\n");
}

#define zero_ddi _ia_set_dd(0,0,0,0)

/* Auxiliary functions */
static void DP_ddi(dd_I* dst, dd_I* a, dd_I* b, int imm8) {
    fprintf(stderr, "Error: Math function not supported yet\n");
}

static void DP_ssi(dd_I* dst, dd_I* a, dd_I* b, int imm8) {
    fprintf(stderr, "Error: Math function not supported yet\n");
}

static dd_I MAX_dd(dd_I a, dd_I b) {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zero_ddi;
}

static dd_I MIN_dd(dd_I a, dd_I b)  {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zero_ddi;
}

static dd_I  MAX_ss(dd_I a,  dd_I b)  {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zero_ddi;
}

static dd_I  MIN_ss(dd_I a,  dd_I b)  {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zero_ddi;
}

static void SELECT4_ssi(dd_I* dst, dd_I* src1, dd_I* src2, int control) {
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
        dst[0] = zero_ddi;
        dst[1] = zero_ddi;
        dst[2] = zero_ddi;
        dst[3] = zero_ddi;
    }
}

static void SELECT4_ddi(dd_I* dst, dd_I* src1, dd_I* src2, int control) {
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
        dst[0] = zero_ddi;
        dst[1] = zero_ddi;
    }
}

static dd_I SELECT4_si(dd_I* src, int control) {
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
    dd_I dst;
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
        default: dst = zero_ddi;
    }

    return dst;
}

static dd_I SELECT4_di(dd_I* src, int control) {
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
    dd_I dst;
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
        default: dst = zero_ddi;
    }

    return dst;
}

static void INTERLEAVE_HIGH_QWORDS_dd(dd_I* dst, dd_I* src1, dd_I* src2) {
    /** DEFINE INTERLEAVE_HIGH_QWORDS(src1[127:0], src2[127:0]) {
     *   dst[63:0] := src1[127:64]
     *   dst[127:64] := src2[127:64]
     *   RETURN dst[127:0]
     *  }
     */
    dst[0] = src1[1];
    dst[1] = src2[1];
}

static void INTERLEAVE_HIGH_DWORDS_ss(dd_I* dst, dd_I* src1, dd_I* src2) {
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

static void INTERLEAVE_QWORDS_dd(dd_I* dst, dd_I* src1, dd_I* src2) {
    /** DEFINE INTERLEAVE_QWORDS(src1[127:0], src2[127:0]) {
     *   dst[63:0] := src1[63:0]
     *   dst[127:64] := src2[63:0]
     *   RETURN dst[127:0]
     *  }
     */
    dst[0] = src1[0];
    dst[1] = src2[0];
}

static void INTERLEAVE_DWORDS_ss(dd_I* dst, dd_I* src1, dd_I* src2) {
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
static dd_I ROUND_di(dd_I a, int rounding)  {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zero_ddi;
}

static dd_I ROUND_si(dd_I a, int rounding)  {
    fprintf(stderr, "Error: Math function not supported yet\n");
    return zero_ddi;
}

static i32 SignExtend_i(u32 a) {
    return a;
}

/* Convert functions */
static dd_I Convert_Int32_To_FP64_i(int a)  {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static dd_I Convert_Int16_To_FP32_i(short int a)  {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static dd_I  Convert_Int32_To_FP32_i(int a)  {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static i32 Convert_FP32_To_Int32_s(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static dd_I Convert_FP32_To_FP64_s(dd_I a)  {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static i32 Convert_FP32_To_Int32_Truncate_s(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static dd_I  Convert_FP64_To_FP32_d(dd_I a) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static i32 Convert_FP64_To_Int32_Truncate_d(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i32 Convert_FP64_To_Int32_d(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i64 Convert_FP64_To_Int64_Truncate_d(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i64 Convert_FP64_To_Int64_d(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static dd_I Convert_Int64_To_FP64_l(i64 a) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static dd_I Convert_Int64_To_FP32_l(i64 a) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static dd_I Convert_UnsignedInt16_To_FP32_i(u16 a) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static dd_I Convert_UnsignedInt8_To_FP32_i(u8 a) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static dd_I  Convert_Int8_To_FP32_i(i8 a) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static i64 Convert_FP32_To_Int64_s(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i32 Convert_FP64_To_Int32_Truncate_s(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static u16 Convert_FP32_To_FP16_s(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static dd_I Convert_FP16_To_FP32_u16(u16 a) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static dd_I Convert_FP16_To_FP32_i(i16 a) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static i16 Convert_FP32_To_Int16_s(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static i8 Convert_FP32_To_Int8_s(dd_I a) {
    fprintf(stderr, "Error: Conversion from interval to integer not supported.\n");
    return 0;
}

static dd_I pow_d (dd_I a, dd_I b) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static dd_I pow_s (dd_I a, dd_I b) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

static dd_I _error_dd (dd_I a) {
    fprintf(stderr, "Error: Function not supported yet\n");
    return zero_ddi;
}

/* Defined functions */
#define _cmp_eq  _ia_cmpeq_dd
#define _cmp_neq _ia_cmpneq_dd
#define _cmp_lt  _ia_cmplt_dd
#define _cmp_leq _ia_cmpleq_dd
#define _cmp_gt  _ia_cmpgt_dd
#define _cmp_geq _ia_cmpgeq_dd

#define SQRT_s               _error_dd
#define SQRT_d               _ia_sqrt_dd
#define FLOOR_s              _error_dd
#define FLOOR_d              _error_dd
#define CEIL_s               _error_dd
#define CEIL_d               _error_dd

#define ACOS_d               _error_dd
#define ACOSH_d              _error_dd
#define ASIN_d               _error_dd
#define ASINH_d              _error_dd
#define ATAN_d               _error_dd
#define ATANH_d              _error_dd
#define CubeRoot_d           _error_dd
#define CDFNormal_d          _error_dd
#define InverseCDFNormal_d   _error_dd
#define COS_d                _error_dd
#define COSD_d               _error_dd
#define COSH_d               _error_dd
#define ERF_d                _error_dd
#define expe_d               _error_dd
#define exp10_d              _error_dd
#define exp2_d               _error_dd
#define InvCubeRoot_d        _error_dd
#define InvSQRT_d            _error_dd
#define ln_d                 _error_dd
#define log10_d              _error_dd
#define log2_d               _error_dd
#define ConvertExpFP64_d     _error_dd
#define SIN_d                _error_dd
#define SIND_d               _error_dd
#define SINH_d               _error_dd
#define ROUND_d              _error_dd
#define TAN_d                _error_dd
#define TAND_d               _error_dd
#define TANH_d               _error_dd
#define TRUNCATE_d           _error_dd
#define NearbyInt_d          _error_dd
#define RoundToNearestEven_d _error_dd

#define ACOS_s               _error_dd
#define ACOSH_s              _error_dd
#define ASIN_s               _error_dd
#define ASINH_s              _error_dd
#define ATAN_s               _error_dd
#define ATANH_s              _error_dd
#define CubeRoot_s           _error_dd
#define CDFNormal_s          _error_dd
#define InverseCDFNormal_s   _error_dd
#define COS_s                _error_dd
#define COSD_s               _error_dd
#define COSH_s               _error_dd
#define ERF_s                _error_dd
#define expe_s               _error_dd
#define exp10_s              _error_dd
#define exp2_s               _error_dd
#define InvCubeRoot_s        _error_dd
#define InvSQRT_s            _error_dd
#define ln_s                 _error_dd
#define log10_s              _error_dd
#define log2_s               _error_dd
#define ConvertExpFP32_s     _error_dd
#define SIN_s                _error_dd
#define SIND_s               _error_dd
#define SINH_s               _error_dd
#define ROUND_s              _error_dd
#define TAN_s                _error_dd
#define TAND_s               _error_dd
#define TANH_s               _error_dd
#define TRUNCATE_s           _error_dd
#define NearbyInt_s          _error_dd
#define RoundToNearestEven_s _error_dd
