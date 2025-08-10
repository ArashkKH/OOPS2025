/* Citation and Sources...
Final Project Milestone 2: 
Module: Billable Logic file
Filename: Billable.cpp
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
Revision History
----------------------------------------------------------------------------
Date        Reason
2025/07/25  Project Milesone 3 : Creating Billable class
----------------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
ANY part that is NOT done by me will be having a comment to point it out 
and include the citation of that code.
----------------------------------------------------------------------------
*/


#include "Billable.h"
#include "Utils.h"

namespace seneca {
    

    Billable::Billable(const Billable& src){
        *this = src;
    }

    Billable& Billable::operator=(const Billable& src){
        if (this != &src) {
            ut.alocpy(m_name , src.m_name);
            m_price = src.m_price;
        }
        return *this;
    }

    Billable::~Billable(){
        delete[] m_name;
        m_name = nullptr;
        m_price = 0;
    }

    double Billable::price() const {
        return m_price;
    }

   double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        money += B.price();
        return money;
    }

    const char* Billable::getName() const {
        return m_name ? m_name : "";
    }



    Billable::operator const char*() const {
        return m_name;
    }

    void Billable::name(const char* name) {
        if (name && name[0] != '\0') {
            ut.alocpy(m_name, name);
        } else {
            delete[] m_name;
            m_name = nullptr;
        }
    }

    void Billable::price(double value) {
        m_price = value;
    }


}

