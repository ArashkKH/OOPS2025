// playdoh-class.cpp
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "playdoh-dynamic.h"
using namespace std;

playdoh::playdoh() {
  cout << "In constr" << endl;
  weight = 0;
  colour = '\0';
  type = nullptr;
}

playdoh::~playdoh() {
  cout << "In destr " << colour << endl;
  delete [] type;
  type = nullptr;
}

playdoh::playdoh(char c, int w, const char* t) {
  *this = playdoh();
  setColour(c);
  setWeight(w);
  setType(t);
}

void playdoh::setColour(char colour){
  this->colour = colour;
}

void playdoh::setWeight(int w){
  if (w < 0) {
    cout << "Playdoh can't have negative weight!!!" <<endl;
    weight = 0;
  }
  else
    weight = w;
}

void playdoh::setType(const char* t) {
  if (t != nullptr) {

    // check if we have allocated memory
    int len = strlen(t);
    if (type != nullptr) 
      delete[] type;

    type = new char[len + 1];
    strcpy(type, t);
  }
}

void playdoh::display() const{

  if (weight == 0)
    cout << "This is an empty jar of playdoh" << endl;
  else
    cout << "Playdoh, colour: " << colour << " weight "
       << weight << " type: " << type << endl; 
}

int main(){

  playdoh p; // what if we could init at this point?
  playdoh p2('c', 120, "kid friendly");
  playdoh p3('d', 140);
  //p.display();
  //p.colour = 'b';
  //p.weight = 100;

  p.setColour('b');
  p.setWeight(100);
  p.setType("Clay");

  p2.display();
  p3.display();

  cout << "End of Program" << endl;
}
