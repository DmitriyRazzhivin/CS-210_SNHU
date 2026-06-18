/*
Given variables letter, region, and amount, declare and assign the following pointers:

character pointer letterPointer is assigned with the address of letter.
integer pointer regionPointer is assigned with the address of region.
double pointer amountPointer is assigned with the address of amount.
Ex: If the input is E 1 16.5, then the output is:

Oil grade: E
Region of import: 1
Quantity: 16.5

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   char letter;
   int region;
   double amount;
   
   char* letterPointer = &letter;
   int* regionPointer = &region;
   double* amountPointer = &amount;
   
   cin >> letter;
   cin >> region;
   cin >> amount;

   cout << "Oil grade: " << *letterPointer << endl;
	cout << "Region of import: " << *regionPointer << endl;
	cout << "Quantity: " << fixed << setprecision(1) << *amountPointer << endl;

   return 0;
}