//
// Created by molna on 2020. 04. 06..
//

#ifndef RESTAURANT2_RESTAURANTANALYZER_H
#define RESTAURANT2_RESTAURANTANALYZER_H

#include <string>
#include <vector>
#include <memory>
#include <fstream>

namespace analytics {

    struct Ingredient {
        Ingredient(const std::string& name, int qty, const std::string& unit) :
            name(name), qty(qty), unit(unit) {}
        std::string name;
        int qty;
        std::string unit;
    };

    struct Recipe {
        using Ingredients = std::vector<std::unique_ptr<Ingredient>>;

        std::string name;
        Ingredients ingredients;
    };


    using WorstRecipes = std::vector<std::pair<std::string, int>>;

    class RestaurantAnalyzer {
        using RecipePair = std::pair<std::unique_ptr<Recipe>, int>;
        using Meals = std::vector<RecipePair>;
    public:
        RestaurantAnalyzer(const std::string& filename) { in.open(filename); }
        ~RestaurantAnalyzer() { if(in) { in.close(); }}

        void parseData();

        WorstRecipes hasMostIngredients() const noexcept;

    private:
        std::string getRecipeName(std::string line) const;
        std::ifstream in;
        Meals meals;
    };

    using RestaurantAnalyzerPtr = std::unique_ptr<RestaurantAnalyzer>;


}


#endif //RESTAURANT2_RESTAURANTANALYZER_H
