#include "zoo.hpp"
#include <iostream>
#include <cstring>

void Animal::init(const char*name , const char*sound ){
        m_name = new char[strlen(name) + 1];
        m_sound = new char[strlen(sound) + 1];

        strcpy(m_name , name);
        strcpy(m_sound , sound);       
}

Animal::Animal(){
    m_name = nullptr;
    m_sound = nullptr;
}

Animal::Animal(const char* name , const char* sound){
    init(name , sound);
}

Animal::~Animal(){
    delete[] m_name;   
    delete[] m_sound;
    
    m_name = nullptr;
    m_sound = nullptr;
}

void Animal::makeSound(std::ostream& os) const{
    os << m_name << " is an Animal!\n" << m_name << "says: " << m_sound << std::endl;
}

Lion::Lion(){
    m_name = nullptr;
    m_sound = nullptr;
}

Lion::Lion(const char* name , const char* sound){
    init(name , sound);
}

Lion::~Lion(){
    delete[] m_name;   
    delete[] m_sound;
    m_name = nullptr;
    m_sound = nullptr;
}

void Lion::makeSound(std::ostream& os) const{
    os << m_name << " is a Lion!\n" << m_name << "Roars: " << m_sound << std::endl;
}


// 
Cat::Cat(){
    m_name = nullptr;
    m_sound = nullptr;
}

Cat::Cat(const char* name , const char* sound){
    init(name , sound);
}

Cat::~Cat(){
    delete[] m_name;   
    delete[] m_sound;
    m_name = nullptr;
    m_sound = nullptr;
}

void Cat::makeSound(std::ostream& os) const{
    os << m_name << " is a Cat!\n" << m_name << "Whispers: " << m_sound << std::endl;
}
// 
Dog::Dog(){
    m_name = nullptr;
    m_sound = nullptr;
}

Dog::Dog(const char* name , const char* sound){
    m_name = new char[strlen(name) + 1];
    m_sound = new char[strlen(sound) + 1];

    strcpy(m_name , name);
    strcpy(m_sound , sound);
}

Dog::~Dog(){
    delete[] m_name;   
    delete[] m_sound;
    m_name = nullptr;
    m_sound = nullptr;
}

void Dog::makeSound(std::ostream& os) const{
    os << m_name << " is a Dog!\n" << m_name << "Barks: " << m_sound << std::endl;
}