#include <ftn/ftn.hxx>
#include <iostream>

int main(int argc, char **argv) {
  const ftn::Fraction a = {0u, -9};
  const ftn::Fraction b = {4, 3};
  std::cout << a << std::endl;
}
