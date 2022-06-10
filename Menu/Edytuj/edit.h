//
// Created by Jimmy on 03.06.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_EDIT_H
#define PROJECT_PASSWORD_MANAGER_EDIT_H
#include <iostream>
#include <vector>

class edit {
public:
    static void editPassword(std::vector<std::vector<std::string>> &vec, const std::string &nameOfPassword);

    static void changingValues(std::vector<std::vector<std::string>> &vec, const int &index);
}

#endif //PROJECT_PASSWORD_MANAGER_EDIT_H
