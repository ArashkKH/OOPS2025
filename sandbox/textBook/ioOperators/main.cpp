#include "Student.hpp"

int main(){


    const char* name = "Arash";
    double grades[] = {12.5, 15.56, 12.75};
    Student me(name, grades, 3);
    me.display();


    cin >> me;
    cout << me;

}