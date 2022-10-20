# ftn

### Description

ftn is a fractions library

### Features

- addition
- substraction
- multiplication
- division
- modulo
- cast to basic types (double, int, etc.)
- equality comparison
- negative numbers support

### Usage

##### Example

```c++
#include <ftn/ftn.hxx>

using ftn::operator""_ftn;

int main() {
    // const auto a = ftn::Fraction(3, 5); /// 3/5
    const auto a = 3_ftn / 5; /// 3/5
    // const auto b = ftn::Fraction(true, 10, 9); /// -10/9
    const auto b = -10_ftn / 9; /// -10/9
    const auto result = a * b; /// -2/3
}
```
