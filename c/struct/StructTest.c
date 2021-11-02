//
// Created by threedays on 2021/11/1.
//
#include "stdio.h"
#include "StructTest.h"

void structTest() {
    // 第一种初始化方式
    struct Student a = {"threedays",12};
    // 第二种初始化方式， 这种比较推荐，因为可以修改成员顺序
    struct Student b = {
        .age=13,
        .name="aaaa",
    };
    // 第三种初始化方式
    struct Student c = {
        name: "bbbb",
        age: 34,
    };

//    struct Student d;
//    d.age=23;
//    d.name="kkk";

    toString(a);    // 传结构体

    toString2(&b);  // 传结构体指针、地址

    toString(c);

    struct A aa;
    struct B bb;
    printf("%d \n", sizeof aa); // 8个字节
    printf("%d \n",sizeof bb);  // 12个字节
    //toString2(d);
}

void toString(struct Student stu){
    // 两种取成员的方式，1
    printf("struct Student:name=%s, age=%d \n", stu.name, stu.age);
}

void toString2(struct Student* stu){
    // 两种取成员的方式，2
    printf("struct Student:name=%s, age=%d \n", stu->name, stu->age);
}




