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

#ifndef PROJECT_PASSWORD_MANAGER_FILEPATH_H
#define PROJECT_PASSWORD_MANAGER_FILEPATH_H
#include <iostream>
#include <filesystem>

namespace fs=std::filesystem;

fs::path filePathRequest(const std::string& source);

#endif //PROJECT_PASSWORD_MANAGER_FILEPATH_H
