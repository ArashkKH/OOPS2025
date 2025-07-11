#include <iostream>
#include "journal.h"
using namespace std;

void readJournal(Journal& j){
    cout << "Enter description: ";
    cin >> j.description;
    cout << "Enter amount: ";
    cin >> j.amount;
    cin.ignore();
}

void displayJournal(const Journal& j){
    cout << j.description << " - $" << j.amount << endl;
}
void displayJournal(const Journal& j , bool withCurrencySymbol){
    cout << j.description << " - " << j.amount << endl;
}

void increaseAmountByValue(Journal j){
    j.amount++;
}
void increaseAmountByReference(Journal& j){
    j.amount++;
}
