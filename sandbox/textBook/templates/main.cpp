#include "stats.hpp"

int main(){
    StatsBox<int> vals;

    vals.add(3);
    vals.add(2);
    vals.add(4);
    vals.add(6);
    vals.add(4);
    vals.add(7);
    vals.add(100);

    vals.print();
    
}