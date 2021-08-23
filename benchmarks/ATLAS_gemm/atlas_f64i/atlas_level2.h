#pragma once
#include "igen_lib.h"
/*
 *             Automatically Tuned Linear Algebra Software v3.10.3
 *                    (C) Copyright 1999 R. Clint Whaley
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions, and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *   3. The name of the ATLAS group or the names of its contributers may
 *      not be used to endorse or promote products derived from this
 *      software without specific written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE ATLAS GROUP OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * ===========================================================================
 * Prototypes for level 2 BLAS
 * ===========================================================================
 */

int ATL_L2AIsOverlapped(int rank, int sz, int M, int N, int A, int lda);
/*
 * Routines with standard 4 prefixes (S, D, C, Z)
 */
void ATL_sgemv(const enum ATLAS_TRANS TransA, const int M, const int N,
               f32_I alpha, const f32_I *A, const int lda, const f32_I *X,
               const int incX, f32_I beta, f32_I *Y, const int incY);
void ATL_sgemvN_L2(int M, int N, f32_I alpha, const f32_I *A, int lda,
                   const f32_I *X, int incX, f32_I beta, f32_I *Y, int incY);
void ATL_sgemvN_L1(int M, int N, f32_I alpha, const f32_I *A, int lda,
                   const f32_I *X, int incX, f32_I beta, f32_I *Y, int incY);
void ATL_sgemvN(int M, int N, f32_I alpha, const f32_I *A, int lda,
                const f32_I *X, int incX, f32_I beta, f32_I *Y, int incY);
void ATL_sgemvT_L2(int M, int N, f32_I alpha, const f32_I *A, int lda,
                   const f32_I *X, int incX, f32_I beta, f32_I *Y, int incY);
void ATL_sgemvT_L1(int M, int N, f32_I alpha, const f32_I *A, int lda,
                   const f32_I *X, int incX, f32_I beta, f32_I *Y, int incY);
void ATL_sgemvT(int M, int N, f32_I alpha, const f32_I *A, int lda,
                const f32_I *X, int incX, f32_I beta, f32_I *Y, int incY);
void ATL_sgbmv(const enum ATLAS_TRANS TransA, const int M, const int N,
               const int KL, const int KU, f32_I alpha, const f32_I *A,
               const int lda, const f32_I *X, const int incX, f32_I beta,
               f32_I *Y, const int incY);
void ATL_strmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f32_I *A,
               const int lda, f32_I *X, const int incX);
void ATL_stbmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const int K,
               const f32_I *A, const int lda, f32_I *X, const int incX);
void ATL_stpmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f32_I *Ap,
               f32_I *X, const int incX);
void ATL_strsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f32_I *A,
               const int lda, f32_I *X, const int incX);
void ATL_stbsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const int K,
               const f32_I *A, const int lda, f32_I *X, const int incX);
void ATL_stpsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f32_I *Ap,
               f32_I *X, const int incX);

void ATL_dgemv(const enum ATLAS_TRANS TransA, const int M, const int N,
               f64_I alpha, const f64_I *A, const int lda, const f64_I *X,
               const int incX, f64_I beta, f64_I *Y, const int incY);
void ATL_dgemvN_L2(int M, int N, f64_I alpha, const f64_I *A, int lda,
                   const f64_I *X, int incX, f64_I beta, f64_I *Y, int incY);
void ATL_dgemvN_L1(int M, int N, f64_I alpha, const f64_I *A, int lda,
                   const f64_I *X, int incX, f64_I beta, f64_I *Y, int incY);
void ATL_dgemvN(int M, int N, f64_I alpha, const f64_I *A, int lda,
                const f64_I *X, int incX, f64_I beta, f64_I *Y, int incY);
void ATL_dgemvT_L2(int M, int N, f64_I alpha, const f64_I *A, int lda,
                   const f64_I *X, int incX, f64_I beta, f64_I *Y, int incY);
void ATL_dgemvT_L1(int M, int N, f64_I alpha, const f64_I *A, int lda,
                   const f64_I *X, int incX, f64_I beta, f64_I *Y, int incY);
void ATL_dgemvT(int M, int N, f64_I alpha, const f64_I *A, int lda,
                const f64_I *X, int incX, f64_I beta, f64_I *Y, int incY);
void ATL_dgbmv(const enum ATLAS_TRANS TransA, const int M, const int N,
               const int KL, const int KU, f64_I alpha, const f64_I *A,
               const int lda, const f64_I *X, const int incX, f64_I beta,
               f64_I *Y, const int incY);
