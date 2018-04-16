#include "Shop.h"
#include "defs.h"

void Shop::addCustomer(Customer* c) { return customers.add(c); }

Customer* Shop::getCustomer(int i) const { return (customers.get(i)); } 

CustomerList& Shop::getCustomers() { return customers; }
