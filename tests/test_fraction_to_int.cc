#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_int(Fraction a, const int& res) {
      assert(static_cast<int>(a) == res);
      std::cout << a << " == " << static_cast<int>(a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr int
      a = 0,
      b = 0,
      c = -1,
      d = 0,
      e = 0;
    ftn::test::to_int({1, 2}, a);
    ftn::test::to_int({true, 1, 2}, b);
    ftn::test::to_int({true, 3, 2}, c);
    ftn::test::to_int({0}, d);
    ftn::test::to_int({true, 0, 1}, e);
  }
}
