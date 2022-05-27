//
// Created by Jimmy on 27.05.2022.
//

#include "menu.h"
#include "../Wyszukaj/wyszukaj.h"
#include <iostream>

using std::cout, std::endl;

void menu::generateMenu(std::vector<std::vector<std::string>> listOfPasswords) {
    int optionNumber;
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
    std::cin >> optionNumber;
//    switch (optionNumber) {
//        case 1:
//            wyszukaj::searchPassword(listOfPasswords);
//            break;
//        case 2:
//            wyszukaj::searchPassword();
//            break;
//        case 3:
//            wyszukaj::searchPassword();
//            break;
//        case 4:
//            wyszukaj::searchPassword();
//            break;
//        case 5:
//            wyszukaj::searchPassword();
//            break;
//        case 6:
//            wyszukaj::searchPassword();
//            break;
//        case 7:
//            wyszukaj::searchPassword();
//            break;
//        default: throw std::errc::invalid_argument("Wrong menu number");
//    }
}
