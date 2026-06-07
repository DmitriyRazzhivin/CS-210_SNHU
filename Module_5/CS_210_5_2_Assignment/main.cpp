/*
*** Name: Dmitriy Razzhivin
*** Description: Reads city temperature data from an input file, 
***             converts Fahrenheit values to Celsius, and writes 
***             the structured results to an output text file.
*** Date: June 7, 2026
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Local variables for data tracking
    string cityName;
    int fahrenheitTemp;
    double celsiusTemp;


    // Opening the file using ifstream
    ifstream inputFile("FahrenheitTemperature.txt");

    //Checking of the file opened successfully
    if (!inputFile.is_open()){
        cout << "Error: Could not open the file" << endl;
        return 1;
    }

    // Opening the output file for writing
    ofstream outputFile("CelsiusTemperature.txt");
    if(!outputFile.is_open()) {
        cout << "Error: Could not open the file" << endl;
        inputFile.close(); // Closing the inputFile if could not open outputFile
        return 1;
    }

    // Processing data
    while(inputFile >> cityName >> fahrenheitTemp){
        // Fahrenheit to Celsius conversion calculation
        celsiusTemp = (fahrenheitTemp - 32.0) * (5.0 / 9.0);
        
        // Formatting the output file stream to 2 decimal places
        outputFile << fixed << setprecision(2);

        // Writing data directly to the output text file
        outputFile << cityName << " " << celsiusTemp << endl;

    }

    //Closing  both files
    inputFile.close();
    outputFile.close();

    cout << "Conversion complete. CelsiusTemperature.txt has been generated." << endl;

    return 0;
}