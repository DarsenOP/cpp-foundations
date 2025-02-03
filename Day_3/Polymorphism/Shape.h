//
// Created by arsen on 2/3/25.
//

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {
public:
    Shape() = default;
    Shape(const std::string& description);
    ~Shape();

    virtual void draw() const
    {
        std::cout << "Shape::draw() called. Drawing " << m_Description << std::endl;
    }
protected:
    std::string m_Description{};
};



#endif //SHAPE_H
