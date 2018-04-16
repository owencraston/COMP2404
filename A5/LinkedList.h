#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


template<class T>
class LinkedList
{
  template<typename U>
  friend ostream& operator<<(ostream&, LinkedList<U>&);

  class Node
  {
    friend class LinkedList;
    private:
      T* data;
      Node* next;
  };

  public:
    LinkedList();
    ~LinkedList();
    int getSize() const;

    LinkedList<T>& operator+=(T*);
    LinkedList<T>& operator-=(T*);
    T* operator[](int);

  private:
    Node* head;
};

// set the head to null
template<class T>
LinkedList<T>::LinkedList() : head(0) { }

// destructor that deletes all the data
template <class T>
LinkedList<T>::~LinkedList() {
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}


// this operator was taken from the existing List classes
template<class T>
LinkedList<T>& LinkedList<T>::operator+=(T* object)
{
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = object;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*(newNode->data) > *(currNode->data))
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

// this operator was taken from the existing List classes
template<class T>
LinkedList<T>& LinkedList<T>::operator-=(T* i)
{
  Node *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == i)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0)
    return *this;

  if (prevNode == 0) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  delete currNode;

  return *this;
}

// calculates the size without storing it as an attribute
template<class T>
int LinkedList<T>::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }

  return size;
}

// gets the item at the given index
template<class T>
T* LinkedList<T>::operator[](int i) {
    if(i < 0 || i > (getSize()-1)) {
        return 0;
    } else {

        Node *currNode = head;
        //iterate over list and stop when item is found
        for (int j = 0; j < i; j++) {
            currNode = currNode->next;
        }

        // return item
        return currNode->data;
    }
}

//void LinkedList::toString(string& outStr)
//calls the << of the element
template<class T>
ostream& operator<<(ostream& output, LinkedList<T>& list)
{
  //iterate through list and call << on each item
  for (int i = 0; i < list.getSize(); i++)  {
    output << (*(list[i]));
  }

  return output;

}
#endif
