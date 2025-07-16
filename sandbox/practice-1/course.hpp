#if !defined(COURSE__HPP)
#define COURSE__HPP

#include <iostream>
using namespace std;


class Course{
    char* m_code;
    char* m_title;
    int m_credit;

public:
    Course();
    Course(const char* , const char* , int);
    Course(const Course&);
    
    Course& operator=(const Course&);
    ~Course();


    void display(ostream& os = cout);
    friend ostream& operator<<(ostream& , const Course&);
    friend istream& operator>>(istream& , Course&);
};

#endif // COURSE__HPP
