/*
set就是集合，STL的set用二叉树实现，集合中的每个元素只出现一次
(参照数学中集合的互斥性)，并且是排好序的(默认按键值升序排列)
set中数元素的值并不能直接被改变。
*/
#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <vector>
#include <list>
using namespace std;
struct jgt
{
    /* data */
};
struct node
{
    int a, b;
    bool operator<(const node W) const
    {
        return a > W.a; //按a的值升序
    }
} t;
int main()
{
    // set 的定义:默认按键值升序
    set<int> g1;
    set<char> g2;
    set<string> g3;
    set<jgt> g4; //结构体的类型
    set<vector<int>> g5;
    set<list<double>> g6;
    set<int, greater<int>> g7; //降序排列
    set<int, less<int>> g8;    //升序排列
    set<node> a;               //按照结构体内部的运算符重载进行排序放入
    // set 容器内元素的访问(set 只能通过迭代器访问)
    /*除开 vector 和 string 之外的 STL 容器都不支持 *(it+i) 的访问方式*/
    for (set<char>::iterator it = g2.begin(); it != g2.end(); it++)
    {
        *it; //访问
    }

    // set的基本操作函数:
    // 1.添加元素
    g2.insert('h'); // insert(x) 可将 x 插入 set 容器中，并自动递增排序和去重，时间复杂度为 O（logN），其中 N 为 set 内的元素个数。
    // 2.查找
    g2.find('l'); // find(value) 返回 set 中对应值为 value 的迭代器，时间复杂度为 O（logN），其中 N 为 set 内的元素个数。
    // 3.删除:
    char value;
    set<char>::iterator it2 = g2.begin();
    g2.erase(value);                // value 为所需要删除元素的值,时间复杂度为 O（logN）
    g2.erase(it2);                  //即删除迭代器为 it 处的元素，时间复杂度为 O（1）可以结合 find() 函数来使用
    g2.erase(g2.begin(), g2.end()); //删除一个区间内的所有元素。

    //其他与前面容器相同的操作函数，具体可以看以前的，不做过多注释:
    g2.size();
    g2.max_size();
    g2.begin();
    /*...(ignore end and so on)*/
    g2.clear();
    g2.empty();
    g2.swap(g2);
    g2.emplace(it2, value); //插入元素
    g2.find(value);         //在q中查找x，返回x的迭代器，若x不存在，则返回指向q尾部的迭代器即 q.end()
    g2.lower_bound(value);
    g2.upper_bound(value);
}
