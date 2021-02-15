//
// Created by Frewen.Wong on 2020/12/5.
//
//包含iostream头文件，C++中有关输入/输出的函数都在这个头文件中定义。
#include <iostream>

// 早期的C/C++版本是将所有（包含变量、函数与类等）的标识符名称都定义为全局性命名空间，
// 因为所有名称都处于同一个命名空间，所以很容易造成命名冲突，发生所谓“覆写”现象。
// 因此在ANSI/ISO C++中，新加入了所谓的命名空间（namespace）。
void testTwoDimensionalArray();

using namespace std;

int main() {

    cout << "我的C++数组程序" << endl;

    int score[8] = {7, 22, 36}; // 声明长度为8的整数数组
    int Temp[] = {1, 2, 3, 4, 5};

    int i;
    // 使用循环打印数组的元素值
    for (i = 0; i < 8; i++) {
        cout << "score[" << i << "]=" << score[i] << endl;
    }
    // 计算数组的大小，就是用使用sizeof(Temp)整个数组的大小
    // 去除以第一个数组元素的大小
    cout << "Temp数组大小=" << sizeof(Temp) / sizeof(Temp[0]) << endl; //计算元素数组个数

    testTwoDimensionalArray();

    // 因为主程序被声明为int数据类型，所以必须返回（return）一个值。
    return 0;
}


/**
 * 测试二维数组
 */
void testTwoDimensionalArray() {

    int score[5][4];    // 声明5＊4的二维数组，用来存放成绩
    int fail[5] = {0};    // 声明并初始化二维数组，用来记录不及格的科目数
    int j, sum = 0, count = 0;
    bool flag;                  // 用来判断是否递增人数
    for (int i = 0; i < 5; i++) {
        flag = false;             // 初始化递增人数的判断开关
        cout << "请输入No." << i + 1 << "的语、英、数、自然成绩：";
        for (j = 0; j < 4; j++) {
            // 要求用户输入信息
            cin >> score[i][j];       // 输入各科成绩
            sum += score[i][j];       // 计算总分
            if (score[i][j] < 60) {
                fail[i] += 1;         // 递增不及格的科目数
                if (flag == false) {
                    count++;          // 递增不及格人数
                    flag = true;        // 变更判断开关
                }
            }
        }
    }
    cout << endl;
    cout << "全班总成绩：" << sum
         << "，全班平均分数：" << (float) sum / (5 * 4) << endl;
    cout << "共有 " << count << " 人有不及格的科目" << endl;
    // 输出有不及格科目的学生的学号及科目数
    for (int i = 0; i < 5; i++)
        if (fail[i] != 0)
            cout << "No." << i + 1 << "有 " << fail[i] << " 科不及格" << endl;

}

