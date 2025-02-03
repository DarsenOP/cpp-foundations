//
// Created by DarsenOP on 2/3/25.
//

/* Polymorphism */

#include <iostream>

#include "Circle.h"
#include "Oval.h"
#include "Shape.h"

int main()
{
    // We might want to use base pointer to manage the objects of the derived class
    Shape shape1("Shape1");
    Oval oval1(2, 3.5, "Oval1");
    Circle circle1(3, "Circle1");

    std::cout << std::endl;
    std::cout << "Calling methods through pointers : static bindings" << std::endl;

    Shape* shape_ptr = &shape1;
    shape_ptr->draw(); // We wish to have Shape::draw

    shape_ptr = &oval1;
    shape_ptr->draw(); // We wish to have Oval::draw

    shape_ptr = &circle1;
    shape_ptr->draw(); // We wish to have Circle::draw

    // The compiler in reality looks at the pointer type to decide which version of draw() to call. It is Shape* in all
    // cases that is why in all cases we get Shape::draw(). This is static binding in action.

    // Static Binding is happening during compiler time the way described above
    // The same happens if we use references - again static binding will be used

    // Now when we add `virtual` before the method everything works as we expected
    // We cannot call non-virtual methods with polymorphism // Compile Error

    // Size of polymorphic objects and slicing
    // Sizes are much larger with dynamic binding, because of vtables, vptrs
    // Slicing is the following :   Base base = derived;
    //      In this case the only part that will be assigned is the Base part the derived part will be deleted
    //      The same happens with collections
    // The reference collections of polymorphic objects won't compile, because of Left Assignability

    // We can enforce overriding with : virtual function() override{}

    // We can also overload the overridden function
    // When overriding function, all the overloads of parent/base class will be hidden and we should explicitly override them too
    // Overridden methods in derived classes will not participate in base class polymorphism

    // Static members
    // They are not object dependent and share between all objects in inheritance and polymorphism hierarchy
    // The derived class can also contain its own static members

    // Final is used when we want to restrict further overrides down the stream
    // Final can be also used to restrict further sub-classing down the stream

    // We cannot change the default arguments when we override, that is when we override a method but give different
    // default values, it will still use the ones in the base class, because this part is happening with static binding
    //      - Default arguments are handled at compile time
    //      - Virtual functions are called during runtime

    // Virtual destructors
    // If we do not make the destructor for polymorphic objects only the base class destructor will be called, which is BAD!
    // By just marking them as virtual, the compiler will know that this is polymorphism it will find the most derived class
    // and call its destructor, then it go up the stream like we knew

    // Dynamic_cast<>
    // Transforming from base class pointer or reference to derived class pointer or reference, at run time
    // Makes it possible to call non-polymorphic methods on derived object
    // Should cast to a class that it point to, otherwise will get nullptr
    // Overusing is a sign of BAD design, and maybe should have make the method as polymorphic in first place

    // NEVER call virtual or polymorphic functions from constructor os destructor
    // Because of the order of constructor, destructor the derived object will not be valid the moment we call it,
    // in other words we will get static binding result

    // We can use pure virtual functions that are constructed like this : virtual function() const = 0; (=0 makes it pure)
    // Which means that the derived object have to implement it and we are not going to implement it in the base class
    // But if we have pure virtual functions in the base class, the class becomes Abstract, that is we cannot have
    // objects of a base class
    // If the derived class doesnt implement the pure virtual function it becomes abstract too

    // An abstract class with no members can be created to model what is called an Interface in OOP
    // It is a specialization of something that should be fully implemented in a derived class

    return 0;
}
