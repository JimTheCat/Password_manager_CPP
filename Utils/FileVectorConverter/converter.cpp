//
// Created by Jimmy on 24.05.2022.
//

#include <fstream>
#include <iterator>
#include "converter.h"
#include "../Decrypting/decrypt.h"
#include "../Timestamp/timestamp.h"

std::vector<std::vector<std::string>> converter::fileToVector(fs::path convertedPath, bool isGoodPassword) {
    int numberOfColumns = 6;
    std::vector<std::vector<std::string>> vectorToReturn;
    std::string fileData;
    std::ifstream readFile(convertedPath);
    std::string separator = " ";
    std::string timestamp;
    bool firstLine = true;

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

void converter::vectorToFile(std::vector<std::vector<std::string>> &vectorToSave, std::filesystem::path pathToFile) {
    std::fstream ofs;
//    std::copy(vectorToSave.begin(), vectorToSave.end(), std::ostream_iterator<std::string>(ofs, " "));
    ofs.open(pathToFile, std::ios_base::out);

    for (auto & i : vectorToSave){
        for (auto & j : i){
            ofs << j << " ";
        }
        ofs << "\n";
    }
    ofs.close();
}
