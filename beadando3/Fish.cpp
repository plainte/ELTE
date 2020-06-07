//
// Created by molna on 2020. 05. 06..
//

#include "Fish.h"

bool Fish::takeCareOfMe(Happiness happiness) {
    if (happiness == Happiness::BAD) {
        if (_vim - 5 <= 0) {
            _vim = 0;
            return false;
        }
        _vim -= 5;
    } else if (happiness == Happiness::AVERAGE) {
        if (_vim - 3 <= 0) {
            _vim = 0;
            return false;
        }
        _vim -= 3;
    } else  if (happiness == Happiness::GOOD) {
        _vim += 1;
        if (_vim > 100) {
            _vim = 100;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Fish &fish) {
    os << static_cast<const Pet &>(fish);
    return os;
}
