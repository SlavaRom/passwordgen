#pragma once

#include <iostream>
#include <string>

#include "strategy.h"

class Generator {
protected:
    Strategy *strategy_;

public:
    explicit Generator(Strategy *strategy = nullptr) : strategy_(strategy) {}

    ~Generator() {
        delete this->strategy_;
    }

    std::string generate(const std::string& alphabet,const int& len)
    {
        return strategy_->generate(alphabet, len);
    }
};
