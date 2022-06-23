//
// Created by Jimmy on 23.04.2022.
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

#include "encrypt.h"

/**
 * Encrypt text
 * @param Combine - string to encrypt
 * @return encrypted string
 */
std::string encrypt::encryptText(std::string const &Combine){

    std::string hash;
    hash.push_back(rand() % 94 + 33);

    int key = hash[0];

    for (auto Letter : Combine){
        hash.push_back((Letter + key) % 94 + 33);
        hash.push_back(rand() % 94 + 33);
    }
    return hash;
}