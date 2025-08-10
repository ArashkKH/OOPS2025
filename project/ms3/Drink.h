/* Citation and Sources...
Final Project Milestone 2: 
Module: Drink Header file
Filename: Drink.h
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
Revision History
----------------------------------------------------------------------------
Date        Reason
2025/07/25  Project Milesone 3 : Creating Drink class
----------------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
ANY part that is NOT done by me will be having a comment to point it out 
and include the citation of that code.
----------------------------------------------------------------------------
*/

#if !defined(DRINK_H)
#define DRINK_H

#include <iostream>
#include "Billable.h"
using std::ostream;
using std::cout;
using std::ifstream;


namespace seneca {

    class Drink : public Billable {
        char m_size = '\0';
        
        public:
            // Constructor
            Drink();

            ostream& print(ostream& ostr=cout) const override;
            bool order() override;
            bool ordered() const override;
            ifstream& read(ifstream& file);

            double price() const override;
    };




}

#endif // DRINK_H
