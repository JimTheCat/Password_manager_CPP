//
// Created by Jimmy on 27.05.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_MENU_H
#define PROJECT_PASSWORD_MANAGER_MENU_H

#include <iostream>
#include <vector>
#include "../../Lib/single_include/nlohmann/json.hpp"

struct menu {
    static void generateMenu(std::vector<std::vector<std::string>> vec, bool isGoodPassword, const nlohmann::json& j,
                             const std::filesystem::path& path);
};


#endif //PROJECT_PASSWORD_MANAGER_MENU_H
