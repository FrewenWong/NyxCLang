cmake_minimum_required(VERSION 3.17)


project(NyxCLang)

# 设置CMake设置的C++的标砖
set(CMAKE_CXX_STANDARD 14)

add_executable(NyxCLang main.cpp)


# 学习数组的相关的代码逻辑
add_executable(HelloClang1 basic/data-type/demo_size_of.cpp)
add_executable(HelloClang2 basic/array/hello_array.cpp)


# 学习指针的相关运行程序的相关的代码逻辑
add_executable(HelloClangPointer1 basic/pointer/01_demo_pointer.cpp)
add_executable(HelloClangPointer2 basic/pointer/01_demo_pointer-of-function.cpp basic/pointer/03_demo_pointer_operator.cpp)
add_executable(HelloClangPointer3 basic/pointer/02_demo_pointer_nullpt.cpp)
add_executable(HelloClangPointer5 basic/pointer/04_demo_pointer_array.cpp)
add_executable(HelloClangPointer6 basic/pointer/05_demo_pointer_new_delete.cpp)


# 学习函数的相关运行程序的相关的代码逻辑
add_executable(HelloClangFunction1 basic/function/01_demo_function_pointer.cpp)


# 学习面向对象的类的相关代码
add_executable(HelloObjectOriented1 basic/object-oriented/01_demo_object_oriented.cpp)
add_executable(HelloObjectOriented2 basic/object-oriented/15_function_obj_transform.cpp)


# 学习C++数据结构相关
add_executable(HelloCLangDataStructure basic/data-structure/01_demo_map.cpp)

# 学习C++的标准库函数
add_executable(HelloCStdio basic/stdio/01_demo_getenv.cpp)
# 学习C++的标准库函数
add_executable(HelloCStdio2 basic/name-space/01_demo_name_space.cpp)

# 学习C++其他的一些基础Demo
add_executable(HelloCLangOther basic/other/01_demo_explicit.cpp)


# 学习C++关于文档操作的File相关的Demo
add_executable(HelloCLangFile basic/file/01_demo_file.cpp)

#======================================================高级编程相关=====================================================
# 学习智能指针相关的学习
add_executable(HelloSmartPointer advanced/smart_pointer/01_smart_pointer_shared_ptr.cpp)
add_executable(HelloSmartPointer2 advanced/smart_pointer/02_smart_pointer_shared_ptr_deleter.cpp)
