#include <bits/stdc++.h>
using namespace std;
// KMP:
int a[1000010], b[10010];
int nex[10010];
int n, m;
void getNext()
{
    ///求next数组
    /// j表示前缀（前缀是固定的），i表示后缀（后缀是相对的）
    int i, j;
    i = 1;
    j = 0;
    nex[0] = 0;
    while (i < m)
    {
        if (j == 0 || b[i] == b[j]) ///如果可以匹配，都加一进行下一轮匹配
        {
            i++;
            j++;
            nex[i] = j;
        }
        else
            j = nex[j]; ///如果不能匹配，就退回到next[j];
    }
}
///返回首次出现的位置
int KMP_Index()
{
    int i = 1, j = 1;
    getNext();
    while (i < n && j < m)
    {
        if (j == 0 || a[i] == b[j])
        {
            i++;
            j++;
        }
        else
            j = nex[j];
    }
    if (j == m)
        return i - m + 1;
    else
        return -1;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        printf("%d\n", KMP_Index());
    }
    return 0;
}
