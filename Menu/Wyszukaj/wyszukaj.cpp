//
// Created by Jimmy on 27.05.2022.
//

#include "wyszukaj.h"
#include <iostream>
#include <vector>

void wyszukaj::searchPassword(std::vector<std::vector<std::string>> vec) {
    std::string pattern;
    bool passwordFounded = false;
    std::cout << std::string( 50, '\n' );
    std::cout << "Wpisz szukane haslo: " << std::endl;
    std::cin >> pattern;
    for (auto & i : vec){
        if (std::equal(pattern.begin(), pattern.end(), i[0].begin(), i[0].end())){
            std::cout << "Found matching password!" << std::endl;
            for (auto & j : i){
                std::cout << j;
            }
            passwordFounded = true;
            std::cout << std::endl;
        }
    }
    if (!passwordFounded) std::cout << "There is not matching passowrd!" << std::endl;
}