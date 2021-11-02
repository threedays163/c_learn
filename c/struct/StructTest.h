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

// 注意这里结构体A和结构体A2的区别,成员个数不同,但是实际上占用的内存空间相同, 说明c语言进行了4字节填充
struct A { // 一共8个字节, f1,f2合并并填充成4个字节, n单独4个字节
    char f1;    // 1个字节
    char f2;    // 1个字节
    int n;      // 4个字节
};

struct A2 { // 一共8个字节, f1,f2合并成4个字节, n单独4个字节
    char f1;    // 1个字节
    char f2;    // 1个字节
    char f3;    // 1个字节
    char f4;    // 1个字节
    int n;      // 4个字节
};

// A,B的差异仅仅是成员顺序不同 通过A,B对比我们知道, 在结构体声明成员时最好同一个类型的放一起,类型占用空间小的排在前面, 可以避免空间浪费
struct B {  // 一共12个字节,f1填充成4个字节, n占4个字节, f2填充成4个字节
    char f1;    // 1个字节, 4字节填充
    int n;      // 4个字节
    char f2;    // 1个字节, 4字节填充
};

// 注意这里结构体可以声明少于类型宽度的成员
struct C { // 一共14个bit宽, 因为c语言4字节对齐, 所以最少需要4byte
    char f1: 4;    // 声明一个成员, 占用3个bit位宽, 最宽8, 因为char最多占用一个字节
    char f2: 2;    // 声明一个成员, 占用2个bit位宽
    int n: 8;     // 声明一个成员, 最多占用12个bit位宽, 后面的数值最大4*8=32
};

struct D {  // 一共33个bit宽, 超过了4个字节,需要2个4字节对齐,即8byte
    char f1: 4;
    char f2: 2;
    int n: 27;
};

// 声明4字节对齐
#pragma pack(4)
struct T1 {
    char age;
    int level;
    int level2;
    int level3;
    char c;
};
#pragma pack()

// 声明8字节对齐
#pragma pack(8)
struct T2 {
    char age;
    int level;
    int level2;
    int level3;
    char c;
};
#pragma pack()


void structTest();

void toString(struct Student stu);

void toString2(struct Student *stu);

#endif //C_LEARN_STRUCTTEST_H