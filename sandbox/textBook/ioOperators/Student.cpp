/**
 * Author:
 * Arash KH
 * LOGS:
 * 1 - Added this Class for Pracitce
 * 2 - Added Helper function of getting average Grade
 * 3 - Added I/O stream Helper Overloaded operators
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
    memoryInit(int(strlen(name)) + 1 , numGrades);
    strcpy(m_name , name);
    arrCopy(m_grades , grades , numGrades);
    m_numGrades = numGrades;
}

Student::Student(const Student& src){
    memoryInit(int(strlen(src.m_name)) + 1, src.m_numGrades);
    strcpy(m_name , src.m_name);
    m_numGrades = src.m_numGrades;
    arrCopy(m_grades , src.m_grades  , m_numGrades);
}

Student& Student::operator=(const Student& src){
    if(this != &src){

        
        delete[] m_name;
        delete[] m_grades;
        memoryInit(int(strlen(src.m_name)) + 1 , src.m_numGrades);
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
    for (int i = 0; i < count; i++) {
        arr1[i] = arr2[i];
    }
}

void Student::display() const {
    cout << "Name: " << m_name << endl;
    cout << "===================" << endl;
    cout << "Grades:"<<  endl;
    
    for (int i = 0; i < m_numGrades; i++)
    {
        cout << m_grades[i] << endl;
    }
    cout << "===================" << endl;
    cout << "Average Score: " << getAverage() << endl;
}


double Student::getAverage() const{
    double sum = 0;
    for (int i = 0; i < m_numGrades; i++)
    {   
        sum += m_grades[i];
    }
    
    return m_numGrades ? sum / m_numGrades : 0.00;
}

ostream& operator<<(ostream& os, const Student& src){
    src.display();
    return os;
}


istream& operator>>(istream& is , Student& src){
    delete[] src.m_name;
    delete[] src.m_grades;
    

    char name[100];
    double grades[100];
    int sz = 0;

    do
    {
        cout << "Enter The name of the Student:" ;
        is >> name;
        cout << endl;
        is.ignore();
        if(!strlen(name)){
            cout << "you didnt Enter Any name" << endl;
        }
    } while (!strlen(name));
    



    cout << "Enter Grades: (enter a negative number to end!) <<" << endl;
    double current;
    
    do
    {
        cout << sz + 1  << "- ";
        cin >> current;
        cout << endl;
        if(current >= 0){
            grades[sz] = current;
            sz++;
            cin.ignore();
        }else{
            cout << "you have entered a NEGATIVE number, Exiting assignment." << endl;
        }
    } while (current >= 0 );


    src.memoryInit(strlen(name) + 1,sz);
    strcpy(src.m_name, name);
    src.m_numGrades = sz;
    src.arrCopy(src.m_grades , grades , sz);
    
    return is;
}
