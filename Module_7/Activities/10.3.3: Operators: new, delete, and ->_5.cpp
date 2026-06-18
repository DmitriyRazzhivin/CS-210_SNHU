/*
Read an integer as the number of MovingBody objects. Assign myMovingBodies with an array of that many MovingBody objects. For each object, call object's Read() followed by the object's Print().

Ex: If the input is 2 35 8 41 37, then the output is:

MovingBody's force: 35
MovingBody's displacement: 8
MovingBody's force: 41
MovingBody's displacement: 37
MovingBody with force 41 and displacement 37 is deallocated.
MovingBody with force 35 and displacement 8 is deallocated.

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
      int force;
      int displacement;
};
MovingBody::MovingBody() {
   force = 0;
   displacement = 0;
}
void MovingBody::Read() {
   cin >> force;
   cin >> displacement;
}
void MovingBody::Print() {
   cout << "MovingBody's force: " << force << endl;
   cout << "MovingBody's displacement: " << displacement << endl;
}
MovingBody::~MovingBody() { // Covered in section on Destructors.
   cout << "MovingBody with force " << force << " and displacement " << displacement << " is deallocated." <<  endl;
}

int main() {
   MovingBody* myMovingBodies = nullptr;
   int count;
   int i;
   
   cin >> count;
   myMovingBodies = new MovingBody [count];
   
   for(i = 0; i < count; i++){
      myMovingBodies[i].Read();
      myMovingBodies[i].Print();
   }
   
   delete[] myMovingBodies;
  
   return 0;
}