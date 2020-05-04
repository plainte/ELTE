//
// Created by molna on 2020. 05. 02..
//

#ifndef HUNTER_LION_H
#define HUNTER_LION_H


#include "WildAnimal.h"

class Lion : public WildAnimal {
public:
    Lion(std::string place, std::string date, double weight, Sex sex)
        : WildAnimal(std::move(place), std::move(date), weight), _sex(sex) { _type = Animals::LION; }
    Sex getSex() override { return _sex; }
private:
    Sex _sex;
};

using LionPtr = std::unique_ptr<Lion>;


#endif //HUNTER_LION_H
