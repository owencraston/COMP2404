#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Vehicle.h"
using namespace std;

class Car : public Vehicle {

    public:
        Car(string="", string="", string="", int = 0, int = 0);
        string toString();
};

#endif
