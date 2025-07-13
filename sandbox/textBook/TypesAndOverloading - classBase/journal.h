#include <iostream>

using namespace std;
#ifndef SENECA_JOURNAL_H
#define SENECA_JOURNAL_H

class Journal {
    char description[51];
    double amount;
public:
    Journal();
    Journal(const char* entryText, double entryAmount);
    void read();
    void display() const;

    friend ostream& operator<<(ostream& os , const Journal& j);
    friend istream& operator>>(istream& is , Journal& j);
};


#endif