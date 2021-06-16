
// 文章参考：https://blog.csdn.net/liitdar/article/details/80055236
// 在头文件中，我们经常会在头文件中见到#ifndef、#define、#endif三者一起使用的宏定义。
// 使用#ifndef、#define、#endif组合宏定义的作用是：防止头文件的重复包含和编译。
#ifndef VISION_SERVICE_LOG_UTILS_H
#define VISION_SERVICE_LOG_UTILS_H

#include <string>
/**
 * 定义命名空间
 */
namespace vision_app {

    class LogUtils {

    public:
        static void configLog();

        static void checkLog();

    private:
        static void toLower(std::string &str);

        static const char *logFileBaseName;
    };
}


#endif //VISION_SERVICE_LOG_UTILS_H
