//
// Created by molna on 2020. 05. 06..
//

#ifndef BEADANDO3_PERSON_H
#define BEADANDO3_PERSON_H

#include "Bird.h"
#include "Fish.h"
#include "Dog.h"
#include <vector>

class Person {
    using PetVector = std::vector<PetPtr>;
    using HappinessVector = std::vector<Happiness>;
public:
    Person(std::string name) : _name(std::move(name)) {}

    //Used for playing
    void simulateDays(int& day);

    //Used for parsing
    void addNewPet(PetPtr petPtr);
    void addHappiness(Happiness happiness);

private:
    Happiness checkHappiness(Happiness dailyHappiness);
    void printDetails(int day, Happiness happiness);
    void printPets();
    void printSaddestPets(int day);
    [[nodiscard]] std::vector<int> getSaddestPets() const;

    HappinessVector _dailyHappiness;
    PetVector _pets;
    std::string _name;
};

using PersonPtr = std::unique_ptr<Person>;

#endif //BEADANDO3_PERSON_H
