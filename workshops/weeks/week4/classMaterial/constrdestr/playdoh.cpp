// playdoh.cpp
//

#include <iostream>
#include "playdoh.h"
using namespace std;

#define debug

//Default constructor
playdoh::playdoh(){
  #ifdef debug
  cout << "Inside playdoh default constr" << endl;
  #endif
  colour = 'x';
  weight = 0;
}

// Destructor
playdoh::~playdoh(){
  #ifdef debug
  cout << "Inside the destructor: " << colour << endl;
  #endif
}

// Overloaded constructor
playdoh::playdoh(char c, int w){
  #ifdef debug
  cout << "Inside overloaded constr" << endl;
  #endif
  setColour(c);
  setWeight(w);
}

bool playdoh::isEmpty() const{ // Check if the Playdoh is empty
  if (weight == 0)
    return true;
  else
    return false;
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

// No arg display
void playdoh::display() const{

  if (weight == 0)
  //if (isEmpty())
    cout << "This is an empty jar of playdoh" << endl;
  else
    cout << "Playdoh, colour: " << colour << " weight "
       << weight << endl; 
}

// One arg display
void playdoh::display(const playdoh& p) const{

  cout << "This playdoh, weight: " << weight 
       << " colour: " << colour << endl;

  cout << "Param playdoh, weight: " << p.weight 
       << " colour: " << p.colour << endl;
}

void playdoh::makePlaydoh(){

  char col;
  int wei = 0;

  cout << "Let's make playdoh" << endl;
  cout << "Enter a char for the colour: ";
  cin >> col;
  cout << "Enter a int for the weight: ";
  cin >> wei;

  colour = col;
  weight = wei;

  playdoh temp(col, wei); // why this?
  *this = temp;
}

playdoh playdoh::retCopy(){
  return *this;
}
playdoh& playdoh::retRef(){
  return *this;
}

//#define ex1
//#define ex2
#define ex3
//#define ex4

int main(){

#ifdef ex1
  cout << "Example 1" << endl;

  playdoh* parr = nullptr;
  parr = new playdoh[3];
  parr[0].setColour('g');
  parr[1].setColour('y');
  parr[2].setColour('w');
  parr[0].setWeight(1);
  parr[1].setWeight(2);
  parr[2].setWeight(3);

  playdoh p1;
  p1.display();
  p1.setColour('r');
  p1.setWeight(100);

  playdoh p2;
  p2.setColour('b');
  p2.setWeight(200);

  // Class Privacy
  delete[] parr;

  p1.display();
  p2.display();
  p1.display(p2);
#endif

#ifdef ex2
  cout << "Example 2" << endl;
  playdoh p3; 
  p3.setColour('g');
  p3.setWeight(300);
  p3.display();

  playdoh p4('g', 4000);
  p4.display();

  playdoh p5('p');
  p5.display();
#endif

#ifdef ex3
  cout << "Example 3" << endl;
  playdoh p5;
  p5.makePlaydoh();
  p5.display();
#endif

#ifdef ex4
  cout << "Example 4" << endl;
  playdoh p6('b', 200);
  playdoh p7;

  cout << "Original" << endl;
  p7 = p6; 

  cout << "retCopy" << endl;
  p7 = p6.retCopy(); // p7 = p6; p7 = copy of p6; 
  p7.setColour('z');
  p6.display();
  p7.display();

  cout << "retRef" << endl;
  p7 = p6.retRef(); // p7 = p6
  p7.setColour('z');
  p6.display();
  p7.display();
#endif

}

