//
// Created by molna on 2020. 04. 26..
//

#include "Customer.h"
#include <iostream>

namespace pStation {

    void Customer::refill(int nr, PetrolStationPtr petrolStation) {
        auto& charger = petrolStation->getChargers()[nr];
        if (current == container) {
            std::cout << "Sorry, your tank is full!" << std::endl;
            return;
        }
        charger->charge(container-current);
        petrolStation->getPayDesk()->pay(charger, petrolStation->getPrice());
    }

}
