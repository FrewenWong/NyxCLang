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

int main() {
    // error: call to 'test' is ambiguous
    test(NULL);
    int intVal = 10;
    int *pIntVa = &intVal;
    test(pIntVa);
    pIntVa = NULL;
    test(pIntVa);

    return 0;
}

// 下面是输出结果
//变量名称 变量值 内存地址
//----------------------------
//num1 	 10	0x7ffeef23b3f8
//ch1  	 A	0x7ffeef23b3f6