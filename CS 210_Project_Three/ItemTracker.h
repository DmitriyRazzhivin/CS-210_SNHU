/*
*** Name: Dmitriy Razzhivin
*** Description: Header file defining the ItemTracker class for managing,
*** counting, and displaying grocery item frequencies.
*** Date:June __, 2026
*/

#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

class ItemTracker {
private:
    // Map container storing item names as keys and their frequencies as values
    std::map<std::string, int> itemFrequencies;

    /** This method reads data from the raw input text file using a character array 
    and automatically backs up the compiled frequencies into frequency.dat.
    parameter - None.
    return - void 
    */
    void LoadDataAndWriteBackup();

public:
    /** Default constructor that initializes the tracker and automatically triggers data processing.
    parameter - None.
    return - N/A (Constructor)
    */
    ItemTracker();

    /** This method searches for a specific grocery item and prints its individual purchase count.
    parameter - itemName - std::string representing the item to look for.
    return - void
    */
    void PrintItemFrequency(const std::string& itemName) const;

    /** This method outputs a complete, alphabetized list of all unique grocery items paired with their numeric frequency.
    parameter - None.
    return - void
    */
    void PrintAllFrequencies() const;

    /** This method outputs an alphabetized text-based histogram where item frequencies are represented by special character bars.
    parameter - None.
    return - void
    */
    void PrintHistogram() const;
};

#endif // ITEM_TRACKER_H