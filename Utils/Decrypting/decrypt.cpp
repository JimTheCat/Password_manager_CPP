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

#include "decrypt.h"

/**
 * Decrypting text
 * @param Combine - string to decrypt
 * @return decrypted string
 */
std::string decrypt(const std::string &Combine) {
    std::string password;
    int counter = 1;

    int key = 122 - Combine[0];

    for(auto Letter : Combine){
        if(counter % 2 == 0){
            password.push_back((Letter + key) % 94 + 33);
        }
        counter++;
    }

    return password;
}

/**
 * Fake decrypting text
 * @param Combine - string to decrypt
 * @return wrong decrypted string
 */
std::string wrongDecrypt(std::string const &Combine){
    std::string password;
    int counter = 1;

    int key = 128 - Combine[0];

    for(auto Letter : Combine){
        if(counter % 2 == 1){
            password.push_back((Letter + key) % 94 + 33);
        }
        counter++;
    }

    return password;
}
