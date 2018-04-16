#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "CustomerList.h"

CustomerList::CustomerList() : head(0) { }


CustomerList::~CustomerList()
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


Customer* CustomerList::get(int id) 
{
  Node *currNode = head;

  while (currNode != 0) {
    if(currNode->data->getId() == id) {
      return currNode->data;
    }
    currNode = currNode->next;
  }

  return 0;
}

int CustomerList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

//taken from the previous add() function. This overloads the += operator
CustomerList& CustomerList::operator +=(Customer* newCust)
{
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newCust;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (newNode->data < currNode->data)
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

  //return a pointer to this list
  return *this;
}

//modified from the add() function. This overloads the -= operator
CustomerList& CustomerList::operator-=(Customer* c) {
  Node *currNode, *prevNode; 
  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    //check if the nodes are equal
    if (c == currNode->data)
      break; // if they are break out of the loop...
    prevNode = currNode;
    currNode = currNode->next;
  }

  //check if node is the head
  if (prevNode == 0) {
    //remove the head by pointing passed it
    head = head->next;
  }
  else {
    // skip passed the element in the list
    prevNode->next=currNode->next;
  }

  // remove c
  delete c;
  //set the next from our node to NULL so it points to nothing
  currNode->next = NULL;
  //delete the node
  delete currNode;
  
  // return a pointer to this list
  return *this;
}

Customer* CustomerList::operator[](int index) {
  //create a temp node and set it to head to start
    Node *currNode;
    currNode = this->head;

    //if the head is null the list is empty
    if(currNode == 0){
        cout << "Cannot get index on empty list" << endl;
        return 0;
    }

  // iterate over the list
  for(int x = 0; x < index; x++){
    // the element was not found so return error
    if(currNode == 0){
      cout << "Requested index is out of bounds" << endl;
      return 0;
    }
    // go to next node
    currNode = currNode->next;
  }
  //return the Customer in the node
  return currNode->data;
}

ostream& operator<<(ostream &output, CustomerList &list)   {
  
  // iterate over the list and print it, this takes advantage of the << operator in the Customer class
  for (int i=0; i < list.getSize(); i++) {
    output << *(list[i]) << endl;
  }
  return output;

}

