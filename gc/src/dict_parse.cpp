//
// Created by suichunyu on 2023/3/27.
//

#include "../include/dict_parse.h"
#include "../include/private_data.h"
#include "../include/private_parse.h"
#include "../include/public_parse.h"

std::string dict_parse:: _file_path;//想要读取的文件路径
std::ifstream dict_parse:: _in;
int dict_parse:: _now_row;//现在读取到了第几行
std::vector<std::string> dict_parse:: _now_row_content;//当前行的内容
std::unordered_map<int,std::shared_ptr<dict_col_meta_data>> dict_parse::_col_type;//第一维是列数，第二维度是当前列的格式


int dict_parse::read_next_line(const char delimiter) {
    std::string temp_str;
    std::getline(_in, temp_str);

    size_t find_pos=temp_str.find(delimiter);
    size_t bef_pos=0;
    _now_row_content.clear();
    while(find_pos!=temp_str.npos){
        std::string sub_str= temp_str.substr(bef_pos, (find_pos-1)-bef_pos+1);
        _now_row_content.push_back(sub_str);
        bef_pos=find_pos+1;
        find_pos=temp_str.find(delimiter);
    }
    _now_row++;

    return 0;
}

int dict_parse::conf() {
    //遍历dict_register
    for(auto&iter:dict_pattern_register::index_to_meta()){
        int now_col=iter.first;
        std::shared_ptr<dict_col_meta_data>now_dict_col_meta_data=iter.second;
        _col_type[now_col]=now_dict_col_meta_data;
    }
    return 0;
}

int dict_parse::read_specific_line(int target_line, const char delimiter) {
    if(target_line==_now_row){
        return 0;
    }
    else if(target_line>_now_row){
        read_next_line(target_line-_now_row);
    } else{
        _in.open(_file_path);
        for(int i=0;i<target_line;i++){
            read_next_line(delimiter);
        }
    }
    return 0;
}

std::vector<std::string> dict_parse::now_row_content() {
    return _now_row_content;
}

int dict_parse::open(std::string s) {
    _in.open(s);
    _file_path=s;
    _now_row=-1;
    _now_row_content.clear();
    conf();
    return 0;
}

template<class T>
int dict_parse::parse_to_val(int row, int col, T &val, int arr_size) {
    read_specific_line(row);
    if(std::is_same_v<std::decay_t<T&>, private_process>){
        return parse_to_private_process(_now_row_content[col],val);
    } else if(std::is_same_v<std::decay_t<T&>, Person>){
        return parse_to_person(_now_row_content[col],val);
    } else if(std::is_same_v<std::decay_t<T&>, int>){
        return parse_to_int(_now_row_content[col],val);
    } else if(std::is_same_v<std::decay_t<T&>, float>){
        return parse_to_float(_now_row_content[col],val);
    } else if(std::is_same_v<std::decay_t<T&>,char*>){
        return parse_to_char_array(_now_row_content[col],val,arr_size);
    }
    return 0;
}

