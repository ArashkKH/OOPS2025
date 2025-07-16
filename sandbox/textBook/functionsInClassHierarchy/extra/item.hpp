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
        Item(const char* title);
        virtual void display(ostream& os = cout) const = 0;
        virtual ~Item();       
};


class Book : public Item{
        int m_pageCount;
    public:
        Book();
        Book(const char* title , int pages);

        void display(ostream& os = cout) const override;
};

class DVD : public Item {
        int m_duration;
    public:
        DVD();
        DVD(const char* title , int duration);
        void display(ostream& os = cout) const override;
};

#endif // ITEM__HPP
