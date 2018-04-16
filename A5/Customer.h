#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Vehicle.h"
#include "Person.h"
#include "LinkedList.h"

using namespace std;

class Customer : public Person {

    friend ostream& operator<<(ostream&, Customer&);

    public:
    
        Customer(string="", string="", string="", string="");
    
        int getId() const;
        int getNumVehicles() const;
        LinkedList<Vehicle>& getVehicles();
        
        //void addVehicle(Vehicle*);
        Customer& operator+=(Vehicle*);
        bool operator<(Customer&);
        bool operator>(Customer&);

    private:

        static int nextId;

        const int id;
        LinkedList<Vehicle> vehicles;
};

#endif
