//最小生成树的克鲁斯卡尔算法，适合稀疏图
/*会用到并查集的思想*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
struct node
{
    int a; //起点
    int b; //终点
    int w; //权重
};
bool cmp(node x, node y)
{
    return x.w < y.w;
}
vector<node> p;
int fa[maxn]; //祖先节点数组
int find(int dex)
{
    if (fa[dex] == dex)
    {
        return dex;
    }
    else
    {
        fa[dex] = find(fa[dex]); //路径压缩
    }
    return fa[dex];
}
int sum = 0;
void myunion(int x, int y, int k)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        sum += p[k].w;
        fa[fy] = fx;
    }
}
int n; //边的个数
int main()
{
    n = 14;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        node temp;
        temp.a = x;
        temp.b = y;
        temp.w = z;
        p.push_back(temp);
    }
    sort(p.begin(), p.end(), cmp);
    for (int i = 1; i <= 9; i++)
        fa[i] = i;
    for (int i = 0; i < p.size(); i++)
    {
        myunion(p[i].a, p[i].b, i);
    }
    cout << sum;
}