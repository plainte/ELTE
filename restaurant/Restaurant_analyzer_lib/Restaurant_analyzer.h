//
// Created by molna on 2020. 03. 30..
//

#ifndef RESTAURANT_RESTAURANT_ANALYZER_H
#define RESTAURANT_RESTAURANT_ANALYZER_H

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <optional>
#include <memory>

namespace analytics {

    enum class ErrorCode {
        ERROR_OPENING,
        ERROR_READING,
        ERROR_EMPTY
    };

    struct Order {
        std::string food;
        std::string time; /* ordered at */
        int qty;
        double px;
    };


    class RestaurantAnalyzer {
        using OrderMap = std::map<std::string, Order>;
    public:
        RestaurantAnalyzer(const std::string &filename);
        ~RestaurantAnalyzer();

        virtual void parseData();

        std::optional<std::string> bestProduct();
        std::optional<double> bestProductIncome();
        OrderMap getOrders() const { return orders;}
    private:
        void upsert(const Order& order);

        std::ifstream in;
        std::optional<std::string> bestFood;
        std::optional<double> bestIncome;
        OrderMap orders;
    };

    using RestaurantAnalyzerPtr = std::unique_ptr<RestaurantAnalyzer>;

}


#endif //RESTAURANT_RESTAURANT_ANALYZER_H
