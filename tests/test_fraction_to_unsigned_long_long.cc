#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_unsigned_long_long(Fraction a, const unsigned long long& res) {
      assert(static_cast<unsigned long long>(a) == res);
      std::cout << a << " == " << static_cast<unsigned long long>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr unsigned long long
      a = 0ull,
      b = 0ull,
      c = -1ull,
      d = 0ull,
      e = 0ull;
    ftn::test::to_unsigned_long_long({1, 2}, a);
    ftn::test::to_unsigned_long_long({true, 1, 2}, b);
    ftn::test::to_unsigned_long_long({true, 3, 2}, c);
    ftn::test::to_unsigned_long_long({0}, d);
    ftn::test::to_unsigned_long_long({true, 0, 1}, e);
  }
}
