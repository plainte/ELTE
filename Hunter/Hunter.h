//
// Created by molna on 2020. 05. 02..
//

#ifndef HUNTER_HUNTER_H
#define HUNTER_HUNTER_H

#include "Lion.h"
#include "Elephant.h"
#include "Rhinoceros.h"
#include <utility>
#include <vector>
#include <string>

class Hunter {
public:
    Hunter(std::string name, int age) : _name(std::move(name)), _age(age) {}

    void addNewTrophy(WildAnimalPtr animal);

    int howManyMaleLionsGotHunted();

private:
    std::vector<WildAnimalPtr> _trophies;
    std::string _name;
    int _age;

};

using HunterPtr = std::unique_ptr<Hunter>;



#endif //HUNTER_HUNTER_H
