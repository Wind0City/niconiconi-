//最短路的dijkstra算法,优化版(最小堆以及邻接表)
#include <bits/stdc++.h>
using namespace std;
#define Maxn 10005
int dis[Maxn];   //记录各个点到起始距离的数组
int check[Maxn]; //记录该点是不是已经为最短路
int path[Maxn];  //记录每一个点在最短路中的父节点
struct   node        //链式前向星
{
    int to;   //指向的节点编号
    int w;    //边的权重
    int next; //以相同节点为起点的上一条边的编号
} ene[Maxn];
int tot, head[Maxn]; // head数组用来存储以下标为起点的边的最后一条边的编号
void init_ls()       //链式向前星的初始化
{
    memset(dis, 0x3f, sizeof(dis));
    memset(head, -1, sizeof(head)); //初始化为0
    memset(check, 0, sizeof(check));
    tot = 1; //初始化边的个数（编号）
}
void add(int x, int y, int z) //链式向前星的加边
{
    //此时加边，边的编号为tot
    ene[tot].to = y;
    ene[tot].w = z;          //终点与权重的赋值
    ene[tot].next = head[x]; //指向x起点的上一条边的编号
    head[x] = tot++;         //以x为起点的第一条边的编号更新
}
void dijkstra_plus(int dex) //优化后的dj算法
{
    dis[dex] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> c; //创建一个以dex[i]为标准的最小堆,first为与出发点距，second为该点编号
    c.push({dis[dex], dex});                                                           //先把第一个推进队列以便开始操作
    while (!c.empty())                                                                 //队列不空，即所有的点没处理完之前
    {
        int node = c.top().second; //将选择的点记为队列首元素的second ，即此时要操作的编号
        c.pop();                   //操作之后这个肯定时最小的了，所以要把他pop出去
        if (check[node])           //检查是否在图的遍历中重复操作一个节点
        {
            continue;
        }
        for (int i = head[node]; ~i; i = ene[i].next) //对以该点为起点的边进行遍历
        {
            if (dis[ene[i].to] > (dis[node] + ene[i].w)) //如果这条边的终点的与出发点距大于此时的起点加上这条边的权重(即距离)
            {
                dis[ene[i].to] = dis[node] + ene[i].w; //更新
                path[ene[i].to] = node;                //记录父节点
                c.push({dis[ene[i].to], ene[i].to});   //如果更新成功了，将这个子节点入队以供操作
            }
        }
        check[node] = 1; //标记node这个的点已经是最短路
    }
}
vector<int> p;        //路径数组
void getpath(int dex) //找寻这个点到起点的最短路路径
{
    if (dex == 1)
    {
        p.push_back(1);
        return;
    }
    if (path[dex] != -1)
    {
        getpath(path[dex]);
    }
    p.push_back(dex);
}
int main()
{
    init_ls();
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
    dijkstra_plus(1);
    for (int i = 1; i <= 7; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    getpath(1);
    for (auto i : p)
    {
        if (i == p[p.size() - 1])
        {
            cout << i;
            break;
        }
        cout << i << "->";
    }
    return 0;
}