#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_float(Fraction a, const float& res) {
      assert(static_cast<float>(a) == res);
      std::cout << a << " == " << static_cast<float>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr float
      a = 0.5f,
      b = -0.5f,
      c = -1.5f,
      d = 0.f,
      e = 0.f;
    ftn::test::to_float({1, 2}, a);
    ftn::test::to_float({true, 1, 2}, b);
    ftn::test::to_float({true, 3, 2}, c);
    ftn::test::to_float({0}, d);
    ftn::test::to_float({true, 0, 1}, e);
  }
}
