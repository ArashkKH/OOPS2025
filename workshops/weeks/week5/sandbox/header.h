#include <iostream>
using namespace std;

class playdoh {
    private:
        int weight;
        char color;
        int* data;
    public:
        playdoh(){
                weight = 12;
                color = 'Y';
        };
        playdoh(int n){
                weight = 12;
                color = 'Y';
                data = new int[n];
        };
        ~playdoh(){
            cout << "Im " << color << " and getting destroyed, Yay!" << endl; 
            delete[] data;
        };
        void setColor(char c);
        void setWeight(int w);
        void display() const; //this const mean that this function do not modify the values!
        void showThis() const;
        playdoh makeACopy() const;
        playdoh makeARef() const;
};