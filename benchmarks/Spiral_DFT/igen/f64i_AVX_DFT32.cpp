#include "igen_immintrin.h"
#include "igen_lib.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
void init_AVX_DFT32(f64_I a) {}

void AVX_DFT32(f64_I *Y, f64_I *X) {
  m256di_2 a98;
  m256di_2 a99;
  m256di_2 s434;
  m256di_2 s435;
  m256di_2 s436;
  m256di_2 s437;
  m256di_2 s438;
  m256di_2 s439;
  m256di_2 s440;
  m256di_2 s441;
  m256di_2 s442;
  m256di_2 s443;
  m256di_2 s444;
  m256di_2 s445;
  m256di_2 s446;
  m256di_2 s447;
  m256di_2 s448;
  m256di_2 s449;
  m256di_2 s450;
  m256di_2 s451;
  m256di_2 s452;
  m256di_2 s453;
  m256di_2 s454;
  m256di_2 s455;
  m256di_2 s456;
  m256di_2 s457;
  m256di_2 s458;
  m256di_2 s459;
  m256di_2 s460;
  m256di_2 s461;
  m256di_2 s462;
  m256di_2 s463;
  m256di_2 s464;
  m256di_2 s465;
  m256di_2 s466;
  m256di_2 s467;
  m256di_2 s468;
  m256di_2 s469;
  m256di_2 s470;
  m256di_2 s471;
  m256di_2 s472;
  m256di_2 s473;
  m256di_2 s474;
  m256di_2 s475;
  m256di_2 s476;
  m256di_2 s477;
  m256di_2 s478;
  m256di_2 s479;
  m256di_2 s480;
  m256di_2 s481;
  m256di_2 s482;
  m256di_2 s483;
  m256di_2 s484;
  m256di_2 s485;
  m256di_2 s486;
  m256di_2 s487;
  m256di_2 s488;
  m256di_2 s489;
  m256di_2 s490;
  m256di_2 s491;
  m256di_2 s492;
  m256di_2 s493;
  m256di_2 s494;
  m256di_2 s495;
  m256di_2 s496;
  m256di_2 s497;
  m256di_2 s498;
  m256di_2 s499;
  m256di_2 s500;
  m256di_2 s501;
  m256di_2 s502;
  m256di_2 s503;
  m256di_2 s504;
  m256di_2 s505;
  m256di_2 s506;
  m256di_2 s507;
  m256di_2 s508;
  m256di_2 s509;
  m256di_2 s510;
  m256di_2 s511;
  m256di_2 s512;
  m256di_2 s513;
  m256di_2 s514;
  m256di_2 s515;
  m256di_2 s516;
  m256di_2 s517;
  m256di_2 s518;
  m256di_2 s519;
  m256di_2 s520;
  m256di_2 s521;
  m256di_2 s522;
  m256di_2 s523;
  m256di_2 s524;
  m256di_2 s525;
  m256di_2 s526;
  m256di_2 s527;
  m256di_2 s528;
  m256di_2 s529;
  m256di_2 s530;
  m256di_2 s531;
  m256di_2 s532;
  m256di_2 s533;
  m256di_2 s534;
  m256di_2 s535;
  m256di_2 s536;
  m256di_2 s537;
  m256di_2 s538;
  m256di_2 s539;
  m256di_2 s540;
  m256di_2 s541;
  m256di_2 s542;
  m256di_2 s543;
  m256di_2 s544;
  m256di_2 s545;
  m256di_2 s546;
  m256di_2 s547;
  m256di_2 s548;
  m256di_2 s549;
  m256di_2 s550;
  m256di_2 s551;
  m256di_2 s552;
  m256di_2 s553;
  m256di_2 s554;
  m256di_2 s555;
  m256di_2 s556;
  m256di_2 s557;
  m256di_2 s558;
  m256di_2 s559;
  m256di_2 s560;
  m256di_2 s561;
  m256di_2 s562;
  m256di_2 s563;
  m256di_2 s564;
  m256di_2 s565;
  m256di_2 s566;
  m256di_2 s567;
  m256di_2 s568;
  m256di_2 s569;
  m256di_2 s570;
  m256di_2 s571;
  m256di_2 s572;
  m256di_2 s573;
  m256di_2 s574;
  m256di_2 s575;
  m256di_2 s576;
  m256di_2 s577;
  m256di_2 t279;
  m256di_2 t280;
  m256di_2 t281;
  m256di_2 t282;
  m256di_2 t283;
  m256di_2 t284;
  m256di_2 t285;
  m256di_2 t286;
  m256di_2 t287;
  m256di_2 t288;
  m256di_2 t289;
  m256di_2 t290;
  m256di_2 t291;
  m256di_2 t292;
  m256di_2 t293;
  m256di_2 t294;
  m256di_2 t295;
  m256di_2 t296;
  m256di_2 t297;
  m256di_2 t298;
  m256di_2 t299;
  m256di_2 t300;
  m256di_2 t301;
  m256di_2 t302;
  m256di_2 t303;
  m256di_2 t304;
  m256di_2 t305;
  m256di_2 t306;
  m256di_2 t307;
  m256di_2 t308;
  m256di_2 t309;
  m256di_2 t310;
  m256di_2 t311;
  m256di_2 t312;
  m256di_2 t313;
  m256di_2 t314;
  m256di_2 t315;
  m256di_2 t316;
  m256di_2 t317;
  m256di_2 t318;
  m256di_2 t319;
  m256di_2 t320;
  m256di_2 t321;
  m256di_2 t322;
  m256di_2 t323;
  m256di_2 t324;
  m256di_2 t325;
  m256di_2 t326;
  m256di_2 t327;
  m256di_2 t328;
  m256di_2 t329;
  m256di_2 t330;
  m256di_2 t331;
  m256di_2 t332;
  m256di_2 t333;
  m256di_2 t334;
  m256di_2 t335;
  m256di_2 t336;
  m256di_2 t337;
  m256di_2 t338;
  m256di_2 t339;
  m256di_2 t340;
  m256di_2 t341;
  m256di_2 t342;
  m256di_2 t343;
  m256di_2 t344;
  m256di_2 t345;
  m256di_2 t346;
  m256di_2 t347;
  m256di_2 t348;
  m256di_2 t349;
  m256di_2 t350;
  m256di_2 t351;
  m256di_2 t352;
  m256di_2 t353;
  m256di_2 t354;
  m256di_2 t355;
  m256di_2 t356;
  m256di_2 *a100;
  m256di_2 *a97;
  a97 = ((m256di_2 *)X);
  s434 = *(a97);
  s435 = *((a97 + 1));
  s436 = _igen_mm256_permute2f128_pd(s434, s435, (0) | ((2) << 4));
  s437 = _igen_mm256_permute2f128_pd(s434, s435, (1) | ((3) << 4));
  s438 = _igen_mm256_unpacklo_pd(s436, s437);
  s439 = _igen_mm256_unpackhi_pd(s436, s437);
  s440 = *((a97 + 8));
  s441 = *((a97 + 9));
  s442 = _igen_mm256_permute2f128_pd(s440, s441, (0) | ((2) << 4));
  s443 = _igen_mm256_permute2f128_pd(s440, s441, (1) | ((3) << 4));
  s444 = _igen_mm256_unpacklo_pd(s442, s443);
  s445 = _igen_mm256_unpackhi_pd(s442, s443);
  t279 = _igen_mm256_add_pd(s438, s444);
  t280 = _igen_mm256_add_pd(s439, s445);
  t281 = _igen_mm256_sub_pd(s438, s444);
  t282 = _igen_mm256_sub_pd(s439, s445);
  s446 = *((a97 + 2));
  s447 = *((a97 + 3));
  s448 = _igen_mm256_permute2f128_pd(s446, s447, (0) | ((2) << 4));
  s449 = _igen_mm256_permute2f128_pd(s446, s447, (1) | ((3) << 4));
  s450 = _igen_mm256_unpacklo_pd(s448, s449);
  s451 = _igen_mm256_unpackhi_pd(s448, s449);
  s452 = *((a97 + 10));
  s453 = *((a97 + 11));
  s454 = _igen_mm256_permute2f128_pd(s452, s453, (0) | ((2) << 4));
  s455 = _igen_mm256_permute2f128_pd(s452, s453, (1) | ((3) << 4));
  s456 = _igen_mm256_unpacklo_pd(s454, s455);
  s457 = _igen_mm256_unpackhi_pd(s454, s455);
  t283 = _igen_mm256_add_pd(s450, s456);
  t284 = _igen_mm256_add_pd(s451, s457);
  t285 = _igen_mm256_sub_pd(s450, s456);
  t286 = _igen_mm256_sub_pd(s451, s457);
  f64_I _t1 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  m256di_2 _t2 = _igen_mm256_set1_pd(_t1);
  m256di_2 _t3 = _igen_mm256_sub_pd(t285, t286);
  s458 = _igen_mm256_mul_pd(_t2, _t3);
  f64_I _t4 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  m256di_2 _t5 = _igen_mm256_set1_pd(_t4);
  m256di_2 _t6 = _igen_mm256_add_pd(t285, t286);
  s459 = _igen_mm256_mul_pd(_t5, _t6);
  s460 = *((a97 + 4));
  s461 = *((a97 + 5));
  s462 = _igen_mm256_permute2f128_pd(s460, s461, (0) | ((2) << 4));
  s463 = _igen_mm256_permute2f128_pd(s460, s461, (1) | ((3) << 4));
  s464 = _igen_mm256_unpacklo_pd(s462, s463);
  s465 = _igen_mm256_unpackhi_pd(s462, s463);
  s466 = *((a97 + 12));
  s467 = *((a97 + 13));
  s468 = _igen_mm256_permute2f128_pd(s466, s467, (0) | ((2) << 4));
  s469 = _igen_mm256_permute2f128_pd(s466, s467, (1) | ((3) << 4));
  s470 = _igen_mm256_unpacklo_pd(s468, s469);
  s471 = _igen_mm256_unpackhi_pd(s468, s469);
  t287 = _igen_mm256_add_pd(s464, s470);
  t288 = _igen_mm256_add_pd(s465, s471);
  t289 = _igen_mm256_sub_pd(s464, s470);
  t290 = _igen_mm256_sub_pd(s465, s471);
  s472 = *((a97 + 6));
  s473 = *((a97 + 7));
  s474 = _igen_mm256_permute2f128_pd(s472, s473, (0) | ((2) << 4));
  s475 = _igen_mm256_permute2f128_pd(s472, s473, (1) | ((3) << 4));
  s476 = _igen_mm256_unpacklo_pd(s474, s475);
  s477 = _igen_mm256_unpackhi_pd(s474, s475);
  s478 = *((a97 + 14));
  s479 = *((a97 + 15));
  s480 = _igen_mm256_permute2f128_pd(s478, s479, (0) | ((2) << 4));
  s481 = _igen_mm256_permute2f128_pd(s478, s479, (1) | ((3) << 4));
  s482 = _igen_mm256_unpacklo_pd(s480, s481);
  s483 = _igen_mm256_unpackhi_pd(s480, s481);
  t291 = _igen_mm256_add_pd(s476, s482);
  t292 = _igen_mm256_add_pd(s477, s483);
  f64_I _t7 = _ia_set_f64((0.70710678118654768), (-0.70710678118654746));
  m256di_2 _t8 = _igen_mm256_set1_pd(_t7);
  m256di_2 _t9 = _igen_mm256_sub_pd(s476, s482);
  a98 = _igen_mm256_mul_pd(_t8, _t9);
  f64_I _t10 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  m256di_2 _t11 = _igen_mm256_set1_pd(_t10);
  m256di_2 _t12 = _igen_mm256_sub_pd(s477, s483);
  a99 = _igen_mm256_mul_pd(_t11, _t12);
  s484 = _igen_mm256_sub_pd(a98, a99);
  s485 = _igen_mm256_add_pd(a98, a99);
  t293 = _igen_mm256_add_pd(t279, t287);
  t294 = _igen_mm256_add_pd(t280, t288);
  t295 = _igen_mm256_sub_pd(t279, t287);
  t296 = _igen_mm256_sub_pd(t280, t288);
  t297 = _igen_mm256_add_pd(t283, t291);
  t298 = _igen_mm256_add_pd(t284, t292);
  t299 = _igen_mm256_sub_pd(t283, t291);
  t300 = _igen_mm256_sub_pd(t284, t292);
  t301 = _igen_mm256_add_pd(t293, t297);
  t302 = _igen_mm256_add_pd(t294, t298);
  t303 = _igen_mm256_sub_pd(t293, t297);
  t304 = _igen_mm256_sub_pd(t294, t298);
  t305 = _igen_mm256_sub_pd(t295, t300);
  t306 = _igen_mm256_add_pd(t296, t299);
  t307 = _igen_mm256_add_pd(t295, t300);
  t308 = _igen_mm256_sub_pd(t296, t299);
  t309 = _igen_mm256_sub_pd(t281, t290);
  t310 = _igen_mm256_add_pd(t282, t289);
  t311 = _igen_mm256_add_pd(t281, t290);
  t312 = _igen_mm256_sub_pd(t282, t289);
  t313 = _igen_mm256_add_pd(s458, s484);
  t314 = _igen_mm256_sub_pd(s459, s485);
  t315 = _igen_mm256_sub_pd(s458, s484);
  t316 = _igen_mm256_add_pd(s459, s485);
  t317 = _igen_mm256_add_pd(t309, t313);
  t318 = _igen_mm256_add_pd(t310, t314);
  t319 = _igen_mm256_sub_pd(t309, t313);
  t320 = _igen_mm256_sub_pd(t310, t314);
  t321 = _igen_mm256_sub_pd(t311, t316);
  t322 = _igen_mm256_add_pd(t312, t315);
  t323 = _igen_mm256_add_pd(t311, t316);
  t324 = _igen_mm256_sub_pd(t312, t315);
  s486 = _igen_mm256_unpacklo_pd(t301, t317);
  s487 = _igen_mm256_unpackhi_pd(t301, t317);
  s488 = _igen_mm256_unpacklo_pd(t302, t318);
  s489 = _igen_mm256_unpackhi_pd(t302, t318);
  s490 = _igen_mm256_permute2f128_pd(s486, s487, (0) | ((2) << 4));
  s491 = _igen_mm256_permute2f128_pd(s486, s487, (1) | ((3) << 4));
  s492 = _igen_mm256_permute2f128_pd(s488, s489, (0) | ((2) << 4));
  s493 = _igen_mm256_permute2f128_pd(s488, s489, (1) | ((3) << 4));
  s494 = _igen_mm256_unpacklo_pd(t305, t321);
  s495 = _igen_mm256_unpackhi_pd(t305, t321);
  s496 = _igen_mm256_unpacklo_pd(t306, t322);
  s497 = _igen_mm256_unpackhi_pd(t306, t322);
  s498 = _igen_mm256_permute2f128_pd(s494, s495, (0) | ((2) << 4));
  s499 = _igen_mm256_permute2f128_pd(s494, s495, (1) | ((3) << 4));
  s500 = _igen_mm256_permute2f128_pd(s496, s497, (0) | ((2) << 4));
  s501 = _igen_mm256_permute2f128_pd(s496, s497, (1) | ((3) << 4));
  s502 = _igen_mm256_permute2f128_pd(s490, s498, (0) | ((2) << 4));
  s503 = _igen_mm256_permute2f128_pd(s490, s498, (1) | ((3) << 4));
  s504 = _igen_mm256_permute2f128_pd(s491, s499, (0) | ((2) << 4));
  s505 = _igen_mm256_permute2f128_pd(s491, s499, (1) | ((3) << 4));
  s506 = _igen_mm256_permute2f128_pd(s492, s500, (0) | ((2) << 4));
  s507 = _igen_mm256_permute2f128_pd(s492, s500, (1) | ((3) << 4));
  s508 = _igen_mm256_permute2f128_pd(s493, s501, (0) | ((2) << 4));
  s509 = _igen_mm256_permute2f128_pd(s493, s501, (1) | ((3) << 4));
  s510 = _igen_mm256_unpacklo_pd(t303, t319);
  s511 = _igen_mm256_unpackhi_pd(t303, t319);
  s512 = _igen_mm256_unpacklo_pd(t304, t320);
  s513 = _igen_mm256_unpackhi_pd(t304, t320);
  s514 = _igen_mm256_permute2f128_pd(s510, s511, (0) | ((2) << 4));
  s515 = _igen_mm256_permute2f128_pd(s510, s511, (1) | ((3) << 4));
  s516 = _igen_mm256_permute2f128_pd(s512, s513, (0) | ((2) << 4));
  s517 = _igen_mm256_permute2f128_pd(s512, s513, (1) | ((3) << 4));
  s518 = _igen_mm256_unpacklo_pd(t307, t323);
  s519 = _igen_mm256_unpackhi_pd(t307, t323);
  s520 = _igen_mm256_unpacklo_pd(t308, t324);
  s521 = _igen_mm256_unpackhi_pd(t308, t324);
  s522 = _igen_mm256_permute2f128_pd(s518, s519, (0) | ((2) << 4));
  s523 = _igen_mm256_permute2f128_pd(s518, s519, (1) | ((3) << 4));
  s524 = _igen_mm256_permute2f128_pd(s520, s521, (0) | ((2) << 4));
  s525 = _igen_mm256_permute2f128_pd(s520, s521, (1) | ((3) << 4));
  s526 = _igen_mm256_permute2f128_pd(s514, s522, (0) | ((2) << 4));
  s527 = _igen_mm256_permute2f128_pd(s514, s522, (1) | ((3) << 4));
  s528 = _igen_mm256_permute2f128_pd(s515, s523, (0) | ((2) << 4));
  s529 = _igen_mm256_permute2f128_pd(s515, s523, (1) | ((3) << 4));
  s530 = _igen_mm256_permute2f128_pd(s516, s524, (0) | ((2) << 4));
  s531 = _igen_mm256_permute2f128_pd(s516, s524, (1) | ((3) << 4));
  s532 = _igen_mm256_permute2f128_pd(s517, s525, (0) | ((2) << 4));
  s533 = _igen_mm256_permute2f128_pd(s517, s525, (1) | ((3) << 4));
  f64_I _t13 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t14 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  f64_I _t15 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t16 = _ia_set_f64(-1.0, 1.0);
  m256di_2 _t17 = _igen_mm256_set_pd(_t13, _t14, _t15, _t16);
  f64_I _t18 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t19 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  f64_I _t20 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t21 = _ia_set_f64(-0.0, 0.0);
  m256di_2 _t22 = _igen_mm256_set_pd(_t18, _t19, _t20, _t21);
  m256di_2 _t23 = _igen_mm256_mul_pd(_t17, s504);
  m256di_2 _t24 = _igen_mm256_mul_pd(_t22, s508);
  s534 = _igen_mm256_sub_pd(_t23, _t24);
  f64_I _t25 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t26 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  f64_I _t27 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t28 = _ia_set_f64(-0.0, 0.0);
  m256di_2 _t29 = _igen_mm256_set_pd(_t25, _t26, _t27, _t28);
  f64_I _t30 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t31 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  f64_I _t32 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t33 = _ia_set_f64(-1.0, 1.0);
  m256di_2 _t34 = _igen_mm256_set_pd(_t30, _t31, _t32, _t33);
  m256di_2 _t35 = _igen_mm256_mul_pd(_t29, s504);
  m256di_2 _t36 = _igen_mm256_mul_pd(_t34, s508);
  s535 = _igen_mm256_add_pd(_t35, _t36);
  t325 = _igen_mm256_add_pd(s502, s534);
  t326 = _igen_mm256_add_pd(s506, s535);
  t327 = _igen_mm256_sub_pd(s502, s534);
  t328 = _igen_mm256_sub_pd(s506, s535);
  f64_I _t37 = _ia_set_f64(-0.83146961230254512, 0.83146961230254535);
  f64_I _t38 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t39 = _ia_set_f64(-0.98078528040323032, 0.98078528040323054);
  f64_I _t40 = _ia_set_f64(-1.0, 1.0);
  m256di_2 _t41 = _igen_mm256_set_pd(_t37, _t38, _t39, _t40);
  f64_I _t42 = _ia_set_f64(-0.55557023301960207, 0.55557023301960229);
  f64_I _t43 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t44 = _ia_set_f64(-0.19509032201612822, 0.19509032201612828);
  f64_I _t45 = _ia_set_f64(-0.0, 0.0);
  m256di_2 _t46 = _igen_mm256_set_pd(_t42, _t43, _t44, _t45);
  m256di_2 _t47 = _igen_mm256_mul_pd(_t41, s503);
  m256di_2 _t48 = _igen_mm256_mul_pd(_t46, s507);
  s536 = _igen_mm256_sub_pd(_t47, _t48);
  f64_I _t49 = _ia_set_f64(-0.55557023301960207, 0.55557023301960229);
  f64_I _t50 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t51 = _ia_set_f64(-0.19509032201612822, 0.19509032201612828);
  f64_I _t52 = _ia_set_f64(-0.0, 0.0);
  m256di_2 _t53 = _igen_mm256_set_pd(_t49, _t50, _t51, _t52);
  f64_I _t54 = _ia_set_f64(-0.83146961230254512, 0.83146961230254535);
  f64_I _t55 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t56 = _ia_set_f64(-0.98078528040323032, 0.98078528040323054);
  f64_I _t57 = _ia_set_f64(-1.0, 1.0);
  m256di_2 _t58 = _igen_mm256_set_pd(_t54, _t55, _t56, _t57);
  m256di_2 _t59 = _igen_mm256_mul_pd(_t53, s503);
  m256di_2 _t60 = _igen_mm256_mul_pd(_t58, s507);
  s537 = _igen_mm256_add_pd(_t59, _t60);
  f64_I _t61 = _ia_set_f64((0.19509032201612828), (-0.19509032201612822));
  f64_I _t62 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t63 = _ia_set_f64(-0.83146961230254512, 0.83146961230254535);
  f64_I _t64 = _ia_set_f64(-1.0, 1.0);
  m256di_2 _t65 = _igen_mm256_set_pd(_t61, _t62, _t63, _t64);
  f64_I _t66 = _ia_set_f64(-0.98078528040323032, 0.98078528040323054);
  f64_I _t67 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t68 = _ia_set_f64(-0.55557023301960207, 0.55557023301960229);
  f64_I _t69 = _ia_set_f64(-0.0, 0.0);
  m256di_2 _t70 = _igen_mm256_set_pd(_t66, _t67, _t68, _t69);
  m256di_2 _t71 = _igen_mm256_mul_pd(_t65, s505);
  m256di_2 _t72 = _igen_mm256_mul_pd(_t70, s509);
  s538 = _igen_mm256_sub_pd(_t71, _t72);
  f64_I _t73 = _ia_set_f64(-0.98078528040323032, 0.98078528040323054);
  f64_I _t74 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t75 = _ia_set_f64(-0.55557023301960207, 0.55557023301960229);
  f64_I _t76 = _ia_set_f64(-0.0, 0.0);
  m256di_2 _t77 = _igen_mm256_set_pd(_t73, _t74, _t75, _t76);
  f64_I _t78 = _ia_set_f64((0.19509032201612828), (-0.19509032201612822));
  f64_I _t79 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t80 = _ia_set_f64(-0.83146961230254512, 0.83146961230254535);
  f64_I _t81 = _ia_set_f64(-1.0, 1.0);
  m256di_2 _t82 = _igen_mm256_set_pd(_t78, _t79, _t80, _t81);
  m256di_2 _t83 = _igen_mm256_mul_pd(_t77, s505);
  m256di_2 _t84 = _igen_mm256_mul_pd(_t82, s509);
  s539 = _igen_mm256_add_pd(_t83, _t84);
  t329 = _igen_mm256_add_pd(s536, s538);
  t330 = _igen_mm256_add_pd(s537, s539);
  t331 = _igen_mm256_sub_pd(s536, s538);
  t332 = _igen_mm256_sub_pd(s537, s539);
  t333 = _igen_mm256_add_pd(t325, t329);
  t334 = _igen_mm256_add_pd(t326, t330);
  t335 = _igen_mm256_sub_pd(t325, t329);
  t336 = _igen_mm256_sub_pd(t326, t330);
  s540 = _igen_mm256_unpacklo_pd(t333, t334);
  s541 = _igen_mm256_unpackhi_pd(t333, t334);
  a100 = ((m256di_2 *)Y);
  s542 = _igen_mm256_permute2f128_pd(s540, s541, (0) | ((2) << 4));
  *(a100) = s542;
  s543 = _igen_mm256_permute2f128_pd(s540, s541, (1) | ((3) << 4));
  *((a100 + 1)) = s543;
  s544 = _igen_mm256_unpacklo_pd(t335, t336);
  s545 = _igen_mm256_unpackhi_pd(t335, t336);
  s546 = _igen_mm256_permute2f128_pd(s544, s545, (0) | ((2) << 4));
  *((a100 + 8)) = s546;
  s547 = _igen_mm256_permute2f128_pd(s544, s545, (1) | ((3) << 4));
  *((a100 + 9)) = s547;
  t337 = _igen_mm256_sub_pd(t327, t332);
  t338 = _igen_mm256_add_pd(t328, t331);
  t339 = _igen_mm256_add_pd(t327, t332);
  t340 = _igen_mm256_sub_pd(t328, t331);
  s548 = _igen_mm256_unpacklo_pd(t337, t338);
  s549 = _igen_mm256_unpackhi_pd(t337, t338);
  s550 = _igen_mm256_permute2f128_pd(s548, s549, (0) | ((2) << 4));
  *((a100 + 4)) = s550;
  s551 = _igen_mm256_permute2f128_pd(s548, s549, (1) | ((3) << 4));
  *((a100 + 5)) = s551;
  s552 = _igen_mm256_unpacklo_pd(t339, t340);
  s553 = _igen_mm256_unpackhi_pd(t339, t340);
  s554 = _igen_mm256_permute2f128_pd(s552, s553, (0) | ((2) << 4));
  *((a100 + 12)) = s554;
  s555 = _igen_mm256_permute2f128_pd(s552, s553, (1) | ((3) << 4));
  *((a100 + 13)) = s555;
  f64_I _t85 = _ia_set_f64((0.92387953251128685), (-0.92387953251128663));
  f64_I _t86 = _ia_set_f64((0.70710678118654768), (-0.70710678118654746));
  f64_I _t87 = _ia_set_f64((0.38268343236508984), (-0.38268343236508973));
  f64_I _t88 = _ia_set_f64(-0.0, 0.0);
  m256di_2 _t89 = _igen_mm256_set_pd(_t85, _t86, _t87, _t88);
  f64_I _t90 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t91 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  f64_I _t92 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t93 = _ia_set_f64(-1.0, 1.0);
  m256di_2 _t94 = _igen_mm256_set_pd(_t90, _t91, _t92, _t93);
  m256di_2 _t95 = _igen_mm256_mul_pd(_t89, s528);
  m256di_2 _t96 = _igen_mm256_mul_pd(_t94, s532);
  s556 = _igen_mm256_sub_pd(_t95, _t96);
  f64_I _t97 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t98 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  f64_I _t99 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t100 = _ia_set_f64(-1.0, 1.0);
  m256di_2 _t101 = _igen_mm256_set_pd(_t97, _t98, _t99, _t100);
  f64_I _t102 = _ia_set_f64((0.92387953251128685), (-0.92387953251128663));
  f64_I _t103 = _ia_set_f64((0.70710678118654768), (-0.70710678118654746));
  f64_I _t104 = _ia_set_f64((0.38268343236508984), (-0.38268343236508973));
  f64_I _t105 = _ia_set_f64(-0.0, 0.0);
  m256di_2 _t106 = _igen_mm256_set_pd(_t102, _t103, _t104, _t105);
  m256di_2 _t107 = _igen_mm256_mul_pd(_t101, s528);
  m256di_2 _t108 = _igen_mm256_mul_pd(_t106, s532);
  s557 = _igen_mm256_add_pd(_t107, _t108);
  t341 = _igen_mm256_add_pd(s526, s556);
  t342 = _igen_mm256_add_pd(s530, s557);
  t343 = _igen_mm256_sub_pd(s526, s556);
  t344 = _igen_mm256_sub_pd(s530, s557);
  f64_I _t109 = _ia_set_f64(-0.19509032201612822, 0.19509032201612828);
  f64_I _t110 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t111 = _ia_set_f64(-0.55557023301960207, 0.55557023301960229);
  f64_I _t112 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  m256di_2 _t113 = _igen_mm256_set_pd(_t109, _t110, _t111, _t112);
  f64_I _t114 = _ia_set_f64(-0.98078528040323032, 0.98078528040323054);
  f64_I _t115 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t116 = _ia_set_f64(-0.83146961230254512, 0.83146961230254535);
  f64_I _t117 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  m256di_2 _t118 = _igen_mm256_set_pd(_t114, _t115, _t116, _t117);
  m256di_2 _t119 = _igen_mm256_mul_pd(_t113, s527);
  m256di_2 _t120 = _igen_mm256_mul_pd(_t118, s531);
  s558 = _igen_mm256_sub_pd(_t119, _t120);
  f64_I _t121 = _ia_set_f64(-0.98078528040323032, 0.98078528040323054);
  f64_I _t122 = _ia_set_f64(-0.92387953251128663, 0.92387953251128685);
  f64_I _t123 = _ia_set_f64(-0.83146961230254512, 0.83146961230254535);
  f64_I _t124 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  m256di_2 _t125 = _igen_mm256_set_pd(_t121, _t122, _t123, _t124);
  f64_I _t126 = _ia_set_f64(-0.19509032201612822, 0.19509032201612828);
  f64_I _t127 = _ia_set_f64(-0.38268343236508973, 0.38268343236508984);
  f64_I _t128 = _ia_set_f64(-0.55557023301960207, 0.55557023301960229);
  f64_I _t129 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  m256di_2 _t130 = _igen_mm256_set_pd(_t126, _t127, _t128, _t129);
  m256di_2 _t131 = _igen_mm256_mul_pd(_t125, s527);
  m256di_2 _t132 = _igen_mm256_mul_pd(_t130, s531);
  s559 = _igen_mm256_add_pd(_t131, _t132);
  f64_I _t133 = _ia_set_f64((0.55557023301960229), (-0.55557023301960207));
  f64_I _t134 = _ia_set_f64((0.92387953251128685), (-0.92387953251128663));
  f64_I _t135 = _ia_set_f64((0.98078528040323054), (-0.98078528040323032));
  f64_I _t136 = _ia_set_f64((0.70710678118654768), (-0.70710678118654746));
  m256di_2 _t137 = _igen_mm256_set_pd(_t133, _t134, _t135, _t136);
  f64_I _t138 = _ia_set_f64((0.83146961230254535), (-0.83146961230254512));
  f64_I _t139 = _ia_set_f64((0.38268343236508984), (-0.38268343236508973));
  f64_I _t140 = _ia_set_f64(-0.19509032201612822, 0.19509032201612828);
  f64_I _t141 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  m256di_2 _t142 = _igen_mm256_set_pd(_t138, _t139, _t140, _t141);
  m256di_2 _t143 = _igen_mm256_mul_pd(_t137, s529);
  m256di_2 _t144 = _igen_mm256_mul_pd(_t142, s533);
  s560 = _igen_mm256_sub_pd(_t143, _t144);
  f64_I _t145 = _ia_set_f64((0.83146961230254535), (-0.83146961230254512));
  f64_I _t146 = _ia_set_f64((0.38268343236508984), (-0.38268343236508973));
  f64_I _t147 = _ia_set_f64(-0.19509032201612822, 0.19509032201612828);
  f64_I _t148 = _ia_set_f64(-0.70710678118654746, 0.70710678118654768);
  m256di_2 _t149 = _igen_mm256_set_pd(_t145, _t146, _t147, _t148);
  f64_I _t150 = _ia_set_f64((0.55557023301960229), (-0.55557023301960207));
  f64_I _t151 = _ia_set_f64((0.92387953251128685), (-0.92387953251128663));
  f64_I _t152 = _ia_set_f64((0.98078528040323054), (-0.98078528040323032));
  f64_I _t153 = _ia_set_f64((0.70710678118654768), (-0.70710678118654746));
  m256di_2 _t154 = _igen_mm256_set_pd(_t150, _t151, _t152, _t153);
  m256di_2 _t155 = _igen_mm256_mul_pd(_t149, s529);
  m256di_2 _t156 = _igen_mm256_mul_pd(_t154, s533);
  s561 = _igen_mm256_add_pd(_t155, _t156);
  t345 = _igen_mm256_add_pd(s558, s560);
  t346 = _igen_mm256_add_pd(s559, s561);
  t347 = _igen_mm256_sub_pd(s558, s560);
  t348 = _igen_mm256_sub_pd(s559, s561);
  t349 = _igen_mm256_add_pd(t341, t345);
  t350 = _igen_mm256_add_pd(t342, t346);
  t351 = _igen_mm256_sub_pd(t341, t345);
  t352 = _igen_mm256_sub_pd(t342, t346);
  s562 = _igen_mm256_unpacklo_pd(t349, t350);
  s563 = _igen_mm256_unpackhi_pd(t349, t350);
  s564 = _igen_mm256_permute2f128_pd(s562, s563, (0) | ((2) << 4));
  *((a100 + 2)) = s564;
  s565 = _igen_mm256_permute2f128_pd(s562, s563, (1) | ((3) << 4));
  *((a100 + 3)) = s565;
  s566 = _igen_mm256_unpacklo_pd(t351, t352);
  s567 = _igen_mm256_unpackhi_pd(t351, t352);
  s568 = _igen_mm256_permute2f128_pd(s566, s567, (0) | ((2) << 4));
  *((a100 + 10)) = s568;
  s569 = _igen_mm256_permute2f128_pd(s566, s567, (1) | ((3) << 4));
  *((a100 + 11)) = s569;
  t353 = _igen_mm256_sub_pd(t343, t348);
  t354 = _igen_mm256_add_pd(t344, t347);
  t355 = _igen_mm256_add_pd(t343, t348);
  t356 = _igen_mm256_sub_pd(t344, t347);
  s570 = _igen_mm256_unpacklo_pd(t353, t354);
  s571 = _igen_mm256_unpackhi_pd(t353, t354);
  s572 = _igen_mm256_permute2f128_pd(s570, s571, (0) | ((2) << 4));
  *((a100 + 6)) = s572;
  s573 = _igen_mm256_permute2f128_pd(s570, s571, (1) | ((3) << 4));
  *((a100 + 7)) = s573;
  s574 = _igen_mm256_unpacklo_pd(t355, t356);
  s575 = _igen_mm256_unpackhi_pd(t355, t356);
  s576 = _igen_mm256_permute2f128_pd(s574, s575, (0) | ((2) << 4));
  *((a100 + 14)) = s576;
  s577 = _igen_mm256_permute2f128_pd(s574, s575, (1) | ((3) << 4));
  *((a100 + 15)) = s577;
}
