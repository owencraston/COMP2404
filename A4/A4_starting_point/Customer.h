#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Vehicle.h"
#include "VehicleList.h"
#include "Person.h"

using namespace std;

class Customer : public Person {
    friend ostream& operator<<(ostream&, Customer&);
    public:
    
        Customer(string="", string="", string="", string="");
    
        int getId() const;
        int getNumVehicles() const;
        VehicleList& getVehicles();
        Customer& operator += (Vehicle*);
        bool operator<(Customer&);
        bool operator>(Customer&);
    private:

        static int nextId;
        
        const int id;
        VehicleList vehicles;
};

#endif
