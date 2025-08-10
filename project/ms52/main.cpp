/* Citation and Sources...
Final Project Milestone 52: 
Module: Utils
Filename: Utils.h
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: Akheirollahi@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2025/08/09  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

#include <iostream>

namespace seneca {
    class Utils {
    public:
        // Foolproof input functions
        int getInt();
        int getInt(int min, int max);
        
        // Dynamic C-string reading
        char* read(std::istream& istr);
        
        // Bill filename generation
        char* makeBillFileName(char* filename, size_t billNo) const;
    };
    
    // Global Utils object for easy access
    extern Utils ut;
}

#endif // SENECA_UTILS_H