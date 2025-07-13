/**
 * Author:
 * Arash KH
 * LOGS:
 * 1 - Added this Class for Pracitce
 * 2 - Added Helper function of getting average Grade
 */


#include "Student.hpp"
#include <cstring>



Student::Student(){
    memoryInit(1,1);
    m_name[0] = '\0';
    m_grades[0] = 0.00;

    m_numGrades = 0;
};

Student::~Student(){
    delete[] m_name;
    delete[] m_grades;
    m_name = nullptr;
    m_grades = nullptr;
}

Student::Student(const char* name , const double* grades , int numGrades){
    memoryInit(strlen(name) + 1 , numGrades);
    strcpy(m_name , name);
    arrCopy(m_grades , grades , numGrades);
    m_numGrades = numGrades;
}

Student::Student(const Student& src){
    memoryInit(strlen(src.m_name) + 1, src.m_numGrades);
    strcpy(m_name , src.m_name);
    m_numGrades = src.m_numGrades;
    arrCopy(m_grades , src.m_grades  , m_numGrades);
}

Student& Student::operator=(const Student& src){
    if(this != &src){

        
        delete[] m_name;
        delete[] m_grades;
        memoryInit(strlen(src.m_name) + 1 , src.m_numGrades);
        strcpy(m_name , src.m_name);
        m_numGrades = src.m_numGrades;
        arrCopy(m_grades , src.m_grades  , m_numGrades);
    }
    return *this;
}



/* -------------------------------------------------------------------------- */
/*                                    Utils                                   */
/* -------------------------------------------------------------------------- */
void Student::memoryInit(const int name,const int grade){
    m_name = new char[name];
    m_grades = new double[grade];
}

void Student::arrCopy(double* arr1, const double* arr2, int count) {
    for (size_t i = 0; i < count; i++) {
        arr1[i] = arr2[i];
    }
}

void Student::display() const {
    cout << "Name: " << m_name << endl;
    cout << "===================" << endl;
    cout << "Grades:"<<  endl;
    
    for (size_t i = 0; i < m_numGrades; i++)
    {
        cout << m_grades[i] << endl;
    }
    cout << "===================" << endl;
    cout << "Avarage Score: " << getAverage() << endl;
}


double Student::getAverage() const{
    double sum = 0;
    for (size_t i = 0; i < m_numGrades; i++)
    {   
        sum += m_grades[i];
    }
    
    return m_numGrades ? sum / m_numGrades : 0.00;
}