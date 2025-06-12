/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.h
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Arash           12/16/2025      headers of the account file
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   const int NameMaxLen = 30;
   class Account {
      double m_balance;
      int m_number;
      char m_holderName[NameMaxLen + 1];
      void cpyName(const char* src); // copies the src into the m_holderName array
      bool isValidNumber(int number)const; // returns true if number is a valid account number
   public:
      Account(const char* holderName = nullptr);
      Account(const char* holderName, int number, double balance);
      std::ostream& display()const;



      // operators
      // typeConversions
      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char*() const;

      // Subscriptions
      char& operator[](int index);
      const char operator[](int index) const;

      // Unaries
      bool operator~() const;
      Account& operator++();
      Account operator++(int);
      Account& operator--();
      Account operator--(int);

      // Binary Assignments
      Account& operator=(int);
      Account& operator=(double);
      Account& operator+=(double);
      Account& operator-=(double);
      Account& operator<<(Account& rhs);
      Account& operator>>(Account& rhs);
   };   
}
#endif // SENECA_ACCOUNT_H_