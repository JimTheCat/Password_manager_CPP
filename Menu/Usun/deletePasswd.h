//
// Created by Jimmy on 03.06.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_DELETEPASSWD_H
#define PROJECT_PASSWORD_MANAGER_DELETEPASSWD_H
#include <iostream>
#include <vector>

class deletePasswd {
public:
    static void deletePassword(std::vector<std::vector<std::string>> &vec, bool isGoodPassword);
};


#endif //PROJECT_PASSWORD_MANAGER_DELETEPASSWD_H
