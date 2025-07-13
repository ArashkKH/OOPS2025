#include "Student.hpp"

int main(){
    // double grades[] = {1.5,5.6,4.69};
    // const char* name = "Arash";
    // Student me(name , grades , 3);

    double grades[] = {12.5, 15.56, 12.75};
    GradStudent me("Arash", grades, 3 , 88.4);
    me.display();

    cin >> me;
    cout << me;
}