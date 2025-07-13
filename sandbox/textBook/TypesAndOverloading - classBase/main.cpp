#include "journal.h"
#include <iostream>
using namespace std;



int main(){
    Journal entry;
    entry.read();
    entry.display();
    cout << endl << "================" << endl;

    Journal lunch("Lunch" , 15.75);
    lunch.display();

    cout << "Using overloaded operators" << endl;

    Journal overloaded;

    cin >> overloaded;
    cout << overloaded;
}

