
/*
 * This code was generated by Spiral 8.0.0, www.spiral.net
 */

#include <math.h>
#include <immintrin.h>

void init_AVX_DFT32(double a) {
}

void AVX_DFT32(double  *Y, double  *X) {
    __m256d a98, a99, s434, s435, s436, s437, s438, s439
    , s440, s441, s442, s443, s444, s445, s446, s447
    , s448, s449, s450, s451, s452, s453, s454, s455
    , s456, s457, s458, s459, s460, s461, s462, s463
    , s464, s465, s466, s467, s468, s469, s470, s471
    , s472, s473, s474, s475, s476, s477, s478, s479
    , s480, s481, s482, s483, s484, s485, s486, s487
    , s488, s489, s490, s491, s492, s493, s494, s495
    , s496, s497, s498, s499, s500, s501, s502, s503
    , s504, s505, s506, s507, s508, s509, s510, s511
    , s512, s513, s514, s515, s516, s517, s518, s519
    , s520, s521, s522, s523, s524, s525, s526, s527
    , s528, s529, s530, s531, s532, s533, s534, s535
    , s536, s537, s538, s539, s540, s541, s542, s543
    , s544, s545, s546, s547, s548, s549, s550, s551
    , s552, s553, s554, s555, s556, s557, s558, s559
    , s560, s561, s562, s563, s564, s565, s566, s567
    , s568, s569, s570, s571, s572, s573, s574, s575
    , s576, s577, t279, t280, t281, t282, t283, t284
    , t285, t286, t287, t288, t289, t290, t291, t292
    , t293, t294, t295, t296, t297, t298, t299, t300
    , t301, t302, t303, t304, t305, t306, t307, t308
    , t309, t310, t311, t312, t313, t314, t315, t316
    , t317, t318, t319, t320, t321, t322, t323, t324
    , t325, t326, t327, t328, t329, t330, t331, t332
    , t333, t334, t335, t336, t337, t338, t339, t340
    , t341, t342, t343, t344, t345, t346, t347, t348
    , t349, t350, t351, t352, t353, t354, t355, t356;
    __m256d  *a100, *a97;
    a97 = ((__m256d  *) X);
    s434 = *(a97);
    s435 = *((a97 + 1));
    s436 = _mm256_permute2f128_pd(s434, s435, (0) | ((2) << 4));
    s437 = _mm256_permute2f128_pd(s434, s435, (1) | ((3) << 4));
    s438 = _mm256_unpacklo_pd(s436, s437);
    s439 = _mm256_unpackhi_pd(s436, s437);
    s440 = *((a97 + 8));
    s441 = *((a97 + 9));
    s442 = _mm256_permute2f128_pd(s440, s441, (0) | ((2) << 4));
    s443 = _mm256_permute2f128_pd(s440, s441, (1) | ((3) << 4));
    s444 = _mm256_unpacklo_pd(s442, s443);
    s445 = _mm256_unpackhi_pd(s442, s443);
    t279 = _mm256_add_pd(s438, s444);
    t280 = _mm256_add_pd(s439, s445);
    t281 = _mm256_sub_pd(s438, s444);
    t282 = _mm256_sub_pd(s439, s445);
    s446 = *((a97 + 2));
    s447 = *((a97 + 3));
    s448 = _mm256_permute2f128_pd(s446, s447, (0) | ((2) << 4));
    s449 = _mm256_permute2f128_pd(s446, s447, (1) | ((3) << 4));
    s450 = _mm256_unpacklo_pd(s448, s449);
    s451 = _mm256_unpackhi_pd(s448, s449);
    s452 = *((a97 + 10));
    s453 = *((a97 + 11));
    s454 = _mm256_permute2f128_pd(s452, s453, (0) | ((2) << 4));
    s455 = _mm256_permute2f128_pd(s452, s453, (1) | ((3) << 4));
    s456 = _mm256_unpacklo_pd(s454, s455);
    s457 = _mm256_unpackhi_pd(s454, s455);
    t283 = _mm256_add_pd(s450, s456);
    t284 = _mm256_add_pd(s451, s457);
    t285 = _mm256_sub_pd(s450, s456);
    t286 = _mm256_sub_pd(s451, s457);
    s458 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(t285, t286));
    s459 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_add_pd(t285, t286));
    s460 = *((a97 + 4));
    s461 = *((a97 + 5));
    s462 = _mm256_permute2f128_pd(s460, s461, (0) | ((2) << 4));
    s463 = _mm256_permute2f128_pd(s460, s461, (1) | ((3) << 4));
    s464 = _mm256_unpacklo_pd(s462, s463);
    s465 = _mm256_unpackhi_pd(s462, s463);
    s466 = *((a97 + 12));
    s467 = *((a97 + 13));
    s468 = _mm256_permute2f128_pd(s466, s467, (0) | ((2) << 4));
    s469 = _mm256_permute2f128_pd(s466, s467, (1) | ((3) << 4));
    s470 = _mm256_unpacklo_pd(s468, s469);
    s471 = _mm256_unpackhi_pd(s468, s469);
    t287 = _mm256_add_pd(s464, s470);
    t288 = _mm256_add_pd(s465, s471);
    t289 = _mm256_sub_pd(s464, s470);
    t290 = _mm256_sub_pd(s465, s471);
    s472 = *((a97 + 6));
    s473 = *((a97 + 7));
    s474 = _mm256_permute2f128_pd(s472, s473, (0) | ((2) << 4));
    s475 = _mm256_permute2f128_pd(s472, s473, (1) | ((3) << 4));
    s476 = _mm256_unpacklo_pd(s474, s475);
    s477 = _mm256_unpackhi_pd(s474, s475);
    s478 = *((a97 + 14));
    s479 = *((a97 + 15));
    s480 = _mm256_permute2f128_pd(s478, s479, (0) | ((2) << 4));
    s481 = _mm256_permute2f128_pd(s478, s479, (1) | ((3) << 4));
    s482 = _mm256_unpacklo_pd(s480, s481);
    s483 = _mm256_unpackhi_pd(s480, s481);
    t291 = _mm256_add_pd(s476, s482);
    t292 = _mm256_add_pd(s477, s483);
    a98 = _mm256_mul_pd(_mm256_set1_pd((-0.70710678118654757)), _mm256_sub_pd(s476, s482));
    a99 = _mm256_mul_pd(_mm256_set1_pd(0.70710678118654757), _mm256_sub_pd(s477, s483));
    s484 = _mm256_sub_pd(a98, a99);
    s485 = _mm256_add_pd(a98, a99);
    t293 = _mm256_add_pd(t279, t287);
    t294 = _mm256_add_pd(t280, t288);
    t295 = _mm256_sub_pd(t279, t287);
    t296 = _mm256_sub_pd(t280, t288);
    t297 = _mm256_add_pd(t283, t291);
    t298 = _mm256_add_pd(t284, t292);
    t299 = _mm256_sub_pd(t283, t291);
    t300 = _mm256_sub_pd(t284, t292);
    t301 = _mm256_add_pd(t293, t297);
    t302 = _mm256_add_pd(t294, t298);
    t303 = _mm256_sub_pd(t293, t297);
    t304 = _mm256_sub_pd(t294, t298);
    t305 = _mm256_sub_pd(t295, t300);
    t306 = _mm256_add_pd(t296, t299);
    t307 = _mm256_add_pd(t295, t300);
    t308 = _mm256_sub_pd(t296, t299);
    t309 = _mm256_sub_pd(t281, t290);
    t310 = _mm256_add_pd(t282, t289);
    t311 = _mm256_add_pd(t281, t290);
    t312 = _mm256_sub_pd(t282, t289);
    t313 = _mm256_add_pd(s458, s484);
    t314 = _mm256_sub_pd(s459, s485);
    t315 = _mm256_sub_pd(s458, s484);
    t316 = _mm256_add_pd(s459, s485);
    t317 = _mm256_add_pd(t309, t313);
    t318 = _mm256_add_pd(t310, t314);
    t319 = _mm256_sub_pd(t309, t313);
    t320 = _mm256_sub_pd(t310, t314);
    t321 = _mm256_sub_pd(t311, t316);
    t322 = _mm256_add_pd(t312, t315);
    t323 = _mm256_add_pd(t311, t316);
    t324 = _mm256_sub_pd(t312, t315);
    s486 = _mm256_unpacklo_pd(t301, t317);
    s487 = _mm256_unpackhi_pd(t301, t317);
    s488 = _mm256_unpacklo_pd(t302, t318);
    s489 = _mm256_unpackhi_pd(t302, t318);
    s490 = _mm256_permute2f128_pd(s486, s487, (0) | ((2) << 4));
    s491 = _mm256_permute2f128_pd(s486, s487, (1) | ((3) << 4));
    s492 = _mm256_permute2f128_pd(s488, s489, (0) | ((2) << 4));
    s493 = _mm256_permute2f128_pd(s488, s489, (1) | ((3) << 4));
    s494 = _mm256_unpacklo_pd(t305, t321);
    s495 = _mm256_unpackhi_pd(t305, t321);
    s496 = _mm256_unpacklo_pd(t306, t322);
    s497 = _mm256_unpackhi_pd(t306, t322);
    s498 = _mm256_permute2f128_pd(s494, s495, (0) | ((2) << 4));
    s499 = _mm256_permute2f128_pd(s494, s495, (1) | ((3) << 4));
    s500 = _mm256_permute2f128_pd(s496, s497, (0) | ((2) << 4));
    s501 = _mm256_permute2f128_pd(s496, s497, (1) | ((3) << 4));
    s502 = _mm256_permute2f128_pd(s490, s498, (0) | ((2) << 4));
    s503 = _mm256_permute2f128_pd(s490, s498, (1) | ((3) << 4));
    s504 = _mm256_permute2f128_pd(s491, s499, (0) | ((2) << 4));
    s505 = _mm256_permute2f128_pd(s491, s499, (1) | ((3) << 4));
    s506 = _mm256_permute2f128_pd(s492, s500, (0) | ((2) << 4));
    s507 = _mm256_permute2f128_pd(s492, s500, (1) | ((3) << 4));
    s508 = _mm256_permute2f128_pd(s493, s501, (0) | ((2) << 4));
    s509 = _mm256_permute2f128_pd(s493, s501, (1) | ((3) << 4));
    s510 = _mm256_unpacklo_pd(t303, t319);
    s511 = _mm256_unpackhi_pd(t303, t319);
    s512 = _mm256_unpacklo_pd(t304, t320);
    s513 = _mm256_unpackhi_pd(t304, t320);
    s514 = _mm256_permute2f128_pd(s510, s511, (0) | ((2) << 4));
    s515 = _mm256_permute2f128_pd(s510, s511, (1) | ((3) << 4));
    s516 = _mm256_permute2f128_pd(s512, s513, (0) | ((2) << 4));
    s517 = _mm256_permute2f128_pd(s512, s513, (1) | ((3) << 4));
    s518 = _mm256_unpacklo_pd(t307, t323);
    s519 = _mm256_unpackhi_pd(t307, t323);
    s520 = _mm256_unpacklo_pd(t308, t324);
    s521 = _mm256_unpackhi_pd(t308, t324);
    s522 = _mm256_permute2f128_pd(s518, s519, (0) | ((2) << 4));
    s523 = _mm256_permute2f128_pd(s518, s519, (1) | ((3) << 4));
    s524 = _mm256_permute2f128_pd(s520, s521, (0) | ((2) << 4));
    s525 = _mm256_permute2f128_pd(s520, s521, (1) | ((3) << 4));
    s526 = _mm256_permute2f128_pd(s514, s522, (0) | ((2) << 4));
    s527 = _mm256_permute2f128_pd(s514, s522, (1) | ((3) << 4));
    s528 = _mm256_permute2f128_pd(s515, s523, (0) | ((2) << 4));
    s529 = _mm256_permute2f128_pd(s515, s523, (1) | ((3) << 4));
    s530 = _mm256_permute2f128_pd(s516, s524, (0) | ((2) << 4));
    s531 = _mm256_permute2f128_pd(s516, s524, (1) | ((3) << 4));
    s532 = _mm256_permute2f128_pd(s517, s525, (0) | ((2) << 4));
    s533 = _mm256_permute2f128_pd(s517, s525, (1) | ((3) << 4));
    s534 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s504), _mm256_mul_pd(_mm256_set_pd(0.92387953251128674, 0.70710678118654757, 0.38268343236508978, 0.0), s508));
    s535 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.92387953251128674, 0.70710678118654757, 0.38268343236508978, 0.0), s504), _mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s508));
    t325 = _mm256_add_pd(s502, s534);
    t326 = _mm256_add_pd(s506, s535);
    t327 = _mm256_sub_pd(s502, s534);
    t328 = _mm256_sub_pd(s506, s535);
    s536 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.83146961230254524, 0.92387953251128674, 0.98078528040323043, 1.0), s503), _mm256_mul_pd(_mm256_set_pd(0.55557023301960218, 0.38268343236508978, 0.19509032201612825, 0.0), s507));
    s537 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.55557023301960218, 0.38268343236508978, 0.19509032201612825, 0.0), s503), _mm256_mul_pd(_mm256_set_pd(0.83146961230254524, 0.92387953251128674, 0.98078528040323043, 1.0), s507));
    s538 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.19509032201612825), 0.38268343236508978, 0.83146961230254524, 1.0), s505), _mm256_mul_pd(_mm256_set_pd(0.98078528040323043, 0.92387953251128674, 0.55557023301960218, 0.0), s509));
    s539 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.98078528040323043, 0.92387953251128674, 0.55557023301960218, 0.0), s505), _mm256_mul_pd(_mm256_set_pd((-0.19509032201612825), 0.38268343236508978, 0.83146961230254524, 1.0), s509));
    t329 = _mm256_add_pd(s536, s538);
    t330 = _mm256_add_pd(s537, s539);
    t331 = _mm256_sub_pd(s536, s538);
    t332 = _mm256_sub_pd(s537, s539);
    t333 = _mm256_add_pd(t325, t329);
    t334 = _mm256_add_pd(t326, t330);
    t335 = _mm256_sub_pd(t325, t329);
    t336 = _mm256_sub_pd(t326, t330);
    s540 = _mm256_unpacklo_pd(t333, t334);
    s541 = _mm256_unpackhi_pd(t333, t334);
    a100 = ((__m256d  *) Y);
    s542 = _mm256_permute2f128_pd(s540, s541, (0) | ((2) << 4));
    *(a100) = s542;
    s543 = _mm256_permute2f128_pd(s540, s541, (1) | ((3) << 4));
    *((a100 + 1)) = s543;
    s544 = _mm256_unpacklo_pd(t335, t336);
    s545 = _mm256_unpackhi_pd(t335, t336);
    s546 = _mm256_permute2f128_pd(s544, s545, (0) | ((2) << 4));
    *((a100 + 8)) = s546;
    s547 = _mm256_permute2f128_pd(s544, s545, (1) | ((3) << 4));
    *((a100 + 9)) = s547;
    t337 = _mm256_sub_pd(t327, t332);
    t338 = _mm256_add_pd(t328, t331);
    t339 = _mm256_add_pd(t327, t332);
    t340 = _mm256_sub_pd(t328, t331);
    s548 = _mm256_unpacklo_pd(t337, t338);
    s549 = _mm256_unpackhi_pd(t337, t338);
    s550 = _mm256_permute2f128_pd(s548, s549, (0) | ((2) << 4));
    *((a100 + 4)) = s550;
    s551 = _mm256_permute2f128_pd(s548, s549, (1) | ((3) << 4));
    *((a100 + 5)) = s551;
    s552 = _mm256_unpacklo_pd(t339, t340);
    s553 = _mm256_unpackhi_pd(t339, t340);
    s554 = _mm256_permute2f128_pd(s552, s553, (0) | ((2) << 4));
    *((a100 + 12)) = s554;
    s555 = _mm256_permute2f128_pd(s552, s553, (1) | ((3) << 4));
    *((a100 + 13)) = s555;
    s556 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.92387953251128674), (-0.70710678118654757), (-0.38268343236508978), 0.0), s528), _mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s532));
    s557 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.38268343236508978, 0.70710678118654757, 0.92387953251128674, 1.0), s528), _mm256_mul_pd(_mm256_set_pd((-0.92387953251128674), (-0.70710678118654757), (-0.38268343236508978), 0.0), s532));
    t341 = _mm256_add_pd(s526, s556);
    t342 = _mm256_add_pd(s530, s557);
    t343 = _mm256_sub_pd(s526, s556);
    t344 = _mm256_sub_pd(s530, s557);
    s558 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd(0.19509032201612825, 0.38268343236508978, 0.55557023301960218, 0.70710678118654757), s527), _mm256_mul_pd(_mm256_set_pd(0.98078528040323043, 0.92387953251128674, 0.83146961230254524, 0.70710678118654757), s531));
    s559 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd(0.98078528040323043, 0.92387953251128674, 0.83146961230254524, 0.70710678118654757), s527), _mm256_mul_pd(_mm256_set_pd(0.19509032201612825, 0.38268343236508978, 0.55557023301960218, 0.70710678118654757), s531));
    s560 = _mm256_sub_pd(_mm256_mul_pd(_mm256_set_pd((-0.55557023301960218), (-0.92387953251128674), (-0.98078528040323043), (-0.70710678118654757)), s529), _mm256_mul_pd(_mm256_set_pd((-0.83146961230254524), (-0.38268343236508978), 0.19509032201612825, 0.70710678118654757), s533));
    s561 = _mm256_add_pd(_mm256_mul_pd(_mm256_set_pd((-0.83146961230254524), (-0.38268343236508978), 0.19509032201612825, 0.70710678118654757), s529), _mm256_mul_pd(_mm256_set_pd((-0.55557023301960218), (-0.92387953251128674), (-0.98078528040323043), (-0.70710678118654757)), s533));
    t345 = _mm256_add_pd(s558, s560);
    t346 = _mm256_add_pd(s559, s561);
    t347 = _mm256_sub_pd(s558, s560);
    t348 = _mm256_sub_pd(s559, s561);
    t349 = _mm256_add_pd(t341, t345);
    t350 = _mm256_add_pd(t342, t346);
    t351 = _mm256_sub_pd(t341, t345);
    t352 = _mm256_sub_pd(t342, t346);
    s562 = _mm256_unpacklo_pd(t349, t350);
    s563 = _mm256_unpackhi_pd(t349, t350);
    s564 = _mm256_permute2f128_pd(s562, s563, (0) | ((2) << 4));
    *((a100 + 2)) = s564;
    s565 = _mm256_permute2f128_pd(s562, s563, (1) | ((3) << 4));
    *((a100 + 3)) = s565;
    s566 = _mm256_unpacklo_pd(t351, t352);
    s567 = _mm256_unpackhi_pd(t351, t352);
    s568 = _mm256_permute2f128_pd(s566, s567, (0) | ((2) << 4));
    *((a100 + 10)) = s568;
    s569 = _mm256_permute2f128_pd(s566, s567, (1) | ((3) << 4));
    *((a100 + 11)) = s569;
    t353 = _mm256_sub_pd(t343, t348);
    t354 = _mm256_add_pd(t344, t347);
    t355 = _mm256_add_pd(t343, t348);
    t356 = _mm256_sub_pd(t344, t347);
    s570 = _mm256_unpacklo_pd(t353, t354);
    s571 = _mm256_unpackhi_pd(t353, t354);
    s572 = _mm256_permute2f128_pd(s570, s571, (0) | ((2) << 4));
    *((a100 + 6)) = s572;
    s573 = _mm256_permute2f128_pd(s570, s571, (1) | ((3) << 4));
    *((a100 + 7)) = s573;
    s574 = _mm256_unpacklo_pd(t355, t356);
    s575 = _mm256_unpackhi_pd(t355, t356);
    s576 = _mm256_permute2f128_pd(s574, s575, (0) | ((2) << 4));
    *((a100 + 14)) = s576;
    s577 = _mm256_permute2f128_pd(s574, s575, (1) | ((3) << 4));
    *((a100 + 15)) = s577;
}
