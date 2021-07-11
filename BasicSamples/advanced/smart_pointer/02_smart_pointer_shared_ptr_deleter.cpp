//
// Created by Frewen.Wong on 2021/7/11.
//
#include <iostream>
#include <memory>   //使用shared_ptr需要include它

/**
 * 定义一个结构体
 */
struct Sample {
    Sample() {
        std::cout << "Sample Constructor Called\n";
    }

    ~Sample() {
        std::cout << "Sample DeConstructor Called\n";
    }
};

//在接收到的指针上调用delete[]的函数
void deleter(Sample *x) {
    std::cout << "DELETER FUNCTION CALLED\n";
    delete[] x;
}


int main() {

    //使用定制的deleter创建shared_ptr
    std::shared_ptr<Sample> p3(new Sample[12], deleter);
    return 0;
}