//
// Created by Jimmy on 03.06.2022.
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

#include <algorithm>
#include "sort.h"

/**
 * Sort passwords by parameters
 * @param vec - vector filled with decrypted passwords
 * @param isGoodPassword - true if password is correct, otherwise false
 */
void sort::sorting(std::vector<std::vector<std::string>> &vec, bool isGoodPassword) {
    if (!isGoodPassword) std::cerr << "void sorting(): Blad! Opcja niedostepna przez niepoprawne haslo do programu" << std::endl;
    else if (vec.empty()) std::cerr << "void sorting(): Nie mozna posortowac hasel poniewaz nie znaleziono zadnego!" << std::endl;
    else {
        int choice = 0;
        int index = 1;
        std::string nameOfColumns[] = {"Haslo", "Nazwa", "Kategoria", "Strona_WWW", "Login"};

        std::cout << "Co dokladnie chcesz zrobic?: " << std::endl;
        std::cout << "[1] Sortuj po jednym parametrze" << std::endl;
        std::cout << "[2] Sortuj po dwoch parametrach" << std::endl;
        std::cin >> choice;
        for (const auto &i: nameOfColumns) {
            std::cout << index++ << ". " << i << std::endl;
        }
        switch (choice) {
            case 1: {
                int parameter;
                std::cout << "Wybierz parametr z listy: " << std::endl;
                std::cin >> parameter;
                parameter--;
                std::sort(vec.begin(), vec.end(),
                          [parameter](const std::vector<std::string> &a, const std::vector<std::string> &b) {
                              return a[parameter] < b[parameter];
                          });
                std::cout << "Sortowanie po parametrze przeszlo pomyslnie!" << std::endl;
                break;
            }
            case 2: {
                int firstParameter;
                int secondParameter;
                std::cout << "Wybierz pierwszy parametr z listy: " << std::endl;
                std::cin >> firstParameter;
                std::cout << "Wybierz drugi parametr z listy: " << std::endl;
                std::cin >> secondParameter;
                firstParameter--;
                secondParameter--;
                std::sort(vec.begin(), vec.end(), [firstParameter, secondParameter](const std::vector<std::string> &a,
                                                                                    const std::vector<std::string> &b) {
                    if (a[firstParameter] != b[firstParameter])
                        return a[firstParameter] < b[firstParameter];
                    return a[secondParameter] < b[secondParameter];
                });
                std::cout << "Sortowanie po dwoch parametrach przeszlo pomyslnie!" << std::endl;
                break;
            }
            default:
                std::cerr << "void sorting(): Podano nieprawidlowy argument!" << std::endl;
        }

        std::cin.ignore();
        std::cout << "Nacisnij ENTER by kontynuowac" << std::endl;
        std::cin.get();
    }
}
