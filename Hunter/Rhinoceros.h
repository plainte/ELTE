//
// Created by molna on 2020. 05. 02..
//

#ifndef HUNTER_RHINOCEROS_H
#define HUNTER_RHINOCEROS_H

#include "WildAnimal.h"
class Rhinoceros : public WildAnimal {
public:
    Rhinoceros(std::string place, std::string date, double weight, double rhino)
            : WildAnimal(std::move(place), std::move(date), weight), _rhino(rhino) { _type = Animals::RHINOCEROS; }
private:
    double _rhino;

};

using RhinocerosPtr = std::unique_ptr<Rhinoceros>;


#endif //HUNTER_RHINOCEROS_H
