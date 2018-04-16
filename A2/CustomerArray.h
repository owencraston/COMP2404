#ifndef CUSTOMERARRAY_H
#define CUSTOMERARRAY_H

#include "Customer.h"

class CustomerArray
{
    public:
        CustomerArray();
        ~CustomerArray();
        int add(Customer*);
        Customer* get(int);
        int getSize();
    private:
        Customer* elements[MAX_CUSTOMERS];
        int size;
};

#endif