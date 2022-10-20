#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_double(Fraction a, const double& res) {
      assert(static_cast<double>(a) == res);
      std::cout << a << " == " << static_cast<double>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr double
      a = 0.5,
      b = -0.5,
      c = -1.5,
      d = 0.,
      e = 0.;
    ftn::test::to_double({1, 2}, a);
    ftn::test::to_double({true, 1, 2}, b);
    ftn::test::to_double({true, 3, 2}, c);
    ftn::test::to_double({0}, d);
    ftn::test::to_double({true, 0, 1}, e);
  }
}
