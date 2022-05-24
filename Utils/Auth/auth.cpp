//
// Created by Jimmy on 24.04.2022.
//

#include "auth.h"
#include "../Decrypting/decrypt.h"
#include <iostream>

bool auth::checkPassword(std::string password) {
    ///TODO: Change from static to dynamic checking
    return password == decrypt("f:9'^0C4g+6.i'~9`2F5#WQXdY#");
}

