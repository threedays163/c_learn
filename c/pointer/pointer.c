//
// Created by zj on 2021/11/2.
//

#include "pointer.h"
#include "stdio.h"

void pointerTest() {

    int arr[] = {0x11223344, 0x55667788};

    short *p = (short *) arr;
    printf("%X,%X,%X\n", *p, *p + 1, *(p + 1));

    int i = (int) arr;

    int v1 = *((int *) i + 1);
    int v2 = *(int *) (i + 1);
    printf("%X, %X\n", v1, v2);

    char *p1;
    short *p2;
    int *p3;
    int **p4;

    printf("char* 长度:%d\n", sizeof(p1));
    printf("short* 长度:%d\n", sizeof(p2));
    printf("int* 长度:%d\n", sizeof(p3));
    printf("int** 长度:%d\n", sizeof(p4));
}