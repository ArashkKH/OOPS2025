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
    void readName(char* nameVar){
        cout << "name>\n" << endl;
        cin >> nameVar;
    }

    void printNum(long long phoneNum){
        // print as (999) 999-9999
        long long groupOne = phoneNum / 1000000;
        long long groupTwo = (phoneNum / 10000) - (groupOne * 1000);
        long long groupThree  = (phoneNum) - (groupOne * 1000000) - (groupTwo * 1000);

        cout << "(" << groupOne << ") " << groupTwo << "-" << groupThree << endl;
    }

    void printRec(const struct PhoneRec record , size_t rowNum , const char* filter){
        if(filter != nullptr){
            if (strstr(record.firstName, filter) != nullptr || strstr(record.lastName, filter) != nullptr) {
                cout << rowNum++ << ": " << record.firstName << " " << record.lastName << " ";
                printNum(record.phoneNum);
            }
     
        }     
    }

    bool readRec(struct PhoneRec& record, FILE* fp){
        bool result = false;
        if(fscanf(fp, "%s %s %lld", record.firstName, record.lastName, &record.phoneNum) == 3){
            result = true;
        }
        return result;
    }

    void printBook(struct PhoneRec* phoneBook[], size_t bookSize ,const char* filter) {
        size_t rowNumber = 0;

        for (rowNumber; rowNumber < bookSize; rowNumber++){
            printRec(*phoneBook[rowNumber] , rowNumber+1 ,filter);
        }
    }

    void setPointers(struct PhoneRec* phoneBookPtr[], struct PhoneRec phoneBook[], size_t arrSize) {
        for (size_t i = 0; i < arrSize; ++i) {
            phoneBookPtr[i] = &phoneBook[i];
        }
    }

    void sortPhoneBook(struct PhoneRec* phoneBookPtr[] , size_t arrSize , bool sortLastNames){
        for (size_t i = 0; i < arrSize - 1 ; i++)
        {
            for (size_t j = i + 1 ; j < arrSize ; j++)
            {
                if(sortLastNames){
                    if(strcmp(phoneBookPtr[i]->lastName, phoneBookPtr[j]->lastName) > 0) {
                        struct PhoneRec* temp = phoneBookPtr[i];
                        phoneBookPtr[i] = phoneBookPtr[j];
                        phoneBookPtr[j] = temp;
                    }
                }else{
                    if(strcmp(phoneBookPtr[i]->firstName, phoneBookPtr[j]->firstName) > 0) {
                        struct PhoneRec* temp = phoneBookPtr[i];
                        phoneBookPtr[i] = phoneBookPtr[j];
                        phoneBookPtr[j] = temp;
                    }
                }
            }
        }
        
    }
}