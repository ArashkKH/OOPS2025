/* Citation and Sources...
Final Project Milestone 2: 
Module: Drink Logic file
Filename: Drink.cpp
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
Revision History
----------------------------------------------------------------------------
Date        Reason
2025/07/25  Project Milesone 3 : Creating Drink class
----------------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
ANY part that is NOT done by me will be having a comment to point it out 
and include the citation of that code.
----------------------------------------------------------------------------
*/

#include "Drink.h"
#include "Utils.h"
#include "Menu.h"
#include <iomanip>
#include <cstring>



using std::left;
using std::right;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;


namespace seneca{
    // constructor
    Drink::Drink() : Billable() , m_size(0) {}
    // Printing Method
    ostream& Drink::print(ostream& ostr) const {
        if(*this){
            // Got this line from Kiarash (Seneca Mr. Hong huan Student)
            ostr << left << setw(28) << setfill('.') << (const char*)(*this);

            if(ordered()){
                switch (m_size){
                    case 'S' : ostr << "SML.."; break;
                    case 'M' : ostr << "MID.."; break;
                    case 'L' : ostr << "LRG.."; break;
                    case 'X' : ostr << "XLR.."; break;
                    default: ostr << "....."; break;
                }
            }else{
                ostr << ".....";
            }
            // Got this line from Kiarash (Seneca Mr. Hong huan Student)
            ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();
        }
        return ostr;
    }
    // Ordering Method
    bool Drink::order() {
        Menu drinkMenu("Drink Size Selection" , "Back" , 3);
        drinkMenu << "Small" << "Medium" << "Larg" << "Extra Large";

        size_t selecation = drinkMenu.select();

        switch (selecation){
            case 1: m_size = 'S'; return true;
            case 2: m_size = 'M'; return true;
            case 3: m_size = 'L'; return true;
            case 4: m_size = 'X'; return true;
            default: return false;

        }
    }

    // ordered query
    bool Drink::ordered() const {
        return m_size != 0;
    }

    // Reading from File
    //got this function code from Kiarash - (other section student of out course)
    std::ifstream& Drink::read(std::ifstream& file) {
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
                m_size = 0; // default to not ordered
            }
        }

        return file;
    }
    
    // had to redo the while MS for this read function >:(

    // price Method
    double Drink::price() const {
        if(!ordered() || m_size == 'L'){
            return Billable::price();
        }

        double basePrice = Billable::price();
        switch (m_size){
            case 'S': return basePrice * 0.5;
            case 'M': return basePrice * 0.75;
            case 'X': return basePrice * 1.5;
            default : return basePrice;
        }
    }
}