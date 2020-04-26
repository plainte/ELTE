//
// Created by molna on 2020. 04. 26..
//

#ifndef PETROLSTATION_PAYDESK_H
#define PETROLSTATION_PAYDESK_H

#include <memory>
#include "Charger.h"

namespace pStation {

    class PayDesk {
    public:
        void pay(ChargerPtr charger, double px);
    };

    using PayDeskPtr = std::shared_ptr<PayDesk>;

}


#endif //PETROLSTATION_PAYDESK_H
