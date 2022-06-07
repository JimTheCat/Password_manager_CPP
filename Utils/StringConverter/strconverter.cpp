//
// Created by Jimmy on 07.06.2022.
//

#include "strconverter.h"

/**
 * Changing every spaces in string to underscore
 * @param stringToConvert - string taken from user
 * @return String with replaced spaces to underscore
 */
std::string strconverter::replaceSpaceToUnderscore(std::string &stringToConvert) {
    int startPosition = 0;
    const static std::string from = " ";
    const static std::string to = "_";

    while((startPosition = stringToConvert.find(from, startPosition)) != std::string::npos){
        stringToConvert.replace(startPosition, from.length(), to);
        startPosition += to.length();
    }
    return stringToConvert;
}
