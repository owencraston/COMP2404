#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "View.h"
#include "CustomerList.h"
#include "Customer.h"
#include "VehicleList.h"
#include "Vehicle.h"


void View::mainMenu(int& choice) const {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "        2. Add Customer\n\n";
    cout<< "        3. Add vehicle\n\n";
    cout<< "        0. Exit\n\n";

    while (choice != 0 && choice != 1 && choice != 2 && choice != 3) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}


void View::printCustomers(CustomerList& list) const {
    cout << endl << "CUSTOMERS: " << endl << endl;

    //declare string to be passed into the toString() function
    string custInfo;
    //call toString()
    list.toString(custInfo);
    //print the output from the osstringstream
    cout << custInfo << endl;
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

// a function to get the users choice of customer id
void View::readID(int& id) const{
    //read the choice
    cout << "Customer ID:";
    id = readInt();
}

// function for getting the new user inputted data for a new vehicle
void View::readNewCustomer(string& fname, string& lname, string& add, string& pnumber) const {
    //create string to sore info
    string newCust;
    //gwt first name
    cout << "First Name:" << endl;
    getline(cin, newCust);
    fname = newCust;

    //get last name
    cout << "Last Name:" << endl;
    getline(cin, newCust);
    lname = newCust;

    //get address
    cout << "Address:" << endl;
    getline(cin, newCust);
    add = newCust;

    // get phone number
    cout << "Phone Numeber:" << endl;
    getline(cin, newCust);
    pnumber = newCust;
}

// function for getting the new user inputted data for a new vehicle
void View::readNewVehicle(string& mk, string& mdl, string& clr, int& yr, int& mil) const {
 //create string to sore info
    string newVehicle;

    //get make
    cout << "Make:";
    getline(cin, newVehicle);
    mk = newVehicle;

    //get model
    cout << "Model:";
    getline(cin, newVehicle);
    mdl = newVehicle;

    //get colour
    cout << "Make:";
    getline(cin, newVehicle);
    clr = newVehicle;

    // get year
    cout << "Year:";
    yr = readInt();

    // get milage
    cout << "Milage:";
    mil = readInt();
}

void View::printInvalidID() const {
    // use this when the id is invalid to display to the user
    cout<<"Invalid Customer ID, Please try again" << endl;
}
