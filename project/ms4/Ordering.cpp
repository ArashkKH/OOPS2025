/* Citation and Sources...
Final Project Milestone 4: 
Module: Ordering
Filename: Ordering.cpp
Version 1.0
Author: [Your Name], StNo: [Your Student Number], Email: [Your Email]
Revision History
-----------------------------------------------------------
Date      Reason
2025/08/09  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace seneca {
    
    // Private Methods
    void Ordering::printBillTitle(ostream& ostr) const {
        // Use '0' only for the bill number, then restore the fill char
        char oldFill = ostr.fill('0');
        ostr << "Bill # " << setw(3) << m_billNumber;
        ostr.fill(oldFill);
        ostr << " =============================" << '\n';
    }
    
    void Ordering::printTotals(ostream& ostr, double total) const {
        double tax = total * Tax;
        double grandTotal = total + tax;

        // We want all labels to START at the same column (same left indentation),
        // and all values to be right-aligned at the same column.
        // Use a fixed left indent for labels, then compute the gap to the value field
        // based on each label's length so that the value column is consistent.
        const int indent = 21;          // number of leading spaces before any label
        const int valueWidth = 13;      // width reserved for the numeric value (right aligned)
        const int gapMin = 1;           // at least one space between label and value field
        const int maxLabelLen = 10;     // length of "Total+Tax:"
        const int valueStartCol = indent + maxLabelLen + gapMin; // fixed column where value field begins

        // ----- Total -----
        int gap = valueStartCol - (indent + 6); // 6 == len("Total:")
        if (gap < gapMin) gap = gapMin;
        ostr << setfill(' ') << right << setw(indent) << ""
             << "Total:" << setw(gap) << ""
             << right << setw(valueWidth - 5) << fixed << setprecision(2) << total << '\n';

        // ----- Tax -----
        gap = valueStartCol - (indent + 4); // 4 == len("Tax:")
        if (gap < gapMin) gap = gapMin;
        ostr << setfill(' ') << right << setw(indent) << ""
             << "Tax:" << setw(gap) << ""
             << right << setw(valueWidth) << fixed << setprecision(2) << tax << '\n';

        // ----- Total+Tax -----
        gap = valueStartCol - (indent + 10); // 10 == len("Total+Tax:")
        if (gap < gapMin) gap = gapMin;
        ostr << setfill(' ') << right << setw(indent) << ""
             << "Total+Tax:" << setw(gap) << ""
             << right << setw(valueWidth) << fixed << setprecision(2) << grandTotal << '\n';

        ostr << "========================================\n";
    }

    
    size_t Ordering::countRecords(const char* file) const {
        size_t newlineCounter = 0;
        ifstream fileStream(file);
        char ch;
        
        while (!fileStream.fail()) {
            fileStream.get(ch);
            if (!fileStream.fail() && ch == '\n') {
                newlineCounter++;
            }
        }
        
        return newlineCounter;
    }
    
    // Constructor
    Ordering::Ordering(const char* drinksFile, const char* foodsFile) 
        : m_foodCounter(0), m_drinkCounter(0), m_billableCounter(0), 
          m_billNumber(1), m_foods(nullptr), m_drinks(nullptr) {
        
        // Initialize bill items array to nullptr
        for (size_t i = 0; i < MaximumNumberOfBillItems; i++) {
            m_billItems[i] = nullptr;
        }
        
        // Count records in files
        size_t drinkRecords = countRecords(drinksFile);
        size_t foodRecords = countRecords(foodsFile);
        
        // Open files for reading
        ifstream drinkFile(drinksFile);
        ifstream foodFile(foodsFile);
        
        if (drinkFile && foodFile && drinkRecords > 0 && foodRecords > 0) {
            // Allocate dynamic arrays
            m_drinks = new Drink[drinkRecords];
            m_foods = new Food[foodRecords];
            
            // Read drinks
            size_t drinkCount = 0;
            for (size_t i = 0; i < drinkRecords && drinkFile; i++) {
                if (m_drinks[i].read(drinkFile)) {
                    drinkCount++;
                } else {
                    break;
                }
            }
            
            // Read foods
            size_t foodCount = 0;
            for (size_t i = 0; i < foodRecords && foodFile; i++) {
                if (m_foods[i].read(foodFile)) {
                    foodCount++;
                } else {
                    break;
                }
            }
            
            // Validate that all records were read successfully
            if (drinkCount != drinkRecords || foodCount != foodRecords) {
                // Revert operation - enter safe empty state
                delete[] m_drinks;
                delete[] m_foods;
                m_drinks = nullptr;
                m_foods = nullptr;
                m_drinkCounter = 0;
                m_foodCounter = 0;
            } else {
                // Success - set counters
                m_drinkCounter = drinkCount;
                m_foodCounter = foodCount;
            }
        } else {
            // Files failed to open or no records - safe empty state
            m_drinks = nullptr;
            m_foods = nullptr;
            m_drinkCounter = 0;
            m_foodCounter = 0;
        }
    }
    
    // Destructor
    Ordering::~Ordering() {
        // Delete dynamic arrays
        delete[] m_foods;
        delete[] m_drinks;
        
        // Delete billable items
        for (size_t i = 0; i < m_billableCounter; i++) {
            delete m_billItems[i];
        }
    }
    
    // Queries
    Ordering::operator bool() const {
        return (m_drinks != nullptr && m_foods != nullptr);
    }
    
    size_t Ordering::noOfBillItems() const {
        return m_billableCounter;
    }
    
    bool Ordering::hasUnsavedBill() const {
        return m_billableCounter > 0;
    }
    
    void Ordering::listFoods() const {
        cout << "List Of Avaiable Meals" << '\n';
        cout << "========================================" << '\n';
        for (size_t i = 0; i < m_foodCounter; i++) {
            m_foods[i].print() << '\n';
        }
        cout << "========================================" << '\n';
    }
    
    void Ordering::listDrinks() const {
        cout << "List Of Avaiable Drinks" << '\n';
        cout << "========================================" << '\n';
        for (size_t i = 0; i < m_drinkCounter; i++) {
            m_drinks[i].print() << '\n';
        }
        cout << "========================================" << '\n';
    }
    
    void Ordering::printBill(ostream& ostr) const {
        double total = 0.0;
        
        printBillTitle(ostr);
        
        for (size_t i = 0; i < m_billableCounter; i++) {
            if (m_billItems[i]) {
                m_billItems[i]->print(ostr) << '\n';
                total += m_billItems[i]->price();
            }
        }
        
        printTotals(ostr, total);
    }
    
    // Methods that modify the class
    void Ordering::orderFood() {
        if (m_foodCounter == 0) return;
        
        Menu foodMenu("Food Menu", "Back to Order", 2, 3);
        
        // Populate menu with food names
        for (size_t i = 0; i < m_foodCounter; i++) {
            foodMenu << static_cast<const char*>(m_foods[i]);
        }
        
        size_t selection = foodMenu.select();
        
        if (selection != 0 && selection <= m_foodCounter && m_billableCounter < MaximumNumberOfBillItems) {
            // Create dynamic copy of selected food item
            Food* newFood = new Food(m_foods[selection - 1]);
            
            // Try to order the item
            if (newFood->order()) {
                // Order successful - add to bill
                m_billItems[m_billableCounter] = newFood;
                m_billableCounter++;
            } else {
                // Order cancelled - delete the copy
                delete newFood;
            }
        }
    }
    
    void Ordering::orderDrink() {
        if (m_drinkCounter == 0) return;
        
        Menu drinkMenu("Drink Menu", "Back to Order", 2, 3);
        
        // Populate menu with drink names
        for (size_t i = 0; i < m_drinkCounter; i++) {
            drinkMenu << static_cast<const char*>(m_drinks[i]);
        }
        
        size_t selection = drinkMenu.select();
        
        if (selection != 0 && selection <= m_drinkCounter && m_billableCounter < MaximumNumberOfBillItems) {
            // Create dynamic copy of selected drink item
            Drink* newDrink = new Drink(m_drinks[selection - 1]);
            
            // Try to order the item
            if (newDrink->order()) {
                // Order successful - add to bill
                m_billItems[m_billableCounter] = newDrink;
                m_billableCounter++;
            } else {
                // Order cancelled - delete the copy
                delete newDrink;
            }
        }
    }
    
    void Ordering::resetBill() {
        if (m_billableCounter > 0) {
            // Generate filename and save bill
            char filename[50];
            ut.makeBillFileName(filename, m_billNumber);
            
            ofstream billFile(filename);
            if (billFile) {
                printBill(billFile);
            }
            
            cout << "Saved bill number " << m_billNumber << '\n';
            cout << "Starting bill number " << (m_billNumber + 1) << '\n';
            
            // Clean up current bill
            for (size_t i = 0; i < m_billableCounter; i++) {
                delete m_billItems[i];
                m_billItems[i] = nullptr;
            }
            
            // Reset counters and increment bill number
            m_billableCounter = 0;
            m_billNumber++;
        }
    }
}
