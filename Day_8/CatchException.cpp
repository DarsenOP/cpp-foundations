//
// Created by arsen on 2/8/25.
//


#include "result.h"

Result<int, std::string> divide(const int& a, const int& b)
{
    if (b == 0)
        return Result<int, std::string>("Division by zero!");

    return Result<int, std::string>(a / b);
}

int main()
{
    // Catching the exceptions by ourselves

    Result<int, std::string> result1 = divide(10, 2);
    if (result1.is_valid()) {
        std::cout << "Result: " << result1.get_value() << std::endl;
    }

    Result<int, std::string> result2 = divide(10, 0);
    if (!result2.is_valid()) {
        std::cout << "Error: " << result2.get_exception() << std::endl;
    }
}