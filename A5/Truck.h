#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Vehicle.h"
using namespace std;

class Truck : public Vehicle {

    public:
        Truck(string="", string="", string="", int = 0, int = 0, int = 0);
        string toString();
        int getNumAxles() const;

    private:
      int numAxles;
};

#endif
