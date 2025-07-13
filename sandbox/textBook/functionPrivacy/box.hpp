#if !defined(BOX_HPP)
#define BOX_HPP

#include <iostream>

class Box
{
private:
    double m_weight;
    char* m_label;
public:
    Box();
    ~Box();

    void setWeight(double w);
    double getWeight() const;

    void setLabel(const char* text);
    const char* getLabel() const;

    void display() const;
};

#endif // BOX_HPP
