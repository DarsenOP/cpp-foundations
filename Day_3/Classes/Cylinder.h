//
// Created by DarsenOP on 2/3/25.
//

#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

class Cylinder
{
public:
    Cylinder() = default;
    Cylinder(double radius, double height);

    double volume();

    double get_height();
    double get_radius();

    void set_height(double height);
    void set_radius(double radius);
private:
    double m_R{};
    double m_H{};
};



#endif //CYLINDER_H
