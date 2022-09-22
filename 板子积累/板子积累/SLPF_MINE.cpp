#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
#define lson root << 1
#define rson root << 1 | 1
#define tr t[root]

int n, m, r, p;
int w[maxn], fa[maxn], son[maxn], dep[maxn], siz[maxn];
int top[maxn], dfn[maxn], rnk[maxn];
int tim; //时间戳/时间记号
struct ss
{
    int to, next;
} ene[maxn << 2];
int head[maxn << 2] = {0}, tot = 0;
struct segment_tree
{
    int l, r, val;
    int add;
} t[maxn << 2];

void pushDown(int root) //下放标记
{
    if (tr.add)
    {
        t[lson].add = (t[lson].add + tr.add) % p;
        t[rson].add = (t[rson].add + tr.add) % p;
        t[lson].val = (t[lson].val + (t[lson].r - t[lson].l + 1) * tr.add) % p;
        t[rson].val = (t[rson].val + (t[rson].r - t[rson].l + 1) * tr.add) % p;
        tr.add = 0;
    }
}
void build(int l, int r, int root) //递归建树
{
    tr.l = l, tr.r = r;
    if (l == r)
    {
        tr.val = w[rnk[l]]; // rank反向映射记录
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    tr.val = (t[lson].val + t[rson].val) % p;
}
void Modify(int l, int r, int root, int x) //线段树区间修改
{
    if (l <= tr.l && tr.r <= r)
    {
        tr.add = (tr.add + x) % p;
        tr.val = (tr.val + (tr.r - tr.l + 1) * x) % p;
        return;
    }
    int mid = (tr.l + tr.r) >> 1;
    pushDown(root); //下放标记
    if (l <= mid)
        Modify(l, r, lson, x);
    if (r > mid)
        Modify(l, r, rson, x);
    tr.val = (t[lson].val + t[rson].val) % p;
}
int query(int l, int r, int root) //区间查询
{
    if (l <= tr.l && tr.r <= r)
    {
        return tr.val;
    }
    int mid = (tr.l + tr.r) >> 1;
    int ret = 0;
    pushDown(root);
    if (l <= mid)
        ret += query(l, r, lson);
    if (r > mid)
        ret += query(l, r, rson);
    return ret % p;
}

void dfs1(int u, int f) //第一次dfs确定节点的信息:父节点，深度，代表的子树大小，重儿子
{
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    int maxsz = -1;
    for (int i = head[u]; i; i = ene[i].next)
    {
        int v = ene[i].to;
        if (v == f)
            continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > maxsz)
        {
            maxsz = siz[v];
            son[u] = v;
        }
    }
}
void dfs2(int u, int f) //第二次dfs确定所在重链起始节点，各个节点的时间戳(优先往重儿子走) 反向映射数组
{
    top[u] = f;
    dfn[u] = ++tim;
    rnk[tim] = u;
    if (!son[u]) //儿子了就结束
        return;
    dfs2(son[u], f); //优先往重儿子走
    for (int i = head[u]; i; i = ene[i].next)
    {
        int v = ene[i].to;
        if (v == fa[u] || v == son[u]) //不能回溯，不能去重儿子
            continue;
        dfs2(v, v);
    }
}
void mchain(int x, int y, int z) //树上的节点最短路径的修改
{
    while (top[x] != top[y]) //不在同一条重链上时先调整
    {
        if (dep[top[x]] < dep[top[y]]) //优先把深度小的往上挪
        {
            swap(x, y);
        }
        Modify(dfn[top[x]], dfn[x], 1, z);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    Modify(dfn[x], dfn[y], 1, z); //转化为边权的时候可以将dfn[x]+1来实现边权下放为点权
}
int qchain(int x, int y) //查询某个几子树的所有值
{
    int ret = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
        {
            swap(x, y);
        }
        ret = (ret + query(dfn[top[x]], dfn[x], 1)) % p;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    ret = (ret + query(dfn[x], dfn[y], 1)) % p;
    return ret;
}
void add(int x, int y)
{
    tot++;
    ene[tot].to = y;
    ene[tot].next = head[x];
    head[x] = tot;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &r, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d", w + i);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs1(r, 0);
    dfs2(r, r);
    build(1, n, 1);
    while (m--)
    {
        int tp, x, y, z;
        scanf("%d", &tp);
        switch (tp)
        {
        case 1:
            scanf("%d%d%d", &x, &y, &z);
            z %= p;
            mchain(x, y, z);
            break;
        case 2:
            scanf("%d%d", &x, &y);
            printf("%d\n", qchain(x, y));
            break;
        case 3:
            scanf("%d%d", &x, &z);
            z %= p;
            Modify(dfn[x], dfn[x] + siz[x] - 1, 1, z);
            break;
        case 4:
            scanf("%d", &x);
            printf("%d\n", query(dfn[x], dfn[x] + siz[x] - 1, 1));
            break;
        }
    }
    return 0;
}
