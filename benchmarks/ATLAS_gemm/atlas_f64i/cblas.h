#ifndef CBLAS_H
#include "igen_lib.h"

#ifndef CBLAS_ENUM_DEFINED_H
   #define CBLAS_ENUM_DEFINED_H
   enum CBLAS_ORDER {CblasRowMajor=101, CblasColMajor=102 };
   enum CBLAS_TRANSPOSE {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113,
                         AtlasConj=114};
   enum CBLAS_UPLO  {CblasUpper=121, CblasLower=122};
   enum CBLAS_DIAG  {CblasNonUnit=131, CblasUnit=132};
   enum CBLAS_SIDE  {CblasLeft=141, CblasRight=142};
#endif

#ifndef CBLAS_ENUM_ONLY
#define CBLAS_H
#define CBLAS_INDEX int

int cblas_errprn(int ierr, int info, char *form, ...);
void cblas_xerbla(int p, const char *rout, const char *form, ...);

/*
 * ===========================================================================
 * Prototypes for level 1 BLAS functions (complex are recast as routines)
 * ===========================================================================
 */
f32_I  cblas_sdsdot(const int N, const f32_I alpha, const f32_I *X,
                    const int incX, const f32_I *Y, const int incY);
f64_I cblas_dsdot(const int N, const f32_I *X, const int incX, const f32_I *Y,
                   const int incY);
f32_I  cblas_sdot(const int N, const f32_I  *X, const int incX,
                  const f32_I  *Y, const int incY);
f64_I cblas_ddot(const int N, const f64_I *X, const int incX,
                  const f64_I *Y, const int incY);
/*
 * Functions having prefixes Z and C only
 */
void   cblas_cdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu);
void   cblas_cdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc);

void   cblas_zdotu_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotu);
void   cblas_zdotc_sub(const int N, const void *X, const int incX,
                       const void *Y, const int incY, void *dotc);


/*
 * Functions having prefixes S D SC DZ
 */
f32_I  cblas_snrm2(const int N, const f32_I *X, const int incX);
f32_I  cblas_sasum(const int N, const f32_I *X, const int incX);

f64_I cblas_dnrm2(const int N, const f64_I *X, const int incX);
f64_I cblas_dasum(const int N, const f64_I *X, const int incX);

f32_I  cblas_scnrm2(const int N, const void *X, const int incX);
f32_I  cblas_scasum(const int N, const void *X, const int incX);

f64_I cblas_dznrm2(const int N, const void *X, const int incX);
f64_I cblas_dzasum(const int N, const void *X, const int incX);


/*
 * Functions having standard 4 prefixes (S D C Z)
 */
CBLAS_INDEX cblas_isamax(const int N, const f32_I  *X, const int incX);
CBLAS_INDEX cblas_idamax(const int N, const f64_I *X, const int incX);
CBLAS_INDEX cblas_icamax(const int N, const void   *X, const int incX);
CBLAS_INDEX cblas_izamax(const int N, const void   *X, const int incX);

/*
 * ===========================================================================
 * Prototypes for level 1 BLAS routines
 * ===========================================================================
 */

/*
 * Routines with standard 4 prefixes (s, d, c, z)
 */
void cblas_sswap(const int N, f32_I *X, const int incX,
                 f32_I *Y, const int incY);
void cblas_scopy(const int N, const f32_I *X, const int incX,
                 f32_I *Y, const int incY);
void cblas_saxpy(const int N, const f32_I alpha, const f32_I *X,
                 const int incX, f32_I *Y, const int incY);
void catlas_saxpby(const int N, const f32_I alpha, const f32_I *X,
                  const int incX, const f32_I beta, f32_I *Y, const int incY);
void catlas_sset
   (const int N, const f32_I alpha, f32_I *X, const int incX);

void cblas_dswap(const int N, f64_I *X, const int incX,
                 f64_I *Y, const int incY);
void cblas_dcopy(const int N, const f64_I *X, const int incX,
                 f64_I *Y, const int incY);
void cblas_daxpy(const int N, const f64_I alpha, const f64_I *X,
                 const int incX, f64_I *Y, const int incY);
void catlas_daxpby(const int N, const f64_I alpha, const f64_I *X,
                  const int incX, const f64_I beta, f64_I *Y, const int incY);
