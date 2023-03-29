//
// Created by suichunyu on 2023/3/28.
//

#ifndef UNTITLED25_ENUM_DATA_H
#define UNTITLED25_ENUM_DATA_H
enum class Process_status{
    CREATE,
    READY,
    RUNNING,
    BLOCKING,
    TERMINATING
};

enum class Height{
    HIGH,
    MEDIUM,
    SHORT
};

enum class Weight{
    FAT,
    MEDIUM,
    SLIM
};

enum class User_self_def{
    PROCESS,
    PERSON
};

enum class Dict_data_type{
    INT,
    FLOAT,
    CHAR_ARRAY,
    USER_SELF_DEF
};

#endif //UNTITLED25_ENUM_DATA_H
