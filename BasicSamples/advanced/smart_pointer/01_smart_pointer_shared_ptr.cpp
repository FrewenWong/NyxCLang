//
// Created by Frewen.Wong on 2021/7/11.
//
#include <iostream>
#include <memory>   //使用shared_ptr需要include它

int main() {
    //通过make_shared创建shared_ptr
    std::shared_ptr<int> p1 = std::make_shared<int>();
    // 给这个指针数据进行赋值
    *p1 = 78;

    std::cout << "p1 = " << *p1 << std::endl;

    //查看引用计数
    std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

    //第二个shared_ptr也将在内部指向相同的指针,这将会使引用计数变为2
    std::shared_ptr<int> p2(p1);

    //查看引用计数
    // p2 Reference count = 2
    // p1 Reference count = 2
    std::cout << "p2 Reference count = " << p2.use_count() << std::endl;
    std::cout << "p1 Reference count = " << p1.use_count() << std::endl;

    //比较智能指针。我们可以看到p1和p2其实是同一个指针
    if (p1 == p2) {
        std::cout << "p1 and p2 are pointing to same pointer\n";
    }

    std::cout << "Reset p1" << std::endl;
    //重置shared_ptr，在这种情况下，其内部不会指向内部的任何指针
    //因此其引用计数将会变为0
    p1.reset();
    std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;

    //重置shared_ptr，在这种情况下，其内部将会指向一个新的指针
    //因此其引用计数将会变为1
    p1.reset(new int(11));
    std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;

    //分配nullptr将取消关联指针并使其指向空值
    p1 = nullptr;
    std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;

    if (!p1) {
        std::cout << "p1 is NULL" << std::endl;
    }

    return 0;
}