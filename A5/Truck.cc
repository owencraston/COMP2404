#include "Truck.h"

Truck::Truck(string ma, string mo, string col, int y, int m, int a) : Vehicle(ma, mo, col, y, m), numAxles(a) {}

int Truck::getNumAxles() const { return numAxles; }

//this logic comes mostly from the << in vehicle but modifed to print the number of axles
string Truck::toString() {
  //create ostringstreams for make_model and the rest of the output
  ostringstream make_model, output;
  make_model << make << " " << model;

  // get the rest of the infor about the Truck
  output << "\t" << setw(7) << colour << " " << year << " " << setw(17);
  output << make_model.str() << " (" << mileage << "km)" << " Number of axles: " << numAxles << endl;

  //return string of output
  return output.str();
}
