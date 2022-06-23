//
// Created by Jimmy on 24.04.2022.
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

#include "auth.h"
#include "../Decrypting/decrypt.h"
#include <iostream>

/**
 * Check the password if it's correct.
 * @param password - password given by user
 * @return true if password is correct, otherwise false
 */
bool auth::checkPassword(const std::string& password) {
    return password == decrypt("iB:@HCo2m<j3rt!/ZAP:<=v]7^[_@");
}

