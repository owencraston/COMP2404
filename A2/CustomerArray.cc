#include "CustomerArray.h"
#include "Customer.h"
#include "defs.h"

// constructor
CustomerArray::CustomerArray() {
  size = 0;
}

// destructor
CustomerArray::~CustomerArray() {
  //Iterate through list and delete customer elements
  for (int i=0; i<size; i++) {
    delete elements[i];
  }
}

// getSize returns the size of the array
int CustomerArray::getSize() { return size; }

// get, returns the 
Customer* CustomerArray::get(int index) {
  if (index >= 0 && index <= size) {
    return elements[index];
  }
  return 0;
}

// addreturns the pointer to the element
int CustomerArray::add(Customer* c) {
  if (size < MAX_CUSTOMERS) {
    elements[size] = c;
    size++;
    return C_OK;
  }
  return C_NOK;
}