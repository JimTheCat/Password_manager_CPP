//
// Created by Jimmy on 27.05.2022.
//

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


void menu::generateMenu(std::vector<std::vector<std::string>> vec, bool isGoodPassword, nlohmann::json j,
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

        switch (optionNumber) {
            case 1:
                searchingPassword::searchPassword(vec);
                break;
            case 2:
                sort::sorting();
                break;
            case 3:
                addPasswd::addPassword(vec, isGoodPassword, j);
                break;
            case 4:
                searchingPassword::searchPassword(vec);
                break;
            case 5:
                deletePasswd::deletePassword(vec);
                break;
            case 6:
                addCategory::add();
                break;
            case 7:
                deleteCategory::deleteCat(vec);
                break;
            case 0:
                cout << "Bye bye! \nZapisuje zmiany do pliku!" << endl;
                break;
            default: throw std::invalid_argument("void generateMenu(): Wrong menu number");
        }
        converter::vectorToFile(vec, path);
    }
}
