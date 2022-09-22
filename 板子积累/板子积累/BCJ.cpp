//并查集

#include <bits/stdc++.h>
using namespace std;
int fa[200]; //假设每个节点的的编号为数组下表，数组元素代表这个节点的父节点
int n;       //编号范围
void init()  //初始化,即将每个点的父节点设置为自己
{
    for (int i = 0; i < n; i++)
    {
        fa[i] = i;
    }
}
int find(int i) //通过编号查找父节点
{
    if (fa[i] == i) //找到祖先位置
    {
        return i;
    }
    else //递归查找
    {
        return find(fa[i]);
    }
}
int find_plus(int i) //通过压缩路径优化
{
    if (fa[i] == i)
    {
        return i;
    }
    else
    {
        fa[i] = find(fa[i]);
        return fa[i];
    }
}
void merge(int x, int y) //合并操作,将x的祖先指向y的祖先
{
    int i = find(x);
    int j = find(y);
    fa[i] = fa[j];
}
int main()
{
}