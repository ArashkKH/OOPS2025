/* Citation and Sources...
Final Project Milestone 2: 
Module: Drink Logic file
Filename: Drink.cpp
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



#include "Drink.h"
#include "Utils.h"
#include "Billable.h"


#include <iostream>

using std::ostream;

namespace seneca {
    
    ostream& Drink::print(ostream& os) const{
        os << getName();
    }

    
}