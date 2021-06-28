#include <iostream>
#include <cstdlib>

// 使用标准的命名空间
using namespace std;

/**
 * 每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，它表示了在内存中的一个地址。
 * 主要学习取值运算符号
 * @return
 */
int main() {
    int num1 = 10;
    char ch1[2] = "A"; // 声明变量num1、ch1

    cout << "变量名称 变量值 内存地址" << endl;
    cout << "----------------------------" << endl;
    // &num1就可以获取变量num1的地址
    cout << "num1 " << "\t " << num1 << '\t' << &num1 << endl;
    // //使用&运算符打印变量num1、ch1的数值与地址
    cout << "ch1  " << "\t " << ch1 << '\t' << &ch1 << endl;

    // 下面是输出结果
    //变量名称 变量值 内存地址
    //----------------------------
    //num1 	 10	0x7ffeef23b3f8
    //ch1  	 A	0x7ffeef23b3f6

    // 指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，对其进行声明。
    // 指针变量声明的一般形式为：
    // type *var-name;

    int var = 20;   // 实际变量的声明
    int *ip;        // 指针变量的声明

    ip = &var;       // 在指针变量中存储 var 的地址
    cout << "Value of var variable: ";
    cout << var << endl;

    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;



    int iVal = 10;         // 整数变量
    double dVal = 123.45;   //双精度实数变量

    // int *piVal = NULL; // 声明为空指针。我们不建议这样声明空指针
    // 而是像下面一样声明空指针
    int *piVal = nullptr;
    piVal = &iVal;   // 整数类型的指针变量，指向iVal变量的地址

    double *pdVal = &dVal;    //实数类型的指针变量，指向dVal变量的地址


    cout << "piVal变量地址为" << piVal << endl;    // 直接打印指针变量，输出的是指针指向的内存地址
    cout << "piVal变量所指向地址的数据内容为" << *piVal << endl;     // 加*代表,指针变量指向的地址的数据内容


    *piVal = 20; // 重新设置piVal指针变量的数据内容为20
    cout << "piVal变量地址为" << piVal << endl;    // 直接打印指针变量，输出的是指针指向的内存地址
    cout << "iVal的数据内容为" << iVal << endl;    // 我们打印看看之前声明的那个变量
    cout << "piVal指针变量重新设置后，iVal的数据内容同步更改为" << iVal << endl;
    cout << "piVal变量所指向地址的数据内容为" << *piVal << endl;     // 加*代表,指针变量指向的地址的数据内容


    cout << "pdVal变量地址为" << pdVal << endl;
    cout << "pdVal变量所指向地址的数据内容为" << *pdVal << endl;    // 123.45


    *pdVal = 67.1234; //重新设置pdVal指针变量的数据内容为67.1234
    cout << "pdVal指针变量重新设置后，dVal的数据内容同步更改为" << dVal << endl;  // 67.1234
    // sizeof 是一个关键字，它是一个编译时运算符，用于判断变量或数据类型的字节大小。
    // sizeof 运算符可用于获取类、结构、共用体和其他用户自定义数据类型的大小。
    // 使用 sizeof 的语法如下：sizeof (data type)
    // 其中，data type 是要计算大小的数据类型，包括类、结构、共用体和其他用户自定义数据类型。
    cout << "双精度实数dVal所占用的内存空间为：" << sizeof(dVal) << "位" << endl;  //
    cout << "双精度实数指针变量pdVal所占用的内存空间为：" << sizeof(pdVal) << endl;

    return 0;
}

