//
// Created by Jimmy on 28.04.2022.
//

#include "seed.h"

/**
 * Generating seed
 * @param Password - password taken from user
 * @return Seed for srand usage
 */
int seed::generateSeed(std::string &Password) {
    int result = 0;
    for (char index : Password){
        result += index;
    }
    std::cout << result << std::endl;
    return result;
}
