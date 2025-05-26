// playdoh-class.cpp
//

#include <iostream>
#include "playdoh-class.h"
using namespace std;

void playdoh::setColour(char c){
  colour = c;
}

void playdoh::setWeight(int w){
  if (w < 0) {
    cout << "Playdoh can't have negative weight!!!" <<endl;
    weight = 0;
  }
  else
    weight = w;
}

void playdoh::display() const{

  if (weight == 0)
    cout << "This is an empty jar of playdoh" << endl;
  else
    cout << "Playdoh, colour: " << colour << " weight "
       << weight << endl; 
}

int main(){

  playdoh p;
  //p.colour = 'b';
  //p.weight = 100;

  //p.setColour('b');
  //p.setWeight(-100);
  //p.display();

// #define arr
#ifdef arr
  playdoh ps[3];

  ps[0].setColour('a');
  ps[0].setWeight(1);
  ps[0].display();
  ps[2].setColour('c');
  ps[2].setWeight(3);
  ps[2].display();
  ps[1].setColour('b');
  ps[1].setWeight(2);
  ps[1].display();

  playdoh* pps[2];
  
  playdoh pa;
  pa.setColour('p');
  pa.setWeight(1000);
  
  pps[0] = &pa; 
#endif 
}