void catlas_dset
   (const int N, const f64_I alpha, f64_I *X, const int incX);

void cblas_cswap(const int N, void *X, const int incX,
                 void *Y, const int incY);
void cblas_ccopy(const int N, const void *X, const int incX,
                 void *Y, const int incY);
void cblas_caxpy(const int N, const void *alpha, const void *X,
                 const int incX, void *Y, const int incY);
void catlas_caxpby(const int N, const void *alpha, const void *X,
                  const int incX, const void *beta, void *Y, const int incY);
void catlas_cset
   (const int N, const void *alpha, void *X, const int incX);

void cblas_zswap(const int N, void *X, const int incX,
                 void *Y, const int incY);
void cblas_zcopy(const int N, const void *X, const int incX,
                 void *Y, const int incY);
void cblas_zaxpy(const int N, const void *alpha, const void *X,
                 const int incX, void *Y, const int incY);
void catlas_zaxpby(const int N, const void *alpha, const void *X,
                  const int incX, const void *beta, void *Y, const int incY);
void catlas_zset
   (const int N, const void *alpha, void *X, const int incX);


/*
 * Routines with S and D prefix only
 */
void cblas_srotg(f32_I *a, f32_I *b, f32_I *c, f32_I *s);
void cblas_srotmg(f32_I *d1, f32_I *d2, f32_I *b1, const f32_I b2, f32_I *P);
void cblas_srot(const int N, f32_I *X, const int incX,
                f32_I *Y, const int incY, const f32_I c, const f32_I s);
void cblas_srotm(const int N, f32_I *X, const int incX,
                f32_I *Y, const int incY, const f32_I *P);

void cblas_drotg(f64_I *a, f64_I *b, f64_I *c, f64_I *s);
void cblas_drotmg(f64_I *d1, f64_I *d2, f64_I *b1, const f64_I b2, f64_I *P);
void cblas_drot(const int N, f64_I *X, const int incX,
                f64_I *Y, const int incY, const f64_I c, const f64_I s);
void cblas_drotm(const int N, f64_I *X, const int incX,
                f64_I *Y, const int incY, const f64_I *P);


/*
 * Routines with S D C Z CS and ZD prefixes
 */
void cblas_sscal(const int N, const f32_I alpha, f32_I *X, const int incX);
void cblas_dscal(const int N, const f64_I alpha, f64_I *X, const int incX);
void cblas_cscal(const int N, const void *alpha, void *X, const int incX);
void cblas_zscal(const int N, const void *alpha, void *X, const int incX);
void cblas_csscal(const int N, const f32_I alpha, void *X, const int incX);
void cblas_zdscal(const int N, const f64_I alpha, void *X, const int incX);

/*
 * Extra reference routines provided by ATLAS, but not mandated by the standard
 */
void cblas_crotg(void *a, void *b, void *c, void *s);
void cblas_zrotg(void *a, void *b, void *c, void *s);
void cblas_csrot(const int N, void *X, const int incX, void *Y, const int incY,
                 const f32_I c, const f32_I s);
void cblas_zdrot(const int N, void *X, const int incX, void *Y, const int incY,
                 const f64_I c, const f64_I s);

/*
 * ===========================================================================
 * Prototypes for level 2 BLAS
 * ===========================================================================
 */

/*
 * Routines with standard 4 prefixes (S, D, C, Z)
 */
void cblas_sgemv(const enum CBLAS_ORDER Order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const f32_I alpha, const f32_I *A, const int lda,
                 const f32_I *X, const int incX, const f32_I beta,
                 f32_I *Y, const int incY);
void cblas_sgbmv(const enum CBLAS_ORDER Order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const int KL, const int KU, const f32_I alpha,
                 const f32_I *A, const int lda, const f32_I *X,
                 const int incX, const f32_I beta, f32_I *Y, const int incY);
void cblas_strmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const f32_I *A, const int lda,
                 f32_I *X, const int incX);
void cblas_stbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const f32_I *A, const int lda,
                 f32_I *X, const int incX);
void cblas_stpmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const f32_I *Ap, f32_I *X, const int incX);
void cblas_strsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const f32_I *A, const int lda, f32_I *X,
                 const int incX);
