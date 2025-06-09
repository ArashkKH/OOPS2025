#include <iostream>
#include <cstring>


class Person{
    char* m_name;
    char* m_lastName;
    char* m_gender;
    int* m_age;

    public:
        Person(); //constructor
        Person(Person* personInfo); //contructor with value
        Person(const char* name); //contructor with value
        ~Person();//destructor

        void setName(char name[10]);
        void setLastName(char lname[10]);
        void setGender(char g);
        void setAge(int age);
      
        void display() const;
    };

void printPercent(int num);