void ATL_dtrmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f64_I *A,
               const int lda, f64_I *X, const int incX);
void ATL_dtbmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const int K,
               const f64_I *A, const int lda, f64_I *X, const int incX);
void ATL_dtpmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f64_I *Ap,
               f64_I *X, const int incX);
void ATL_dtrsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f64_I *A,
               const int lda, f64_I *X, const int incX);
void ATL_dtbsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const int K,
               const f64_I *A, const int lda, f64_I *X, const int incX);
void ATL_dtpsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f64_I *Ap,
               f64_I *X, const int incX);

void ATL_cgemv(const enum ATLAS_TRANS TransA, const int M, const int N,
               const f32_I *alpha, const f32_I *A, const int lda,
               const f32_I *X, const int incX, const f32_I *beta, f32_I *Y,
               const int incY);
void ATL_cgemvN_L2(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                   const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                   int incY);
void ATL_cgemvN_L1(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                   const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                   int incY);
void ATL_cgemvN(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                int incY);
void ATL_cgemvT_L2(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                   const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                   int incY);
void ATL_cgemvT_L1(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                   const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                   int incY);
void ATL_cgemvT(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                int incY);
void ATL_cgbmv(const enum ATLAS_TRANS TransA, const int M, const int N,
               const int KL, const int KU, const f32_I *alpha, const f32_I *A,
               const int lda, const f32_I *X, const int incX, const f32_I *beta,
               f32_I *Y, const int incY);
void ATL_ctrmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f32_I *A,
               const int lda, f32_I *X, const int incX);
void ATL_ctbmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const int K,
               const f32_I *A, const int lda, f32_I *X, const int incX);
void ATL_ctpmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f32_I *Ap,
               f32_I *X, const int incX);
void ATL_ctrsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f32_I *A,
               const int lda, f32_I *X, const int incX);
void ATL_ctbsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const int K,
               const f32_I *A, const int lda, f32_I *X, const int incX);
void ATL_ctpsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f32_I *Ap,
               f32_I *X, const int incX);

void ATL_zgemv(const enum ATLAS_TRANS TransA, const int M, const int N,
               const f64_I *alpha, const f64_I *A, const int lda,
               const f64_I *X, const int incX, const f64_I *beta, f64_I *Y,
               const int incY);
void ATL_zgemvN_L2(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                   const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                   int incY);
void ATL_zgemvN_L1(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                   const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                   int incY);
void ATL_zgemvN(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                int incY);
void ATL_zgemvT_L2(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                   const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                   int incY);
void ATL_zgemvT_L1(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                   const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                   int incY);
void ATL_zgemvT(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                int incY);
void ATL_zgbmv(const enum ATLAS_TRANS TransA, const int M, const int N,
               const int KL, const int KU, const f64_I *alpha, const f64_I *A,
               const int lda, const f64_I *X, const int incX, const f64_I *beta,
               f64_I *Y, const int incY);
void ATL_ztrmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f64_I *A,
               const int lda, f64_I *X, const int incX);
void ATL_ztbmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const int K,
               const f64_I *A, const int lda, f64_I *X, const int incX);
void ATL_ztpmv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f64_I *Ap,
               f64_I *X, const int incX);
void ATL_ztrsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f64_I *A,
               const int lda, f64_I *X, const int incX);
void ATL_ztbsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const int K,
               const f64_I *A, const int lda, f64_I *X, const int incX);
void ATL_ztpsv(const enum ATLAS_UPLO Uplo, const enum ATLAS_TRANS TransA,
               const enum ATLAS_DIAG Diag, const int N, const f64_I *Ap,
               f64_I *X, const int incX);

/*
 * Routines with S and D prefixes only
 */
void ATL_ssymv(const enum ATLAS_UPLO Uplo, const int N, f32_I alpha,
               const f32_I *A, const int lda, const f32_I *X, const int incX,
               f32_I beta, f32_I *Y, const int incY);
void ATL_ssbmv(const enum ATLAS_UPLO Uplo, const int N, const int K,
               f32_I alpha, const f32_I *A, const int lda, const f32_I *X,
               const int incX, f32_I beta, f32_I *Y, const int incY);
void ATL_sspmv(const enum ATLAS_UPLO Uplo, const int N, f32_I alpha,
               const f32_I *Ap, const f32_I *X, const int incX, f32_I beta,
               f32_I *Y, const int incY);
