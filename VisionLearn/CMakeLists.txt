# 本CMakeLists.txt的project名称

# 会自动创建两个变量，PROJECT_SOURCE_DIR和PROJECT_NAME
# ${PROJECT_SOURCE_DIR}：本CMakeLists.txt所在的文件夹路径
# ${PROJECT_NAME}：本CMakeLists.txt的project名称

#第一步：CMake的版本号
cmake_minimum_required(VERSION 3.10)

#第二步：设置CMake设置的C++的标砖
set(CMAKE_CXX_STANDARD 14)

#第三步：
project(VisionLearn)    #必须这个是一个工程必须的

# ================= 编译的配置选项==============================
option(BUILD_EXAMPLES "build examples" OFF)   # 编译实例
option(BUILD_TOOLS "build tools" ON)         # 编译Tools


# set变量的语句
# set product mode: mainline(主线)
# or other projects(ford_cd542, toyota_760, toyota_030d, chery ...)
set(PRODUCT mainline)

#第四步： 添加需要编译的子目录
add_subdirectory(vision)    #父目录必须，子目录不必


# add_library(库文件名称 STATIC 文件)  #通常子目录(二选一)
# add_executable(可执行文件名称 文件)   #通常父目录(二选一)


# target_link_libraries(库文件名称/可执行文件名称 链接的库文件名称)  #必须
