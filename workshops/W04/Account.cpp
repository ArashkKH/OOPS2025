/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.cpp
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// You may modify any code in this file to suit your requirements.
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Arash           12/16/2025      account core file for defining the constructors and functions
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::cpyName(const char* src) {
      int i;
      for (i = 0; src && src[i] && i < NameMaxLen; i++) {
         m_holderName[i] = src[i];
      }
      m_holderName[i] = char(0);
   }
   bool Account::isValidNumber(int number) const {
      return number >= 10000 && number <= 99999;
   }
   Account::Account(const char* holderName) {  
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0]) {
         cpyName(holderName);
         m_number = 0;
      }
   }
   Account::Account(const char* holderName, int number, double balance ) {
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0] && isValidNumber(number)
         && balance > 0) {
         cpyName(holderName);
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout.fill(' ');
         cout.width(NameMaxLen);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " | ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << " ";
         cout.fill(' ');
         cout.width(30);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " |  NEW  |         0.00 ";
      }
      else {
         cout << " Bad Account                    | ----- | ------------ ";
      }
      return cout;
   }


   Account::operator bool() const{
      return (isValidNumber(m_number) && m_balance >= 0 && m_holderName[0] != '\0');
   }

   Account::operator int() const{
      return m_number;
   }

   Account::operator double() const{
      return m_balance;
   }

   Account::operator const char *() const{
      return m_holderName;
   }

   // subsripts
   char& Account::operator[](int index){
      index = index % (NameMaxLen + 1);
      return m_holderName[index];
   }

   const char Account::operator[](int index) const{
      index = index % (NameMaxLen + 1);
      return m_holderName[index];  
   }

   // Unaries
   bool Account::operator~() const{
      return (m_number == 0);
   }

   Account& Account::operator++(){
      if(*this){
         m_balance++;
      }
      return *this;
   }

   Account Account::operator++(int) {
      Account temp = *this;
      ++(*this);
      return temp;
   }

   Account& Account::operator--(){
      if(*this){
         m_balance--;
      }
      return *this;
   }

   Account Account::operator--(int){
      Account temp = *this;
      --(*this);
      return temp;
   }


   // Binary Assignments
   Account& Account::operator=(int number){
      if(m_number == 0){
         if(isValidNumber(number)){
            m_number = number;
         }else{
            *this = double(-1);
         }
      }
      return *this;
   }

   Account& Account::operator=(double balance){
      if(balance >= 0){
         m_balance = balance;
      }else{
         m_number = -1;
         m_balance = 0.0;
         m_holderName[0] = '\0';
      }

      return *this;
   }
   
   Account& Account::operator+=(double value){
      if(*this && value > 0){
         m_balance += value;
      }

      return *this;
   }
   Account& Account::operator-=(double value){
      if(*this && value > 0 && m_balance >= value){
         m_balance -= value;
      }

      return *this;
   }

   Account& Account::operator<<(Account& rhs){
      if(this != &rhs && *this && rhs){
         m_balance += rhs.m_balance;
         rhs-=(rhs.m_balance);
      }

      return *this;
   }

      Account& Account::operator>>(Account& rhs){
      if(this != &rhs && *this && rhs){
         rhs.m_balance += m_balance;
         m_balance = 0.0;
      }

      return *this;
   }
}