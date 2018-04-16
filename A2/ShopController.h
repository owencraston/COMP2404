#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include "View.h"
#include "Shop.h"

class ShopController {

    public:
        ShopController();
        void launch();
    private:
        Shop mechanicShop;
        View view;
        void initCustomers();
};

#endif
