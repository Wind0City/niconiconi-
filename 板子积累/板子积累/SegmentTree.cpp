#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
#define tr tree[root]
int a[maxn]; //原始数据
struct tre
{
    int l, r;     //存储的区间范围
    int inf;      //区间信息
    int lazy = 0; //懒标记
    friend ostream &operator<<(ostream &out, tre a)
    {
        out << "from " << a.l << " to " << a.r << " inf : " << a.inf << endl;
        return out;
    }
} tree[maxn << 2];
void spread(int root) //标记下放
{
    if (tr.lazy)
    {
        tree[root << 1].lazy += tr.lazy;
        tree[root << 1 | 1].lazy += tr.lazy; //下放标记给左右儿子
        tree[root << 1].inf += (tree[root << 1].r - tree[root << 1].l + 1) * tr.lazy;
        tree[root << 1 | 1].inf += (tree[root << 1].r - tree[root << 1 | 1].l + 1) * tr.lazy; //左右儿子的区间更新
        tr.lazy = 0;
    }
}
void build(int le, int ri, int root) //建树
{
    tr.l = le;
    tr.r = ri;
    if (le == ri)
    {
        tr.inf = a[le];
        return;
    }
    int mid = (tr.l + tr.r) >> 1;
    build(le, mid, root << 1);
    build(mid + 1, ri, root << 1 | 1);
    tr.inf = tree[root << 1].inf + tree[root << 1 | 1].inf;
}
void change_point(int x, int y, int root) //单点修改
{
    if (tr.l == tr.r)
    {
        tr.inf = y;
        a[x] = y;
        return;
    }
    int mid = (tr.l + tr.r) >> 1;
    if (x <= mid)
    {
        change_point(x, y, root << 1);
    }
    if (x > mid)
    {
        change_point(x, y, root << 1 | 1);
    }
    tr.inf = tree[root << 1].inf + tree[root << 1 | 1].inf;
}
int query_simple(int le, int ri, int root) //区间查询
{
    if (le <= tr.l && tr.r <= ri)
    {
        return tr.inf;
    }
    if (le > tr.r || ri < tr.l)
    {
        return 0;
    }
    spread(root);
    int mid = (tr.l + tr.r) >> 1;
    int ans = 0;
    if (le <= mid)
        ans += query_simple(le, ri, root << 1);
    if (ri > mid)
        ans += query_simple(le, ri, root << 1 | 1);
    return ans;
}
void change_que(int l, int r, int root, int x) //区间修改
{
    if (l <= tr.l && tr.r <= r)
    {
        tr.inf += (tr.r - tr.l + 1) * x;
        tr.lazy += x;
        return;
    }
    spread(root);
    int mid = (tr.l + tr.r) >> 1;
    if (l <= mid)
    {
        change_que(l, r, root << 1, x);
    }
    if (r > mid)
    {
        change_que(l, r, root << 1 | 1, x);
    }
    tr.inf = tree[root << 1].inf + tree[root << 1 | 1].inf;
    /*  if (r <= mid)
         change_que(l, r, root << 1, x);
     //如果被修改区间完全在左区间
     else if (l > mid)
         change_que(l, r, root << 1 | 1, x);
     //如果被修改区间完全在右区间
     else
         change_que(l, r, root << 1, x), change_que(mid + 1, r, root << 1 | 1, x);
     //如果都不在，就要把修改区间分解成两块，分别往左右区间递归 */
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, n, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << tree[i];
    }
    cout << query_simple(3, 7, 1) << endl;
    cout << query_simple(3, 8, 1) << endl;
    /*     for (int i = 2; i <= 8; i++)
        {
            change_point(i, i + 1, 1);
        } */
    change_que(3, 10, 1, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << tree[i];
    }
    cout << query_simple(3, 7, 1) << endl;
    cout << query_simple(3, 8, 1) << endl;
}