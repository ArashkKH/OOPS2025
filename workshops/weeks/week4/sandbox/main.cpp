#include "headers.h"

// functions

// #define DEBUG


void person::setName(char newName[30]){
    strcpy(name , newName);
    #ifdef DEBUG
    cout << "Now Testing setName()" << endl;
    #endif // DEBUG
}

void person::modHealth(int healthD){
    health += healthD;
    if(healthD < 0){
        cout << "Damaging Character by " << health * -1 << endl;
    }else if(health > 0){
        cout << "Healing Character by " << health << endl;
    }else{
        cout << "No Damage Taken!" << endl;
    }
    cout << "New health:" << health << endl;
    
    #ifdef DEBUG
    cout << "Now Testing modHealth()" << endl;
    #endif // DEBUG
}

void person::modMoney(int moneyD){

    #ifdef DEBUG
    cout << "Now Testing modMoney()" << endl;
    #endif // DEBUG
}
void person::checkPerson(){
    


    
    #ifdef DEBUG
    cout << "Now Testing checkPerson()" << endl;
    #endif // DEBUG
}


main(){
    struct person armita;


    armita.modHealth(-50);
}
