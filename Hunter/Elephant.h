//
// Created by molna on 2020. 05. 02..
//

#ifndef HUNTER_ELEPHANT_H
#define HUNTER_ELEPHANT_H

#include <utility>

#include "WildAnimal.h"

class Elephant : public WildAnimal {
public:
    Elephant(std::string place, std::string date, double weight, std::pair<double, double>  tusks)
            : WildAnimal(std::move(place), std::move(date), weight), _tusks(std::move(tusks)) { _type = Animals::ELEPHANT; }
private:
    std::pair<double, double> _tusks;

};

using ElephantPtr = std::unique_ptr<Elephant>;


#endif //HUNTER_ELEPHANT_H
