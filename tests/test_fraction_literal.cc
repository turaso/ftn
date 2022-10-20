#include <ftn/ftn.hxx>

using ftn::operator""_ftn;

int main() {
  static_assert(1_ftn .numerator() == 1);
  static_assert(1_ftn .denominator() == 1);
  static_assert(1_ftn .negative() == false);
  static_assert(1_ftn .whole() == 1);
}
