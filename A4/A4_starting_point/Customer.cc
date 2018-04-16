#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "Customer.h"


int Customer::nextId = 1000;

Customer::Customer(string fname, string lname, string add, string pnum) : 
        id(Customer::nextId++), Person(fname, lname, add, pnum) {  //set the attributes and attributes of the parent class (person)
}

int           Customer::getId() const           { return id; }
int           Customer::getNumVehicles() const  { return vehicles.getSize(); }
VehicleList&  Customer::getVehicles()           { return vehicles; }


Customer& Customer::operator +=(Vehicle* v)  { 
    // make use of the += operator in vehicles to add to the list
    vehicles += v;
    //return a pointer to this list
    return *this;    
}

// overload << operator. Printing taken from the original printing code
ostream& operator<<(ostream& output, Customer& c) {
    // get the name and store it in a ostringstream
    ostringstream name;
    name << c.getFname() << " " << c.getLname();

    // use the output param and print all the other data to that stream
    output << "Customer ID " << c.getId() << endl << endl
        << "    Name: " << setw(40) << name.str() << endl 
        << "    Address: " << setw(37) << c.getAddress() << endl
        << "    Phone Number: " << setw(32) <<  c.getPhoneNumber() << endl;
    
    //if the customer has vehicles...
    if (c.getNumVehicles() > 0) {
        output << endl << "    " << c.getNumVehicles() 
                << " vehicle(s): " << endl << endl;

        // print the vehicles list
        string vehicle_output;
        output << c.getVehicles() << endl<<endl;
    }

    return output;
}

bool Customer::operator<(Customer &rhs) {
    //check if the last name is less than the right hand side last name
    if (getLname() < rhs.getLname()) {
        // since this is our condition, return true
        return true;
    } else {
        return false;
    }
}

bool Customer::operator>(Customer &rhs) {
    // check if the last name is greater than the right hand side last name
    if (getLname() > rhs.getLname()) {
        return true;
    } else {
        return false;
    }
}
