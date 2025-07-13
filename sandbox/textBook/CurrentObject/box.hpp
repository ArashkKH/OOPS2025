#if !defined(BOX_HPP)
#define BOX_HPP

#include <iostream>

class Box
{
private:
    char* m_label;
    double m_weight;
public:
    Box();
    Box(char* label , double weight);
    ~Box();

    Box& setWeight(double w);
    double getWeight() const;

    Box& setLabel(const char* text);
    const char* getLabel() const;

    const Box& display() const;
};

#endif // BOX_HPP
