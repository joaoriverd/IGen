#pragma once

#include "igen_immintrin.h"
#include "igen_dd_immintrin_types.h"
#include "igen_dd_lib.h"
#include "igen_dd_math.h"

static ddi_4 _igen_dd_op_mm256_add_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_add_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst;
}

static ddi_4 _igen_dd_op_mm256_mul_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_mul_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst;
}

static ddi_4 _igen_dd_op_mm256_fmadd_pd(ddi_4 a, ddi_4 b, ddi_4 c) {
    ddi_4 dst;
    ddi_4 t1 = _igen_dd_op_mm256_mul_pd(a, b);
    dst      = _igen_dd_op_mm256_add_pd(t1, c);
    return dst;
}

static ddi_4 _igen_dd_op_mm256_hadd_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;
    int j;
    int i;
    dst.f[0] = _ia_add_dd(a.f[1], a.f[0]);
    dst.f[1] = _ia_add_dd(b.f[1], b.f[0]);
    dst.f[2] = _ia_add_dd(a.f[3], a.f[2]);
    dst.f[3] = _ia_add_dd(b.f[3], b.f[2]);
    return dst;
}

static ddi_4 _igen_dd_op_mm256_div_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_div_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst;
}

static ddi_4 _igen_dd_op_mm256_sub_pd(ddi_4 a, ddi_4 b) {
    ddi_4 dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_sub_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst;
}

static ddi_4 _igen_dd_op_mm256_set_pd(dd_I e3, dd_I e2, dd_I e1, dd_I e0) {
    ddi_4 dst;

    dst.f[0] = e0;
    dst.f[1] = e1;
    dst.f[2] = e2;
    dst.f[3] = e3;

    return dst;
}

static ddi_4 _igen_dd_op_mm256_set1_pd(dd_I a) {
    ddi_4 dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = a;
    }

    return dst;
}

static ddi_4 _igen_dd_op_mm256_blend_pd(ddi_4 a, ddi_4 b, int imm8) {
    ddi_4 dst;
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

    return dst;
}

static ddi_4 _igen_dd_op_mm256_setzero_pd() {
    ddi_4 dst;
    dst.f[0] = _ia_set_pointed_dd(0.0,0.0);
    dst.f[1] = _ia_set_pointed_dd(0.0,0.0);
    dst.f[2] = _ia_set_pointed_dd(0.0,0.0);
    dst.f[3] = _ia_set_pointed_dd(0.0,0.0);
    return dst;
}

static ddi_4 _igen_dd_op_mm256_castpd128_pd256(ddi_2 a) {
    ddi_4 dst;
    dst.f[0] = a.f[0];
    dst.f[1] = a.f[1];
    return dst;
}

static ddi_2 _igen_dd_op_mm256_castpd256_pd128(ddi_4 a) {
    ddi_2 dst;
    dst.f[0] = a.f[0];
    dst.f[1] = a.f[1];
    return dst;
}

static ddi_4 _igen_dd_op_mm256_shuffle_pd(ddi_4 a, ddi_4 b, int imm8) {
    ddi_4 dst;
    dst.f[0] = (((imm8 >> 0) & 1) == 0) ? a.f[0] : a.f[1];
    dst.f[1] = (((imm8 >> 1) & 1) == 0) ? b.f[0] : b.f[1];
    dst.f[2] = (((imm8 >> 2) & 1) == 0) ? a.f[2] : a.f[3];
    dst.f[3] = (((imm8 >> 3) & 1) == 0) ? b.f[2] : b.f[3];
    return dst;
}

static ddi_4 _igen_dd_op_mm256_loadu_pd(const dd_I *mem_addr) {
    ddi_4 dst;
    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);
    return dst;
}

static ddi_4 _igen_dd_op_mm256_load_pd(const dd_I *mem_addr) {
    ddi_4 dst;
    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 1);
    dst.f[2] = *(mem_addr + 2);
    dst.f[3] = *(mem_addr + 3);
    return dst;
}

static void _igen_dd_op_mm256_storeu_pd(dd_I *mem_addr, ddi_4 a) {
    *(mem_addr + 0) = a.f[0];
    *(mem_addr + 1) = a.f[1];
    *(mem_addr + 2) = a.f[2];
    *(mem_addr + 3) = a.f[3];
}

static ddi_4 _igen_dd_op_mm256_broadcast_sd(const dd_I *mem_addr) {
    ddi_4 dst;
    dst.f[0] = *(mem_addr + 0);
    dst.f[1] = *(mem_addr + 0);
    dst.f[2] = *(mem_addr + 0);
    dst.f[3] = *(mem_addr + 0);
    return dst;
}