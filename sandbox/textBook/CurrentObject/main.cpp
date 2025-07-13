#include "box.hpp"

int main(){
    Box box("banana" , 12);

    box.display();
    box.setWeight(12.5).setLabel("Box Of Fruits").display();
}