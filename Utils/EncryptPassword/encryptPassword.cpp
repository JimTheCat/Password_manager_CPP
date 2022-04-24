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
    hash.push_back(rand() % 128);

    int key = hash[0];

//    std::cout << key << " " << std::endl;

    for (auto Letter : Combine){
//        if (Letter + key > 126)
//            hash.push_back(32 + ((Letter + key) - 126));
//        else
//            hash.push_back(Letter + key);

        hash.push_back((Letter + key) % 128);
        hash.push_back(rand() % 128);
    }
    return hash;
}