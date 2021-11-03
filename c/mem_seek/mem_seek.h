//
// Created by zj on 2021/11/3.
//

#ifndef C_LEARN_MEM_SEEK_H
#define C_LEARN_MEM_SEEK_H

#endif //C_LEARN_MEM_SEEK_H


void mainFun();

// 读取文件中的字节
char * load(const char *filePath);

long seekFirstOffset(const char *content, char *target);

long *seekAllOffset(const char *content, char *target);