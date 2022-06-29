/*deque，double ended queue即双端队列，是一种在两端均可以扩展或者收缩的序列化容器。
deque可以在头部和尾部进行插入和删除操作。*/
#include <iostream>
#include <iterator>
#include <deque>
using namespace std;
int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 1.deque的构造:
    deque<int> v1;
    deque<int> v2(v1);
    deque<int> v3 = v2;
    deque<int> v4(10, 2); // v3中有n个元素，并且值都为value
    deque<int> v5(10);    // v4包含了n个重复执行了值初始化的对象
    deque<int> v6{1, 2, 3, 4, 5};
    deque<int> v7 = {1, 2, 3, 4, 5};
    deque<int> v8(x, x + 10);

    // 2.deque的迭代器:
    deque<int>::iterator it;
    it = v1.begin();
    it = v1.end();
    deque<int>::const_iterator it1;
    it1 = v1.cbegin();
    it1 = v1.cend();
    deque<int>::reverse_iterator it2;
    it2 = v1.rbegin();
    it2 = v1.rend();
    deque<int>::const_reverse_iterator it3;
    it3 = v1.crbegin();
    it3 = v1.crend();
    /*
    加c的表示增加了const属性，不能用于修改元素
    .iterator,const_iterator作用：遍历容器内的元素，并访问这些元素的值。
    iterator可以改元素值,但const_iterator不可改。跟C的指针有点像。
    */

    // 3.deque容器的成员方法:/*与前面容器方法作用一样，不做详细解释，但deque是可以随机操作的，即迭代器可以+数字*/
    v1.size();     //元素个数
    v1.max_size(); //最多能容纳元素个数
    v1.resize(10);
    v1.resize(10, 5);
    v1.empty();
    v1.back();
    v1.front();
    v1.assign(10, 2);
    v1.assign(v2.begin(), v2.end());
    v1.assign(x, x + 10);
    v1.push_back(1);
    v1.push_front(1);
    v1.pop_back();
    v1.pop_front();
    v1.insert(it, 10);
    v1.insert(it, 10, 2);
    v1.insert(it, v2.begin(), v2.begin() + 5);
    v1.erase(it);
    v1.erase(v1.begin(), v1.begin() + 5);
    v1.clear();
    v1.swap(v2);
    // new:
    v1.at(5);             //使用元素的索引来访问deque，其中at(index)中index为索引，必须是合法的。
    v1.emplace(it, 10);   //插入元素
    v1.emplace_back(10);  //在deque尾部插入元素
    v1.emplace_front(10); //在deque尾部插入元素
}