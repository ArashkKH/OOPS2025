/***********************************************************************
// OOP244 Workshop 6 lab
// 
// File	Numbers.cpp
// Version 1.0
// Author	Arash Kheirollahi
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Numbers.h"
using namespace std;

namespace seneca {

   Numbers::Numbers(const char* filename) {
      // implemented in prof file
   }

   Numbers::Numbers(const Numbers& other) {
      setEmpty();
      m_isOriginal = false;
      if (!other.isEmpty()) {
         m_numCount = other.m_numCount;
         m_numbers = new double[m_numCount];
         for (int i = 0; i < m_numCount; ++i) {
            m_numbers[i] = other.m_numbers[i];
         }
      }
   }

   Numbers& Numbers::operator=(const Numbers& other) {
      if (this != &other) {
         delete[] m_numbers;
         setEmpty();
         m_isOriginal = false;
         if (!other.isEmpty()) {
            m_numCount = other.m_numCount;
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; ++i) {
               m_numbers[i] = other.m_numbers[i];
            }
         }
      }
      return *this;
   }

   Numbers::~Numbers() {
      if (m_isOriginal && !isEmpty()) {
         save();
      }
      delete[] m_numbers;
      delete[] m_filename;
   }

   int Numbers::numberCount() const {
      ifstream file(m_filename);
      int count = 0;
      char ch;
      while (file.get(ch)) {
         if (ch == '\n') count++;
      }
      return count;
   }

   bool Numbers::load() {
      ifstream file(m_filename);
      if (!file) return false;

      m_numCount = numberCount();
      if (m_numCount == 0) return false;

      m_numbers = new double[m_numCount];
      for (int i = 0; i < m_numCount; ++i) {
         file >> m_numbers[i];
      }
      file.close();
      return !file.fail();
   }

   void Numbers::save() {
      if (m_isOriginal && !isEmpty()) {
         ofstream file(m_filename);
         for (int i = 0; i < m_numCount; ++i) {
            file << m_numbers[i] << endl;
         }
      }
   }

   void Numbers::setEmpty() {
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
      m_isOriginal = false;
   }

   void Numbers::sort() {
      // implemented in prof file
   }

   double Numbers::average() const {
      // implemented in prof file
      return 0.0;
   }

   double Numbers::max() const {
      // implemented in prof file
      return 0.0;
   }

   double Numbers::min() const {
      // implemented in prof file
      return 0.0;
   }

   Numbers& Numbers::operator+=(double value) {
      double* temp = new double[m_numCount + 1];
      for (int i = 0; i < m_numCount; ++i) {
         temp[i] = m_numbers[i];
      }
      temp[m_numCount] = value;
      delete[] m_numbers;
      m_numbers = temp;
      m_numCount++;
      sort();
      return *this;
   }

   ostream& Numbers::display(ostream& os) const {
      if (isEmpty()) {
         os << "Empty list" << endl;
      } else {
         os << "=============================" << endl;
         if (m_isOriginal) {
            os << m_filename << endl;
         } else {
            os << "*** COPY ***" << endl;
         }
         for (int i = 0; i < m_numCount; ++i) {
            os << m_numbers[i];
            if (i != m_numCount - 1) os << ", ";
         }
         os << endl << "-----------------------------" << endl;
         os << "Total of " << m_numCount << " number(s)" << endl;
         os << "Largest number:  " << fixed << setprecision(2) << max() << endl;
         os << "Smallest number: " << fixed << setprecision(2) << min() << endl;
         os << "Average:         " << fixed << setprecision(2) << average() << endl;
         os << "=============================" << endl;
      }
      return os;
   }

   ostream& operator<<(ostream& os, const Numbers& N) {
      return N.display(os);
   }

   istream& operator>>(istream& is, Numbers& N) {
      double val;
      if (is >> val) {
         N += val;
      }
      return is;
   }

} // namespace seneca
