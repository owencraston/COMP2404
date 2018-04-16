#include <iostream>
using namespace std;
#include "Customer.h"


int Customer::nextId = 1000;

Customer::Customer(string fname, string lname, string add, string pnum) { 
    id          = nextId++;
    firstName   = fname;
    lastName    = lname;
    address     = add;
    phoneNumber = pnum;
}

int           Customer::getId() const                 { return id; }
string        Customer::getFname() const           { return firstName; }
string        Customer::getLname() const             { return lastName; }
string        Customer::getAddress() const            { return address; }
string        Customer::getPhoneNumber() const        { return phoneNumber; }
int           Customer::getNumVehicles() const       { return vehicles.getSize(); }
VehicleList& Customer::getVehicles()          { return vehicles; }
void           Customer::addVehicle(Vehicle* v)  { return vehicles.add(v); }

