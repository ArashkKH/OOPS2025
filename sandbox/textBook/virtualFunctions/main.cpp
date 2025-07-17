#include "zoo.hpp"

void hearAnimals(Animal* a){
    a->makeSound();
}

using namespace std;
 
int main(){
    Animal* zoo[3];

    zoo[0] = new Lion("Max" , "ROAR!!!");
    zoo[1] = new Dog("Buck" , "Woof!");
    zoo[2] = new Cat("Whiskers" , "Meow");

    for (size_t i = 0; i < 3; i++)
    {
        cout << "\n";
        hearAnimals(zoo[i]);
        cout << "\n";
    }
    

    
    return 0;
}
