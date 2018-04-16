#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"


class CustomerList
{
  friend ostream& operator<<(ostream&, CustomerList&);
  class Node
  {
    friend class CustomerList;
    private:
      Customer* data;
      Node*    next;
  };

  public:
    CustomerList();
    ~CustomerList();
    void add(Customer*);
    CustomerList& operator+= (Customer*);
    int getSize() const;
    Customer* get(int);
    CustomerList& operator -= (Customer*);
    Customer* operator[] (int);

  private:
    Node* head;
};

#endif
