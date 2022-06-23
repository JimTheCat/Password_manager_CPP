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

#include "addCategory.h"
#include "../../Utils/Encrypting/encrypt.h"
#include "../../Utils/Decrypting/decrypt.h"
#include <fstream>
#include <filesystem>

namespace fs=std::filesystem;

/**
 * Add category to categories.json
 * @param isGoodPassword - true if password is correct, otherwise false
 */
void addCategory::add(bool isGoodPassword) {
    if (!isGoodPassword) std::cerr << "void add(): Blad! Opcja niedostepna przez niepoprawne haslo do programu" << std::endl;
    else {
        std::string nameOfCategory;
        std::string nameOfPath = "../categories.json";
        bool uniqueOfCategory = true;
        nlohmann::json j;
        fs::path path(nameOfPath);

        std::cout << "Wpisz nazwe kategorii: " << std::endl;
        std::cin >> nameOfCategory;

        if (!exists(path)) addCategory::createCategories();
        std::ifstream i(path);
        i >> j;
        i.close();
        for (const auto& k : j["categories"]){
            if (decrypt(k) == nameOfCategory) uniqueOfCategory = false;
        }
        if (!uniqueOfCategory) std::cerr << "Nie udalo sie dodac kategorii poniewaz znajduje sie na liscie" << std::endl;
        else {
            std::ofstream o(path);
            j["categories"].push_back(encrypt::encryptText(nameOfCategory));
            o << std::setw(4) << j << std::endl;
            o.close();
            std::cout << "Kategoria " << nameOfCategory << " zostala dodana pomyslnie!" << std::endl;
        }
        std::cin.ignore();
        std::cout << "Nacisnij ENTER by kontynuowac" << std::endl;
        std::cin.get();
    }
}

/**
 * Create file 'categories.json'
 */
void addCategory::createCategories(){
    std::filesystem::path path("../categories.json");
    std::cout << "Nie znaleziono pliku z kategoriami! Tworze nowy plik!" << std::endl;
    std::ofstream of(path);
    auto j2 = R"(
                {
                    "categories": [

                    ]
                }
            )"_json;

    of << std::setw(4) << j2 << std::endl;
    of.close();
}