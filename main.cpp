#include <iostream>
#include <fstream>
#include "single_include/nlohmann/json.hpp"
#include "Utils/Encrypting/encrypt.h"
#include "Utils/Decrypting/decrypt.h"
#include "Utils/Auth/auth.h"
#include "Utils/Seed/seed.h"
#include "Menu/FilePath/filePath.h"
#include "Utils/FileVectorConverter/converter.h"
#include "Menu/Design/menu.h"
#include "Utils/Timestamp/timestamp.h"

using namespace std;
using json = nlohmann::json;

int main() {
    string filePath;
    string password;
    string fileData;
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
//
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
    cin >> password;
    srand(seed::generateSeed(password));
    cout << encrypt("hasloDoGoogla123") << endl;
    cout << encrypt("Google_Account") << endl;
    cout << encrypt("Internet") << endl;
    cout << encrypt("www.google.com") << endl;
    cout << encrypt("-") << endl;
    cout << timestamp::realTS() << endl;
//    cout << timestamp::randomTS() << endl;
    cout << "=-=-=-=END OF TESTS!=-=-=-=" << endl;
//    cout << encrypt(password) << endl;
//    cout << "Witaj w Password Managerze! \nProsze wpisz haslo by odszyfrowac twoje dane!: " << endl;
//    cin >> password;
//    srand(seed::generateSeed(password));
    cout << "Wpisz sciezke do pliku ktory chcesz odszyfrowac: " << endl;
    cin >> filePath;
    vector<vector<string>> vectorTestowy;
    try {
        vectorTestowy = converter::fileToVector(filePathRequest(filePath), auth::checkPassword(password));
        menu::generateMenu(vectorTestowy);
    }catch (invalid_argument& e){
        cerr << e.what() << endl;
        return -1;
    }
    cout << auth::checkPassword(password) << endl;
    cout << vectorTestowy [0][0] << endl;
    cout << vectorTestowy [0][1] << endl;
    cout << vectorTestowy [0][2] << endl;
    cout << vectorTestowy [0][3] << endl;
    cout << vectorTestowy [0][4] << endl;
    cout << vectorTestowy [0][5] << endl;

    return 0;
}
