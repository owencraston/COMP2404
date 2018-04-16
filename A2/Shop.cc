#include "Shop.h"
#include "defs.h"

int Shop::addCustomer(Customer* c) { return customers.add(c); }

Customer& Shop::getCustomer(int i)  { return *(customers.get(i)); } 

CustomerArray& Shop::getCustomers() { return customers; }
