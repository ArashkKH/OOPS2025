#include "header.hpp"


using namespace std;

//======================== natives =======================
Person::Person() {
  m_name = new char[10];
  m_lastName = new char[10];
  m_gender = new char;
  m_age = new int;

  cout << "a new blank Person was created" << endl;
}



Person::Person(struct Person* personInfo) {
  cout << "seems like you are trying to duplicate a person" << endl << "lets see their info:" << endl ;
  personInfo->display();
  cout << "====================" << endl;
  strcpy(m_name , personInfo->m_name);
  strcpy(m_lastName , personInfo->m_lastName);
  m_gender = personInfo->m_gender;
  m_age = personInfo->m_age;
  cout << "a new Person was created called: " << *m_name << " " << m_lastName <<  endl;
}



Person::Person(const char* name) {
  m_name = new char[strlen(name) + 1];
  strcpy(m_name , name);
  cout << "a new Person was created called: " << *m_name << endl;
}

Person::~Person(){
  cout << "A person has Died! RIP:" << m_name << endl; 
  cout << "collecting corps" << endl;
  
  delete[] m_name;
  printPercent((int)100/8);
  delete[] m_lastName;
  printPercent((int)200/8);
  delete[] m_gender;
  printPercent((int)300/8);
  delete m_age;
  printPercent((int)400/8);
  m_name = nullptr;
  printPercent((int)500/8);
  m_lastName = nullptr;
  printPercent((int)600/8);
  m_gender = nullptr;
  printPercent((int)700/8);
  m_age = nullptr;
  printPercent((int)800/8);

  cout << "corpse collected soccessfully" << endl << endl;
}
//======================== natives =======================


//======================== Modifiers =======================


void Person::setName(char name[10]){
  strcpy(m_name, name);
}
void Person::setLastName(char lname[10]){
  strcpy(m_lastName, lname);
}
void Person::setGender(char g){
  *m_gender = g;
}
void Person::setAge(int age){
  *m_age = age;
}

//======================== Modifiers =======================


//======================== Consts =======================
void Person::display() const{
  cout<< "heres the info about:" << endl << "Name:\t" << m_name << endl;
}
//======================== Consts =======================

void printPercent(int num){
  num > 100 || num < 0 ? throw std::runtime_error("!!!! Too much percent! !!!!") : cout << "|" ; 
  for (size_t i = 1; i < (num+1) / 5 ; i++)
  {
    cout << "O";
  }
  for (size_t i = 1; i < 21 - (num+1) / 5 ; i++)
  {
    cout << "-";
  }
  cout << "|" << endl ;
}



