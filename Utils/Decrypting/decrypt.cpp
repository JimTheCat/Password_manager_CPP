//
// Created by Jimmy on 23.04.2022.
//

#include "decrypt.h"

/**
 * Decrypting text
 * @param Combine - string to decrypt
 * @return decrypted string
 */
std::string decrypt(const std::string &Combine) {
    std::string password;
    int counter = 1;

    int key = 122 - Combine[0];

    for(auto Letter : Combine){
        if(counter % 2 == 0){
            password.push_back((Letter + key) % 94 + 33);
        }
        counter++;
    }

    return password;
}

/**
 * Fake decrypting text
 * @param Combine - string to decrypt
 * @return wrong decrypted string
 */
std::string wrongDecrypt(std::string const &Combine){
    std::string password;
    int counter = 1;

    int key = 128 - Combine[0];

    for(auto Letter : Combine){
        if(counter % 2 == 1){
            password.push_back((Letter + key) % 94 + 33);
        }
        counter++;
    }

    return password;
}
