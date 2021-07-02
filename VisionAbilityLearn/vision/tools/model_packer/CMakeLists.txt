
set(CXX g++)
set(CMAKE_CXX_STANDARD 14)    #设置C++d的标砖
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


# 设置变量
set(TOOL_NAME merge_model_tool)

# CMakeLists 关于List的使用方法
#list(LENGTH <list><output variable>)                                        // 返回list的长度
#list(GET <list> <elementindex> [<element index> ...]<output variable>)
#list(APPEND <list><element> [<element> ...])                                // 添加新element到list中
#list(FIND <list> <value><output variable>)
#list(INSERT <list><element_index> <element> [<element> ...])
#list(REMOVE_ITEM <list> <value>[<value> ...])
#list(REMOVE_AT <list><index> [<index> ...])
#list(REMOVE_DUPLICATES <list>)
#list(REVERSE <list>)
#list(SORT <list>)
list(APPEND packer_src
        main.cpp
        merge_tool.cpp)


# # 规定.h头文件路径
#include_directories(
#        ${CMAKE_BINARY_DIR}
#)

# 编译可执行程序的逻辑
# 将packer_src的list中所有的文件增加可执行文件
# TOOL_NAME 为可执行文件的名称
# packer_src可执行文件的列表
add_executable(${TOOL_NAME} ${packer_src})