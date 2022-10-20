#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_unsigned_long(Fraction a, const unsigned long& res) {
      assert(static_cast<unsigned long>(a) == res);
      std::cout << a << " == " << static_cast<unsigned long>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr unsigned long
      a = 0ul,
      b = 0ul,
      c = -1ul,
      d = 0ul,
      e = 0ul;
    ftn::test::to_unsigned_long({1, 2}, a);
    ftn::test::to_unsigned_long({true, 1, 2}, b);
    ftn::test::to_unsigned_long({true, 3, 2}, c);
    ftn::test::to_unsigned_long({0}, d);
    ftn::test::to_unsigned_long({true, 0, 1}, e);
  }
}
