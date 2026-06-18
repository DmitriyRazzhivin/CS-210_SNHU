/*
Read two doubles as the power and the distance of a SoundWave object. Declare and assign pointer mySoundWave with a new SoundWave object using the power and the distance as arguments in that order. Then call mySoundWave's IncreaseDistance() member function.

Ex: If the input is 3.0 8.5, then the output is:

SoundWave's distance is increased.
SoundWave's power: 3.0
SoundWave's distance: 85.0


*/

#include <iostream>
#include <iomanip>
using namespace std;

class SoundWave {
   public:
      SoundWave(double powerValue, double distanceValue);
      void IncreaseDistance();
      void Print();
   private:
      double power;
      double distance;
};
SoundWave::SoundWave(double powerValue, double distanceValue) {
   power = powerValue;
   distance = distanceValue;
}
void SoundWave::IncreaseDistance() {
	distance = distance * 10.0;
   cout << "SoundWave's distance is increased." << endl;
}
void SoundWave::Print() {
   cout << "SoundWave's power: " << fixed << setprecision(1) << power << endl;
   cout << "SoundWave's distance: " << fixed << setprecision(1) << distance <<  endl;
}


int main() {
   
   double power, distance;
   cin >> power >> distance;
   
   SoundWave* mySoundWave;
   mySoundWave = new SoundWave(power, distance);
   
   mySoundWave->IncreaseDistance();

   /* Your code goes here */

   mySoundWave->Print();
   
   return 0;
}