#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void substract(Fraction a, Fraction b, Fraction res) {
      assert(a - b == res);
      std::cout << "(" << a << ")" << " - " << "(" << b << ")"
        << " == " << (a - b) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    ftn::test::substract({1, 2}, {1, 2}, {0});
    ftn::test::substract({true, 1, 2}, {1, 2}, {-1});
    ftn::test::substract({true, 3, 2}, {1, 2}, {-2});
    ftn::test::substract({5, 14}, {true, 10, 14}, {15, 14});
    ftn::test::substract({true, 5, 9}, {true, 7, 9}, {2, 9});
  }
}