void cblas_stbsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const f32_I *A, const int lda,
                 f32_I *X, const int incX);
void cblas_stpsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const f32_I *Ap, f32_I *X, const int incX);

void cblas_dgemv(const enum CBLAS_ORDER Order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const f64_I alpha, const f64_I *A, const int lda,
                 const f64_I *X, const int incX, const f64_I beta,
                 f64_I *Y, const int incY);
void cblas_dgbmv(const enum CBLAS_ORDER Order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const int KL, const int KU, const f64_I alpha,
                 const f64_I *A, const int lda, const f64_I *X,
                 const int incX, const f64_I beta, f64_I *Y, const int incY);
void cblas_dtrmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const f64_I *A, const int lda,
                 f64_I *X, const int incX);
void cblas_dtbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const f64_I *A, const int lda,
                 f64_I *X, const int incX);
void cblas_dtpmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const f64_I *Ap, f64_I *X, const int incX);
void cblas_dtrsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const f64_I *A, const int lda, f64_I *X,
                 const int incX);
void cblas_dtbsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const f64_I *A, const int lda,
                 f64_I *X, const int incX);
void cblas_dtpsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const f64_I *Ap, f64_I *X, const int incX);

void cblas_cgemv(const enum CBLAS_ORDER Order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY);
void cblas_cgbmv(const enum CBLAS_ORDER Order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const int KL, const int KU, const void *alpha,
                 const void *A, const int lda, const void *X,
                 const int incX, const void *beta, void *Y, const int incY);
void cblas_ctrmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ctbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ctpmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *Ap, void *X, const int incX);
void cblas_ctrsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *A, const int lda, void *X,
                 const int incX);
void cblas_ctbsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ctpsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *Ap, void *X, const int incX);

void cblas_zgemv(const enum CBLAS_ORDER Order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *X, const int incX, const void *beta,
                 void *Y, const int incY);
void cblas_zgbmv(const enum CBLAS_ORDER Order,
                 const enum CBLAS_TRANSPOSE TransA, const int M, const int N,
                 const int KL, const int KU, const void *alpha,
                 const void *A, const int lda, const void *X,
                 const int incX, const void *beta, void *Y, const int incY);
void cblas_ztrmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ztbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ztpmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *Ap, void *X, const int incX);
void cblas_ztrsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *A, const int lda, void *X,
                 const int incX);
void cblas_ztbsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const int K, const void *A, const int lda,
                 void *X, const int incX);
void cblas_ztpsv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE TransA, const enum CBLAS_DIAG Diag,
                 const int N, const void *Ap, void *X, const int incX);


/*
 * Routines with S and D prefixes only
 */
void cblas_ssymv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const f32_I alpha, const f32_I *A,
                 const int lda, const f32_I *X, const int incX,
                 const f32_I beta, f32_I *Y, const int incY);
void cblas_ssbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const int K, const f32_I alpha, const f32_I *A,
                 const int lda, const f32_I *X, const int incX,
                 const f32_I beta, f32_I *Y, const int incY);
void cblas_sspmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const f32_I alpha, const f32_I *Ap,
                 const f32_I *X, const int incX,
                 const f32_I beta, f32_I *Y, const int incY);
void cblas_sger(const enum CBLAS_ORDER Order, const int M, const int N,
                const f32_I alpha, const f32_I *X, const int incX,
                const f32_I *Y, const int incY, f32_I *A, const int lda);
void cblas_ssyr(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f32_I alpha, const f32_I *X,
                const int incX, f32_I *A, const int lda);
void cblas_sspr(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f32_I alpha, const f32_I *X,
                const int incX, f32_I *Ap);
void cblas_ssyr2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f32_I alpha, const f32_I *X,
                const int incX, const f32_I *Y, const int incY, f32_I *A,
                const int lda);
void cblas_sspr2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f32_I alpha, const f32_I *X,
                const int incX, const f32_I *Y, const int incY, f32_I *A);

void cblas_dsymv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const f64_I alpha, const f64_I *A,
                 const int lda, const f64_I *X, const int incX,
                 const f64_I beta, f64_I *Y, const int incY);
