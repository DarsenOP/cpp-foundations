//
// Created by arsen on 2/3/25.
//

#ifndef OVAL_H
#define OVAL_H
#include "Shape.h"


class Oval : public Shape {
public:
    Oval() = default;
    Oval(double x_radius, double y_radius, const std::string& description);
    ~Oval();

    virtual void draw() const
    {
        std::cout << "Oval::draw() called. Drawing "
                  << m_Description << " with radiuses : " << m_XRadius << ", " << m_YRadius << std::endl;
    }
protected:
    double get_x_radius() const { return m_XRadius; }
    double get_y_radius() const { return m_YRadius; }
private:
    double m_XRadius{};
    double m_YRadius{};
};



#endif //OVAL_H
