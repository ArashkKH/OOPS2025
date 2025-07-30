/* Citation and Sources...
Final Project Milestone 2: 
Module: Billable Header file
Filename: Billable.h
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
Revision History
----------------------------------------------------------------------------
Date        Reason
2025/07/25  Project Milesone 3 : Creating Billable class
----------------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
ANY part that is NOT done by me will be having a comment to point it out 
and include the citation of that code.
----------------------------------------------------------------------------
*/

#if !defined(BILLABLE_H)
#define BILLABLE_H
#include <iostream>
#include <fstream>


using std::ostream;
using std::cout;
using std::ifstream;

namespace seneca{
    class Billable {
        private:
            // properties
            char*   m_name = nullptr;
            double  m_price = 0.00;

        protected:
            // Sets the item's price
            void price(double value);

            // Sets the item's name, Hnadling dynamic allocation
            void name(const char* name);
            
            // query functions
            const char* getName() const;
            const double getPrice() const;


        public:
            Billable() = default;
            // copy constructor
            Billable(const Billable& src);
            // Assignment Operator
            Billable& operator=(const Billable& src);
            // ensuring proper cleanup using a virtual constructor
            virtual ~Billable();
            // Getting the item's price and allowing derived classes to override
            virtual double price() const;


            /* ------------------------------ Pure Virtuals ----------------------------- */

            // Displaying item information in a formatted way
            virtual ostream& print(ostream& ostr=cout) const = 0;
            // Takes customer order details of the item
            virtual bool order() = 0;
            // Returns true if the details have been set, indicating the item has been ordered
            virtual bool ordered() const = 0;
            // Reads items details from an input file
            virtual ifstream& read(ifstream& file) = 0;


            /* --------------------------- Operator Overloads --------------------------- */

            friend double operator+(double money, const Billable& B);
            friend double& operator+=(double& money, const Billable& B);
            operator const char*() const;
    };
};

#endif // BILLABLE_H