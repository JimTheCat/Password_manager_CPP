//
// Created by Jimmy on 03.06.2022.
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

#ifndef PROJECT_PASSWORD_MANAGER_DELETEPASSWD_H
#define PROJECT_PASSWORD_MANAGER_DELETEPASSWD_H
#include <iostream>
#include <vector>

class deletePasswd {
public:
    static void deletePassword(std::vector<std::vector<std::string>> &vec, bool isGoodPassword);
    static void singlePassword(std::vector<std::vector<std::string>> &vec);
    static void parametersPassword(std::vector<std::vector<std::string>> &vec);
};


#endif //PROJECT_PASSWORD_MANAGER_DELETEPASSWD_H
