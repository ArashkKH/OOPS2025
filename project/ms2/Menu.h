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

#ifndef MENU__H
#define MENU__H
#include <iostream>
#include "constants.h"

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
        
        MenuItem();
        MenuItem(const char* content ,const int indent ,const int indentSize ,const int row);
        ~MenuItem();
        
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        
        operator bool() const{
            return m_content != nullptr && !m_isSafeEmpty;
        }

        ostream& display(ostream& ostr = cout) const;

        /**
         * based on the need of declaing in order there was some difficulties on
         * classes trying to recognize each other,
         * the orther and the use of keywork CLASS below was suggested by AI
         */

        friend class Menu;
    };
    
    class Menu{
        
        int m_indent;
        int m_indentSize;
        int m_menuItemQty;
        
        MenuItem m_title;
        MenuItem m_exit;
        MenuItem m_entryPrompt;

        MenuItem* m_menuOptions[MaximumNumberOfMenuItems];

        public:
            Menu(const char* title , const char* exitOption = "Exit" , int indent = 0 , int indentSize = 3);
            Menu& operator<<(const char* content);
            ~Menu();

            // Rule of Three
            Menu(const Menu&) = delete;
            Menu& operator=(const Menu&) = delete;

        
            size_t select() const;
    };

    size_t operator<<(ostream& ostr , const Menu& m);


};

#endif 
