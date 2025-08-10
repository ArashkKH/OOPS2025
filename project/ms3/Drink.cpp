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
#include "Billable.h"
#include "Menu.h"


#include <iostream>
#include <iomanip>
#include <cstring>




using std::ostream;

namespace seneca {
    
    ostream& Drink::print(ostream& ostr) const {
        ostr << left << setw(28) << setfill('.') << (const char*)(*this);

        if (!ordered()) {
            ostr << ".....";
        } else {
            switch (m_size) {
                case 'S': ostr << "SML.."; break;
                case 'M': ostr << "MID.."; break;
                case 'L': ostr << "LRG.."; break;
                case 'X': ostr << "XLR.."; break;
                default:  ostr << "....."; break;
            }
        }

        ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();
        return ostr;
    }

    bool Drink::order(){
        Menu ms2("Drink Size Selection" , "Back" , 3 ,3);
        ms2 << "Small" << "Medium" << "Larg" << "Extra Large";
        size_t selection{};
    
        selection = ms2.select();
        switch (selection) {
        case 0:{
            m_size = '\0';
            return false;
        }
        case 1: {
            m_size = 'S';
            return true;
        }
        case 2:{
            m_size = 'M';
            return true;
        }
        case 3:{
            m_size = 'L';
            return true;
        }
        case 4:{
            m_size = 'X';
            return true;
        }
        default:
            return false;
        }
    }

    bool Drink::ordered() const{
        if(m_size){
            return true;
        }else{
            return false;
        }
    }

    ifstream& Drink::read(ifstream& file) {
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
                m_size = '\0'; // default to not ordered
            }
        }

        return file;
    }

    double Drink::price() const{
        double multiplier = 1.0;

        switch (m_size)
            {
            case 'S':
                multiplier = 0.5;
                break;
            case 'M':
                multiplier = 0.75;
                break;
            case 'L':
                multiplier = 1.0;
                break;
            case 'X':
                multiplier = 1.5;
                break;
            default:
                multiplier = 1.0;
                break;
            }

        return getPrice() * multiplier;
    }
}
 