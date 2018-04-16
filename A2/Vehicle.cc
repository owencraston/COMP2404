#include "Vehicle.h"

//Constructor
Vehicle::Vehicle(string mk, string mdl, string col, int yr, int miles) {

  make = mk;
  model = mdl;
  colour = col;
  year = year;
  mileage = miles;
}

//Get methods
string Vehicle::getMake() { return make; }
string Vehicle::getModel() { return model; }
string Vehicle::getColour() { return colour; }
int Vehicle::getYear() { return year; }
int Vehicle::getMilage() { return mileage; }
