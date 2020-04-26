#include <iostream>
#include "PetrolStation.h"
#include "Customer.h"


int main() {
    pStation::PetrolStationPtr ptr = std::make_shared<pStation::PetrolStation>(1.5);
    pStation::CustomerPtr customer0 = std::make_shared<pStation::Customer>(23.5, 11.4);
    pStation::CustomerPtr customer1 = std::make_shared<pStation::Customer>(23.5, 0.1);
    pStation::CustomerPtr customer2 = std::make_shared<pStation::Customer>(23.5, 23.5);

    customer0->refill(3, ptr);
    customer1->refill(3, ptr);
    customer2->refill(3, ptr);

    return 0;
}
