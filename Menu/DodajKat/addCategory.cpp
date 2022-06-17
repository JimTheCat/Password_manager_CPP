//
// Created by Jimmy on 03.06.2022.
//

#include "addCategory.h"
#include "../../Utils/Encrypting/encrypt.h"
#include <fstream>

/**
 * Add category to categories.json
 * @param isGoodPassword - check if user password is correct
 */
void addCategory::add(bool isGoodPassword) {
    if (!isGoodPassword) std::cerr << "void add(): Blad! Opcja niedostepna przez niepoprawne haslo do programu" << std::endl;
    else {
        nlohmann::json j;
        std::ifstream i("../categories.json");
        i >> j;
        i.close();

        std::string nameOfCategory;
        std::ofstream o("../categories.json");

        std::cout << "Wpisz nazwe kategorii: " << std::endl;
        std::cin >> nameOfCategory;

        j["categories"].push_back(encrypt(nameOfCategory));

        o << std::setw(4) << j << std::endl;
        o.close();
    }
}
