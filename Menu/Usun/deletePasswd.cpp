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

#include <algorithm>
#include "deletePasswd.h"

/**
 * Delete password
 * @param vec - vector filled with passwords
 * @param isGoodPassword - check if user password is correct
 */
void deletePasswd::deletePassword(std::vector<std::vector<std::string>> &vec, bool isGoodPassword) {
    if (!isGoodPassword) std::cerr << "void deletePassword(): Blad! Opcja niedostepna przez niepoprawne haslo do programu" << std::endl;
    else if (vec.empty()) std::cerr << "void deletePassword(): Nie mozna usunac hasla poniewaz lista hasel jest pusta!" << std::endl;
    else {
        int action = 0;

        std::cout << "Co dokladnie chcesz zrobic" << std::endl;
        std::cout << "[1] Usunac konkretne haslo" << std::endl;
        std::cout << "[2] Usunac hasla po danym parametrze" << std::endl;
        std::cin >> action;

        switch (action) {
            case 1:{
                deletePasswd::singlePassword(vec);
                break;
            }
            case 2:{
                deletePasswd::parametersPassword(vec);
                break;
            }
            default: std::cerr << "void deletePassword(): Podano niepoprawny numer!" << std::endl;
        }
        std::cin.ignore();
        std::cout << "Nacisnij ENTER by kontynuowac" << std::endl;
        std::cin.get();
    }
}

/**
 * Deletes password by name
 * @param vec - vector filled with passwords
 */
void deletePasswd::singlePassword(std::vector<std::vector<std::string>> &vec){
    bool passwordFounded = false;
    int index = 0;
    std::string passwordToDelete;

    std::cout << "Wpisz unikalna nazwe hasla ktore chcesz usunac!: " << std::endl;
    std::cin >> passwordToDelete;

    for (auto i: vec) {
        if (i[1] == passwordToDelete) {
            passwordFounded = true;
            break;
        }
        index++;
    }

    if (passwordFounded) {
        char deletePasswd = 'n';
        std::cout << "Haslo zostalo znalezione!: " << std::endl;
        for (int j = 0; j < 6; j++) {
            std::cout << vec[index][j] << " ";
        }
        std::cout << "\n";
        std::cout << "Czy chcesz usunac te haslo?: [t/n]";
        std::cin >> deletePasswd;
        if (deletePasswd == 't') vec.erase(vec.begin() + index);
    }
    else std::cerr << "void singlePassword(): Haslo nie zostalo znalezione" << std::endl;
}

/**
 * Deletes passwords by parameters
 * @param vec - vector filled with passwords
 */
void deletePasswd::parametersPassword(std::vector<std::vector<std::string>> &vec){
    std::string listOfColumns[] = {"Haslo", "Nazwa", "Kategoria", "Strona_WWW", "Login"};
    bool passwordFounded = false;
    std::vector<int> indexesOfPasswords;
    std::string passwordToDelete;
    int index;
    int selectedColumn = -1;
    int countOfParameters = 0;
    std::cout << "Po ilu parametrach chcesz szukac! [1-5]: " << std::endl;
    std::cin >> countOfParameters;
    if (countOfParameters > 5 || countOfParameters < 1) std::cerr << "void parametersPassword(): Niepoprawna ilosc parametrow!" << std::endl;
    else {
        for(int howManyParameters = 0; howManyParameters < countOfParameters; howManyParameters++) {
            std::cout << "Wybierz numer kolumny: " << std::endl;
            index = 0;
            for (const auto &i: listOfColumns) {
                std::cout << ++index << ". " << i << std::endl;
            }
            std::cin >> selectedColumn;
            selectedColumn--;

            std::cout << "Wprowadz nazwe: " << std::endl;
            std::cin >> passwordToDelete;

            index = 0;
            for (auto j: vec) {
                if (j[selectedColumn] == passwordToDelete) {
                    passwordFounded = true;
                    indexesOfPasswords.push_back(index);
                }
                index++;
            }
        }

        std::sort(indexesOfPasswords.begin(), indexesOfPasswords.end());
        indexesOfPasswords.erase(std::unique(indexesOfPasswords.begin(), indexesOfPasswords.end()), indexesOfPasswords.end());

        if (passwordFounded) {
            char deletePasswd = 'n';
            std::cout << "Hasla zostaly znalezione!: " << std::endl;
            for (const auto &i: indexesOfPasswords) {
                for (int j = 0; j < 6; j++) {
                    std::cout << vec[i][j] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "Czy chcesz usunac te hasla?: [t/n]";
            std::cin >> deletePasswd;
            if (deletePasswd == 't') {
                for (int k = indexesOfPasswords.size() - 1; k >= 0; k--){
                    vec.erase(vec.begin() + indexesOfPasswords[k]);
                }
            }
        }
    }
}