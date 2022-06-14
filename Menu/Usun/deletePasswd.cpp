//
// Created by Jimmy on 03.06.2022.
//

#include "deletePasswd.h"

void deletePasswd::deletePassword(std::vector<std::vector<std::string>> &vec, bool isGoodPassword) {
    if (!isGoodPassword) std::cerr << "void deletePassword(): Blad! Opcja niedostepna przez niepoprawne haslo do programu" << std::endl;
    else {
        std::string passwordToDelete;
        bool passwordFounded = false;
        int index = 0;

        std::cout << "Wpisz nazwe hasla ktore chcesz usunac!: " << std::endl;
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
            for (const auto& i: vec[index]) {
                std::cout << i << " ";
            }
            std::cout << "\nCzy chcesz usunac te haslo?: [t/n]";
            std::cin >> deletePasswd;
            if (deletePasswd == 't') vec.erase(vec.begin() + index);
        } else std::cerr << "void deletePassword(): Haslo zostalo nie znalezione" << std::endl;
    }
}
