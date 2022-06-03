//
// Created by Patryk on 03.06.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_ADDPASSWD_H
#define PROJECT_PASSWORD_MANAGER_ADDPASSWD_H


#include <iostream>
#include <vector>

struct addPasswd {
    void addPassword(std::vector<std::vector<std::string>> vec, bool isGoodPassowrd);
    void pushingText(std::string textToPush, std::vector<std::string> password);
};


#endif //PROJECT_PASSWORD_MANAGER_ADDPASSWD_H
