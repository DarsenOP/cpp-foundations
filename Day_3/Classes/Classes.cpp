//
// Created by DarsenOP on 2/3/25.
//

/* Classes */

#include <iostream>
#include "Cylinder.h"
#include "Dog.h"

// To make everything organized we can put constants in a separate file
// const double PI {3.14159265358979323846};


// It is also better to have ClassName.h for declaration and ClassName.cpp for implementation
// class Cylinder
// {
// // Private members of classes (functions, variables) are not accessible from outside the class itself
// public:
//     // Constructor
//     /*Cylinder()
//     {
//         m_H = 3;
//         m_R = 2;
//     }*/
//     // When we set up our own constructor, the program will not generate the default constructor
//     // In order to create one we can write
//     Cylinder() = default;
//
//     Cylinder(double radius, double height)
//     {
//         m_H = height;
//         m_R = radius;
//     }
//
//     // Class methods have access to member variables regardless they are public, private or protected
//     double volume()
//     {
//         return PI * m_R * m_R * m_H;
//     }
//
//     // Because the members are public we cannot access or modify them directly, that is why we use getters and setters
//     double get_height()
//     {
//         return m_H;
//     }
//
//     double get_radius()
//     {
//         return m_R;
//     }
//
//     void set_height(double height)
//     {
//         m_H = height;
//     }
//
//     void set_radius(double radius)
//     {
//         m_R = radius;
//     }
// private:
//     // Member variables can be either raw stack variables or pointers
//     // Member cannot be references
//     double m_R{};
//     double m_H{};
// };

void DestructorCheck1(Dog dog)
{
    std::cout << "Check 1\n";
}

Dog DestructorCheck2(int age)
{
    return Dog("A", "B", age);
}

int main()
{
    // Classes are just templates
    Cylinder cylinder1;
    std::cout << cylinder1.volume() << std::endl;
    // cylinder.m_R = 10; // Only when public
    // std::cout << cylinder.volume() << std::endl;
    // cylinder.m_H = 0.01; // Only when public
    // std::cout << cylinder.volume() << std::endl;

    Cylinder cylinder2(3, 1.5);
    std::cout << cylinder2.volume() << std::endl;

    cylinder2.set_radius(5);
    cylinder2.set_height(3);
    std::cout << cylinder2.get_height() << std::endl;
    std::cout << cylinder2.get_radius() << std::endl;
    std::cout << cylinder2.volume() << std::endl;

    // Managing class objects with pointers

    Cylinder* cylinder3 = new Cylinder(11, 20);
    std::cout << (*cylinder3).volume() << std::endl; // First way with dereferencing
    std::cout << cylinder3->volume() << std::endl; // Second way using ->

    // Destructors
    Dog dog("Pupsik", "Shepard", 25);
    // DestructorCheck1(dog); // This throws an error, because when getting out of the function the destructor is called
                              // and the pointer is deleted, but when getting out of main it tries to delete it one more time
    Dog dog2 = DestructorCheck2(14); // This calls a destructor too, because when returning it copies the return
                                          // value and destroys the original one

    // Constructors are called top to bottom, the destructors bottom to top

    // Each class member function contains a hidden pointer called `this`. This pointer contains address of the
    // current object, for which the method is being executed. This also applies to constructors and destructors

    // By using pointers and this we can create chained calls
    Dog* p_dog = new Dog();

    p_dog->info();
    p_dog->set_name("Pupsik")->set_breed("Shepard")->set_age(25);
    p_dog->info();

    // It is also possible to make chain calls with references just returning *this instead of this in methods

    // Struct VS Class
    // The only difference is that member variables, methods and everything else is public on default in struct,
    // and private in class

    // Size of class objects, which is a bit tricky
    // So in most cases the size is just the sum of all member variables
    // But because of something called `Boundary alignment` the size can appear more than the sum

    return 0;
}