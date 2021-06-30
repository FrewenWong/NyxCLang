#include "help_utils.h"
#include <cstring>
#include <cstdio>
#include "vision.h"

namespace vision_app {
    static const char *TAG = "HelpUtils";

    /**
     * VisionApp的参数处理
     * @param argc
     * @param argv 二级指针（因为这个参数是main函数里面传入的字符串数组）
     * 关于二级指针：https://blog.csdn.net/daiyutage/article/details/8604720
     */
    void HelpUtils::handleArguments(int argc, char **argv) {
        // #include <cstdio>  需要到这个包
        printf("=====Hello handleArguments===== argCount: %d", argc);
        if (argc == 1) {
            // print start and version info
            // TODO 这个VLOGI的数据是是在哪里定义的？？？
            //  VLOGI(TAG, "vision-app starts, version %s", VISION_VERSION_STR);
            return;
        }
        if (argc >= 2) {
            if (strcmp(argv[1], "-v") == 0 ||
                strcmp(argv[1], "--version") == 0) {
                // VLOGI(TAG, "version: %s", VISION_VERSION_STR);
                // exit(0);
            }
        }
    }
}