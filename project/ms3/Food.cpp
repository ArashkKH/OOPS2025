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
#include <iomanip>
#include <string>

using std::ostream;
using std::cout;
using std::cin;
using std::left;
using std::right;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;
 namespace seneca{
    // Constructrots
    Food::Food() : Billable() , m_ordered(false) , m_child(false) , m_customize(nullptr) {}
    // Copy Constructor
    Food::Food(const Food& other): Billable(other) , m_ordered(other.m_ordered) , m_child(other.m_child) , m_customize(nullptr){
        if(other.m_customize){ut.alocpy(m_customize , other.m_customize);}
    }
    // Assignment Operator
    Food& Food::operator=(const Food& other){
        if(this != &other){
            Billable::operator=(other);
            m_ordered = other.m_ordered;
            m_child = other.m_child;

            delete[] m_customize;
            m_customize = nullptr;

            if(other.m_customize){
                ut.alocpy(m_customize , other.m_customize);
            }
        }
        return *this;
    }
    // Destructor
    Food::~Food(){
        delete[] m_customize;
        m_customize = nullptr;
    }

    ostream& Food::print(ostream& ostr) const {
        if(*this){
            // Got this line from Kiarash (Seneca Mr. Hong huan Student)
            ostr << left << setw(28) << setfill('.') << (const char*)(*this);

            if(ordered()){
                if(m_child){
                    ostr << "Child";
                }else{
                    ostr << "Adult";
                }
            }else{
                ostr << ".....";
            }

            ostr << right << setfill(' ') << setw(7) << fixed << setprecision(2) << price();

            if(&ostr == &cout && m_customize && m_customize[0]){
                ostr << " >> ";
                string customStr = m_customize;
                if(customStr.length() > 30){
                    customStr = customStr.substr(0 , 30);
                }
                ostr << customStr;
            }

        }
        return ostr;
    }

    bool Food::order(){
        Menu foodMenu("Food Size Selection" , "Back" , 3);
        foodMenu << "Adult" << "Child";
        size_t selection = foodMenu.select();

        if(selection == 1 || selection == 2){
            m_ordered = true;
            m_child = (selection == 2);

            cout << "Special instructions" << endl << "> ";
    
            cin.ignore(1000, '\n');
            // String management Suggested by AI
            string customization;
            getline(cin , customization);
    
            delete[] m_customize;
            m_customize = nullptr;
    
            // string check by AI
            if(!customization.empty() && customization != " "){
                ut.alocpy(m_customize , customization.c_str());            
            }
            return true;
        }else{
            m_ordered = false;
            delete [] m_customize;
            m_customize = nullptr;
            return false;
        }

    }

    // Ordered Method
    //got this function code from Kiarash - other section of this course
    bool Food::ordered() const {return m_ordered;}

    // Reading method
    std::ifstream& Food::read(std::ifstream& file) {
        char name[256]{};
        double priceVal;

        if (file.good()) {
            file.getline(name, 256, ',');
            file >> priceVal;
            file.ignore(1000, '\n');

            if (file) {
                name[255] = '\0';
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
        if (m_ordered && m_child) {
            return Billable::price() * 0.5;
        } else {
            return Billable::price();
        }
    }
 }