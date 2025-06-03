#include "header.h"

using namespace std;

int main(){
    playdoh x(12);
    cout << "lets wait:" << endl;
    
    void* temp = nullptr;
    cin >> temp;

    x.setColor('w');
    x.display();
}