#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include <string>
#include "VehicleList.h"

// taken from encapsulation number 8
VehicleList::VehicleList() : head(0) { }

// taken from encapsulation number 8
VehicleList::~VehicleList() {
    Node *currNode, *nextNode;
    currNode = head;
    while (currNode != 0) {
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

// taken from encapsulation number 8
void VehicleList::add(Vehicle* vehicle){
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = vehicle;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (newNode->data->getMilage() < currNode->data->getMilage()) //modified to sort by Milage
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

int VehicleList::getSize() const {
  //set a sixe counter to 0
  int size = 0;
  //iterate through the list and incrment the counter
  for (Node* currNode=head; currNode != 0; currNode = currNode->next)
    size ++;
  return size;
}

void VehicleList::toString(string& outStr) const {
  ostringstream vehicleInfo;
  cout << endl << "VEHICLE: " << endl << endl;

  // check the size of the list 
  int size = getSize();
  //if the size of the list is 0, dont print
  if (size > 0) {
    // create the currNode for iteration
    Node* currNode = head;
    int count = 0;
    // iterate over the list of vehicles
    // prit info
    while(currNode != 0) {
      vehicleInfo << count << "  Make:"  << currNode->data->getMake() << endl << endl
            << "  Model:" << currNode->data->getModel() << endl
            << "  Colour:" << currNode->data->getColour() << endl
            << "  Year:"  << currNode->data->getYear() << endl
            << "  Milage (KM):" << currNode->data->getMilage() << endl;

      // count up
      count++;
      // go to the next nodes
      currNode = currNode->next;
    }
  }
  //our output  as a string
  outStr = vehicleInfo.str();
}