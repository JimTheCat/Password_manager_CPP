//
// Created by Jimmy on 27.05.2022.
//

#include "menu.h"
#include "../Wyszukaj/searchingPassword.h"
#include <iostream>

using std::cout, std::endl;

void menu::generateMenu(std::vector<std::vector<std::string>> listOfPasswords) {
    int optionNumber;

    while (optionNumber != 0){
        cout << "*--------------------*" << endl;
        cout << "|   WYBIERZ CYFRE    |" << endl;
        cout << "*--------------------*" << endl;
        cout << "|[1]- Wyszukaj hasla |" << endl;
        cout << "*--------------------*" << endl;
        cout << "|[2]- Posortuj hasla |" << endl;
        cout << "*--------------------*" << endl;
        cout << "|[3]- Dodaj haslo    |" << endl;
        cout << "*--------------------*" << endl;
        cout << "|[4]- Edytuj haslo   |" << endl;
        cout << "*--------------------*" << endl;
        cout << "|[5]- Usun haslo     |" << endl;
        cout << "*--------------------*" << endl;
        cout << "|[6]- Dodaj kategorie|" << endl;
        cout << "*--------------------*" << endl;
        cout << "|[7]- Usun kategorie |" << endl;
        cout << "*--------------------*" << endl;
        cout << "|[0]- Zamknij program|" << endl;
        cout << "*--------------------*" << endl;
        std::cin >> optionNumber;
//    switch (optionNumber) {
//        case 1:
//            searchPassword::searchPassword(listOfPasswords);
//            break;
//        case 2:
//            searchPassword::searchPassword();
//            break;
//        case 3:
//            searchPassword::searchPassword();
//            break;
//        case 4:
//            searchPassword::searchPassword();
//            break;
//        case 5:
//            searchPassword::searchPassword();
//            break;
//        case 6:
//            searchPassword::searchPassword();
//            break;
//        case 7:
//            searchPassword::searchPassword();
//            break;
//        default: throw std::errc::invalid_argument("Wrong menu number");
//    }
    }
}
