/*
Integer hareCount is read from input as the number of input values that follow. The node headHare is created with the value of hareCount. Use cin to read hareCount integers. Insert a HareNode for each integer at the end of the linked list.

Ex: If the input is 2 30 31, then the output is:

2
30
31
*/

#include <iostream>
using namespace std;
  
class HareNode {
   public:
      HareNode(int babiesInit = 0, HareNode* nextLoc = nullptr);
      void InsertAfter(HareNode* nodeLoc);
      HareNode* GetNext();
      void PrintNodeData();
   private:
      int babiesVal;
      HareNode* nextNodePtr;
};

HareNode::HareNode(int babiesInit, HareNode* nextLoc) {
   this->babiesVal = babiesInit;
   this->nextNodePtr = nextLoc;
}

void HareNode::InsertAfter(HareNode* nodeLoc) {
   HareNode* tmpNext = nullptr;

   tmpNext = this->nextNodePtr;
   this->nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}

HareNode* HareNode::GetNext() {
   return this->nextNodePtr;
}

void HareNode::PrintNodeData() {
   cout << this->babiesVal << endl;
}

int main() {
   HareNode* headHare = nullptr;
   HareNode* currHare = nullptr;
   HareNode* lastHare = nullptr;
   int hareCount;
   int inputValue;
   int i;

   cin >> hareCount;
   
   headHare = new HareNode(hareCount);
   lastHare = headHare;
   
   for(i = 0; i < hareCount; ++i){
      cin >> inputValue; // Reading next integer from standard input.
      currHare = new HareNode(inputValue); // Dynamically allocate a new HareNode on the heap.
      lastHare->InsertAfter(currHare); // Linking the new node directly after the current last node.
      lastHare = currHare; // Shift the lastNode pointer forward so the new node becomes the tail.
   }
      

   currHare = headHare;
   while (currHare != nullptr) {
      currHare->PrintNodeData();
      currHare = currHare->GetNext();
   }

   return 0;
}