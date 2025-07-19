/* Citation and Sources...
Final Project Milestone 2: 
Module: Menu Header
Filename: menu.h
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
Revision History
----------------------------------------------------------------------------
Date        Reason
2025/07/12  Project Initiation and submission of mileStone 1
2025/07/18  Project Milesone 2 : Adding Menu Module
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


    
    class Menu{
        
        int m_ident;
        int m_indentSize;
        int m_menuItemQty;
        
        MenuItem m_title;
        MenuItem m_exit;
        MenuItem m_entryPrompt;

        MenuItem* m_menuOptions[MaximumNumberOfMenuItems];

        public:
            Menu(const char* title , const char* exitOption , int indent = 0 , int indentSize = 3);
            

    };
    class MenuItem{
        char*   m_content;
        int     m_indent;
        int     m_indentSize;
        int     m_row;  
        bool    m_isSafeEmpty;
        
        // utils
        
        void setSafe();
        
        MenuItem();
        MenuItem(const char* content ,const int indent ,const int indentSize ,const int row);
        ~MenuItem();
        
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        
        operator bool() const{
            return m_content != nullptr && !m_isSafeEmpty;
        }

        ostream& display(ostream& ostr = cout) const;

        friend Menu;
    };



};

#endif 
