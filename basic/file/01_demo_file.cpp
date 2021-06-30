//
// Created by Frewen.Wong on 2021/6/30.
//
#include <iostream>


class FileDemo {
public:
    /**
     * FileDemo的构造函数
     * @param v
     */
    FileDemo(int value) : var(value) {
        fopen_s(&file, "test", "r");
    }

    ~FileDemo() {
        fclose(file);
    }

private:
    int var;
    FILE *file;
};

