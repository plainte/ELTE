//
// Created by molna on 2020. 04. 06..
//

#include "App.h"
#include <iostream>

void App::processData() {
    raPtr->parseData();
    auto worstRecipes = raPtr->hasMostIngredients();
    std::cout << "The recipe(s) that has the most ingredients is: " << std::endl;
    for (const auto& recipe : worstRecipes) {
        std::cout << " - " << recipe.first << " - ingredients: " << recipe.second << std::endl;
    }
}

int App::Run() {
    const std::string filename ="../input.txt";
    App app(filename);
    app.processData();
    return 0;
}