void ATL_sger_OOC(const int M, const int N, f32_I alpha, const f32_I *X,
                  const int incX, const f32_I *Y, const int incY, f32_I *A,
                  const int lda);
void ATL_sger_L1(const int M, const int N, f32_I alpha, const f32_I *X,
                 const int incX, const f32_I *Y, const int incY, f32_I *A,
                 const int lda);
void ATL_sger_L2(const int M, const int N, f32_I alpha, const f32_I *X,
                 const int incX, const f32_I *Y, const int incY, f32_I *A,
                 const int lda);
void ATL_sger(const int M, const int N, f32_I alpha, const f32_I *X,
              const int incX, const f32_I *Y, const int incY, f32_I *A,
              const int lda);
void ATL_sger2_OOC(const int M, const int N, f32_I alpha, const f32_I *X,
                   const int incX, const f32_I *Y, const int incY, f32_I beta,
                   const f32_I *W, const int incW, const f32_I *Z,
                   const int incZ, f32_I *A, const int lda);
void ATL_sger2_L1(const int M, const int N, f32_I alpha, const f32_I *X,
                  const int incX, const f32_I *Y, const int incY, f32_I beta,
                  const f32_I *W, const int incW, const f32_I *Z,
                  const int incZ, f32_I *A, const int lda);
void ATL_sger2_L2(const int M, const int N, f32_I alpha, const f32_I *X,
                  const int incX, const f32_I *Y, const int incY, f32_I beta,
                  const f32_I *W, const int incW, const f32_I *Z,
                  const int incZ, f32_I *A, const int lda);
void ATL_sger2(const int M, const int N, f32_I alpha, const f32_I *X,
               const int incX, const f32_I *Y, const int incY, f32_I beta,
               const f32_I *W, const int incW, const f32_I *Z, const int incZ,
               f32_I *A, const int lda);
void ATL_ssyr(const enum ATLAS_UPLO Uplo, const int N, f32_I alpha,
              const f32_I *X, const int incX, f32_I *A, const int lda);
void ATL_sspr(const enum ATLAS_UPLO Uplo, const int N, f32_I alpha,
              const f32_I *X, const int incX, f32_I *Ap);
void ATL_ssyr2(const enum ATLAS_UPLO Uplo, const int N, f32_I alpha,
               const f32_I *X, const int incX, const f32_I *Y, const int incY,
               f32_I *A, const int lda);
void ATL_sspr2(const enum ATLAS_UPLO Uplo, const int N, f32_I alpha,
               const f32_I *X, const int incX, const f32_I *Y, const int incY,
               f32_I *A);

void ATL_dsymv(const enum ATLAS_UPLO Uplo, const int N, f64_I alpha,
               const f64_I *A, const int lda, const f64_I *X, const int incX,
               f64_I beta, f64_I *Y, const int incY);
void ATL_dsbmv(const enum ATLAS_UPLO Uplo, const int N, const int K,
               f64_I alpha, const f64_I *A, const int lda, const f64_I *X,
               const int incX, f64_I beta, f64_I *Y, const int incY);
void ATL_dspmv(const enum ATLAS_UPLO Uplo, const int N, f64_I alpha,
               const f64_I *Ap, const f64_I *X, const int incX, f64_I beta,
               f64_I *Y, const int incY);
void ATL_dger_OOC(const int M, const int N, f64_I alpha, const f64_I *X,
                  const int incX, const f64_I *Y, const int incY, f64_I *A,
                  const int lda);
void ATL_dger_L1(const int M, const int N, f64_I alpha, const f64_I *X,
                 const int incX, const f64_I *Y, const int incY, f64_I *A,
                 const int lda);
void ATL_dger_L2(const int M, const int N, f64_I alpha, const f64_I *X,
                 const int incX, const f64_I *Y, const int incY, f64_I *A,
                 const int lda);
void ATL_dger(const int M, const int N, f64_I alpha, const f64_I *X,
              const int incX, const f64_I *Y, const int incY, f64_I *A,
              const int lda);
void ATL_dger2_OOC(const int M, const int N, f64_I alpha, const f64_I *X,
                   const int incX, const f64_I *Y, const int incY, f64_I beta,
                   const f64_I *W, const int incW, const f64_I *Z,
                   const int incZ, f64_I *A, const int lda);
