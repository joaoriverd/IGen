/*
 * rem_pio2, used in correctly rounded trigonometric functions
 *
 * Author : Catherine Daramy, David Defour, Florent de Dinechin
 *
 * This file contains code fragments from the crlibm library developed
 * by the Arenaire project at Ecole Normale Superieure de Lyon
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include <math.h>
#ifndef HAVE_INTTYPES_H
#define HAVE_INTTYPES_H  // This is required inside scs.h
#endif
#define SCS_NB_WORDS 8
#ifdef __cplusplus
extern "C" {
#endif
#include <scs.h>
#ifdef __cplusplus
}
#endif

#define DOUBLE_PRECISION 52
#define SINGLE_PRECISION 23
#define QUAD_PRECISION   112

#define INV_PIO2_UP 0.6366197723675813824328885
#define INV_PIO2_LO 0.6366197723675812714105860

#define PIO2_UP 1.5707963267948967800435867
#define PIO2_LO 1.5707963267948965579989818

#define PI_TIMES_2 6.28318530717958647692528
#define MAX_INT_QUADRANT  3373259424.0         /* floor(MAX_INT * PIO2) */
#define MAX_LONG_QUADRANT 14148475504056880.0  /* floor(2^53 * PIO2) */

static const int two_over_pi[]=
        {0x28be60db, 0x24e44152, 0x27f09d5f, 0x11f534dd,
         0x3036d8a5, 0x1993c439, 0x0107f945, 0x23abdebb,
         0x31586dc9, 0x06e3a424, 0x374b8019, 0x092eea09,
         0x3464873f, 0x21deb1cb, 0x04a69cfb, 0x288235f5,
         0x0baed121, 0x0e99c702, 0x1ad17df9, 0x013991d6,
         0x0e60d4ce, 0x1f49c845, 0x3e2ef7e4, 0x283b1ff8,
         0x25fff781, 0x1980fef2, 0x3c462d68, 0x0a6d1f6d,
         0x0d9fb3c9, 0x3cb09b74, 0x3d18fd9a, 0x1e5fea2d,
         0x1d49eeb1, 0x3ebe5f17, 0x2cf41ce7, 0x378a5292,
         0x3a9afed7, 0x3b11f8d5, 0x3421580c, 0x3046fc7b,
         0x1aeafc33, 0x3bc209af, 0x10d876a7, 0x2391615e,
         0x3986c219, 0x199855f1, 0x1281a102, 0x0dffd880};

