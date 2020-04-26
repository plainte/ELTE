//
// Created by molna on 2020. 04. 26..
//

#ifndef PETROLSTATION_CUSTOMER_H
#define PETROLSTATION_CUSTOMER_H

#include "PetrolStation.h"

namespace pStation {

    class Customer {
    public:
        Customer(double c, double curr) : container(c), current(curr) {}
        void refill(int nr, PetrolStationPtr petrolStation);

    private:
        double container;
        double current;
    };

    using CustomerPtr = std::shared_ptr<Customer>;

}


#endif //PETROLSTATION_CUSTOMER_H
