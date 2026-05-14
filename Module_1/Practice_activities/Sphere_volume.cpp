#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
   double sphereVolume;
   double sphereRadius;

   cin >> sphereRadius;

   sphereVolume = (4.0 / 3.0) * M_PI * (pow(sphereRadius, 3));

   cout << fixed << setprecision(2) << sphereVolume << endl;

   return 0;
}