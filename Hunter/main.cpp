#include <iostream>
#include "Lion.h"
#include "Rhinoceros.h"
#include "Elephant.h"
#include "Hunter.h"

int main() {
    LionPtr l = std::make_unique<Lion>("a", "b", 50, Sex::MALE);
    LionPtr l2 = std::make_unique<Lion>("ee", "dd", 40.2, Sex::MALE);
    RhinocerosPtr r = std::make_unique<Rhinoceros>("aa", "ee", 40.2, 6.2);
    ElephantPtr e = std::make_unique<Elephant>("dd", "bb", 31.9, std::make_pair(67.2, 65.1));

    HunterPtr h = std::make_unique<Hunter>("hunter", 99);

    h->addNewTrophy(std::move(l));
    h->addNewTrophy(std::move(l2));
    h->addNewTrophy(std::move(r));
    h->addNewTrophy(std::move(e));

    std::cout << "The hunter shot " << h->howManyMaleLionsGotHunted() << " male lions" << std::endl;


    return 0;
}
