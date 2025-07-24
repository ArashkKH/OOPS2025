/**
 *  OOP244 Workshop 8 lab: Labeld line class
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
#include "Line.h"
#include "Utils.h"
#include <iostream>
using std::istream;
using std::ostream;


namespace seneca{
    Line::Line(const char* label, int len)
    : LblShape(label)
    , m_length(len) {
        if(m_length < ut.strlen(label)){
            m_length = ut.strlen(label);
        }
    } ;

    void Line::getSpecs(istream& is){
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n'); 
    }

    void Line::draw(ostream& os) const{
        // std::cout << m_length << std::endl;
        if(m_length > 0 && label() != nullptr){
            os << label();
            os << std::endl;
            
            for (int i = 0; i < m_length; i++)
            {
                os << "=";
            }
            //os << std::endl;
        }
    }
}
