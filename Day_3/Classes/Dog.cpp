//
// Created by DarsenOP on 2/3/25.
//

#include "Dog.h"


Dog::Dog()
{
    dog_name = "NONE";
    dog_breed = "NONE";
    dog_age = new int{};

    // std::cout << "Dog::Dog() called at " << this << std::endl;
}

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param)
{
    dog_name = name_param;
    dog_breed = breed_param;
    dog_age = new int{age_param};

    // std::cout << "Dog::Dog() called at " << this << std::endl;
}

Dog::~Dog()
{
    delete dog_age;
    dog_age = nullptr;

    // std::cout << "Dog::~Dog() called at " << this << std::endl;
}

// void Dog::set_name(std::string_view dog_name)
// {
//     this->dog_name = dog_name;
// }

Dog *Dog::set_name(std::string_view name_param)
{
    dog_name = name_param;
    return this;
}

Dog *Dog::set_breed(std::string_view breed_param)
{
    dog_breed = breed_param;
    return this;
}

Dog *Dog::set_age(int age_param)
{
    dog_age = new int{age_param};
    return this;
}

void Dog::info()
{
    std::cout << "Dog name: " << dog_name << std::endl;
    std::cout << "Dog breed: " << dog_breed << std::endl;
    std::cout << "Dog age: " << *dog_age << std::endl;
}

