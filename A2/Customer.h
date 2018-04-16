#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Vehicle.h"
#include "VehicleArray.h"
using namespace std;

class Customer {

    public:
    
        Customer(string="", string="", string="", string="");
    
        int getId();
        string getFname();
        string getLname();
        string getAddress();
        string getPhoneNumber();
        int getNumVehicles();
        VehicleArray& getVehicles();
        
        int addVehicle(Vehicle*);
        
    private:

        static int nextId;
        
        int id;
        string firstName;
        string lastName;
        string address;
        string phoneNumber;
        VehicleArray vehicles;
};

#endif