void ATL_dger2_L1(const int M, const int N, f64_I alpha, const f64_I *X,
                  const int incX, const f64_I *Y, const int incY, f64_I beta,
                  const f64_I *W, const int incW, const f64_I *Z,
                  const int incZ, f64_I *A, const int lda);
void ATL_dger2_L2(const int M, const int N, f64_I alpha, const f64_I *X,
                  const int incX, const f64_I *Y, const int incY, f64_I beta,
                  const f64_I *W, const int incW, const f64_I *Z,
                  const int incZ, f64_I *A, const int lda);
void ATL_dger2(const int M, const int N, f64_I alpha, const f64_I *X,
               const int incX, const f64_I *Y, const int incY, f64_I beta,
               const f64_I *W, const int incW, const f64_I *Z, const int incZ,
               f64_I *A, const int lda);
void ATL_dsyr(const enum ATLAS_UPLO Uplo, const int N, f64_I alpha,
              const f64_I *X, const int incX, f64_I *A, const int lda);
void ATL_dspr(const enum ATLAS_UPLO Uplo, const int N, f64_I alpha,
              const f64_I *X, const int incX, f64_I *Ap);
void ATL_dsyr2(const enum ATLAS_UPLO Uplo, const int N, f64_I alpha,
               const f64_I *X, const int incX, const f64_I *Y, const int incY,
               f64_I *A, const int lda);
void ATL_dspr2(const enum ATLAS_UPLO Uplo, const int N, f64_I alpha,
               const f64_I *X, const int incX, const f64_I *Y, const int incY,
               f64_I *A);

/*
 * Routines with C and Z prefixes only
 */
void ATL_cgemvCN_L2(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                    const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                    int incY);
void ATL_cgemvCN_L1(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                    const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                    int incY);
void ATL_cgemvCN(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                 const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                 int incY);
void ATL_cgemvCT_L2(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                    const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                    int incY);
void ATL_cgemvCT_L1(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                    const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                    int incY);
void ATL_cgemvCT(int M, int N, const f32_I *alpha, const f32_I *A, int lda,
                 const f32_I *X, int incX, const f32_I *beta, f32_I *Y,
                 int incY);
void ATL_chemv(const enum ATLAS_UPLO Uplo, const int N, const f32_I *alpha,
               const f32_I *A, const int lda, const f32_I *X, const int incX,
               const f32_I *beta, f32_I *Y, const int incY);
void ATL_chbmv(const enum ATLAS_UPLO Uplo, const int N, const int K,
               const f32_I *alpha, const f32_I *A, const int lda,
               const f32_I *X, const int incX, const f32_I *beta, f32_I *Y,
               const int incY);
void ATL_chpmv(const enum ATLAS_UPLO Uplo, const int N, const f32_I *alpha,
               const f32_I *Ap, const f32_I *X, const int incX,
               const f32_I *beta, f32_I *Y, const int incY);
void ATL_cgerc_OOC(const int M, const int N, const f32_I *alpha, const f32_I *X,
                   const int incX, const f32_I *Y, const int incY, f32_I *A,
                   const int lda);
void ATL_cgerc_L2(const int M, const int N, const f32_I *alpha, const f32_I *X,
                  const int incX, const f32_I *Y, const int incY, f32_I *A,
                  const int lda);
void ATL_cgerc_L1(const int M, const int N, const f32_I *alpha, const f32_I *X,
                  const int incX, const f32_I *Y, const int incY, f32_I *A,
                  const int lda);
void ATL_cgerc(const int M, const int N, const f32_I *alpha, const f32_I *X,
               const int incX, const f32_I *Y, const int incY, f32_I *A,
               const int lda);
void ATL_cgeru_OOC(const int M, const int N, const f32_I *alpha, const f32_I *X,
                   const int incX, const f32_I *Y, const int incY, f32_I *A,
                   const int lda);
void ATL_cgeru_L2(const int M, const int N, const f32_I *alpha, const f32_I *X,
                  const int incX, const f32_I *Y, const int incY, f32_I *A,
                  const int lda);
void ATL_cgeru_L1(const int M, const int N, const f32_I *alpha, const f32_I *X,
                  const int incX, const f32_I *Y, const int incY, f32_I *A,
                  const int lda);
void ATL_cgeru(const int M, const int N, const f32_I *alpha, const f32_I *X,
               const int incX, const f32_I *Y, const int incY, f32_I *A,
               const int lda);

