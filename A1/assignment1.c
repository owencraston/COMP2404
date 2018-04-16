#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_STR 32
#define MAX_VEHICLES 4
#define MAX_CUSTOMERS 6

typedef struct {
// member variables
	char make[MAX_STR];
	char model[MAX_STR];
	char colour[MAX_STR];
	int year;
	int mileage;
} VehicleType;

typedef struct {
// member variables
	char first_name[MAX_STR];
	char last_name[MAX_STR];
	int num_vehicles;
	VehicleType individual_vehicles[MAX_VEHICLES];
} CustomerType;

void print_vehicle(VehicleType *v) {
    //print all the attributes of v
    printf("Make: %s, Model: %s, Colour: %s, Year: %d, Mileage: %dKM\n",v->make, v->model, v->colour, v->year, v->mileage);
}

void print_customer(CustomerType *c) {
    printf("\n\nName: %s %s | Number of Registered Vehicles: %d\n", c->first_name, c->last_name, c->num_vehicles);
    // print the vehicle information
	for(int i=0; i < c->num_vehicles; i++){
		print_vehicle(&c->individual_vehicles[i]);
	}
}

int add_vehicle(CustomerType *customer, VehicleType *vehicle) {
	// 
    if (customer->num_vehicles < MAX_VEHICLES) {
		//add the vehicle
        customer->individual_vehicles[customer->num_vehicles] = *vehicle;
		//increment the number of vehicles
        customer->num_vehicles++;
		//return 0 for success
        return 0;
	}
	printf("You have reached the maximum number of vehicles\n");
    //return -1 if not valid
	return -1;
}

CustomerType create_customer(char* fname, char* lname) {
    // allocate memory
    CustomerType *customer = (CustomerType*)malloc(sizeof(CustomerType));
	// copy the data into the customer
    strncpy(customer->first_name, fname, MAX_STR-1);
	strncpy(customer->last_name, lname, MAX_STR-1);
    // set number of registered vehicles to 0
	customer->num_vehicles = 0;
    // return the newly created customer
	return *customer;
}

VehicleType create_vehicle(char* make, char* model, char* colour, int year, int mileage) {
    // allocare memory
	VehicleType *vehicle = (VehicleType*)malloc(sizeof(VehicleType));
	// copy data into vehicle
    strncpy(vehicle->make, make, MAX_STR-1);
	strncpy(vehicle->model, model, MAX_STR-1);
	strncpy(vehicle->colour, colour, MAX_STR-1);
    //set year and milage values
	vehicle->year = year;
	vehicle->mileage = mileage;
    // return the newly created vehcle
	return *vehicle;
}


int main() {

    CustomerType customers[MAX_CUSTOMERS];
    
    customers[0] = create_customer("Jim","Bean");
    customers[1] = create_customer("Jack","Daniels");
    customers[2] = create_customer("Owen","Craston");
    customers[3] = create_customer("Jonhy","Walker");
    customers[4] = create_customer("Sailor","Jerry");
    customers[5] = create_customer("Arthur", "Guinness");

    VehicleType owen_car = create_vehicle("Nissan", "GTR", "Black", 2018, 2);

    for(int i=0; i < MAX_CUSTOMERS; i++) {
        for(int j=0; j<=i && j <= 4; j++) {
          add_vehicle(&customers[i], &owen_car);
        }
    }

    for(int i=0; i < MAX_CUSTOMERS; i++){
    	print_customer(&customers[i]);
    }

    return 0;
}


