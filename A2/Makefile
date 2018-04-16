OBJ = main.o ShopController.o View.o Shop.o CustomerArray.o VehicleArray.o Customer.o Vehicle.o

mechanicshop:	$(OBJ)
	g++ -o mechanicshop $(OBJ)

main.o:	main.cc 
	g++ -c main.cc

ShopController.o:	ShopController.cc ShopController.h Shop.h View.h
	g++ -c ShopController.cc

View.o:	View.cc View.h 
	g++ -c View.cc

Shop.o:	Shop.cc Shop.h CustomerArray.h  
	g++ -c Shop.cc

CustomerArray.o: CustomerArray.cc CustomerArray.h Customer.h defs.h
	g++ -c CustomerArray.cc

VehicleArray.o:	VehicleArray.cc VehicleArray.h Vehicle.h defs.h
	g++ -c VehicleArray.cc

Customer.o:	Customer.cc Customer.h 
	g++ -c Customer.cc

Vehicle.o: Vehicle.cc Vehicle.h
	g++ -c Vehicle.cc

clean:
	rm -f $(OBJ) mechanicshop
