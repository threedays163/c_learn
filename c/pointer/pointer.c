//
// Created by zj on 2021/11/2.
//

#include "pointer.h"
#include "stdio.h"

void pointerTest() {

    char *p1;
    short *p2;
    int *p3;
    int **p4;

    printf("char* 长度:%d\n", sizeof(p1));
    printf("short* 长度:%d\n", sizeof(p2));
    printf("int* 长度:%d\n", sizeof(p3));
    printf("int** 长度:%d\n", sizeof(p4));
}