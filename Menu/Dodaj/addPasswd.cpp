//
// Created by Jimmy on 27.05.2022.
//

#include "addPasswd.h"
#include <vector>
#include <iostream>
#include "../../Lib/single_include/nlohmann/json.hpp"
void addPasswd::addPassword(std::vector<std::vector<std::string>> vec, bool isGoodPassowrd, nlohmann::json j) {
    if (!isGoodPassowrd) throw std::invalid_argument("Password is wrong! This option is not available!");
    else {
        std::vector<std::string> passwordToPush;
        std::string textToPush;
        std::cout << "Podaj haslo: " << std::endl;
        std::cin >> textToPush;
        pushingText(textToPush, passwordToPush);
        std::cout << "Podaj nazwe: " << std::endl;
        std::cin >> textToPush;
        pushingText(textToPush, passwordToPush);
        std::cout << "Podaj kategorie: " << std::endl;
        std::cin >> textToPush;
        for (auto i : j){
            if (i == textToPush) pushingText(textToPush, passwordToPush);
            else throw std::invalid_argument("Nie ma takiej kategorii");
        }
    }
}

void addPasswd::pushingText(std::string textToPush, std::vector<std::string> password) {
    std::string separator = " ";
    password.push_back(textToPush);
    password.push_back(separator);
}