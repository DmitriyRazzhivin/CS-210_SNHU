/*
Multiple integers, representing the number of ducklings, are read from input and inserted into a linked list of DuckNodes. For each integer greater than 7 in the linked list of DuckNodes, output the integer followed by " is plenty of ducklings." on a new line.

Ex: If the input is 1 8, then the output is:

8 is plenty of ducklings.
*/

#include <iostream>
using namespace std;
  
class DuckNode {
   public:
      DuckNode(int ducklingsInit = 0, DuckNode* nextLoc = nullptr);
      void InsertAfter(DuckNode* nodeLoc);
      DuckNode* GetNext();
      int GetNodeData();
   private:
      int ducklingsVal;
      DuckNode* nextNodePtr;
};

DuckNode::DuckNode(int ducklingsInit, DuckNode* nextLoc) {
   this->ducklingsVal = ducklingsInit;
   this->nextNodePtr = nextLoc;
}

void DuckNode::InsertAfter(DuckNode* nodeLoc) {
   DuckNode* tmpNext = nullptr;

   tmpNext = this->nextNodePtr;
   this->nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}

DuckNode* DuckNode::GetNext() {
   return this->nextNodePtr;
}

int DuckNode::GetNodeData() {
   return this->ducklingsVal;
}

int main() {
   DuckNode* headDuck = nullptr;
   DuckNode* currDuck = nullptr;
   DuckNode* lastDuck = nullptr;
   int count;
   int inputValue;
   int i;
   
   cin >> count;
   
   headDuck = new DuckNode(count);
   lastDuck = headDuck;

   for (i = 0; i < count; ++i) {
      cin >> inputValue;
      
      currDuck = new DuckNode(inputValue);
      
      lastDuck->InsertAfter(currDuck);
      lastDuck = currDuck;
   }

   // my solution here:
   currDuck = headDuck;
   while(currDuck != nullptr){
      
      if(currDuck->GetNodeData() > 7){
         cout << currDuck->GetNodeData() << " is plenty of ducklings." << endl;
      }
      currDuck = currDuck->GetNext();
   }
   
   return 0;
}
