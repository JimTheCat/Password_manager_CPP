//
// Created by Jimmy on 03.06.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_SEARCHINGPASSWORD_H
#define PROJECT_PASSWORD_MANAGER_SEARCHINGPASSWORD_H
#include <vector>
#include <iostream>


class searchingPassword {
public:
    static void searchPassword(std::vector<std::vector<std::string>> &vec);
protected:
    static void showAllPasswords(std::vector<std::vector<std::string>> &vec);

    void showCurrentPasswords(std::vector<std::vector<std::string>> vec);
};


#endif //PROJECT_PASSWORD_MANAGER_SEARCHINGPASSWORD_H
