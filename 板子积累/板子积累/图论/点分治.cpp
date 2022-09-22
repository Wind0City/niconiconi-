#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10, inf = 0x7fffffff;
int n, k, ans;
int siz[maxn], S, f[maxn], rt, dep[maxn], d[maxn];
int head[maxn], to[2 * maxn], nxt[2 * maxn], edge[2 * maxn], tot;
bool vis[maxn];
void add(int x, int y, int z) //正常的链式前向星加边
{
    edge[++tot] = z;
    to[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    edge[++tot] = z;
    to[tot] = x;
    nxt[tot] = head[y];
    head[y] = tot;
}
void getrt(int x, int fa) //求重心
{
    siz[x] = 1; // size表示的是以x为根的子树大小
    f[x] = 0;
    for (int i = head[x]; i; i = nxt[i]) //遍历x的子树
    {
        int y = to[i];
        if (y == fa || vis[y]) //首先不能往回走。其次这个点要没删除过
            continue;
        getrt(y, x);              //递归遍历
        siz[x] += siz[y];         //递归结束后加上当前遍历的子树大小
        f[x] = max(f[x], siz[y]); //找出子树最大的(仅限当前遍历的)
    }
    f[x] = max(f[x], S - siz[x]); //当然x做根节点也要考虑他的父节点做他的根节点的子树大小
    if (f[x] < f[rt])             //如果x子树最大值小于当前存储的子树最大值，那他就是重心
        rt = x;
}

void getdep(int x, int fa) //这一部肯定会重复计算的
{
    dep[++dep[0]] = d[x]; //
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = to[i];
        if (y == fa || vis[y])
            continue;
        d[y] = d[x] + edge[i];
        getdep(y, x);
    }
}

int getsum(int x, int dis)
{
    d[x] = dis;   //距离这条边的起始距离
    dep[0] = 0;   // dep是个局部纪录数组
    getdep(x, 0); //找出所有以x为根节点的路经长度
    sort(dep + 1, dep + 1 + dep[0]);
    int L = 1, R = dep[0], sum = 0;
    while (L < R) //默认的先将所有的当作经过根节点路径进行组合判断
    {
        if (dep[L] + dep[R] <= k)
            sum += R - L, L++;
        else
            R--;
    }
    return sum;
}

void solve(int x) //处理以x为根节点的树
{
    vis[x] = true;                       // x这个节点已经处理过了，"删除"x
    ans += getsum(x, 0);                 //第一层的化是首先记录由x点出发的所有路径中满足条件的数目(一定会重复)
    for (int i = head[x]; i; i = nxt[i]) //遍历解决
    {
        int y = to[i];
        if (vis[y])
            continue;
        ans -= getsum(y, edge[i]); //去掉起始点在同一个子树内且经过根的路径,容斥原理的应用
        rt = 0;                    //重心初始化
        S = siz[y];                //重心初始化
        getrt(y, 0);               //求这个子树的重心
        solve(rt);                 //分支求解这个子树
    }
}
int main()
{
    while (~scanf("%d%d", &n, &k), n != 0)
    {
        memset(vis, 0, sizeof(vis));
        memset(head, 0, sizeof(head));
        tot = ans = 0;
        for (int i = 1; i < n; i++)
        {

            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
        }
        f[rt = 0] = inf;
        S = n;
        getrt(1, 0);
        solve(rt);
        printf("%d\n", ans);
    }

    return 0;
}