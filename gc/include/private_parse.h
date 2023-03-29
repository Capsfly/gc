//
// Created by suichunyu on 2023/3/29.
//

#ifndef UNTITLED25_PRIVATE_PARSE_H
#define UNTITLED25_PRIVATE_PARSE_H

#include "private_data.h"

#include <sstream>
int parse_to_private_process(std::string&s, private_process&p);

int parse_to_person(const std::string&s, Person&p);

template<class T>
int parse_to_private_data(std::string&s, T& pri_data);





#endif //UNTITLED25_PRIVATE_PARSE_H
