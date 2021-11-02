//
// Created by zj on 2021/11/2.
//

#include "stdio.h"

void test1() {

    char c = 0x34;
    short s = 0x2233;
    int i = 0x44556677;
    int a = 12;
    long l = 0x99aabbccddeeff;

    printf("%c,%d,%d,%d,%d \n", c, s, i, l, a);


    return;
}

void print() {
//    %d 十进制有符号整数（常用）
//    %u 十进制无符号整数（常用）
//    %f 浮点数
//    %s 字符串（常用）
//    %c 单个字符（常用）
//    %p 指针的值（常用）
//    %e 指数形式的浮点数
//    %x, %X 无符号以十六进制表示的整数(常用，打印指针一般会用到这个)
//    %o 无符号以八进制表示的整数
//    %g 把输出的值按照%e或者%f类型中输出长度较小的方式输出
//    %p 输出地址符
//    %lu 32位无符号整数
//    %llu 64位无符号整数
//
//    可以在“%”和字母之间插进数字表示最大场宽
//    %3d表示输出3位整型数，不够3位右对齐
    int a = 123;
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    printf("%d, %s, %p, %c \n", a, arr, *arr, 0x61);     //123, abcde, 0x61, a

    // arr本身就是指向char的地址, &arr相当于二维数组地址,所以起始地址是一样的; *arr是取地址的值
    printf("%p %p %p\n", arr, &arr, *arr);          // 0x7ffee3613838 0x7ffee3613838 0x61
    printf("%d, %d \n", arr + 1, sizeof(arr));      // -527280073, 6
    printf("%d, %d \n", (&arr) + 1, sizeof(&arr));  // -527280068, 8
    return;
}

void stringTest() {

    // 定义字符串的三种形式
    char str1[] = {'a', 'b', 'c'};  // 声明一个字符数组, 由3个字符填充
    char str2[] = "abc";            // 声明一个字符数组, 指向一个字符串常量,结尾带'\0'
    char *str3 = "abc";             // 声明一个字符引用, 指向字符串常量

    int len = sizeof(str1) / sizeof(char);
    printf("str1的长度为:%d \n", len);    // 获取数组长度
    printf("%d,%d \n", sizeof(str1), sizeof(str2));     // 3,4    所以字符串数组和字符串差了一个\0
    for (int i = 0; i < sizeof(str2); i++) {
        printf("%x ", str2[i]);
    }
    printf("\n");

    char str4[] = {'a', 'b', '\0', 'c', '0', '1', '\0'}; // 这样可以存储, 但是遇到输出时会截断\0后面的, 如果想输出,需要自己写for循环读取
    printf("%s\n", str4);       // ab

    // 对于指向字符串常量的指针(如上面的:str3), 不可以修改具体的值
    str2[1] = 'z';
    printf("修改后str2=%s\n", str2);
    str3[1] = 'z';
    printf("修改后str3=%s\n", str3);   // 报错
    return;
}