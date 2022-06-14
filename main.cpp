#include <iostream>
#include <fstream>
#include "Utils/Auth/auth.h"
#include "Utils/Seed/seed.h"
#include "Menu/FilePath/filePath.h"
#include "Utils/FileVectorConverter/converter.h"
#include "Menu/Design/menu.h"
#include "Utils/Timestamp/timestamp.h"

using std::cout, std::endl, std::string, std::vector;

/**
 * Main function. There is the origin of the program.
 * @return exit of program without errors
 */
int main() {
    vector<vector<string>> vectorTestowy;
    string filePath;
    string password;
    string fileData;
    char endAnswer = 'n';
    std::filesystem::path pathToFile;
    nlohmann::json jd;
    std::ifstream i(R"(..\categories.json)");
    i >> jd;
    cout << jd["categories"][0].get<string>() << endl;
    i.close();
    /*
     * HASŁO DO PROGRAMU TO: trudneHaslo123
     */
//    string testaa = encrypt("Ziemniaki");
//    string test2 = encrypt("TrudneBardzoHaslo*2137");
//    cout << "START" << endl << testaa << endl << "END" << endl << decrypt(testaa) << endl;
//    cout << "START" << endl << testaa << endl << "END" << endl << wrongDecrypt(testaa) << endl;
//    cout << "START" << endl << test2 << endl << "END" << endl << decrypt(test2) << endl;
//    cout << "START" << endl << test2 << endl << "END" << endl << wrongDecrypt(test2) << endl;
//
//    cout << auth::checkPassword("BardzoTrudneHaslo*2137") << endl;
//
//    cout << "-------------------" << endl;
//
//    std::string test = "assss 322 aaaa";
//    std::string separator = " ";
//    std::string result = test.substr(0 , test.find(separator));
//    test.erase(0, test.find(separator) + 1);
//    result = test.substr(0 , test.find(separator));
//
//    cout << result << endl;
//    cin >> password;
//    srand(seed::generateSeed(password));
    cout << "=-=-=-=END OF TESTS!=-=-=-=" << endl;
//    cout << encrypt(password) << endl;
    while (endAnswer != 't') {
        char answer = 'n';
        cout << "Witaj w Password Managerze! \nProsze wpisz haslo by odszyfrowac twoje dane!: " << endl;
        std::cin >> password;
        srand(seed::generateSeed(password));
        try {
            while (answer != 't') {
                cout << "Wpisz sciezke do pliku ktory chcesz odszyfrowac: " << endl;
                std::cin >> filePath;
                pathToFile = filePathRequest(filePath);
                vectorTestowy = converter::fileToVector(pathToFile, auth::checkPassword(password));
                if (vectorTestowy.empty()) cout << "Timestamp bedzie przydzielony gdy dodasz haslo" << endl;
                else timestamp::decryptTS(vectorTestowy);
                menu::generateMenu(vectorTestowy, auth::checkPassword(password), jd, pathToFile);
                cout << "Czy chcesz zakonczyc dzialanie programu na tym pliku? [t/n]: " << endl;
                std::cin >> answer;
            }
        } catch (std::invalid_argument &e) {
            std::cerr << e.what() << endl;
            return -1;
        }
        cout << "Czy chcesz zakonczyc dzialanie programu? [t/n]: " << endl;
        std::cin >> endAnswer;
    }
    return 0;
}
