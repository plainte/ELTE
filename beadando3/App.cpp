//
// Created by molna on 2020. 05. 06..
//

#include "App.h"
#include <sstream>
#include <iostream>



int App::Run() {
    const std::string filename = "../test.txt";
    App app(filename);
    app.parseData();
    app.play();

    return 0;
}

void App::parseData() {
    std::string line;
    int counter = 0;
    std::string happiness;
    std::getline(in, line);
    std::istringstream iss(line);
    iss >> counter;
    //parse content line by line
    while(std::getline(in, line)) {
        iss = std::istringstream(line);
        if (counter-- > 0) {
            char species;
            std::string name;
            int vim = 0;
            iss >> species >> name >> vim;
            createPet(species, name, vim);
        } else {
            iss >> happiness;
            createHappinessLevels(happiness);
        }
    }
}

void App::createPet(char species, std::string name, int vim) {
    if (species == 'H') {
        auto newPet = std::make_unique<Fish>(std::move(name), vim);
        person->addNewPet(std::move(newPet));
    } else if (species == 'M') {
        auto newPet = std::make_unique<Bird>(std::move(name), vim);
        person->addNewPet(std::move(newPet));
    } else {
        auto newPet = std::make_unique<Dog>(std::move(name), vim);
        person->addNewPet(std::move(newPet));
    }
}

void App::createHappinessLevels(const std::string &happiness) {
    for (const auto &daily : happiness) {
        switch(daily) {
            case 'j':
                person->addHappiness(Happiness::GOOD);
                break;
            case 'a':
                person->addHappiness(Happiness::AVERAGE);
                break;
            case 'r':
                person->addHappiness(Happiness::BAD);
                break;
            default:
                std::cout << "undefined happiness level: " << daily << std::endl;
        }
    }
}

void App::play() {
    person->simulateDays(_day);
}
