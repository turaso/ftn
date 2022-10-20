#ifndef FTN_EXPRESSION_HH_
#define FTN_EXPRESSION_HH_

#include <ftn/fraction.hh>

namespace ftn {

template <typename T>
class Expression {
public:
  constexpr Expression() = default;
  constexpr Expression(const T& value);
protected:
private:
  T value_;
};

} /// namespace ftn

#endif /// FTN_EXPRESSION_HH_
