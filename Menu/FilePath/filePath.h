//
// Created by Patryk on 07.05.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_FILEPATH_H
#define PROJECT_PASSWORD_MANAGER_FILEPATH_H
#include <iostream>
#include <filesystem>

namespace fs=std::filesystem;

fs::path filePathRequest(std::string source);

#endif //PROJECT_PASSWORD_MANAGER_FILEPATH_H
