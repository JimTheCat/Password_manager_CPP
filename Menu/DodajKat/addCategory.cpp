//
// Created by Jimmy on 03.06.2022.
//

#include "addCategory.h"
#include "../../Utils/Encrypting/encrypt.h"
#include "../../Utils/StringConverter/strconverter.h"
#include <fstream>

void addCategory::add() {
    nlohmann::json j;
    std::ifstream i("../categories.json");
    i >> j;
    i.close();

    std::string nameOfCategory;
    std::ofstream o("../categories.json");

    std::cout << "Wpisz nazwe kategorii: " << std::endl;
    std::cin >> nameOfCategory;

    j["categories"].push_back(encrypt(strconverter::replaceSpaceToUnderscore(nameOfCategory)));

    o << std::setw(4) << j << std::endl;
    o.close();
}
