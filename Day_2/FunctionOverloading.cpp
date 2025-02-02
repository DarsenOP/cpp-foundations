//
// Created by DarsenOP on 2/2/25.
//

/* Function Overloading */

#include <iostream>

int max(int a, int b);
double max(double a, double b);
std::string max(std::string_view a, std::string_view b);

int main()
{
    // To overload we need parameter difference - order, number, types
    int int_value1{41};
    int int_value2{29};

    double double_value1{1.1};
    double double_value2{4.25};

    std::string_view string_value1{"Hello"};
    std::string_view string_value2{"World"};

    std::cout << max(int_value1, int_value2) << std::endl;
    std::cout << max(double_value1, double_value2) << std::endl;
    std::cout << max(string_value1, string_value2) << std::endl;

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

double max(double a, double b)
{
    return a > b ? a : b;
}

std::string max(std::string_view a, std::string_view b)
{
    std::string result;
    if (a > b) {
        result = a;
    } else {
        result = b;
    }

    return result;
}