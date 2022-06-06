//
// Created by Jimmy on 24.05.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_CONVERTER_H
#define PROJECT_PASSWORD_MANAGER_CONVERTER_H

#include <iostream>
#include <vector>
#include <filesystem>

namespace fs=std::filesystem;

class converter {
public:
    static std::vector<std::vector<std::string>> fileToVector(fs::path convertedPath, bool isGoodPassword);
    static void vectorToFile(std::vector<std::vector<std::string>> &vectorToSave, const std::filesystem::path& pathToFile);
};


#endif //PROJECT_PASSWORD_MANAGER_CONVERTER_H
