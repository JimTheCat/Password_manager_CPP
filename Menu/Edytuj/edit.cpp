//
// Created by Jimmy on 03.06.2022.
//

#include "edit.h"
#include "../Dodaj/addPasswd.h"


void edit::editPassword(std::vector<std::vector<std::string>> &vec) {
    std::string nameOfPassword;
    int index = 0;
    bool passwordFounded = false;

    std::cout << "Podaj nazwe hasla ktore chcesz edytowac: " << std::endl;
    std::cin >> nameOfPassword;

    for (auto i : vec){
        if (i[1] == nameOfPassword) {
            passwordFounded = true;
            break;
        }
        index++;
    }
    if(passwordFounded) edit::changingValues(vec, index);
    else std::cerr << "void editPassword(): Nie znaleziono takiego hasla!" << std::endl;
}

void edit::changingValues(std::vector<std::vector<std::string>> &vec, const int& index){
    std::string textToChange;
    const std::string options[] = {"Haslo", "Nazwa", "Strona_WWW", "Login"};
    int indexOfLine = 1;
    char choice = '0';

    std::cout << "Ktory parametr chcialbys zmienic w tym hasle:" << std::endl;
    for (const auto& i : options){
        std::cout << indexOfLine++ << ". " << i << std::endl;
    }
    std::cin >> choice;
    switch (choice) {
        case '1':{
            char changePasswd = 'n';

            std::cout << "Czy chcesz randomowe haslo? [t/n]: " << std::endl;
            std::cin >> changePasswd;
            if (changePasswd == 't') textToChange = addPasswd::generatePassword();
            else if (changePasswd == 'n') {
                std::cout << "Podaj haslo: " << std::endl;
                std::cin >> textToChange;
            }
            addPasswd::checkingStrengthOfPassword(textToChange);
            vec[index][0] = textToChange;
            break;
        }
        case '2':{
            bool isNameUnique = false;
            std::cout << "Podaj nazwe: " << std::endl;
            while (!isNameUnique) {
                std::cin >> textToChange;
                isNameUnique = addPasswd::checkingUniqueOfName(textToChange, vec);
                if (!isNameUnique) std::cout << "Nazwa juz wystapila w innym hasle! Wprowadz inna nazwe: " << std::endl;
            }
            vec[index][1] = textToChange;
            break;
        }
        case '3':{
            // strona www
            std::cout << "Podaj nazwe strony WWW: " << std::endl;
            std::cin >> textToChange;

            vec[index][3] = textToChange;
            break;
        }
        case '4':{
            // login
            std::cout << "Podaj login: " << std::endl;
            std::cin >> textToChange;

            vec[index][4] = textToChange;
            break;
        }
        default: std::cerr << "void changingValues(): Wybrano niepoprawna opcje!" << std::endl;
    }
}
