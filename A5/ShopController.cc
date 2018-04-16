#include "ShopController.h"

ShopController::ShopController() {

    initShop();

}

void ShopController::launch() {

    int choice;

    while (1) {
        choice = -1;
        view.mainMenu(choice);

        if (choice == 1) {
            view.printCustomers(mechanicShop.getCustomers());
            view.pause();
        } else if (choice == 2) {
            string fname, lname, address, phone;
            view.promptUserInfo(fname, lname, address, phone);
            mechanicShop += new Customer(fname, lname, address, phone);
            view.pause();
        } else if (choice == 3) { // add vehicle
            int id;
            //get the Customer ID to add vehicle too
            view.promptUserId(id);
            //get the customer
            Customer* cust = mechanicShop.getCustomer(id);
            // if the customer was valid
            if (cust != 0) {
              //create variables for the vehcile attributes
              int choiceType; // variable to store the type of vehcile
              string make, model, colour;
              int year, milage, n;
                // get the type of vehicle the user wants to create
                view.getVehicleType(choiceType);
                if (choiceType == 1) { //car
                  // get info from user to create car
                  view.promptVehicleInfo(make, model, colour, year, milage);
                  //create car using factory and the info the user gave us
                  (*cust) += factory.create(make, model, colour, year, milage);
                } else if (choiceType == 2) {// truck
                  // we need an extra value to get the number of axles on the truck
                  int numAxles;
                  // get the info from user to create truck
                  view.promptTruckInfo(make, model, colour, year, milage, numAxles);
                  //create truck using factory and the info provided by user, add it to the customer
                  (*cust) += factory.create(make, model, colour, year, milage, numAxles);
                } else if (choiceType == 3) { //motor cycle
                  // we need an extra value to store if the motorbike has a side car, the string will store the users response and we will parse it into a boolean to create the motorcycle instance
                  string sideCarResponse;
                  bool sideCar;
                  // get the info about the bike from user
                  view.promptMotorcycleInfo(make, model, colour, year, milage, sideCarResponse);
                  // the response to sidecar was yes or y, then the bike has a side car
                  if((sideCarResponse == "y") || (sideCarResponse == "yes")) {
                    sideCar = true;
                  } else {
                    sideCar = false;
                  }
                  //create motorcycle based on the above response from user
                  (*cust) += factory.create(make, model, colour, year, milage, sideCar);
                }
            } else {
                view.displayInvalid();
            }
            view.pause();
        } else if (choice == 4) {
            int id;
            view.promptUserId(id);
            Customer* cust = mechanicShop.getCustomer(id);
            if (cust != 0) {
                mechanicShop -= cust;
                delete cust;
            } else {
                view.displayInvalid();
            }
            view.pause();
        } else if (choice == 5) {
            int id;
            view.promptUserId(id);
            Customer* cust = mechanicShop.getCustomer(id);
            if (cust != 0) {
                int choice;
                view.promptVehicle(cust->getNumVehicles(), choice);
				if (choice < 0|| (cust->getNumVehicles()-1) < choice) {
					view.displayInvalid();
				} else {
					Vehicle* v = cust->getVehicles()[choice];
                	cust->getVehicles() -= v;
                	delete v;
				}
            } else {
                view.displayInvalid();
            }
            view.pause();
        } else if (choice == 6) {
            view.printMechanics(mechanicShop.getMechanics());
            view.pause();
        } else {
            break;
        }
    }
}


void ShopController::initShop() {

    Customer* newCustomer;
    Vehicle* newVehicle;
    Mechanic* newMechanic;

    newCustomer = new Customer("Maurice", "Mooney", "2600 Colonel By Dr.",
                                            "(613)728-9568");
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("Ford", "Fiesta", "Red", 2007, 100000);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;


    newCustomer = new Customer("Abigail", "Atwood", "43 Carling Dr.",
                                        "(613)345-6743");
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("Subaru", "Forester", "Green", 2016, 40000);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;


    newCustomer = new Customer("Brook", "Banding", "1 Bayshore Dr.",
                                        "(613)123-7456");
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("Honda", "Accord", "White", 2018, 5000);
    (*newCustomer) += newVehicle;
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("Volkswagon", "Beetle", "White", 1972, 5000);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;


    newCustomer = new Customer("Ethan", "Esser", "245 Rideau St.",
                                        "(613)234-9677");
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("Toyota", "Camery", "Black", 2010, 50000);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;


    newCustomer = new Customer("Eve", "Engram", "75 Bronson Ave.",
                                        "(613)456-2345");
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("Toyota", "Corolla", "Green", 2013, 80000);
    (*newCustomer) += newVehicle;
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("Toyota", "Rav4", "Gold", 2015, 20000);
    (*newCustomer) += newVehicle;
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("Toyota", "Prius", "Blue", 2017, 10000);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;


    newCustomer = new Customer("Victor", "Vanvalkenburg", "425 O'Connor St.",
                                        "(613)432-7622");
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("GM", "Envoy", "Purple", 2012, 60000);
    (*newCustomer) += newVehicle;
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("GM", "Escalade", "Black", 2016, 40000);
    (*newCustomer) += newVehicle;
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("GM", "Malibu", "Red", 2015, 20000);
    (*newCustomer) += newVehicle;
    //when creating a new vehicle, use the factory create functions to create the new instance based off the params
    newVehicle = factory.create("GM", "Trailblazer", "Orange", 2012, 90000);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;

    // create mechanics
    newMechanic = new Mechanic("Bill", "Taylor", "54 Park Place",
                                        "(613)826-9847", 75000);
    mechanicShop += newMechanic;
    newMechanic = new Mechanic("Steve", "Bane", "77 Oak St.",
                                        "(613)223-4653", 60000);
    mechanicShop += newMechanic;
    newMechanic = new Mechanic("Jane", "Smyth", "10 5th Ave.",
                                        "(613)762-4678", 71000);
    mechanicShop += newMechanic;

}
