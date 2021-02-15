//
// Created by Frewen.Wong on 2021/2/15.
//

#include <iostream>
#include <cstdlib>

// 使用标准的命名空间
using namespace std;


int main() {
    int *ptr_1 = new int;    // 定义 ＊ptr_1 指针，并由new分配内存
    int *ptr_2 = new int;    // 定义 ＊ptr_2 指针，并由new分配内存

    cout << "输入被加数：";
    cin >> *ptr_1;                              // ＊ptr_1 存储被加数
    cout << "输入加数  :";
    cin >> *ptr_2;                              // ＊ptr_2 存储加数

    cout << *ptr_1 << " + " << *ptr_2 << " = ";
    cout << *ptr_1 + *ptr_2;                    // 计算总和

    cout << endl;                               // 换行


    delete ptr_1;                               // 释放分配给ptr_1 的内存空间
    delete ptr_2;                               // 释放分配给ptr_2 的内存空间
    return 0;
}