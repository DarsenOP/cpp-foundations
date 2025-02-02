//
// Created by DarsenOP on 2/2/25.
//

/* Operation on Data */

#include <iostream>
#include <ios>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
    // Basic operations
    int number1 {31};
    int number2 {10};

    // Addition
    std::cout << number1 + number2 << std::endl;
    // Subtraction
    std::cout << number1 - number2 << std::endl;
    // Multiplication
    std::cout << number1 * number2 << std::endl;
    // Division (without the fractional part)
    std::cout << number1 / number2 << std::endl;
    // Modulus
    std::cout << number1 % number2 << std::endl;

    // Precedence and Associativity

    // Prefix and Postfix + and -
    int value {5};
    // Increment by one
    value = value + 1;
    std::cout << value << std::endl;

    // Reset value
    value = 5;

    // Decrement by one
    value = value - 1;
    std::cout << value << std::endl;

    value = 5;

    // Increment with postfix
    std::cout << value++ << std::endl; // Print then increment: 5
    std::cout << value << std::endl; // After increment: 6

    value = 5;

    // Decrement with postfix
    std::cout << value-- << std::endl; // Print then decrement: 5
    std::cout << value << std::endl; // After decrement: 4

    value = 5;

    // Increment with prefix
    std::cout << ++value << std::endl; // Increment then display: 6

    value = 5;

    // Decrement with prefix
    std::cout << --value << std::endl; // Decrement then display: 4

    // Compound operators : variable (operator)= value ---> variable = variable (operator) value
    value = 5;
    value += 5;
    std::cout << value << std::endl;
    value -= 5;
    std::cout << value << std::endl;
    value *= 5;
    std::cout << value << std::endl;
    value /= 5;
    std::cout << value << std::endl;
    value %= 5;
    std::cout << value << std::endl;

    // Relational operators: >, <, >=, <=, ==, !=
    // Logical operators: &&, ||, ! (And, Or, Not)
    // Output Formatting
    bool bool_value {true};
    std::cout << bool_value << std::endl; // This will print (1/0)
    std::cout << std::boolalpha << bool_value << std::endl; // This will print with words (true/false)
    std::cout << std::noboolalpha << bool_value << std::endl; // Resets to defaults

    int int_value {10};
    // Use of different numberical systems: dec(10), hex(16), oct(8)
    std::cout << int_value << std::endl;
    std::cout << std::hex << std::showbase << int_value << std::endl; // Show the base of a number when displaying in other systems
    std::cout << std::oct << std::noshowbase << int_value << std::endl; // Resets to defaults
    std::cout << std::dec << int_value << std::endl; // Again in decimal

    int neg_value {-1};
    std::cout << neg_value << std::endl; // When negative - sign is displayed
    std::cout << int_value << std::endl; // Which is not true for positive numbers
    std::cout << std::showpos << int_value << std::endl; // This will allow to display + sign too
    std::cout << std::noshowpos << int_value << std::endl; // Back to defaults

    // Use of uppercase characters in hex and floating numbers
    float float_value {3.14e26};
    std::cout << std::uppercase << float_value << std::endl;
    std::cout << std::hex << std::showbase << std::uppercase << int_value << std::endl;
    std::cout << std::dec << std::noshowbase << std::nouppercase << int_value
              << " " << float_value << std::endl; // Back to defaults

    // Placement of fill characters: internal, left, right
    // Default, right placement
    std::cout << std::setw(15) << -1.12 << "\n"
              << std::setw(15) << 42 << "\n"
              << std::setw(15) << "Arsen" << "\n";
    // Left placement
    std::cout << std::left;
    std::cout << std::setw(15) << -1.12 << "\n"
              << std::setw(15) << 42 << "\n"
              << std::setw(15) << "Arsen" << "\n";
    // Internal placement: - sign goes to the left, but the text is on default
    std::cout << std::internal;
    std::cout << std::setw(15) << -1.12 << "\n"
              << std::setw(15) << 42 << "\n"
              << std::setw(15) << "Arsen" << "\n";

    // Default formatting of floating numbers
    std::cout << std::scientific << std::setprecision(5) << float_value << std::endl; // Scientific
    std::cout << std::fixed << std::setprecision(5) << float_value << std::endl; // Fixed
    std::cout << std::defaultfloat << float_value << std::endl; // Default

    // std::setw(x) for setting the width of the next output field
    // std::setprecision(x) for setting floating point precision
    // std::setfill(char) to fill the blank spaces with char

    // Numeric limits
    std::cout << std::numeric_limits<double>::max() << std::endl; // Maximum possible
    std::cout << std::numeric_limits<double>::min() << std::endl; // Minimal that is > 0
    std::cout << std::numeric_limits<double>::lowest() << std::endl; // Lowest possible

    // Math functions: abs, exp(power of e), log(base is e), log10(base is 10), log2(base is 2), pow, sqrt,
    //                 sin, cos, tan, asin, acos, atan, ceil, floor, round,

    // Weird integral types: types less than 4 bytes do not support arithmetic operations


    return 0;
}