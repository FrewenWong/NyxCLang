//
// Created by Frewen.Wong on 2021/7/2.
//

//Map的使用
//需要导入头文件
#include <map> // STL头文件没有扩展名.h

//map 对象是一个模版类，需要关键字和存储对象两个模版参数
//std::map<int, std::string> person; // 其实就是一个Key-Value键值对

//可以对模版进行类型定义使其使用方便
//typedef std::map<int , std::string> MAP_INI_STRING;
//MAP_INI_STRING person;

//Map 的构造
//1、map 最基本的构造函数；
//std::map<int , std::string> mapPerson;

//2、map 添加数据；

//1) insert 函数插入 pair 数据
//std::map < int , std::string > mapPerson;
//mapPerson.insert(pair < int,string > (1,"Jim"));

//2)insert 函数插入 value_type 数据
//mapPerson.insert(std::map < int, std::string > ::value_type (2, "Tom"));

//3、Map 数据的遍历
//三种最常用的遍历方法：
//1)前向迭代器
//std::map < int ,std::string > ::iterator it;
//std::map < int ,std::string > ::iterator itEnd;
//it = mapPerson.begin();
//itEnd = mapPerson.end();
//while (it != itEnd) {
//cout<<it->first<<' '<<it->second<<endl;
//it++;
//}

//2)反向迭代器
//std::map < int, string > ::reverse_iterator iter;
//for(iter = mapPerson.rbegin(); iter != mapPerson.rend(); iter++)
//cout<<iter->first<<"  "<<iter->second<<endl;

//3)数组形式
//mapPerson.insert(std::map<int, std::string>::value_type (1, "Tom"));
//mapPerson[2] = "Jim";
//mapPerson[3] = "Jerry";
//
//int nSize = mapPerson.size();
//for(int n = 1; n <= nSize; n++)
//qDebug()<<QString::fromStdString(mapPerson[n]);

//三种都是遍历，建议使用前向迭代器，慎用使用数组形成（角标开始位置谨慎）。

int main() {

    std::map<int, std::string> map1;
    std::map<int, int> map2;
    std::map<int, std::string> map3;

    map1.insert(pair<int, std::string>(1, "map1Value1"));
    map1.insert(std::map<int, std::string>::value_type(1, "Tom"));
}