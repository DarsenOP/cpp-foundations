//
// Created by DarsenOP on 2/3/25.
//

#ifndef PERSON_H
#define PERSON_H
#include <ostream>


class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
public:
    Person();
    Person(std::string_view first_name_param, std::string_view last_name_param);
    ~Person();

    Person(const Person& person);
// private:
protected: // Protected is like private, but accessible for in derived class
    std::string m_First_name{"Unknown"};
    std::string m_Last_name{"Person"};
private:
    int private_var{};
};




#endif //PERSON_H
