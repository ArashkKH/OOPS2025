#if !defined(STUDENT__HPP)
#define STUDENT__HPP

#include <iostream>

using namespace std;

class Student {
    private:
        char* m_name;
        double* m_grades;
        int m_numGrades;

        void memoryInit(const int name,const int grade);
        void arrCopy(double* arr1, const double* arr2, int count);
    public:
        Student(); //default constructor
        Student(const char* , const double* , int); //deep copy constructor
        Student(const Student&); //copy constructor

        Student& operator=(const Student&); //copy Assignment

        ~Student();
        
        void display() const;
        double getAverage() const;



};
#endif //  