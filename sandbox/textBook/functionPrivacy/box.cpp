#include "box.hpp"
#include <cstring>

using namespace std;

Box::Box(){
    m_label = new char[1];
    m_label[0] = '\0';
}
Box::~Box(){
    delete[] m_label;
    m_label = nullptr; 
}

void Box::setWeight(double w){
    m_weight = w;
}

double Box::getWeight() const{
    return m_weight;
}
void Box::setLabel(const char* text){
    delete[] m_label;
    m_label = new char[strlen(text) + 1 ];
    strcpy(m_label , text);
}

const char* Box::getLabel() const{
    return m_label;
}

void Box::display() const{
    cout << "Label: " << m_label << " - Weight: " << m_weight << endl;
}