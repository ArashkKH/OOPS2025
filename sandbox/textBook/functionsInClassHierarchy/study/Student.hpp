#if !defined(STUDENT__HPP)
#define STUDENT__HPP

#include "person.hpp"
#include <iostream>

using namespace std;

class Student : public Person {
    private:
        char* m_name;
        double* m_grades;
        int m_numGrades;

        void memoryInit(const int name,const int grade);
        void arrCopy(double* tar, const double* src, int count);
    public:
        Student(); //default constructor
        Student(const char* , const double* , int); //deep copy constructor
        Student(const Student&); //copy constructor

        Student& operator=(const Student&); //copy Assignment

        ~Student();
        
        void display(ostream& os = cout) const override;
        double getAverage() const;

        friend ostream& operator<<(ostream& , const Student&);
        friend istream& operator>>(istream& , Student&);
};


class GradStudent : public Student { 
    double m_thesisScore;
public:
    GradStudent();
    GradStudent(const char*, const double* , int , double);
    void display(ostream& os = cout) const override;

    friend ostream& operator<<(ostream& os , const GradStudent& src);
    friend istream& operator>>(istream& is , GradStudent& src);
};

#endif