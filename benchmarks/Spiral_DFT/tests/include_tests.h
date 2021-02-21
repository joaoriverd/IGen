#pragma once

#include "igen_lib.h"
#include "igen_dd_lib.h"
#include "boost_common.h"
#include "filib_common.h"
#include "gaol_common.h"
#include "yalaa_wrap.h"

void init_DFT16(double);
void init_DFT32(double);
void init_DFT64(double);
void init_DFT128(double);
void init_DFT256(double);

void init_DFT16(f64_I);
void init_DFT32(f64_I);
void init_DFT64(f64_I);
void init_DFT128(f64_I);
void init_DFT256(f64_I);

void init_DFT16(dd_I);
void init_DFT32(dd_I);
void init_DFT64(dd_I);
void init_DFT128(dd_I);
void init_DFT256(dd_I);

void init_DFT16_bst();
void init_DFT32_bst();
void init_DFT64_bst();
void init_DFT128_bst();
void init_DFT256_bst();

void init_DFT16_fil();
void init_DFT32_fil();
void init_DFT64_fil();
void init_DFT128_fil();
void init_DFT256_fil();

void init_DFT16_gal();
void init_DFT32_gal();
void init_DFT64_gal();
void init_DFT128_gal();
void init_DFT256_gal();

void init_DFT16_yalaa();
void init_DFT32_yalaa();
void init_DFT64_yalaa();
void init_DFT128_yalaa();
void init_DFT256_yalaa();

void init_AVX_DFT16(double);
void init_AVX_DFT32(double);
void init_AVX_DFT64(double);
void init_AVX_DFT128(double);
void init_AVX_DFT256(double);

void init_AVX_DFT16(f64_I);
void init_AVX_DFT32(f64_I);
void init_AVX_DFT64(f64_I);
void init_AVX_DFT128(f64_I);
void init_AVX_DFT256(f64_I);

void init_AVX_DFT16(dd_I);
void init_AVX_DFT32(dd_I);
void init_AVX_DFT64(dd_I);
void init_AVX_DFT128(dd_I);
void init_AVX_DFT256(dd_I);

void DFT16 (double *Y, double *X);
void DFT32 (double *Y, double *X);
void DFT64 (double *Y, double *X);
void DFT128(double *Y, double *X);
void DFT256(double *Y, double *X);

void DFT16 (f64_I  *Y, f64_I  *X);
void DFT32 (f64_I  *Y, f64_I  *X);
void DFT64 (f64_I  *Y, f64_I  *X);
void DFT128(f64_I  *Y, f64_I  *X);
void DFT256(f64_I  *Y, f64_I  *X);

void DFT16 (dd_I   *Y, dd_I   *X);
void DFT32 (dd_I   *Y, dd_I   *X);
void DFT64 (dd_I   *Y, dd_I   *X);
void DFT128(dd_I   *Y, dd_I   *X);
void DFT256(dd_I   *Y, dd_I   *X);

void DFT16 (f64i_bst *Y, f64i_bst *X);
void DFT32 (f64i_bst *Y, f64i_bst *X);
void DFT64 (f64i_bst *Y, f64i_bst *X);
void DFT128(f64i_bst *Y, f64i_bst *X);
void DFT256(f64i_bst *Y, f64i_bst *X);

void DFT16 (f64i_fil *Y, f64i_fil *X);
void DFT32 (f64i_fil *Y, f64i_fil *X);
void DFT64 (f64i_fil *Y, f64i_fil *X);
void DFT128(f64i_fil *Y, f64i_fil *X);
void DFT256(f64i_fil *Y, f64i_fil *X);

void DFT16 (f64i_gal *Y, f64i_gal *X);
void DFT32 (f64i_gal *Y, f64i_gal *X);
void DFT64 (f64i_gal *Y, f64i_gal *X);
void DFT128(f64i_gal *Y, f64i_gal *X);
void DFT256(f64i_gal *Y, f64i_gal *X);

