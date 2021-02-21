#pragma once

typedef enum {
    FALSE_I   =  0,
    TRUE_I    =  1,
    UNKNOWN_I = -1
} bool_I;

/// Tribool logic operations
static bool_I _ia_or_tb (bool_I a, bool_I b) {
    /* todo: change this to correct tribool evaluation */
    return (bool_I) ((int) a || (int) b);
}

static bool_I _ia_and_tb (bool_I a, bool_I b) {
    /* todo: change this to correct tribool evaluation */
    return (bool_I) ((int) a && (int) b);
}

static bool_I _ia_cvt2tb (int a) {
    /* todo: change this to correct tribool evaluation */
    if (a) {
        return TRUE_I;
    }
    else {
        return FALSE_I;
    }
}