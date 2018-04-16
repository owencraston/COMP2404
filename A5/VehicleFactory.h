#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"

class VehicleFactory {

    public:
        Vehicle* create(string, string, string, int, int, int); // truck
        Vehicle* create(string, string, string, int, int); // car
        Vehicle* create(string, string, string, int, int, bool); // Motorcycle
};

#endif
