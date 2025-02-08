//
// Created by arsen on 2/8/25.
//

#ifndef RESULT_H
#define RESULT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>

template<typename T, typename E>
class Result
{
    bool valid;
    T value;
    E exception;
public:
    Result(const T& val) : valid(true), value(val) {}
    Result(const E& ex) : valid(false), exception(ex) {}

    bool is_valid() const { return valid; }

    T get_value() const
    {
        if (!is_valid()) {
            throw std::logic_error("Value from an invalid result!");
        }
        return value;
    }

    E get_exception() const
    {
        if (!is_valid()) {
            throw std::logic_error("Exception from a valid result!");
        }
        return exception;
    }
};

#endif //RESULT_H
