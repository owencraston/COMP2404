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
        }
        else {
            break;
        }
    }
}


void ShopController::initCustomers() {
    //Create customers
    Customer* customer_1 = new Customer("Owen", "Craston", "12 Brookdale ave", "613 407 5354");
    Vehicle* vehicle_1 = new Vehicle("Honda", "Pilot", "Blue", 2004, 250000);
    customer_1 -> addVehicle(vehicle_1);
    mechanicShop.addCustomer(customer_1);

    Customer* customer_2 = new Customer("Hugh", "Xie", "12 applebye pvt", "613 777 1111");
    Vehicle* vehicle_2 = new Vehicle("OC transpo bus", "OC", "Red/white", 2004, 250000);
    customer_2 -> addVehicle(vehicle_2);
    mechanicShop.addCustomer(customer_2);

    Customer* customer_3 = new Customer("Connor", "O'rielly", "1 belldune st", "613 334 4655");
    Vehicle* vehicle_3 = new Vehicle("Dodge", "Dakota", "Black", 2015, 10000);
    customer_3 -> addVehicle(vehicle_3);
    mechanicShop.addCustomer(customer_3);

    Customer* customer_4 = new Customer("Lisa", "Meyer", "12 Oslo airport", "123 456 7890");
    Vehicle* vehicle_4 = new Vehicle("Nissan", "GTR", "Red", 2020, 1);
    Vehicle* vehicle_5 = new Vehicle("BMW", "M5", "red", 2019, 10000);
    customer_4 -> addVehicle(vehicle_4);
    customer_4 -> addVehicle(vehicle_5);
    mechanicShop.addCustomer(customer_4);

    Customer* customer_5 = new Customer("bob", "burger", "3 sussux drive", "123 689 87546");
    Vehicle* vehicle_6 = new Vehicle("Honda", "Civic", "Blue", 1999, 298989);
    Vehicle* vehicle_7 = new Vehicle("BMW", "i3", "black", 22, 1500);
    Vehicle* vehicle_8 = new Vehicle("Volkswagen", "beetle", "Blue", 2005, 1203456);
    customer_5 -> addVehicle(vehicle_6);
    customer_5 -> addVehicle(vehicle_7);
    customer_5 -> addVehicle(vehicle_8);
    mechanicShop.addCustomer(customer_5);

    Customer* customer_6 = new Customer("HUGH", "Xie", "1 street ave", "613 737 1111");
    Vehicle* vehicle_9 = new Vehicle("Toyota", "Camry", "Blue", 2006, 100);
    Vehicle* vehicle_10 = new Vehicle("Toyota", "Corrola", "Blue", 2000, 10000);
    Vehicle* vehicle_11 = new Vehicle("Volkswagen", "golf", "silver", 2010, 909090);
    Vehicle* vehicle_12 = new Vehicle("Lambo", "mercy", "uknonw", 2018, 1);
    customer_6 -> addVehicle(vehicle_9);
    customer_6 -> addVehicle(vehicle_10);
    customer_6 -> addVehicle(vehicle_11);
    customer_6 -> addVehicle(vehicle_12);
    mechanicShop.addCustomer(customer_6);
}