void cblas_dsbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const int K, const f64_I alpha, const f64_I *A,
                 const int lda, const f64_I *X, const int incX,
                 const f64_I beta, f64_I *Y, const int incY);
void cblas_dspmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const f64_I alpha, const f64_I *Ap,
                 const f64_I *X, const int incX,
                 const f64_I beta, f64_I *Y, const int incY);
void cblas_dger(const enum CBLAS_ORDER Order, const int M, const int N,
                const f64_I alpha, const f64_I *X, const int incX,
                const f64_I *Y, const int incY, f64_I *A, const int lda);
void cblas_dsyr(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f64_I alpha, const f64_I *X,
                const int incX, f64_I *A, const int lda);
void cblas_dspr(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f64_I alpha, const f64_I *X,
                const int incX, f64_I *Ap);
void cblas_dsyr2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f64_I alpha, const f64_I *X,
                const int incX, const f64_I *Y, const int incY, f64_I *A,
                const int lda);
void cblas_dspr2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f64_I alpha, const f64_I *X,
                const int incX, const f64_I *Y, const int incY, f64_I *A);


/*
 * Routines with C and Z prefixes only
 */
void cblas_chemv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const void *alpha, const void *A,
                 const int lda, const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_chbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const int K, const void *alpha, const void *A,
                 const int lda, const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_chpmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const void *alpha, const void *Ap,
                 const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_cgeru(const enum CBLAS_ORDER Order, const int M, const int N,
                 const void *alpha, const void *X, const int incX,
                 const void *Y, const int incY, void *A, const int lda);
void cblas_cgerc(const enum CBLAS_ORDER Order, const int M, const int N,
                 const void *alpha, const void *X, const int incX,
                 const void *Y, const int incY, void *A, const int lda);
void cblas_cher(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f32_I alpha, const void *X, const int incX,
                void *A, const int lda);
void cblas_chpr(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f32_I alpha, const void *X,
                const int incX, void *A);
void cblas_cher2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const int N,
                const void *alpha, const void *X, const int incX,
                const void *Y, const int incY, void *A, const int lda);
void cblas_chpr2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const int N,
                const void *alpha, const void *X, const int incX,
                const void *Y, const int incY, void *Ap);

void cblas_zhemv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const void *alpha, const void *A,
                 const int lda, const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_zhbmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const int K, const void *alpha, const void *A,
                 const int lda, const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_zhpmv(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const int N, const void *alpha, const void *Ap,
                 const void *X, const int incX,
                 const void *beta, void *Y, const int incY);
void cblas_zgeru(const enum CBLAS_ORDER Order, const int M, const int N,
                 const void *alpha, const void *X, const int incX,
                 const void *Y, const int incY, void *A, const int lda);
void cblas_zgerc(const enum CBLAS_ORDER Order, const int M, const int N,
                 const void *alpha, const void *X, const int incX,
                 const void *Y, const int incY, void *A, const int lda);
void cblas_zher(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f64_I alpha, const void *X, const int incX,
                void *A, const int lda);
void cblas_zhpr(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                const int N, const f64_I alpha, const void *X,
                const int incX, void *A);
void cblas_zher2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const int N,
                const void *alpha, const void *X, const int incX,
                const void *Y, const int incY, void *A, const int lda);
void cblas_zhpr2(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo, const int N,
                const void *alpha, const void *X, const int incX,
                const void *Y, const int incY, void *Ap);

/*
 * ===========================================================================
 * Prototypes for level 3 BLAS
 * ===========================================================================
 */

/*
 * Routines with standard 4 prefixes (S, D, C, Z)
 */
void cblas_sgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const f32_I alpha, const f32_I *A,
                 const int lda, const f32_I *B, const int ldb,
                 const f32_I beta, f32_I *C, const int ldc);
void cblas_ssymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const int M, const int N,
                 const f32_I alpha, const f32_I *A, const int lda,
                 const f32_I *B, const int ldb, const f32_I beta,
                 f32_I *C, const int ldc);
void cblas_ssyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                 const f32_I alpha, const f32_I *A, const int lda,
                 const f32_I beta, f32_I *C, const int ldc);
void cblas_ssyr2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                  const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                  const f32_I alpha, const f32_I *A, const int lda,
                  const f32_I *B, const int ldb, const f32_I beta,
                  f32_I *C, const int ldc);
