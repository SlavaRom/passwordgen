#pragma once

#include <iostream>
#include <string>

class Strategy {
public:
    virtual ~Strategy() {}
    virtual std::string generate(const std::string &data, const int& len) = 0;
};
