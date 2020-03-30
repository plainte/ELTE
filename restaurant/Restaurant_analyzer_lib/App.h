//
// Created by molna on 2020. 03. 30..
//

#ifndef RESTAURANT_APP_H
#define RESTAURANT_APP_H

#include "Restaurant_analyzer.h"
#include <iostream>

using namespace::analytics;

class App {
public:
    static int Run();

private:
    App(const std::string& filename) : restaurantAnalyzerPtr(std::make_unique<RestaurantAnalyzer>(filename)) {}

    void collectData();

    RestaurantAnalyzerPtr restaurantAnalyzerPtr;
};


#endif //RESTAURANT_APP_H
