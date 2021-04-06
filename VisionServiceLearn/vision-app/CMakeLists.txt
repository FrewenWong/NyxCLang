
message(STATUS "=============开始编译VisionApp==================")

#
option(BUILD_TOOLS "build tools" OFF)
# 设置VisionApp的名字
set(VISION_APP_NAME vision_app)
# 设置VisionApp的代码目录 ./vision-app/src
set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 设置camera模块的文件目录
# collect_source_files的方法是在最外部定义一个的一个宏（macros）
collect_source_files(module_srcs GLOB_RECURSE camera)
collect_source_files(module_srcs GLOB_RECURSE utils)

list(APPEND srcs
        ${module_srcs}
        ${SRC_ROOT}/vision_app.cpp)


# 增加编译可执行程序的逻辑
add_executable(${VISION_APP_NAME} ${srcs})