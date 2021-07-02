set(UT_NAME vis_service_unit_test)

# 将所有的文件添加到test_srcs的文件目录下面
list(APPEND test_srcs
        ${srcs}
        test_handler.cpp)

# 添加编译的可执行程序目录
add_executable(${UT_NAME} ${test_srcs})

#
target_include_directories(${UT_NAME} PRIVATE ${GTEST_INCLUDE_DIR})
target_link_directories(${UT_NAME} PRIVATE ${GTEST_LINK_DIR})

target_link_libraries(${UT_NAME} PRIVATE ${VISION_LIB} ${SQLITE_LIB} ${OPENCV_LIB} ${GTEST_LIB})