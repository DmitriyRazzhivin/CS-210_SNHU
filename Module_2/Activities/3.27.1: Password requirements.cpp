/*
String checkStr is read from input. For each character in checkStr that is a 
letter, increment count by 1. Then, output "Valid" if count is no more 
than 6 and checkStr's length is greater than or equal to 5. 
Otherwise, output "Invalid". End each output with a newline.

*/

#include <iostream>
using namespace std;

int main() {
   string checkStr;
   int i;
   int count;
   
   getline(cin, checkStr);
   count = 0;
   
   for (i = 0; i < checkStr.size(); ++i){
      if(isalpha(checkStr.at(i))){
         count++;
      }
   }
   //cout << "Count: " << count;
   if(count <= 6 && checkStr.size() >= 5)
      cout << "Valid" << endl;
   else
      cout << "Invalid" << endl;
   
   
   return 0;
}