void DFT16 (yalaa_af0 *Y, yalaa_af0 *X);
void DFT32 (yalaa_af0 *Y, yalaa_af0 *X);
void DFT64 (yalaa_af0 *Y, yalaa_af0 *X);
void DFT128(yalaa_af0 *Y, yalaa_af0 *X);
void DFT256(yalaa_af0 *Y, yalaa_af0 *X);

void AVX_DFT16 (double *Y, double *X);
void AVX_DFT32 (double *Y, double *X);
void AVX_DFT64 (double *Y, double *X);
void AVX_DFT128(double *Y, double *X);
void AVX_DFT256(double *Y, double *X);

void AVX_DFT16 (f64_I  *Y, f64_I  *X);
void AVX_DFT32 (f64_I  *Y, f64_I  *X);
void AVX_DFT64 (f64_I  *Y, f64_I  *X);
void AVX_DFT128(f64_I  *Y, f64_I  *X);
void AVX_DFT256(f64_I  *Y, f64_I  *X);

void AVX_DFT16 (dd_I   *Y, dd_I   *X);
void AVX_DFT32 (dd_I   *Y, dd_I   *X);
void AVX_DFT64 (dd_I   *Y, dd_I   *X);
void AVX_DFT128(dd_I   *Y, dd_I   *X);
void AVX_DFT256(dd_I   *Y, dd_I   *X);

/* Functions to bench */
static void DFT16_base      (void* Y, void* X) { DFT16 ((double*) Y, (double*) X); }
static void DFT32_base      (void* Y, void* X) { DFT32 ((double*) Y, (double*) X); }
static void DFT64_base      (void* Y, void* X) { DFT64 ((double*) Y, (double*) X); }
static void DFT128_base     (void* Y, void* X) { DFT128((double*) Y, (double*) X); }
static void DFT256_base     (void* Y, void* X) { DFT256((double*) Y, (double*) X); }

static void DFT16_f64i      (void* Y, void* X) { DFT16 ((f64_I*)  Y, (f64_I*)  X); }
static void DFT32_f64i      (void* Y, void* X) { DFT32 ((f64_I*)  Y, (f64_I*)  X); }
static void DFT64_f64i      (void* Y, void* X) { DFT64 ((f64_I*)  Y, (f64_I*)  X); }
static void DFT128_f64i     (void* Y, void* X) { DFT128((f64_I*)  Y, (f64_I*)  X); }
static void DFT256_f64i     (void* Y, void* X) { DFT256((f64_I*)  Y, (f64_I*)  X); }

static void DFT16_ddi       (void* Y, void* X) { DFT16 ((dd_I*)   Y, (dd_I*)   X); }
static void DFT32_ddi       (void* Y, void* X) { DFT32 ((dd_I*)   Y, (dd_I*)   X); }
static void DFT64_ddi       (void* Y, void* X) { DFT64 ((dd_I*)   Y, (dd_I*)   X); }
static void DFT128_ddi      (void* Y, void* X) { DFT128((dd_I*)   Y, (dd_I*)   X); }
static void DFT256_ddi      (void* Y, void* X) { DFT256((dd_I*)   Y, (dd_I*)   X); }

static void DFT16_boost     (void* Y, void* X) { DFT16 ((f64i_bst *)  Y, (f64i_bst *) X); }
static void DFT32_boost     (void* Y, void* X) { DFT32 ((f64i_bst *)  Y, (f64i_bst *) X); }
static void DFT64_boost     (void* Y, void* X) { DFT64 ((f64i_bst *)  Y, (f64i_bst *) X); }
static void DFT128_boost    (void* Y, void* X) { DFT128((f64i_bst *)  Y, (f64i_bst *) X); }
static void DFT256_boost    (void* Y, void* X) { DFT256((f64i_bst *)  Y, (f64i_bst *) X); }

