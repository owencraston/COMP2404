OBJ = main.o ShopController.o View.o Shop.o CustomerList.o VehicleList.o Customer.o Vehicle.o

mechanicshop:	$(OBJ)
	g++ -o mechanicshop $(OBJ)

main.o:	main.cc 
	g++ -c main.cc

ShopController.o:	ShopController.cc ShopController.h Shop.h View.h
	g++ -c ShopController.cc

View.o:	View.cc View.h 
	g++ -c View.cc

Shop.o:	Shop.cc Shop.h CustomerList.h  
	g++ -c Shop.cc

CustomerList.o: CustomerList.cc CustomerList.h Customer.h defs.h
	g++ -c CustomerList.cc

VehicleList.o:	VehicleList.cc VehicleList.h Vehicle.h defs.h
	g++ -c VehicleList.cc

Customer.o:	Customer.cc Customer.h 
	g++ -c Customer.cc

Vehicle.o: Vehicle.cc Vehicle.h
	g++ -c Vehicle.cc

clean:
	rm -f $(OBJ) mechanicshop
