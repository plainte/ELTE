//
// Created by molna on 2020. 05. 06..
//

#include "Bird.h"

bool Bird::takeCareOfMe(Happiness happiness) {
    if (happiness == Happiness::BAD) {
        if (_vim - 3 <= 0) {
            _vim = 0;
            return false;
        }
        _vim -= 3;
    } else if (happiness == Happiness::AVERAGE) {
        if (_vim - 1 <= 0) {
            _vim = 0;
            return false;
        }
        _vim -= 1;
    } else  if (happiness == Happiness::GOOD) {
        _vim += 2;
        if (_vim > 100) {
            _vim = 100;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Bird &bird) {
    os << static_cast<const Pet &>(bird);
    return os;
}
