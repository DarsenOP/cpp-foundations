//
// Created by arsen on 2/8/25.
//

#include <iostream>
#include <vector>
#include "functional.h"

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> result = filter(v, [](int i){return i%2==0;});

    for (auto& i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<int> map_result = map(v, [](int i){return i + 2;});

    for (auto& i : map_result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}