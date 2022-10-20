#ifndef FTN_UTIL_HH_
#define FTN_UTIL_HH_

#include <cmath>
#include <string>


namespace ftn {

namespace util {

// template <typename T>
// const long long lnm(const T& num) {
//   const auto str = std::to_string(num);
//   std::size_t count = 0;
//   bool dotted = false;
//   long long n = 0;
//   for (int i = 0; i < str.length(); i++) {
//     if (str[i] != '.') {
//       n = n * 10 + (str[i] - '0');
//       if (dotted) {
//         count++;
//       }
//     } else {
//       dotted = true;
//     }
//   }
//   if (!dotted) {
//     return 1;
//   }
//   return static_cast<long long>(std::pow(10, count));
// }

template <typename T, typename D>
constexpr unsigned long long lnm(T& n, D& d) {
  auto nCopy = n;
  auto dCopy = d;
  auto count = 0;
  while (nCopy != static_cast<long long>(nCopy)
      || dCopy != static_cast<long long>(dCopy)) {
    nCopy *= 10;
    dCopy *= 10;
    count++;
  }
  return count;
}

} /// namespace util

} /// namespace ftn

#endif /// FTN_UTIL_HH_
