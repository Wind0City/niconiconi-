#include <iostream>
using namespace std;
class Point
{
    int x, y;
    /*其他类 《名程》*///类组合==类的嵌套
public:
    Point(Point &p) //拷贝构造函数的写法==(￣(工)￣)
    {
        this->x = p.x;
        y = p.y;
    }
    Point &move(int a, int b) //返回值类型是一个整体
    {
        x += a;
        y += b;
        return *this;
    }
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};
void fun1(Point p)//变相引用拷贝构造函数
{
    /*code*/
}
void fun2(Point& p)//这种情况不会引用拷贝构造函数
{
    /*code*/
}
int main()
{
    Point obj1;
    Point obj2(obj1); //拷贝，系统会默认（在没写的前提下）
    Point obj3 = obj1;//另一种形式
}
//类组合时构造函数，形参是对象的引用，即不用拷贝构造函数（（节省空间？
