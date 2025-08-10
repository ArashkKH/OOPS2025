/* Citation and Sources...
Final Project Milestone 5: 
Module: Main Program
Filename: main.cpp
Version 1.0
Author: Arash Kheirollahi, StNo: 146731245, Email: akheirollahi@myseneca.ca
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
#include <iostream>

using namespace std;
using namespace seneca;

int main() {
    // Initialize Ordering system with data files
    Ordering restaurant("drinks.csv", "foods.csv");
    
    // Check if initialization was successful
    if (!restaurant) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }
    
    // Create main menu
    Menu mainMenu("Seneca Restaurant", "End Program");
    mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
    
    // Create order submenu
    Menu orderMenu("Order Menu", "Back to main menu", 1, 3);
    orderMenu << "Food" << "Drink";
    
    // Create confirmation menu for unsaved bills
    Menu confirmMenu("You have bills that are not saved. Are you sue you want to exit?", "No", 1, 3);
    confirmMenu << "Yes";
    
    bool running = true;
    
    while (running) {
        size_t mainSelection = mainMenu.select();
        
        switch (mainSelection) {
        case 1: // Order
            {
                bool orderingActive = true;
                while (orderingActive) {
                    size_t orderSelection = orderMenu.select();
                    
                    switch (orderSelection) {
                    case 1: // Food
                        restaurant.orderFood();
                        break;
                    case 2: // Drink
                        restaurant.orderDrink();
                        break;
                    case 0: // Back to main menu
                        orderingActive = false;
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
                // Show confirmation menu for unsaved bills
                size_t confirmSelection = confirmMenu.select();
                
                if (confirmSelection == 1) { // Yes - exit anyway
                    running = false;
                }
                // If No (0) - continue to main menu (do nothing)
            } else {
                // No unsaved bills - exit normally
                running = false;
            }
            break;
        }
    }
    
    return 0;
}