//
// Created by molna on 2020. 05. 02..
//

#ifndef HUNTER_WILDANIMAL_H
#define HUNTER_WILDANIMAL_H

#include <string>
#include <utility>
#include <memory>

enum class Animals {
    ANIMAL,
    LION,
    ELEPHANT,
    RHINOCEROS
};

enum class Sex {
    UNDEFINED,
    MALE,
    FEMALE
};

class WildAnimal {
public:
    WildAnimal(std::string place, std::string date, double weight) :
            _place(std::move(place)), _date(std::move(date)), _weight(weight) { _type = Animals::ANIMAL; }

    virtual Animals getAnimalType() const { return _type; }
    virtual Sex getSex() { return Sex::UNDEFINED; }
protected:
    Animals _type;
    std::string _place;
    std::string _date;
    double _weight;

};

using WildAnimalPtr = std::unique_ptr<WildAnimal>;


#endif //HUNTER_WILDANIMAL_H
