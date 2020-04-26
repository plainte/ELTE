//
// Created by molna on 2020. 04. 26..
//

#include "PayDesk.h"
#include <iostream>

namespace pStation {

    void PayDesk::pay(ChargerPtr charger, double px) {
        std::cout << "Customer pay: " << (charger->getQuantity() * px) << std::endl;
        charger->resetQuantity();
    }

}