#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include "Mechanic.h"


int Mechanic::nextId = 5000;

Mechanic::Mechanic(string fname, string lname, string add, string pnum, int sal) : 
        id(Mechanic::nextId++), salary(sal), Person(fname, lname, add, pnum) { //set all the class attributes as well as the parent class attributes (person)
}

// getters
int Mechanic::getId() const           { return id; }
int Mechanic::getSalary() const         {return salary; }

// overload the << operator and model the print off the Customer class print
// this prints all the info about the Mechanic, mosty from the Perosn class but also prints the salary from the Mechanic
ostream& operator<<(ostream& output, Mechanic& m) {
    ostringstream name;
    name << m.getFname() << " " << m.getLname();

    output << "Mechanic ID " << m.getId() << endl << endl
        << "    Name: " << setw(40) << name.str() << endl 
        << "    Address: " << setw(37) << m.getAddress() << endl
        << "    Phone Number: " << setw(32) <<  m.getPhoneNumber() << endl
        << "    Salary: " << setw(32) << m.getSalary() << endl; //print salary


    return output;
}
