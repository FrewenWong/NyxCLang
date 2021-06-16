#这个是必须的：设置cmake的最低版本号
cmake_minimum_required(VERSION 3.8)

#这个是必须的：设置工程名字
project(vision-service)

# set语句是进行变量设置。
#添加版本号
set(Vision_Service_VERSION_MAJOR 1)
set(Vision_Service_VERSION_MINOR 0)

# 这个是设置外部依赖的仓库的库目录，是当前cmake文件目录下的3rd-party
set(EXTERN_LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party) # 外部依赖的库目录
# 这个目录需要请教一下
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install) # 编译产出的安装路径


# 配置我们进行编译时候的配置开关
option(BUILD_APP "build vision_app" ON) # 是否编译 app。默认我们暂时开启
option(BUILD_UNIT_TEST "build unit test" OFF) # 是否编译单元测试程序，默认打开
option(BUILD_MOCK_INTERFACE "build mock interface lib" OFF) # 是否编译模拟接口
option(OPEN_LOG "open log" ON) # 是否打开日志，默认关掉日志

# 通过配置头文件，用于将cmake中的某些数据设置进代码中
configure_file(
        "${PROJECT_SOURCE_DIR}/VisionServiceConfig.h.in"
        "${PROJECT_BINARY_DIR}/VisionServiceConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")


if (OPEN_LOG)
    # 添加编译参数,比如add_definitions(-DVISION_DEBUG)
    # 将在gcc命令行添加VISION_DEBUG宏定义
    add_definitions(-DVISION_DEBUG)
endif ()

# 如果没有定义VISION_TARGET_OS这个变量，那么设置默认的SYS_TAG为osx
# 否则就按照编译脚本传入的参数类设置
if (NOT DEFINED VISION_TARGET_OS)
    set(SYS_TAG osx)
else ()
    # 如果设置了的话，则就按照设置的系统类型
    set(SYS_TAG ${VISION_TARGET_OS})
endif ()

# 如果没有设置编译架构这个参数，那么默认设置为x86_64位架构
# 否则就按照编译脚本传入的参数类设置
if (NOT DEFINED VISION_TARGET_ARCH)
    set(SYS_ARCH x86_64)
else ()
    set(SYS_ARCH ${VISION_TARGET_ARCH})
endif ()

# message函数就是为用户显示一条消息
message(STATUS "SYS_TAG = ${SYS_TAG}")
message(STATUS "SYS_ARCH = ${SYS_ARCH}")

# TODO 学习macro的语法的知识点
macro(collect_source_files srcs)
    # cmake_parse_arguments 为解析函数（function）或 宏（macros） 参数的命令；
    # cmake_parse_arguments(<prefix> <options> <one_value_keywords> <multi_value_keywords> <args>...)
    # <prefix>前缀, 解析出的参数都会按照 prefix_参数名 的形式形成新的变量;
    # <options>: 可选值
    # 此处包含可选项的变量名称, 对应的值为 TRUE 或 FALSE;
    # 如果传递进来的参数包含此变量,则为 TRUE 反之为 FALSE
    # <one_value_keywords>: 单值关键词列表  每个关键词仅仅对应一个值
    # <multi_value_keywords>: 多值关键词列表  每个关键词可对应多个值
    # <args>... 参数, 一般传入 ${ARGN} 即可
    cmake_parse_arguments(MODULE "" "" "GLOB;GLOB_RECURSE" ${ARGN})
    if (MODULE)
        file(GLOB files LIST_DIRECTORIES FALSE
                ${SRC_ROOT}/${MODULE_GLOB}/*.c
                ${SRC_ROOT}/${MODULE_GLOB}/*.cpp)
        list(APPEND ${srcs} ${files})
    endif ()
    if (MODULE_GLOB_RECURSE)
        file(GLOB_RECURSE files LIST_DIRECTORIES FALSE
                ${SRC_ROOT}/${MODULE_GLOB_RECURSE}/*.c
                ${SRC_ROOT}/${MODULE_GLOB_RECURSE}/*.cc
                ${SRC_ROOT}/${MODULE_GLOB_RECURSE}/*.cpp)
        list(APPEND ${srcs} ${files})
    endif ()
endmacro()


message(STATUS "ANDROID_ABI ==== ${ANDROID_ABI}")
message(STATUS "VISION_OSX ==== ${VISION_OSX}")

#这个是必须的：这个是一个编译工程必备的。
#我们先注释掉这个测试Demo。然后我们加载子目录
#add_executable(Tutorial main.cpp)


add_subdirectory(vision-service)
# 如果是构建一个App的话，那我们就vision-app的目录也添加进去
if (BUILD_APP)
    add_subdirectory(vision-app)
endif ()