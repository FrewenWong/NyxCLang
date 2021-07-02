//
// Created by Frewen.Wong on 2021/6/30.
//
#include <iostream>
#include <fstream>

using namespace std;

// 到目前为止，我们已经使用了 iostream 标准库，它提供了 cin 和 cout 方法分别用于从标准输入读取流和向标准输出写入流。
//本教程介绍如何从文件读取流和向文件写入流。这就需要用到 C++ 中另一个标准库 fstream，它定义了三个新的数据类型：
//数据类型	描述
//ofstream	该数据类型表示输出文件流，用于创建文件并向文件写入信息。
//ifstream	该数据类型表示输入文件流，用于从文件读取信息。
//fstream	该数据类型通常表示文件流，且同时具有 ofstream 和 ifstream 两种功能，这意味着它可以创建文件，向文件写入信息，从文件读取信息。

//要在 C++ 中进行文件处理，必须在 C++ 源代码文件中包含头文件 <iostream> 和 <fstream>。



//打开文件
//在从文件读取信息或者向文件写入信息之前，必须先打开文件。
//ofstream 和 fstream 对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用 ifstream 对象。

//下面是 open() 函数的标准语法，open() 函数是 fstream、ifstream 和 ofstream 对象的一个成员。
//void open(const char *filename, ios::openmode mode);

//在这里，open() 成员函数的第一参数指定要打开的文件的名称和位置，第二个参数定义文件被打开的模式。
//模式标志	描述
//ios::app	追加模式。所有写入都追加到文件末尾。
//ios::ate	文件打开后定位到文件末尾。
//ios::in	打开文件用于读取。
//ios::out	打开文件用于写入。
//ios::trunc	如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。


//您可以把以上两种或两种以上的模式结合使用。例如，如果您想要以写入模式打开文件，并希望截断文件，以防文件已存在，那么您可以使用下面的语法：
//ofstream outfile;
//outfile.open("file.dat", ios::out | ios::trunc );

//类似地，您如果想要打开一个文件用于读写，可以使用下面的语法：
//fstream  afile;
//afile.open("file.dat", ios::out | ios::in );






class FileDemo {
public:
    /**
     * FileDemo的构造函数
     * @param v
     */
    FileDemo(int value) : var(value) {
        // fopen_s(&file, "test", "r");
    }

    ~FileDemo() {
        fclose(file);
    }

private:
    int var;
    FILE *file;
};


int main() {
    char data[20];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("aFile.dat");

    cout << "开始写入文件：" << endl;
    cout << "请输入你的名称: ";
    // cin、cin.getline()、getline()的用法
    // https://blog.csdn.net/u011630575/article/details/79721024
    cin.getline(data, 20);
    // 向文件写入用户输入的数据
    outfile << data << endl;

    cout << "请输入你的年龄：";
    cin >> data;
    cin.ignore();
    // 再次向文件写入用户输入的数据
    outfile << data << endl;

    // 关闭打开的文件
    outfile.close();





    // 以读模式打开文件
    ifstream infile;
    infile.open("aFile.dat");

    cout << "读取文件的内容：" << endl;
    infile >> data;
    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    cout << "再次读取文件的内容：" << endl;
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();

}
