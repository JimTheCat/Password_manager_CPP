//
// Created by Jimmy on 27.05.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_TIMESTAMP_H
#define PROJECT_PASSWORD_MANAGER_TIMESTAMP_H

#include <iostream>
#include <vector>

struct timestamp {
    static std::string randomTS();
    static std::string realTS();

    static void decryptTS(std::vector<std::vector<std::string>> vec);
};


#endif //PROJECT_PASSWORD_MANAGER_TIMESTAMP_H
