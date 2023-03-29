#include "../include/dict_pattern_register.h"
#include "../include/enum_data.h"
#include "../include/public_parse.h"
#include "../include/dict_parse.h"

#include <iostream>
#include <fstream>
#include<functional>


int main() {
    dict_pattern_register::insert(0, Dict_data_type::INT, reinterpret_cast<user_def_parse&>(parse_to_int));
    std::cout<<"123455"<<std::endl;
    dict_pattern_register::insert(1, Dict_data_type::FLOAT, reinterpret_cast<user_def_parse &>(parse_to_float));

    dict_parse::open("in.txt");
//    std::ifstream in("in.txt");
//
//    std::string line;
//    int cnt=0;
//    while(std::getline(in,line)){
//        std::cout<<line<<std::endl;
//        cnt++;
//    }





    return 0;
}
