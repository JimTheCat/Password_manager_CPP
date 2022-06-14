//
// Created by Jimmy on 27.05.2022.
//

#include "addPasswd.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "../../Utils/Decrypting/decrypt.h"

void addPasswd::addPassword(std::vector<std::vector<std::string>> &vec, bool isGoodPassword, nlohmann::json j) {
    if (!isGoodPassword) std::cerr << "Password is wrong! This option is not available!" << std::endl;
    else {
        char answer;
        std::string textToPush;
        bool didFoundCategory = false;
        bool isNameUnique = false;
        std::vector<std::string> passwordToPush;

        std::cout << "Czy chcesz randomowe haslo? [t/n]: " << std::endl;
        std::cin >> answer;
        if (answer == 't') textToPush = generatePassword();
        else if (answer == 'n') {
            std::cout << "Podaj haslo: " << std::endl;
            std::cin >> textToPush;
            addPasswd::checkingStrengthOfPassword(textToPush);
        }
        passwordToPush.push_back(textToPush);
        std::cout << "Podaj nazwe: " << std::endl;
        while (!isNameUnique) {
            std::cin >> textToPush;
            isNameUnique = checkingUniqueOfName(textToPush, vec);
            if (!isNameUnique) std::cout << "Nazwa juz wystapila w innym hasle! Wprowadz inna nazwe: " << std::endl;
            else passwordToPush.push_back(textToPush);
        }
        std::cout << "Podaj kategorie: " << std::endl;
        addPasswd::showCategories();
        std::cin >> textToPush;
        for (const auto& i: j["categories"]) {
            if (!decrypt(i.get<std::string>()).compare(textToPush)) {
                passwordToPush.push_back(textToPush);
                didFoundCategory = true;
            }
        }
        if (!didFoundCategory) throw std::invalid_argument("Nie ma takiej kategorii");
        std::cout << "Podaj Strone WWW (opcjonalne): " << std::endl;
        std::cin >> textToPush;
        if (textToPush.empty() || !textToPush.compare("\n")) passwordToPush.emplace_back("-");
        else passwordToPush.push_back(textToPush);

        std::cout << "Podaj Login (opcjonalne): " << std::endl;
        std::cin >> textToPush;
        if (textToPush.empty()) passwordToPush.emplace_back("-");
        else passwordToPush.push_back(textToPush);

        vec.push_back(passwordToPush);
    }
}

std::string addPasswd::generatePassword() {
    char answer;
    int lengthOfPassword;
    bool isUpperCase;
    bool specialLetters;

    std::cout << "Jak dlugie ma byc twoje haslo?: " << std::endl;
    std::cin >> lengthOfPassword;
    std::cout << "Czy ma zawierac duze i male litery? (t/n): " << std::endl;
    std::cin >> answer;
    if (answer == 't') isUpperCase = true;
    else if (answer == 'n') isUpperCase = false;
    else throw std::invalid_argument("generatePassword(): Nie poprawny znak!");
    std::cout << "Czy ma zawierac znaki specjalne? (t/n): " << std::endl;
    std::cin >> answer;
    if (answer == 't') specialLetters = true;
    else if (answer == 'n') specialLetters = false;
    else throw std::invalid_argument("generatePassword(): Nie poprawny znak!");
    return generatedPasswordToReturn(lengthOfPassword, isUpperCase, specialLetters);
}

std::string addPasswd::generatedPasswordToReturn(int lengthOfPassword, bool isUpperCase, bool specialLetters) {
    static const char arrOfNumbers[] = "0123456789";
    static const char arrOfSmallLetters[] = "abcdefghijklmnopqrstuwvxyz";
    static const char arrOfSpecialLetters[] = "!@#$%^&*()";
    static const char arrOfBigLetters[] = "ABCDEFGHIJKLMNOPQRSTUWVXYZ";
    std::string generatedPasswordToReturn;

    for (int i = 0; i < lengthOfPassword; i++) {
        switch (rand() % 4 + 1) {
            case 1:
                generatedPasswordToReturn += arrOfNumbers[rand() % (sizeof(arrOfNumbers) - 1)];
                break;
            case 2:
                generatedPasswordToReturn += arrOfSmallLetters[rand() % (sizeof(arrOfSmallLetters) - 1)];
                break;
            case 3: {
                if (specialLetters)
                    generatedPasswordToReturn += arrOfSpecialLetters[rand() % (sizeof(arrOfSpecialLetters) - 1)];
                else generatedPasswordToReturn += arrOfNumbers[rand() % (sizeof(arrOfNumbers) - 1)];
                break;
            }
            case 4: {
                if (isUpperCase) generatedPasswordToReturn += arrOfBigLetters[rand() % (sizeof(arrOfBigLetters) - 1)];
                else generatedPasswordToReturn += arrOfSmallLetters[rand() % (sizeof(arrOfSmallLetters) - 1)];
                break;
            }
        }
    }

    std::cout << "Twoje haslo to: " << generatedPasswordToReturn << std::endl;
    return generatedPasswordToReturn;
}

void addPasswd::showCategories() {
    nlohmann::json j;
    std::ifstream i("../categories.json");
    i >> j;

    std::cout << "Oto lista dostepnych kategorii: " << std::endl;
    for (const auto &k: j["categories"]) {
        std::cout << decrypt(k.get<std::string>()) << std::endl;
    }
}

void addPasswd::checkingStrengthOfPassword(const std::string &passwordToCheck) {

    const static std::string specialLetters = "!@#$%^&*()";

    bool containSpecialLetters = std::any_of(passwordToCheck.begin(), passwordToCheck.end(), [](auto arg) -> auto {
        return specialLetters.find(arg) != std::string::npos;
    });
    bool containBigLetters = std::any_of(passwordToCheck.begin(), passwordToCheck.end(),
                                         [](auto arg) -> auto { return std::isupper(arg); });

    if (containBigLetters && containSpecialLetters) std::cout << "Twoje haslo jest silne!" << std::endl;
    else if (containBigLetters || containSpecialLetters)
        std::cout << "Twoje haslo jest umiarkowanie silne" << std::endl;
    else std::cout << "Twoje haslo jest slabe" << std::endl;
}

bool addPasswd::checkingUniqueOfName(const std::string &nameToCheck, std::vector<std::vector<std::string>> &vec) {
    for (auto &i: vec) {
        if (nameToCheck == i[1]) return false;
    }
    return true;
}