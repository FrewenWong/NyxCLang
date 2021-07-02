//
// Created by Frewen.Wong on 2021/6/30.
//
#include <iostream>
#include <fstream>

using namespace std;

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
