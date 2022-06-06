//
// Created by Patryk on 03.06.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_ADDPASSWD_H
#define PROJECT_PASSWORD_MANAGER_ADDPASSWD_H


#include <iostream>
#include <vector>
#include "../../Lib/single_include/nlohmann/json.hpp"

struct addPasswd {
    static void addPassword(std::vector<std::vector<std::string>>& vec, bool isGoodPassword, nlohmann::json j);
    static std::string generatePassword();
    static std::string generatedPasswordToReturn(int lengthOfPassword, bool isUpperCase, bool specialLetters);
};


#endif //PROJECT_PASSWORD_MANAGER_ADDPASSWD_H
