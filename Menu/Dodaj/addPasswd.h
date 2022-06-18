//
// Created by Patryk on 03.06.2022.
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

#ifndef PROJECT_PASSWORD_MANAGER_ADDPASSWD_H
#define PROJECT_PASSWORD_MANAGER_ADDPASSWD_H


#include <iostream>
#include <vector>
#include "../../Lib/single_include/nlohmann/json.hpp"
#include "../Edytuj/edit.h"

class addPasswd {
public:
    static void addPassword(std::vector<std::vector<std::string>>& vec, bool isGoodPassword);
    friend void edit::changingValues(std::vector<std::vector<std::string>> &vec, const int& index);
protected:
    static std::string generatePassword();
    static std::string generatedPasswordToReturn(int lengthOfPassword, bool isUpperCase, bool specialLetters);
    static void showCategories(nlohmann::json j);
    static void checkingStrengthOfPassword(const std::string &passwordToCheck);
    static bool checkingUniqueOfName(const std::string &nameToCheck, std::vector<std::vector<std::string>> &vec);
};


#endif //PROJECT_PASSWORD_MANAGER_ADDPASSWD_H
