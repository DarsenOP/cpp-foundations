//
// Created by DarsenOP on 2/8/25.
//

#ifndef VALUE_H
#define VALUE_H
#include <iostream>

class Value
{
    static int next_id;
    int id;

    int *resource;
public:
    Value() : id(++next_id), resource(new int{0})
    {
        std::cout << "Value::id(" << id << ")" << std::endl;
    }

    ~Value()
    {
        std::cout << "~Value::id(" << id << ")" << std::endl;
        delete resource;
    }
};

int Value::next_id = 0;

#endif //VALUE_H
