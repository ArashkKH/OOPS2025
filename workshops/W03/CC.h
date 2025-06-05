/* Citation and Sources...
-----------------------------------------------------------
Workshop 03
Module: header file for CC.cpp
Filename: CC.h
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
V0.2    2025/5/22 Fixing Memory Leaks

-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
        
         
         // data
         char* m_name;
         unsigned long long m_number;
         short m_cvv;
         short m_expMon;
         short m_expYear;
         // methods
            //alocation and memory management
            void aloCopy(const char* name); //✅
            void deloDm();//✅
            // validation and displaying
            void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;//✅
            void prnNumber(unsigned long long no) const;//✅
            bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const;//✅

         public:
         CC();
         CC(const char* name, unsigned long long number, short cvv, short expMon = 12, short expYear = 26);
         ~CC();
         

            void set();//✅
            void set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear);//✅
            bool isEmpty() const;//✅
            void display() const;//✅
   };

}
#endif // !SENECA_CC_H_


