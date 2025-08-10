/* Citation and Sources...
Final Project Milestone 2: 
Module: Menu
Filename: menu.cpp
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




#include "Menu.h"
#include "constants.h"
#include "Utils.h"
namespace seneca{

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
        if(!content || ut.isspace(content) || indent > 4 || indentSize > 4 || row > int(MaximumNumberOfMenuItems)){
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
                if ((m_indent > 0 || m_indentSize > 0) && m_row < 10){
                    os << ' ';
                }
                os << m_row << "- ";
            }
            const char* start = m_content;
            while (*start && isspace(*start)) {
                ++start;
            }
            os << start;
        }else{
            os << "??????????";
        }
        return os;
    }
    //======================== MS2 =======================
    // the instant allocation was suggested by AI, I was doing it the long way :)
    Menu::Menu(const char* title , const char* exitOption, int indent , int indentSize)
    : m_indent(indent)
    , m_indentSize(indentSize)
    , m_menuItemQty(0)
    , m_title(title , indent , indentSize , -1)
    , m_exit(exitOption , indent , indentSize , 0)
    , m_entryPrompt("> " , indent , indentSize , -1)
    {
        for (size_t i = 0; i < MaximumNumberOfMenuItems; i++)
        {
            m_menuOptions[i] = nullptr;
        }
        
    }



    Menu& Menu::operator<<(const char* content){
        if(m_menuItemQty < int(MaximumNumberOfMenuItems)){
            m_menuOptions[m_menuItemQty] = new MenuItem(
                content , m_indent , m_indentSize , m_menuItemQty + 1
            );
            ++m_menuItemQty;
        }

        return *this;
    }

    Menu::~Menu(){
        for (int i = 0; i < m_menuItemQty; ++i)
        {
            delete m_menuOptions[i];
            m_menuOptions[i] = nullptr;
        }
    }

    size_t Menu::select() const{
        if(m_title){
            m_title.display()<<endl;
        }

        for (int i = 0; i < m_menuItemQty; ++i)
        {
            if(m_menuOptions[i]){
                m_menuOptions[i]->display()<<endl;
            }
        }
        

        if(m_exit){
            m_exit.display()<<endl;
        }

        if(m_entryPrompt){
            m_entryPrompt.display();
        }

        return size_t(ut.getInt(0 , m_menuItemQty));
    }

    size_t operator<<(ostream& ostr, const Menu& m) {
        if (&ostr == &cout) {
            return m.select();
        }
        return 0;
    }


//======================== MS2 =======================

}