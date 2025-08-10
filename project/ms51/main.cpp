/* Citation and Sources...
Final Project Milestone 5: 
Main Program
Filename: main.cpp
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: Akheirollahi@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2025/08/09  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Menu.h"
#include "Ordering.h"
#include <iostream>

using namespace std;
using namespace seneca;

int main() {
    // Initialize the Ordering system with data files
    Ordering restaurant("drinks.csv", "foods.csv");
    
    // Check if initialization was successful
    if (!restaurant) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }
    
    // Create main menu
    Menu mainMenu("Seneca Restaurant", "End Program", 2, 3);
    mainMenu << "Order" 
             << "Print Bill" 
             << "Start a New Bill" 
             << "List Foods" 
             << "List Drinks";
    
    // Create order sub-menu
    Menu orderMenu("Order Menu", "Back to main menu", 2, 3);
    orderMenu << "Food" << "Drink";
    
    // Create confirmation menu for unsaved bills
    Menu confirmMenu("You have bills that are not saved. Are you sue you want to exit?", "No", 2, 3);
    confirmMenu << "Yes";
    
    bool exitProgram = false;
    
    while (!exitProgram) {
        size_t mainSelection = mainMenu.select();
        
        switch (mainSelection) {
            case 1: // Order
                {
                    bool backToMain = false;
                    while (!backToMain) {
                        size_t orderSelection = orderMenu.select();
                        
                        switch (orderSelection) {
                            case 1: // Food
                                restaurant.orderFood();
                                break;
                            case 2: // Drink
                                restaurant.orderDrink();
                                break;
                            case 0: // Back to main menu
                                backToMain = true;
                                break;
                        }
                    }
                }
                break;
                
            case 2: // Print Bill
                restaurant.printBill(cout);
                break;
                
            case 3: // Start a New Bill
                restaurant.resetBill();
                break;
                
            case 4: // List Foods
                restaurant.listFoods();
                break;
                
            case 5: // List Drinks
                restaurant.listDrinks();
                break;
                
            case 0: // End Program
                if (restaurant.hasUnsavedBill()) {
                    // There are unsaved bills, show confirmation
                    size_t confirmSelection = confirmMenu.select();
                    if (confirmSelection == 1) { // Yes, exit anyway
                        exitProgram = true;
                    }
                    // If No (0), continue the main loop
                } else {
                    // No unsaved bills, exit normally
                    exitProgram = true;
                }
                break;
        }
    }
    
    return 0;
}