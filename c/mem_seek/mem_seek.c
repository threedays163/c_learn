//
// Created by zj on 2021/11/3.
//

#include <stdlib.h>
#include <unistd.h>
#include "mem_seek.h"
#include "stdio.h"
#include "string.h"


void printCurrentWorkspace() {
    char buf[80];
    getcwd(buf, sizeof(buf));
    printf("current working directory: %s\n", buf);
}

void mainFun() {

    printCurrentWorkspace();

    char *filePath = "./cmake_install.cmake";
    // 读取字节码文件到内存
//    char *aa = load(filePath);
//    printf("aa=%s\n", aa);

    char *content = "";
    load2(filePath, &content);
    printf("content=%s\n", content);
    //long firstOffset = seekFirstOffset(content, "1");
//    if (aa != NULL) {
//        free(aa);
//    }
}

// 切记: 如果返回指针,则return返回的指针一定不能是栈上创建的,因为栈上创建的所有变量,包括指针,离开了作用域一定会被销毁,要传出来必须要动态申请内存
// 申请动态内存有2种, 一种是
char *load(const char *filePath) {
    FILE *fp = NULL;
    fp = fopen(filePath, "rb");
    if (fp == NULL) {
        printf("文件%s打开失败\n", filePath);
        exit(0);
    }

    // 两次读取, 第一次读取文件获取文件长度, 第二次使用给定长度接收文件内容

    int count = 0;
    int tmp = fgetc(fp);
    while (!feof(fp)) {
        count++;
        tmp = fgetc(fp);
    }

    // 文件指针回拨到开头
    rewind(fp);

    // 声明给定大小的动态内存,用于返回值;不使用这种方式申请内存,就是栈上变量,在方法离开后会被销毁掉
    char *p = (char *) malloc(sizeof(count + 1));

    int i = 0;
    tmp = fgetc(fp);
    while (!feof(fp)) {
        p[i++] = tmp;
        tmp = fgetc(fp);
    }
    p[i] = '\0';

    if (fclose(fp) != 0) {
        perror("fclose");
    }

    return p;
}

// 通过传二级指针方式返回参数
char *load2(const char *filePath, char **content) {
    FILE *fp = NULL;
    fp = fopen(filePath, "rb");
    if (fp == NULL) {
        printf("文件%s打开失败\n", filePath);
        exit(0);
    }

    // 两次读取, 第一次读取文件获取文件长度, 第二次使用给定长度接收文件内容

    int count = 0;
    int tmp = fgetc(fp);
    while (!feof(fp)) {
        count++;
        tmp = fgetc(fp);
    }

    // 文件指针回拨到开头
    rewind(fp);

    // 声明给定大小的动态内存,用于返回值;不使用这种方式申请内存,就是栈上变量,在方法离开后会被销毁掉
    *content = (char *) malloc(sizeof(count + 1));

    int i = 0;
    tmp = fgetc(fp);
    while (!feof(fp)) {
        (*content)[i++] = tmp;
        tmp = fgetc(fp);
    }
    (*content)[i] = '\0';

    if (fclose(fp) != 0) {
        perror("fclose");
    }
    return NULL;
}

long seekFirstOffset(const char *content, char *target) {
    return 0;
}

long *seekAllOffset(const char *content, char *target) {
    return 0;
}