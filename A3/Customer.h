#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Vehicle.h"
#include "VehicleList.h"
using namespace std;

class Customer {

    public:
    
        Customer(string="", string="", string="", string="");
    
        int getId() const;
        string getFname() const;
        string getLname() const;
        string getAddress() const;
        string getPhoneNumber() const;
        int getNumVehicles() const;
        VehicleList& getVehicles();
        
        void addVehicle(Vehicle*);
        
    private:

        static int nextId;
        
        int id;
        string firstName;
        string lastName;
        string address;
        string phoneNumber;
        VehicleList vehicles;
};

#endif
