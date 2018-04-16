using namespace std;
#include <string>
#include "Person.h"


Person::Person(string fname, string lname, string add, string pnum)
{
    // set all the attributes on the Person class
    firstName   = fname;
    lastName    = lname;
    address     = add;
    phoneNumber = pnum;
}

// getters for all the Person attributres
string        Person::getFname() const        { return firstName; }
string        Person::getLname() const        { return lastName; }
string        Person::getAddress() const      { return address; }
string        Person::getPhoneNumber() const  { return phoneNumber; }