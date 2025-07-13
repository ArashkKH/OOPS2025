#include "Student.hpp";


int main(){
    // double grades[] = {1.5,5.6,4.69};
    // const char* name = "Arash";
    // Student me(name , grades , 3);

    const char* name = "Arash";
    double grades[] = {12.5, 15.56, 12.75};
    Student me(name, grades, 3);
    me.display();  
    return 0;
}