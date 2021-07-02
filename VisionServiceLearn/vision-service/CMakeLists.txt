message(STATUS "=============VisionService的CMake编译脚本==================")




if (BUILD_UNIT_TEST)
    add_subdirectory(test)
endif()