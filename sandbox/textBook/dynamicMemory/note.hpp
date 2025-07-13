using namespace std;

#ifndef NOTE_H
#define NOTE_H
#include <iostream>

class Note {
    char* m_desc;
    int m_length;

public:
    Note();
    Note(const char* desc);
    Note(const Note& src);
    ~Note();

    void read();
    void display() const;
    friend istream& operator>>(istream& , Note& note );
    friend ostream& operator<<(ostream& , const Note& note);

};




#endif // !NOTE_H