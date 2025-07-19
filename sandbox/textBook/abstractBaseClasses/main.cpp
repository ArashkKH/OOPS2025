#include "shape.hpp"

void renderShape(const Shape* s){
    s->draw(cout);
}


int main(){

    Shape* shapes[3];

    shapes[0] = new Square();
    shapes[1] = new Circle();
    shapes[2] = new Triangle();

    

    for (size_t i = 0; i < 3; i++)
    {
        renderShape(shapes[i]);
        delete shapes[i];
    }
    

}