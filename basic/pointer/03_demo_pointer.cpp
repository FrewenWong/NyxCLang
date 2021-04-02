//
// Created by Frewen.Wong on 2021/2/15.
//

#include <iostream>
#include <cstdlib>

// 使用标准的命名空间
using namespace std;


int main() {

    int iVal = 10;         // 整数变量
    double dVal = 123.45;   //双精度实数变量

    // int *piVal = NULL; // 声明为空指针。我们不建议这样声明空指针
    // 而是像下面一样声明空指针
    int *piVal = nullptr;
    piVal = &iVal;   //整数类型的指针变量，指向iVal变量的地址

    double *pdVal = &dVal;    //实数类型的指针变量，指向dVal变量的地址


    cout << "piVal变量地址为" << piVal << endl;    // 直接打印指针变量，输出的是指针指向的内存地址
    cout << "piVal变量所指向地址的数据内容为" << *piVal << endl;     // 加*代表,指针变量指向的地址的数据内容


    *piVal = 20; // 重新设置piVal指针变量的数据内容为20
    cout << "piVal变量地址为" << piVal << endl;    // 直接打印指针变量，输出的是指针指向的内存地址
    cout << "iVal的数据内容为" << iVal << endl;    // 我们打印看看之前声明的那个变量
    cout << "piVal指针变量重新设置后，iVal的数据内容同步更改为" << iVal << endl;
    cout << "piVal变量所指向地址的数据内容为" << *piVal << endl;     // 加*代表,指针变量指向的地址的数据内容


    cout << "pdVal变量地址为" << pdVal << endl;
    cout << "pdVal变量所指向地址的数据内容为" << *pdVal << endl;


    *pdVal = 67.1234; //重新设置pdVal指针变量的数据内容为67.1234
    cout << "pdVal指针变量重新设置后，dVal的数据内容同步更改为" << dVal << endl;
    cout << "双精度实数dVal所占用的内存空间为：" << sizeof(dVal) << "位" << endl;
    cout << "双精度实数指针变量pdVal所占用的内存空间为：" << sizeof(pdVal) << endl;

    return 0;
}