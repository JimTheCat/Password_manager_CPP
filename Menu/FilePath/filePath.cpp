//
// Created by Patryk on 07.05.2022.
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

#include "filePath.h"
#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs=std::filesystem;

/**
 * Check if path is correct
 * @param source - raw path
 * @return corrected path
 */
fs::path filePathRequest(const std::string& source){
    fs::path filePath(source);
    std::string toMakeCorrectPath = "../";
    if (filePath.extension() != ".txt") throw std::invalid_argument("fs::path filePathRequest(): Blad! Sprawdz czy nazwa pliku zawiera rozszerzenie '.txt'");
    if(!filePath.has_root_name()) filePath = (fs::path) toMakeCorrectPath.append(source);
    if (!exists(filePath)){
        std::cout << "Podana sciezka pliku nie isnieje! Tworze nowy plik w podanej lokalizacji!" << std::endl;
        std::ofstream newFile(filePath);
        newFile.close();
    }
    return filePath;
}