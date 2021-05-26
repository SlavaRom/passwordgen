#include <iostream>
#include <string>
#include <vector>

#include "json.hpp"
#include "simple.h"
#include "medium.h"
#include "strong.h"
#include "custom.h"
#include "argparser.h"
#include "passwordgenerator.h"

using json = nlohmann::json;
namespace {
    const static std::string alphabet_simple {"abcdefghijklmopqrtsuvwxyzABCDEFGHIJKLMOPQRTSUVWXYZ0123456789"};
    const static std::string alphabet_medium {"abcdefghijklmopqrtsuvwxyzABCDEFGHIJKLMOPQRTSUVWXYZ0123456789!@#_"};
    const static std::string alphabet_strong {"abcdefghijklmopqrtsuvwxyzABCDEFGHIJKLMOPQRTSUVWXYZ0123456789!@#$%^&*()-_+="};
}

int main(int argc, char *argv[]) {
    auto parser = parse_args(QCoreApplication(argc, argv));
    int length;
    if (parser->isSet("length"))
        length = parser->value("length").toUInt();
    else {
        if (!parser->isSet("strong"))
            length = 8;
        else
            length = 10;
    }
    if (length < 4 || length > 100) throw std::runtime_error("Invalid length");
    //auto pwdgen = PasswordGenerator(select_alphabet(*parser));
    Generator *generator;
    auto medium_set = parser->isSet("medium");
    auto strong_set = parser->isSet("strong");
    auto simple_set = parser->isSet("simple");

    if ((simple_set && (strong_set || medium_set || (medium_set && strong_set))) || (strong_set && medium_set))
        throw std::runtime_error("You cannot specify more than one complexity level. Choose one of: --simple, --medium or --strong");

    if (medium_set) {
        generator = new Generator(new Medium());
        std::cout << generator->generate(alphabet_medium, length) << std::endl;
    }
    else if (strong_set){
        generator = new Generator(new Strong());
        std::cout << generator->generate(alphabet_strong, length) << std::endl;
    }
    else if (simple_set){
        generator = new Generator(new Simple());
        std::cout << generator->generate(alphabet_simple, length) << std::endl;
    }
    else{
        generator = new Generator(new Custom());
        std::cout << generator->generate(parser->value("alphabet").toStdString(), length) << std::endl;
    }
    return 0;
}
