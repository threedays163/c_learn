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

//结构体字节对齐:  https://blog.csdn.net/m0_37829435/article/details/81348532

//1.先确定实际对齐单位，其由以下三个因素决定
//
//(1) CPU周期
//
//        WIN  vs  qt  默认8字节对齐
//
//        Linux 32位 默认4字节对齐，64位默认8字节对齐
//
//(2) 结构体最大成员(基本数据类型变量)
//
//        (3) 预编译指令#pragma pack(n)手动设置     n--只能填1 2 4 8 16
//
//上面三者取最小的,就是实际对齐单位(这里的“实际对齐单位”是我为了方便区分随便取的概念)
//
//2.除结构体的第一个成员外，其他所有的成员的地址相对于结构体地址(即它首个成员的地址)的偏移量必须为实际对齐单位或自身大小的整数倍(取两者中小的那个)
//
//3.结构体的整体大小必须为实际对齐单位的整数倍。

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
    int n: 8;     // 声明一个成员, 最多占用8个bit位宽, 后面的数值最大4*8=32
};

struct D {  // 一共33个bit宽, 超过了4个字节,需要2个4字节对齐,即8byte
    char f1: 4;
    char f2: 2;
    int n: 27;
};

//#pragma pack(n)  预编译指令,手动设置对齐单位, n=1,2,4,8,16

// 声明4字节对齐
//#pragma pack(4)
struct T1 {
    char age;
    int level;
    int level2;
    int level3;
    char c;
};
//#pragma pack()

// 声明8字节对齐
//#pragma pack(8)
struct T2 {
    char age;
    int level;
    int level2;
    int level3;
    char c;
};
//#pragma pack()

struct Person {
    int _age;   // 4字节
    char* _name;// 8字节,作为最大成员,则该结构体以8字节对齐
};

void structTest();

void structfun();

void toString(struct Student stu);

void toString2(struct Student *stu);

#endif //C_LEARN_STRUCTTEST_H