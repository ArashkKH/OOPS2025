/***********************************************************************
// OOP244 Workshop 7 lab: Employee
//
// File  Professor.Cpp
// Author   Arash Kheirollahi
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Project submission   17-07-2025      implementing main logic
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Professor.h"
#include "Utils.h"
namespace seneca {

    Professor::Professor(const char* name , const char* subjectName , const int sectionQty , const size_t empNumber , const double salary)
        : m_name(ut.alocpy(name))
        , m_subjectName(ut.alocpy(subjectName))
        , m_sectionQty(sectionQty)
    {}

    double Professor::devPay() const{
        return (m_salary / 100) * m_sectionQty;
    }

    istream& Professor::read(istream& istr){
        Employee::read(istr);
        
    }


}