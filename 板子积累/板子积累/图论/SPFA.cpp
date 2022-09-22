#include <bits/stdc++.h>
using namespace std;
#define Maxn 10005
int n;
int dis[Maxn];   //记录各个点到起始距离的数组
int check[Maxn]; //记录该点是不是已经在队列中出现过
int path[Maxn];  //记录每一个点在最短路中的父节点
struct ss        //链式前向星
{
    int to;   //指向的节点编号
    int w;    //边的权重
    int next; //以相同节点为起点的上一条边的编号
} ene[Maxn];
int tot, head[Maxn]; // head数组用来存储以下标为起点的边的最后一条边的编号
void init()          //链式向前星的初始化
{
    memset(dis, 0x3f, sizeof(dis));
    memset(head, -1, sizeof(head)); //初始化为0
    memset(check, 0, sizeof(check));
    memset(path, -1, sizeof(path));
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
void spfa(int dex)
{
    dis[dex] = 0;
    queue<int> q; //顶点队列
    q.push(dex);
    check[dex] = 1; //出发点已经在队列中
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        check[node] = 0;
        for (int i = head[node]; ~i; i = ene[i].next)
        {
            int v = ene[i].to;
            int w = ene[i].w;
            if (dis[v] > dis[node] + w)
            {
                dis[v] = dis[node] + w;
                path[v] = node;
                if (!check[v])
                {
                    check[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
vector<int> p;
void getpath(int dex)
{
    if (dex == 1)
    {
        p.push_back(1);
        return;
    }
    if (dex != -1)
    {
        getpath(path[dex]);
    }
    p.push_back(dex);
}
int main()
{
    n = 7;
    init();
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
    spfa(1);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    getpath(7);
    for (auto i : p)
    {
        if (i == p[p.size() - 1])
        {
            cout << i;
            break;
        }
        cout << i << "->";
    }
}