/**
 *  OOP244 Workshop 8 lab: Shape class
 *  File	Shape.cpp
 *  Version 1.0
 *  Author	Arash Kheirollahi
 *  Description:
 *      Encapsulates a shape that can be drawn on the screen
 *      (An interface, serving as an abstract base class with
 *      only pure virtual functions)     
 *  Revision History:
 *  -----------------------------------------------------------
 *  Name            Date            Reason
 *  0.012           2025-07-24      Workshop submission
 ___________________________________________________________ */

#include "Shape.h"

namespace seneca{

    Shape::~Shape() {}
    std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        shape.draw(os);
        return os;
    }
    std::istream& operator>>(std::istream& is, Shape& shape) {
        shape.getSpecs(is);
        return is;
    }

}