/*
*** Description: Class definitions and implementation for managing a list of contacts.
*** Date: June 19, 2026
*** Author: Dmitriy Razzhivin
*/

#include <iostream>
#include <string>
using namespace std;

class ContactNode {
public:
   // Constructor
   ContactNode(string nameInit = "", string phoneInit = ""); 
   
   //public member functions (Getters and Setters):
   string GetName() const;
   string GetPhoneNumber() const;
   void InsertAfter(ContactNode* nodeLoc);
   ContactNode* GetNext() const;
   void PrintContactNode() const;
   
private:
   // Private Data Members
   string contactName;
   string contactPhoneNumber;
   ContactNode* nextNodePtr;
   
};
// Constructor
ContactNode::ContactNode(string nameInit, string phoneInit){
   this->contactName = nameInit;
   this->contactPhoneNumber = phoneInit;
   this->nextNodePtr = nullptr;
}

string ContactNode::GetName() const{
   return this->contactName;
}

string ContactNode::GetPhoneNumber() const{
   return this->contactPhoneNumber;
}

ContactNode* ContactNode::GetNext() const{
   return this->nextNodePtr;
}

void ContactNode::InsertAfter(ContactNode* nodeLoc){
  ContactNode* tmpNext = nullptr;
  
  tmpNext = this->nextNodePtr;
  this->nextNodePtr = nodeLoc;
  nodeLoc->nextNodePtr = tmpNext;
}

void ContactNode::PrintContactNode() const{
   cout << "Name: " << this->contactName << endl;
   cout << "Phone number: " << this->contactPhoneNumber << endl;
}

int main() {
   
   //decalring the variables to hold data for name and phone number   
   string inputName;
   string inputPhone;
   

   
   //getting the input
   getline(cin, inputName);
   getline(cin, inputPhone);
   ContactNode* Person1 = new ContactNode(inputName, inputPhone);
   cout << "Person 1: " << Person1->GetName() << ", " << Person1->GetPhoneNumber() << endl;
   
   // Contact #2
   getline(cin, inputName);
   getline(cin, inputPhone);
   ContactNode* Person2 = new ContactNode(inputName, inputPhone);
   cout << "Person 2: " << Person2->GetName() << ", " << Person2->GetPhoneNumber() << endl;
   
   // Contact #3
   getline(cin, inputName);
   getline(cin, inputPhone);
   ContactNode* Person3 = new ContactNode(inputName, inputPhone);
   cout << "Person 3: " << Person3->GetName() << ", " << Person3->GetPhoneNumber() << endl;
   
   // creating pointers for ContactNode objects
   ContactNode* headContact = Person1;
   ContactNode* currContact = nullptr;
   
   // Linking the contacts together
   Person1->InsertAfter(Person2);
   Person2->InsertAfter(Person3);
   
   //Printing
   cout << endl << "CONTACT LIST" << endl;
   
   currContact = headContact;
   while(currContact != nullptr){
      currContact->PrintContactNode();
      cout << endl;
      currContact = currContact->GetNext();
   }
   
   
   return 0;
}