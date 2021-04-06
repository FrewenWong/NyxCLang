//
// Created by wangzhijiang on 2021/4/2.
//
#include <stdio.h>
#include <iostream>
#include "utils/log_utils.h"
#include "utils/help_utils.h"

// 声明使用vision_app这个明明空间
using namespace vision_app;

/**
 * VisionApp的入口函数
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {

    // 日志打印的方法
    printf("=====Hello VisionApp=========\n");
    // fprintf(stdout, "=====Hello VisionApp=========");
    // https://blog.csdn.net/u011675745/article/details/51939108
    // std::cout << "=====Hello VisionApp=========" << std::endl;
    LogUtils::configLog();

    // 进行Main函数的参数处理
    HelpUtils::handleArguments(argc, argv);


}