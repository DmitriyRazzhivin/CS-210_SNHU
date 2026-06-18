/*
Complete ChangeArea() to output "areaPointer is null." if areaPointer is null. Otherwise, assign areaValue to the variable pointed to by areaPointer. End with a newline.

Ex: If the input is Y 2, then the output is:

Area is 2.
*/

#include <iostream>
using namespace std;

void ChangeArea(int* areaPointer, int areaValue) {

   if(areaPointer == nullptr){
      cout << "areaPointer is null." << endl;
   }
   else{
      *areaPointer = areaValue; 
   }

}

int main() {
   int area;
   int* areaPointer;
   char action;
   int value;

   area = 0;
   cin >> action;
   cin >> value;

   if (action == 'Y') {
      areaPointer = &area;
   }
   else {
      areaPointer = nullptr;
   }
  
   ChangeArea(areaPointer, value);
	cout << "Area is " << area << "." << endl;

   return 0;
}