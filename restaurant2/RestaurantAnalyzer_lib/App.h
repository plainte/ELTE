//
// Created by molna on 2020. 04. 06..
//

#ifndef RESTAURANT2_APP_H
#define RESTAURANT2_APP_H

#include "RestaurantAnalyzer.h"

using namespace::analytics;

class App {
public:
    static int Run();

private:
    App(const std::string& filename) : raPtr(std::make_unique<RestaurantAnalyzer>(filename)) {}

    void processData();

    RestaurantAnalyzerPtr raPtr;
};


#endif //RESTAURANT2_APP_H
