cmake_minimum_required(VERSION 3.17)
project(password_gen)

set(CMAKE_CXX_STANDARD 14)

add_executable(password_gen
        strategy.h strategy.cpp
        generator.h generator.cpp
        simple.h simple.cpp
        medium.h medium.cpp
        strong.h strong.cpp
        alphabet.h alphabet.cpp
        argparser.h argparser.cpp
        main.cpp)