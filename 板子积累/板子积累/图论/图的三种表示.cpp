//所有图的节点编号都为数字
#include <bits/stdc++.h>
using namespace std;
struct amg
{
    int am[100][100]; //邻接矩阵，元素为权重
    int m, n;         //这张图的点数和边数
} amgra;
void init() //邻接矩阵的初始化
{
    memset(amgra.am, 0, sizeof(amgra.am));
    amgra.m = 0;
    amgra.n = 0;
}
void add_am(int x, int y, int z) //邻接矩阵的加边
{
    amgra.am[x][y] = z; //如果是无向图对应的要am[y][x]=1(这是无向图邻接矩阵的性质)
    amgra.n++;          //边数加一
}
bool visted_am[100] = {0}; //邻接矩阵的是否已经访问过下标
void clear()               //清空访问标记
{
    memset(visted_am, 0, sizeof(visted_am));
}
void visted_dosth(int index) //访问以及操作函数
{
    cout << index << " ";
    visted_am[index] = 1; //标记已经访问过来（别忘记
}
void bfs_am(amg g, int dex) //对邻接矩阵图g的广度优先搜索,从标号dex开始,美妙的一层一层遍历，就很nice！手动模拟更为nice
{
    queue<int> a;
    visted_dosth(dex); //对dex的顶点访问
    a.push(dex);       //将dex入队
    while (!a.empty()) //当队列不为空的时候
    {
        int cuc = a.front(); //拿出队首元素
        a.pop();             //对队首元素所链接的点开始遍历
        for (int i = 1; i <= g.m; i++)
        {
            if (g.am[cuc][i] && !visted_am[i]) //当这两个点存在边的时候并且i点没有被访问过
            {
                visted_dosth(i); //访问这个点;
                a.push(i);       //并将这个点推入队列
            }
        }
    }
}
void dfs_am(amg g, int dex) //对邻接矩阵图g的深度优先搜索，从标号dex开始
{
    visted_dosth(dex); //首先访问第一个
    for (int i = 1; i <= g.m; i++)
    {
        if (g.am[dex][i] && !visted_am[i]) //没有被访问过并且有边
        {
            dfs_am(g, i); //递归访问i以及他的附属边
        }
    }
}
void bfs_allam(amg g, int dex) //如果图不是连通图的广度优先遍历,dfs同理不多赘述
{
    bfs_am(g, dex);
    for (int i = 0; i < g.m; i++) //如果对dex广搜过后还有遗漏的点，那就是非连通图
    {
        if (!visted_am[i])
        {
            bfs_am(g, i);
        }
    }
}
/****************************************************************手动分割线*********************************************************************************/
struct node
{
    int to; //这条边的中终点
    int w;  //边的权重
};
int bianhao[100];    //每个点的编号/权重
int m, n;            //点数与变数
vector<node> a[100]; //邻接表,下标为边的起点
void init_ljb()      //邻接表的初始化
{
    node temp;
    temp.to = -1;
    temp.w = -1;
    for (int i = 0; i < 100; i++) //将每个点的边集的重点定位-1，这在遍历中会有用
    {
        a[i].push_back(temp);
    }
}
void add_al(int x, int y, int z) //邻接表的加边
{
    node temp; //辅助结构体
    temp.to = y;
    temp.w = z;
    a[x].push_back(temp);
    n++;
}
bool visted_2[100] = {0};
void visted_ljb(int dex)
{
    cout << dex << " ";
    visted_2[dex] = 1; //标记为已经访问
}
void bfs_ljb(vector<node> g[], int dex) //邻接表的bfs遍历
{
    queue<int> q;
    visted_ljb(dex); //访问初始点
    q.push(dex);     // dex点入队
    while (!q.empty())
    {
        int cuc = q.front();       //取出队首元素
        q.pop();                   //弹出
        int i = a[cuc].size() - 1; //指向这个点边集的第一个(其实是最后一个)
        while (a[cuc][i].to != -1)
        {
            if (!visted_2[a[cuc][i].to])
            {
                visted_ljb(a[cuc][i].to);
                q.push(a[cuc][i].to);
            }
            i--;
        }
    }
}
void dfs_ljb(vector<node> g[], int dex)
{
    visted_ljb(dex); //访问第一个
    int i = a[dex].size() - 1;
    while (a[dex][i].to != -1)
    {
        if (!visted_2[a[dex][i].to])
        {
            dfs_ljb(g, a[dex][i].to);
        }
        i--;
    }
}
/****************************************************************手动分割线*********************************************************************************/
struct //链式前向星
{
    int to;   //指向的节点编号
    int w;    //边的权重
    int next; //以相同节点为起点的上一条边的编号
} ene[100];
int tot, head[100]; // head数组用来存储以下标为起点的边的最后一条边的编号
void init_ls()      //链式向前星的初始化
{
    memset(head, 0, sizeof(head)); //初始化为0
    tot = 1;                       //初始化边的个数（编号）
}
void add_ls(int x, int y, int z) //链式向前星的加边
{
    //此时加边，边的编号为tot
    ene[tot].to = y;
    ene[tot].w = z;          //终点与权重的赋值
    ene[tot].next = head[x]; //指向x起点的上一条边的编号
    head[x] = tot++;         //以x为起点的第一条边的编号更新
}
bool vis_ls[100] = {0}; //标记数组
void vislis(int dex)    //访问函数
{
    cout << dex << " ";
    vis_ls[dex] = 1; //标记已访问
}
void bfs(int dex) //链式前向星的广搜
{
    queue<int> q; //定义队列
    vislis(dex);  //
    q.push(dex);  //该点入队
    while (!q.empty())
    {
        int cuc = q.front();
        q.pop();
        for (int i = head[cuc]; i != 0; i = ene[i].next)
        {
            if (!vis_ls[ene[i].to])
            {
                vislis(ene[i].to);
                q.push(ene[i].to);
            }
        }
    }
}
void dfs(int dex) //链式前向星的深搜
{
    vislis(dex);
    for (int i = head[dex]; i != 0; i = ene[i].next)
    {
        if (!vis_ls[ene[i].to])
        {
            dfs(ene[i].to);
        }
    }
}
/****************************************************************手动分割线*********************************************************************************/
int main()
{
    init_ls();
    add_ls(1, 2, 1);
    add_ls(1, 3, 1);
    add_ls(2, 4, 1);
    add_ls(2, 8, 1);
    add_ls(3, 8, 1);
    add_ls(3, 6, 1);
    add_ls(4, 7, 1);
    add_ls(6, 5, 1);
    dfs(1);
}