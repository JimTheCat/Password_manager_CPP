//
// Created by Jimmy on 24.04.2022.
//

#include "auth.h"
#include "../DecryptPassword/decryptPassword.h"
#include <iostream>

bool auth::checkPassword(std::string password) {
    ///TODO: Change from static to dynamic checking
    return password == decryptPassword("IKCj~{$ma#lxV]n{r~pmIw1nQQ;ji|+u3xF3;;\\:G<,@^");
}
