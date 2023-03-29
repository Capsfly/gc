//
// Created by suichunyu on 2023/3/27.
//

#ifndef UNTITLED25_PUBLIC_PARSE_CPP
#define UNTITLED25_PUBLIC_PARSE_CPP
#include "../include/public_parse.h"
#include <string>

int parse_to_int(const std::string &s, int &val) {
    val=std::stoi(s);
    return 0;
}

int parse_to_float(const std::string &s, float &val) {
    val=std::stof(s);
    return 0;
}

int parse_to_char_array(const std::string &s, char *val, int char_arr_size) {
    int pos=0;
    for(auto&i:s){
        val[pos++]=i;
    }
    return 0;
}

#endif //UNTITLED25_PUBLIC_PARSE_CPP
