/*
map是STL的一个关联容器，它提供一对一的hash。,具体hash是啥，自行搜索(doge)
理解成字典也不是不行
map的所有元素都是pair，同时拥有实值(value)和键值(key)。
pair的第一个元素会被视为键值，第二个元素会被视为实值。
map不允许两个元素拥有相同的键值。
pair的实现是一个结构体
*/
#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;
struct A
{
    /* code */
};
int main()
{
    string dit[3] = {"hello", "world", "fuckQ"};
    int x[3] = {1, 2, 3};
    string dit2[3] = {"sasigei!", "naruto!", "baga~!"};
    int y[3] = {7, 8, 9};
    //基本构造：左类型->右类型，类型可以是基本得，也可以是类，结构体之类
    map<string, int> str_intmap;
    map<int, string> int_strmap;
    map<string, char> str_charmap;
    map<char, string> char_strmap;
    map<int, char> int_charmap;
    map<char, int> char_intmap;
    map<A, int> struct_intmap;

    map<A, int> a(struct_intmap);      //拷贝构造
    map<A, int> b(a.begin(), a.end()); //迭代器范围内的副本

    // map定义的类型：，或者说迭代器，不同的类型相当于定义不同的迭代器
    map<A, int>::key_type it1;     //键对应的类型
    map<A, int>::mapped_type it2;  //值对应的类型
    map<A, int>::value_type it3; //对应的一个pair类型(即包含键，也包含值)，first对应键，second对应值；

    // map的基本操作函数:
    map<int, string> k, j;
    // 1.给map添加元素:
    for (int i = 0; i < 3; i++) //用下标获取元素，然后赋值
    {
        k[x[i]] = dit[i];
    }
    for (int i = 0; i < 3; i++)
    {
        j[y[i]] = dit2[i];
    }
    pair<int, string> newpair(4, "niconiconi~");
    map<int, string>::value_type it4(5, "waku~waku~");
    map<int, string>::value_type it5(10, "Evayyds!");
    k.insert(newpair);            // map.insert(pair)
    k.insert(it4);                // map.insert(value_type)
    k.insert(j.begin(), j.end()); // map.insert(iterator1,iterator2)
    k.insert(++k.begin(), it5);   // map.insert(iterator,pair/value_type)
    k.insert(make_pair(11, "RNG"));
    k.insert(map<int, string>::value_type(12, "EDG"));
    // 2.查找并读取map中的元素(注意都是用键查找):输出可以用iterator->first/second输出
    map<int, string>::iterator it6;
    it6 = k.find(5);
    if (it6 != k.end())
    {
        cout << "find!" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }                  // map.find(要查找的健)，如果查到返回迭代器，没查到返回最后超出范围的迭代器，即map.end()
    string num = k[6]; //如果该键不在map容器中,那么会插入该元素

    // 3.从map中删除元素:
    k.erase(3);                  //删除键为3的元素,返回size_type类型的值表示删除元素的个数
    k.erase(--k.end());          // delete iterator -> value
    k.erase(k.begin(), k.end()); // delete iterator1-iterator2 ->value
    //与顺序容器的erase区别,顺序容器的erase返回值是一个迭代器，指向被删除元素后面的元素.

    // 4.new:
    k.lower_bound(5); //返回键值>=给定元素的第一个位置
    k.upper_bound(5); //返回键值>给定元素的第一个位置
    k.count(1);       //返回k出现1的次数(0/1)
    k.equal_range(3); //二分查找 如果nums中没有val，则返回[-1,-1];如果nums中有val，则返回val元素的起始index和结束index
    k.key_comp();     //返回比较元素key的函数 目前学习还不知道用法 I'm too vegetables
    k.value_comp();   //返回比较元素value的函数 目前学习还不知道用法

    // 5.其他与前面容器相同的操作函数，具体可以看以前的，不做过多注释
    k.clear();
    k.empty(); // return true/false
    k.size();  // return int
    k.max_size();
    k.swap(j);
    k.rend();
    k.rbegin();
    k.cbegin();
    k.cend();
    k.crbegin();
    k.crend();
}