//
// Created by Jimmy on 27.05.2022.
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

#include "menu.h"
#include "../Wyszukaj/searchingPassword.h"
#include "../Posortuj/sort.h"
#include "../Dodaj/addPasswd.h"
#include "../../Utils/FileVectorConverter/converter.h"
#include "../Usun/deletePasswd.h"
#include "../DodajKat/addCategory.h"
#include "../UsunKat/deleteCategory.h"
#include <iostream>

using std::cout, std::endl;

/**
 * Generate menu
 * @param vec - vector filled with decrypted passwords
 * @param isGoodPassword - true if password is correct, otherwise false
 * @param path - path to file
 */
void menu::generateMenu(std::vector<std::vector<std::string>>& vec, bool isGoodPassword,
                        const std::filesystem::path& path) {
    int optionNumber = -1;

    while (optionNumber != 0){
        cout << "*---------------------*" << endl;
        cout << "|    WYBIERZ CYFRE    |" << endl;
        cout << "*---------------------*" << endl;
        cout << "|[1]- Wyszukaj hasla  |" << endl;
        cout << "*---------------------*" << endl;
        cout << "|[2]- Posortuj hasla  |" << endl;
        cout << "*---------------------*" << endl;
        cout << "|[3]- Dodaj haslo     |" << endl;
        cout << "*---------------------*" << endl;
        cout << "|[4]- Edytuj haslo    |" << endl;
        cout << "*---------------------*" << endl;
        cout << "|[5]- Usun haslo      |" << endl;
        cout << "*---------------------*" << endl;
        cout << "|[6]- Dodaj kategorie |" << endl;
        cout << "*---------------------*" << endl;
        cout << "|[7]- Usun kategorie  |" << endl;
        cout << "*---------------------*" << endl;
        cout << "|[0]- Zamknij program |" << endl;
        cout << "*---------------------*" << endl;

        std::cin >> optionNumber;
        try {
            switch (optionNumber) {
                case 1:
                    searchingPassword::searchPassword(vec);
                    break;
                case 2:
                    sort::sorting(vec, isGoodPassword);
                    break;
                case 3:
                    addPasswd::addPassword(vec, isGoodPassword);
                    break;
                case 4:
                    edit::editPassword(vec, isGoodPassword);
                    break;
                case 5:
                    deletePasswd::deletePassword(vec, isGoodPassword);
                    break;
                case 6:
                    addCategory::add(isGoodPassword);
                    break;
                case 7:
                    deleteCategory::deleteCat(vec, isGoodPassword);
                    break;
                case 0:
                    cout << "Bye bye! \nZapisuje zmiany do pliku!" << endl;
                    break;
                default:
                    std::cerr << "void generateMenu(): Wrong menu number" << endl;
            }
            if (isGoodPassword) converter::vectorToFile(vec, path);
        }
        catch (std::invalid_argument &e) {
            std::cerr << e.what() << endl;
            std::cin.ignore();
            std::cout << "Nacisnij ENTER by kontynuowac" << std::endl;
            std::cin.get();
        }
    }
}
