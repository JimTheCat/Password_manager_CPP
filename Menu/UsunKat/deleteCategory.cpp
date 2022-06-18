//
// Created by Jimmy on 03.06.2022.
//
/*
    Ta aplikacja została napisana przez Patryka Kłosińskiego.
    Jeśli chcesz wykorzystać ten kod proszę o nie usuwanie tego komentarza!
    Bardzo dziękuje!
    ---------------------------------------------------------------------------
    This app was written by Patryk Kłosiński.
    If you want to use this code please don't delete this comment!
    Thank you very much!
    ---------------------------------------------------------------------------
    GitHub: https://github.com/JimTheCat
    E-Mail: klosinski.patryk2137@gmail.com
 */

#include "deleteCategory.h"
#include "../../Utils/Decrypting/decrypt.h"
#include <fstream>
#include <unistd.h>

/**
 * Delete category in categories.json
 * @param vec - vector filled with passwords
 * @param isGoodPassword - check if user password is correct
 */
void deleteCategory::deleteCat(std::vector<std::vector<std::string>> &vec, bool isGoodPassword) {
    if (!isGoodPassword) std::cerr << "void deleteCat(): Blad! Opcja niedostepna przez niepoprawne haslo do programu" << std::endl;
    else {
        std::string nameOfCategory;
        int index = 0;
        nlohmann::json j;
        std::ifstream i("../categories.json");
        i >> j;
        i.close();

        if (j["categories"].empty()) std::cerr << "void deleteCat(): Nie mozna usunac kategorii poniewaz lista jest pusta" << std::endl;
        else {
            bool categoryExists = false;
            std::cout << "Lista kategorii do wyboru: " << std::endl;

            for (const auto &k: j["categories"]) {
                std::cout << decrypt(k) << std::endl;
            }

            std::cout << "\n";

            std::cout
                    << "Wpisz nazwe kategorii ktora chcesz usunac\n!UWAGA!\nUsuniecie kategorii wiaze sie z usunieciem wszystkich hasel wraz z wpisana kategoria: "
                    << std::endl;
            std::cin >> nameOfCategory;


            for (const auto &k: j["categories"]) {
                if (decrypt(k.get<std::string>()) == nameOfCategory) {
                    categoryExists = true;
                    deletePasswordsContainCurrentCategory(nameOfCategory, vec);
                    j["categories"].erase(index);
                    break;
                } else index++;
            }

            if(categoryExists) {
                std::ofstream o("../categories.json");
                o << std::setw(4) << j << std::endl;
                o.close();

                std::cout << "Kategoria " << nameOfCategory << " zostala usunieta!" << std::endl;
            }
            else std::cout << "Wpisana nazwa kategorii nie istnieje!" << std::endl;
            std::cin.ignore();
            std::cout << "Nacisnij ENTER by kontynuowac" << std::endl;
            std::cin.get();
        }
    }
}

/**
 * Deletes passwords connected with deleted category
 * @param nameOfCategory - name of category
 * @param vec - vector filled with passwords
 */
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