//
// Created by Jimmy on 24.05.2022.
//

#include <fstream>
#include <iterator>
#include "converter.h"
#include "../Decrypting/decrypt.h"
#include "../Timestamp/timestamp.h"
#include "../Encrypting/encrypt.h"

/**
 * Saving data from file to vector
 * @param convertedPath - path to file
 * @param isGoodPassword - information about the correct password
 * @return filled vector with data
 */
std::vector<std::vector<std::string>> converter::fileToVector(fs::path convertedPath, bool isGoodPassword) {
    int numberOfColumns = 6;
    std::vector<std::vector<std::string>> vectorToReturn;
    std::string fileData;
    std::ifstream readFile(convertedPath);
    std::string separator = " ";
    std::string timestamp;
    bool firstLine = true;

    if (convertedPath.empty()) return vectorToReturn;

    while (std::getline(readFile, fileData)){
        std::vector<std::string> vectorOfLines;
        std::string result;
        for (int i = 0; i < numberOfColumns - 1; i++){
            result = fileData.substr(0, fileData.find(separator));
            result = isGoodPassword ? decrypt(result) : wrongDecrypt(result);
            vectorOfLines.push_back(result);
            fileData.erase(0, fileData.find(separator) + 1);
        }
        if (firstLine) {
            vectorOfLines.push_back(timestamp::realTS());
            firstLine = false;
        } else vectorOfLines.push_back(timestamp::randomTS());
        vectorToReturn.push_back(vectorOfLines);
    }
    return vectorToReturn;
}

/**
 * Saving data from vector to file
 * @param vectorToSave - vector with stored data
 * @param pathToFile - path to output file
 */
void converter::vectorToFile(std::vector<std::vector<std::string>> &vectorToSave, const std::filesystem::path& pathToFile) {
    std::fstream ofs;
    bool firstLine = true;

    ofs.open(pathToFile, std::ios_base::out);

    for (auto & i : vectorToSave){
        for (int j = 0; j < i.at(0).size() - 1; j++){
            ofs << encrypt(i[j]) << " ";
        }
        firstLine ? i.push_back(timestamp::realTS()) : i.push_back(timestamp::randomTS());
        ofs << i[i.at(0).size() - 1];
        ofs << "\n";
        firstLine = false;
    }

    ofs.close();
}
