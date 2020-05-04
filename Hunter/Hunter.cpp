//
// Created by molna on 2020. 05. 02..
//

#include "Hunter.h"

int Hunter::howManyMaleLionsGotHunted() {
    int maleLions = 0;
    for (const auto& trophy : _trophies) {
        if (trophy->getAnimalType() == Animals::LION && trophy->getSex() == Sex::MALE) {
            ++maleLions;
        }
    }
    return maleLions;
}

void Hunter::addNewTrophy(WildAnimalPtr animal) {
    animal->getAnimalType();
    _trophies.emplace_back(std::move(animal));
}
