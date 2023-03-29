//
// Created by suichunyu on 2023/3/27.
//

#ifndef UNTITLED25_DICT_PARSE_H
#define UNTITLED25_DICT_PARSE_H
#include "enum_data.h"
#include "dict_pattern_register.h"

#include <fstream>
#include <vector>
#include <unordered_map>


const char COL_DELIMETER='\t';
class dict_parse {
public:
    static int open(std::string s);
    static int conf();//配置每一列的格式
    static int read_next_line(const char delimiter=COL_DELIMETER);
    static int read_specific_line(int target_line, const char delimiter=COL_DELIMETER);

    template<class T>
    static int parse_to_val(int row, int col, T&val, int arr_size=0);

    static std::vector<std::string> now_row_content();
private:
    static std::string _file_path;//想要读取的文件路径
    static std::ifstream _in;
    static int _now_row;//现在读取到了第几行
    static std::vector<std::string> _now_row_content;//当前行的内容
    static std::unordered_map<int,std::shared_ptr<dict_col_meta_data>> _col_type;//第一维是列数，第二维度是当前列的格式
};


#endif //UNTITLED25_DICT_PARSE_H
