#include "medium.h"
#include "passwordgenerator.h"

std::string Medium::generate(const std::string& alphabet, const int& len) {
    auto pwdgen = PasswordGenerator(alphabet);
    std::string password = pwdgen.generate(len);
    srand(static_cast<unsigned int>(time(0)));
    int cnt = rand() % (len/2) + 2;
    std::string symbols = "-_!@#$~";
    for (int i=0; i < cnt; i++){
        int tmp = rand() % len;
        bool flag = true;
        if (isalpha(password[tmp])) {
            if (islower(password[tmp])) {
                password[tmp] = toupper(password[tmp]);
            } else {
                password[tmp] = _tolower(password[tmp]);
            }
            flag = false;
        }
        if (flag) {
            password[cnt] = '0' + rand() % 10;
        }
    }
    int ind = rand() % len + 1;
    password[ind] = '0' + (rand() % 10);
    password[ind-1] = symbols[rand() % symbols.size()];
    return password;
}
