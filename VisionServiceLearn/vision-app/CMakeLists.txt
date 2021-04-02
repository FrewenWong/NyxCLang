
message(STATUS "=============开始编译VisionApp==================")

#
option(BUILD_TOOLS "build tools" OFF)
# 设置VisionApp的名字
set(VISION_APP_NAME vision_app)
# 设置VisionApp的代码目录 ./vision-app/src
set(SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 设置camera模块的文件目录
# collect_source_files的方法是在最外部定一个
collect_source_files(module_srcs GLOB_RECURSE camera)

list(APPEND srcs
        ${module_srcs}
        ${SRC_ROOT}/vision_app.cpp)