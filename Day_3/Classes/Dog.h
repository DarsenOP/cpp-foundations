//
// Created by DarsenOP on 2/3/25.
//

#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include <string_view>

class Dog {
public:
    Dog();
    Dog(std::string_view name_param, std::string_view breed_param, int age_param);
    // Destructors are called when 1) when an object is passed by value to a function
    //                             2) when a local object is returned from a function
    //                             3) when a local stack object goes out of scope (dies)
    //                             4) when a heap object is released with delete
    ~Dog();

    // `this` is useful when the function takes a parameter with the same name as member variable
    // void set_name(std::string_view dog_name);

    // Chained calls
    Dog* set_name(std::string_view name_param);
    Dog* set_breed(std::string_view breed_param);
    Dog* set_age(int age_param);

    void info();
private:
    std::string dog_name;
    std::string dog_breed;
    int* dog_age;
};



#endif //DOG_H
