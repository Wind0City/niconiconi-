// list用法
#include <iostream>
#include <list> //list
using namespace std;
int main()
{
    int x[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 1.list的构造:
    list<int> a(x, x + 9); //构造函数将[beg, end)区间中的元素拷贝给本身。注意该区间是左闭右开的区间。
    list<int> b(a.begin(), b.end());
    list<int> c(a);     //拷贝构造函数。
    list<int> d(10, 2); //构造函数将n个elem拷贝给本身
    list<int> e(0);
    // 2.迭代器的使用:
    //   2.1.使用正向迭代器正向list中的元素
    for (list<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    // 2.1.使用反向迭代器逆向打印list中的元素
    list<int>::reverse_iterator it;
    for (it = a.rbegin(); it != a.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //常用内置函数使用:
    // 3.头尾的添加移除操作:
    a.push_back(1);  //在容器尾部加入一个元素
    a.pop_back();    //删除容器中最后一个元素
    a.push_front(1); //在容器开头插入一个元素
    a.pop_front();   //从容器开头移除第一个元素

    // 4.数据存取:
    a.front(); //返回第一个元素
    a.back();  //返回最后一个元素

    // 5.赋值操作:
    a.assign(x + 2, x + 5); //将[beg, end)区间中的数据拷贝赋值给本身。注意该区间是左闭右开的区间。
    a.assign(10, 2);        //将n个elem拷贝赋值给本身。
    a.swap(b);              //互换

    // 6.大小:
    a.size();        //返回容器中元素的个数
    a.empty();       //判断容器是否为空
    a.resize(10);    //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
    a.resize(10, 2); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除

    // 7.插入元素**
    list<int>::iterator kik;
    kik = a.begin();
    a.insert(kik, 5);                  //在pos位置插入一个elem元素的拷贝，返回新数据的位置
    a.insert(kik, 2, 29);              //在pos位置插入n个elem数据，无返回值。
    a.insert(kik, b.begin(), b.end()); //在pos位置插入[beg,end)区间的数据，无返回值。

    // 8.删除元素
    a.clear();                   //移除容器的所有数据
    a.erase(a.begin(), a.end()); //删除[beg,end)区间的数据，返回下一个数据的位置
    a.erase(kik);                //删除pos位置的数据，返回下一个数据的位置。
    a.remove(1);                 //删除容器中所有与elem值匹配的元素。
    /*
    **对于list的单点位置操作，只能由迭代器来进行，而且begin与end不能加减num
    **不支持随机访问容器 begin()+6 (x)
    **
    */

    // 9.
    a.sort();
    a.reverse(); //反转链表
}