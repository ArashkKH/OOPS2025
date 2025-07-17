/***********************************************************************
// OOP244 Workshop 7 lab: Employee
//
// File  Professor.h
// Author   Arash Kheirollahi
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Project submission   17-07-2025      implementing main logic
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Employee.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::cout;
using std::cin;


namespace seneca{
    class Professor : public Employee {
        char *m_name{};
        size_t m_employeeNo{};
        char* m_subjectName{};
        int m_sectionQty{};

        public:
            Professor() = default;
            Professor(const char* name , const char* subjectName , const int sectionQty , const size_t empNumber , const double salary);

            // Methods 
            double devPay() const;                          //1% salary * sectionQty
            istream& read(istream& istr = cin);             //call employee read + the prof member values
            ostream& write(ostream& ostr = cout) const;     //https://github.com/Seneca-244200/OOP-Workshops/tree/main/WS07#ostream-writeostream-ostr--cout-const
            ostream& title(ostream& ostr = cout) const;     //calling employees title function + " Teaching Subject | Sec # | $Dev Pay |"

            ~Professor();
    };
}
#endif // PROFESSOR_H

