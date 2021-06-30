
# 进行开始编译VisionApp的Demo的日志打印
message(STATUS "=============开始编译VisionApp的Demo程序==================")

# 添加编译配置开关   是否打开编译配置工具工具
option(BUILD_TOOLS "build tools" OFF)

# 设置VisionApp的名字
set(VISION_APP_NAME vision_app)

# 设置VisionApp的代码目录为当前CMake文件目录 ./vision-app/src
set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 设置VisionService工程依赖的目录。为当前Cmake文件目录下面的src目录
set(VISION_SERVICE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/vision-service/src)

# 设置camera模块的文件目录
# collect_source_files的方法是在最外部定义一个的一个宏（macros）
collect_source_files(module_srcs GLOB_RECURSE camera)
collect_source_files(module_srcs GLOB_RECURSE utils)
collect_source_files(module_srcs GLOB_RECURSE handler)

# CMakeLists 关于List的使用方法。
# 相当于在srcs这个list后面添加module_srcs设置的所有文件目录。同时添加./vision-app/src/vision_app.cpp
# https://blog.csdn.net/qq_19734597/article/details/101755468
list(APPEND srcs
        ${module_srcs}
        ${SRC_ROOT}/vision_app.cpp)


# 增加编译可执行程序的逻辑。设置VISION_APP_NAME的name是vision_app
add_executable(${VISION_APP_NAME} ${srcs})