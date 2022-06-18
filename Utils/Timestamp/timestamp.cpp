//
// Created by Jimmy on 27.05.2022.
//
/*
    Ta aplikacja została napisana przez Patryka Kłosińskiego.
    Jeśli chcesz wykorzystać ten kod proszę o nie usuwanie tego komentarza!
    Bardzo dziękuje!
    ---------------------------------------------------------------------------
    This app was written by Patryk Kłosiński.
    If you want to use this code please don't delete this comment!
    Thank you very much!
    ---------------------------------------------------------------------------
    GitHub: https://github.com/JimTheCat
    E-Mail: klosinski.patryk2137@gmail.com
 */

#include "timestamp.h"
#include <iostream>
#include <ctime>
#include <vector>

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
/**
 * Display stylish timestamp
 * @param vec - vector with encoded passwords
 */
void timestamp::formatedTS(std::vector<std::vector<std::string>>& vec){
    struct tm * ptm;
    std::string timeStamp;
    std::string result;
    result.resize(40);
    for (int i = 0; i < realTS().size(); i++) {
        if (i % 2 == 0) timeStamp += vec[0][5][i];
    }
    time_t time1 = std::stoi(timeStamp);
    ptm = localtime(&time1);
    strftime(&result[0], 40, "Ostatni timestamp: %x %X", ptm);
    std::cout << result << std::endl;
}