/*
*** Name: Dmitriy Razzhivin
*** Description: Implementation file for the ItemTracker class. 
        Handles file I/O using character arrays, aggregates frequency 
        data using a map, and manages data output formats.
*** Date: June __, 2026
*/

#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/** This method/functions will initialize the ItemTracker object and automatically 
trigger the internal loading and backing up of the grocery data files.
parameter - None.
return - N/A (Constructor)
*/
ItemTracker::ItemTracker() {
    // Automatically populate map and create backup file upon instantiation
    LoadDataAndWriteBackup();
}

/** This method/functions will read grocery items from the input text file using fixed-width 
character arrays, count their frequencies via a map container, and write a backup file.
parameter - None.
return - void
*/

void ItemTracker::LoadDataAndWriteBackup() {
    //Open grocery transaction for reading
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    //Verify if the inpu file opened correctly
    if (!inputFile.is_open()){
        cout << "Error: Unable to open input file CS210_Project_Three_Input_File.txt" << endl;
        return;
    }

    // Create an array buffer
    char itemBuffer[50];

    // Read the token seqqunetially using fixed-width character array
    while(inputFile >> itemBuffer){

        // Convert the char arrayto a std::string to key it into the map
        string standardItemString(itemBuffer);

        // Increment the frequency count for this item in the map
        itemFrequencies[standardItemString]++;
    }

    // Close the file
    inputFile.close();

    // Open the backup data file for writing
    ofstream backupFile("frequency.dat");

    if(!backupFile.is_open()){
        cout << "Error: Unable to create backup data file frequency.dat" << endl;
        return;
    }

    // Traverse the map and save all accumulated frequencies into the backup file
    for (auto const& pair : itemFrequencies) {
        // Writes "ItemName Frequency" on separate rows
        backupFile << pair.first << " " << pair.second << endl;
    }

    // Close the output data backup stream
    backupFile.close();
}
/** This method/functions will look up a specific item name provided by the user 
and display how many times it was purchased.
parameter - itemName - const std::string& - The name of the item to search for.
return - void
*/
void ItemTracker::PrintItemFrequency(const string& itemName) const {
    // Search the map for the requested item key
    auto lookupResult = itemFrequencies.find(itemName);
    
    cout << endl;
    if (lookupResult != itemFrequencies.end()) {
        // Item found: output its associated integer value
        cout << lookupResult->first << " was purchased " << lookupResult->second << " times." << endl;
    } else {
        // Item not found in the transaction log
        cout << itemName << " was purchased 0 times." << endl;
    }
    cout << endl;
}

/** This method/functions will iterate through the map to output a comprehensive, 
alphabetized list of all unique grocery items and their frequency counts.
parameter - None.
return - void
*/
void ItemTracker::PrintAllFrequencies() const {
    cout << endl;
    cout << "=============================" << endl;
    cout << "   OVERALL ITEM FREQUENCY    " << endl;
    cout << "=============================" << endl;
    
    for (auto const& pair : itemFrequencies) {
        cout << left << setw(15) << pair.first << " " << pair.second << endl;
    }
    
    cout << "=============================" << endl;
    cout << endl;
}

void ItemTracker::PrintHistogram() const {
    cout << endl;
    cout << "=============================" << endl;
    cout << "       ITEM HISTOGRAM        " << endl;
    cout << "=============================" << endl;
    
    // Loop through each item in the map
    for (auto const& pair : itemFrequencies) {
        cout << left << setw(15) << pair.first << " : ";
        
        // Print one asterisk per transaction frequency unit
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
    
    cout << "=============================" << endl;
    cout << endl;
}

