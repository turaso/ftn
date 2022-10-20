#include <ftn/ftn.hxx>

#include <cassert>
#include <iostream>

namespace ftn {
  namespace test {
    void whole(Fraction&& a, unsigned long long&& res) {
      assert(a.whole() == res);
      std::cout << "(" << a << ")" << ".whole() == " << a.whole() << std::endl;
    }
  } /// namespace test
} /// namespace ftn

int main() {
  {
    ftn::test::whole({1, 2}, 0);
    ftn::test::whole({true, 1, 2}, 0);
    ftn::test::whole({true, 3, 2}, 1);
    ftn::test::whole({0}, 0);
    ftn::test::whole({true, 0, 1}, 0);
    ftn::test::whole({2}, 2);
    ftn::test::whole({-2}, 2);
    ftn::test::whole({8, 2}, 4);
    ftn::test::whole({-8, 2}, 4);
    ftn::test::whole({8, -2}, 4);
  }
}
