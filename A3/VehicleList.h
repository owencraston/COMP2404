#ifndef VEHICLE_LIST_H
#define VEHICLE_LIST_H
#include "Vehicle.h"

class VehicleList
{
  class Node
  {
    friend class VehicleList;
    private:
      Vehicle* data;
      Node*    next;
  };
  public:
    VehicleList();
    ~VehicleList();
    void add(Vehicle*);
    int getSize() const;
    void toString(string&) const;
  private:
    Node* head;
};

#endif
