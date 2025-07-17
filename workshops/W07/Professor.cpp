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

    double Professor::devPay() const {
        return (salary() / 100.0) * m_sectionQty;
    }

    istream& Professor::read(istream& istr){
        Employee::read(istr);
        istr.ignore();
        char buffer[1024];
        istr.getline(buffer, 1024, ',');
        ut.alocpy(m_subjectName, buffer);
        return istr >> m_sectionQty;
    }

  std::ostream& Professor::write(std::ostream& os) const {
        char subjectOut[21]{};
        if (m_subjectName) {
            ut.strcpy(subjectOut, m_subjectName, 20);  // copy max 20 characters
        }

        os << ' ';              
        Employee::write(os);    

        os.setf(std::ios::left);
        os.width(20);
        os << subjectOut << " | ";

        os.unsetf(std::ios::left);
        os.setf(std::ios::right);
        os.width(5);
        os << m_sectionQty << " | ";

        os.setf(std::ios::fixed);
        os.precision(2);
        os.width(8);
        os << devPay() << " |";
        return os;
    }

    std::ostream& Professor::title(std::ostream& os) const {
        Employee::title(os);
        os << " Teaching Subject | Sec # | $Dev Pay |";
        return os;
    }

    std::ostream& operator<<(std::ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, Professor& P) {
        return P.read(istr);
    }

}