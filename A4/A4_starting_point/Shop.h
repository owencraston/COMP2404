#ifndef SHOP_H
#define SHOP_H

#include "Customer.h"
#include "Mechanic.h"
#include "CustomerList.h"

class Shop{

    public:
        Shop();
        ~Shop();
        Customer* getCustomer(int);
        CustomerList& getCustomers();
        Mechanic* getMechanic(int);
        Mechanic** getMechanics();
        int getMechanicArraySize();
        int getNumMechanics();
        Shop& operator += (Customer*);
        Shop& operator -= (Customer*);
        Shop& operator += (Mechanic*);
    private:
        CustomerList customers;
        int numMechanics;

        Mechanic* mechanicArray[5];


};

#endif
