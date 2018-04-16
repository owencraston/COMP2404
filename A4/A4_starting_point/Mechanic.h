#ifndef MECHANIC_H
#define MECHANIC_H

#include <string>
#include "Vehicle.h"
#include "VehicleList.h"
#include "Person.h"

using namespace std;

class Mechanic : public Person {
    friend ostream& operator<<(ostream&, Mechanic&);
    public:
    
        Mechanic(string="", string="", string="", string="", int=0);
        int getId() const;
        int getSalary() const;
    
    private:
        int salary;
        static int nextId;
        
        const int id;
};

#endif
