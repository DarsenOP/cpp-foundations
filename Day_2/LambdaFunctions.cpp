//
// Created by DarsenOP on 2/2/25.
//

/* Lambda Functions */

#include <iostream>

int main()
{
    // A mechanism to set up an anonymous functions (without names). Once we have them set up, we can either
    // give them names and call them, or we can even get them to do things directly

    // Giving names
    auto func = []() {
        std::cout << "Hello World!\n";
    };

    func();
    func();

    // Calling directly
    []() {
        std::cout << "Calling Directly!\n";
    }();

    // Returning something
    auto result = [](int a, int b) {
        return (a + b);
    }(2, 5);

    std::cout << "Result of a sum: ";
    std::cout << result << std::endl;

    // Explicitly write down the return type
    auto maxFunc = [](double a, double b)->double {
        return a > b ? a : b;
    };

    double max1{maxFunc(1, 2)};
    double max2{maxFunc(3.25, 4.116)};
    std::cout << max1 << std::endl;
    std::cout << max2 << std::endl;

    // Capture list
    double a{10};
    double b{10};

    // This is capturing by value. SEE LATER
    auto func2 = [a, b]() {
        std::cout << "a + b = " << a + b << std::endl;
    };
    func2();

    // Here we change the captured value - a
    a++;
    func2(); // The sum is still 20, because it's copy value was captures when it was declared, so changing after
             // will not change anything

    // This function is capturing by reference, so that it always refers to the variable and not the copy
    auto func3 = [&]() {
        a++;
        double result{};
        if (a > b) {
            result = a;
        } else {
            result = b;
        }
        std::cout << "max(a, b) = " << result << std::endl;
    };
    func3();

    // Capture all: by value (=) and by reference (&)

    return 0;
}
