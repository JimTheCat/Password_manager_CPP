//
// Created by Jimmy on 28.04.2022.
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

#include "seed.h"

/**
 * Generating seed
 * @param Password - password taken from user
 * @return Seed for srand usage
 */
int seed::generateSeed(std::string &Password) {
    int result = 0;
    for (char index : Password){
        result += index;
    }
    return result;
}
