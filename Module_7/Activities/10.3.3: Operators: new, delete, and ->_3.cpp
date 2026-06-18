/*
Assign pointer myMovingBody with a new MovingBody object. Call myMovingBody's Read() to read the object's fields. Then, call myMovingBody's Print() to output the values of the fields. Finally, delete myMovingBody.

Ex: If the input is 35 47, then the output is:

MovingBody's velocity: 35
MovingBody's duration: 47
MovingBody with velocity 35 and duration 47 is deallocated.
*/

#include <iostream>
using namespace std;

class MovingBody {
   public:
      MovingBody();
      void Read();
      void Print();
      ~MovingBody();
   private:
      int velocity;
      int duration;
};
MovingBody::MovingBody() {
   velocity = 0;
   duration = 0;
}
void MovingBody::Read() {
   cin >> velocity;
   cin >> duration;
}  
void MovingBody::Print() {
   cout << "MovingBody's velocity: " << velocity << endl;
   cout << "MovingBody's duration: " << duration << endl;
}  
MovingBody::~MovingBody() { // Covered in section on Destructors.
   cout << "MovingBody with velocity " << velocity << " and duration " << duration << " is deallocated." <<  endl;
}

int main() {
   MovingBody* myMovingBody = nullptr;
   
   myMovingBody = new MovingBody();
   
   myMovingBody->Read();
   myMovingBody->Print();
   
   delete myMovingBody;

   return 0;
}