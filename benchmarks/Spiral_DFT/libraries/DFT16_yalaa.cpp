#include "yalaa_wrap.h"

double cospi(double x);
double sinpi(double x);

void init_DFT16_yalaa() {
}

void DFT16(yalaa_af0  *Y, yalaa_af0  *X) {
    yalaa_af0 a145, a146, a147, a148, a149, a150, a151, a152
            , a153, a154, a155, a156, s61, s62, s63, s64
            , s65, s66, s67, s68, s69, s70, s71, s72
            , s73, s74, s75, s76, s77, s78, s79, s80
            , t373, t374, t375, t376, t377, t378, t379, t380
            , t381, t382, t383, t384, t385, t387, t388, t389
            , t390, t391, t392, t393, t394, t395, t396, t397
            , t398, t399, t400, t401, t402, t403, t404, t405
            , t406, t407, t408, t409, t410, t411, t412, t413
            , t414, t415, t416, t417, t418, t419, t420, t421
            , t422, t423, t424, t425, t426, t427, t428, t429
            , t430, t431, t432, t433, t434, t435, t436, t437
            , t438, t439, t440, t441, t442, t443, t444, t445
            , t446, t447, t448, t449, t450, t451, t452, t453
            , t454, t455, t456, t457;
    t373 = (*(X) + *((X + 16)));
    t374 = (*((X + 1)) + *((X + 17)));
    t375 = (*(X) - *((X + 16)));
    t376 = (*((X + 1)) - *((X + 17)));
    t377 = (*((X + 4)) + *((X + 20)));
    t378 = (*((X + 5)) + *((X + 21)));
    a145 = (0.70710678118654757*(*((X + 4)) - *((X + 20))));
    a146 = (0.70710678118654757*(*((X + 5)) - *((X + 21))));
    s61 = (a145 - a146);
    s62 = (a145 + a146);
    t379 = (*((X + 8)) + *((X + 24)));
    t380 = (*((X + 9)) + *((X + 25)));
    t381 = (*((X + 8)) - *((X + 24)));
    t382 = (*((X + 9)) - *((X + 25)));
    t383 = (*((X + 12)) + *((X + 28)));
    t384 = (*((X + 13)) + *((X + 29)));
    a147 = (0.70710678118654757*(*((X + 12)) - *((X + 28))));
    a148 = (0.70710678118654757*(*((X + 13)) - *((X + 29))));
    s63 = (a147 + a148);
    s64 = (a147 - a148);
    t385 = (t373 + t379);
    t387 = (t374 + t380);
    t388 = (t373 - t379);
    t389 = (t374 - t380);
    t390 = (t377 + t383);
    t391 = (t378 + t384);
    t392 = (t377 - t383);
    t393 = (t378 - t384);
    t394 = (t385 + t390);
    t395 = (t387 + t391);
    t396 = (t385 - t390);
    t397 = (t387 - t391);
    t398 = (t388 - t393);
    t399 = (t389 + t392);
    t400 = (t388 + t393);
    t401 = (t389 - t392);
    t402 = (t375 - t382);
    t403 = (t376 + t381);
    t404 = (t375 + t382);
    t405 = (t376 - t381);
    t406 = (s61 - s63);
    t407 = (s62 + s64);
    t408 = (s61 + s63);
    t409 = (s62 - s64);
    t410 = (t402 + t406);
    t411 = (t403 + t407);
    t412 = (t402 - t406);
    t413 = (t403 - t407);
    t414 = (t404 - t409);
    t415 = (t405 + t408);
    t416 = (t404 + t409);
    t417 = (t405 - t408);
    t418 = (*((X + 2)) + *((X + 18)));
    t419 = (*((X + 3)) + *((X + 19)));
    t420 = (*((X + 2)) - *((X + 18)));
    t421 = (*((X + 3)) - *((X + 19)));
    t422 = (*((X + 6)) + *((X + 22)));
    t423 = (*((X + 7)) + *((X + 23)));
    a149 = (0.70710678118654757*(*((X + 6)) - *((X + 22))));
    a150 = (0.70710678118654757*(*((X + 7)) - *((X + 23))));
    s65 = (a149 - a150);
    s66 = (a149 + a150);
    t424 = (*((X + 10)) + *((X + 26)));
    t425 = (*((X + 11)) + *((X + 27)));
    t426 = (*((X + 10)) - *((X + 26)));
    t427 = (*((X + 11)) - *((X + 27)));
    t428 = (*((X + 14)) + *((X + 30)));
    t429 = (*((X + 15)) + *((X + 31)));
    a151 = (0.70710678118654757*(*((X + 14)) - *((X + 30))));
    a152 = (0.70710678118654757*(*((X + 15)) - *((X + 31))));
    s67 = (a151 + a152);
    s68 = (a151 - a152);
    t430 = (t418 + t424);
    t431 = (t419 + t425);
    t432 = (t418 - t424);
    t433 = (t419 - t425);
    t434 = (t422 + t428);
    t435 = (t423 + t429);
    t436 = (t422 - t428);
    t437 = (t423 - t429);
    t438 = (t430 + t434);
    t439 = (t431 + t435);
    t440 = (t430 - t434);
    t441 = (t431 - t435);
    a153 = (0.70710678118654757*(t432 - t437));
    a154 = (0.70710678118654757*(t433 + t436));
    s69 = (a153 - a154);
    s70 = (a153 + a154);
    a155 = (0.70710678118654757*(t432 + t437));
    a156 = (0.70710678118654757*(t433 - t436));
    s71 = (a155 + a156);
    s72 = (a155 - a156);
    t442 = (t420 - t427);
    t443 = (t421 + t426);
    t444 = (t420 + t427);
    t445 = (t421 - t426);
    t446 = (s65 - s67);
    t447 = (s66 + s68);
    t448 = (s65 + s67);
    t449 = (s66 - s68);
    t450 = (t442 + t446);
    t451 = (t443 + t447);
    t452 = (t442 - t446);
    t453 = (t443 - t447);
    s73 = ((0.92387953251128674*t450) - (0.38268343236508978*t451));
    s74 = ((0.38268343236508978*t450) + (0.92387953251128674*t451));
    s75 = ((0.38268343236508978*t452) + (0.92387953251128674*t453));
    s76 = ((0.92387953251128674*t452) - (0.38268343236508978*t453));
    t454 = (t444 - t449);
    t455 = (t445 + t448);
    t456 = (t444 + t449);
    t457 = (t445 - t448);
    s77 = ((0.38268343236508978*t454) - (0.92387953251128674*t455));
    s78 = ((0.92387953251128674*t454) + (0.38268343236508978*t455));
    s79 = ((0.92387953251128674*t456) + (0.38268343236508978*t457));
    s80 = ((0.38268343236508978*t456) - (0.92387953251128674*t457));
    *(Y) = (t394 + t438);
    *((Y + 1)) = (t395 + t439);
    *((Y + 16)) = (t394 - t438);
    *((Y + 17)) = (t395 - t439);
    *((Y + 2)) = (t410 + s73);
    *((Y + 3)) = (t411 + s74);
    *((Y + 18)) = (t410 - s73);
    *((Y + 19)) = (t411 - s74);
    *((Y + 4)) = (t398 + s69);
    *((Y + 5)) = (t399 + s70);
    *((Y + 20)) = (t398 - s69);
    *((Y + 21)) = (t399 - s70);
    *((Y + 6)) = (t414 + s77);
    *((Y + 7)) = (t415 + s78);
    *((Y + 22)) = (t414 - s77);
    *((Y + 23)) = (t415 - s78);
    *((Y + 8)) = (t396 - t441);
    *((Y + 9)) = (t397 + t440);
    *((Y + 24)) = (t396 + t441);
    *((Y + 25)) = (t397 - t440);
    *((Y + 10)) = (t412 - s75);
    *((Y + 11)) = (t413 + s76);
    *((Y + 26)) = (t412 + s75);
    *((Y + 27)) = (t413 - s76);
    *((Y + 12)) = (t400 - s71);
    *((Y + 13)) = (t401 + s72);
    *((Y + 28)) = (t400 + s71);
    *((Y + 29)) = (t401 - s72);
    *((Y + 14)) = (t416 - s79);
    *((Y + 15)) = (t417 + s80);
    *((Y + 30)) = (t416 + s79);
    *((Y + 31)) = (t417 - s80);
}
