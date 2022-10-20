#ifndef FTN_LITERALS_HH_
#define FTN_LITERALS_HH_

#include <ftn/fraction.cc.hh>

namespace ftn {

constexpr Fraction operator"" _ftn (unsigned long long v) {
  return {v};
}

} /// namespace ftn

#endif /// FTN_LITERALS_HH_
