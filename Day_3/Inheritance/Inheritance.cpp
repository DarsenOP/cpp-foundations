//
// Created by DarsenOP on 2/3/25.
//

/* Inheritance */

#include <iostream>
#include "Player.h"

int main()
{
    /* Inheritance: public, private, protected
     * 1) Public Inheritance: In this case all the access specifiers remain the same in the Derived class, that is we can
     *    use public and protected members in any-level derived class, where as private ones nowhere
     * 2) Protected Inheritance: In this case public and protected become protected in the Derived class, that is we can still
     *    use public and protected members in any-level derived class (and again private ones not), with the only difference
     *    that the public members will not be accessible outside the derived class. For example if we have a derived class
     *    with protected inheritance and it inherited public member ID, then in case of Derived object we will not be able
     *    to modify it outside the class, and in the case Base class we will be able to do so
     * 3) Private Inheritance: In this case everything in the Base class becomes private in the Derived class, and because of
     *    that we will be able to use public, protected (and we will not be able to use private) in the 1-level Dervied class
     *    and we can use nothing in N-level derived class for N>=2.
     */

    /* Resurrecting member back in scope
     * Even though after using private inheritance we cannot access neither public nor protected members in further
     * derived class it is still possible to resurrect them (the ones that are actually possible to resurrect, because
     * base class private members are not accessible in any way): using ParentClass::member;
     */

    /* Always provide a default constructor for classes, especially if they will be a part of an inheritance hierarchy*/

    Player player("Arsen", "Aghayan", "Basketball"); // Constructors go from base to bottom, destructors the other way

    // Custom constructors with inheritance
    // Not an ideal choice is to use this->parameter=value, because those parameters can be private in the base class
    // You cannot use initializer list, because the compiler will not accept initialization of a member not belonging to the derived class
    // But using the initializer list with Person() constructor we have can make it work

    // Copy constructors with inheritance
    // Default one makes a shallow copy which is bad for classes with pointers
    // So we can make custom ones (SEE Player.cpp)

    // If we have Base and Derived class that contain the same name members accessing it with obj.member, will automatically
    // choose the one in derived class to get the one in base class we can write, obj.Base::member, BUT
    // BE AWARE of name hiding : even if the method has different signature it will be hidden and the default one again will be
    // the derived class one
    // Another way to solve name hiding is: using Base::member


    return 0;
}