#include <iostream>
using namespace std;
#include "Customer.h"

int Customer::nextId = 1000;

//Constructor
Customer::Customer(string first_Name, string last_Name, string addr, string phone_Number) {
  firstName = first_Name;
  lastName = last_Name;
  address = addr;
  phoneNumber = phone_Number;
  id = nextId++;
}

//Getters
int Customer::getId() { return id; }
string Customer::getFname() { return firstName; }
string Customer::getLname() { return lastName; }
string Customer::getAddress() { return address; }
string Customer::getPhoneNumber() { return phoneNumber; }
VehicleArray& Customer::getVehicles() { return vehicles; }
int Customer::getNumVehicles() { return vehicles.getSize(); }

//Add vehicle
int Customer::addVehicle(Vehicle* v) { return vehicles.add(v); }