//
// Created by Jimmy on 23.04.2022.
//

#include "encrypt.h"

/**
 * Encrypting text
 * @param Combine - string to ecrypt
 * @return encrypted string
 */
std::string encrypt(std::string const &Combine){

    std::string hash;
    hash.push_back(rand() % 94 + 33);

    int key = hash[0];

    for (auto Letter : Combine){
        hash.push_back((Letter + key) % 94 + 33);
        hash.push_back(rand() % 94 + 33);
    }
    return hash;
}