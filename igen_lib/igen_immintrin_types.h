#pragma once

#include <immintrin.h>

/* Transformation of _m128d type */
typedef struct sIntervalM128D { __m256d _0; } f64i_simd2;
typedef f64i_simd2 m256di_1;

/* Transformation of _m128 type */
typedef struct sIntervalM128S { __m256  _0; } f32i_simd4;
typedef f32i_simd4 m256si_1;

/* Transformation of _m256d type */
typedef struct sIntervalM256D { __m256d _0; __m256d _1; } f64i_simd4;
typedef f64i_simd4 m256di_2;

/* Transformation of _m256 type */
typedef struct sIntervalM256S { __m256  _0; __m256 _1; } f32i_simd8;
typedef f32i_simd8 m256si_2;

/* Transformation of _m512d type */
typedef struct sIntervalM512D { __m512d _0; __m512d _1; } f64i_simd8;
typedef f64i_simd8 m512di_2;

/* Transformation of _m256 type */
typedef struct sIntervalM512S { __m512  _0; __m512 _1; } f32i_simd16;
typedef f32i_simd16 m512si_2;

///
/// Special types for promotion of precision
///
/* Transformation from _m256 to double precision (m256di_4) */
typedef struct { __m256d _0; __m256d _1; __m256d _2; __m256d _3; } f64i_simd8_avx2;
typedef f64i_simd8_avx2 m256di_4;
