#ifndef FTN_FRACTION_HH_
#define FTN_FRACTION_HH_

#include <numeric>
#include <concepts>

#include <ftn/util.hh>

namespace ftn {

template <typename T>
concept Unsigned = std::unsigned_integral<T>;

template <
    Unsigned Numerator = unsigned long long,
    Unsigned Denominator = Numerator
> class Fraction_ {
public:
  using numerator_type = Numerator;
  using denominator_type = Denominator;
  constexpr Fraction_() = default;
  template <typename N>
  constexpr Fraction_(const N& _numerator);
  template <typename N, typename D>
  constexpr Fraction_(const N& _numerator, const D& _denominator);
  template <typename N, typename D>
  constexpr Fraction_(
      const bool _negative,
      const N& _numerator,
      const D& _denominator
  );
  // template <typename W, typename N, typename D>
  // constexpr Fraction(const W& _whole, const N& _numerator, const D& _denominator);
  // template <typename W, typename N, typename D>
  // constexpr Fraction(const bool _negative, const W& _whole, const N& _numerator, const D& _denominator);
  constexpr bool negative() const { return negative_; };
  constexpr Numerator whole() const; //?
  constexpr Numerator numerator() const { return numerator_; };
  constexpr Denominator denominator() const { return denominator_; };
  constexpr Fraction_ clone() const;
  constexpr Fraction_& negative(const bool p);
  // template <typename W>
  // constexpr Fraction& whole(const W& w);
  template <typename N>
  constexpr Fraction_& numerator(const N& n);
  template <typename D>
  constexpr Fraction_& denominator(const D& d);
  constexpr bool operator==(const Fraction_& o) const;
  constexpr Fraction_ operator+() const;
  constexpr Fraction_ operator+(const Fraction_& o) const;
  constexpr Fraction_ operator-() const;
  constexpr Fraction_ operator-(const Fraction_& o) const;
  constexpr Fraction_ operator*(const Fraction_& o) const;
  constexpr Fraction_ operator/(const Fraction_& o) const;
  constexpr Fraction_ operator%(const Fraction_& o) const;
  constexpr operator long double() const;
  constexpr operator double() const;
  constexpr operator float() const;
  constexpr operator long long() const;
  constexpr operator unsigned long long() const;
  constexpr operator long() const;
  constexpr operator unsigned long() const;
  constexpr operator int() const;
  constexpr operator unsigned int() const;
  constexpr operator short() const;
  constexpr operator unsigned short() const;
  constexpr operator char() const;
  constexpr operator unsigned char() const;
  constexpr operator bool() const;
protected:
  bool negative_ = false;
  // unsigned long long whole_ = 0; //! !
  Numerator numerator_ = 0;
  Denominator denominator_ = 1;
private:
};

using Fraction0ull1ull = Fraction_<unsigned long long>;
using FractionULL = Fraction_<unsigned long long>;
using Fraction_ull = Fraction_<unsigned long long>;
using Fraction0ull = Fraction0ull1ull;
using Fraction = Fraction0ull;

} /// namespace ftn

#endif /// FTN_FRACTION_HH_
