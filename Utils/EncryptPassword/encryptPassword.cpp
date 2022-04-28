//
// Created by Jimmy on 23.04.2022.
//

#include "encryptPassword.h"

/**
 *
 * @param Combine; element to encrypt
 * @return encrypted element
 */
std::string hashPassword(std::string const &Combine){

    std::string hash;
    hash.push_back(rand() % 96 + 32);

    int key = hash[0];

    for (auto Letter : Combine){
        hash.push_back((Letter + key) % 96 + 32);
        hash.push_back(rand() % 96 + 32);
    }
    return hash;
}