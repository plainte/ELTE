//
// Created by molna on 2020. 05. 06..
//

#ifndef BEADANDO3_BIRD_H
#define BEADANDO3_BIRD_H

#include <ostream>
#include "Pet.h"

class Bird : public Pet {
public:
    Bird(std::string name, int vim) : Pet(std::move(name), vim) {}

    friend std::ostream &operator<<(std::ostream &os, const Bird &bird);

    bool takeCareOfMe(Happiness happiness) override;
};

using BirdPtr = std::unique_ptr<Bird>;


#endif //BEADANDO3_BIRD_H
