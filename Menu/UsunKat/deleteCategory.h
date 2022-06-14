//
// Created by Jimmy on 03.06.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_DELETECATEGORY_H
#define PROJECT_PASSWORD_MANAGER_DELETECATEGORY_H

#include <iostream>
#include "../../Lib/single_include/nlohmann/json.hpp"

class deleteCategory {
public:
    static void deleteCat(std::vector<std::vector<std::string>> &vec, bool isGoodPassword);
private:
    static void deletePasswordsContainCurrentCategory(const std::string& nameOfCategory, std::vector<std::vector<std::string>>& vec);

};


#endif //PROJECT_PASSWORD_MANAGER_DELETECATEGORY_H
