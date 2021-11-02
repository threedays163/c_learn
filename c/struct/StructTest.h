//
// Created by threedays on 2021/11/1.
//

#ifndef C_LEARN_STRUCTTEST_H
#define C_LEARN_STRUCTTEST_H

// 声明一个结构体
struct Student {
    char name[20];
    int age;
};

// 注意这里结构体A和结构体B的区别,只是字段的顺序不同,但是实际上占用的内存空间不同
struct A { // 一共8个字节, f1,f2合并并填充成4个字节, n单独4个字节
    char f1;    // 1个字节
    char f2;    // 1个字节
    int n;      // 4个字节
};

struct B {  // 一共12个字节,f1填充成4个字节, n占4个字节, f2填充成4个字节
    char f1;    // 1个字节
    int n;      // 4个字节
    char f2;    // 1个字节
};

void structTest();

void toString(struct Student stu);

void toString2(struct Student *stu);

#endif //C_LEARN_STRUCTTEST_H