/*
*** Name: Dmitriy Razzhivin
*** Program description: This program purporse is to get an initial time from the user input and then to display the time in the following format: HH:MM:SS
*** Date: May 24, 2026
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// initiating global variables for hours, minutes, and seconds. To be accessable by all functions.

int hours = 0;
int minutes = 0;
int seconds = 0;

// Functions Prototypes

void addOneHour();
void addOneMinute();
void addOneSecond();
void displayClocks();
void displayMenu();
 
int main() {

    int initialHours, initialMinutes, initialSeconds;
    string amPmFlag;
   
    // Getting the intial time from user

    cout << "Enter initial time (Expmaple: 12:45:00 or 12 45 00 PM)";
    cin >> initialHours; 

    
    if (cin.peek() == ':'){ // If the user typed a colon separator, discard it to prevent an input stream failure
        cin.ignore();
    }
    cin >> initialMinutes;

    if (cin.peek() == ':'){ // Discard the second colon separator if present before reading remaining values
        cin.ignore();
    }

    cin >> initialSeconds >> amPmFlag;

    // Assigning the global variables with the user input
    hours = initialHours;
    minutes = initialMinutes;
    seconds = initialSeconds;

    if ((amPmFlag == "PM" || amPmFlag == "pm") && hours != 12) {
        hours += 12; // Adjust evening hours for internal 24-hour calculations
    } 
    else if ((amPmFlag == "AM" || amPmFlag == "am") && hours == 12) {
        hours = 0; // Adjust midnight hour for internal 24-hour calculations
    }

    int userChoice = 0;
    // Main program loop, runs untill user enters '4'
    while (userChoice != 4){
        displayClocks();
        displayMenu();

        cin >> userChoice;

        // Map the choices directly to your outside worker logic functions
        switch (userChoice) {
            case 1:
                addOneHour(); 
                break;
            case 2:
                addOneMinute(); 
                break;
            case 3:
                addOneSecond(); 
                break;
            case 4:
                cout << "Program Finished." << endl;
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
                break;
        }
    }
    return 0;
}

/** This function increments the internal global hours tracking variable by one.
It automatically handles 24-hour clock overflow by resetting to zero at midnight.
Parameter - None
Return - None (Void)
*/

void addOneHour(){
    hours++;
    if(hours >= 24)
        hours = 0; //Resetting hours at midnight
}

/** This function increments the internal global minutes tracking variable by one.
It automatically resets to zero and triggers the hour increment logic upon reaching 60 minutes.
Parameter - None
Return - None (Void)
*/

void addOneMinute(){
    minutes++;
    if(minutes >= 60){
        minutes = 0;
        addOneHour(); // Addinng one hours after minutes pass 60
    }
}

/** This function increments the internal global seconds tracking variable by one.
It automatically resets to zero and triggers the minute increment logic upon reaching 60 seconds.
Parameter - None
Return - None (Void)
*/

void addOneSecond(){
    seconds++;

    if(seconds >= 60){
        seconds = 0;
        addOneMinute(); // Adding one minute after seconds pass 60
    }
}

/** This function converts internal 24-hour time to 12-hour format and outputs both clocks simultaneously.
It utilizes stream manipulators to print perfectly aligned side-by-side display boxes.
Parameter - None
Return - None (Void)
*/

void displayClocks(){
    string amPm = (hours >= 12) ? "PM" : "AM"; // calculating the 12-hour format values

    int display12Hour = hours;
    if(hours == 0){
        display12Hour = 12; //Midnight conversion
    }
    else if(hours > 12){
        display12Hour = hours - 12; //converting hours after noon.
    }

    // Prinring top borders for better visinility and user experience.
    cout << setfill('*') << setw(26) << "" << "     " << setfill('*') << setw(26) << "" << endl;

    // Printing clock lables
    cout << setfill(' ');
    cout << "* 12-Hour Clock          *" << "     " << "* 24-Hour Clock          *" << endl;

    // Printing the time displays.
    cout << "* ";
    cout << setw(2) << setfill('0') << display12Hour << ":";
    cout << setw(2) << setfill('0') << minutes << ":";
    cout << setw(2) << setfill('0') << seconds << " " << amPm;
    cout << "           **     * ";

    cout << setw(2) << setfill('0') << hours << ":";
    cout << setw(2) << setfill('0') << minutes << ":";
    cout << setw(2) << setfill('0') << seconds;
    cout << "               *" << endl;
    // Printing bottom borders
    cout << setfill('*') << setw(26) << "" << "     " << setfill('*') << setw(26) << "" << endl;

}

/** This function prints the user interaction menu block to the console interface.
It displays the text options for adding time components or exiting the system.
Parameter - None
Return - None (Void)
*/

void displayMenu(){
    // Printing borders for better visibility and better user experience
    cout << setfill('*') << setw(26) << "" << endl;

    // Menu choices
    cout << setfill(' ');
    cout << "* 1-Add One Hour         *" << endl;
    cout << "* 2-Add One Minute       *" << endl;
    cout << "* 3-Add One Second       *" << endl;
    cout << "* 4 -Exit Program        *" << endl;

    // Printing lower border
    cout << setfill('*') << setw(26) << "" << endl;
}