//
// Created by Frewen.Wong on 2021/2/15.
//

#include <iostream>
#include <cstdlib>

// 使用标准的命名空间
using namespace std;

/**
 * 主要学习取值运算符号
 * @return
 */
int main() {
    int num1 = 10;
    char ch1[2] = "A"; //声明变量num1、ch1

    cout << "变量名称 变量值 内存地址" << endl;
    cout << "----------------------------" << endl;
    // &num1就可以获取变量num1的地址
    cout << "num1 " << "\t " << num1 << '\t' << &num1 << endl;
    // //使用&运算符打印变量num1、ch1的数值与地址
    cout << "ch1  " << "\t " << ch1 << '\t' << &ch1 << endl;


    char p[] = "12345";
//    int *a = (void *) p;

    return 0;
}

// 下面是输出结果
//变量名称 变量值 内存地址
//----------------------------
//num1 	 10	0x7ffeef23b3f8
//ch1  	 A	0x7ffeef23b3f6