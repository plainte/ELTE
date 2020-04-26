//
// Created by molna on 2020. 04. 26..
//

#ifndef PETROLSTATION_CHARGER_H
#define PETROLSTATION_CHARGER_H

#include <memory>

namespace pStation {

    class Charger {
    public:
        void charge(double container);
        double getQuantity() { return quantityIndicator; }
        void resetQuantity() { quantityIndicator = 0; }
    private:
        double quantityIndicator = 0;
    };

    using ChargerPtr = std::shared_ptr<Charger>;

}


#endif //PETROLSTATION_CHARGER_H
