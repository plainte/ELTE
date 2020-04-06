//
// Created by molna on 2020. 04. 05..
//

#ifndef FISHING_COMPETITION_ANALYZER_APP_H
#define FISHING_COMPETITION_ANALYZER_APP_H

#include "FC_analyzer.h"

using namespace::analytics;

class App {
public:
    static int Run();

    void processData();

private:
    App(const std::string& filename) : fcaPtr(std::make_unique<FCAnalyzer>(filename)) {}

    FCAnalyzerPtr fcaPtr;
};


#endif //FISHING_COMPETITION_ANALYZER_APP_H
