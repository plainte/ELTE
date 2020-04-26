//
// Created by molna on 2020. 04. 26..
//

#ifndef PETROLSTATION_PETROLSTATION_H
#define PETROLSTATION_PETROLSTATION_H

#include "Charger.h"
#include "PayDesk.h"

constexpr int MAX_CHARGERS = 6;

namespace pStation {

    class PetrolStation {
        using Chargers = std::array<ChargerPtr, MAX_CHARGERS>;
    public:
        PetrolStation(double px);

        Chargers& getChargers() { return chargers; }

        PayDeskPtr& getPayDesk() { return payDesk; }

        double getPrice() const { return unitPrice; }

    private:
        Chargers chargers;
        PayDeskPtr payDesk;

        double unitPrice;

    };

    using PetrolStationPtr = std::shared_ptr<PetrolStation>;

}

#endif //PETROLSTATION_PETROLSTATION_H
