//
// Created by Jimmy on 03.06.2022.
//

#ifndef PROJECT_PASSWORD_MANAGER_SORT_H
#define PROJECT_PASSWORD_MANAGER_SORT_H
#include <iostream>
#include <vector>

class sort {
public:
    static void sorting(std::vector<std::vector<std::string>> &vec, bool b);
protected:
    static bool compareByFirstAndSecondParameter(const int firstIndex, const int secondIndex, std::vector<std::vector<std::string>>& vec);
};


#endif //PROJECT_PASSWORD_MANAGER_SORT_H
