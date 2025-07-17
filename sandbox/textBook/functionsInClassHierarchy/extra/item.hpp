#if !defined(ITEM__HPP)
#define ITEM__HPP

#include <iostream>
using namespace std;


class Item{
    protected:
        char* m_title;
        void initItemName(char* name = nullptr);
        void deleteItemName();
    public:
        Item();
        Item(char* title);
        virtual void display(ostream& os = cout) const = 0;
        virtual ~Item();       
};


class Book : public Item{
        int m_pageCount;
    public:
        Book();
        Book( char* title , int pages);
        ~Book() override;
        void display(ostream& os = cout) const override;
};

class DVD : public Item {
        int m_duration;
    public:
        DVD();
        DVD(char* title , int duration);
        ~DVD() override;
        void display(ostream& os = cout) const override;
};

#endif // ITEM__HPP