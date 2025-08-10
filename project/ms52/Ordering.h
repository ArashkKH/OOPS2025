/* Citation and Sources...
Final Project Milestone 4: 
Module: Ordering
Filename: Ordering.h
Version 1.0
Author: [Your Name], StNo: [Your Student Number], Email: [Your Email]
Revision History
-----------------------------------------------------------
Date        Reason
2025/08/09  MS4 submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#if !defined(ORDERING_H)
#define ORDERING_H

#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"
#include <iostream>
#include <fstream>

namespace seneca{
    class Ordering {
        // Counters
        size_t m_foodCounter;
        size_t m_drinkCounter;
        size_t m_billableCounter;

        // Bill number
        size_t m_billNumber;

        // Dynamic arrays
        Food* m_foods;
        Drink* m_drinks;

        // Array of Billable pointers for current bill
        Billable* m_billItems[MaximumNumberOfBillItems];

        // Private methods
        void printBillTitle(std::ostream& ostr) const;
        void printTotals(std::ostream& ostr, double total) const;
        size_t countRecords(const char* file) const;

    public:
        // Constructor and Destructor
        Ordering(const char* drinksFile, const char* foodsFile);
        ~Ordering();

        // Delete copy constructor and assignment operator
        Ordering(const Ordering& other) = delete;
        Ordering& operator=(const Ordering& other) = delete;

        // Queries (const methods)
        operator bool() const;
        size_t noOfBillItems() const;
        bool hasUnsavedBill() const;
        void listFoods() const;
        void listDrinks() const;
        void printBill(std::ostream& ostr = std::cout) const;

        // Methods that modify the class
        void orderFood();
        void orderDrink();
        void resetBill();
    };
}


#endif // ORDERING_H
