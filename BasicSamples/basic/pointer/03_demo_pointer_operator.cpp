//
// Created by wangzhijiang on 2021/6/28.
//
#include <iostream>

using namespace std;
// 全局变量常量int
const int MAX = 3;

int main() {

    int varArray[MAX] = {10, 100, 200};

    int *arrayPtr; // 声明一个int型的指针

    // 指针中的数组地址  数组的数组名称其实就是代表数组的地址。
    // 下面的语句代表将数组的地址赋值给指针arrayPtr
    arrayPtr = varArray;

    for (int i = 0; i < MAX; ++i) {
        cout << "数组元素的地址 of var[" << i << "] = ";
        cout << arrayPtr << endl;

        cout << "数组元素的元素 of var[" << i << "] = ";
        cout << *arrayPtr << endl;
    }
}