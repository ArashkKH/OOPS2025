#include <iostream>
#include "journal.h"
#include <cstring>
using namespace std;

void Journal::display() const{
    cout << description << " - $" << amount << endlr;
}
void Journal::read(){
    cout << "Enter Description: ";
    cin >> description ;
    cout << "Enter the amount: ";
    cin >> amount;
    cin.ignore(); //emptying input buffer
}

Journal::Journal(){
    description[0] = '\0';
    amount = 0.0;
}
Journal::Journal(const char* entryText, double entryAmount){
    strcpy(description, entryText);
    amount = entryAmount;
}


