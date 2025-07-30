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

using std::ostream;
using std::cout;
using std::cin;

namespace seneca {
    
    Food& Food::operator=(const Food& src){
        ut.alocpy(m_customize);
        m_ordered = src.m_ordered;
        m_child = src.m_child;

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

    ostream& Food::print(ostream& os) const{
        char* buffer = nullptr;
        ut.alocpy(buffer, getName());
        os.setf(std::ios::left);
        os.width(28);
        os.fill('.');
        os << (buffer ? buffer : "");
        delete[] buffer;

        // displaying portion size
        if(ordered()){
            if(m_child){
                os << "Child";
            }else{
                os << "Adult";
            }
        }else{
            os << ".....";
        }

        // for getting two Digits Codes
        // Code suggested by AI        os.unsetf(std::ios::left);
        os.width(7);
        os << std::right << std::fixed << std::setprecision(2) << price();

        if(m_customize && (&os == &std::cout)){
            os << " >> ";
            int i = 0;
            while (i < 30 && m_customize[i] != '\0') {
                os << m_customize[i];
                ++i;
            }
        }

        return os;
    };

    bool Food::order() {
        Menu ms2("Food Size Selection", "Back", 1, 3);
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
        cin.ignore(1000, '\n'); 
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

    std::ifstream& Food::read(std::ifstream& file) {
        // Save current position for rollback on failure
        std::streampos pos = file.tellg();

        char buffer[1024]{};
        double priceVal = 0.0;

        if (file.getline(buffer, 1024, ',') && (file >> priceVal)) {
            file.ignore(1000, '\n');
            name(buffer);
            Billable::price(priceVal);
            m_child = false;
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
        } else {
            file.clear();
            file.seekg(pos);
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
 