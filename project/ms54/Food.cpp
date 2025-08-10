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
2025/08/09  Project Milesone 53 : milestone 3 Food Ordering update
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
        Menu portionMenu("Food Size Selection", "Back", 3, 3);
        portionMenu << "Adult" << "Child";
        
        size_t selection = portionMenu.select();
        
        if (selection == 0) {
            // Back was selected
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
            return false;
        }
        
        // Set portion based on selection
        if (selection == 1) {
            m_child = false;  // Adult portion
        } else if (selection == 2) {
            m_child = true;   // Child portion
        }
        
        m_ordered = true;
        
        // Prompt for customizations
        cout << "Special instructions" << endl;
        cout << "> ";
        
        // Clear any previous customization
        delete[] m_customize;
        m_customize = nullptr;
        
        // Read the entire line for customizations
        cin.ignore(); // Clear any leftover newline
        string customization;
        getline(cin, customization);
        
        // If not empty, store the customization
        if (!customization.empty() && customization != " ") {
            m_customize = new char[customization.length() + 1];
            strcpy(m_customize, customization.c_str());
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
 