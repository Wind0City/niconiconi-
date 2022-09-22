//最短路的floyd算法,注意只能用邻接表和邻接矩阵,这里用邻接矩阵,
#include <bits/stdc++.h>
using namespace std;
#define maxn 10008
int path[maxn][maxn];
struct amg
{
    int am[100][100]; //邻接矩阵，元素为权重
    int m, n;         //这张图的点数和边数
} amgra;
void init() //邻接矩阵的初始化
{
    memset(path, -1, sizeof(path));
    memset(amgra.am, 0x3f, sizeof(amgra.am));
    amgra.m = 0;
    amgra.n = 0;
}
void add(int x, int y, int z) //邻接矩阵的加边
{
    amgra.am[x][y] = z; //如果是无向图对应的要am[y][x]=1(这是无向图邻接矩阵的性质)
    amgra.n++;          //边数加一
    amgra.am[y][x] = z;
    amgra.n++;
}
void floyd()
{
    for (int i = 1; i <= amgra.m; i++)
    {
        amgra.am[i][i] = 0;
    }
    for (int k = 1; k <= amgra.m; k++)
    {
        for (int i = 1; i <= amgra.m; i++)
        {
            for (int j = 1; j <= amgra.m; j++)
            {
                if (amgra.am[i][j] > amgra.am[i][k] + amgra.am[k][j]) //核心区域，dp思想
                {
                    amgra.am[i][j] = amgra.am[i][k] + amgra.am[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}
vector<pair<int, int>> pa;
void getpath(int u, int v)
{
    if (path[u][v] == -1)
    {
        pa.push_back({u, v});
    }
    else
    {
        int mid = path[u][v];
        getpath(u, mid);
        getpath(mid, v);
    }
}
int main()
{
    init();
    amgra.m = 7;
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
    floyd();
    for (int k = 1; k <= amgra.m; k++)
    {
        for (int i = 1; i <= amgra.m; i++)
        {
            cout << (amgra.am[k][i] < 0x3f ? amgra.am[k][i] : -1) << " ";
        }
        cout << endl;
    }
    getpath(1, 7);
    cout << pa[0].first << "->" << pa[0].second;
    for (int i = 1; i < pa.size(); i++)
    {
        cout << "->" << pa[i].second;
    }
}