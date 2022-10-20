#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void add(Fraction&& a, Fraction&& b, Fraction&& res) {
      assert(a + b == res/*, ftn::to_string(a + b)*/);
      std::cout << "(" << a << ")" << " + " << "(" << b << ")"
        << " == " << (a + b) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    ftn::test::add({1, 2}, {1, 2}, {1});
    ftn::test::add({true, 1, 2}, {1, 2}, {0});
    ftn::test::add({true, 3, 2}, {1, 2}, {-1});
    ftn::test::add({true, 5, 14}, {10, 14}, {5, 14});
    ftn::test::add({5, 9}, {true, 7, 9}, {true, 2, 9});
  }
}
