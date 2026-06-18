/*
ageValue and weightValue are read from input. Declare and assign pointer myHorse with a new Horse object. Then, set myHorse's age and weight to ageValue and weightValue, respectively.

Ex: if the input is 11 307, then the output is:

Horse's age: 11
Horse's weight: 307
*/
#include <iostream>
using namespace std;

class Horse {
   public:
      Horse();
      void Print();

      int age;
      int weight;
};
Horse::Horse() {
   age = 0;
   weight = 0;
}
void Horse::Print() {
   cout << "Horse's age: " << age << endl;
   cout << "Horse's weight: " << weight <<  endl;
}

int main() {
   int ageValue;
   int weightValue;
   
   Horse* myHorse;
   myHorse = new Horse;
  
   cin >> ageValue;
   cin >> weightValue;
  
   myHorse->age = ageValue;
   myHorse->weight = weightValue;
   
   myHorse->Print();
   
   return 0;
}
