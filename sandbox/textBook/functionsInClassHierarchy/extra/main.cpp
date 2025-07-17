#include "item.hpp"

int main(){
    Item* stuff[2];
    stuff[0] = new Book("Harry Potter: chapter 1" , 500);
    stuff[1] = new DVD("Ben10" , 1000);

    for (size_t i = 0; i < 2; i++){
        stuff[i]->display();

        cout << "\n-------------------------------\n" << endl;
    };
    
}