cmake_minimum_required(VERSION 3.24)
project(untitled25)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled25 src/main.cpp src/public_parse.cpp src/private_parse.cpp include/private_data.h src/dict_parse.cpp include/dict_parse.h include/enum_data.h include/dict_pattern_register.h src/dict_pattern_register.cpp include/private_parse.h include/public_parse.h include/public_parse.h src/private_data.cpp)
