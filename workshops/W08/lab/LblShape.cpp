/**
 *  OOP244 Workshop 8 lab: Shape labeling class
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

#include "LblShape.h"
#include "Utils.h"
#include <iostream>
using std::istream;

namespace seneca{
    LblShape::LblShape(const char* string){
        m_label = new char[ut.strlen(string) + 1 ];
        ut.alocpy(m_label , string);
    }

    void LblShape::getSpecs(istream& is){
        char buffer[80];
        is.getline(buffer , 80 , ',');

        m_label = nullptr;
        delete[] m_label;

        m_label = new char[ut.strlen(buffer) + 1];

        ut.alocpy(m_label , buffer);
        is.ignore();
    }

    LblShape::~LblShape(){
        m_label = nullptr;
        delete[] m_label;
    }

}