void ATL_cger2c_OOC(const int M, const int N, const f32_I *alpha,
                    const f32_I *X, const int incX, const f32_I *Y,
                    const int incY, const f32_I *beta, const f32_I *W,
                    const int incW, const f32_I *Z, const int incZ, f32_I *A,
                    const int lda);
void ATL_cger2c_L2(const int M, const int N, const f32_I *alpha, const f32_I *X,
                   const int incX, const f32_I *Y, const int incY,
                   const f32_I *beta, const f32_I *W, const int incW,
                   const f32_I *Z, const int incZ, f32_I *A, const int lda);
void ATL_cger2c_L1(const int M, const int N, const f32_I *alpha, const f32_I *X,
                   const int incX, const f32_I *Y, const int incY,
                   const f32_I *beta, const f32_I *W, const int incW,
                   const f32_I *Z, const int incZ, f32_I *A, const int lda);
void ATL_cger2c(const int M, const int N, const f32_I *alpha, const f32_I *X,
                const int incX, const f32_I *Y, const int incY,
                const f32_I *beta, const f32_I *W, const int incW,
                const f32_I *Z, const int incZ, f32_I *A, const int lda);
void ATL_cger2u_OOC(const int M, const int N, const f32_I *alpha,
                    const f32_I *X, const int incX, const f32_I *Y,
                    const int incY, const f32_I *beta, const f32_I *W,
                    const int incW, const f32_I *Z, const int incZ, f32_I *A,
                    const int lda);
void ATL_cger2u_L2(const int M, const int N, const f32_I *alpha, const f32_I *X,
                   const int incX, const f32_I *Y, const int incY,
                   const f32_I *beta, const f32_I *W, const int incW,
                   const f32_I *Z, const int incZ, f32_I *A, const int lda);
void ATL_cger2u_L1(const int M, const int N, const f32_I *alpha, const f32_I *X,
                   const int incX, const f32_I *Y, const int incY,
                   const f32_I *beta, const f32_I *W, const int incW,
                   const f32_I *Z, const int incZ, f32_I *A, const int lda);
void ATL_cger2u(const int M, const int N, const f32_I *alpha, const f32_I *X,
                const int incX, const f32_I *Y, const int incY,
                const f32_I *beta, const f32_I *W, const int incW,
                const f32_I *Z, const int incZ, f32_I *A, const int lda);
void ATL_cher(const enum ATLAS_UPLO Uplo, const int N, f32_I alpha,
              const f32_I *X, const int incX, f32_I *A, const int lda);
void ATL_chpr(const enum ATLAS_UPLO Uplo, const int N, f32_I alpha,
              const f32_I *X, const int incX, f32_I *A);
void ATL_cher2(const enum ATLAS_UPLO Uplo, const int N, const f32_I *alpha,
               const f32_I *X, const int incX, const f32_I *Y, const int incY,
               f32_I *A, const int lda);
void ATL_chpr2(const enum ATLAS_UPLO Uplo, const int N, const f32_I *alpha,
               const f32_I *X, const int incX, const f32_I *Y, const int incY,
               f32_I *Ap);

void ATL_zgemvCN_L2(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                    const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                    int incY);
void ATL_zgemvCN_L1(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                    const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                    int incY);
void ATL_zgemvCN(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                 const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                 int incY);
void ATL_zgemvCT_L2(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                    const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                    int incY);
void ATL_zgemvCT_L1(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                    const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                    int incY);
void ATL_zgemvCT(int M, int N, const f64_I *alpha, const f64_I *A, int lda,
                 const f64_I *X, int incX, const f64_I *beta, f64_I *Y,
                 int incY);
void ATL_zhemv(const enum ATLAS_UPLO Uplo, const int N, const f64_I *alpha,
               const f64_I *A, const int lda, const f64_I *X, const int incX,
               const f64_I *beta, f64_I *Y, const int incY);
void ATL_zhbmv(const enum ATLAS_UPLO Uplo, const int N, const int K,
               const f64_I *alpha, const f64_I *A, const int lda,
               const f64_I *X, const int incX, const f64_I *beta, f64_I *Y,
               const int incY);
void ATL_zhpmv(const enum ATLAS_UPLO Uplo, const int N, const f64_I *alpha,
               const f64_I *Ap, const f64_I *X, const int incX,
               const f64_I *beta, f64_I *Y, const int incY);
void ATL_zgerc_OOC(const int M, const int N, const f64_I *alpha, const f64_I *X,
                   const int incX, const f64_I *Y, const int incY, f64_I *A,
                   const int lda);
