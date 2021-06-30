//
// Created by Frewen.Wong on 2021/6/29.
//

#include <iostream>

using namespace std;

// 第一个命名空间
namespace first_space {
    void func() {
        cout << "Inside first_space" << endl;
    }
}

// 第二个命名空间
namespace second_space {
    void func() {
        cout << "Inside second_space" << endl;
    }
}

using namespace first_space;

int main() {
    // 调用第一个命名空间中的函数
    func();
    // 调用第二个命名空间中的函数
    second_space::func();
    // Inside first_space
    // Inside second_space
    return 0;
}