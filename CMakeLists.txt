cmake_minimum_required(VERSION 3.17)
project(password_gen)

set(CMAKE_CXX_STANDARD 17)
find_package(Qt5Core REQUIRED)
include_directories(.)
add_executable(password_gen
        strategy.h strategy.cpp
        generator.h generator.cpp
        simple.h simple.cpp
        medium.h medium.cpp
        strong.h strong.cpp
        argparser.h argparser.cpp
        passwordgenerator.h passwordgenerator.cpp
        main.cpp custom.cpp custom.h)
target_link_libraries(password_gen Qt5::Core)