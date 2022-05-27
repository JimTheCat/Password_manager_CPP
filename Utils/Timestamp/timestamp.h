//
// Created by Jimmy on 27.05.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_TIMESTAMP_H
#define PROJECT_PASSWORD_MANAGER_TIMESTAMP_H

#include <iostream>

struct timestamp {
    static std::string randomTS();
    static std::string realTS();
};


#endif //PROJECT_PASSWORD_MANAGER_TIMESTAMP_H
