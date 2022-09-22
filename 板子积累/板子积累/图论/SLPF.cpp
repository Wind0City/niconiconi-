#include <bits/stdc++.h>
using namespace std;
struct node
{
    int to;
    int next;
} ene[100];
int head[100], cot;
int vis[100];
void init()
{
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    cot = 0;
}
void add(int f, int t)
{
    cot++;
    ene[cot].to = t;
    ene[cot].next = head[f];
    head[f] = cot;
}
int timing[100];
int num = 1;
void dfs(int dex)
{
    timing[dex] = num;
    num++;
    printf("%d %d\n", dex, timing[dex]);
    for (int i = head[dex]; ~i; i = ene[i].next)
    {
        if (!vis[ene[i].to])
        {
            vis[ene[i].to] = 1;
            dfs(ene[i].to);
        }
    }
}
int main()
{
    init();
    for (int i = 1; i <= 11; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        add(x, y);
        add(y, x);
    }
    printf("\n\n");
    dfs(1);
}