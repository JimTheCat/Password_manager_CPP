//
// Created by Jimmy on 24.05.2022.
//

#include <fstream>
#include "converter.h"
#include "../Decrypting/decrypt.h"

std::vector<std::vector<std::string>> converter::fileToVector(fs::path convertedPath, bool isGoodPassword) {
    int numberOfColumns = 6;
    std::vector<std::vector<std::string>> vectorToReturn;
    std::string fileData;
    std::ifstream readFile(convertedPath);
    std::string separator = " ";

    while (std::getline(readFile, fileData)){
        std::vector<std::string> vectorOfLines;
        std::string result;
        for (int i = 0; i < numberOfColumns - 1; i++){
            result = fileData.substr(0, fileData.find(separator));
            result = isGoodPassword ? decrypt(result) : wrongDecrypt(result);
            vectorOfLines.push_back(result);
            fileData.erase(0, fileData.find(separator) + 1);
        }
        result = fileData.substr(0, fileData.find(separator));
        vectorOfLines.push_back(result);

        vectorToReturn.push_back(vectorOfLines);
    }
    return vectorToReturn;
}

void converter::vectorToFile(std::vector<std::vector<std::string>> vectorToSave) {

}
