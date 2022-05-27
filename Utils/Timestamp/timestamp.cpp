//
// Created by Jimmy on 27.05.2022.
//

#include "timestamp.h"
#include <iostream>
#include <ctime>

std::string timestamp::randomTS() {
    std::string numberToReturn;
    for (int i = 0; i < realTS().length(); i++){
        numberToReturn += std::to_string(rand()%10);
    }
    return numberToReturn;
}

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
