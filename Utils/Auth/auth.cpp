//
// Created by Jimmy on 24.04.2022.
//

#include "auth.h"
#include "../Decrypting/decrypt.h"
#include <iostream>

bool auth::checkPassword(std::string password) {
    ///TODO: Change from static to dynamic checking
    return password == decrypt("iB:@HCo2m<j3rt!/ZAP:<=v]7^[_@");
}

