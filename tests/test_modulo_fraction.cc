#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void modulo(Fraction a, Fraction b, Fraction res) {
      assert(a % b == res);
      std::cout << "(" << a << ")" << " % " << "(" << b << ")"
        << " == " << (a % b) << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    ftn::test::modulo({15, 49}, {3, 7}, {});
    ftn::test::modulo({5, 8}, {14, 7}, {});
    ftn::test::modulo({543, 5}, {634, 5}, {});
    ftn::test::modulo({108, 32}, {301, 80}, {});
    ftn::test::modulo({97, 203}, {5, 683}, {});
  }
}
