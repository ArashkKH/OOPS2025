/* Citation and Sources...
-----------------------------------------------------------
Workshop 01 
Module: perform the phonebook search functionality
Filename: io.cpp
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

// io.cpp
#include "io.h"
using namespace std;

namespace seneca {

// Definitions and functions go here
    void readName(char nameVar){
        cout << "name>\n" << endl;
        cin >> nameVar;
    }

    void printNum(long long phoneNum){
        // print as (999) 999-9999
        int groupOne = phoneNum / 1000000;
        int groupTwo = (phoneNum / 10000) - (groupOne * 1000);
        int groupThree  = (phoneNum) - (groupOne * 1000000) - (groupTwo * 1000);

        cout << "(" << groupOne << ") " << groupTwo << "-" << groupThree << endl;
    }

    void printRec(const struct PhoneRec record , size_t rowNum , const char* filter = nullptr){
        
    }
   

}