#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void to_char(Fraction&& a, const char& res) {
      assert(static_cast<char>(a) == res);
      std::cout << a << " == " << static_cast<char>(res) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    static constexpr char
      a = 0,
      b = 0,
      c = -1,
      d = 0,
      e = 0;
    ftn::test::to_char({1, 2}, a);
    ftn::test::to_char({true, 1, 2}, b);
    ftn::test::to_char({true, 3, 2}, c);
    ftn::test::to_char({0}, d);
    ftn::test::to_char({true, 0, 1}, e);
  }
}
