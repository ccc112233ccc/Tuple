# Tuple

## Description
仿照STL中的tuple，实现一个tuple类。

## Usage
```cpp
#include "Tuple.h"
#include <iostream>

int main() {
    using ccutil::Tuple;
    using ccutil::Get;
    Tuple<int, double, std::string> t(1, 3.14, "hello");
    std::cout << t.get<0>() << std::endl;
    std::cout << t.get<1>() << std::endl;
    std::cout << t.get<2>() << std::endl;

    Get<2>(t) = "world";
    std::cout << t.get<2>() << std::endl;

    Tuple<int, char, std::string> t2(1, 'a', "world");
    std::cout << (t == t2) << std::endl;

    return 0;
}
```