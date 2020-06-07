//
// Created by molna on 2020. 05. 06..
//

#ifndef BEADANDO3_DOG_H
#define BEADANDO3_DOG_H

#include <ostream>
#include "Pet.h"

class Dog : public Pet{
public:
    Dog(std::string name, int vim) : Pet(std::move(name), vim) {}

    friend std::ostream &operator<<(std::ostream &os, const Dog &dog);

    bool takeCareOfMe(Happiness happiness) override;
};

using DogPtr = std::unique_ptr<Dog>;


#endif //BEADANDO3_DOG_H
