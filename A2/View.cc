#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "View.h"
#include "CustomerArray.h"
#include "Customer.h"
#include "VehicleArray.h"
#include "Vehicle.h"


void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 1) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}


void View::printCustomers(CustomerArray& arr) {
    cout << endl << "CUSTOMERS: " << endl << endl;

    for (int i = 0; i < arr.getSize(); i++) {
        
        Customer* cust = arr.get(i);
        ostringstream name;
        name << cust->getFname() << " " << cust->getLname();

        cout << "Customer ID " << cust->getId() << endl << endl
             << "    Name: " << setw(40) << name.str() << endl 
             << "    Address: " << setw(37) << cust->getAddress() << endl
             << "    Phone Number: " << setw(32) <<  cust->getPhoneNumber() << endl;
             
        if (cust->getNumVehicles() > 0) {
             cout << endl << "    " << cust->getNumVehicles() 
                  << " vehicle(s): " << endl << endl;
        }

        VehicleArray& varr = cust->getVehicles();
        for (int j = 0; j < varr.getSize(); j++) {
            Vehicle* v = varr.get(j);
            ostringstream make_model;
            make_model << v->getMake() << " " << v->getModel();

            cout << "\t" << j+1 << ") " << setw(7) << v->getColour() << " " 
                 << v->getYear() << " " << setw(17) << make_model.str() << " (" 
                 << v->getMilage() << "km)" << endl;
        }

        cout << endl << endl;   
    }
}

void View::pause() {
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

int View::readInt() {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}
