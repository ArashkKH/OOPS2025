/* Citation and Sources...
Final Project Milestone 2: 
Module: Constants Header
Filename: constants.h
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
Revision History
----------------------------------------------------------------------------
Date        Reason
2025/07/12  Project Initiation and submission of mileStone 1
2025/07/26  Milestone 3: adding Drink static values
----------------------------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
ANY part that is NOT done by me will be having a comment to point it out 
and include the citation of that code.
----------------------------------------------------------------------------
*/


#ifndef SENECA_CONSTANTS_H
#define SENECA_CONSTANTS_H
#include <cstddef>
namespace seneca {
   const size_t MaximumNumberOfMenuItems = 20u;
   const int DrinksPrintMaxNameCharacters = 25;
   const int DrinksPrintMaxNameSpaces = 28;
   const double Tax = 0.13;
   const size_t MaximumNumberOfBillItems = 50u;
}
#endif // !SENECA_CONSTANTS_H