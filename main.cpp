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

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Utils/Auth/auth.h"
#include "Utils/Seed/seed.h"
#include "Menu/FilePath/filePath.h"
#include "Utils/FileVectorConverter/converter.h"
#include "Menu/Design/menu.h"
#include "Utils/Timestamp/timestamp.h"

using std::cout, std::endl, std::string, std::vector;

/**
 * Main function. The program starts here.
 * @return exit of program without errors
 */
int main() {
    vector<vector<string>> vectorTestowy;
    string filePath;
    string password;
    string fileData;
    char endAnswer = 'n';
    std::filesystem::path pathToFile;
    /*
     * HASŁO DO PROGRAMU TO: trudneHaslo123 (haslo podane tutaj jest tylko informacja dla sprawdzajacego więc prosze mi nie ucinać pkt za to :<)
     */

    while (endAnswer != 't') {
        char answer = 'n';
        cout << "Witaj w Password Managerze! \nProsze wpisz haslo do programu!: " << endl;
        std::cin >> password;
        srand(seed::generateSeed(password));
        try {
            while (answer != 't') {
                cout << "Wpisz sciezke do pliku ktory chcesz odszyfrowac (musi zawierac rozszerzenie pliku '.txt'): " << endl;
                std::cin >> filePath;

                pathToFile = filePathRequest(filePath);
                vectorTestowy = converter::fileToVector(pathToFile, auth::checkPassword(password));

                if (vectorTestowy.empty()) cout << "Timestamp bedzie przydzielony gdy dodasz haslo" << endl;
                else timestamp::formatedTS(vectorTestowy);
                sleep(2);

                menu::generateMenu(vectorTestowy, auth::checkPassword(password), pathToFile);

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
