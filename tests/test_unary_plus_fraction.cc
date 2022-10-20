#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void unary_plus(Fraction a, Fraction res) {
      assert(+a == res);
      std::cout << "+" << "(" << a << ")" << " == " << (+a) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    ftn::test::unary_plus({1, 2}, {1, 2});
    ftn::test::unary_plus({true, 1, 2}, {true, 1, 2});
    ftn::test::unary_plus({true, 3, 2}, {true, 3, 2});
    ftn::test::unary_plus({0}, {0});
    ftn::test::unary_plus({true, 0, 1}, {0, 1});
  }
}
