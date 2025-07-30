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

// for getting two Digits Codes
// Code suggested by AI
#include <iomanip>

using std::ostream;

namespace seneca {
    
    ostream& Drink::print(ostream& os) const{
        char* buffer = nullptr;
        ut.alocpy(buffer, getName());
        os.setf(std::ios::left);
        os.width(28);
        os.fill('.');
        os << (buffer ? buffer : "");
        delete[] buffer;

        // Print size
        if(!ordered()){
            os << ".....";
        }else{
            switch (m_size)
            {
            case 'S':
                os << "SML..";
                break;
            case 'M':
                os << "MID..";
                break;
            case 'L':
                os << "LRG..";
                break;
            case 'X':
                os << "XLR..";
                break;
            default:
                os << ".....";
                break;
            // Ensure a return value in all code paths
            return os;
            }
        }

        // for getting two Digits Codes
        // Code suggested by AI        os.unsetf(std::ios::left);
        os.width(7);
        os << std::right << std::fixed << std::setprecision(2) << price();

        return os;
    };

    bool Drink::order(){
        Menu ms2("Drink Size Selection" , "Back" , 1 ,3);
        ms2 << "Small" << "Medium" << "Larg" << "Extra Large";
        size_t selection{};
    
        selection = ms2.select();
        switch (selection) {
        case 0:{
            break;
            return false;
        }
        case 1: {
            m_size = 'S';
            return true;
            break;
        }
        case 2:{
            m_size = 'M';
            return true;
            break;
        }
        case 3:{
            m_size = 'L';
            return true;
            break;
        }
        case 4:{
            m_size = 'X';
            return true;
            break;
        }
        default:
            return false;
        }
        return false;
    }

    bool Drink::ordered() const{
        if(m_size){
            return true;
        }else{
            return false;
        }
    }

    ifstream& Drink::read(ifstream& file) {
        // This line was suggested by AI for reading failure
        std::streampos pos = file.tellg();

        char buffer[1024]{};
        double priceVal = 0.0;

        if (file.getline(buffer, 1024, ',') && (file >> priceVal)) {
            file.ignore(1000, '\n');
            name(buffer);
            Billable::price(priceVal);
            m_size = '\0';
        } else {            
            // This block and the placementof block aboove in the if statement
            // were suggested by AI for reading failure
            file.clear();
            file.seekg(pos);
        }
        return file;
    }

    double Drink::price() const{
        double multiplier = 0;

        switch (m_size)
            {
            case 'S':
                multiplier = 0.5;
                break;
            case 'M':
                multiplier = 0.75;
                break;
            case 'L':
                multiplier = 1;
                break;
            case 'X':
                multiplier = 1.5;
                break;
            default:
                multiplier = -1 / getPrice();
                break;
            }

        return getPrice() * multiplier;
    }
}
 