/* Citation and Sources...
Final Project Milestone 2: 
Module: Food Header file
Filename: Food.h
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
Revision History
----------------------------------------------------------------------------
Date        Reason
2025/07/29  Project Milesone 3 : Creating Food class
----------------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
ANY part that is NOT done by me will be having a comment to point it out 
and include the citation of that code.
----------------------------------------------------------------------------
*/

#if !defined(FOOD_H)
#define FOOD_H

#include <iostream>
#include "Billable.h"
using std::ostream;
using std::cout;
using std::ifstream;


namespace seneca {

    class Food : public Billable {
        private:
            bool m_ordered = false;
            bool m_child = false;
            char* m_customize = nullptr;  
        public:
            Food();
            //copy constructor
            Food(const Food& src);
            Food& operator=(const Food& src);
            ~Food();
            ostream& print(ostream& ostr=cout) const override;

            bool order() override;
            bool ordered() const override;
            ifstream& read(ifstream& file);
            double price() const override;



    };




}

#endif // FOOD_H
