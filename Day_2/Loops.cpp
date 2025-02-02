//
// Created by DarsenOP on 2/2/25.
//

/* Loops */

#include <iostream>

int main()
{
    // For loops
    const size_t COUNT {10};
    for (size_t i {0}; i < COUNT; i++) {
        std::cout << "#" << i + 1 << ": I LOVE C++!" << std::endl;
    }

    // While loops
    // COUNT is 10
    size_t i {};

    while (i < COUNT) {
        std::cout << "#" << i + 1 << ": I LOVE C++!" << std::endl;
        i++;
    }

    // do while loops, which runs then checks (not the other way around)
    i = 11;
    do {
        std::cout << "#" << i + 1 << ": I LOVE C++!" << std::endl;
        i++;
    } while (i < COUNT);

    return 0;
}