#include "Student.hpp"
#include "Person.hpp"

#define HIERCHY_TEST

int main(){

    double grades[] = {12.5, 15.56, 12.75};

    #if !defined(HIERCHY_TEST)
    GradStudent me("Arash", grades, 3 , 88.4);
    me.display();

    cin >> me;
    cout << me;
    #else
    Person* people[2];
    
    people[0] = new Student("Alice" , grades , 3);
    people[1] = new GradStudent("Bob" , grades , 3 , 88.5);

    for (int i = 0; i < 2; i++){
        people[i]->display();
        cout << "--------------------------------------------------------------------" << endl;
        delete people[i];
    }
    
    #endif
}