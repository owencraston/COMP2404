#ifndef VIEW_H
#define VIEW_H
#include "Mechanic.h"
#include "Customer.h"
#include "LinkedList.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(LinkedList<Customer>&) const;
        void pause() const;
        void promptUserInfo(string&, string&, string&, string&);
        void promptUserId(int&);
        void displayInvalid();
        void promptVehicleInfo(string&, string&, string&, int&, int&);
        void promptVehicle(int, int&);
        void printMechanics(LinkedList<Mechanic>&) const;
        void promptTruckInfo(string&, string&, string&, int&, int&, int&);
        void promptMotorcycleInfo(string&, string&, string&, int&, int&, string&);
        void getVehicleType(int&);
    private:
        int readInt() const;
};

#endif
