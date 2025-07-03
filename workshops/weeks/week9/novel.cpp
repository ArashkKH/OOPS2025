#include <iostream>
#include <string.h>
#include "novel.h"
using namespace std;


Novel::Novel(){
    // set empty stats
    title[0] = '\0';
    price = 0;
}

Novel::Novel(const char* t, double p){
    set(t , p);
}
void Novel::set(const char* t, double p){
    // validating params before doing anything
    // t must be none empty and none null, p must be > 0 and < 300
    *this = Novel();
    if(t != nullptr && t[0] != '\0' && p > 0 && p < 300 ){
        strncpy(title , t , MAX_LENGTH);
    }
}
bool Novel::isEmpty() const{
    return title[0] == '\0';
}
Novel& Novel::operator+=(double p){
    double temp = p + price;
    if(temp < 0 ){
        price = 1;
    }else if(temp > 299){
        price = 300;
    }else{
        price = temp;
    }

    return *this;
}

