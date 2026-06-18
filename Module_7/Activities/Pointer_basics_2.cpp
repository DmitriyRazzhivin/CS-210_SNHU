/*
Assign sizePointer with the address of the smaller size. If the sizes are the same, then assign sizePointer with nullptr.

Ex: If the input is 189 180, then the output is:

180 is the smaller size.
sizePointer points to size2.

*/

#include <iostream>
using namespace std;

int main() {
   int size1;
   int size2;
   int* sizePointer;

   cin >> size1;
   cin >> size2;
   
   if (size1 < size2){
      sizePointer = &size1;
   }
   else if(size2 < size1){
      sizePointer = &size2;
   }
   else{
      sizePointer = nullptr;
   }

   if (sizePointer == nullptr) {
      cout << "The sizes are the same." << endl;
   }
   else {
      cout << *sizePointer << " is the smaller size." << endl;
      
      if (sizePointer == &size1) {
         cout << "sizePointer points to size1." << endl;
      }
      if (sizePointer == &size2) {
         cout << "sizePointer points to size2." << endl;
      }
   }

   return 0;
}