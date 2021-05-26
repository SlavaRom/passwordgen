#include "custom.h"
#include "passwordgenerator.h"

std::string Custom::generate(const std::string& alphabet, const int& len) {
    std::string password;
    auto pwdgen = PasswordGenerator(alphabet);
    return pwdgen.generate(len);
}
