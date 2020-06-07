//
// Created by molna on 2020. 05. 06..
//

#ifndef BEADANDO3_PET_H
#define BEADANDO3_PET_H

#include <string>
#include <memory>
#include <ostream>

enum class Happiness {
    BAD,
    AVERAGE,
    GOOD
};

class Pet {
public:
    Pet(std::string name, int vim) : _name(std::move(name)), _vim(vim) {}

    virtual bool takeCareOfMe(Happiness happiness) = 0;

    friend std::ostream &operator<<(std::ostream &os, const Pet &pet) {
        os << " - Pet name: " << pet._name << " vim: " << pet._vim;
        return os;
    }

    [[nodiscard]] int getVim() const { return _vim; }
    [[nodiscard]] const std::string &getName() const { return _name; }
protected:
    std::string _name;
    int _vim;
};

using PetPtr = std::unique_ptr<Pet>;


#endif //BEADANDO3_PET_H
