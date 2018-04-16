#ifndef SHOP_H
#define SHOP_H

#include "Customer.h"
#include "CustomerList.h"

class Shop{

    public:
        void addCustomer(Customer*);
        Customer* getCustomer(int) const;
        CustomerList& getCustomers();

    private:
        CustomerList customers;

};

#endif
