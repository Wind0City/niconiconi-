//假设这道是求数组逆序对数
#include <bits/stdc++.h>
using namespace std;
#define N 500000
int a[N];  //原始数组
int a1[N]; //备份数组
int b[N];  //离散化数组
int c[N];  //树状数组
int n;     //原始数组个数
int m;     //离散数组个数
int lowbit(int x)
{
    return x & (-x);
}
void discrete() //离散化，数据过大时需要
{
    sort(a1 + 1, a1 + 1 + n);
    m = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || a1[i] != a1[i - 1])
        {
            b[++m] = a1[i];
        }
    }
}
int search(int x) //查询a中x映射为1-m之间那个数
{
    return lower_bound(b + 1, b + 1 + m, x) - b;
}
int ask(int x) //查询区间和
{
    int ans = 0;
    while (x)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
void insert(int x, int y) //单点修改
{
    while (x <= m)
    {
        c[x] += y;
        x += lowbit(x);
    }
}
int main()
{
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            a1[i] = a[i];
        }
        discrete();
        long long ans = 0;
        memset(c, 0, sizeof(c));
        for (int i = n; i >= 1; i--)
        {
            int k = search(a[i]);
            ans += ask(k);
            insert(k, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
    // niconiconi~
}