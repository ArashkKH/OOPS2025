#include <iostream>
#include <cstring>
#include "item.hpp"


Item::Item(){
    initItemName();
}

Item::Item(char* name){
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

Item::~Item(){
    deleteItemName();
}

Book::Book(){
    Item::initItemName();
}

Book::Book(char* title , int pages){
    Item::initItemName(title);
    m_pageCount = pages;
}

void Book::display(ostream& os) const{
    os << "Item Type:Book\n==============\nTitle: " << m_title << "\nPage Count: "<< m_pageCount << endl;
}

Book::~Book(){
    Item::deleteItemName();
}

DVD::DVD(){
    Item::initItemName();
}

DVD::DVD(char* name , int duration){
    Item::initItemName(name);
    m_duration = duration;
}

void DVD::display(ostream& os) const {
    os << "Item Type:DVD disc\n==============\nTitle: " << m_title << "\nContent Duration: "<< m_duration << endl;
}

DVD::~DVD(){
    Item::deleteItemName();
}

/* ---------------------------------- utils --------------------------------- */