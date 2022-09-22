#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int cnt = 0;
int ss[maxn][30];
int num[maxn];
void insert(string &s)
{
    int u = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int now = s[i] - 'a';
        if (!ss[u][now])
        {
            ss[u][now] = ++cnt;
        }
        u = ss[u][now];
    }
    num[u]++;
}
int find(string &s)
{
    int u = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        int now = s[i] - 'a';
        if (!ss[u][now])
        {
            return 0;
        }
        u = ss[u][now];
    }
    return num[u];
}
void init()
{
    memset(ss, 0, sizeof(ss));
    memset(num, 0, sizeof(num));
}
int main()
{
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        printf("%d\n", find(s));
    }
    return 0;
}