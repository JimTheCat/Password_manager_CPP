//
// Created by Jimmy on 27.05.2022.
//

#include "dodaj.h"

void dodaj::addPassowrd(std::vector<std::vector<std::string>> vec, bool isGoodPassowrd) {
    if (!isGoodPassowrd) throw std::invalid_argument("Password is wrong! This option is not available!");
    else {
        std::vector<std::string> passwordToPush;
        std::string textToPush;
        std::cout << "Podaj haslo: " << std::endl;
        std::cin >> textToPush;
        pushingText(textToPush, passwordToPush);
    }
}

void dodaj::pushingText(std::string textToPush, std::vector<std::string> password) {
    std::string separator = " ";
    password.push_back(textToPush);
    password.push_back(separator);
}