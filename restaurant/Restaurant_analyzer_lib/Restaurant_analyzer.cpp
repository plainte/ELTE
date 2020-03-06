//
// Created by molna on 2020. 03. 30..
//

#include "Restaurant_analyzer.h"

namespace analytics {

    RestaurantAnalyzer::RestaurantAnalyzer(const std::string &filename) {
        in.open(filename);
        if (!in) {
            throw ErrorCode::ERROR_OPENING;
        } else if ( in.peek() == std::ifstream::traits_type::eof() ) {
            throw ErrorCode::ERROR_EMPTY;
        }
    }

    RestaurantAnalyzer::~RestaurantAnalyzer() {
        if (in) {
            in.close();
        }
    }

    void RestaurantAnalyzer::parseData() {
        std::string line;
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            Order newOrd;
            if (!(iss >> newOrd.food >> newOrd.time >> newOrd.qty >> newOrd.px)) {
                throw ErrorCode::ERROR_READING;
            }
            upsert(newOrd);
        }
    }

    void RestaurantAnalyzer::upsert(const Order &order) {
        auto &key = order.food;
        auto search = orders.find(key);
        if (search != orders.end()) {
            orders[key].qty += order.qty;
        } else {
            orders[key] = order;
            if (!bestIncome) {
                bestIncome = order.qty * order.px;
                bestFood = key;
                return;
            }
        }
        auto weightedPx = orders[key].qty * orders[key].px;
        if (bestIncome < weightedPx) {
            bestIncome = weightedPx;
            bestFood = key;
        }
    }

    std::optional<std::string> RestaurantAnalyzer::bestProduct() {
        if (!bestFood) {
            return std::nullopt;
        }
        return bestFood;
    }

    std::optional<double> RestaurantAnalyzer::bestProductIncome() {
        if (!bestIncome) {
            return std::nullopt;
        }
        return bestIncome;
    }

}