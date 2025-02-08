//
// Created by DarsenOP on 2/8/25.
//

#include <algorithm>
#include <iostream>
#include <memory>
#include <cassert>
#include <vector>
#include <functional>
#include "Y.h"

class X
{
    int _val;
public:
    explicit X(int v) : _val(v) { std::cout << "X::X" << std::endl; }
    ~X() { std::cout << "X::~X" << std::endl; }

    int get_value() const { return _val; }
};



void func1(X* px)
{
    std::cout << "Entered func1" << std::endl;

    std::cout << px->get_value() << std::endl;

    std::cout << "Leaving func1" << std::endl;

    delete px;
    px = nullptr;
}

void func2(std::unique_ptr<X> px)
{
    std::cout << "Entered func2" << std::endl;

    std::cout << px->get_value() << std::endl;

    std::cout << "Leaving func2" << std::endl;
}

int sum(std::vector<int> v)
{
    int sum{};

    std::ranges::for_each(v.begin(), v.end(), [&sum](const int i) { sum += i; });

    return sum;
}

template <typename T>
T add(T val)
{
    return val;
}

template <typename T, typename... Args>
T add(const T& first, Args... args)
{
    return first + add(args...);
}

int main()
{
    /* Range-based for */

    // Iterate over containers like arrays, strings, and STL containers
    // Can work with custom types
    // No off-by-one error
    // Higher level

    const auto arr = {1, 2, 3};

    for (const auto el : arr) {
        std::cout << el << std::endl;
    }

    /* Smart Pointers */

    // std::unique_pre, std::shared_ptr, std::weak_ptr

    // Without smart pointers
    X *px = new X(5);

    std::cout << "Calling func1" << std::endl;
    func1(px);
    std::cout << "Back from func1" << std::endl;

    // With smart pointer : unique pointer
    std::unique_ptr<X> p2(new X(10));

    std::cout << "Calling func2" << std::endl;
    func2(std::move(p2));
    std::cout << "Back from func2" << std::endl;

    assert(p2 == nullptr);

    /* Lambdas */
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << sum(v) << std::endl;

    /* Move semantics */

    // R-value references
    // Move semantics
    // Make use of temporaries
    // Reduce construction and copying

    Y a(1), b(2);

    Y c; // 3 constructors
    c = b; // op=(Y&), constructor, destructor (of the temporary)

    Y d; // constructor
    d = a + b; // constructor of the object through an + operator overload, destructor of it after returning the rvalue
               // op=(Y&&), destructor fo the temporary and then 4 destructors for a,b,c,d

    /* Functions and Bind */

    std::function<int (int, int)> f = [](int a, int b) { return a + b; };
    std::cout << f(1, 2) << std::endl; // Will display 3

    std::function<int (int)> add3 = std::bind(f, 3, std::placeholders::_1);

    std::cout << add3(1) << std::endl;

    /* Templates */

    std::cout << add(2.4, 1, 3) << std::endl;
    std::cout << add(1, 2.5, 3, '5') << std::endl;

    std::cout << add(std::string("something"), std::string("serious")) << std::endl;

    return 0;
}
