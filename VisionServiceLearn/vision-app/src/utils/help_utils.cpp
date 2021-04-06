//
// Created by wangzhijiang on 2021/4/6.
//

#include "help_utils.h"

namespace vision_app {
    static const char *TAG = "HelpUtils";

    /**
     * VisionApp的参数处理
     * @param argc
     * @param argv 二级指针（因为这个参数是main函数里面传入的字符串数组）
     * 关于二级指针：https://blog.csdn.net/daiyutage/article/details/8604720
     */
    void HelpUtils::handleArguments(int argc, char **argv) {
        if (argc == 1) {
            // print start and version info
            // VLOGI(TAG, "vision-app starts, version %s", VISION_VERSION_STR);
            return;
        }
        //
        if (argc >= 2) {
            if (strcmp(argv[1], "-v") == 0 ||
                strcmp(argv[1], "--version") == 0) {
                // VLOGI(TAG, "version: %s", VISION_VERSION_STR);
                exit(0);
            }
        }
    }
}