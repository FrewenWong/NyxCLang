//
// Created by Frewen.Wong on 2021/6/30.
//

#include <iostream>

using namespace std;

/**
 * explicit关键字
 * 1、指定构造函数或转换函数 (C++11起)为显式, 即它不能用于隐式转换和复制初始化.
 * 2、explicit 指定符可以与常量表达式一同使用. 函数若且唯若该常量表达式求值为 true 才为显式. (C++20起)
 */
class Point {
public:
    int x, y;

    // 文章参考：https://zhuanlan.zhihu.com/p/52152355
    // 如果避免隐式调用可以加上explicit(明确的)不允许隐式调用
    // 为啥Google Code Style和CppCoreGuidelines都建议只有single-parameter的constructor才要explicit，明明2个parameter也会出问题
    // explicit Point(int x = 0, int y = 0) : x(x), y(y) {
    Point(int x = 0, int y = 0) : x(x), y(y) {
        cout << "构造函数调用：(x:" << x << ",y:" << y << ")" << endl;
    }
};

/**
 * 定义一个全局函数。
 * @param p 入参是Point对象的引用。引用取值是.操作符
 */
void displayPoint(const Point &p) {
    cout << "(" << p.x << ","
         << p.y << ")" << endl;
}

int main() {
    displayPoint(1);
    // (1,0)
    Point p = 1;
}