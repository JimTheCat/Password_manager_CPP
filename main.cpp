#include <iostream>
#include <fstream>
#include "Utils/Encrypting/encrypt.h"
#include "Utils/Decrypting/decrypt.h"
#include "Utils/Auth/auth.h"
#include "Utils/Seed/seed.h"
#include "Menu/FilePath/filePath.h"
#include "Utils/FileVectorConverter/converter.h"
#include "Menu/Design/menu.h"
#include "Utils/Timestamp/timestamp.h"
#include "Lib/single_include/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
    vector<vector<string>> vectorTestowy;
    string filePath;
    string password;
    string fileData;
    std::filesystem::path pathToFile;
    char answer = 'n';
    json jd;
    ifstream i(R"(C:\Users\Jimmy\Desktop\PJC\Project_password_manager\categories.json)");
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
    cout << "Witaj w Password Managerze! \nProsze wpisz haslo by odszyfrowac twoje dane!: " << endl;
    cin >> password;
    srand(seed::generateSeed(password));
    try {
        while (answer != 't') {
            cout << "Wpisz sciezke do pliku ktory chcesz odszyfrowac: " << endl;
            cin >> filePath;
            pathToFile = filePathRequest(filePath);
            vectorTestowy = converter::fileToVector(pathToFile, auth::checkPassword(password));
            if (vectorTestowy.empty()) cout << "Timestamp bedzie przydzielony gdy dodasz haslo" << endl;
            else timestamp::decryptTS(vectorTestowy);
            menu::generateMenu(vectorTestowy, auth::checkPassword(password), jd, pathToFile);
            cout << "Czy chcesz zakonczyc dzialanie programu? [t/n]: " << endl;
            cin >> answer;
        }
    }catch (invalid_argument& e){
        cerr << e.what() << endl;
        return -1;
    }


    return 0;
}
