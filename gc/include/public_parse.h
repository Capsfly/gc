//
// Created by suichunyu on 2023/3/29.
//

#ifndef UNTITLED25_PUBLIC_PARSE_H
#define UNTITLED25_PUBLIC_PARSE_H

#include <string>

int parse_to_int(const std::string &s, int &val);

int parse_to_float(const std::string &s, float &val);

int parse_to_char_array(const std::string &s, char *val, int char_arr_size);


#endif //UNTITLED25_PUBLIC_PARSE_H
