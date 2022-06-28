#include <iostream>
#include <numeric>   //算术算法头文件
#include <algorithm> //泛型算法头文件
#include <string>
#include <vector>
using namespace std;
bool cmp(const int &s1, const int &s2) //降序排列自定义函数
{
    return s1 > s2 ? true : false;
}
bool judge(const int &a) // count_if需要的条件函数
{
    return a > 5;
}
int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> a(x, x + 10);

    // 1.只读算法
    //  1.1.accumulate函数,定义在numeric头文件中
    int num;
    int ans = accumulate(a.begin(), a.end(), num);
    /*个人理解为在num基础上的累加算法,返回类型就是其第三个实参的类型*/

    // 1.2.find_first_of函数,类型不必精确匹配,只要可以使用==操作符进行比较即可。
    find_first_of(a.begin(), a.begin() + 5, a.begin() + 5, a.end());
    /*查找两个范围(可以是相同容器，也可以是不同容器)内相匹配的第一个的迭代器*/
    /*实际使用应该不断变化目标容器的的迭代区间左值来进行统计相同个数*/

    // 2.写容器元素的算法
    // 2.1fill()//对该范围内所有赋值
    fill(a.begin(), a.end(), 5);

    // 2.2fill_n()不检查写入操作的算法
    fill_n(a.begin(), 10, 2); //从迭代器指向的元素开始，多重集合（将指定数量的元素设置为给定的值
                              /* 2.3copy*/
    // copy的用法见aboutcopy相关文件，简单的使用是够的

    // 3.对容器元素重新排序的算法
    // 3.1unique()  unique把重复的元素添加到容器末尾，而返回值是去重之后的尾地址(地址!!!)
    unique(a.begin(), a.end());
    // 3.2stable_sort()稳定排序
    stable_sort(a.begin(), a.end(), cmp);
    // 3.3count_if()//返回区间中满足指定条件的元素数目。
    count_if(a.begin(), a.end(), judge);
}