//
// Created by zj on 2021/11/2.
//

#ifndef C_LEARN_FUN_H
#define C_LEARN_FUN_H

// 函数三种声明方式
//void myFun(int param[]);
//void myFun(int *param);
//void myFun(int param[10]);

// 可变参数,第一个int参数代表可变参数个数, 后面的表示具体的参数
void func(int num,...);


#endif //C_LEARN_FUN_H
