//
// Created by DarsenOP on 2/2/25.
//

/* References */

#include <iostream>

int main()
{
    // References are just aliases for variables, just another naming, not a type
    int int_value {45};
    double double_value {3.14};

    int& ref_int {int_value}; // Declare and initialize in one statement
    double& ref_double {double_value};

    // Then you can use it as a normal variable
    std::cout << ref_int << std::endl; // value
    std::cout << &ref_int << std::endl; // address

    // The sizes are the same as of a original variable
    std::cout << sizeof(ref_int) << std::endl;
    std::cout << sizeof(ref_double) << std::endl;

    // References VS Pointers
    // References: 1) Do not use dereferencing for reading and writing,
    //             2) Cannot be changed to reference something else,
    //             3) Must be initialized at declaration
    // Pointers: 1) Must go through dereferencing to write and read
    //           2) Can be changed to point something else
    //           3) Can be declared uninitialized, will contain garbage value

    // References are like const pointers, but still there are differences in how we access them
    // We can modify through references. If we want to not be able to do that we can declare it as const
    // It is similar to const int* const pointer
    // No such thing const int& const reference
    // Const applies to the alias not the original

    return 0;
}