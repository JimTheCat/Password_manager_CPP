//
// Created by Jimmy on 27.05.2022.
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

#ifndef PROJECT_PASSWORD_MANAGER_MENU_H
#define PROJECT_PASSWORD_MANAGER_MENU_H

#include <iostream>
#include <vector>
#include "../../Lib/single_include/nlohmann/json.hpp"

class menu {
public:
    static void generateMenu(std::vector<std::vector<std::string>>& vec, bool isGoodPassword,
                             const std::filesystem::path& path);
};


#endif //PROJECT_PASSWORD_MANAGER_MENU_H
