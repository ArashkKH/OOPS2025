/**
 *  OOP244 Workshop 8 lab: Rectangle class (HEADER)
 *  File	Line.cpp
 *  Version 1.0
 *  Author	Arash Kheirollahi
 *  Description:
 *      Encapsulates a rectangle on the screen that can be labeled
 *      (This concrete class draws a rectangle with a label inside)
 *      
 *  Revision History:
 *  -----------------------------------------------------------
 *  Name            Date            Reason
 *  0.012           2025-07-24      Workshop submission
 ___________________________________________________________ */
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

   class Rectangle : public LblShape {
      // Width of the rectangle
      int m_width = 0;
      // Height of the rectangle
      int m_height = 0;

   public:
      // Default constructor
      Rectangle() = default;
      // Constructor that initializes label, width, and height
      Rectangle(const char* label , int width , int height);
      // Draws the rectangle using the label, width, and height
      void draw(ostream& os) const override;
      // Gets specifications of the rectangle (label, width, height) from input
      void getSpecs(istream& is) override;

      // helpers
      void drawBorder(ostream& os , int len) const;
   };


}

#endif // !SENECA_RECTANGLE_H
