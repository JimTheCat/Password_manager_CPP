//
// Created by Patryk on 03.06.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_ADDPASSWD_H
#define PROJECT_PASSWORD_MANAGER_ADDPASSWD_H


#include <iostream>
#include <vector>
#include "../../Lib/single_include/nlohmann/json.hpp"
#include "../Edytuj/edit.h"

class addPasswd {
public:
    static void addPassword(std::vector<std::vector<std::string>>& vec, bool isGoodPassword, nlohmann::json j);
    friend void edit::changingValues(std::vector<std::vector<std::string>> &vec, const int& index);
protected:
    static std::string generatePassword();
    static std::string generatedPasswordToReturn(int lengthOfPassword, bool isUpperCase, bool specialLetters);
    static void showCategories();
    static void checkingStrengthOfPassword(const std::string &passwordToCheck);
    static bool checkingUniqueOfName(const std::string &nameToCheck, std::vector<std::vector<std::string>> &vec);
};


#endif //PROJECT_PASSWORD_MANAGER_ADDPASSWD_H
