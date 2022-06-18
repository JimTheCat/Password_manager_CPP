//
// Created by Jimmy on 27.05.2022.
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

#ifndef PROJECT_PASSWORD_MANAGER_TIMESTAMP_H
#define PROJECT_PASSWORD_MANAGER_TIMESTAMP_H

#include <iostream>
#include <vector>

class timestamp {
public:
    static std::string randomTS();
    static std::string realTS();
    static void formatedTS(std::vector<std::vector<std::string>>& vec);
};


#endif //PROJECT_PASSWORD_MANAGER_TIMESTAMP_H
