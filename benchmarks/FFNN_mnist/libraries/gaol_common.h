#pragma once
#include "gaol/gaol"


/* Make intervals unprotected since it is the fastest options (does not guarantee soundness) */
typedef gaol::interval gal_I;

