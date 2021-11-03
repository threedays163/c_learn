//
// Created by threedays on 2021/11/2.
//

#include "asm.h"

void asmTest(){
//    int out;
//    int out2;
//
//    // 模拟JVM的虚拟机栈
//    Stack<int> stack(10);
//
//    stack.push(10);
//    stack.push(20);
//
//    __asm__ (
//    // 保存现场，这个寄存器后面要用，作为中转站，暂存OS栈的SP
//    "push %%r8 \r\n"
//
//    // 保存sp
//    "movq %%rsp, %%r8 \r\n"
//
//    // 自定义栈顶指针赋值给rsp，就可以用pop、push相关命令了
//    "movq %2, %%rax \r\n"
//
//    // 切栈
//    "movq %%rax, %%rsp \r\n"
//
//    // 用这两条指令模拟pop，因为64bit机下push、pop不支持32bit读取
//    "movl (%%rsp), %%eax \r\n"
//    "subl $4, %%esp \r\n"
//
//    "movl %%eax, %0 \r\n"
//
//    // 用这两条指令模拟pop，因为64bit机下push、pop不支持32bit读取（暂时不知道如何配置）
//    "movl (%%rsp), %%eax \r\n"
//    "subl $4, %%esp \r\n"
//
//    "movl %%eax, %1 \r\n"
//
//    "movq %%r8, %%rsp \r\n"
//    "pop %%r8 \r\n"
//
//    :"=r"(out), "=r"(out2):"r"(stack.currentDataPtr()):
//    );
//
//    printf("Result: out=%d, out2=%d\n", out, out2);

}