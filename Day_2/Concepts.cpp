//
// Created by DarsenOP on 2/2/25.
//

/* Concepts */

#include <iostream>

template <typename T>
requires std::integral<T> // Syntax 1, also can be used with std::is_integral<T>, which is a type trait
T add(T a, T b)
{
    return a + b;
}

template <std::integral T> // Syntax 2
T add2(T a, T b)
{
    return a + b;
}

auto add3(std::integral auto a, std::integral auto b) // Syntax 3 with auto
{
    return a + b;
}

template <typename T> // Syntax 4
T add4(T a, T b) requires std::integral<T>
{
    return a + b;
}

template <typename T>
concept Integral = std::is_integral_v<T>;

template <typename T>
concept Incrementable = requires(T a)
{
    a++;
    ++a;
    a+=1;
};

template <typename T>
void increment(T a) requires Incrementable<T>
{
    a++;
    std::cout << "Increment: " << a << std::endl;
    ++a;
    std::cout << "Increment: " << a << std::endl;
    a+=1;
    std::cout << "Increment: " << a << std::endl;
}

template <typename T>
concept TinyType = requires(T a)
{
    sizeof(T) <= 4; // Simple
    requires sizeof(T) <= 4; // Nested
};

template <typename T>
concept IntAddable = requires(T a, T b)
{
    {a + b} -> std::convertible_to<int>;
};

template <typename T>
void IsSmall(T x) requires TinyType<T>
{
    std::cout << sizeof(T) << std::endl;
}

template <IntAddable T>
T add5(T a, T b)
{
    return a + b;
}

int main()
{
    // A mechanism to place constraints on the template
    // Similar static_assert and type traits

    // Standard, built in concepts
    // Custom concepts: there are again few syntaxes: 1) using type traits, 2) other way
    int a{1};
    increment(a);

    double b{2.52};
    increment(b);

    char c{'a'};
    increment(c);

    int* pointer{new int[5]{}};
    increment(pointer);
    delete[] pointer;
    pointer = nullptr;

    // Requires clause can take 4 kinds of requirements:
    // 1) Simple requirements (like syntax checking)
    // 2) Nested requirements (checking the truth of an expression)
    // 3) Compound requirements (forcing expression return type)
    // 4) Type requirements ()

    char d{};
    IsSmall(d);

    double x {54};
    double y {24.32};
    std::cout << add5(x, y) << std::endl;

    // We can also enforce concepts on variables or return types which is not really required

    return 0;
}