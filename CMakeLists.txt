cmake_minimum_required(VERSION 3.17)


project(NyxCLang)

# 设置CMake设置的C++的标砖
set(CMAKE_CXX_STANDARD 14)

add_executable(NyxCLang main.cpp)


# 学习数组的相关的代码逻辑
add_executable(HelloClang2 array/hello_array.cpp)


# 学习指针的相关运行程序的相关的代码逻辑
add_executable(HelloClangPointer1 pointer/01_demo_pointer.cpp)
add_executable(HelloClangPointer2 pointer/02_demo_pointer_nullpt.cpp)
add_executable(HelloClangPointer3 pointer/03_demo_pointer.cpp)
add_executable(HelloClangPointer4 pointer/04_demo_pointer_array.cpp)
add_executable(HelloClangPointer5 pointer/05_demo_pointer_new_delete.cpp)



# 学习函数的相关运行程序的相关的代码逻辑
add_executable(HelloClangFunction1 function/01_demo_function_pointer.cpp)

