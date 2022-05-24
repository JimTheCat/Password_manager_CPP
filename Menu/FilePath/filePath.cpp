//
// Created by Patryk on 07.05.2022.
//

#include "filePath.h"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs=std::filesystem;

fs::path filePathRequest(const std::string& source){
    fs::path filePath(source);
    if (source.empty() || filePath.extension() != ".txt") throw std::invalid_argument("Err! File not Found! Check extension of file or path and try again!");
    if(filePath.has_root_name()) return filePath;
    std::string toMakeCorrectPath = "../";
    return filePath = (fs::path)toMakeCorrectPath.append(source);
};