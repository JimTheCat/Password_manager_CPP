#include <iostream>
#include "Utils/EncryptPassword/encryptPassword.h"
#include "Utils/DecryptPassword/decryptPassword.h"
#include "Utils/Auth/auth.h"
#include <ctime>

using namespace std;

int main() {
    /**
     * @srand for random encryption
     */
    srand(time(NULL));

    string test = hashPassword("BardzoTrudneHaslo*2137");
    cout << "START" << endl << test << endl << "END" << endl << decryptPassword(test) << endl;

    cout << auth::checkPassword("BardzoTrudneHaslo*2137") << endl;
    return 0;
}
