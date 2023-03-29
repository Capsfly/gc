//
// Created by suichunyu on 2023/3/28.
//

#ifndef UNTITLED25_DICT_PATTERN_REGISTER_H
#define UNTITLED25_DICT_PATTERN_REGISTER_H

#include "enum_data.h"

#include <functional>
#include <string>
#include <unordered_map>
#include <memory>
using user_def_parse=std::function<int(const std::string&, void*)>;
//using user_def_parse_arr=std::function<int(const std::string&,)>

class dict_col_meta_data{
public:
    dict_col_meta_data(Dict_data_type type, const user_def_parse& parse): _type(type), _parse_func(parse){}
private:
    Dict_data_type _type;
    user_def_parse _parse_func;
};


class dict_pattern_register {
public:
    static void insert(int index, Dict_data_type type, user_def_parse &parse);
    static std::unordered_map<int,std::shared_ptr<dict_col_meta_data>> index_to_meta();
private:
    static std::unordered_map<int,std::shared_ptr<dict_col_meta_data>> _index_to_meta;
};


#endif //UNTITLED25_DICT_PATTERN_REGISTER_H
