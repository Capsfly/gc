//
// Created by suichunyu on 2023/3/27.
//

#ifndef UNTITLED25_PRIVATE_DATA_H
#define UNTITLED25_PRIVATE_DATA_H
#include "enum_data.h"

#include <string>

class private_process {
    int _pid;
    std::string _process_name;
    Process_status _status;
public:
    private_process(int _pid, std::string _process_name, Process_status _status): _pid(_pid), _process_name(_process_name), _status(_status){}
    void setPid(int pid);
    void setProcessName(std::string process_name);
    void setProcessStatus(Process_status ps);
};



class Person{
    Weight _w;
    Height _h;
    int _id;
public:
    Person(int id,Weight w,Height h):_id(id),_w(w),_h(h){}
    void setWeight(Weight w);
    void setHeight(Height h);
    int setId(int id);
    int id();
};



#endif //UNTITLED25_PRIVATE_DATA_H
