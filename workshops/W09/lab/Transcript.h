/**
 *  OOP244 Workshop 9 lab: Marks module
 *  File	Transcript.cpp
 *  Version 1.0
 *  Started by Fardad
 *  Author Arash Kheirollahi
 *  Description:
 *      The Transcript class extends the Marks class 
 *      by introducing two additional attributes
 *      
 *  Revision History:
 *  -----------------------------------------------------------
 *  Name            Date            Reason
 *  0.01           2025-07-31      Workshop submission
 ___________________________________________________________ */
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
using std::ostream;
using std::cout;

namespace seneca {
   class Transcript :
      public Marks {
      // character pointer student name
      char* m_stdName = nullptr;
      // unsigned integer or size_t student number
      unsigned int m_stdNum; 
   public:
      // Constructor
      Transcript(const char* name, unsigned int num);
      // Rule of Three
      Transcript(const Transcript& src);
      Transcript& operator=(const Transcript& src);
      // Destructor
      ~Transcript();

      ostream& display(ostream& ostr = cout)const;

   };
}
#endif // !SENECA_TRANSCRIPT_H


