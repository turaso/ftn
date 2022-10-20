#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void unary_minus(Fraction a, Fraction res) {
      assert(-a == res);
      std::cout << "-" << "(" << a << ")" << " == " << (-a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    ftn::test::unary_minus({1, 2}, {-1, 2});
    ftn::test::unary_minus({true, 1, 2}, {1, 2});
    ftn::test::unary_minus({true, 3, 2}, {3, 2});
    ftn::test::unary_minus({0}, {0});
    ftn::test::unary_minus({true, 0, 1}, {0, 1});
  }
}
