#include <iostream>
#include "journal.h"
#include <cstring>
using namespace std;

void Journal::display() const{
    cout << description << " - $" << amount << endl;
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

ostream& operator<<(ostream& os , const Journal& j){
    cout << "//Displaying data from user using overload operator!" << endl;
    j.display();
    return os;
}

istream& operator>>(istream& is , Journal& j){
    cout << "//Gettin data from user using overload operator!" << endl;
    j.read();
    return is;
}


