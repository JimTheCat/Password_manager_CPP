//
// Created by Jimmy on 03.06.2022.
//

#include <unistd.h>
#include <algorithm>
#include "searchingPassword.h"

/**
 * Searches passwords in vector
 * @param vec - vector filled with encoded passwords
 */
void searchingPassword::searchPassword(std::vector<std::vector<std::string>> &vec) {
    std::string pattern;
    int answer = 0;

    std::cout << "Co dokladnie chcesz zrobic?: " << std::endl;
    std::cout << "[1] Wypisz wszystkie hasla" << std::endl;
    std::cout << "[2] Wypisz hasla po parametrach" << std::endl;
    std::cin >> answer;
    switch (answer) {
        case 1:{
            searchingPassword::showAllPasswords(vec);
            break;
        }
        case 2:{
            searchingPassword::showCurrentPasswords(vec);
            break;
        }
        default: std::cerr << "void searchPassword(): Zostala podana niepoprawna wartosc" << std::endl;
    }
}

/**
 * Return all passwords in vector
 * @param vec - vector filled with passwords
 */
void searchingPassword::showAllPasswords(std::vector<std::vector<std::string>> &vec){
    int index = 1;
    for (const auto& i : vec){
        std::cout << index++ << ". ";
        for (const auto& j : i){
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
//    std::cin.ignore();
    //TODO: Ogarnac stopa jakiegos by poprawic komfort przegladania :3
}

/**
 * Returns selected passowrds contains pattern.
 * @param vec - vector filled with passwords
 */
void searchingPassword::showCurrentPasswords(std::vector<std::vector<std::string>>& vec){
    int numberOfParameters;
    int index = 1;
    std::string nameOfColumns[] = {"Haslo", "Nazwa", "Kategoria", "Strona_WWW", "Login"};
    int indexOfColumn;
    std::vector<int> indexOfVector;

    std::cout << "Po ilu parametrach chcesz szukac?" << std::endl;
    std::cin >> numberOfParameters;
    for (const auto& i : nameOfColumns){
        std::cout << index++ << ". " << i << std::endl;
    }
    if (numberOfParameters <= 0 || numberOfParameters > 5) std::cerr << "void showCurrentPasswords(): Podano nie poprawny argument!" << std::endl;
    else{
        while (numberOfParameters != 0){
            std::string parameterToSearch;
            std::cout << "Podaj nr kolumny: " << std::endl;
            std::cin >> indexOfColumn;
            indexOfColumn--;
            if (indexOfColumn <= 0 || indexOfColumn > 5) std::cerr << "void showCurrentPasswords(): Podano nie poprawny argument!" << std::endl;
            else{
                int indexOfLine = 0;
                std::cout << "Podaj nazwe: " << std::endl;
                std::cin >> parameterToSearch;
                for (auto i : vec){
                    if (i[indexOfColumn] == parameterToSearch) indexOfVector.push_back(indexOfLine);
                    indexOfLine++;
                }
            }
            numberOfParameters--;
        }
    }

    std::sort(indexOfVector.begin(), indexOfVector.end());
    indexOfVector.erase(std::unique(indexOfVector.begin(), indexOfVector.end()), indexOfVector.end());

    for (auto i : indexOfVector){
        for( int j = 0; j < 5; j++){
            std::cout << vec[i][j] << " ";
        }
        std::cout << "\n";
    }
}