#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "View.h"
#include "CustomerList.h"
#include "Customer.h"
#include "VehicleList.h"
#include "Vehicle.h"


void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "        2. Add Customer\n\n";
    cout<< "        3. Add Vehicle\n\n";
    cout<< "        4. Remove Customer\n\n";
    cout<< "        5. Remove Vehicle\n\n";
    cout<< "        6. Print Mechanics\n\n";
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 6) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}

void View::displayInvalid() { cout << "Invalid choice." << endl << endl; }

void View::promptUserInfo(string &fname, string &lname, string &address, string &phone) {
    cout << "\nFirst name: ";
    getline(cin, fname);
    cout << "Last name: ";
    getline(cin, lname);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone number: ";
    getline(cin, phone);
    cout<<endl;
}

void View::promptVehicleInfo(string &make, string &model, string &colour, 
                                int &year, int &mileage) {
    cout << "\nMake: ";
    getline(cin, make);
    cout << "Model: ";
    getline(cin, model);
    cout << "Colour: ";
    getline(cin, colour);
    cout << "Year: ";
    year = readInt();
    cout << "Mileage: ";
    mileage = readInt();
    cout<<endl;
}

void View::promptUserId(int &id) {
    cout << "Customer ID: ";
    id = readInt();
    cout<<endl;
}

void View::promptUserCarIndex(int &i) {
    cout << " Vehicle index: ";
    i = readInt();
    cout<<endl;
}


void View::printCustomers(CustomerList& arr) const {
    cout << endl << "CUSTOMERS: " << endl << endl;
    
    string output; 

    cout << arr << endl;
}

//print function that takes the size and an array of mechanics
void View::printMechanics(Mechanic** arr, int size) const {
    cout << endl << "Mechanics: " << size << endl << endl;

    //creae ostringstream to store the output
    ostringstream output;

    //iterate over the array based on size and call << to print the info
    for (int i=0; i<size;i++) {
        // this takes advantage of the << operator
        output << *(arr[i]) << endl;
    }

    //print output
    cout << output.str() << endl;
}

// success message for the removed customers
void View::printRemovedCustomer() const {
    cout << "Sucessfully removed customer" << endl;
}

//success message for the removed vehicle
void View::printRemovedVehicle() const {
    cout << "Sucessfully removed vehicle" << endl;
}


void View::pause() const {
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

int View::readInt() const {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}
