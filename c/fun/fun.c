//
// Created by zj on 2021/11/2.
//

#include "fun.h"
#include "stdio.h"
#include "stdarg.h"


void myFun(int param[]) {

}

void func(int num, ...) {
    // 声明 va_list类型参数变量, 该类型在stdarg.h头文件中定义
    va_list args;

    int sum = 0;

    // 使用num和 va_start宏来初始化args
    va_start(args, num);

    for (int i = 0; i < num; ++i) {
        // 使用va_arg访问
        sum += va_arg(args,int);
    }
    // 清理为args保留的内存
    va_end(args);
    printf("sum=%d", sum);
}
