#include <iostream>
#include "header.hpp"

using namespace std;

int main(){
    char* firstName = new char[4];
    strcpy(firstName, "bob");
    // *firstName = "bob";
    Person* bob = new Person(firstName);
    bob->display();

    cout<< "making a copy of bob:" << endl;
    Person* alex = new Person(bob);
    
    cout<< "changin the copy Name:" << endl;
    char secondName[5] = "alex";
    alex->setName(&secondName);
    alex->display();
    delete[] secondName;
    bob->display();
    



    delete bob;
    delete alex;
    delete[] firstName;
    bob = nullptr;
    alex = nullptr;
    firstName = nullptr;
}
