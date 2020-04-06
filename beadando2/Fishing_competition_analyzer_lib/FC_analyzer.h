//
// Created by molna on 2020. 04. 05..
//

#ifndef FISHING_COMPETITION_ANALYZER_FC_ANALYZER_H
#define FISHING_COMPETITION_ANALYZER_FC_ANALYZER_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>

namespace analytics {

    struct Competitor {
        using fishName = std::string;
        using fish = std::pair<fishName, int>;

        std::string competitorName;
        std::vector<fish> fishVector;
    };

    class FCAnalyzer {
        using Competition = std::string;
        using Competitors = std::vector<Competitor>;
        using Competitions = std::map<Competition, Competitors>;
    public:
        FCAnalyzer(const std::string& filename) { in.open(filename); }
        ~FCAnalyzer() { if (in) { in.close(); } }

        void parseData();

        void whoCaughtTheFish(const std::string& fish);
        void caughtAsBiggestFishOnAnyCompetition(const std::string& fish);
        //for testing purposes
        const std::vector<std::string> whoCaughtTheFishTest(const std::string& fish) const;
        const std::vector<int> caughtAsBiggestFishOnAnyCompetitionTest(const std::string& fish) const;
    private:
        void upsert(const Competition& key, const Competitor& competitor);

        Competitions competitions;
        std::ifstream in;
    };

    using FCAnalyzerPtr = std::unique_ptr<FCAnalyzer>;

}


#endif //FISHING_COMPETITION_ANALYZER_FC_ANALYZER_H
