// TODO:0 make a header Guard
#ifndef _NOVEL_H
#define _NOVEL_H

// TODO:1 Declare an integer for max string
#define MAX_LENGTH 33

class Novel{
    // TODO:2 Make the class!
    char    title[MAX_LENGTH];
    double  price;

    public:
        Novel();
        Novel(const char* t, double p);

        void set(const char* t, double p);
        bool isEmpty() const;
    Novel& operator+=(double p);
};

#endif

