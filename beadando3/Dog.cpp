//
// Created by molna on 2020. 05. 06..
//

#include "Dog.h"

bool Dog::takeCareOfMe(Happiness happiness) {
    if (happiness == Happiness::BAD) {
        if (_vim - 10 <= 0) {
            _vim = 0;
            return false;
        }
        _vim -= 10;
    } else {
        _vim += 3;
        if (_vim > 100) {
            _vim = 100;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Dog &dog) {
    os << static_cast<const Pet &>(dog);
    return os;
}
