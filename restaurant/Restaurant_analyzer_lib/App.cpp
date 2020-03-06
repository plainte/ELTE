//
// Created by molna on 2020. 03. 30..
//

#include "App.h"
#include <algorithm>


void App::collectData() {
    restaurantAnalyzerPtr->parseData();
    // safe to call due to must have value at this point
    auto orders = restaurantAnalyzerPtr->getOrders();
    auto food = restaurantAnalyzerPtr->bestProduct().value();
    auto key = food;
    std::for_each(food.begin(), food.end(), [](char& c){
        c = ::toupper(c);
    });
    std::cout << "The best product was the " << food << std::endl;
    std::cout << " - sold " << orders[key].qty << " times @" <<  orders[key].px << std::endl;
    std::cout << " - total worth: " << restaurantAnalyzerPtr->bestProductIncome().value() << std::endl;
}


int App::Run() {
    const std::string filename = "../input.txt";
    try {
        App app(filename);
        app.collectData();
    } catch (ErrorCode e) {
        if (e == ErrorCode::ERROR_OPENING) {
            std::cout << "Unable to open \"" << filename << "\" !" << std::endl;
            std::cout << "File may not exists..." << std::endl;
            std::cout << "Closing program!" << std::endl;
            return 1;
        } else if (e == ErrorCode::ERROR_EMPTY) {
            std::cout << "File is empty..." << std::endl;
            std::cout << "Closing program!" << std::endl;
            return 2;
        } else if (e == ErrorCode::ERROR_READING) {
            std::cout << "Not a sequential file, please edit then try again!" << std::endl;
            std::cout << "Closing program!" << std::endl;
            return 3;
        }
    }
    return 0;
}

