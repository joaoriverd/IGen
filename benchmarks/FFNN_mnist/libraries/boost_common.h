#pragma once
#include <boost/numeric/interval.hpp>

using namespace boost::numeric;
using namespace boost::numeric::interval_lib;

/* Make intervals unprotected since it is the fastest options (does not guarantee soundness) */
//typedef unprotect<interval<double>>::type  bst_I;
//typedef interval<double, policies<save_state<rounded_transc_std<double> >, checking_base<double> > >  bst_I;
typedef unprotect<interval<double, policies<save_state_nothing<rounded_transc_opp<double> >, checking_base<double> > >>::type bst_I;