void cblas_strmm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_DIAG Diag, const int M, const int N,
                 const f32_I alpha, const f32_I *A, const int lda,
                 f32_I *B, const int ldb);
void cblas_strsm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_DIAG Diag, const int M, const int N,
                 const f32_I alpha, const f32_I *A, const int lda,
                 f32_I *B, const int ldb);

void cblas_dgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const f64_I alpha, const f64_I *A,
                 const int lda, const f64_I *B, const int ldb,
                 const f64_I beta, f64_I *C, const int ldc);
void cblas_dsymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const int M, const int N,
                 const f64_I alpha, const f64_I *A, const int lda,
                 const f64_I *B, const int ldb, const f64_I beta,
                 f64_I *C, const int ldc);
void cblas_dsyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                 const f64_I alpha, const f64_I *A, const int lda,
                 const f64_I beta, f64_I *C, const int ldc);
void cblas_dsyr2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                  const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                  const f64_I alpha, const f64_I *A, const int lda,
                  const f64_I *B, const int ldb, const f64_I beta,
                  f64_I *C, const int ldc);
void cblas_dtrmm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_DIAG Diag, const int M, const int N,
                 const f64_I alpha, const f64_I *A, const int lda,
                 f64_I *B, const int ldb);
void cblas_dtrsm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_DIAG Diag, const int M, const int N,
                 const f64_I alpha, const f64_I *A, const int lda,
                 f64_I *B, const int ldb);

void cblas_cgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc);
void cblas_csymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *B, const int ldb, const void *beta,
                 void *C, const int ldc);
void cblas_csyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                 const void *alpha, const void *A, const int lda,
                 const void *beta, void *C, const int ldc);
void cblas_csyr2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                  const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                  const void *alpha, const void *A, const int lda,
                  const void *B, const int ldb, const void *beta,
                  void *C, const int ldc);
void cblas_ctrmm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_DIAG Diag, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 void *B, const int ldb);
void cblas_ctrsm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_DIAG Diag, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 void *B, const int ldb);

void cblas_zgemm(const enum CBLAS_ORDER Order, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc);
void cblas_zsymm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *B, const int ldb, const void *beta,
                 void *C, const int ldc);
void cblas_zsyrk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                 const void *alpha, const void *A, const int lda,
                 const void *beta, void *C, const int ldc);
void cblas_zsyr2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                  const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                  const void *alpha, const void *A, const int lda,
                  const void *B, const int ldb, const void *beta,
                  void *C, const int ldc);
void cblas_ztrmm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_DIAG Diag, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 void *B, const int ldb);
void cblas_ztrsm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const enum CBLAS_TRANSPOSE TransA,
                 const enum CBLAS_DIAG Diag, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 void *B, const int ldb);


/*
 * Routines with prefixes C and Z only
 */
void cblas_chemm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *B, const int ldb, const void *beta,
                 void *C, const int ldc);
void cblas_cherk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                 const f32_I alpha, const void *A, const int lda,
                 const f32_I beta, void *C, const int ldc);
void cblas_cher2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                  const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                  const void *alpha, const void *A, const int lda,
                  const void *B, const int ldb, const f32_I beta,
                  void *C, const int ldc);
void cblas_zhemm(const enum CBLAS_ORDER Order, const enum CBLAS_SIDE Side,
                 const enum CBLAS_UPLO Uplo, const int M, const int N,
                 const void *alpha, const void *A, const int lda,
                 const void *B, const int ldb, const void *beta,
                 void *C, const int ldc);
void cblas_zherk(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                 const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                 const f64_I alpha, const void *A, const int lda,
                 const f64_I beta, void *C, const int ldc);
void cblas_zher2k(const enum CBLAS_ORDER Order, const enum CBLAS_UPLO Uplo,
                  const enum CBLAS_TRANSPOSE Trans, const int N, const int K,
                  const void *alpha, const void *A, const int lda,
                  const void *B, const int ldb, const f64_I beta,
                  void *C, const int ldc);

int cblas_errprn(int ierr, int info, char *form, ...);

#endif  /* end #ifdef CBLAS_ENUM_ONLY */
#endif
