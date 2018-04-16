#include "Car.h"

//initialize the Car, since the values are the same as Vehicle we only need to init the vehicle attributes
Car::Car(string ma, string mo, string col, int y, int m) : Vehicle(ma, mo, col, y, m) {}

//print the car information
//this function was taken from the origin printing in the vehicle class
string Car::toString() {
  //create ostringsteam to store output of car info
  ostringstream make_model, output;
  make_model << make << " " << model;
  //print the car info
  output << "\t" << setw(7) << colour << " " << year << " " << setw(17);
  output << make_model.str() << " (" << mileage << "km)" << endl;
  //return string output
  return output.str();
}
