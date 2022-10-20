#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_short(Fraction a, const short& res) {
      assert(static_cast<short>(a) == res);
      std::cout << a << " == " << static_cast<short>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr short
      a = 0,
      b = 0,
      c = -1,
      d = 0,
      e = 0;
    ftn::test::to_short({1, 2}, a);
    ftn::test::to_short({true, 1, 2}, b);
    ftn::test::to_short({true, 3, 2}, c);
    ftn::test::to_short({0}, d);
    ftn::test::to_short({true, 0, 1}, e);
  }
}
