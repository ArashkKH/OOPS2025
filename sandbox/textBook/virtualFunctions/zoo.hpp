#if !defined(ZOO_HPP)
#define ZOO_HPP

#include <iostream>

class Animal{
    protected:
        char* m_name;
        char* m_sound;
    public:
        Animal();

        Animal(const char* name , const char* sound);
        
        virtual~Animal();
        virtual void makeSound(std::ostream& os = std::cout) const;

        void init(const char*name , const char*sound);
};

class Lion : public Animal{

    public:
        Lion();
        Lion(const char* name , const char* sound);
        ~Lion();
        void makeSound(std::ostream& os = std::cout) const override;
};
class Dog : public Animal{

    public:
        Dog();
        Dog(const char* name ,const char* sound);
        ~Dog();
        void makeSound(std::ostream& os = std::cout) const override;
};
class Cat : public Animal{

    public:
        Cat();
        Cat(const char* name ,const char* sound);
        ~Cat();
        void makeSound(std::ostream& os = std::cout) const override;
};

#endif // ZOO_HPP
