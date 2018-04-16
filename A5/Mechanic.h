#ifndef MECHANIC_H
#define MECHANIC_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Person.h"

using namespace std;

class Mechanic : public Person {

    friend ostream& operator<<(ostream&, Mechanic&);

    public:
    
        Mechanic(string="", string="", string="", string="", int=0);
        int getId() const;
        bool operator<(Mechanic&);
        bool operator>(Mechanic&);

    private:

        static int nextId;

        const int id;
        int salary;
};

#endif
