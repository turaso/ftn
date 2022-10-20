#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_unsigned(Fraction a, const unsigned& res) {
      assert(static_cast<unsigned>(a) == res);
      std::cout << a << " == " << static_cast<unsigned>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr unsigned
      a = 0u,
      b = 0u,
      c = -1u,
      d = 0u,
      e = 0u;
    ftn::test::to_unsigned({1, 2}, a);
    ftn::test::to_unsigned({true, 1, 2}, b);
    ftn::test::to_unsigned({true, 3, 2}, c);
    ftn::test::to_unsigned({0}, d);
    ftn::test::to_unsigned({true, 0, 1}, e);
  }
}
