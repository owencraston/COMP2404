#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h"

class View {

    public:
        void mainMenu(int&) const;
        void printCustomers(CustomerList&) const;
        void pause() const;
        void readID(int&) const;
        void readNewCustomer(string&, string&, string&, string&) const;
        void readNewVehicle(string&, string&, string&, int&, int&) const;
        void printInvalidID() const;
    private:
        int readInt() const;
};

#endif
