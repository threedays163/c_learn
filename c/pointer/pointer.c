//
// Created by zj on 2021/11/2.
//

#include "pointer.h"
#include "stdio.h"

void pointerTest() {

    long arr[] = {0x11223344, 0x55667788};

    short *p = (short *) arr;
    printf("%X,%X,%X\n", *p, *p + 1, *(p + 1));

    // 演示将指针地址保存到普通变量,并取出转为指针继续使用
    long i = (long) arr;

    long v1 = *((long *) i + 1);
    long v2 = *(long *) (i + 1);
    printf("%X, %X\n", v1, v2);

    char *p1 = 0;
    short *p2 = 0;
    int *p3 = 0;
    int **p4 = 0;
    char **p5 = 0;

    printf("char* 长度:%d\n", sizeof(p1));
    printf("short* 长度:%d\n", sizeof(p2));
    printf("int* 长度:%d\n", sizeof(p3));
    printf("int** 长度:%d\n", sizeof(p4));
    printf("%d, %d\n", p1 + 1, p3 + 1);

    //printf("%d, %d\n", *p1, *p2);   // 报错
    printf("%d, %d\n", p4 + 2, p5 + 2);

    int y = 0x11223344;
    char *p6 = (char *) &y;
    printf("%X, %d\n", *p6, *p6);
    printf("%X\n", *(p6 + 1));
    printf("%X\n", *(p6 + 2));
    printf("%X\n", *(p6 + 3));

    int a = 10;
    int b = 20;

    // 常量指针(指向常量的指针)
    const int *p7 = &a;
    printf("%d\n", *p7);
    p7 = &b;
    printf("%d\n", *p7);
    //*p7 = 30;   // 编译不通过, 常量指针不能修改取值后的值, 可以改指向
    printf("%d\n", *p7);

    // 指针常量(指针是常量)
    int *const p8 = &b;
    printf("%d\n", *p8);
    //p8 = &a;    // 编译不通过 指针常量不能修改指针指向, 但是可以修改指针指向的值
    printf("%d\n", *p8);
    *p8 = 30;
    printf("%d\n", *p7);

    // 指向常量的指针常量
    const int *const p9 = &a;   // 即不可以修改指针指向,也不可以修改指针指向的内容
    //p9 = &b;  // 编译不通过
    //*p9 = b;  // 编译不通过


}