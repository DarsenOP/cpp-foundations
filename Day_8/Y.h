//
// Created by arsen on 2/8/25.
//

#ifndef Y_H
#define Y_H

#include <iostream>

class Y
{
    int* _val;
public:
    Y(int v = 0) : _val(new int(v)) { std::cout << "Y::Y" << std::endl; }
    ~Y() { delete _val; std::cout << "Y::~Y" << std::endl; }

    Y(const Y& other) : _val(new int(*(other._val)))
    {
        std::cout << "Y(Y&)" << std::endl;
    }

    Y(Y&& other)
    {
        std::cout << "Y(Y&&)" << std::endl;
        _val = other._val;
        other._val = nullptr;
    }

    Y& operator=(const Y& other)
    {
        std::cout << "op=(Y&)" << std::endl;
        Y tmp(*(other._val));
        std::swap(_val, tmp._val);

        return *this;
    }

    Y& operator=(Y&& other)
    {
        std::cout << "op=(Y&&)" << std::endl;
        _val = other._val;
        other._val = nullptr;

        return *this;
    }

    friend Y operator+(const Y& lhs, const Y& rhs);
};

inline Y operator+(const Y& lhs, const Y& rhs)
{
    Y tmp(*lhs._val + *rhs._val);
    return tmp;
}

#endif //Y_H
