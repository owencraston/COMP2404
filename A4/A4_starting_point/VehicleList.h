#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "Vehicle.h"
#include <string>
using namespace std;


class VehicleList
{
  friend ostream& operator<<(ostream&, VehicleList&);
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
    int getSize() const;
    Vehicle* operator[](int);
    VehicleList& operator +=(Vehicle*);
    VehicleList& operator -=(Vehicle*);
  private:
    Node* head;
};

#endif
