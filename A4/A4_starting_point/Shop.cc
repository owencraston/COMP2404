#include "Shop.h"
#include "defs.h"
#include <iostream>

// constructor that sets the initial numMechanics to 0
Shop::Shop(): numMechanics(0) {}
//destructor to clear memory
Shop::~Shop() {
    for (int i=0; i<5; i++) {
        //remove the elements in the mechanicsArray
        delete mechanicArray[i];
    }
}

// get  id
Customer* Shop::getCustomer(int i)  { return customers.get(i); } 

// get customers list
CustomerList& Shop::getCustomers() { return customers; }

// get a specific mechanic
Mechanic* Shop::getMechanic(int i)  { return mechanicArray[i]; } 

//get the mechanics array
Mechanic** Shop::getMechanics() { return mechanicArray; }


//getter for the num of mechanics
int Shop::getNumMechanics() { return numMechanics; }

// add a customer to the customers list. This takes advantage of the += operator 
Shop& Shop::operator += (Customer * c) {
    customers += c;
    // return the pointer tio this list
    return *this;
}

// remove a customer from the customers list. This takes advantage of the -= operator 
Shop& Shop::operator -= (Customer * c) {
    customers -= c;
    // return the pointer to this list
    return *this;
}

//overload the += operator to take a mechanic and add it to the mechanics array
Shop& Shop::operator += (Mechanic * m) {
    // create a var to check when the step is done so we only perform the action once
    int done = 0;
    //iterate over the array starting at the size
    for(int i = numMechanics; i < 5 && done == 0; i++) {
        //add the mechanic at that position
        mechanicArray[i] = m;
        //increment the numMechanics value
        numMechanics++;
        ///set done to 1 so that we dont do it again
        done = 1;
    }
    //return the pointer to this list
    return *this;
}