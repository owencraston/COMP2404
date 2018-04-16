#include "ShopController.h"

ShopController::ShopController() {

    initCustomers();

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
            // add new customer
            addCustomer();
            view.pause();
        } else if (choice == 3) {
            addVehicle();
            view.pause();
        }
        else {
            break;
        }
    }
}


void ShopController::initCustomers() {

    Customer* newCustomer;
    Vehicle* newVehicle;

    newCustomer = new Customer("Maurice", "Mooney", "2600 Colonel By Dr.", 
                                        "(613)728-9568");
    newVehicle = new Vehicle("Ford", "Fiesta", "Red", 2007, 100000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);

    
    newCustomer = new Customer("Abigail", "Atwood", "43 Carling Dr.", 
                                        "(613)345-6743");
    newVehicle = new Vehicle("Subaru", "Forester", "Green", 2016, 40000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);


    newCustomer = new Customer("Brook", "Banding", "1 Bayshore Dr.", 
                                        "(613)123-7456");
    newVehicle = new Vehicle("Honda", "Accord", "White", 2018, 5000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("Volkswagon", "Beetle", "White", 1972, 5000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);


    newCustomer = new Customer("Ethan", "Esser", "245 Rideau St.", 
                                        "(613)234-9677");
    newVehicle = new Vehicle("Toyota", "Camery", "Black", 2010, 50000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);
    

    newCustomer = new Customer("Eve", "Engram", "75 Bronson Ave.", 
                                        "(613)456-2345");
    newVehicle = new Vehicle("Toyota", "Corolla", "Green", 2013, 80000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("Toyota", "Rav4", "Gold", 2015, 20000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("Toyota", "Prius", "Blue", 2017, 10000);
    newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);

    
    newCustomer = new Customer("Victor", "Vanvalkenburg", "425 O'Connor St.", 
                                        "(613)432-7622");
    newVehicle = new Vehicle("GM", "Envoy", "Purple", 2012, 60000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("GM", "Escalade", "Black", 2016, 40000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("GM", "Malibu", "Red", 2015, 20000);
    newCustomer->addVehicle(newVehicle);
    newVehicle = new Vehicle("GM", "Trailblazer", "Orange", 2012, 90000);
    newCustomer->addVehicle(newVehicle);
    //newVehicle = new Vehicle("GM", "Vue", "Blue", 2015, 20000);
    //newCustomer->addVehicle(newVehicle);
    mechanicShop.addCustomer(newCustomer);

}

// add new customer
void ShopController::addCustomer() {

    //create a new customer
    Customer* newCustomer;
    string fname, lname, add, pnumber;
    //call the view functions
    view.readNewCustomer(fname, lname, add, pnumber);

    //create and add the new customer
    newCustomer = new Customer(fname, lname, add, pnumber);
    mechanicShop.addCustomer(newCustomer);

}

//add new vehicle
void ShopController::addVehicle() {
    int id;
    Customer* customer;

    //try to get a valid id
    view.readID(id);

    //get the corresponding customer
    customer = mechanicShop.getCustomer(id);

    //check if the customer is null
    if (customer == 0) {
        //print error to user
        view.printInvalidID();
    } else { // valid
        // create new vehicle
        Vehicle* newVehicle;
        string mk, mdl, clr;
        int yr, mil;
        // get values form input
        view.readNewVehicle(mk, mdl, clr, yr, mil);
        // create new vehicle object with newVehicle
        newVehicle = new Vehicle(mk, mdl, clr, yr, mil);
        //add vehicle to customer
        customer -> addVehicle(newVehicle);
    }

}
