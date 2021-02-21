#pragma once
#include <boost/numeric/interval.hpp>

using namespace boost;
//using namespace boost::numeric::interval_lib;

/* Make intervals unprotected since it is the fastest options (does not guarantee soundness) */
typedef boost::numeric::interval_lib::unprotect<boost::numeric::interval<double>>::type  f64i_bst;
//typedef interval<double, policies<save_state<rounded_transc_std<double> >, checking_base<double> > >  f64i_bst;
//typedef interval<double, policies<save_state_nothing<rounded_transc_exact<double> >, checking_base<double> > >  f64i_bst;

