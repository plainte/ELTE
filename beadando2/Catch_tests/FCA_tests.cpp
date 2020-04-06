//
// Created by molna on 2020. 04. 05..
//


#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "FC_analyzer.h"

using namespace::analytics;

using Competition = std::string;
using Competitors = std::vector<Competitor>;
using Competitions = std::map<Competition, Competitors>;

TEST_CASE("Test functionality", "[Functionality]")
{
    const std::string filename = "../../input.txt";
    const std::string filename2 = "../../input2.txt";

    SECTION("Test data structure") {
        const std::string competition0 = "Kiliti0512";
        const std::string competition1 = "Siofok0505";
        const std::string competitor0 = "PETER";
        const std::string competitor1 = "HARRY";
        FCAnalyzer fca(filename);
        fca.parseData();

        auto vec = fca.whoCaughtTheFishTest("Keszeg");

        REQUIRE_THAT(vec[0], Catch::Contains(competitor0));
        REQUIRE_THAT(vec[1], Catch::Contains(competitor1));

        auto vecFish = fca.caughtAsBiggestFishOnAnyCompetitionTest("Keszeg");
        REQUIRE(vecFish[0] == 100);
    }
    SECTION("Keszeg is not the biggest fish") {
        FCAnalyzer fca(filename2);
        fca.parseData();

        auto vecFish = fca.caughtAsBiggestFishOnAnyCompetitionTest("Keszeg");
        REQUIRE(vecFish.empty());
    }
}