/*
*** Name: Dmitriy Razzhivin
*** Description: Main driver file for the Corner Grocer item-tracking program.
        Manages the interactive user interface, input validation,
        and coordinates menu selections with the ItemTracker class.
*** Date: June 20, 2026
*/

#include "ItemTracker.h"
#include <iostream>
#include <string>

using namespace std;

/** This method/functions will display the main interface menu options to the user.
parameter - None.
return - void
*/
void DisplayMenu() {

    cout << "=========================================" << endl;
    cout << "       CORNER GROCER ITEM TRACKER        " << endl;
    cout << "=========================================" << endl;
    cout << "1. Search for an individual item frequency" << endl;
    cout << "2. Display overall item purchase list" << endl;
    cout << "3. Display graphical item histogram" << endl;
    cout << "4. Exit Program" << endl;
    cout << "=========================================" << endl;
    cout << "Enter your choice (1-4): ";
}

int main(){
    //Initiating the tracking class
    ItemTracker tracker;

    int userChoice = 0;
    string searchItem;

    // Core loop running until option 4 is selected
    while(userChoice != 4) {
        DisplayMenu();

        // Input validation to handle non-integer menu entries
        if (!(cin >> userChoice)) {
            cout << endl << "Invalid entry. Please enter a number between 1 and 4." << endl << endl;
            cin.clear();            // Reset the stream error state
            cin.ignore(1000, '\n'); // Clear the invalid token buffer
            continue;               // Restart the loop input phase
        }
        // Branching execution logic mapped to project rubric criteria
        switch (userChoice) {
            case 1:
                cout << "Enter the item name to search for: ";
                cin >> searchItem;
                tracker.PrintItemFrequency(searchItem);
                break;
                
            case 2:
                tracker.PrintAllFrequencies();
                break;
                
            case 3:
                tracker.PrintHistogram();
                break;
                
            case 4:
                cout << endl << "Thank you for using the Corner Grocer Tracking System. Goodbye!" << endl;
                break;
                
            default:
                cout << endl << "Error: Selection out of range. Choose options 1 through 4." << endl << endl;
                break;
        }

    }

    return 0;
}