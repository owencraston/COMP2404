#include <iostream>
using namespace std;
#include "Mechanic.h"

int Mechanic::nextId = 5000;

Mechanic::Mechanic(string fname, string lname, string add, string pnum, int sal) : 
        Person(fname,lname,add,pnum), id(Mechanic::nextId++), salary(sal) { }

int Mechanic::getId() const { return id; }

ostream& operator<<(ostream& output, Mechanic& m)
{
    ostringstream name;
    name << m.firstName << " " << m.lastName;

    output << "Employee ID " << m.id << endl << endl
           << "    Name: " << setw(40) << name.str() << endl 
           << "    Address: " << setw(37) << m.address << endl
           << "    Phone Number: " << setw(32) << m.phoneNumber << endl
           << "    Salary: " << setw(38) << m.salary << endl;
    return output;
}

bool Mechanic::operator<(Mechanic& m){
    return salary < m.salary;
}

bool Mechanic::operator>(Mechanic& m){
    return salary > m.salary;
}
