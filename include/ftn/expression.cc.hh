#ifndef FTN_EXPRESSION_CC_HH_
#define FTN_EXPRESSION_CC_HH_

#include <ftn/expression.hh>

namespace ftn {

template <typename T>
constexpr Expression<T>::Expression(const T& value) {
  value_ = value;
}

} /// namespace ftn

#endif /// FTN_EXPRESSION_CC_HH_
