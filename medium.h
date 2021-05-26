#pragma once

#include <iostream>
#include <string>

#include "generator.h"

class Medium : public Strategy {
public:
    std::string generate(const std::string& alphabet, const int& len) override;
};
