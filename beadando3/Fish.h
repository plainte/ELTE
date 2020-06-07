//
// Created by molna on 2020. 05. 06..
//

#ifndef BEADANDO3_FISH_H
#define BEADANDO3_FISH_H

#include <ostream>
#include "Pet.h"

class Fish : public Pet {
public:
    Fish(std::string name, int vim) : Pet(std::move(name), vim) {}

    friend std::ostream &operator<<(std::ostream &os, const Fish &fish);

    bool takeCareOfMe(Happiness happiness) override;
};

using FishPtr = std::unique_ptr<Fish>;


#endif //BEADANDO3_FISH_H
