#ifndef FTN_OUTPUT_HH_
#define FTN_OUTPUT_HH_

#include <string>
#include <ostream>

#include <ftn/fraction.hh>

namespace ftn {

// std::string string(const Fraction& f);
template <typename N, typename D>
std::string string(const Fraction_<N, D>& f) {
  if (f.denominator() == 1ull) {
    // return (f.negative() ? "-" : "") + std::to_string(f.whole());
    return (f.negative() ? "-" : "") + std::to_string(f.numerator());
  }
  // if (f.whole() != 0ull) {
    // return (f.negative() ? "-(" : "") + std::to_string(f.whole()) + "," + std::to_string(f.numerator()) + "/" + std::to_string(f.denominator()) + (f.negative() ? ")" : "");
  // }
  return (
      f.negative() ?
          "-(" : "") +
          std::to_string(f.numerator()) +
          "/" + std::to_string(f.denominator()) +
          (f.negative() ? ")" : ""
  );
}

template <typename N, typename D>
std::string to_string(const Fraction_<N, D>& f) {
  return string(f);
}

template <typename N, typename D>
std::ostream& operator<<(std::ostream& out, const Fraction_<N, D>& f) {
  return out << string(f);
}

} /// namespace ftn

#endif /// FTN_OUTPUT_HH_
