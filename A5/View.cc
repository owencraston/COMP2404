#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "View.h"
#include "Customer.h"
#include "Vehicle.h"
#include "Mechanic.h"
#include "LinkedList.h"


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

//function to the vehicle type
void View::getVehicleType(int &choice) {
  choice = -1;
  cout << "      \n What type of vehicle do you want to add. Pick by typing the corresponding number \n\n";
  cout<< "        1. Car\n\n";
  cout<< "        2. Truck\n\n";
  cout<< "        3. Motorcycle\n\n";

  while (choice < 1 || choice > 3) {
      cout << "Enter your choice:  ";
      choice = readInt();
  }
}

// get information for new car
void View::promptVehicleInfo(string &make, string &model, string &colour,
                                int &year, int &mileage) {
    cout << "Car \n\n";
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

// get information for new Truck
void View::promptTruckInfo(string &make, string &model, string &colour,
                                int &year, int &mileage, int &numAxles) {
    cout << "Truck \n\n";
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
    cout << "Numbr of axles: ";
    numAxles = readInt();
    cout<<endl;
}

// get information for new Motorcycle
void View::promptMotorcycleInfo(string &make, string &model, string &colour,
                                int &year, int &mileage, string &sidecar) {
    cout << "Motorcycle \n\n";
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
    cout << "Side car?: ";
    getline(cin, sidecar);
    cout<<endl;
}

void View::promptUserId(int &id) {
    cout << "Customer ID: ";
    id = readInt();
    cout<<endl;
}

void View::printCustomers(LinkedList<Customer>& arr) const {
    cout << endl << "CUSTOMERS: " << endl << endl << arr << endl;
}

void View::printMechanics(LinkedList<Mechanic>& m) const {
    cout << endl << "MECHANICS: " << endl << endl << m << endl;
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

void View::promptVehicle(int numVehicles, int &choice) {
    cout << "Vehicle (0 - " << numVehicles-1 << "): ";
    choice = readInt();
    cout << endl;
}
