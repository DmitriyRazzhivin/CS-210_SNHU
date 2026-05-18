/*
Read in a 2-character string from input into variable passCode. Declare a boolean variable isValid and set isValid to true if the following conditions are met:

passCode does not contain two of the same character.
For alphabetic characters, passCode does not contain two of the same letter (regardless of case).
Otherwise, set isValid to false.
Ex: If the input is 8%, then isValid is assigned with true, so the output is:

Passcode is valid

Ex: If the input is Ff, then isValid is assigned with false, so the output is:

Passcode is not valid

Note: Use getline(cin, passCode) to read the entire line from input into passCode.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   string passCode;

   getline(cin, passCode);
   
   bool isValid;
   
   if( tolower(passCode.at(0)) != tolower( passCode.at(1)) ){
      isValid = true;
   }
   else
      isValid = false;
      
   if (isValid) {
      cout << "Passcode is valid" << endl;
   }
   else {
      cout << "Passcode is not valid" << endl;
   }

   return 0;
}