//
// Created by arsen on 2/3/25.
//

#include "Oval.h"

Oval::Oval(double x_radius, double y_radius, const std::string &description)
    : m_XRadius(x_radius), m_YRadius(y_radius),  Shape(description)
{
}

Oval::~Oval()
{
}

