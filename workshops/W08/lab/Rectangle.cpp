/**
 *  OOP244 Workshop 8 lab: Rectangle class
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
#include "Rectangle.h"
#include "Utils.h"
#include <iostream>
using std::istream;
using std::ostream;
using std::ios;

namespace seneca{
    Rectangle::Rectangle(const char* label , int width , int height)
    : LblShape(label) 
    , m_width(width) 
    , m_height(height){};

    void Rectangle::getSpecs(istream& is){
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');

        if(m_width < ut.strlen(label())){
            m_width = ut.strlen(label());
        }
    }

    void Rectangle::draw(ostream& os) const{
        if(m_width > 0 && m_height > 0){
            drawBorder(os , m_width );
            
            os<<'|';
            os.width(m_width - 2);
            os.setf(ios::left);
            os << label() << '|' << std::endl;

            for (int i = 0; i < m_height - 3; i++)
            {
                os << '|';
                os.unsetf(ios::left);
                os.width(m_width - 1);
                os.fill(' ');
                os << '|' << std::endl;
            }
            
            drawBorder(os , m_width );
        }
    }

    void Rectangle::drawBorder(ostream& os , int wid) const{
        os << '+';
        for (int i = 0; i < wid - 2; i++)
        {
            os << '-';
        }
        os << '+';
        os << std::endl;
    }
    
}