void ATL_zgerc_L2(const int M, const int N, const f64_I *alpha, const f64_I *X,
                  const int incX, const f64_I *Y, const int incY, f64_I *A,
                  const int lda);
void ATL_zgerc_L1(const int M, const int N, const f64_I *alpha, const f64_I *X,
                  const int incX, const f64_I *Y, const int incY, f64_I *A,
                  const int lda);
void ATL_zgerc(const int M, const int N, const f64_I *alpha, const f64_I *X,
               const int incX, const f64_I *Y, const int incY, f64_I *A,
               const int lda);
void ATL_zgeru_OOC(const int M, const int N, const f64_I *alpha, const f64_I *X,
                   const int incX, const f64_I *Y, const int incY, f64_I *A,
                   const int lda);
void ATL_zgeru_L2(const int M, const int N, const f64_I *alpha, const f64_I *X,
                  const int incX, const f64_I *Y, const int incY, f64_I *A,
                  const int lda);
void ATL_zgeru_L1(const int M, const int N, const f64_I *alpha, const f64_I *X,
                  const int incX, const f64_I *Y, const int incY, f64_I *A,
                  const int lda);
void ATL_zgeru(const int M, const int N, const f64_I *alpha, const f64_I *X,
               const int incX, const f64_I *Y, const int incY, f64_I *A,
               const int lda);

void ATL_zger2c_OOC(const int M, const int N, const f64_I *alpha,
                    const f64_I *X, const int incX, const f64_I *Y,
                    const int incY, const f64_I *beta, const f64_I *W,
                    const int incW, const f64_I *Z, const int incZ, f64_I *A,
                    const int lda);
void ATL_zger2c_L2(const int M, const int N, const f64_I *alpha, const f64_I *X,
                   const int incX, const f64_I *Y, const int incY,
                   const f64_I *beta, const f64_I *W, const int incW,
                   const f64_I *Z, const int incZ, f64_I *A, const int lda);
void ATL_zger2c_L1(const int M, const int N, const f64_I *alpha, const f64_I *X,
                   const int incX, const f64_I *Y, const int incY,
                   const f64_I *beta, const f64_I *W, const int incW,
                   const f64_I *Z, const int incZ, f64_I *A, const int lda);
void ATL_zger2c(const int M, const int N, const f64_I *alpha, const f64_I *X,
                const int incX, const f64_I *Y, const int incY,
                const f64_I *beta, const f64_I *W, const int incW,
                const f64_I *Z, const int incZ, f64_I *A, const int lda);
void ATL_zger2u_OOC(const int M, const int N, const f64_I *alpha,
                    const f64_I *X, const int incX, const f64_I *Y,
                    const int incY, const f64_I *beta, const f64_I *W,
                    const int incW, const f64_I *Z, const int incZ, f64_I *A,
                    const int lda);
void ATL_zger2u_L2(const int M, const int N, const f64_I *alpha, const f64_I *X,
                   const int incX, const f64_I *Y, const int incY,
                   const f64_I *beta, const f64_I *W, const int incW,
                   const f64_I *Z, const int incZ, f64_I *A, const int lda);
void ATL_zger2u_L1(const int M, const int N, const f64_I *alpha, const f64_I *X,
                   const int incX, const f64_I *Y, const int incY,
                   const f64_I *beta, const f64_I *W, const int incW,
                   const f64_I *Z, const int incZ, f64_I *A, const int lda);
void ATL_zger2u(const int M, const int N, const f64_I *alpha, const f64_I *X,
                const int incX, const f64_I *Y, const int incY,
                const f64_I *beta, const f64_I *W, const int incW,
                const f64_I *Z, const int incZ, f64_I *A, const int lda);
void ATL_zher(const enum ATLAS_UPLO Uplo, const int N, f64_I alpha,
              const f64_I *X, const int incX, f64_I *A, const int lda);
void ATL_zhpr(const enum ATLAS_UPLO Uplo, const int N, f64_I alpha,
              const f64_I *X, const int incX, f64_I *A);
void ATL_zher2(const enum ATLAS_UPLO Uplo, const int N, const f64_I *alpha,
               const f64_I *X, const int incX, const f64_I *Y, const int incY,
               f64_I *A, const int lda);
void ATL_zhpr2(const enum ATLAS_UPLO Uplo, const int N, const f64_I *alpha,
               const f64_I *X, const int incX, const f64_I *Y, const int incY,
               f64_I *Ap);
