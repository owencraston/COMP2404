#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include <string>
#include "CustomerList.h"
// taken from encapsulation number 8
CustomerList::CustomerList() : head(0) { }

// taken from encapsulation number 8
CustomerList::~CustomerList() {
    Node* currNode, *nextNode;
    currNode = head;
    while (currNode != 0) {
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}
// taken from encapsulation number 8,
void CustomerList::add(Customer* customer){
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = customer;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (newNode->data->getLname() < currNode->data->getLname()) // modified this to sort by last name
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0) {
    head = newNode;
  }
  else {
    prevNode->next = newNode;
  }

  newNode->next = currNode;
}

int CustomerList::getSize() const {
  // set a size counter to 0
  int size = 0;
  // iterate through the list and count up
  for (Node* currNode=head; currNode != 0; currNode = currNode->next) {
    size ++; //increment the counter
  }
  return size; // return size
}

Customer* CustomerList::get(int id) const {
  //create new node and set it to the head of the list
  Node* currNode=head;

  //iterate through the list until the node with the specified id is found
  while (currNode != 0) {
    if (currNode->data->getId() == id) {
      return currNode->data;
    }
    currNode = currNode->next;
  }
  //return Customer
  return currNode->data;
}

void CustomerList::toString(string& outStr) const {
  //define an osstring stream to store our values
  ostringstream customerInfo;
  cout << endl << "CUSTOMERS: " << endl << endl;

  // create the currNode for iteration
  Node* currNode = head;

  // iterate over the list of Customers, get and print the info to the stream
  while(currNode != 0) {
    customerInfo << "ID:"  << currNode->data->getId() << endl << endl
           << "First name:" << currNode->data->getFname() << endl
           << "Last name:" << currNode->data->getLname() << endl
           << "Address:"  << currNode->data->getAddress() << endl
           << "Phonenumber:" << currNode->data->getPhoneNumber() << endl
           << "Number of vehicles:" << currNode->data->getNumVehicles() << endl;
           //create a new string to be passed into the vehiclelist toString()
    string vehicleList;
    //get the vehicles and their info
    currNode->data->getVehicles().toString(vehicleList);
    // print the entire values to our os string stream
    customerInfo << vehicleList << endl;
    // go to next customer
    currNode = currNode->next;
  }
  // this is our output
  outStr = customerInfo.str();
}
