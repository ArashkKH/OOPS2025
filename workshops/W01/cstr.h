/* Citation and Sources...
-----------------------------------------------------------
Workshop 01 
Module: header file for cstr
Filename: cstr.h
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


// cstr.h
#include <stdio.h>

#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H

namespace seneca {
// Declarations and prototypes go here
    char* strcat(char* des, const char* src);
    char tolower(char ch);
    char* tolower(char* des, const char* src);
    char* tolower(char* str);
    int strcmp(const char* s1, const char* s2);
    int strcmp(const char* s1, const char* s2, size_t len);
    char* strcpy(char* des, const char* src);
    char* strcpy(char* des, const char* src, size_t len);
    char* strncpy(char* des, const char* src, size_t len);
    size_t strlen(const char* str);
    const char* strstr(const char* str, const char* toFind);
    bool isalpha(char ch);
    bool isspace(char ch);
}
#endif // !SENECA_CSTR_H 