//
// Created by DarsenOP on 2/3/25.
//

#include "Person.h"

#include <iostream>


Person::Person()
{
    std::cout << "Person Constructor" << std::endl;
}

Person::Person(std::string_view first_name_param, std::string_view last_name_param)
{
    m_First_name = first_name_param;
    m_Last_name = last_name_param;
    std::cout << "Person Constructor" << std::endl;
}

Person::~Person()
{
    std::cout << "Person Destructor" << std::endl;
}

Person::Person(const Person &person)
    : m_First_name(person.m_First_name), m_Last_name(person.m_Last_name)
{
    std::cout << "Copy Person Constructor\n";
}
