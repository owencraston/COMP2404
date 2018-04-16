#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person {

    public:
        Person(string, string, string, string);
        string getFname() const;
        string getLname() const;
        string getAddress() const;
        string getPhoneNumber() const;

    protected:
        string firstName;
        string lastName;
        string address;
        string phoneNumber;
};

#endif
