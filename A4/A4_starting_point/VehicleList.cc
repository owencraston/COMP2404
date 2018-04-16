#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include <string>

#include "VehicleList.h"

//constructor that sets head to null
VehicleList::VehicleList() : head(0) { }


//deststructor that clears the list
VehicleList::~VehicleList()
{
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

//get size of the list
int VehicleList::getSize() const {
  //create temp node and counter
  Node *currNode = head;
  int size = 0;

  //iterate over the list and increment the counter
  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  //return the result
  return size;
}

//overload the [] opeator, take an index and get the value at thta index
Vehicle* VehicleList::operator[](int index) {
    //create a temp node and set it to head
    Node *currNode;
    currNode = this->head;

    // if the node is null the list is empty
    if(currNode == 0){
        cout << "Cannot get index on empty list" << endl;
        return 0;
    }

  // else iterte over list
  for(int x = 0; x < index; x++){
    // check if the node is null
    if(currNode == 0){
      cout << "Requested index is out of bounds" << endl;
      return 0;
    }
    //go to next node
    currNode = currNode->next;
  }
  //return Vehicle at spot
  return currNode->data;
}

//overload the += operator. This code was taken from the add() function
VehicleList& VehicleList::operator+=(Vehicle* newVeh) {
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newVeh;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (newNode->data > currNode->data)
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
  //return the pointer to this list
  return *this;
}

//overload the -= operator. this function modifies the add function
VehicleList& VehicleList::operator-=(Vehicle* v) {
  Node *currNode, *prevNode;  

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    //check if the nodes are equal
    if (v == currNode->data)
      break; //if they are break from the loop
    prevNode = currNode;
    currNode = currNode->next;
  }
    //check if node is the head
  if (prevNode == 0) {
    //remove the head by pointing passed it
    head = head->next;
  }
  else {
    //remove the node from the list
    prevNode->next=currNode->next;
  }

  //delete the node and data as well as set the next pointe to null
  currNode->next = NULL;
  delete v;
  delete currNode;
  
  //return the pointer to the list
  return *this;
}


//overload the << operator. 
ostream& operator<<(ostream &output, VehicleList &list)   {
  
  //iterate over the list and print it. This takes advantage of the << operator on vehicle
  for (int i=0; i < list.getSize(); i++) {
    output << *(list[i]) << endl;
  }
  return output;

}