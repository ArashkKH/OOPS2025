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
#include <cstring>

namespace seneca{

    // Protected Methods
    void Billable::price(double val){
        m_price = val;
    }
    void Billable::name(const char* name){ut.alocpy(m_name , name);}
    // constructors and destructors
    Billable::Billable() : m_name(nullptr) , m_price(0.0) {}
    Billable::Billable(const Billable& other): m_name{nullptr} , m_price(other.m_price) {
        name(other.m_name);
    }
    Billable& Billable::operator=(const Billable& other){
        if (this != &other){
            name(other.m_name);
            m_price = other.m_price;
        }
        return *this;
    }
    // Virtuals
    Billable::~Billable(){delete [] m_name; m_name = nullptr;}
    double Billable::price() const {return m_price;};
    // Conversions
    Billable::operator const char*() const{return m_name;}
    // Global Operators
    double operator+(double money , const Billable& B){return money + B.price();}
    double& operator+=(double& money, const Billable& B){return money += B.price();}
}