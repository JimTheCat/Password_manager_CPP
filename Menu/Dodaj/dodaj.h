//
// Created by Jimmy on 27.05.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_DODAJ_H
#define PROJECT_PASSWORD_MANAGER_DODAJ_H

#include <iostream>
#include <vector>

struct dodaj {
    void addPassword(std::vector<std::vector<std::string>> vec, bool isGoodPassowrd);
    void pushingText(std::string textToPush, std::vector<std::string> password);
};


#endif //PROJECT_PASSWORD_MANAGER_DODAJ_H
