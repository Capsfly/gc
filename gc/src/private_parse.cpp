//
// Created by suichunyu on 2023/3/27.
//

#ifndef UNTITLED25_PRIVATE_PARSE_CPP
#define UNTITLED25_PRIVATE_PARSE_CPP
#include "../include/private_data.h"
#include "../include/private_parse.h"

#include <sstream>
int parse_to_private_process(std::string&s, private_process&p){
    std::stringstream ss(s);
    int pid;
    std::string process_name;
    std::string flag;

    ss>>pid;
    ss>>process_name;
    ss>>flag;

    if(flag=="CREATE"){
        p.setProcessStatus(Process_status::CREATE);
    }else if(flag=="READY"){
        p.setProcessStatus(Process_status::READY);
    }else if(flag=="RUNNING"){
        p.setProcessStatus(Process_status::RUNNING);
    }else if(flag=="BLOCKING"){
        p.setProcessStatus(Process_status::BLOCKING);
    }else if(flag=="TERMINATING"){
        p.setProcessStatus(Process_status::TERMINATING);
    }else {
        return -1;
    }
    p.setPid(pid);
    p.setProcessName(process_name);
}

int parse_to_person(const std::string&s, Person&p){
    std::stringstream ss(s);
    std::string flag1;
    ss>>flag1;
    if(flag1=="HIGH"){
        p.setHeight(Height::HIGH);
    } else if(flag1=="MEDIUM"){
        p.setHeight(Height::MEDIUM);
    } else if(flag1=="SHORT"){
        p.setHeight(Height::SHORT);
    }

    std::string flag2;
    ss>>flag2;
    if(flag2=="FAT"){
        p.setWeight(Weight::FAT);
    } else if(flag2=="MEDIUM"){
        p.setWeight(Weight::MEDIUM);
    } else if(flag2=="SLIM"){
        p.setWeight(Weight::SLIM);
    }

    return 0;
}



template<class T>
int parse_to_private_data(std::string&s, T& pri_data){
    if(std::is_same_v<std::decay_t<T&>,private_process>){
        parse_to_private_data(s,pri_data);
    }
    else if(std::is_same_v<std::decay_t<T&>,Person>){
        parse_to_person(s,pri_data);
    }
    return 0;
}



#endif //UNTITLED25_PRIVATE_PARSE_CPP
