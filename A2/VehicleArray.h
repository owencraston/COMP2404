#ifndef VEHICLEARRAY_H
#define VEHICLEARRAY_H

#include "defs.h"
#include "Vehicle.h"

class VehicleArray
{
    public:
        VehicleArray();
        ~VehicleArray();
        int add(Vehicle*);
        Vehicle* get(int);
        int getSize();
    private:
        Vehicle* elements[MAX_VEHICLES];
        int size;
};

#endif
