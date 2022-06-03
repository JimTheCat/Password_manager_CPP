//
// Created by Jimmy on 03.06.2022.
//

#include "addCategory.h"
#include "../../../Project_password_manager/Lib/single_include/nlohmann/json.hpp"
#include <fstream>

void addCategory::add(std::string &nameOfCategory) {
    nlohmann::json jd;
    std::ifstream i(R"(C:\Users\Jimmy\Desktop\PJC\Project_password_manager\categories.json)");
    i >> jd;
    nameOfCategory = jd.dump();
}
