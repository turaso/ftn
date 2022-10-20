#ifndef FTN_FRACTION_CC_HH_
#define FTN_FRACTION_CC_HH_

#include <ftn/fraction.hh>

#include <iostream>
#include <algorithm>

namespace ftn {

template <Unsigned Numerator, Unsigned Denominator>
template <typename N>
constexpr Fraction_<Numerator, Denominator>::Fraction_(const N& _numerator) {
  if (_numerator < 0) {
    negative_ = true;
    numerator_ = static_cast<unsigned long long>(-_numerator);
  } else {
    numerator_ = static_cast<unsigned long long>(_numerator);
  }
}

template <Unsigned Numerator, Unsigned Denominator>
template <typename N, typename D>
constexpr Fraction_<Numerator, Denominator>::Fraction_(
    const N& _numerator,
    const D& _denominator
) {
  if (_numerator != 0ull) {
    // const unsigned long long numerator = std::abs(_numerator);
    const unsigned long long numerator = _numerator < 0 ?
      static_cast<unsigned long long>(-_numerator)
      : static_cast<unsigned long long>(_numerator);
    // const unsigned long long denominator = std::abs(_denominator);
    const unsigned long long denominator = _denominator < 0 ?
      static_cast<unsigned long long>(-_denominator)
      : static_cast<unsigned long long>(_denominator);
    const auto gcd = std::gcd(numerator, denominator);
    numerator_ = numerator / gcd;
    denominator_ = denominator / gcd;
    negative_ = (_numerator < 0) != (_denominator < 0);
  }
}

template <Unsigned Numerator, Unsigned Denominator>
template <typename N, typename D>
constexpr Fraction_<Numerator, Denominator>::Fraction_(
    const bool _negative,
    const N& _numerator,
    const D& _denominator
) : Fraction_(_negative ?
        -static_cast<long long>(_numerator) :
        static_cast<long long>(_numerator),
    _denominator) {}

//template <typename Numerator, typename Denominator>
// template <typename W, typename N, typename D>
// constexpr Fraction::Fraction(const W& _whole, const N& _numerator, const D& _denominator)
//   : Fraction(_whole * _denominator + _numerator, _denominator) {}

//template <typename Numerator, typename Denominator>
// template <typename W, typename N, typename D>
// constexpr Fraction::Fraction(const bool _negative, const W& _whole, const N& _numerator, const D& _denominator)
//   : Fraction(_negative, _whole * _denominator + _numerator, _denominator) {}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Numerator Fraction_<Numerator, Denominator>::whole() const {
  return numerator_ / denominator_;
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>
Fraction_<Numerator, Denominator>::clone() const {
  return {*this};
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>&
Fraction_<Numerator, Denominator>::negative(const bool p) {
  negative_ = p;
  return *this;
}

//template <typename Numerator, typename Denominator>
// template <typename W>
// constexpr Fraction& Fraction::whole(const W& w) {
//   const auto tmp = static_cast<unsigned long long>(w);
//   if (tmp < 0) {
//     negative = !negative;
//     whole_ = -tmp;
//   } else {
//     whole_ = tmp;
//   }
//   return *this;
// }

template <Unsigned Numerator, Unsigned Denominator>
template <typename N>
constexpr Fraction_<Numerator, Denominator>&
Fraction_<Numerator, Denominator>::numerator(const N& n) {
  // const auto tmp = static_cast<unsigned long long>(n) + whole_ * denominator_ * (negative_ ? -1 : 1);
  // const auto gcd = std::gcd(tmp, denominator_);
  // const auto reduced = numerator / gcd;
  // denominator_ = denominator / gcd;
  // numerator_ = reduced % denominator_;
  // whole_ = reduced / denominator_;
  // negative_ = (n < 0);
  const unsigned long long numerator = n < 0 ?
    static_cast<unsigned long long>(-n)
    : static_cast<unsigned long long>(n);
  const auto gcd = std::gcd(numerator, denominator_);
  numerator_ = numerator / gcd;
  denominator_ = denominator_ / gcd;
  negative_ = ((n < 0) != negative_);
  return *this;
}

template <Unsigned Numerator, Unsigned Denominator>
template <typename D>
constexpr Fraction_<Numerator, Denominator>&
Fraction_<Numerator, Denominator>::denominator(const D& d) {
  // const auto tmp = static_cast<unsigned long long>(d);
  // denominator_ =
  const unsigned long long denominator = d < 0 ?
    static_cast<unsigned long long>(-d)
    : static_cast<unsigned long long>(d);
  const auto gcd = std::gcd(numerator_, denominator);
  numerator_ = numerator_ / gcd;
  denominator_ = denominator / gcd;
  negative_ = (negative_ != (d < 0));
  return *this;
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr bool
Fraction_<Numerator, Denominator>::operator==(const Fraction_& o) const {
  return negative() == o.negative() &&
    // whole() == o.whole() &&
    numerator() == o.numerator() &&
    denominator() == o.denominator();
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>
Fraction_<Numerator, Denominator>::operator+() const {
  return this->clone();
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>
Fraction_<Numerator, Denominator>::operator+(const Fraction_& o) const {
  // const auto n1 = (
  //   negative() ?
  //   -static_cast<long long>(whole() * denominator() + numerator()) :
  //   static_cast<long long>(whole() * denominator() + numerator())
  // ) * static_cast<long long>(o.denominator());
  // const auto n2 = (
  //   o.negative() ?
  //   -static_cast<long long>(o.whole() * o.denominator() + o.numerator()) :
  //   static_cast<long long>(o.whole() * o.denominator() + o.numerator())
  // ) * static_cast<long long>(denominator());
  // return { n1 + n2, denominator() * o.denominator(), };
  const auto lcm = std::lcm(denominator_, o.denominator_);
  // return { (negative_ ? -1 : +1) * lcm / denominator_ * numerator_ + (o.negative_ ? -1 : +1) * lcm / o.denominator_ * o.numerator_, lcm, };
  const auto left = lcm / denominator_;
  const auto right = lcm / o.denominator_;
  const long long lnum = (negative_ ? -1 : 1) * left * numerator_;
  const long long rnum = (o.negative_ ? -1 : 1) * right * o.numerator_;
  const auto numerator = lnum + rnum;
  return { numerator, lcm, };
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>
Fraction_<Numerator, Denominator>::operator-() const {
  // if (whole_ * denominator_ + numerator_ == 0) {
  if (numerator_ == 0) {
    return this->clone();
  }
  return this->clone().negative(!negative_);
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>
Fraction_<Numerator, Denominator>::operator-(const Fraction_& o) const {
  return { *this + (-(o.clone())) };
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>
Fraction_<Numerator, Denominator>::operator*(const Fraction_& o) const {
  // return { negative() != o.negative(), (whole() * denominator() + numerator()) * (o.whole() * o.denominator() + o.numerator()), denominator() * o.denominator(), };
  return {
    negative() != o.negative(),
    numerator_ * o.numerator_,
    denominator_ * o.denominator_,
  };
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>
Fraction_<Numerator, Denominator>::operator/(const Fraction_& o) const {
  // return { negative() != o.negative(), (whole() * denominator() + numerator()) * o.denominator(), denominator() * (o.whole() * o.denominator() + o.numerator()), };
  return {
    negative() != o.negative(),
    numerator_ * o.denominator_,
    denominator_ * o.numerator_,
  };
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>
Fraction_<Numerator, Denominator>::operator%(const Fraction_& o) const {
  return {};
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator long double() const {
  // return (negative_ ? -1 : 1) * (static_cast<long double>(numerator_) / denominator_ + whole_);
  return (negative_ ? -1 : 1) *
      (static_cast<long double>(numerator_) / denominator_);
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator double() const {
  return static_cast<double>(this->operator long double());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator float() const {
  return static_cast<float>(this->operator long double());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator long long() const {
  return static_cast<long long>(this->operator long double());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator
unsigned long long() const {
  return static_cast<unsigned long long>(this->operator long long());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator long() const {
  return static_cast<long>(this->operator long double());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator unsigned long() const {
  return static_cast<unsigned long>(this->operator long());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator int() const {
  return static_cast<int>(this->operator long double());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator unsigned() const {
  return static_cast<unsigned>(this->operator int());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator short() const {
  return static_cast<short>(this->operator long double());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator unsigned short() const {
  return static_cast<unsigned short>(this->operator short());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator char() const {
  return static_cast<char>(this->operator long double());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator unsigned char() const {
  return static_cast<unsigned char>(this->operator char());
}

template <Unsigned Numerator, Unsigned Denominator>
constexpr Fraction_<Numerator, Denominator>::operator bool() const {
  return static_cast<bool>(this->operator long double());
}

} /// namespace ftn

#endif /// FTN_FRACTION_CC_HH_
