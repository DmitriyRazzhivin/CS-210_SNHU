/*
Write a copy constructor for CarParkingSpot that assigns origCarParkingSpot.parkingSpot to the constructed object's parkingSpot. Sample output for the given program:
Parking Spot: 5
*/

#include <iostream>
using namespace std;

class CarParkingSpot {
   public:
      CarParkingSpot();
      CarParkingSpot(const CarParkingSpot& origCarParkingSpot);
      void SetParkingSpot(const int spot) {
         *parkingSpot = spot;
      }
      int GetParkingSpot() const {
         return *parkingSpot;
      }
   private:
      int* parkingSpot;
};

CarParkingSpot::CarParkingSpot() {
   parkingSpot = new int;
   *parkingSpot = 0;
}

// FIXME add copy constructor
CarParkingSpot::CarParkingSpot(const CarParkingSpot& origCarParkingSpot){
   parkingSpot = new int;
   *parkingSpot = *(origCarParkingSpot.parkingSpot);
}

/* Your solution goes here  */

void ParkingSpotPrinter(CarParkingSpot carParkSpot) {
   cout << "Parking Spot: " << carParkSpot.GetParkingSpot();
}

int main() {
   CarParkingSpot carParkingSpot;
   int spot;

   cin >> spot;

   carParkingSpot.SetParkingSpot(spot);
   ParkingSpotPrinter(carParkingSpot);

   return 0;
}