//
// Created by DarsenOP on 2/2/25.
//

/* Varibales & Data Types */

#include <iostream>

int main()
{
    /* Number Systems */
    int number1 = 15; // dec
    int number2 = 017; // oct
    int number3 = 0xF; // hex
    int number4 = 0b1111; // bin

    std::cout << number1 << std::endl;
    std::cout << number2 << std::endl;
    std::cout << number3 << std::endl;
    std::cout << number4 << std::endl;

    /* Integers */
    // Braced Initialization
    // Stores Decimals, typically occupies 4 bytes in memory
    int elephnas_count; // Uninitialized, that is junk data
    int lion_count{}; // Initializes to zero
    int dog_count{5}; // Initializes to five
    int cat_count{10}; // Initializes to ten

    // Can use expressions for initializations
    int domesticated_animal_count{ dog_count + cat_count };

    // Won't compile, the expression in the braces uses undeclared variables
    // int bad_initalization{ doesnt_exist1 + doesnt_exist2 };

    // 2.9 is of type double, with a wider range than int. ERROR
    // int narrowing_conversion{2.9};

    // Functional initialization
    int variable_like_function(); // BAD. Can be confused with function declerations
    int apple_count(5);
    int orange_count(10);

    int fruit_count(apple_count + orange_count);

    // int bad_initalization2{ doesnt_exist3 + doesnt_exist4 };

    // Information lost. Less safe than braced initializer
    int narrowing_conversion_functional(2.8);

    // Assignment initialization
    int bike_count = 5;
    int truck_count = 6;

    int vehicle_count = bike_count + truck_count;

    // int bad_initalization3 = doesnt_exist5 + doesnt_exist6;

    // With assignment initialization narrowing will happen so 2.9 will become 2
    int narrowing_converstion_assignment = 2.9;

    // Size of a type in memory
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(elephnas_count) << std::endl;

    // Integer modifiers
    short short_var {-32768}; // 2 Bytes
    short int short_int {455};
    signed short signed_short {122};
    signed short int signed_short_int {-456};
    unsigned short int unsigned_short_int {456};

    int int_var {55}; // 4 Bytes
    signed signed_var {66};
    signed int signed_int {77};
    unsigned int unsigned_int {77};

    long long_var {88}; // 4 OR 8 Bytes depending on architecture
    long int long_int {33};
    signed long signed_long {44};
    signed long int signed_long_int {-44};
    unsigned long int unsigned_long_int {42};

    long long long_long {888}; // 8 Bytes
    long long int long_long_int {-888};
    signed long long signed_long_long {-88};
    signed long long int signed_long_long_int {-88};
    unsigned long long int unsigned_long_long_int {1234};

    // Fractional numbers
    float float_var {3.14f}; // 4 Bytes, 7 Precision
    double double_var {3.14}; // 8 Bytes, 15 Precision, RECOMMENDED DEFAULT
    long double long_double_var {65.42}; // 12 OR 16 Bytes depending on architecture, > double

    // Scientific notation
    double number5 {1.924e8};
    double number6 {3.498e-11};

    std::cout << number5 << std::endl;
    std::cout << number6 << std::endl;

    // how to get +/- infinity and NaN with floating point numbers
    // n(floating point)/0 ----> +/- infinity
    std::cout << number5 / 0 << std::endl;
    // 0.0/0.0 ----> Nan
    std::cout << (0.0) / (0.0) << std::endl;


    // Booleans
    // True or False
    bool bool_var {true}; // 1 Byte
    std::cout << bool_var << std::endl;

    // Characters and Text
    char character1 {'a'}; // 1 Byte
    char character2 {'r'}; // 1 Byte
    std::cout << character1 << " of size " << sizeof(character1) << std::endl;
    std::cout << character2 << " of size " << sizeof(character2) << std::endl;

    // Assignment with ASCII code
    char value {65};
    std::cout << value << std::endl; // Value corresponding to ASCII code 65
    std::cout << static_cast<int>(value) << std::endl; // The ASCII code itself

    // Auto
    auto var1{12}; // int
    auto var2{13.0}; // double
    auto var3{14.0f}; // float
    auto var4{15.0l}; // long double
    auto var5{'c'}; // char

    // Int modifier suffixes
    auto var6{123u}; // unsigned int
    auto var7{123ul}; // unsigned long
    auto var8{123ull}; // unsigned long long

    std::cout << sizeof(var1) << std::endl;
    std::cout << sizeof(var2) << std::endl;
    std::cout << sizeof(var3) << std::endl;
    std::cout << sizeof(var4) << std::endl;
    std::cout << sizeof(var5) << std::endl;
    std::cout << sizeof(var6) << std::endl;
    std::cout << sizeof(var7) << std::endl;
    std::cout << sizeof(var8) << std::endl;

    // Assignments
    auto age{23u}; // Declare and initialize
    std::cout << age << std::endl;

    age = 25; // Assign
    std::cout << age << std::endl;

    age = -22; // Danger. Thr type of the age is unsigned: no negative values
    std::cout << age << std::endl;

    return 0;
}