/* Citation and Sources...
Final Project Milestone 1: 
Module: Menu
Filename: menu.cpp
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

#include "Menu.h"
#include "constants.h"
#include "Utils.h"
using namespace seneca;

void MenuItem::setSafe(){
    m_content = nullptr;
    m_indent = 0;
    m_indentSize = 0; 
    m_row = -1;
    m_isSafeEmpty = 1;
}

MenuItem::MenuItem(){
    setSafe();
}

MenuItem::MenuItem(const char* content ,const  int indent ,const int indentSize ,const int row){
    if(!content || ut.isspace(content) || indent > 4 || indentSize > 4 || row > MaximumNumberOfMenuItems){
        setSafe();
    }else{
        m_content = new char[ut.strlen(content) + 1];
        ut.strcpy(m_content, content);
        m_indent = indent;
        m_indentSize = indentSize;
        m_row = row;
    }

}

MenuItem::~MenuItem(){
    delete[] m_content;
    setSafe();
}

ostream& MenuItem::display(ostream& os) const{
    if(m_content != nullptr || !m_isSafeEmpty){
        for (int i = 0; i < m_indent; i++)
        {
            for (int j = 0; j < m_indentSize; j++)
            {
                os << ' ';
            } 
        }

        if(m_row >= 0){
            if (m_indent > 0 || m_indentSize > 0){
                os << ' ';
            }
            os << m_row << "- ";
        }
        
        /**
         * -->>> START of citation STARTSPACE
         * This Space skip have been formatted by using
         * a part of utils isspace function
         */
        const char* start = m_content;
        while (*start && isspace(*start)) {
            ++start;
        }
        // <<<--- END of citation STARTSPACE
        os << start;
        
    }else{
        os << "??????????";
    }


    return os;
}
