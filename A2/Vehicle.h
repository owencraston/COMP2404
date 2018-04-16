#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {

    public:
        Vehicle(string, string, string, int, int);

        string getMake();
        string getModel();
        string getColour();
        int getYear();
        int getMilage();

    private:
        string make;
        string model;
        string colour;
        int year;
        int mileage;
};

#endif
