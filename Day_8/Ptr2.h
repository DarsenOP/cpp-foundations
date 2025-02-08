//
// Created by arsen on 2/8/25.
//

#ifndef PTR2_H
#define PTR2_H

#include <memory>
class Value;

class Ptr2
{
    std::unique_ptr<Value> ptr;
public:
    Ptr2() : ptr{std::make_unique<Value>()} {}

    Ptr2(const Ptr2& other) = delete;
    Ptr2 &operator=(const Ptr2 &other) = delete;

    Ptr2(Ptr2 &&other) : ptr{other.release()} {}

    Ptr2 &operator=(Ptr2 &&other)
    {
        ptr = std::move(other.ptr);
        return *this;
    }

    std::unique_ptr<Value> release()
    {
        std::unique_ptr<Value> tmp{std::move(ptr)};
        return tmp;
    }

    Value *get() const
    {
        return ptr.get();
    }

    void reset(Value *new_value)
    {
        ptr.reset(new_value);
    }

    void swap(Ptr2 &other)
    {
        ptr.swap(other.ptr);
    }
};

#endif //PTR2_H
