#include <iostream>
#include <string>
using namespace std;
//多态性：一接口多方法，接口相同实现不同
//静态多态：函数重载，运算符重载也算在其中
//同名函数的不同方法取决于前面引用的类型：创建指针或者引用来调用基类的
//基类的想调用派生类的：强制转换：
//BasePlusCommissionEmployee *derivedPtr = dynamic_cast<BasePlusCommissionEmployee *> (binding,CommissionEmployeePtr )向下强制类型转换
//动态多态：虚函数
/*
基类中的接口函数写成虚函数
 派生类中正常写
 1.因为输入输出运算符的特殊性，所以基类需声明重载输入输出运算符函数

2.由基类调用派生类的输入输出操作函数来对派生类进行输入输出

3.由于基类无法调用派生类的友元函数，所以派生类应将输入输出操作写在非输入输出运算符函数内

4.由基类的重载输入输出运算符调用派生类的输入输出操作函数，达到输入输出运算符重载的效果

5.派生类需要输入输出重载，则可在自己函数体内声明输入输出重载函数再调用操作函数

抽象类派生出新的类之后，如果派生类给出所有  纯虚函数的函数实现，这个派生类就可以声明自己的对象，因而不再是抽象类；
反之 ，如果派生类没有给出全部  纯虚函数的实现，这时的派生类仍然是一个抽象类。

6.强制转换也可以当做判等的条件，即如果转换成功指针不为0
————————————————
版权声明：本文为CSDN博主「likey3」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/likey3/article/details/24493647
*/

class cas
{
    
};
int main()
{
    string a;
    getline(cin,a);
    cout<<a;
}