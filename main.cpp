#include <iostream>
#include "Utils/Encrypting/encrypt.h"
#include "Utils/Decrypting/decrypt.h"
#include "Utils/Auth/auth.h"
#include "Utils/Seed/seed.h"
#include "Menu/FilePath/filePath.h"
#include "Utils/FileVectorConverter/converter.h"
#include <ctime>

using namespace std;

int main() {
    string filePath;
    string password;

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

    cout << "=-=-=-=END OF TESTS!=-=-=-=" << endl;

    cout << "Witaj w Password Managerze! \nProsze wpisz haslo by odszyfrowac twoje dane!: " << endl;
    cin >> password;
    srand(seed::generateSeed(password));
    cout << "Wpisz sciezke do pliku ktory chcesz odszyfrowac: " << endl;
    cin >> filePath;
    vector<vector<string>> vectorTestowy;
    try {
        vectorTestowy = converter::fileToVector(filePathRequest(filePath), auth::checkPassword(password));
    }catch (invalid_argument& e){
        cerr << e.what() << endl;
        return -1;
    }

    for(auto & i : vectorTestowy){
        for(int j = 0; j < 6; j++){
            cout << i[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
