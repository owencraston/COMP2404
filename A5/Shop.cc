#include "Shop.h"
#include "defs.h"
#include "LinkedList.h"

Shop::Shop() : numMechanics(0) { }

Shop::~Shop() {
    for (int i=0; i < numMechanics; i++)
        delete mechanics[i];
}

//void Shop::addCustomer(Customer* c) { customers += c; }
Shop& Shop::operator+=(Customer* c) {
    customers += c;
    return *this;
}

Shop& Shop::operator+=(Mechanic* m) {
    mechanics += m;
    return *this;
}

Shop& Shop::operator-=(Customer* c) {
    customers -= c;
    return *this;
}

// get customer based on ID
Customer* Shop::getCustomer(int i) {
  //iterate through the list of customers and check if the id is the same as the one passed in
    for (int j=0; j < customers.getSize(); j++) {
      // if they match...
        if (customers[j]->getId() == i) {
          //return the item in that list
            return customers[j];
        }
    }
    return 0;
}


LinkedList<Customer>& Shop::getCustomers() { return customers; }


// int Shop::getNumMechanics() { return mechanics.getSize(); }

// use linkedlist template as return type for get mechanics
LinkedList<Mechanic>& Shop::getMechanics()  { return mechanics; }
