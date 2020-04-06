//
// Created by molna on 2020. 04. 05..
//

#include "App.h"


void App::processData() {
    fcaPtr->parseData();
    fcaPtr->whoCaughtTheFish("Keszeg");
    fcaPtr->caughtAsBiggestFishOnAnyCompetition("Keszeg");
}

int App::Run() {
    const std::string filename = "../input.txt";
    App app(filename);
    app.processData();
    return 0;
}

