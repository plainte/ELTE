//
// Created by molna on 2020. 05. 06..
//

#include "Person.h"
#include <iostream>

void Person::printPets()
{
    for (const auto &pet : _pets) {
        std::cout << *pet << std::endl;
    }
}

Happiness Person::checkHappiness(Happiness dailyHappiness)
{
    if (dailyHappiness != Happiness::GOOD) {
        auto increaseHappiness = true;
        for (const auto &pet : _pets) {
            if (pet->getVim() < 5) {
                increaseHappiness = false;
                break;
            }
        }
        if (increaseHappiness) {
            dailyHappiness = static_cast<Happiness>(static_cast<int>(dailyHappiness) + 1);
        }
    }
    return dailyHappiness;
}

void Person::addHappiness(Happiness happiness)
{
    _dailyHappiness.emplace_back(happiness);
}

void Person::addNewPet(PetPtr petPtr)
{
    _pets.emplace_back(std::move(petPtr));
}

std::ostream& operator<<(std::ostream& os, const Happiness& other)
{
    switch (other){
        case Happiness::BAD:
            os << "Bad";
            break;
        case Happiness::AVERAGE:
            os << "Average";
            break;
        case Happiness::GOOD:
            os << "Good";
            break;
        default:
            break;
    }
    return os;
}

void Person::simulateDays(int& day)
{
    for (const auto &currentHappiness : _dailyHappiness) {
        auto happiness = checkHappiness(currentHappiness);
        for (auto it = _pets.begin(); it != _pets.end();) {
            if (!it->get()->takeCareOfMe(happiness)) {
                it = _pets.erase(it);
            } else {
                ++it;
            }
        }
        printDetails(++day, happiness);
    }
    printSaddestPets(day);
}

void Person::printDetails(int day, Happiness happiness)
{
    std::cout << "Day " << day  << ": " << _name << "'s mood => " << happiness << " - total pets: " <<  _pets.size() << std::endl;
    printPets();
}

void Person::printSaddestPets(int day)
{
    std::vector<int> saddestPetsIndices = getSaddestPets();
    std::cout << "Saddest pets after day " << day << ":" << std::endl;
    for (const auto &i : saddestPetsIndices) {
        std::cout << " - Pet name: " << _pets[i]->getName() << " vim: " << _pets[i]->getVim() << std::endl;
    }
}

std::vector<int> Person::getSaddestPets() const
{
    std::vector<int> indices;
    auto min = 100;
    for (size_t i = 0; i < _pets.size(); ++i) {
        if (_pets[i]->getVim() <= min) {
            if (_pets[i]->getVim() != min) {
                min = _pets[i]->getVim();
                if (!indices.empty()) {
                    indices.clear();
                }
            }
            indices.emplace_back(i);
        }
    }
    return indices;
}



