//
// Created by Frewen.Wong on 2021/2/15.
//

#include <iostream>
#include <cstdlib>

// 使用标准的命名空间
using namespace std;


void test(void *p) {
    cout << "p is pointer " << p << endl;
}

void test(int num) {
    cout << "num is int " << num << endl;
}

/**
 * 在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。
 * 赋为 NULL 值的指针被称为空指针。
 * NULL 指针是一个定义在标准库中的值为零的常量。请看下面的程序：
 * @return
 */
int main() {
    // error: call to 'test' is ambiguous
    // test(NULL);
    int intVal = 10;
    int *pIntVa = &intVal;
    test(pIntVa);
    // 在大多数的操作系统上，程序不允许访问地址为 0 的内存，因为该内存是操作系统保留的。
    // 然而，内存地址 0 有特别重要的意义，它表明该指针不指向一个可访问的内存位置。
    // 但按照惯例，如果指针包含空值（零值），则假定它不指向任何东西。
    // 如需检查一个空指针，您可以使用 if 语句，如下所示：
    // 因此，如果所有未使用的指针都被赋予空值，同时避免使用空指针，就可以防止误用一个未初始化的指针。
    // 很多时候，未初始化的变量存有一些垃圾值，导致程序难以调试。
    pIntVa = NULL;
    test(pIntVa);

    return 0;
}

// 下面是输出结果
//变量名称 变量值 内存地址
//----------------------------
//num1 	 10	0x7ffeef23b3f8
//ch1  	 A	0x7ffeef23b3f6