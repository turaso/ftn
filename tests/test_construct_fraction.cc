#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    template <typename N, typename D>
    void construct(Fraction&& a, bool&& p, N&& n, D&& d) {
      assert(a.negative() == p);
      // static_assert(a.whole() == w);
      assert(a.numerator() == n);
      assert(a.denominator() == d);
      std::cout << a << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    ftn::test::construct({1, 2}, false, 1, 2);
    ftn::test::construct({1, -2}, true, 1, 2);
    ftn::test::construct({-1, 2}, true, 1, 2);
    ftn::test::construct({-1, -2}, false, 1, 2);
    ftn::test::construct({2, 1}, false, 2, 1);
    ftn::test::construct({2, -1}, true, 2, 1);
    ftn::test::construct({-2, 1}, true, 2, 1);
    ftn::test::construct({-2, -1}, false, 2, 1);
    ftn::test::construct({0}, false, 0, 1);
    ftn::test::construct({-0}, false, 0, 1);
    ftn::test::construct({0, 1}, false, 0, 1);
    ftn::test::construct({-0, 1}, false, 0, 1);
    ftn::test::construct({-0, -1}, false, 0, 1);
    ftn::test::construct({0, -1}, false, 0, 1);
    ftn::test::construct({true, 0, 1}, false, 0, 1);
    ftn::test::construct({false, 0, 1}, false, 0, 1);
    ftn::test::construct({true, -0, 1}, false, 0, 1);
    ftn::test::construct({false, -0, 1}, false, 0, 1);
    ftn::test::construct({true, -0, -1}, false, 0, 1);
    ftn::test::construct({false, -0, -1}, false, 0, 1);
    ftn::test::construct({true, 0, -1}, false, 0, 1);
    ftn::test::construct({false, 0, -1}, false, 0, 1);
    ftn::test::construct({0, 2}, false, 0, 1);
    ftn::test::construct({-0, 2}, false, 0, 1);
    ftn::test::construct({0, -2}, false, 0, 1);
    ftn::test::construct({-0, -2}, false, 0, 1);
  }
}
