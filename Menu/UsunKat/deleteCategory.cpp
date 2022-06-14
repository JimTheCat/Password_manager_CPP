//
// Created by Jimmy on 03.06.2022.
//

#include "deleteCategory.h"
#include "../../Utils/Decrypting/decrypt.h"
#include <fstream>
#include <unistd.h>

void deleteCategory::deleteCat(std::vector<std::vector<std::string>> &vec, bool isGoodPassword) {
    if (!isGoodPassword) std::cerr << "void deleteCat(): Blad! Opcja niedostepna przez niepoprawne haslo do programu" << std::endl;
    else {
        std::string nameOfCategory;
        int index = 0;
        nlohmann::json j;
        std::ifstream i("../categories.json");
        i >> j;
        i.close();

        std::cout
                << "Wpisz nazwe kategorii ktora chcesz usunac\n!UWAGA!\nUsuniecie kategorii wiaze sie z usunieciem wszystkich hasel wraz z wpisana kategoria: "
                << std::endl;
        std::cin >> nameOfCategory;

        for (const auto& k: j["categories"]) {
            if (decrypt(k.get<std::string>()) == nameOfCategory) {
                deletePasswordsContainCurrentCategory(nameOfCategory, vec);
                j["categories"].erase(index);
                break;
            } else index++;
        }

        std::ofstream o("../categories.json");
        o << std::setw(4) << j << std::endl;
        o.close();

        std::cout << "Kategoria " << nameOfCategory << " zostala usunieta!" << std::endl;

        sleep(2);
    }
}

void deleteCategory::deletePasswordsContainCurrentCategory(const std::string& nameOfCategory,
                                                           std::vector<std::vector<std::string>>& vec) {
    std::vector<int> vecOfIndex;
    for (int i = 0; i < vec.size(); i++){
        if (nameOfCategory == vec[i][2]) vecOfIndex.push_back(i);
    }
    for (int i = vecOfIndex.size() - 1; i >= 0; i--) {
        vec.erase(vec.begin() + vecOfIndex[i]);
    }
    std::cout << "Hasla zawierajace kategorie " << nameOfCategory << " zostaly usuniete!" << std::endl;
    sleep(2);
}