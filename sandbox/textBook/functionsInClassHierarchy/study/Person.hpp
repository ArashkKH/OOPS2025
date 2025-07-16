#if !defined(PERSON__HPP)
#define PERSON__HPP

#include <iostream>

using namespace std;


class Person{

    public:
        virtual void display(ostream& os = cout) const = 0;
        virtual ~Person(){};
};

#endif // PERSON__HPP
