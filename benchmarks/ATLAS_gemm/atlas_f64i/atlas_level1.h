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
 * Prototypes ATLAS Level 1 functions not defined in atlas_aux.h
 */

/*
 * Many level one blas routines actually taken care of by atlas auxiliary
 */
#include "atlas_aux.h"

f32_I ATL_sdsdot(const int N, f32_I alpha, const f32_I *X, const int incX,
                 const f32_I *Y, const int incY);
f64_I ATL_dsdot(const int N, const f32_I *X, const int incX, const f32_I *Y,
                const int incY);
/*
 * Routines with all four types
 */
void ATL_sswap(const int N, f32_I *X, const int incX, f32_I *Y, const int incY);
int ATL_isamax(const int N, const f32_I *X, const int incX);

void ATL_dswap(const int N, f64_I *X, const int incX, f64_I *Y, const int incY);
int ATL_idamax(const int N, const f64_I *X, const int incX);

void ATL_cswap(const int N, f32_I *X, const int incX, f32_I *Y, const int incY);
int ATL_icamax(const int N, const f32_I *X, const int incX);

void ATL_zswap(const int N, f64_I *X, const int incX, f64_I *Y, const int incY);
int ATL_izamax(const int N, const f64_I *X, const int incX);

/*
 * Routines with real types
 */
void ATL_srotg(f32_I *a, f32_I *b, f32_I *c, f32_I *s);
void ATL_srotmg(f32_I *d1, f32_I *d2, f32_I *b1, f32_I b2, f32_I *P);
void ATL_srot(const int N, f32_I *X, const int incX, f32_I *Y, const int incY,
              f32_I c, f32_I s);
void ATL_srotm(const int N, f32_I *X, const int incX, f32_I *Y, const int incY,
               const f32_I *P);
f32_I ATL_sdot(const int N, const f32_I *X, const int incX, const f32_I *Y,
               const int incY);
void ATL_sssq(const int N, const f32_I *X, const int incX, f32_I *scal0,
              f32_I *ssq0);
f32_I ATL_snrm2(const int N, const f32_I *X, const int incX);
f32_I ATL_sasum(const int N, const f32_I *X, const int incX);

void ATL_drotg(f64_I *a, f64_I *b, f64_I *c, f64_I *s);
void ATL_drotmg(f64_I *d1, f64_I *d2, f64_I *b1, f64_I b2, f64_I *P);
void ATL_drot(const int N, f64_I *X, const int incX, f64_I *Y, const int incY,
              f64_I c, f64_I s);
void ATL_drotm(const int N, f64_I *X, const int incX, f64_I *Y, const int incY,
               const f64_I *P);
f64_I ATL_ddot(const int N, const f64_I *X, const int incX, const f64_I *Y,
               const int incY);
void ATL_dssq(const int N, const f64_I *X, const int incX, f64_I *scal0,
              f64_I *ssq0);
f64_I ATL_dnrm2(const int N, const f64_I *X, const int incX);
f64_I ATL_dasum(const int N, const f64_I *X, const int incX);

/*
 * Routines with complex types
 */
void ATL_csrot(const int N, f32_I *X, const int incX, f32_I *Y, const int incY,
               f32_I c, f32_I s);
void ATL_crotg(f32_I *a, const f32_I *b, f32_I *c, f32_I *s);
void ATL_cdotu_sub(const int N, const f32_I *X, const int incX, const f32_I *Y,
                   const int incY, f32_I *dot);
void ATL_cdotc_sub(const int N, const f32_I *X, const int incX, const f32_I *Y,
                   const int incY, f32_I *dot);
void ATL_cssq(const int N, const f32_I *X, const int incX, f32_I *scal0,
              f32_I *ssq0);
f32_I ATL_scnrm2(const int N, const f32_I *X, const int incX);
f32_I ATL_scasum(const int N, const f32_I *X, const int incX);

void ATL_zdrot(const int N, f64_I *X, const int incX, f64_I *Y, const int incY,
               f64_I c, f64_I s);
void ATL_zrotg(f64_I *a, const f64_I *b, f64_I *c, f64_I *s);
void ATL_zdotu_sub(const int N, const f64_I *X, const int incX, const f64_I *Y,
                   const int incY, f64_I *dot);
void ATL_zdotc_sub(const int N, const f64_I *X, const int incX, const f64_I *Y,
                   const int incY, f64_I *dot);
void ATL_zssq(const int N, const f64_I *X, const int incX, f64_I *scal0,
              f64_I *ssq0);
f64_I ATL_dznrm2(const int N, const f64_I *X, const int incX);
f64_I ATL_dzasum(const int N, const f64_I *X, const int incX);
