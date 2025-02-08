//
// Created by arsen on 2/8/25.
//

#ifndef PTR_H
#define PTR_H

class Value;

class Ptr
{
    Value* val;
public:
    Ptr() : val(new Value) {}

    ~Ptr() { delete val; }

    Ptr(const Ptr& other) = delete;
    Ptr& operator=(const Ptr& other) = delete;

    Ptr& operator=(Ptr&& other)
    {
        if (this != &other) {
            delete val;
            val = other.release();
        }

        return *this;
    };

    Value* release()
    {
        Value* tmp = val;
        val = nullptr;
        return tmp;
    }

    Value* get() const
    {
        return val;
    }

    void reset(Value* new_val)
    {
        Value* tmp = val;
        val = new_val;
        delete tmp;
    }

    void swap(Ptr& other)
    {
        Value* tmp = val;
        val = other.val;
        other.val = tmp;

    }

};

#endif //PTR_H
