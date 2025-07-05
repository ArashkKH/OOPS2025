/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File	Mark.cpp
// Version 1.0
// Date	2025/06/12
// Author	partially done by Fardad Soleimanloo and Arash Kheirollahi
// Description    Mark main file containing functions
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// v1              07/03/2025      Workshop assignment
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cmath> //used ai help
#include "Mark.h"
using namespace std;
namespace seneca {
   bool Mark::isValid()const {
      return  (m_value >= 0 && m_value <= 100);
   }

   Mark::Mark(int value, char type) {
      *this = type;
      m_value = double(value);
   }

   Mark::Mark(double value) {
      m_type = MARK;
      m_value = value;
   }

   Mark& Mark::operator+=(const Mark& M) {
      m_value += M.m_value;
      return *this;
   }

   Mark& Mark::operator-=(const Mark& M) {
      m_value -= M.m_value;
      return *this;
   }

   Mark Mark::operator+(const Mark& M) const {
      return Mark(*this) += M;
   }

   Mark Mark::operator-(const Mark& M) const {
      return Mark(*this) -= M;
   }

   Mark& Mark::operator/=(int other) {
      m_value = m_value / other;
      return *this;
   }

   Mark Mark::operator/(int other) const {
      return Mark(m_value / other);
   }

   Mark& Mark::operator=(int value) {
      m_value = value;
      return *this;
   }

   Mark& Mark::operator=(char type) {
      m_type = MARK;
      if (type == GRADE || type == GPA) {
         m_type = type;
      }
      return *this;
   }

   double Mark::raw() const {
      return m_value;
   }

   Mark::operator int() const {
      int value = -1;
      if (isValid()) {
         value = int(std::round(m_value < 0 ? 0 : m_value));
      }
      return value;
   }

   Mark::operator bool() const {
      return isValid();
   }

   Mark::operator double() const {
      double gpa = 0;
      if (!isValid()) gpa = -1;
      else gpa = m_value * 0.04;
      return gpa;
   }

   Mark::operator const char* () const {
      char* grade = const_cast<char*>(m_grade);
      int value = int(*this);
      grade[1] = grade[2] = '\0';

      if (value < 0 || value > 100) grade[0] = 'X';
      else if (value >= 90) grade[0] = 'A', grade[1] = '+';
      else if (value >= 80) grade[0] = 'A';
      else if (value >= 75) grade[0] = 'B', grade[1] = '+';
      else if (value >= 70) grade[0] = 'B';
      else if (value >= 65) grade[0] = 'C', grade[1] = '+';
      else if (value >= 60) grade[0] = 'C';
      else if (value >= 55) grade[0] = 'D', grade[1] = '+';
      else if (value >= 50) grade[0] = 'D';
      else grade[0] = 'F';

      return m_grade;
   }

   std::ostream& Mark::display(std::ostream& os) const {
      if (!isValid() && !(*this)) {
         os << ((m_type == GRADE) ? "**" : "***");
      } else {
         switch (m_type) {
         case GPA: {
            double gpa = double(*this);
            int whole = int(gpa);
            int fraction = int((gpa - whole) * 10 + 0.5);

            // if (whole < 10) os << '0';
            os << whole << '.' << fraction;
            break;
         }
         case MARK: {
            int val = int(*this);
            if (val < 10) os << "__" << val;
            else if (val < 100) os << '_' << val;
            else os << val;
            break;
         }
         case GRADE: {
            const char* grade = operator const char *();
            os << grade;
            if (grade[1] == '\0') os << "  ";
            else os << ' ';
            break;
         }
         default:
            break;
         }
      }
      return os;
   }

   std::ostream& display(const Mark& mark, char type, std::ostream& os) {
      Mark temp = mark;
      temp = MARK;
      temp.display(os);
      if (type != MARK) {
         os << ": ";
         temp = type;
         temp.display(os);
      }
      return os;
   }

   std::ostream& operator<<(std::ostream& os, const Mark& mark) {
      return mark.display(os);
   }

   std::istream& operator>>(std::istream& is, Mark& mark) {
      int temp;
      char next;
      bool done = false;

      while (!done) {
         if (!(is >> temp)) {
            cout << "Invalid integer, try again.\n> ";
            is.clear();
            is.ignore(1000, '\n');
         } else {
            next = is.get();
            if (next != '\n') {
               cout << "Invalid trailing characters. Please enter only an integer.\n> ";
               is.ignore(1000, '\n');
            } else if (temp < 0 || temp > 100) {
               cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
            } else {
               mark = temp;
               mark = MARK;
               done = true;
            }
         }
      }
      return is;
   }

   std::ifstream& operator>>(std::ifstream& is, Mark& mark) {
      int value;
      char type;
      if (is >> value) {
         if (is.get() == ',') {
            if (is >> type) {
               mark = value;
               mark = type;
            }
         }
      }
      return is;
   }

   double operator+(double value, const Mark& mark) {
      return value + double(mark);
   }

   int operator+(int value, const Mark& mark) {
      return value + int(mark);
   }

   double operator-(double value, const Mark& mark) {
      return value - double(mark);
   }

   int operator-(int value, const Mark& mark) {
      return value - int(mark);
   }

   double operator/(double value, const Mark& mark) {
      return value / mark.m_value;
   }

   int operator/(int value, const Mark& mark) {
      return value / int(mark.m_value + 0.5);
   }
}
