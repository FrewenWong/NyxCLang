//
// Created by Frewen.Wong on 2021/2/27.
//

#include <cstdlib>
#include <cstdio>

// 使用标准的命名空间
using namespace std;

/**
 * C 库函数 char *getenv(const char *name) 搜索 name 所指向的环境字符串，并返回相关的值给字符串。
 * 下面是 getenv() 函数的声明。
 * char *getenv(const char *name)
 *
 * @return
 */
int main() {

//    指针变量可以用来指向已定义变量的地址，再通过指针间接存取该变量的内容。
//    其实在C++中，指针变量也可以声明为指向函数的起始地址，并借助该指针变量来调用函数。
//    这种指向函数的指针变量被称为函数指针（Pointer of Function），
//    主要是可使用同一个函数指针名称在程序运行期间动态地决定所要调用的函数。
    printf("PATH : %s\n", getenv("PATH"));
    printf("HOME : %s\n", getenv("HOME"));
    printf("ROOT : %s\n", getenv("ROOT"));

    return 0;
}
