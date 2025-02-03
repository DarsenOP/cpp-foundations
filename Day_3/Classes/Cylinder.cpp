//
// Created by DarsenOP on 2/3/25.
//

#include "Cylinder.h"

Cylinder::Cylinder(double radius, double height)
{
    m_H = height;
    m_R = radius;
}

double Cylinder::volume()
{
    return PI * m_R * m_R * m_H;
}

double Cylinder::get_height()
{
    return m_H;
}

double Cylinder::get_radius()
{
    return m_R;
}

void Cylinder::set_height(double height)
{
    m_H = height;
}

void Cylinder::set_radius(double radius)
{
    m_R = radius;
}