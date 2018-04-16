#include "VehicleFactory.h"

// create Truck method
Vehicle* VehicleFactory::create(string ma, string mo, string col, int y, int m, int a) {
  //create new instance with the passed in params
  return new Truck(ma, mo, col, y, m, a);
}

// create Car method
Vehicle* VehicleFactory::create(string ma, string mo, string col, int y, int m) {
  //create new instance with the passed in params
  return new Car(ma, mo, col, y, m);
}

// create Motorcycle method
Vehicle* VehicleFactory::create(string ma, string mo, string col, int y, int m, bool sc) {
  //create new instance with the passed in params
  return new Motorcycle(ma, mo, col, y, m, sc);
}
