//
// Created by molna on 2020. 05. 06..
//

#ifndef BEADANDO3_APP_H
#define BEADANDO3_APP_H

#include "Person.h"
#include <fstream>

class App {
public:
    static int Run();

private:
    App(const std::string &filename) { in.open(filename); }
    ~App() { if(in) { in.close(); } }

    void parseData();
    void createPet(char species, std::string name, int vim);
    void createHappinessLevels(const std::string &happiness);

    void play();

    int _day = 0;
    std::ifstream in;
    PersonPtr person = std::make_unique<Person>("Person");
};


#endif //BEADANDO3_APP_H
