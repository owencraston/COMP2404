#ifndef VIEW_H
#define VIEW_H

#include "CustomerArray.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(CustomerArray&);
        void pause();

    private:
        int readInt();
};

#endif
