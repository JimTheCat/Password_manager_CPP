//
// Created by Jimmy on 23.04.2022.
//

#include "decryptPassword.h"

/**
 *
 * @param Combine
 * @return
 */
std::string decryptPassword(std::string const &Combine){

    std::string password;
    int counter = 1;

    int key = 128 - Combine[0];

    for(auto Letter : Combine){
        if(counter % 2 == 0){
            password.push_back((Letter + key) % 96 + 32);
        }
        counter++;
    }

    return password;
}
