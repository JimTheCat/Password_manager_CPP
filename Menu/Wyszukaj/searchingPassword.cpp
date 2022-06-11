//
// Created by Jimmy on 03.06.2022.
//

#include "searchingPassword.h"

void searchingPassword::searchPassword(std::vector<std::vector<std::string>> &vec) {
    std::string pattern;
    bool passwordFounded = false;
    int answer = 0;

    std::cout << "Co dokladnie chcesz zrobic?: " << std::endl;
    std::cout << "[1] Wypisz wszystkie hasla" << std::endl;
    std::cout << "[2] Wypisz hasla po parametrach" << std::endl;
    switch (answer) {
        case 1:{
            searchingPassword::showAllPasswords(vec);
            break;
        }
        case 2:{

        }
        default: std::cerr << "void searchPassword(): Zostala podana niepoprawna wartosc" << std::endl;
    }
    std::cout << "Wpisz szukane haslo: " << std::endl;
    std::cin >> pattern;
    for (auto & i : vec){
        if (std::equal(pattern.begin(), pattern.end(), i[0].begin(), i[0].end())){
            std::cout << "Found matching password!" << std::endl;
            for (auto & j : i){
                std::cout << j;
            }
            passwordFounded = true;
            std::cout << std::endl;
        }
    }
    if (!passwordFounded) std::cout << "There is not matching passowrd!" << std::endl;
}

void searchingPassword::showAllPasswords(std::vector<std::vector<std::string>> &vec){
    for (const auto& i : vec){
        for (const auto& j : i){
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

void searchingPassword::showCurrentPasswords(std::vector<std::vector<std::string>> vec){
    int numberOfParameters = 0;
    int index = 1;
    std::string nameOfColumns[] = {"Haslo", "Nazwa", "Kategoria", "Strona_WWW", "Login"};
    int indexOfColumn

    std::cout << "Po ilu parametrach chcesz szukac?" << std::endl;
    std::cin >> numberOfParameters;
    for (auto i : nameOfColumns){
        std::cout << index++ << ". " << i << std::endl;
    }
    if (numberOfParameters <= 0 && numberOfParameters > 5) std::cerr << "void showCurrentPasswords(): Podano nie poprawny argument!" << std::endl;
    else{
        while (numberOfParameters != 0){
            std::string parameterToSearch;
            //TODO: Dokonczyc searching!
            std::cout << "Podaj nr kolumny: " << std::endl;
            std::cin >> indexOfColumn;
            indexOfColumn--;
            if (indexOfColumn <= 0 && indexOfColumn > 5)
            std::cout << "Podaj nazwe: " << std::endl;
            std::cin >> parameterToSearch;
            for (auto i : vec){
                if (i[in])
            }
        }
    }
}