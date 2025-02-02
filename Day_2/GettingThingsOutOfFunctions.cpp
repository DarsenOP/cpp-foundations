//
// Created by DarsenOP on 2/2/25.
//

/* Getting things out of functions */

#include <iostream>

void max_string(const std::string& input1, const std::string& input2, std::string& output);
int sum(int a, int b);
std::string add_strings(std::string input1, std::string input2);

int main()
{
    // Input, output function parameters
    // The output parameter should be passed in such way that you can actually modify it from inside the function
    // References are preferred over pointers
    // Input parameters should not be modifiable from inside the function, you enforce modification restriction with
    // const keyword
    // Again const references can be used

    std::string input1{"Hello World!"};
    std::string input2{"Warden"};
    std::string output{};

    max_string(input1, input2, output);

    std::cout << output << std::endl;

    // Returning from functions (default is by value)
    int a{34};
    int b{16};

    int result = sum(a, b);
    std::cout << "Out : &result(int): " << &result << std::endl;
    std::cout << "Sum : " << result << std::endl;

    // RVO - compiler optimization to return by reference
    std::string str_result = add_strings(std::string("Hello "), std::string("World!"));
    std::cout << "Out : &result(int): " << &str_result << std::endl; // Here the addresses of IN and OUT are the same
    std::cout << "str_result : " << str_result << std::endl;

    return 0;
}

void max_string(const std::string& input1, const std::string& input2, std::string& output)
{
    if (input1 > input2) {
        output = input1;
    } else {
        output = input2;
    }
}

int sum(int a, int b)
{
    int result = a + b;
    std::cout << "In : &result(int): " << &result << std::endl;
    return result;
}

std::string add_strings(std::string input1, std::string input2)
{
    std::string result = input1 + input2;
    std::cout << "In : &result(int): " << &result << std::endl;
    return result;
}