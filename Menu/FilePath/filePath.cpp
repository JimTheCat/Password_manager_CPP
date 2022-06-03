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
    char answer;
    std::string toMakeCorrectPath = "../";
    if(!filePath.has_root_name()) filePath = (fs::path)toMakeCorrectPath.append(source);
    if (!exists(filePath)){
        std::cout << "Podana sciezka pliku nie isnieje! Tworze nowy plik w podanej lokalizacji!" << std::endl;
        std::ofstream newFile(toMakeCorrectPath);
        newFile.close();
    }
    if (filePath.extension() != ".txt") throw std::invalid_argument("Err! File have wrong extension! Check if this file is .txt");
    if(filePath.has_root_name()) return filePath;
    return filePath = (fs::path)toMakeCorrectPath.append(source);
};