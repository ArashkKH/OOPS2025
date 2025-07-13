/* Citation and Sources...
Final Project Milestone 1: 
Module: Menu Header
Filename: menu.h
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
Revision History
----------------------------------------------------------------------------
Date        Reason
2025/07/12  Project Initiation and submission of mileStone 1
----------------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
ANY part that is NOT done by me will be having a comment to point it out 
and include the citation of that code.
----------------------------------------------------------------------------
*/

#if !defined(MENU__H)
#define MENU__H
#include <iostream>

using namespace std;

namespace seneca{


    class MenuItem{
        char*   m_content;
        int     m_indent;
        int     m_indentSize;
        int     m_row;  
        bool    m_isSafeEmpty;
        
        // utils
        
        void setSafe();

    public:
        MenuItem();
        MenuItem(const char* content ,const int indent ,const int indentSize ,const int row);
        ~MenuItem();

        /**
         * -->>> START of citation DELETION
         * This was added in the process of debugging using Ai copilot
         */
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        // <<<--- END of citation DELETION
        
        operator bool() const{
            return m_content != nullptr && !m_isSafeEmpty;
        }

        ostream& display(ostream& ostr = cout) const;
    };


};

#endif 
