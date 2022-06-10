//
// Created by Jimmy on 03.06.2022.
//

#include "edit.h"


void edit::editPassword(std::vector<std::vector<std::string>> &vec, const std::string& nameOfPassword) {
    int index = 0;
    bool passwordFounded = false;
    for (auto i : vec){
        if (i[1] == nameOfPassword) {
            passwordFounded = true;
            break;
        }
        index++;
    }
    if(passwordFounded) edit::changingValues(vec, index);
    else std::cerr << "Nie znaleziono takiego hasla!" << std::endl;
}

void edit::changingValues(std::vector<std::vector<std::string>> &vec, const int& index){
    char answer = 'n';
    while (answer != 't'){
        const std::string options[] = {"Haslo", "Nazwa", "Strona_WWW", "Login"};
        int indexOfLine = 1;
        char choice = '0';
        std::cout << "Ktory parametr chcialbys zmienic w tym hasle:" << std::endl;
        for (const auto& i : options){
            std::cout << indexOfLine++ << ". " << i << std::endl;
        }
        //TODO: dokonczyc switcha :3
//        switch (choice) {
//            case 1:
//        }

    }
}
