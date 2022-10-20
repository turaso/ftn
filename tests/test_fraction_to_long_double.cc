#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_long_double(Fraction a, const long double& res) {
      assert(static_cast<long double>(a) == res);
      std::cout << a << " == " << static_cast<long double>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr long double
      a = 0.5l,
      b = -0.5l,
      c = -1.5l,
      d = 0.l,
      e = 0.l;
    ftn::test::to_long_double({1, 2}, a);
    ftn::test::to_long_double({true, 1, 2}, b);
    ftn::test::to_long_double({true, 3, 2}, c);
    ftn::test::to_long_double({0}, d);
    ftn::test::to_long_double({true, 0, 1}, e);
  }
}
