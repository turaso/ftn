#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_long(Fraction a, const long& res) {
      assert(static_cast<long>(a) == res);
      std::cout << a << " == " << static_cast<long>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr long
      a = 0l,
      b = 0l,
      c = -1l,
      d = 0l,
      e = 0l;
    ftn::test::to_long({1, 2}, a);
    ftn::test::to_long({true, 1, 2}, b);
    ftn::test::to_long({true, 3, 2}, c);
    ftn::test::to_long({0}, d);
    ftn::test::to_long({true, 0, 1}, e);
  }
}
