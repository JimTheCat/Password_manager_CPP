#include <iostream>
#include "Utils/EncryptPassword/encryptPassword.h"
#include "Utils/DecryptPassword/decryptPassword.h"
#include "Utils/Auth/auth.h"
#include "Utils/Seed/seed.h"
#include <ctime>

using namespace std;

int main() {
    string test = hashPassword("Ziemniaki");
    string test2 = hashPassword("TrudneBardzoHaslo*2137");
    /**
     * @srand for random encryption
     */
    srand(seed::generateSeed(test));

    cout << "START" << endl << test << endl << "END" << endl << decryptPassword(test) << endl;
    cout << "START" << endl << test2 << endl << "END" << endl << decryptPassword(test2) << endl;

    cout << auth::checkPassword("BardzoTrudneHaslo*2137") << endl;
    return 0;
}