static void DFT16_filib     (void* Y, void* X) { DFT16 ((f64i_fil *)  Y, (f64i_fil *) X); }
static void DFT32_filib     (void* Y, void* X) { DFT32 ((f64i_fil *)  Y, (f64i_fil *) X); }
static void DFT64_filib     (void* Y, void* X) { DFT64 ((f64i_fil *)  Y, (f64i_fil *) X); }
static void DFT128_filib    (void* Y, void* X) { DFT128((f64i_fil *)  Y, (f64i_fil *) X); }
static void DFT256_filib    (void* Y, void* X) { DFT256((f64i_fil *)  Y, (f64i_fil *) X); }

static void DFT16_gaol      (void* Y, void* X) { DFT16 ((f64i_gal *)  Y, (f64i_gal *)   X); }
static void DFT32_gaol      (void* Y, void* X) { DFT32 ((f64i_gal *)  Y, (f64i_gal *)   X); }
static void DFT64_gaol      (void* Y, void* X) { DFT64 ((f64i_gal *)  Y, (f64i_gal *)   X); }
static void DFT128_gaol     (void* Y, void* X) { DFT128((f64i_gal *)  Y, (f64i_gal *)   X); }
static void DFT256_gaol     (void* Y, void* X) { DFT256((f64i_gal *)  Y, (f64i_gal *)   X); }

static void DFT16_yalaa     (void* Y, void* X) { DFT16 ((yalaa_af0 *)  Y, (yalaa_af0 *) X); }
static void DFT32_yalaa     (void* Y, void* X) { DFT32 ((yalaa_af0 *)  Y, (yalaa_af0 *) X); }
static void DFT64_yalaa     (void* Y, void* X) { DFT64 ((yalaa_af0 *)  Y, (yalaa_af0 *) X); }
static void DFT128_yalaa    (void* Y, void* X) { DFT128((yalaa_af0 *)  Y, (yalaa_af0 *) X); }
static void DFT256_yalaa    (void* Y, void* X) { DFT256((yalaa_af0 *)  Y, (yalaa_af0 *) X); }

static void AVX_DFT16_base  (void* Y, void* X) { AVX_DFT16 ((double*) Y, (double*) X); }
static void AVX_DFT32_base  (void* Y, void* X) { AVX_DFT32 ((double*) Y, (double*) X); }
static void AVX_DFT64_base  (void* Y, void* X) { AVX_DFT64 ((double*) Y, (double*) X); }
static void AVX_DFT128_base (void* Y, void* X) { AVX_DFT128((double*) Y, (double*) X); }
static void AVX_DFT256_base (void* Y, void* X) { AVX_DFT256((double*) Y, (double*) X); }

static void AVX_DFT16_f64i  (void* Y, void* X) { AVX_DFT16 ((f64_I*)  Y, (f64_I*)  X); }
static void AVX_DFT32_f64i  (void* Y, void* X) { AVX_DFT32 ((f64_I*)  Y, (f64_I*)  X); }
static void AVX_DFT64_f64i  (void* Y, void* X) { AVX_DFT64 ((f64_I*)  Y, (f64_I*)  X); }
static void AVX_DFT128_f64i (void* Y, void* X) { AVX_DFT128((f64_I*)  Y, (f64_I*)  X); }
static void AVX_DFT256_f64i (void* Y, void* X) { AVX_DFT256((f64_I*)  Y, (f64_I*)  X); }

static void AVX_DFT16_ddi   (void* Y, void* X) { AVX_DFT16 ((dd_I*)   Y, (dd_I*)   X); }
static void AVX_DFT32_ddi   (void* Y, void* X) { AVX_DFT32 ((dd_I*)   Y, (dd_I*)   X); }
static void AVX_DFT64_ddi   (void* Y, void* X) { AVX_DFT64 ((dd_I*)   Y, (dd_I*)   X); }
static void AVX_DFT128_ddi  (void* Y, void* X) { AVX_DFT128((dd_I*)   Y, (dd_I*)   X); }
static void AVX_DFT256_ddi  (void* Y, void* X) { AVX_DFT256((dd_I*)   Y, (dd_I*)   X); }