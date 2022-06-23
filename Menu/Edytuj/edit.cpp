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

#include "edit.h"
#include "../Dodaj/addPasswd.h"

/**
 * Edit current password by name;
 * @param vec - vector filled with decrypted passwords
 * @param isGoodPassword - true if password is correct, otherwise false
 */
void edit::editPassword(std::vector<std::vector<std::string>> &vec, bool isGoodPassword) {
    if (!isGoodPassword) std::cerr << "void editPassword(): Blad! Opcja niedostepna przez niepoprawne haslo do programu" << std::endl;
    else if (vec.empty()) std::cerr << "void editPassword(): Nie mozna edytowac hasla poniewaz nie posiadasz zadnego!" << std::endl;
    else {
        std::string nameOfPassword;
        int index = 0;
        bool passwordFounded = false;

        std::cout << "Podaj nazwe hasla ktore chcesz edytowac: " << std::endl;
        std::cin >> nameOfPassword;

        for (auto i: vec) {
            if (i[1] == nameOfPassword) {
                passwordFounded = true;
                std::cout << "Haslo " << nameOfPassword << " zostalo znalezione!" << std::endl;
                break;
            }
            index++;
        }
        if (passwordFounded) edit::changingValues(vec, index);
        else std::cerr << "void editPassword(): Nie znaleziono takiego hasla!" << std::endl;

        std::cin.ignore();
        std::cout << "Nacisnij ENTER by kontynuowac" << std::endl;
        std::cin.get();
    }
}

/**
 * Change values of current password
 * @param vec - vector filled with decrypted passwords
 * @param index - index of current password
 */
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
            std::cout << "Podaj nazwe strony WWW: " << std::endl;
            std::cin >> textToChange;

            vec[index][3] = textToChange;
            break;
        }
        case '4':{
            std::cout << "Podaj login: " << std::endl;
            std::cin >> textToChange;

            vec[index][4] = textToChange;
            break;
        }
        default: std::cerr << "void changingValues(): Wybrano niepoprawna opcje!" << std::endl;
    }
}
