#include "header.h"
using namespace std;
#define THIS

void playdoh::setColor(char c){
    #ifndef THIS
    color = c;
    #endif // THIS


    #ifdef THIS
    this->color = c;
    #endif // THIS  
}

void playdoh::setWeight(int w){
    #ifndef THIS
    weight = w;
    #endif // THIS

    
    #ifdef THIS
    this->weight = w;
    #endif // THIS
}

void playdoh::display() const{  //you should also add const here as well!
    #ifndef THIS
   
    cout << "color  is:" << color << endl ;
    cout << "weight is:" << weight << endl ;
    
    #endif // THIS

    #ifdef THIS
    //* Let's use this for displaying the content
    cout << "THIS color  is: " << this->color << endl;
    cout << "THIS weight is: " << this->weight << endl;
    #endif // THIS
}

void playdoh::showThis() const {
    cout << "My address is:" << this << endl;
}


playdoh playdoh::makeACopy() const{
    cout<< endl << "making a Copy of this Object" << endl;
    return *this;
}




