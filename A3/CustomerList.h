#ifndef CUSTOMER_LIST_H
#define CUSTOMER_LIST_H
#include "Customer.h"

class CustomerList
{
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
    int getSize() const;
    Customer* get(int) const;
    void toString(string&) const;
  private:
    Node* head;
};

#endif