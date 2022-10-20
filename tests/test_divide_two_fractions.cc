#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void divide(Fraction&& a, Fraction&& b, Fraction&& res) {
      assert(a / b == res);
      std::cout << "(" << a << ")" << " / " << "(" << b << ")"
        << " == " << (a / b) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    ftn::test::divide({15, 49}, {3, 7}, {5, 7});
    ftn::test::divide({5, 8}, {14, 7}, {35, 112});
    ftn::test::divide({543, 5}, {634, 5}, {543, 634});
    ftn::test::divide({108, 32}, {301, 80}, {270, 301});
    ftn::test::divide({97, 203}, {5, 683}, {66251, 1015});
  }
}
