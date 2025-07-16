#include <iostream>
#include <cstring>
#include "item.hpp"


Item::Item(){
    initItemName();
}

Item::Item(const char* name){
    m_title = new char[strlen(name) + 1];
    strcpy(m_title , name);   
}

void Item::initItemName(char* name){
    if(name != nullptr){
        m_title = new char[strlen(name) + 1];
        strcpy(m_title , name);
    }else{
        m_title = nullptr;
    }
}

void Item::deleteItemName(){
    delete[] m_title;
    m_title = nullptr;
}


/* ---------------------------------- utils --------------------------------- */

