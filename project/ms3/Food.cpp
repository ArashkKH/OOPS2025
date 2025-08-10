/* Citation and Sources...
Final Project Milestone 2: 
Module: Food Logic file
Filename: Food.cpp
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
Revision History
----------------------------------------------------------------------------
Date        Reason
2025/07/29  Project Milesone 3 : Creating Food class
2025/08/08  Project Milesone 3 : fixing read method on bad input check
                                 it gets in an infinite loop on virtual function.
----------------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
ANY part that is NOT done by me will be having a comment to point it out 
and include the citation of that code.
----------------------------------------------------------------------------
*/



#include "Food.h"
#include "Utils.h"
#include "Billable.h"
#include "Menu.h"


#include <iostream>

// for getting two Digits Codes
// Code suggested by AI
#include <iomanip>
#include <cstring>

using std::ostream;
using std::cout;
using std::cin;

namespace seneca {
    
    Food& Food::operator=(const Food& src){
        if (this != &src) {
            Billable::operator=(src);
            ut.alocpy(m_customize, src.m_customize);
            m_ordered = src.m_ordered;
            m_child = src.m_child;
        }
        return *this;
    }


    Food::Food(const Food& src)
        : Billable(src)
    {
        *this = src;
    }

    Food::~Food(){
        delete[] m_customize;
        m_customize = nullptr;
    }

    ostream& Food::print(ostream& ostr) const {
        ostr << left << setw(28) << setfill('.') << (const char*)(*this);

        if (!m_ordered) {
            ostr << ".....";
        } else {
            ostr << (m_child ? "Child" : "Adult");
        }

        ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();

        if (m_customize && &ostr == &cout) {
            ostr << " >> ";
            for (int i = 0; i < 30 && m_customize[i]; ++i)
                ostr << m_customize[i];
        }

        return ostr;
    }

    bool Food::order() {
        Menu ms2("Food Size Selection", "Back", 3, 3);
        ms2 << "Adult" << "Child";
        size_t selection = ms2.select();

        switch (selection) {
        case 0: // Back
            m_ordered = false;
            m_child = false;
            delete[] m_customize;
            m_customize = nullptr;
            return false;
        case 1: // Adult
            m_child = false;
            m_ordered = true;
            break;
        case 2: // Child
            m_child = true;
            m_ordered = true;
            break;
        default:
            return false;
        }

        // Prompt for customization
        char temp[256]{};
        cout << "Special instructions\n> ";
        cin.getline(temp, 256);

        if (temp[0] == '\0') {
            delete[] m_customize;
            m_customize = nullptr;
        } else {
            ut.alocpy(m_customize, temp);
        }

        return true;
    }

    bool Food::ordered() const{
        if(m_ordered){
            return true;
        }else{
            return false;
        }
    }

    ifstream& Food::read(ifstream& file) {
        char name[256]{};
        double priceVal;

        if (file.good()) {
            file.getline(name, 256, ',');
            file >> priceVal;
            file.ignore(1000, '\n');

            if (file) {
                // Remove leading and trailing spaces
                int len = strlen(name);
                while (len > 0 && (name[len-1] == ' ' || name[len-1] == '\r' || name[len-1] == '\n')) {
                    name[--len] = '\0';
                }
                while (name[0] == ' ') {
                    for (int i = 0; name[i]; i++) {
                        name[i] = name[i + 1];
                    }
                }
                Billable::name(name);
                Billable::price(priceVal);
                m_ordered = false;
                m_child = false;
                delete[] m_customize;
                m_customize = nullptr;
            }
        }

        return file;
    }


    double Food::price() const {
        if (ordered() && m_child) {
            return Billable::price() * 0.5;
        }
        return Billable::price();
    }
}
 