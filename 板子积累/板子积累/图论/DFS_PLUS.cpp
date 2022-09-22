
#include <bits/stdc++.h>
using namespace std;
#define MVNum 100    //表示最大顶点个数
bool visited[MVNum]; //定义一个visited数组，记录已被访问的顶点
/*邻接矩阵存储表示*/

#define MVNum 100 //表示最大顶点个数
typedef struct AMGraph
{
    char vexs[MVNum];       //顶点表
    int arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum, arcnum;     //当前的顶点数和边数
} AMGraph;

/*找到顶点v的对应下标*/
int LocateVex(AMGraph &G, char v)
{
    int i;
    for (i = 0; i < G.vexnum; i++)
        if (G.vexs[i] == v)
            return i;
}
void DFS_AM(AMGraph &G, int v)
{
    int w;
    printf("%c ", G.vexs[v]);
    visited[v] = 1;
    for (w = 0; w < G.vexnum; w++)
        if (G.arcs[v][w] && !visited[w]) //递归调用
            DFS_AM(G, w);
}