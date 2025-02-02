//
// Created by DarsenOP on 2/2/25.
//

/* Functions */

#include <iostream>
#include <string>

double GetMax(double a, double b)
{
    return a > b ? a : b;
}

void DisplayNumber(int a)
{
    std::cout << a << std::endl;
    return;
}

void ChangeArguments(int a, std::string b)
{
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a++;
    b[0] = '=';
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return;
}

double GetSum(double a, double b); // This is also called prototype
// Prototypes should come before the function is called

void say_age_value(int age);
void say_age_pointer(int* age);
void say_age_reference(int& age);

int main()
{
    // Definitions cannot show up more than once in the whole program, or TU
    // One Definition Rule context:
    // - Free standing variables
    // - Functions
    // - Classes
    // - Class member functions
    // - Class static member variables

    // Function example - function signature is the name + arguments, not the return type
    double a{12.52};
    double b{25.62};
    double c{GetMax(a, b)};
    std::cout << "Max: " << c << std::endl;

    // There is an implicit conversion in the functions
    DisplayNumber(2.5);

    // Argument scope: COPIES, that is the values are copied so in side the function you will not modify the original
    // variable, but the copies of the arguments
    int x {5};
    std::string y {"arsen"};
    ChangeArguments(x, y);
    std::cout << "Original " << x << std::endl;
    std::cout << "Original " << y << std::endl; // The original ones haven't changed

    // You can separate the implementation and the declaration of the function
    double sum {GetSum(a, b)};
    std::cout << "Sum: " << sum << std::endl;

    // Functions across multiple files
    // How c++ makes the executable:
    // 1) Preprocessing, where all the headers get replaced by the actual code of that header. Those files are called TU
    // 2) Compilation, where all TUs get compiled and new binaries are created for each TU called Objects
    // 3) Linking, in the last step the Linker takes all the objects and connects them into one executable, which we run
    // ODR for functions : The same function implementation cannot show up in the global namespace more than once
    // The linker searches for definitions in all TUs

    // Argument passing by value
    int age{23};

    std::cout << "age - before : " << age << std::endl;
    say_age_value(age); // The original values do not change, because the arguments get copied and then we modify them
    std::cout << "age - after : " << age << std::endl;

    // Argument passing by pointers
    std::cout << "age - before : " << age << std::endl;
    say_age_pointer(&age); // Here we pass the address so that we actually modify the value inside the variable and not copy
    std::cout << "age - after : " << age << std::endl;

    // Argument passing by reference
    std::cout << "age - before : " << age << std::endl;
    say_age_reference(age); // Here we pass the value, and function takes the reference of it and actually changes it
    std::cout << "age - after : " << age << std::endl;

    return 0;
}

double GetSum(double a, double b)
{
    return a + b;
}

void say_age_value(int age)
{
    ++age;
    std::cout << "Hello! You are " << age << " years old !" << std::endl;
}

void say_age_pointer(int* age)
{
    ++(*age);
    std::cout << "Hello! You are " << *age << " years old !" << std::endl;
}

void say_age_reference(int& age)
{
    ++age;
    std::cout << "Hello! You are " << age << " years old !" << std::endl;
}