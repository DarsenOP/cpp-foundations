//
// Created by arsen on 2/8/25.
//

#include "Subject.h"
#include "Observer.h"

int main()
{
    Subject subject1("one"), subject2("two");
    Observer observer;

    observer.subscribe(typeid(EventOne), std::bind(&Subject::handle, subject1, std::placeholders::_1));
    observer.subscribe(typeid(EventOne), std::bind(&Subject::handle, subject2, std::placeholders::_1));
    observer.subscribe(typeid(EventTwo), std::bind(&Subject::handle, subject1, std::placeholders::_1));

    observer.notify(EventOne());
    observer.notify(EventTwo());
}