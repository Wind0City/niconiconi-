//正常的线段树，不过一般不会过于明显
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;            //原始数组大小
int a[N];         //原始数组
int s[N << 2];    //线段树数组,一般开四倍足够用；
void push(int sx) //单点更新，此处形参代表的是线段树数组的下标
{
    //对应的更新；总会涉及st*2(左儿子)和st*2+1(右儿子)
}
void bulid(int sx, int l, int r) // sx与上方法意思一样
{
    if (l == r)
    {
        //递归到叶子节点的对应，一般是此区间也就是这个点，赋值给线段数组
        return;
    }
    int mid=l+r>>1;//如果没到叶子节点，进行分治
    bulid(sx*2,l,mid);//每个父节点对应的左儿子的下标是父节点的下标*2
    bulid(sx*2+1,mid+1,r);//右节点是父节点下标*2+1（线段数组的基本定义）
    push(sx);//假设对某一个节点的左右儿子节点建立完，则要对父节点更新
}
//build(1,1,n);//将a数组元素从1-n建立线段树
void insert(int sx,int l,int r, int x,int v)//单点修改，将a[x]的值修改为v
{
    if(l==r)//找到对应的叶子节点
    {
        s[sx]=v;
        return;
    }
    int mid =l+r>>1;
    if(x<=mid)//修改的节点在当前父节点的左儿子里
    {
        insert(sx*2,l,mid,x,v);
    }
    else//在右儿子节点
    {
        insert(sx*2+1,mid+1,r,x,v);
    }
    push(sx);//和建树一样修改完后要更新父节点
}
//区间修改可以暴力的进行重复的单点修改，可写成函数
int ask1(int sx,int l,int r,int L,int R)//正常的区间查询,[L,R]为要查询的区间，L==R时为单点查询
{
    if(L<=l&&r<=R)//如果当前递归的区间刚好完全包含于要查询的区间
    {
        return s[sx];//返回当前的线段树节点所代表的区间信息
    }
    int mid=l+r>>1;
    int ansl;
    if(L<=mid)//如果当前的递归区间与要查询的区间左边相交
    {
        /*ask1(sx*2,l,mid,L,R)*/
        //继续对左儿子进行查询递归
    }
    if(R>=mid+1)//如果当前的递归区间与要查询的区间右边相交
    {
        /*ask1(sx*2,mid+1,r,L,R)*/
        //继续对右儿子进行查询递归
    }
    return ansl;//查询完后要返回
}