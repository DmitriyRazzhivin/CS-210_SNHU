/*
Two strings, name1 and name2, are read from input as two friends' names. headObj has the default value of "name". Create a new node firstFriend with string name1 and insert firstFriend after headObj. Then, create a second node secondFriend with string name2 and insert secondFriend after firstFriend.

Ex: If the input is Jen Gus, then the output is:

name
Jen
Gus
*/
#include <iostream>
using namespace std;

class FriendNode {
   public:
      FriendNode(string nameInit = "", FriendNode* nextLoc = nullptr);
      void InsertAfter(FriendNode* nodeLoc);
      FriendNode* GetNext();
      void PrintNodeData();
   private:
      string nameVal;
      FriendNode* nextNodePtr;
};

FriendNode::FriendNode(string nameInit, FriendNode* nextLoc) {
   this->nameVal = nameInit;
   this->nextNodePtr = nextLoc;
}

void FriendNode::InsertAfter(FriendNode* nodeLoc) {
   FriendNode* tmpNext = nullptr;

   tmpNext = this->nextNodePtr;
   this->nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}

FriendNode* FriendNode::GetNext() {
   return this->nextNodePtr;
}

void FriendNode::PrintNodeData() {
   cout << this->nameVal << endl;
}

int main() {
   FriendNode* headObj = nullptr;
   FriendNode* firstFriend = nullptr;
   FriendNode* secondFriend = nullptr;
   FriendNode* currFriend = nullptr;
   string name1;
   string name2;

   cin >> name1;
   cin >> name2;

   headObj = new FriendNode("name");
   
   firstFriend = new FriendNode(name1);
   headObj->InsertAfter(firstFriend);
   
   secondFriend = new FriendNode(name2);
   firstFriend->InsertAfter(secondFriend);

   currFriend = headObj;
   while (currFriend != nullptr) {
      currFriend->PrintNodeData();
      currFriend = currFriend->GetNext();
   }

   return 0;
}