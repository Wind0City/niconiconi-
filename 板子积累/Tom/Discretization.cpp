#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 5;
int x[N];       //原始数据
int b[N];       //备份数据
int a[N];       //离散化之后的数据
int n;          //原始数据大小
int m;          //离散化之后数据大小
void discrete() //离散化，数据过大时需要
{
    sort(b + 1, b + 1 + n);
    m = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || b[i] != b[i - 1])
        {
            a[++m] = b[i];
        }
    }
}
int search(int x) //查询离散化之后x的位置下标
{
    return lower_bound(a + 1, a + 1 + m, x) - a;
}