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
#include "./cstr.h"

#ifndef SENECA_IO_H
#define SENECA_IO_H

namespace seneca {

// Declarations and prototypes go here
 struct PhoneRec
    {
        char firstName[15];
        char lastName[25];
        long long phoneNum;

    };
    
    void read(char* nameVar);
    void printNum(long long phoneNum);
    void printRec(const struct PhoneRec record , size_t rowNum , const char* filter = nullptr);
    bool read(struct PhoneRec& record, FILE* fp);
    void print(struct PhoneRec* phoneBook[], size_t* bookSize ,const char* filter = nullptr) ;
    void setPointers(struct PhoneRec* phoneBookPtr[], struct PhoneRec phoneBook[], size_t arrSize) ;
    void sort(struct PhoneRec* phoneBookPtr[] , size_t arrSize , bool sortLastNames);


}
#endif // !SENECA_IO_H 