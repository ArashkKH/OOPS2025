#if !defined(SHAPE_HPP)
#define SHAPE_HPP

#include <iostream>
using std::ostream;
using std::endl;
using std::cout;

class Shape{
    public:
        virtual void draw(ostream& os = cout) const = 0;
        virtual ~Shape() {}
};

class Square : public Shape {
    public:
        void draw(ostream& os = cout) const override;
};

class Circle : public Shape {
    public:
        void draw(ostream& os = cout) const override;
};

class Triangle : public Shape {
    public:
        void draw(ostream& os = cout) const override;
};



#endif // SHAPE_HPP
