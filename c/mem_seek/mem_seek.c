//
// Created by zj on 2021/11/3.
//

#include "mem_seek.h"
#include "stdio.h"


void mainFun() {
    char *filePath = "/Users/zj/projects/c_project/c_learn/c_learn/test.txt";
    // 读取字节码文件到内存
    char *content = load(filePath);
//    char *p = content;
//    printf("%s\n", p);
    printf("%s\n", content);
    char *a = "aaa";
    printf("%s\n", a);
    //long firstOffset = seekFirstOffset(content, "1");
}

char *load(char *filePath) {
    FILE *fp = NULL;
    fp = fopen(filePath, "r");

    // 两次读取, 第一次读取文件获取文件长度, 第二次使用给定长度接收文件内容

    int count = 0;
    int tmp = fgetc(fp);
    while (!feof(fp)) {
        count++;
        tmp = fgetc(fp);
    }

    // 文件指针回拨到开头
    rewind(fp);

    // 声明给定大小的数组
    char result[count + 1];

    int i = 0;
    tmp = fgetc(fp);
    while (!feof(fp)) {
        result[i++] = tmp;
        tmp = fgetc(fp);
    }

    fclose(fp);
    result[i] = '\0';
    char *p = result;
    return p;
}

long seekFirstOffset(const char *content, char *target) {
    return 0;
}

long *seekAllOffset(const char *content, char *target) {
    return 0;
}