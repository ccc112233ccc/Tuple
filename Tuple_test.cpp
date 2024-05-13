#include "Tuple.h"

#include <iostream>
#include <string>

int main() {
  using ccutil::Get;
  using ccutil::Tuple;
  Tuple<int, char, std::string> t(1, 'a', "hello");
  std::cout << Get<2>(t) << std::endl;

  Get<2>(t) = "world";
  std::cout << Get<2>(t) << std::endl;

  Tuple<int, char, std::string> t2(1, 'a', "world");
  std::cout << (t == t2) << std::endl;

  return 0;
}