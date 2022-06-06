//
// Created by Jimmy on 03.06.2022.
//

#include "deleteCategory.h"
#include "../../Lib/single_include/nlohmann/json.hpp"
#include <fstream>

void deleteCategory::deleteCat() {

    std::string nameOfCategory;
    int index = 0;
    nlohmann::json j;
    std::ifstream i("../categories.json");
    i >> j;
    i.close();

    std::cout << "Wpisz nazwe kategorii ktora chcesz usunac: " << std::endl;
    std::cin >> nameOfCategory;

    for (auto i : j["categories"]) {
        if (i.get<std::string>() == nameOfCategory) {
            j["categories"].erase(index);
            break;
        } else index++;
    }

    std::ofstream o("../categories.json");
    o << std::setw(4) << j << std::endl;
    o.close();

    std::cout << "Kategoria " << nameOfCategory << " zostala usunieta!" << std::endl;
}