/* Todo: properly add licence of code respective to this which was taken from scs */
static int rem_pio2_scs(const scs_ptr x){
    uint64_t r[SCS_NB_WORDS+3], tmp;
    unsigned int N;
    /* result r[0],...,r[10] could store till 300 bits of precision */
    int i, ind;
    int *two_over_pi_pt;

    if ((x->exception.d != 1)||(x->index < -1)){
        return 0;
    }

    /* Compute the product |x| * 2/Pi */
    if (x->index == -1){
        /* In this case we consider number between ]-1,+1[    */
        /* we may use simpler algorithm such as Cody And Waite */
        r[0] =  0;    r[1] =  0;
        r[2] =  (uint64_t)(two_over_pi[0]) * x->h_word[0];
        r[3] = ((uint64_t)(two_over_pi[0]) * x->h_word[1]
                +(uint64_t)(two_over_pi[1]) * x->h_word[0]);
        if(x->h_word[2] == 0){
            for(i=4; i<(SCS_NB_WORDS+3); i++){
                r[i] = ((uint64_t)(two_over_pi[i-3]) * x->h_word[1]
                        +(uint64_t)(two_over_pi[i-2]) * x->h_word[0]);
            }}else {
            for(i=4; i<(SCS_NB_WORDS+3); i++){
                r[i] = ((uint64_t)(two_over_pi[i-4]) * x->h_word[2]
                        +(uint64_t)(two_over_pi[i-3]) * x->h_word[1]
                        +(uint64_t)(two_over_pi[i-2]) * x->h_word[0]);
            }
        }
    }else {
        if (x->index == 0){
            r[0] =  0;
            r[1] =  (uint64_t)(two_over_pi[0]) * x->h_word[0];
            r[2] = ((uint64_t)(two_over_pi[0]) * x->h_word[1]
                    +(uint64_t)(two_over_pi[1]) * x->h_word[0]);
            if(x->h_word[2] == 0){
                for(i=3; i<(SCS_NB_WORDS+3); i++){
                    r[i] = ((uint64_t)(two_over_pi[i-2]) * x->h_word[1]
                            +(uint64_t)(two_over_pi[i-1]) * x->h_word[0]);
                }}else {
                for(i=3; i<(SCS_NB_WORDS+3); i++){
                    r[i] = ((uint64_t)(two_over_pi[i-3]) * x->h_word[2]
                            +(uint64_t)(two_over_pi[i-2]) * x->h_word[1]
                            +(uint64_t)(two_over_pi[i-1]) * x->h_word[0]);
                }}
        }else {
            if (x->index == 1){
                r[0] =  (uint64_t)(two_over_pi[0]) * x->h_word[0];
                r[1] = ((uint64_t)(two_over_pi[0]) * x->h_word[1]
                        +(uint64_t)(two_over_pi[1]) * x->h_word[0]);
                if(x->h_word[2] == 0){
                    for(i=2; i<(SCS_NB_WORDS+3); i++){
                        r[i] = ((uint64_t)(two_over_pi[i-1]) * x->h_word[1]
                                +(uint64_t)(two_over_pi[ i ]) * x->h_word[0]);
                    }}else {
                    for(i=2; i<(SCS_NB_WORDS+3); i++){
                        r[i] = ((uint64_t)(two_over_pi[i-2]) * x->h_word[2]
                                +(uint64_t)(two_over_pi[i-1]) * x->h_word[1]
                                +(uint64_t)(two_over_pi[ i ]) * x->h_word[0]);
                    }}
            }else {
                if (x->index == 2){
                    r[0] = ((uint64_t)(two_over_pi[0]) * x->h_word[1]
                            +(uint64_t)(two_over_pi[1]) * x->h_word[0]);
                    if(x->h_word[2] == 0){
                        for(i=1; i<(SCS_NB_WORDS+3); i++){
                            r[i] = ((uint64_t)(two_over_pi[ i ]) * x->h_word[1]
                                    +(uint64_t)(two_over_pi[i+1]) * x->h_word[0]);
                        }}else {
                        for(i=1; i<(SCS_NB_WORDS+3); i++){
                            r[i] = ((uint64_t)(two_over_pi[i-1]) * x->h_word[2]
                                    +(uint64_t)(two_over_pi[ i ]) * x->h_word[1]
                                    +(uint64_t)(two_over_pi[i+1]) * x->h_word[0]);
                        }}
                }else {
                    ind = (x->index - 3);
                    two_over_pi_pt = (int*)&(two_over_pi[ind]);
                    if(x->h_word[2] == 0){
                        for(i=0; i<(SCS_NB_WORDS+3); i++){
                            r[i] = ((uint64_t)(two_over_pi_pt[i+1]) * x->h_word[1]
                                    +(uint64_t)(two_over_pi_pt[i+2]) * x->h_word[0]);
                        }}else {
                        for(i=0; i<(SCS_NB_WORDS+3); i++){
                            r[i] = ((uint64_t)(two_over_pi_pt[ i ]) * x->h_word[2]
                                    +(uint64_t)(two_over_pi_pt[i+1]) * x->h_word[1]
                                    +(uint64_t)(two_over_pi_pt[i+2]) * x->h_word[0]);
                        }
                    }
                }
            }
        }
    }

    /* Carry propagate */
    r[SCS_NB_WORDS+1] += r[SCS_NB_WORDS+2]>>30;
    for(i=(SCS_NB_WORDS+1); i>0; i--) {tmp=r[i]>>30;   r[i-1] += tmp;  r[i] -= (tmp<<30);}

    /* The integer part is in r[0] */
    N = (unsigned int)(r[0]);

    return x->sign*N;
}

static unsigned int trig_quadrant (double x) {
    unsigned  int q;
    /* negate to simulate rounding mode towards -inf  */
    double neg_x = -fabs(x);
    if (x < MAX_INT_QUADRANT && x > -MAX_INT_QUADRANT) {
        /* x is small enough to be stored in an 32-bit integer */
        double _d1 = neg_x * INV_PIO2_LO;
        double _d2 = neg_x * INV_PIO2_UP;
        _d1 = -_d1;
        _d2 = -_d2;
        int k1 = (int)  _d1;
        int k2 = (int)  _d2;
        unsigned int q1 = x >= 0.0 ? k1&3 : (~k1)&3;
        unsigned int q2 = x >= 0.0 ? k2&3 : (~k2)&3;

        if (q1 == q2) {
            q = q1;
        }
        else {
            /* More precision needed, use multi precision SCS library */
            scs_t sc_x;
            scs_set_d(sc_x, x);
            int k = rem_pio2_scs(sc_x);
            q = k & 3;
        }
    }
    else if (x < MAX_LONG_QUADRANT && x > -MAX_LONG_QUADRANT) {
        /* x is small enough to be stored in an 64-bit integer */
        double _d1 = neg_x * INV_PIO2_LO;
        double _d2 = neg_x * INV_PIO2_UP;
        _d1 = -_d1;
        _d2 = -_d2;
        int64_t k1 = (int64_t)  _d1;
        int64_t k2 = (int64_t)  _d2;
        unsigned int q1 = _d1 >= 0.0 ? k1&3 : (~k1)&3;
        unsigned int q2 = _d2 >= 0.0 ? k2&3 : (~k2)&3;

        if (q1 == q2) {
            q = q1;
        }
        else {
            /* More precision needed, use multi precision SCS library */
            scs_t sc_x;
            scs_set_d(sc_x, x);
            int k = rem_pio2_scs(sc_x);
            q = k & 3;
        }
    }
    else {
        /* Worst case : x very large, use multi precision SCS library */
        scs_t sc_x;
        scs_set_d(sc_x, x);
        int k = rem_pio2_scs(sc_x);
        q = k & 3;
    }

    return q;
}