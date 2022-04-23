#include <iostream>
//#include "Features/Log in/login.h"
#include "Features/EncryptPassword/encryptPassword.h"
#include "Features/DecryptPassword/decryptPassword.h"
#include <ctime>

using namespace std;

int main() {
    /**
     * @srand for random encryption
     */
    srand(time(NULL));

    string test = hashPassword("testCombination");
    cout << "START" << endl << test << endl << "END" << endl << decryptPassword(test);

    return 0;
}
