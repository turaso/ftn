#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_bool(Fraction&& a, const bool& res) {
      assert(static_cast<bool>(a) == res);
      std::cout << a << " == " << static_cast<bool>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr bool
      a = true,
      b = true,
      c = true,
      d = false,
      e = false;
    ftn::test::to_bool({1, 2}, a);
    ftn::test::to_bool({true, 1, 2}, b);
    ftn::test::to_bool({true, 3, 2}, c);
    ftn::test::to_bool({0}, d);
    ftn::test::to_bool({true, 0, 1}, e);
  }
}
