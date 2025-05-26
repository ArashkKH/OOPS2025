#include "stdio.h"
#include "iostream"
#include "string.h"

using namespace std;


class person{
    public:
    void setName(char name[30]);
        void modHealth(int healthD); // *D = delta
        void modMoney(int moneyD);
        void checkPerson();
    private:
        char name[30];
        int health = 100;
        int money = 10000;
};


