
#include <iostream>

using namespace std;

int main() {
    cout << "Size of char : " << sizeof(char) << endl;              // 一个字节
    cout << "Size of short int : " << sizeof(short int) << endl;    // 两个字节
    cout << "Size of int : " << sizeof(int) << endl;                // 四个字节
    cout << "Size of float : " << sizeof(float) << endl;            // 四个节点
    cout << "Size of long int : " << sizeof(long int) << endl;      // 八个字节
    cout << "Size of double : " << sizeof(double) << endl;          // 八个字节
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
    return 0;
}
