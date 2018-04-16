#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class Vehicle {

    friend ostream& operator<<(ostream&, Vehicle&);

    public:
        Vehicle(string, string, string, int, int);
    
        string getMake() const;
        string getModel() const;
        string getColour() const;
        int getYear() const;
        int getMilage() const;

        bool operator<(Vehicle&);
        bool operator>(Vehicle&);
        virtual string toString() = 0;

    protected:
        string make;
        string model;
        string colour;
        int year;
        int mileage;
};

#endif
