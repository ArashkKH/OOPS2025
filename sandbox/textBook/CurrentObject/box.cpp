#include "box.hpp"
#include <cstring>

using namespace std;

Box::Box(){
    m_label = new char[1];
    m_label[0] = '\0';
}
Box::Box(char* label , double weight){
    m_label = new char[strlen(label) + 1];
    strcpy(m_label , label);

    m_weight = weight;
}
Box::~Box(){
    delete[] m_label;
    m_label = nullptr; 
}

Box& Box::setWeight(double w){
    m_weight = w;
    return *this;
}

double Box::getWeight() const{
    return m_weight;
}
Box& Box::setLabel(const char* text){
    delete[] m_label;
    m_label = new char[strlen(text) + 1 ];
    strcpy(m_label , text);
    return *this;
}

const char* Box::getLabel() const{
    return m_label;
}

const Box& Box::display() const{
    cout << "Label: " << m_label << " - Weight: " << m_weight << endl;
    return *this;
}