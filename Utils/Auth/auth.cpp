//
// Created by Jimmy on 24.04.2022.
//

#include "auth.h"
#include "../Decrypting/decrypt.h"
#include <iostream>

/**
 * Checking the password if it's correct.
 * @param password - password taken from user
 * @return true if password is correct, otherwise false
 */
bool auth::checkPassword(const std::string& password) {
    return password == decrypt("iB:@HCo2m<j3rt!/ZAP:<=v]7^[_@");
}

