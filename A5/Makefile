OBJ = main.o ShopController.o View.o Shop.o Customer.o Vehicle.o Mechanic.o Person.o Car.o Truck.o Motorcycle.o VehicleFactory.o

mechanicshop:	$(OBJ)
	g++ -o mechanicshop $(OBJ)

main.o:	main.cc
	g++ -c main.cc

ShopController.o:	ShopController.cc ShopController.h Shop.h View.h VehicleFactory.h
	g++ -c ShopController.cc

View.o:	View.cc View.h
	g++ -c View.cc

VehicleFactory.o: VehicleFactory.cc VehicleFactory.h Car.h Truck.h Motorcycle.h
	g++ -c VehicleFactory.cc

Shop.o:	Shop.cc Shop.h LinkedList.h Mechanic.h
	g++ -c Shop.cc

Customer.o:	Customer.cc Customer.h LinkedList.h Vehicle.h
	g++ -c Customer.cc

Car.o: Car.cc Car.h Vehicle.h
	g++ -c Car.cc

Motorcycle.o: Motorcycle.cc Motorcycle.h Vehicle.h
	g++ -c Motorcycle.cc

Truck.o: Truck.cc Truck.h Vehicle.h
	g++ -c Truck.cc

Vehicle.o: Vehicle.cc Vehicle.h
	g++ -c Vehicle.cc

Mechanic.o: Mechanic.cc Mechanic.h Person.h
	g++ -c Mechanic.cc

Person.o: Person.h Person.cc
	g++ -c Person.cc

clean:
	rm -f $(OBJ) mechanicshop
