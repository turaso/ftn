#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_long_long(Fraction a, const long long& res) {
      assert(static_cast<long long>(a) == res);
      std::cout << a << " == " << static_cast<long long>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr long long
      a = 0ll,
      b = 0ll,
      c = -1ll,
      d = 0ll,
      e = 0ll;
    ftn::test::to_long_long({1, 2}, a);
    ftn::test::to_long_long({true, 1, 2}, b);
    ftn::test::to_long_long({true, 3, 2}, c);
    ftn::test::to_long_long({0}, d);
    ftn::test::to_long_long({true, 0, 1}, e);
  }
}
