/* Citation and Sources...
-----------------------------------------------------------
Workshop 03
Module: Core file for structures of W3
Filename: CC.cpp
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

#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }

   void CC::aloCopy(const char* name) {
      if (name) {
         size_t len = strlen(name);
         m_name = new char[len + 1];
         strcpy(m_name, name);
      } else {
         m_name = nullptr;
      }
   }
   void CC::deloDm() {
      delete[] m_name;
      m_name = nullptr;
   }


   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
      if (!name || strlen(name) <= 2) return false;
      if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) return false;
      if (cvv < 100 || cvv > 999) return false;
      if (expMon < 1 || expMon > 12) return false;
      if (expYear < 24 || expYear > 32) return false;
      return true;
   }

   void CC::set() {
      m_name = nullptr;
      m_number = 0;
      m_cvv = 0;
      m_expMon = 0;
      m_expYear = 0;
   }
   void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
      set(); // set to safe empty state
      if (validate(cc_name, cc_no, cvv, expMon, expYear)) {
         aloCopy(cc_name);
         m_number = cc_no;
         m_cvv = cvv;
         m_expMon = expMon;
         m_expYear = expYear;
      }
   }
   bool CC::isEmpty() const{
      return m_name == nullptr;
   }
   void CC::display() const {
      if (isEmpty()) {
         cout << "Invalid Credit Card Record" << endl;
      } else {
         display(m_name, m_number, m_expYear, m_expMon, m_cvv);
      }
   }

   CC::CC() {
            m_name = nullptr;
            m_number = 0;
            m_cvv = 0;
            m_expMon = 0;
            m_expYear = 0;
         }

   CC::CC(const char* name, unsigned long long number, short cvv, short expMon, short expYear) {
            m_name = nullptr;
            m_number = 0;
            m_cvv = 0;
            m_expMon = 0;
            m_expYear = 0;

            if (validate(name, number, cvv, expMon, expYear)) {
               aloCopy(name);
               m_number = number;
               m_cvv = cvv;
               m_expMon = expMon;
               m_expYear = expYear;
            }
          }
         
   CC::~CC() {
      deloDm();
   };
}