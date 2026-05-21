/*
"123" is a string commonly found in weak passwords. Use a while loop to find and replace t
he occurrences of "123" in keyWord with an empty string (""). Then, assign lengthStr with the length of keyWord.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
   string keyWord;
    int index;
    int lengthStr;
   
    cin >> keyWord;

    index = keyWord.find("123");
	//lengthStr = 0;

   while (index != string::npos){
      
        keyWord.erase(index, 3);
      
        index = keyWord.find("123");
   }
   lengthStr = keyWord.size();

   cout << "Remaining string: " << keyWord << endl;
	cout << "Length: " << lengthStr << endl;
   
   return 0;
}