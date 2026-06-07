/*
Complete the function to replace any period by an exclamation point. Ex: "Hello. I'm Miley. Nice to meet you." becomes:
"Hello! I'm Miley! Nice to meet you!"
*/
#include <iostream>
#include <string>
using namespace std;

void MakeSentenceExcited(string& sentenceText) {
   
   for(char &c : sentenceText) {
      if (c == '.'){
         c = '!';
      }
   }
   

}

int main() {
   string testStr;

   getline(cin, testStr);
   MakeSentenceExcited(testStr);
   cout << testStr;

   return 0;
}