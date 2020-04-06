//
// Created by molna on 2020. 04. 06..
//

#include "RestaurantAnalyzer.h"
#include <sstream>

namespace analytics {


    void RestaurantAnalyzer::parseData() {
        std::string line;
        while (std::getline(in, line)) {
            std::istringstream iss(line);
            auto recipe = std::make_unique<Recipe>();
            auto found = line.find(":");
            if (found != std::string::npos) {
                std::string maybeName;
                iss >> maybeName;
                recipe->name = getRecipeName(maybeName);
            } else {
                iss >> recipe->name;
            }

            std::string name;
            int qty;
            std::string unit;
            while (iss >> name >> qty >> unit) {
                auto ingrdnt = std::make_unique<Ingredient>(name, qty, unit);
                recipe->ingredients.push_back(std::move(ingrdnt));
            }
            meals.push_back(std::make_pair(std::move(recipe), recipe->ingredients.size()));
        }
    }

    WorstRecipes RestaurantAnalyzer::hasMostIngredients() const noexcept {

        auto max = 0;
        WorstRecipes result;
        for (const auto &meal : meals) {
            if (meal.second >= max) {
                if (meal.second > max) {
                    result.clear();
                    max = meal.second;
                }
                result.push_back(std::make_pair(meal.first->name, meal.second));
            }
        }
        return result;
    }

    std::string RestaurantAnalyzer::getRecipeName(std::string line) const {
        std::string rName;
        std::string delimiter = ":";
        auto pos = line.find(delimiter);
        std::string token = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        return std::string(token + " " + line);
    }

}
