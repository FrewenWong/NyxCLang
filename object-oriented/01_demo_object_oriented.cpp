//
// Created by Frewen.Wong on 2021/2/17.
//
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * 下面是Class类Student类的声明
 */
class Student {
private:
    int stuID;
    float englishScore, mathScore, articleScore;
protected:
    int stuAge;
public:
    Student() {
        cout << "调用无惨构造函数" << endl;
    }

    // 进行类的构造函数的声明，通过范围运算符在类的外面进行书写实现
    Student(int id, float english, float math, float article);

    void input_data(); //声明成员函数的原型

    void show_data();   //声明成员函数的原型
};

Student::Student(int id, float english, float math, float article) {
    cout << "调用类的含参构造函数" << endl;
    stuID = id;
    englishScore = english;
    mathScore = math;
    articleScore = article;
}

// 如果是在类外面编写成员函数，只要在外部定义时函数名称前面加上类名称与范围解析运算符（::）即可。
// 范围解析运算符的主要作用就是指出成员函数所属的类。
void Student::input_data() {
    cout << "请输入您的成绩：";
    cin >> stuID;
}

void Student::show_data() {  //实现show_data函数
    cout << "成绩是：" << stuID << endl;
}

int main() {
    Student stu1;
    stu1.input_data();
    stu1.show_data();

    cout << "===================指针方式类的实例化=================" << endl;

    Student *stuPtr = new Student();
    stuPtr->input_data();
    stuPtr->show_data();


    cout << "===================指针方式类的含参数构造函数实例化=================" << endl;

    Student *stuParamPtr = new Student(10001, 56, 78, 89);
    stuParamPtr->input_data();
    stuParamPtr->show_data();

    return 0;

}
