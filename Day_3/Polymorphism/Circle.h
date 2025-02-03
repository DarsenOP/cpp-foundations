//
// Created by arsen on 2/3/25.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Oval.h"

class Circle : public Oval {
public:
    Circle() = default;
    Circle(double radius, const std::string& description);
    ~Circle();

    virtual void draw() const
    {
        std::cout << "Circle::draw() called. Drawing "
                  << m_Description << " with radius : " << get_x_radius() << std::endl;
    }
};



#endif //CIRCLE_H
