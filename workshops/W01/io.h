/* Citation and Sources...
-----------------------------------------------------------
Workshop 01 
Module: header file for io
Filename: io.h
-----------------------------------------------------------
Author: Arash Kheirollahi
Student number: 146,731,245
Email: akheirollahi@myseneca.ca
Subject: OOP244NFF
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.1    2025/5/22 Workshop Initiation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/


// io.h
#include <iostream>
#include <stdio.h>

#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H

namespace seneca {

// Declarations and prototypes go here
 struct PhoneRec
    {
        char firstName[15];
        char lastName[25];
        long long phoneNum;

    };
    
    void readName(char nameVar);


}
#endif // !SENECA_CSTR_H 