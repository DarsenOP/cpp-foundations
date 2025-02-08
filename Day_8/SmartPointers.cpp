//
// Created by DarsenOP on 2/8/25.
//

#include <iostream>

class Resource
{
public:
    Resource()
    {
        std::cout << "Creating resource" << std::endl;
    }

    ~Resource()
    {
        std::cout << "Destroying resource" << std::endl;
    }

    void do_something()
    {
        std::cout << "Doing something" << std::endl;
    }
};

// First implementation of a smart pointer

template <typename T>
class Ptr
{
    T* _ptr;

    // Prevent copying
    Ptr(const Ptr&);
    Ptr& operator =(const Ptr&);
public:
    explicit Ptr(T* p = 0) : _ptr(p) {}
    ~Ptr() { delete _ptr; }

    T* operator->() const { return _ptr; }
    T& operator*() const { return *_ptr; }
};

template <typename T>
class Ptr2
{
    T* _ptr;

    // Prevent copying
    Ptr2(const Ptr2&);
    Ptr2& operator =(const Ptr2&);
public:
    explicit Ptr2(T* p = 0) : _ptr(p) {}
    ~Ptr2() { delete _ptr; }

    T* operator->()
    {
        if (!_ptr)
            _ptr = new T();

        return _ptr;
    }

    T& operator*()
    {
        if (!_ptr)
            _ptr = new T();

        return *_ptr;
    }
};

int main()
{
    // Without smart pointers

    // Resource *pr = new Resource();
    //
    // pr->do_something();
    //
    // delete pr;

    // With smart pointers - 1

    // Ptr<Resource> pr(new Resource());
    //
    // pr->do_something();

    // With smart pointers - 2

    Ptr2<Resource> pr;

    pr->do_something();

    return 0;
}


