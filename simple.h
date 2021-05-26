#pragma once

#include <iostream>
#include <string>

#include "generator.h"

class Simple : public Strategy {
public:
    std::string generate(const std::string &data, const int& len) override;
};
