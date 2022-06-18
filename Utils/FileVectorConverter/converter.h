//
// Created by Jimmy on 24.05.2022.
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

#ifndef PROJECT_PASSWORD_MANAGER_CONVERTER_H
#define PROJECT_PASSWORD_MANAGER_CONVERTER_H

#include <iostream>
#include <vector>
#include <filesystem>

namespace fs=std::filesystem;

class converter {
public:
    static std::vector<std::vector<std::string>> fileToVector(const fs::path& convertedPath, bool isGoodPassword);
    static void vectorToFile(std::vector<std::vector<std::string>> &vectorToSave, const std::filesystem::path& pathToFile);
};


#endif //PROJECT_PASSWORD_MANAGER_CONVERTER_H
