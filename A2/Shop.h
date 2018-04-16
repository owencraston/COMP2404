#ifndef SHOP_H
#define SHOP_H

#include "Customer.h"
#include "CustomerArray.h"

class Shop{

    public:
        int addCustomer(Customer*);
        Customer& getCustomer(int);
        CustomerArray& getCustomers();

    private:
        CustomerArray customers;

};

#endif
