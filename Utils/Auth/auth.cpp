//
// Created by Jimmy on 24.04.2022.
//

#include "auth.h"
#include "../DecryptPassword/decryptPassword.h"
#include "../EncryptPassword/encryptPassword.h"
#include <iostream>

bool auth::checkPassword(std::string password) {
    ///TODO: Change from static to dynamic checking
    std::cout << password << " " << decryptPassword("W↓V8^II;hQhFu+@I~L{;CEc<&▼g8qJ:C_Fe☺=   h") << std::endl;
    return password == decryptPassword(hashPassword("BardzoTrudneHaslo*2137"));
}