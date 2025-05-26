//playdoh.cpp
//

#include <iostream>
#include "playdoh.h"
using namespace std;

int weight = 4000; // Global

void display() {
  cout << "Inventory" << endl;
}

void playdoh::setColour(char c){
  colour = c; 
}

void playdoh::setWeight(int w){
  weight = w; 
}

void playdoh::display() const{
  ::display();
  cout << "Playdoh Info" << endl;
  cout << "Colour: " << colour << endl; 
  cout << "Weight: " << weight << endl; 
  cout << "Global Weight: " << ::weight << endl;
}

int main(){
  playdoh p;
  p.setColour('r');
  //p.colour = 55; // public access
  p.setWeight(100);
  p.display();
}
