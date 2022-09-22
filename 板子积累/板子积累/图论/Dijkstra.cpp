//最短路的dijkstra算法
#include <bits/stdc++.h>
using namespace std;
#define Maxn 10005
//首先是朴素算法,用的是邻接矩阵存图;
int dis[Maxn];   //记录各个点到起始距离的数组
int check[Maxn]; //记录该点是不是已经为最短路
int path[Maxn];  //记录每一个点在最短路中的父节点
struct am
{
    int m;               //顶点数
    int map[Maxn][Maxn]; //邻接矩阵
} qaq;
void init() //邻接矩阵初始化
{
    memset(qaq.map, 0x3f, sizeof(qaq.map));//注意矩阵的初始化值为无穷大
    memset(dis, 0x3f, sizeof(dis)); //刚开始全部定为无穷大
    memset(check, 0, sizeof(check));
}
void add(int x, int y, int z) //加边函数
{
    qaq.map[x][y] = z;
}
void dijkstra(int dex) //图中各点到dex最短路的算法
{
    dis[dex] = 0;
    for (int i = 1; i <= qaq.m - 1; i++) //已经获取了一个点的最短路(即它本身),所以只遍历n-1次
    {
        int node = -1;
        for (int j = 1; j <= qaq.m; j++)
        {
            if (!check[j] && (node == -1 || (dis[node] > dis[j]))) //找到没标记，并且距出发点最近的点
            {
                node = j;
            }
        }
        for (int j = 1; j <= qaq.m; j++) //遍历找到的这个点的所有邻节点并尝试松弛
        {
            if (dis[j] > dis[node] + qaq.map[node][j])
            {
                dis[j] = dis[node] + qaq.map[node][j];
                path[j] = node;
            }
        }
        check[node] = 1;
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
    init();
    qaq.m = 7;
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
    dijkstra(1);
    for (int i = 1; i <= qaq.m; i++)
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