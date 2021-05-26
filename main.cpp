#include <iostream>
#include <string>
#include <vector>

#include "json.hpp"
#include "simple.h"
#include "medium.h"
#include "strong.h"
#include "alphabet.h"
#include "argparser.h"

using json = nlohmann::json;

int main(int argc, char *argv[]) {
    auto parser = parse_args(QCoreApplication(argc, argv));
    auto length = parser->value("length").toUInt();
    Generator *generator;
    std::string a = "asdsd";
    int b = 4;
    generator = new Generator(new Simple());
    std::cout << generator->generate("asd", 4);
    generator = new Generator(new Medium());
    std::cout << generator->generate("asd", 4);
    generator = new Generator(new Strong());
    std::cout << generator->generate("asd", 4);
    return 0;
}
