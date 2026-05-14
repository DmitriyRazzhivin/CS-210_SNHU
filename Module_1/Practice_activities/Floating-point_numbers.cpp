#include <iomanip>
#include <iostream>
using namespace std;

int main() {
   // Modify the following code
   int lengthInches;
   int lengthFeet;
   
   cin >> lengthInches;
   
   lengthFeet = lengthInches / 12;
   
   cout << fixed << setprecision(3) << lengthFeet << " feet" << endl;

   return 0;
}