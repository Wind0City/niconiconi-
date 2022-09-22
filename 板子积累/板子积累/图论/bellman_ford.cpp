//最短路的bellman-ford算法及其优化
#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
int dis[maxn];  //与出发点的最短路径
int bis[maxn];  //记录dis的数组，第三次 优化循环会用到
int path[maxn]; //路径记录
//这里用存边方法
struct node
{
    int from, to;
    int w;
};
node bb[maxn];                //所有的边
int n, m = 1;                 //点数以及变数
void add(int x, int y, int z) //加边
{
    bb[m].from = x;
    bb[m].to = y;
    bb[m].w = z;
    m++;
}
void bellman(int dex) //正常的求最短路
{
    memset(dis, 0x3f, sizeof(dis));
    dis[dex] = 0;
    for (int k = 1; k <= n - 1; k++) //循环点的个数n-1次，原因是一个点到另一个点最短路径的经过最多边为n-1条边
    {
        for (int i = 1; i <= m - 1; i++) //循环所有边
        {
            if (dis[bb[i].to] > dis[bb[i].from] + bb[i].w) //松弛操作
            {
                dis[bb[i].to] = dis[bb[i].from] + bb[i].w;
            }
        }
    }
}
void bellman_plus(int dex) //检测是否有负权回路的优化
{
    memset(dis, 0x3f, sizeof(dis));
    dis[dex] = 0;
    for (int k = 1; k <= n - 1; k++) //循环点的个数n-1次
    {
        for (int i = 1; i <= m - 1; i++) //循环所有边
        {
            if (dis[bb[i].to] > dis[bb[i].from] + bb[i].w) //松弛操作
            {
                dis[bb[i].to] = dis[bb[i].from] + bb[i].w;
            }
        }
    }

    //检测负权回路,其实就是再进行所有点的松弛操作后，是否还有能松弛的机会
    int flag = 0;
    for (int i = 1; i <= m - 1; i++) //循环所有边
    {
        if (dis[bb[i].to] > dis[bb[i].from] + bb[i].w) //发现还能进行松弛操作松弛操作
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << "负权回路" << endl;
}
void bellman_plus_plus(int dex) //检是否在循环到最后一层时已经求出最短路的优化，其实就是开一个记录数组，如果两次循环前后dis没有变，那是已经求出最短路了
{
    for (int i = 1; i <= n; i++) //后面查重会用
    {
        bis[i] = dis[i];
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(path, -1, sizeof(path));
    dis[dex] = 0;
    for (int k = 1; k <= n - 1; k++) //循环点的个数n-1次
    {
        for (int i = 1; i <= m - 1; i++) //循环所有边
        {
            if (dis[bb[i].to] > dis[bb[i].from] + bb[i].w) //松弛操作
            {
                dis[bb[i].to] = dis[bb[i].from] + bb[i].w;
                path[bb[i].to] = bb[i].from;
            }
        }
        //检测是否已经最短路了
        int check = 0;
        for (int i = 1; i <= n; i++)
        {
            if (bis[i] != dis[i])
            {
                check = 1;
                break;
            }
        }
        if (!check) //如果松弛之后未变化，那是已经是最短路了,直接停止循环即可
        {
            break;
        }
    }
    //检测负权回路,其实就是再进行所有点的松弛操作后，是否还有能松弛的机会
    int flag = 0;
    for (int i = 1; i <= m - 1; i++) //循环所有边
    {
        if (dis[bb[i].to] > dis[bb[i].from] + bb[i].w) //发现还能进行松弛操作松弛操作
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << "负权回路" << endl;
    }
}
vector<int> p;
void getpath(int x)
{
    if (x == 1) //指向起始点，这里以1为起点做样例
    {
        p.push_back(1);
        return;
    }
    if (x != -1)
    {
        getpath(path[x]);
    }
    p.push_back(x);
}
int main()
{
    n = 7;
    add(1, 3, 2);
    add(1, 2, 5);
    add(3, 4, 6);
    add(2, 4, 1);
    add(3, 6, 8);
    add(2, 5, 6);
    add(4, 6, 2);
    add(4, 5, 1);
    add(5, 7, 7);
    add(6, 7, 3);
    bellman_plus_plus(1);
    getpath(7);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i] << "->";
    }
}