#if !defined(STUDENT__HPP)
#define STUDENT__HPP

#include <iostream>

class Student{
    char* m_name;
    Course* m_courses;
    int m_numCourses;

public:
    Student();
    Student(const char* , const Course* , int);
    Student(const Student&);
    Student& operator=(const Student&);
    virtual ~Student();

    
};

#endif // STUDENT__HPP
