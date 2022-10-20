#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void multiply(Fraction a, Fraction b, Fraction res) {
      assert(a * b == res);
      std::cout << "(" << a << ")" << " * " << "(" << b << ")"
        << " == " << (a * b) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    ftn::test::multiply({1, 3}, {3, 1}, {1, 1});
    ftn::test::multiply({1, 12}, {2}, {1, 6});
    ftn::test::multiply({3}, {1}, {3});
    ftn::test::multiply({true, 25, 68}, {16, 13}, {true, 100, 221});
    ftn::test::multiply({true, 127, 343}, {true, 238, 192}, {2159, 4704});
  }
}
