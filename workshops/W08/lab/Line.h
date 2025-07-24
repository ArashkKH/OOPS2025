/**
 *  OOP244 Workshop 8 lab: Labeld line class (Header)
 *  File	Line.cpp
 *  Version 1.0
 *  Author	Arash Kheirollahi
 *  Description:
 *      Encapsulates a horizontal line on a screen with a label
 *      (This concrete class draws a labeled line)
 *      
 *  Revision History:
 *  -----------------------------------------------------------
 *  Name            Date            Reason
 *  0.012           2025-07-24      Workshop submission
 ___________________________________________________________ */
#ifndef SENECA_LINE_H
#define SENECA_LINE_H

#include "LblShape.h"


namespace seneca {

   class Line : public LblShape{
       // Length of the line
      int m_length = 0;
   public:
      // Default constructor
      Line() = default;
      // Constructor that initializes label and length
      Line(const char* label, int len);
      // Draws the line, using the label and length
      void draw(ostream& os) const override;
      // Gets specifications of the line (label and length) from input
      void getSpecs(istream& is) override;

      Line(const Line& obj) = delete;
      Line& operator=(const Line& obj) = delete;
   };

}

#endif // !SENECA_LINE_H
