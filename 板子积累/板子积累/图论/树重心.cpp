//树的重心是，所有节点做根节点其最大子树最小的
#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
// fa存储父节点,si存储每个节点对应的子树大小，r存储每个节点作为根节点的最大子树
int fa[maxn], si[maxn], r[maxn];
int n; //点的个数
struct bb
{
    int to;
    int w;
    int next;
} ene[maxn];
int tot = 1, head[maxn];
void init()
{
    memset(head, -1, sizeof(head));
}
void add(int x, int y, int z)
{
    ene[tot].to = y;
    ene[tot].w = z;
    ene[tot].next = head[x];
    head[x] = tot++;
}
int dfs(int x, int y) //用深搜确定是fa和si
{
    fa[x] = y;
    si[x] = 1;
    for (int i = head[x]; ~i; i = ene[i].next)
    {
        if (ene[i].to != y) //不能回溯，类似打标记，但是不能与打标记不同
        {
            si[i] += dfs(ene[i].to, x);
        }
    }
    return si[x];
}
void ans() //流程
{
    dfs(1, 0);                   //先建立以1为根节点的树,确定每个节点对应的子树大小
    int mm = 0x3f;               //用来找最小值
    for (int i = 1; i <= n; i++) //遍历每个点，找寻每个点做根节点对应的最大子树
    {
        r[i] = n - si[i]; //这一步相当于把dfs(1，0)的成果拿来用，相当于拿出该点作为根节点(之前这个点是当作子节点的)时，它原先父节点做子树的大小
        for (int j = head[i]; ~j; j = ene[j].next)
        {
            if (fa[ene[j].to] == i) //首先要是子树
            {
                r[i] = max(r[i], si[ene[j].to]);
            }
        }
        mm = min(r[i], mm);
    }
    for (int i = 1; i <= n; i++) //找寻与重心值相等的节点(重心可能用多个)
    {
        if (r[i] == mm)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    n = 9;
    int x, y;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x >> y ;
        add(x, y, 1);
        add(y, x, 1);
    }
    init();
    ans();
}