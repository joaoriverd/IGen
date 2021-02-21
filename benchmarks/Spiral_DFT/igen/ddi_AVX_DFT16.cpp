#include "igen_dd_immintrin.h"
#include "igen_dd_lib.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
void init_AVX_DFT16(dd_I a) {}

void AVX_DFT16(dd_I *Y, dd_I *X) {
  ddi_4 s211;
  ddi_4 s212;
  ddi_4 s213;
  ddi_4 s214;
  ddi_4 s215;
  ddi_4 s216;
  ddi_4 s217;
  ddi_4 s218;
  ddi_4 s219;
  ddi_4 s220;
  ddi_4 s221;
  ddi_4 s222;
  ddi_4 s223;
  ddi_4 s224;
  ddi_4 s225;
  ddi_4 s226;
  ddi_4 s227;
  ddi_4 s228;
  ddi_4 s229;
  ddi_4 s230;
  ddi_4 s231;
  ddi_4 s232;
  ddi_4 s233;
  ddi_4 s234;
  ddi_4 s235;
  ddi_4 s236;
  ddi_4 s237;
  ddi_4 s238;
  ddi_4 s239;
  ddi_4 s240;
  ddi_4 s241;
  ddi_4 s242;
  ddi_4 s243;
  ddi_4 s244;
  ddi_4 s245;
  ddi_4 s246;
  ddi_4 s247;
  ddi_4 s248;
  ddi_4 s249;
  ddi_4 s250;
  ddi_4 s251;
  ddi_4 s252;
  ddi_4 s253;
  ddi_4 s254;
  ddi_4 s255;
  ddi_4 s256;
  ddi_4 s257;
  ddi_4 s258;
  ddi_4 s259;
  ddi_4 s260;
  ddi_4 s261;
  ddi_4 s262;
  ddi_4 s263;
  ddi_4 s264;
  ddi_4 s265;
  ddi_4 s266;
  ddi_4 s267;
  ddi_4 s268;
  ddi_4 s269;
  ddi_4 s270;
  ddi_4 s271;
  ddi_4 s272;
  ddi_4 s273;
  ddi_4 s274;
  ddi_4 s275;
  ddi_4 s276;
  ddi_4 s277;
  ddi_4 s278;
  ddi_4 s279;
  ddi_4 s280;
  ddi_4 t129;
  ddi_4 t130;
  ddi_4 t131;
  ddi_4 t132;
  ddi_4 t133;
  ddi_4 t134;
  ddi_4 t135;
  ddi_4 t136;
  ddi_4 t137;
  ddi_4 t138;
  ddi_4 t139;
  ddi_4 t140;
  ddi_4 t141;
  ddi_4 t142;
  ddi_4 t143;
  ddi_4 t144;
  ddi_4 t145;
  ddi_4 t146;
  ddi_4 t147;
  ddi_4 t148;
  ddi_4 t149;
  ddi_4 t150;
  ddi_4 t151;
  ddi_4 t152;
  ddi_4 t153;
  ddi_4 t154;
  ddi_4 t155;
  ddi_4 t156;
  ddi_4 t157;
  ddi_4 t158;
  ddi_4 t159;
  ddi_4 t160;
  ddi_4 *a45;
  ddi_4 *a46;
  a45 = ((ddi_4 *)X);
  s211 = *(a45);
  s212 = *((a45 + 1));
  s213 = _igen_dd_mm256_permute2f128_pd(s211, s212, (0) | ((2) << 4));
  s214 = _igen_dd_mm256_permute2f128_pd(s211, s212, (1) | ((3) << 4));
  s215 = _igen_dd_mm256_unpacklo_pd(s213, s214);
  s216 = _igen_dd_mm256_unpackhi_pd(s213, s214);
  s217 = *((a45 + 4));
  s218 = *((a45 + 5));
  s219 = _igen_dd_mm256_permute2f128_pd(s217, s218, (0) | ((2) << 4));
  s220 = _igen_dd_mm256_permute2f128_pd(s217, s218, (1) | ((3) << 4));
  s221 = _igen_dd_mm256_unpacklo_pd(s219, s220);
  s222 = _igen_dd_mm256_unpackhi_pd(s219, s220);
  t129 = _igen_dd_mm256_add_pd(s215, s221);
  t130 = _igen_dd_mm256_add_pd(s216, s222);
  t131 = _igen_dd_mm256_sub_pd(s215, s221);
  t132 = _igen_dd_mm256_sub_pd(s216, s222);
  s223 = *((a45 + 2));
  s224 = *((a45 + 3));
  s225 = _igen_dd_mm256_permute2f128_pd(s223, s224, (0) | ((2) << 4));
  s226 = _igen_dd_mm256_permute2f128_pd(s223, s224, (1) | ((3) << 4));
  s227 = _igen_dd_mm256_unpacklo_pd(s225, s226);
  s228 = _igen_dd_mm256_unpackhi_pd(s225, s226);
  s229 = *((a45 + 6));
  s230 = *((a45 + 7));
  s231 = _igen_dd_mm256_permute2f128_pd(s229, s230, (0) | ((2) << 4));
  s232 = _igen_dd_mm256_permute2f128_pd(s229, s230, (1) | ((3) << 4));
  s233 = _igen_dd_mm256_unpacklo_pd(s231, s232);
  s234 = _igen_dd_mm256_unpackhi_pd(s231, s232);
  t133 = _igen_dd_mm256_add_pd(s227, s233);
  t134 = _igen_dd_mm256_add_pd(s228, s234);
  t135 = _igen_dd_mm256_sub_pd(s227, s233);
  t136 = _igen_dd_mm256_sub_pd(s228, s234);
  t137 = _igen_dd_mm256_add_pd(t129, t133);
  t138 = _igen_dd_mm256_add_pd(t130, t134);
  t139 = _igen_dd_mm256_sub_pd(t129, t133);
  t140 = _igen_dd_mm256_sub_pd(t130, t134);
  t141 = _igen_dd_mm256_sub_pd(t131, t136);
  t142 = _igen_dd_mm256_add_pd(t132, t135);
  t143 = _igen_dd_mm256_add_pd(t131, t136);
  t144 = _igen_dd_mm256_sub_pd(t132, t135);
  s235 = _igen_dd_mm256_unpacklo_pd(t137, t141);
  s236 = _igen_dd_mm256_unpackhi_pd(t137, t141);
  s237 = _igen_dd_mm256_unpacklo_pd(t138, t142);
  s238 = _igen_dd_mm256_unpackhi_pd(t138, t142);
  s239 = _igen_dd_mm256_permute2f128_pd(s235, s236, (0) | ((2) << 4));
  s240 = _igen_dd_mm256_permute2f128_pd(s235, s236, (1) | ((3) << 4));
  s241 = _igen_dd_mm256_permute2f128_pd(s237, s238, (0) | ((2) << 4));
  s242 = _igen_dd_mm256_permute2f128_pd(s237, s238, (1) | ((3) << 4));
  s243 = _igen_dd_mm256_unpacklo_pd(t139, t143);
  s244 = _igen_dd_mm256_unpackhi_pd(t139, t143);
  s245 = _igen_dd_mm256_unpacklo_pd(t140, t144);
  s246 = _igen_dd_mm256_unpackhi_pd(t140, t144);
  s247 = _igen_dd_mm256_permute2f128_pd(s243, s244, (0) | ((2) << 4));
  s248 = _igen_dd_mm256_permute2f128_pd(s243, s244, (1) | ((3) << 4));
  s249 = _igen_dd_mm256_permute2f128_pd(s245, s246, (0) | ((2) << 4));
  s250 = _igen_dd_mm256_permute2f128_pd(s245, s246, (1) | ((3) << 4));
  s251 = _igen_dd_mm256_permute2f128_pd(s239, s247, (0) | ((2) << 4));
  s252 = _igen_dd_mm256_permute2f128_pd(s239, s247, (1) | ((3) << 4));
  s253 = _igen_dd_mm256_permute2f128_pd(s240, s248, (0) | ((2) << 4));
  s254 = _igen_dd_mm256_permute2f128_pd(s240, s248, (1) | ((3) << 4));
  s255 = _igen_dd_mm256_permute2f128_pd(s241, s249, (0) | ((2) << 4));
  s256 = _igen_dd_mm256_permute2f128_pd(s241, s249, (1) | ((3) << 4));
  s257 = _igen_dd_mm256_permute2f128_pd(s242, s250, (0) | ((2) << 4));
  s258 = _igen_dd_mm256_permute2f128_pd(s242, s250, (1) | ((3) << 4));
  dd_I _t1 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                        0.70710678118654757, -2.737310929369414e-18);
  dd_I _t2 = _ia_neg_dd(_t1);
  dd_I _t3 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  dd_I _t4 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                        0.70710678118654757, -2.737310929369414e-18);
  dd_I _t5 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t6 = _igen_dd_mm256_set_pd(_t2, _t3, _t4, _t5);
  dd_I _t7 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                        0.70710678118654757, -2.737310929369414e-18);
  dd_I _t8 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  dd_I _t9 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                        0.70710678118654757, -2.737310929369414e-18);
  dd_I _t10 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t11 = _igen_dd_mm256_set_pd(_t7, _t8, _t9, _t10);
  ddi_4 _t12 = _igen_dd_mm256_mul_pd(_t6, s253);
  ddi_4 _t13 = _igen_dd_mm256_mul_pd(_t11, s257);
  s259 = _igen_dd_mm256_sub_pd(_t12, _t13);
  dd_I _t14 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t15 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  dd_I _t16 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t17 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t18 = _igen_dd_mm256_set_pd(_t14, _t15, _t16, _t17);
  dd_I _t19 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t20 = _ia_neg_dd(_t19);
  dd_I _t21 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  dd_I _t22 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t23 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t24 = _igen_dd_mm256_set_pd(_t20, _t21, _t22, _t23);
  ddi_4 _t25 = _igen_dd_mm256_mul_pd(_t18, s253);
  ddi_4 _t26 = _igen_dd_mm256_mul_pd(_t24, s257);
  s260 = _igen_dd_mm256_add_pd(_t25, _t26);
  t145 = _igen_dd_mm256_add_pd(s251, s259);
  t146 = _igen_dd_mm256_add_pd(s255, s260);
  t147 = _igen_dd_mm256_sub_pd(s251, s259);
  t148 = _igen_dd_mm256_sub_pd(s255, s260);
  dd_I _t27 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t28 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t29 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t30 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t31 = _igen_dd_mm256_set_pd(_t27, _t28, _t29, _t30);
  dd_I _t32 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t33 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t34 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t35 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t36 = _igen_dd_mm256_set_pd(_t32, _t33, _t34, _t35);
  ddi_4 _t37 = _igen_dd_mm256_mul_pd(_t31, s252);
  ddi_4 _t38 = _igen_dd_mm256_mul_pd(_t36, s256);
  s261 = _igen_dd_mm256_sub_pd(_t37, _t38);
  dd_I _t39 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t40 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t41 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t42 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t43 = _igen_dd_mm256_set_pd(_t39, _t40, _t41, _t42);
  dd_I _t44 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t45 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t46 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t47 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t48 = _igen_dd_mm256_set_pd(_t44, _t45, _t46, _t47);
  ddi_4 _t49 = _igen_dd_mm256_mul_pd(_t43, s252);
  ddi_4 _t50 = _igen_dd_mm256_mul_pd(_t48, s256);
  s262 = _igen_dd_mm256_add_pd(_t49, _t50);
  dd_I _t51 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t52 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t53 = _ia_neg_dd(_t51);
  dd_I _t54 = _ia_neg_dd(_t52);
  dd_I _t55 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t56 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t57 = _igen_dd_mm256_set_pd(_t53, _t54, _t55, _t56);
  dd_I _t58 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t59 = _ia_neg_dd(_t58);
  dd_I _t60 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t61 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t62 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t63 = _igen_dd_mm256_set_pd(_t59, _t60, _t61, _t62);
  ddi_4 _t64 = _igen_dd_mm256_mul_pd(_t57, s254);
  ddi_4 _t65 = _igen_dd_mm256_mul_pd(_t63, s258);
  s263 = _igen_dd_mm256_sub_pd(_t64, _t65);
  dd_I _t66 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t67 = _ia_neg_dd(_t66);
  dd_I _t68 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t69 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t70 = _ia_set_dd(-0.0, 0.0, 0.0, 0.0);
  ddi_4 _t71 = _igen_dd_mm256_set_pd(_t67, _t68, _t69, _t70);
  dd_I _t72 = _ia_set_dd(-0.92387953251128674, -1.5168638949398881e-18,
                         0.92387953251128674, 1.5168638949398883e-18);
  dd_I _t73 = _ia_set_dd(-0.70710678118654757, 2.7373109293694144e-18,
                         0.70710678118654757, -2.737310929369414e-18);
  dd_I _t74 = _ia_neg_dd(_t72);
  dd_I _t75 = _ia_neg_dd(_t73);
  dd_I _t76 = _ia_set_dd(-0.38268343236508978, 1.7792326804919868e-18,
                         0.38268343236508978, -1.7792326804919865e-18);
  dd_I _t77 = _ia_set_dd(-1.0, 0.0, 1.0, 0.0);
  ddi_4 _t78 = _igen_dd_mm256_set_pd(_t74, _t75, _t76, _t77);
  ddi_4 _t79 = _igen_dd_mm256_mul_pd(_t71, s254);
  ddi_4 _t80 = _igen_dd_mm256_mul_pd(_t78, s258);
  s264 = _igen_dd_mm256_add_pd(_t79, _t80);
  t149 = _igen_dd_mm256_add_pd(s261, s263);
  t150 = _igen_dd_mm256_add_pd(s262, s264);
  t151 = _igen_dd_mm256_sub_pd(s261, s263);
  t152 = _igen_dd_mm256_sub_pd(s262, s264);
  t153 = _igen_dd_mm256_add_pd(t145, t149);
  t154 = _igen_dd_mm256_add_pd(t146, t150);
  t155 = _igen_dd_mm256_sub_pd(t145, t149);
  t156 = _igen_dd_mm256_sub_pd(t146, t150);
  s265 = _igen_dd_mm256_unpacklo_pd(t153, t154);
  s266 = _igen_dd_mm256_unpackhi_pd(t153, t154);
  a46 = ((ddi_4 *)Y);
  s267 = _igen_dd_mm256_permute2f128_pd(s265, s266, (0) | ((2) << 4));
  *(a46) = s267;
  s268 = _igen_dd_mm256_permute2f128_pd(s265, s266, (1) | ((3) << 4));
  *((a46 + 1)) = s268;
  s269 = _igen_dd_mm256_unpacklo_pd(t155, t156);
  s270 = _igen_dd_mm256_unpackhi_pd(t155, t156);
  s271 = _igen_dd_mm256_permute2f128_pd(s269, s270, (0) | ((2) << 4));
  *((a46 + 4)) = s271;
  s272 = _igen_dd_mm256_permute2f128_pd(s269, s270, (1) | ((3) << 4));
  *((a46 + 5)) = s272;
  t157 = _igen_dd_mm256_sub_pd(t147, t152);
  t158 = _igen_dd_mm256_add_pd(t148, t151);
  t159 = _igen_dd_mm256_add_pd(t147, t152);
  t160 = _igen_dd_mm256_sub_pd(t148, t151);
  s273 = _igen_dd_mm256_unpacklo_pd(t157, t158);
  s274 = _igen_dd_mm256_unpackhi_pd(t157, t158);
  s275 = _igen_dd_mm256_permute2f128_pd(s273, s274, (0) | ((2) << 4));
  *((a46 + 2)) = s275;
  s276 = _igen_dd_mm256_permute2f128_pd(s273, s274, (1) | ((3) << 4));
  *((a46 + 3)) = s276;
  s277 = _igen_dd_mm256_unpacklo_pd(t159, t160);
  s278 = _igen_dd_mm256_unpackhi_pd(t159, t160);
  s279 = _igen_dd_mm256_permute2f128_pd(s277, s278, (0) | ((2) << 4));
  *((a46 + 6)) = s279;
  s280 = _igen_dd_mm256_permute2f128_pd(s277, s278, (1) | ((3) << 4));
  *((a46 + 7)) = s280;
}
