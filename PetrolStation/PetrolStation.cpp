//
// Created by molna on 2020. 04. 26..
//

#include "PetrolStation.h"

pStation::PetrolStation::PetrolStation(double px) {
    for (auto& charger : chargers) {
        charger = std::make_shared<Charger>();
    }
    payDesk = std::make_shared<PayDesk>();
    unitPrice = px;
}
