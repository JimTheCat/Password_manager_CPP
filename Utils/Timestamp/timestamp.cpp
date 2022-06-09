//
// Created by Jimmy on 27.05.2022.
//

#include "timestamp.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <zconf.h>

/**
 * Generate decrypted fake timestamp
 * @return decrypted timestamp
 */
std::string timestamp::randomTS() {
    std::string numberToReturn;
    for (int i = 0; i < realTS().length(); i++){
        numberToReturn += std::to_string(rand()%10);
    }
    return numberToReturn;
}

/**
 * Generate decrypted timestamp
 * @return decrypted timestamp
 */
std::string timestamp::realTS() {
    std::string TS = std::to_string((int) time(nullptr));
    int index = 0;
    std::string tsToReturn;
    for (int i = 0; i < TS.length()*2; i++){
        if (i%2 == 1) tsToReturn += std::to_string(rand() % 10);
        else {
            tsToReturn += TS[index];
            index++;
        }
    }
    return tsToReturn;
}

void timestamp::decryptTS(std::vector<std::vector<std::string>> vec){
    std::string result;
    for (int i = 0; i < realTS().size(); i++) {
        if (i % 2 == 0) result += vec[0][5][i];
    }
    std::cout << "Timestamp: " << result << std::endl;
    sleep(1);
}