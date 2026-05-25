/*
4.11 LAB: Sort a vector

Define a function named SortVector that takes a vector of integers as a parameter. Function SortVector() modifies the vector parameter by sorting the elements in descending order (highest to lowest). Then write a main program that reads a list of integers from input, stores the integers in a vector, calls SortVector(), and outputs the sorted vector. The first input integer indicates how many numbers are in the list.

Ex: If the input is:

5 10 4 39 12 2
the output is:

39,12,10,4,2,
For coding simplicity, follow every output value by a comma, including the last one.

Your program must define and call the following function:
void SortVector(vector<int>& myVec)
*/

/*
Name: Dmitriy Razzhivin
Date: 05/23/26
Program's purpose: This program uses 'SortVector' user-defined function that takes vector of integers
as a parameter then sorts the vector in the descending order using Bubble sort algorithm.
In main function the new vector is declared, then from the input we take the vector size, then using 
for loop the values are entered into vector, then using SortVector function we sort the vector, and finally
the vector's values displayed.
*/

#include <iostream>
#include <vector>
using namespace std;

/* This function is used to sort a vector of integers using Bubble sort method.*/
void SortVector(vector<int>& userVector){
   
   int n = userVector.size();
   // Outer loop tracks the number of passes through the vector
   for (int i = 0; i < n - 1; ++i){
      // Flag to track if any elements were swapped during this pass
      bool swapped = false;
      
      // Inner loop compares adjacent elements. 
      // 'n - i - 1' prevents checking elements already sorted at the end.
      for (int j = 0; j < n - i - 1; ++j){
         if(userVector[j] < userVector[j + 1]){
            // Compare adjacent values; swap if the left value is smaller than the right
            int temp = userVector[j];
            userVector[j] = userVector[j + 1];
            userVector[j + 1] = temp;
            
            swapped = true;
         }
      }
      if (!swapped)  // Exit early if array is already sorted
         break;
      
   }
}

int main() {
   
   int n;
   cin >> n;  // Read the total number of elements to process
  
   vector<int> myVector;  // Initialize vector as empty to allow dynamic allocation via push_back
   
   // Read input values and dynamically populate the vector
   for (int i = 0; i < n; ++i){
      int element;
      cin >> element;
      myVector.push_back(element);
   }
   
   // Sort elements from highest to lowest
   SortVector(myVector);
   // for loop for testing
   for (size_t i = 0; i < myVector.size(); ++i){
      cout << myVector.at(i) << ",";
   }
   cout << endl;

   return 0;
}
