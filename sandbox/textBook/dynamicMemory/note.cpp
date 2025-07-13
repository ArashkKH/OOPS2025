#include "note.hpp"

#ifndef NOTE_CPP
#define NOTE_CPP

#include <cstring>

using namespace std;

Note::Note(){
    m_length = 0;
    m_desc = new char[1];
    m_desc[0] = '\0';
}
Note::Note(const char* desc){
    m_length = strlen(desc);
    m_desc = new char[m_length + 1];
    strcpy(m_desc , desc);
    m_desc[m_length] = '\0';
}
Note::Note(const Note& src){
    m_length = src.m_length;
    m_desc = new char[m_length + 1];
    strcpy(m_desc , src.m_desc);
}
Note::~Note(){
    delete[] m_desc;
    m_desc = nullptr;
}

void Note::display() const{
    cout << "Description: " << m_desc << " - Length:" << m_length << endl ; 
}
void Note::read(){
    char temp[100];
    cout << "please enter the Description:";
    cin >> temp;
    m_length = strlen(temp);
    delete[] m_desc;
    m_desc = new char[m_length + 1];
    strcpy(m_desc , temp);
}

istream& operator>>(istream& is , Note& note){
    note.read();
    return is;
}

ostream& operator<<(ostream& os , const Note& note){
    note.display();
    return os;
}


#endif // !NOTE_CPP