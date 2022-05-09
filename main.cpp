#include <iostream>
#include "Utils/Encrypting/encrypt.h"
#include "Utils/Decrypting/decrypt.h"
#include "Utils/Auth/auth.h"
#include "Utils/Seed/seed.h"
#include <ctime>

using namespace std;

int main() {
    string test = encrypt("Ziemniaki");
    string test2 = encrypt("TrudneBardzoHaslo*2137");
    /**
     * @srand for random encryption
     */
    srand(seed::generateSeed(test));

    cout << "START" << endl << test << endl << "END" << endl << decrypt(test) << endl;
    cout << "START" << endl << test << endl << "END" << endl << wrongDecrypt(test) << endl;
    cout << "START" << endl << test2 << endl << "END" << endl << decrypt(test2) << endl;
    cout << "START" << endl << test2 << endl << "END" << endl << wrongDecrypt(test2) << endl;

    cout << auth::checkPassword("BardzoTrudneHaslo*2137") << endl;
    return 0;
}
