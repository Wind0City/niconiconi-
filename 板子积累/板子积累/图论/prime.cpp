//最小生成树的prime算法，最小生成树可能有多个，但权值的和是相同的
/*prime类似于dijkstra算法，是对点的不断探索,优化方式也是一样的，这里就不写了*/
//此处先用邻接矩阵来整
#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
int check[maxn]; //检查点位是否已经在集合中
int dis[maxn];   //距离数组,注意此时距离是距离每一次合并之后的整体的
int sum;
struct ma
{
    int map[maxn][maxn];
    int n, m; //点的个数边的个数
} amg;
void init()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(check, 0, sizeof(check));
    memset(amg.map, 0x3f, sizeof(amg.map));
    for (int i = 1; i <= amg.n; i++)
    {
        amg.map[i][i] = 0;
    }
}
void add(int x, int y, int z)
{
    amg.map[x][y] = z;
    amg.map[y][x] = z;
    amg.m++;
}
void prime()
{
    //从1开始长树
    dis[1] = 0;
    while (1)
    {
        int node = -1;  //用来找当前循环距离整体最近的点
        int mmm = 0x3f; //距离整体的距离
        for (int i = 1; i <= amg.n; i++)
        {
            if (!check[i] && dis[i] < mmm)
            {
                node = i;
                mmm = dis[i];
            }
        }               //可以优化成优先队列
        if (node == -1) //所有的点都已经划入树中，找不到
        {
            break;
        }
        check[node] = 1;                 //纳入整体
        for (int i = 1; i <= amg.n; i++) //遍历与node相连的节点
        {
            if (dis[i] > amg.map[node][i] && !check[i]) //如果这个节点没有在整体中，并且距离整体的距离(此时应该是与node的距离)存在，先更新
            {
                dis[i] = amg.map[node][i];
            }
        } //可以优化成链式前向星存图
        //每次循环都会找出与整体距离最短的那个点，然后将这个点纳入整体，再对这个点连接的点遍历更新距离(更新的是与整体的距离)
        //距离的更新要好好理解，以便下一次循环能找到与整体相连的距离最小点
    }
    //循环结束后dis存储的就是于树根节点的距离，累加求和就是最小生成树的权值和
}
int main()
{
    amg.n = 9;
    init();
    add(1, 2, 4);
    add(1, 8, 8);
    add(2, 3, 8);
    add(8, 9, 7);
    add(2, 8, 11);
    add(8, 7, 1);
    add(9, 7, 6);
    add(3, 9, 2);
    add(3, 4, 7);
    add(3, 6, 4);
    add(7, 6, 2);
    add(4, 6, 14);
    add(4, 5, 9);
    add(6, 5, 9);
    prime();
    int ans = 0;
    for (int i = 1; i <= amg.n; i++)
    {
        cout << dis[i] << " ";
        ans += dis[i];
    }
    cout << endl
         << ans;
}