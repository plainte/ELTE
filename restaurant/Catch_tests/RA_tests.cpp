//
// Created by molna on 2020. 03. 30..
//

#define CATCH_CONFIG_MAIN
#include "Restaurant_analyzer.h"
#include "catch.hpp"

using namespace analytics;

TEST_CASE("Test input files", "[FileTesting]")
{
    const std::string filename1 = "i.txt";
    const std::string filename2 = "../../input2.txt";
    const std::string filename3 = "../../badformat.txt";
    const std::string filename4 = "../../input.txt";

    SECTION("Testing not existing file") {
        REQUIRE_THROWS(RestaurantAnalyzer(filename1));
    }
    SECTION("Testing existing empty file") {
        REQUIRE_THROWS(RestaurantAnalyzer(filename2));
    }
    SECTION("Testing wrongly formatted file") {
        REQUIRE_THROWS(RestaurantAnalyzer(filename3).parseData());
    }
    SECTION("Testing correct txt file") {
        REQUIRE_NOTHROW(RestaurantAnalyzer(filename4).parseData());
    }
}

TEST_CASE("Test basic logic", "[LogicTesting]")
{
    const std::string filename = "../../input.txt";
    RestaurantAnalyzer ra(filename);

    REQUIRE(ra.bestProductIncome() == std::nullopt);
    REQUIRE(ra.bestProduct() == std::nullopt);

    WHEN( "foods added") {
        ra.parseData();

        THEN("best product calculated") {
            REQUIRE(ra.bestProductIncome().has_value());
            REQUIRE(ra.bestProduct().has_value());
        }
        AND_THEN("check calc") {
            auto bestOrder = ra.getOrders()[ra.bestProduct().value()];
            auto px = bestOrder.px * bestOrder.qty;
            auto food = bestOrder.food;
            REQUIRE(ra.bestProductIncome().value() == px);
            REQUIRE(ra.bestProduct().value() == food);
        }
    }
}

