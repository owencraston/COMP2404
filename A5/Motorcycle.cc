#include "Motorcycle.h"

Motorcycle::Motorcycle(string ma, string mo, string col, int y, int m, bool sc) : Vehicle(ma, mo, col, y, m), hasSideCar(sc) {}

// implement the toString method for motorcycle
string Motorcycle::toString() {
  // create ostringstream to store info about the vehicle
  ostringstream make_model, output;
  make_model << make << " " << model;

  // print the rest of the info with the extra variable of if the motorcycle has a side car
  output << "\t" << setw(7) << colour << " " << year << " " << setw(17);
  output << make_model.str() << " (" << mileage << "km)" << " " << "side car?" << hasSideCar << endl;

  // return string output
  return output.str();
}
