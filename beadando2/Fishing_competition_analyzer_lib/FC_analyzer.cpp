//
// Created by molna on 2020. 04. 05..
//

#include <algorithm>
#include "FC_analyzer.h"
#include <iostream>

namespace analytics {

    void FCAnalyzer::parseData() {
        std::string line;
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            Competition competition;
            Competitor competitor;
            iss >> competitor.competitorName >> competition;
            std::pair<std::string, int> fish;
            while (iss >> fish.first >> fish.second) {
                competitor.fishVector.push_back(fish);
            }
            upsert(competition, competitor);
        }
    }

    void FCAnalyzer::upsert(const Competition& key, const Competitor& competitor) {
        competitions[key].push_back(competitor);
    }

    void FCAnalyzer::whoCaughtTheFish(const std::string &fish) {
        std::cout << "People who caught : " << fish << std::endl;
        auto someoneCaught = false;
        for (const auto& competition : competitions) {
            for (const auto& competitor : competition.second) {
                for (const auto& fishes : competitor.fishVector) {
                    if (fishes.first == fish) {
                        if (!someoneCaught) {
                            someoneCaught = true;
                        }
                        std::cout << " - " << competitor.competitorName << "@" << competition.first << std::endl;
                    }
                }
            }
        }
        if (!someoneCaught) {
            std::cout << "no one" << std::endl;
        }
    }

    void FCAnalyzer::caughtAsBiggestFishOnAnyCompetition(const std::string &fish) {
        std::cout << "Competitions where " << fish << " was the biggest result: " << std::endl;
        auto wasBiggest = false;
        for (const auto& competition : competitions) {
            std::pair<std::string, int> biggest;
            for (const auto& competitor : competition.second) {
                for (const auto& fishes : competitor.fishVector) {
                    if (fishes.second > biggest.second) {
                        biggest.first = fishes.first;
                        biggest.second = fishes.second;
                    }
                }
            }
            if (biggest.first == fish) {
                if (!wasBiggest) {
                    wasBiggest = true;
                }
                std::cout << " - caught@" << competition.first <<  " weight: " << biggest.second << std::endl;
            }
        }
        if (!wasBiggest) {
            std::cout << " - none" << std::endl;
        }
    }

    const std::vector<std::string> FCAnalyzer::whoCaughtTheFishTest(const std::string &fish) const {
        std::vector<std::string> test;
        for (const auto& competition : competitions) {
            for (const auto& competitor : competition.second) {
                for (const auto& fishes : competitor.fishVector) {
                    if (fishes.first == fish) {
                        test.push_back(competitor.competitorName);
                    }
                }
            }
        }
        return test;
    }

    const std::vector<int> FCAnalyzer::caughtAsBiggestFishOnAnyCompetitionTest(const std::string &fish) const {
        std::vector<int> test;
        for (const auto& competition : competitions) {
            std::pair<std::string, int> biggest;
            for (const auto& competitor : competition.second) {
                for (const auto& fishes : competitor.fishVector) {
                    if (fishes.second > biggest.second) {
                        biggest.first = fishes.first;
                        biggest.second = fishes.second;
                    }
                }
            }
            if (biggest.first == fish) {
                test.push_back(biggest.second);
            }
        }
        return test;
    }


}
