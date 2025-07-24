/**
 *  OOP244 Workshop 8 lab: Shape class (HEADER)
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
#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>
using std::ostream;
using std::istream;

namespace seneca {

   class Shape {
   public:
      // Pure virtual function to draw the shape, implemented in derived classes
      virtual void draw(ostream& os) const;
      // Pure virtual function to get specifications of the shape, implemented in derived classes
      virtual void getSpecs(istream& is);
      // Virtual destructor to ensure proper cleanup of derived class objects
      virtual ~Shape();
   };

   // Operator overload to handle output stream, relies on draw function
   ostream& operator<<(ostream& os , const Shape& shape);
   // Operator overload to handle input stream, relies on getSpecs function
   istream& operator>>(istream& is ,Shape& shape);
}

#endif // !SENECA_SHAPE_H
