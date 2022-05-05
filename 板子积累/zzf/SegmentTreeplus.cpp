//假设这道是关于区间和
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct stree //结构体方法，更清晰一点
{
    int num;  //区间信息
    int l, r; //区间范围
    int tag;  //懒标记
} a[N << 2];
int b[N]; //原始数组
void push(int st)
{
    a[st].num = a[st * 2].num + a[st * 2 + 1].num;
    //对应的更新,总会涉及st*2(左儿子)和st*2+1(右儿子)
}
void bulid(int st, int l, int r) // st标识线段数组下标，递归建立
{
    a[st].l = l;
    a[st].r = r;
    if (l == r)
    {
        a[st].num == b[l]; //递归到底也是叶子节点
        a[st].tag = 0;
    }
    int mid = l + r >> 1;
    bulid(st * 2, l, mid); //每个父节点对应的左儿子的下标是父节点的下标*2
    bulid(st * 2 + 1, mid + 1, r);
    push(st);
}
void insert(int sum, int x, int v) //单点修改，将a[x]的值修改为v，改进版
{
    if (a[sum].l == a[sum].r) //递归找到对应的叶子节点
    {
        a[sum].num = v;
        return;
    }
    int mid = a[sum].l + a[sum].r >> 1;
    if (x <= mid) //修改的节点在当前父节点的左儿子里
    {
        insert(sum * 2, x, v);
    }
    else //在右儿子节点
    {
        insert(sum * 2 + 1, x, v);
    }
    push(sum); //和建树一样修改完后要更新父节点
}
void spread(int sum) //下放标记,假设这道区间修改是要相加的
{
    if (a[sum].tag) //如果当前的节点有标记
    {
        a[sum << 1].num += (a[sum << 1].r - a[sum << 1].l + 1) * a[sum].tag; //将标记下放给左儿子
        a[sum << 1].tag += a[sum].tag;
        a[sum << 1 | 1].num += (a[sum << 1 | 1].r - a[sum << 1 | 1].l + 1) * a[sum].tag; //将标记下放给右儿子
        a[sum << 1 | 1].tag += a[sum].tag;
        a[sum].tag = 0;
    }
}
void change(int l, int r, int sum, int d) //区间修改,sum可以代表一个区间,即当前递归到的区间,l,r为修改的区间
{
    if (l <= a[sum].l && r >= a[sum].r) //如果当前递归区间完全在要修改的区间内
    {
        a[sum].num += (a[sum].r - a[sum].l + 1) * d; //区间信息修改并打上标记
        a[sum].tag += d;
        return;
    }
    spread(sum); //如果不符合上述情况，将标记下放
    int mid = (a[sum].l + a[sum].r) >> 1;
    if (l <= mid) //如果当前递归区间与要修改的区间做部分有交集，修改要修改区间的左部分（以要修改区间的中间为界）
    {
        change(l, mid, sum * 2, d);
    }
    if (r > mid) //如果当前递归区间与要修改的区间做部分有交集，修改要修改区间的右部分（以要修改区间的中间为界）
    {
        change(mid + 1, r, sum * 2 + 1, d);
    }
    return;
}
int ask(int sum, int l, int r) //区间查询
{
    if (l <= a[sum].l && r >= a[sum].r) //递归区间递归到完全包含于所查询区间
    {
        return a[sum].num; //返回区间信息；
    }
    spread(sum); //如果不满足上述条件，始终要下放标记并清零
    int mid = a[sum].l + a[sum].r >> 1;
    int ans = 0;
    if (l <= mid)
    {
        /*ask(sx*2,l,mid)*/
        //对左儿子递归查询
    }
    if (r > mid)
    {
        /*ask(sx*2+1,mid+1,r)*/
        //对右儿子递归查询
    }
    return ans;
    //最终返回的答案
}