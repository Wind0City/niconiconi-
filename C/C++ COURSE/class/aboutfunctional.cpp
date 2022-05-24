/*若一个类重载了运算符 “()”，则该类的对象就成为函数对象。*/
#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
using namespace std;
// eg:
class myaverage
{
public:
    double operator()(int a1, int a2, int a3)
    {
        return (double)(a1 + a2 + a3) / 3;
    }
} average;
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    average(1, 2, 3);

    //提一嘴函数指针
    int (*p)(int, int); //函数指针的定义
    // int (*p)();             //函数指针的另一种定义方式，不过不建议使用
    // int (*p)(int a, int b); //也可以使用这种方式定义函数指针

    p = max; //函数指针初始化

    int ret = p(10, 15); //函数指针的调用
    // int ret = (*max)(10, 15);
    // int ret = (*p)(10, 15);
    //以上两种写法与第一种写法是等价的，不过建议使用第一种方式
    printf("max = %d \n", ret);

    //常用的函数对象
    //元素按 “<” 规定的比较方法升序排列  greater
    //元素按 “>” 规定的比较方法升序排列  less

    /*高端的建议自行搜索，或者自己写，(●°u°●) 」(doge)*/
}