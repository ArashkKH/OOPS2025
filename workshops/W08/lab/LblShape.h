/**
 *  OOP244 Workshop 8 lab: Shape labeling class (HEADER)
 *  File	LblShape.cpp
 *  Version 1.0
 *  Author	Arash Kheirollahi
 *  Description:
 *      Encapsulates a shape that can be labeled
 *      (An abstract base class that represents a labeled shape)
 *      
 *  Revision History:
 *  -----------------------------------------------------------
 *  Name            Date            Reason
 *  0.012           2025-07-24      Workshop submission
 ___________________________________________________________ */
#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H

#include <iostream>
#include "LblShape.h"
#include "Shape.h"

using std::istream;


namespace seneca {

   class LblShape : Shape{
      // Dynamically allocated label for the shape
      char* m_label = nullptr;
   protected:
      // Returns the label string for derived classes to access
      const char* label() const;
   public:
      // Default constructor
      LblShape() = default;
      // Constructor with label initialization
      LblShape(const char* string);
      // Copy constructor and assignment operator are deleted to prevent copying
      LblShape(const LblShape& obj) = delete;
      LblShape& operator=(const LblShape obj) = delete;
      // Reads label specifications from input stream
      void getSpecs(istream& is) override;
      // Destructor to release dynamically allocated memory
      ~LblShape();
   };
}

#endif // !SENECA_LABELEDSHAPE_H
