#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include <string>
#include "Vehicle.h"

Vehicle::Vehicle(string ma, string mo, string col, int y, int m) { 
    //constructor that sets all the attributes
    make = ma;
    model = mo;
    colour = col;
    year = y;
    mileage = m;
}
//getters
string  Vehicle::getMake() const     { return make; }
string  Vehicle::getModel() const    { return model; }
string  Vehicle::getColour() const   { return colour; }
int     Vehicle::getYear() const     { return year; }
int     Vehicle::getMilage() const   { return mileage; }

//override the << operator
//this is taken from the original print code and prints all the information about a vehicle
ostream& operator<<(ostream &output, Vehicle &v)   {
    output << "\t" << setw(7) << v.getColour() << " " 
        << v.getYear() << " " << setw(17) << v.getMake() << " " << v.getModel() << " (" 
        << v.getMilage() << "km)" << endl;

    return output;
}

//overload the < operator
bool Vehicle::operator<(Vehicle &rhs) {
    //check if the year is less than the right hand side
    if (getYear() < rhs.getYear()) {
        return true;
    } else {
        return false;
    }
}

//overload the > operator
bool Vehicle::operator>(Vehicle &rhs) {
    //check if the year is less than the reight hand side
    if (getYear() > rhs.getYear()) {
        return true;
    } else {
        return false;
    }
}


