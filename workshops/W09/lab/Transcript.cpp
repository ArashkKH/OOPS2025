/**
 *  OOP244 Workshop 9 lab: Marks module
 *  File	Transcript.cpp
 *  Version 1.0
 *  Author	Arash Kheirollahi
 *  Description:
 *      The Transcript class extends the Marks class 
 *      by introducing two additional attributes
 *      
 *  Revision History:
 *  -----------------------------------------------------------
 *  Name            Date            Reason
 *  0.01           2025-07-31      Workshop submission
 ___________________________________________________________ */


#include "Transcript.h"
#include "Utils.h"

using std::ostream;
using std::cout;


namespace seneca{

    Transcript::Transcript(const char* name , unsigned int num){
        m_stdName = new char[ut.strlen(name) + 1 ];
        ut.strcpy(m_stdName , name);
        m_stdNum = num;
    }
    Transcript::Transcript(const Transcript& src)
        : Marks(src)
    {
        m_stdName = new char[ut.strlen(src.m_stdName) + 1];
        ut.strcpy(m_stdName, src.m_stdName);
        m_stdNum = src.m_stdNum;
    }

    Transcript& Transcript::operator=(const Transcript& src){
        if(this != &src){
            Marks::operator=(src);

            delete [] m_stdName;
            m_stdName = new char[ut.strlen(src.m_stdName) + 1];
            ut.strcpy(m_stdName , src.m_stdName);
            m_stdNum = src.m_stdNum;
        }
            
        return *this;
    }
    
    Transcript::~Transcript(){
        delete [] m_stdName;
        m_stdName = nullptr;

        m_stdNum = 0;
    }    

    ostream& Transcript::display(ostream& ostr) const{
        ostr << m_stdName << " (" << m_stdNum << ")\n--------------------------------------------------------------------------\n";
        Marks::display(ostr);
        return ostr;
    }



}