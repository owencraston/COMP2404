#include "VehicleArray.h"
#include "Vehicle.h"
#include "defs.h"
#include <iostream>
using namespace std;

// constructor
VehicleArray::VehicleArray() {
  size = 0;
}

// destructor
VehicleArray::~VehicleArray() {
  //delete all customer elements
  for (int i=0; i<size; i++) {
    delete elements[i];
  }
}

// getSize retuns size of array
int VehicleArray::getSize() { return size; }

// get, returns index to element
Vehicle* VehicleArray::get(int index) {
  if (index >= 0 && index <= size) {
    return elements[index];
  }
  return 0;
}

// add
int VehicleArray::add(Vehicle* v) {
  if (size < MAX_VEHICLES) {
    elements[size] = v;
    size++;
    return C_OK;
  }
  return C_NOK;
}